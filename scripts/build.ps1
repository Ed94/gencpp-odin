$devshell           = Join-Path $PSScriptRoot 'helpers/devshell.ps1'
$misc               = Join-Path $PSScriptRoot 'helpers/misc.ps1'
$incremental_checks = Join-Path $PSScriptRoot 'helpers/incremental_checks.ps1'
$vendor_toolchain   = Join-Path $PSScriptRoot 'helpers/vendor_toolchain.ps1'

. $misc

$path_root = Get-ScriptRepoRoot

Push-Location $path_root

#region Arguments
       $vendor       = $null
       $release      = $null
[bool] $verbose      = $false
[bool] $lib          = $false
[bool] $exmaples     = $false

[array] $vendors = @( "clang", "msvc" )

if ( $args ) { $args | ForEach-Object {
	switch ($_){
		{ $_ -in $vendors }   { $vendor   = $_; break }
		"verbose"			  { $verbose  = $true }
		"release"             { $release  = $true }
		"debug"               { $release  = $false }
		"lib"                 { $lib      = $true }
		"examples"            { $examples = $true }
	}
}}
#endregion Arguments

& $devshell -arch amd64

if ( $vendor -eq $null ) {
	write-host "No vendor specified, assuming clang available"
	$compiler = "clang"
}

if ( $release -eq $null ) {
	write-host "No build type specified, assuming debug"
	$release = $false
}
elseif ( $release -eq $false ) {
	$debug = $true
}
else {
	$optimize = $true
}

$cannot_build =                     $lib         -eq $false
$cannot_build = $cannot_build -and  $examples    -eq $false
if ( $cannot_build ) {
	throw "No build target specified. One must be specified, this script will not assume one"
}

. $incremental_checks

#region Building
$path_build         = Join-Path $path_root   'build'
$path_examples      = join-path $path_root   'examples'
$path_gencpp        = join-Path $path_root   'gencpp'
$path_gencpp_source = join-Path $path_gencpp 'source'
$path_scripts       = Join-Path $path_root   'scripts'

verify-path $path_build

#region CPU_Info
$path_system_details = join-path $path_build 'system_details.ini'
if ( test-path $path_system_details ) {
    $iniContent = Get-IniContent $path_system_details
    $CoreCount_Physical = $iniContent["CPU"]["PhysicalCores"]
    $CoreCount_Logical  = $iniContent["CPU"]["LogicalCores"]
}
elseif ( $IsWindows ) {
	$CPU_Info = Get-CimInstance –ClassName Win32_Processor | Select-Object -Property NumberOfCores, NumberOfLogicalProcessors
	$CoreCount_Physical, $CoreCount_Logical = $CPU_Info.NumberOfCores, $CPU_Info.NumberOfLogicalProcessors

	new-item -path $path_system_details -ItemType File
    "[CPU]"                             | Out-File $path_system_details
    "PhysicalCores=$CoreCount_Physical" | Out-File $path_system_details -Append
    "LogicalCores=$CoreCount_Logical"   | Out-File $path_system_details -Append
}
write-host "Core Count - Physical: $CoreCount_Physical Logical: $CoreCount_Logical"
#endregion CPU_Info

if ( $lib )
{
	write-host "Building gencpp c11 library with $vendor"
	write-host "Build Type: $(if ($release) {"Release"} else {"Debug"} )"

	. $vendor_toolchain

	$path_lib = join-path $path_gencpp 'lib/win64'
	verify-path $path_lib

	$includes = @( $path_gencpp )
	$unit     = join-path $path_gencpp_source "gencpp_c11.c"
	$path_lib = join-path $path_lib           "gencpp_c11.lib"

	$compiler_args = @()
	$compiler_args += $flag_all_c
	$compiler_args += $flag_updated_cpp_macro
	$compiler_args += $flag_c11
	$compiler_args += ($flag_define + 'GEN_STATIC_LINK')

	$linker_args = @()
	$result = build-simple $path_build $includes $compiler_args $linker_args $unit $path_lib
}

if ( $examples )
{
	$odin_compiler_defs = join-path $path_scripts 'helpers/odin_compiler_defs.ps1'
	. $odin_compiler_defs

	write-host "Building gencpp-odin examples"
	$executable = join-path $path_build 'hellope_gencpp.exe'
	$pdb        = join-path $path_build 'hellope_gencpp.pdb'

	$path_file  = join-path $path_examples 'hellope_gencpp.odin'

	$build_args = @()
	$build_args += $command_build
	$build_args += $path_file
	$build_args += $flag_file_package
	$build_args += $flag_output_path + $executable
	# $build_args += $flag_micro_architecture_native
	$build_args += $flag_use_separate_modules
	$build_args += $flag_thread_count + $CoreCount_Physical
	$build_args += $flag_optimize_none
	# $build_args += $flag_optimize_minimal
	# $build_args += $flag_optimize_speed
	# $build_args += $falg_optimize_aggressive
	$build_args += $flag_debug
	$build_args += $flag_pdb_name + $pdb
	$build_args += $flag_subsystem + 'windows'
	# $build_args += ($flag_extra_linker_flags + $linker_args )
	$build_args += $flag_show_timings
	# $build_args += $flag_show_system_call
	# $build_args += $flag_no_bounds_check
	# $build_args += $flag_no_thread_checker
	# $build_args += $flag_default_allocator_nil
	$build_args += ($flag_max_error_count + '10')
	# $build_args += $flag_sanitize_address
	# $build_args += $flag_sanitize_memory

	Write-Host $build_args

	push-location $path_examples
		Invoke-WithColorCodedOutput { & $odin_compiler $build_args }
	pop-location
}
#endregon Building

pop-location
