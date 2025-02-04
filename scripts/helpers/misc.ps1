function Get-IniContent { param( [string] $path_file )
	$ini            = @{}
	$currentSection = $null
	switch -regex -file $path_file
	{
		"^\[(.+)\]$" {
			$currentSection       = $matches[1].Trim()
			$ini[ $currentSection ] = @{}
		}
		"^(.+?)\s*=\s*(.*)" {
			$key, $value = $matches[1].Trim(), $matches[2].Trim()
			if ($null -ne $currentSection) {
				$ini[ $currentSection ][ $key ] = $value
			}
		}
	}
	return $ini
}

function Get-ScriptRepoRoot {
    $currentPath = $PSScriptRoot
    while ($currentPath -ne $null -and $currentPath -ne "")
	{
        if (Test-Path (Join-Path $currentPath ".git")) {
            return $currentPath
        }
        # Also check for .git file which indicates a submodule
        $gitFile = Join-Path $currentPath ".git"
        if (Test-Path $gitFile -PathType Leaf)
		{
            $gitContent = Get-Content $gitFile
            if ($gitContent -match "gitdir: (.+)") {
                return $currentPath
            }
        }
        $currentPath = Split-Path $currentPath -Parent
    }
    throw "Unable to find repository root"
}

function verify-path { param( $path )
	if (test-path $path) {return $true}

	new-item -ItemType Directory -Path $path
	return $false
}
