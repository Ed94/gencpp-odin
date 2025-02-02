// This file was generated automatially by gencpp's c_library.cpp  (See: https://github.com/Ed94/gencpp)

// This file is intended to be included within gen.hpp (There is no pragma diagnostic ignores)

#pragma region Platform Detection

/* Platform architecture */

#if defined( _WIN64 ) || defined( __x86_64__ ) || defined( _M_X64 ) || defined( __64BIT__ ) || defined( __powerpc64__ ) || defined( __ppc64__ ) || defined( __aarch64__ )
#	ifndef GEN_ARCH_64_BIT
#		define GEN_ARCH_64_BIT 1
#	endif
#else
#	ifndef GEN_ARCH_32_BItxt_StrCaT
#		define GEN_ARCH_32_BIT 1
#	endif
#endif

/* Platform OS */

#if defined( _WIN32 ) || defined( _WIN64 )
#	ifndef GEN_SYSTEM_WINDOWS
#		define GEN_SYSTEM_WINDOWS 1
#	endif
#elif defined( __APPLE__ ) && defined( __MACH__ )
#	ifndef GEN_SYSTEM_OSX
#		define GEN_SYSTEM_OSX 1
#	endif
#	ifndef GEN_SYSTEM_MACOS
#		define GEN_SYSTEM_MACOS 1
#	endif
#elif defined( __unix__ )
#	ifndef GEN_SYSTEM_UNIX
#		define GEN_SYSTEM_UNIX 1
#	endif
#	if defined( ANDROID ) || defined( __ANDROID__ )
#		ifndef GEN_SYSTEM_ANDROID
#			define GEN_SYSTEM_ANDROID 1
#		endif
#		ifndef GEN_SYSTEM_LINUX
#			define GEN_SYSTEM_LINUX 1
#		endif
#	elif defined( __linux__ )
#		ifndef GEN_SYSTEM_LINUX
#			define GEN_SYSTEM_LINUX 1
#		endif
#	elif defined( __FreeBSD__ ) || defined( __FreeBSD_kernel__ )
#		ifndef GEN_SYSTEM_FREEBSD
#			define GEN_SYSTEM_FREEBSD 1
#		endif
#	elif defined( __OpenBSD__ )
#		ifndef GEN_SYSTEM_OPENBSD
#			define GEN_SYSTEM_OPENBSD 1
#		endif
#	elif defined( __EMSCRIPTEN__ )
#		ifndef GEN_SYSTEM_EMSCRIPTEN
#			define GEN_SYSTEM_EMSCRIPTEN 1
#		endif
#	elif defined( __CYGWIN__ )
#		ifndef GEN_SYSTEM_CYGWIN
#			define GEN_SYSTEM_CYGWIN 1
#		endif
#	else
#		error This UNIX operating system is not supported
#	endif
#else
#	error This operating system is not supported
#endif

/* Platform compiler */

#if defined( _MSC_VER )
#	pragma message("Detected MSVC")
// #	define GEN_COMPILER_CLANG 0
#	define GEN_COMPILER_MSVC  1
// #	define GEN_COMPILER_GCC   0
#elif defined( __GNUC__ )
#	pragma message("Detected GCC")
// #	define GEN_COMPILER_CLANG 0
// #	define GEN_COMPILER_MSVC  0
#	define GEN_COMPILER_GCC   1
#elif defined( __clang__ )
#	pragma message("Detected CLANG")
#	define GEN_COMPILER_CLANG 1
// #	define GEN_COMPILER_MSVC  0
// #	define GEN_COMPILER_GCC   0
#else
#	error Unknown compiler
#endif

#if defined( __has_attribute )
#	define GEN_HAS_ATTRIBUTE( attribute ) __has_attribute( attribute )
#else
#	define GEN_HAS_ATTRIBUTE( attribute ) ( 0 )
#endif

#if defined(GEN_GCC_VERSION_CHECK)
#  undef GEN_GCC_VERSION_CHECK
#endif
#if defined(GEN_GCC_VERSION)
#  define GEN_GCC_VERSION_CHECK(major,minor,patch) (GEN_GCC_VERSION >= GEN_VERSION_ENCODE(major, minor, patch))
#else
#  define GEN_GCC_VERSION_CHECK(major,minor,patch) (0)
#endif

#if !defined(GEN_COMPILER_C)
#	ifdef __cplusplus
#		define GEN_COMPILER_C   0
#		define GEN_COMPILER_CPP 1
#	else
#		if defined(__STDC__)
#			define GEN_COMPILER_C   1
#		    define GEN_COMPILER_CPP 0
#		else
            // Fallback for very old C compilers
#			define GEN_COMPILER_C   1
#		    define GEN_COMPILER_CPP 0
#		endif
#   endif
#endif

#if GEN_COMPILER_C
#pragma message("GENCPP: Detected C")
#endif

#pragma endregion Platform Detection

#pragma region Mandatory Includes

#	include <stdarg.h>
#	include <stddef.h>

#	if defined( GEN_SYSTEM_WINDOWS )
#		include <intrin.h>
#	endif

#if GEN_COMPILER_C
#include <assert.h>
#include <stdbool.h>
#endif

#pragma endregion Mandatory Includes

#if GEN_DONT_USE_NAMESPACE || GEN_COMPILER_C
#	if GEN_COMPILER_C
#		define GEN_NS
#		define GEN_NS_BEGIN
#		define GEN_NS_END
#	else
#		define GEN_NS              ::
#		define GEN_NS_BEGIN
#		define GEN_NS_END
#	endif
#else
#	define GEN_NS              gen::
#	define GEN_NS_BEGIN        namespace gen {
#	define GEN_NS_END          }
#endif

GEN_NS_BEGIN

#pragma region Macros

#ifndef GEN_API
#if GEN_COMPILER_MSVC
    #ifdef GEN_DYN_LINK
        #ifdef GEN_DYN_EXPORT
            #define GEN_API __declspec(dllexport)
        #else
            #define GEN_API __declspec(dllimport)
        #endif
    #else
        #define GEN_API  // Empty for static builds
    #endif
#else
    #ifdef GEN_DYN_LINK
        #define GEN_API __attribute__((visibility("default")))
    #else
        #define GEN_API  // Empty for static builds
    #endif
#endif
#endif // GEN_API

#ifndef gen_global // Global variables
#	ifdef GEN_DYN_EXPORT
#		define gen_global         
#	else
#		define gen_global static
#	endif
#endif
#ifndef gen_internal
#define gen_internal      static    // Internal linkage
#endif
#ifndef gen_local_persist
#define gen_local_persist static    // Local Persisting variables
#endif

#ifndef gen_bit
#define gen_bit( Value )                         ( 1 << Value )
#endif

#ifndef gen_bitfield_is_set
#define gen_bitfield_is_set( Type, Field, Mask ) ( (gen_scast(Type, Mask) & gen_scast(Type, Field)) == gen_scast(Type, Mask) )
#endif

// Mainly intended for forcing the base library to utilize only C-valid constructs or type coercion
#ifndef GEN_C_LIKE_CPP
#define GEN_C_LIKE_CPP 0
#endif

#if GEN_COMPILER_CPP
#	ifndef gen_cast
#	define gen_cast( type, value ) (tmpl_cast<type>( value ))
#	endif
#else
#	ifndef gen_cast
#	define gen_cast( type, value )  ( (type)(value) )
#	endif
#endif

#if GEN_COMPILER_CPP
#	ifndef gen_ccast
#	define gen_ccast( type, value ) ( const_cast< type >( (value) ) )
#	endif
#	ifndef gen_pcast
#	define gen_pcast( type, value ) ( * reinterpret_cast< type* >( & ( value ) ) )
#	endif
#	ifndef gen_rcast
#	define gen_rcast( type, value ) reinterpret_cast< type >( value )
#	endif
#	ifndef gen_scast
#	define gen_scast( type, value ) static_cast< type >( value )
#	endif
#else
#	ifndef gen_ccast
#	define gen_ccast( type, value ) ( (type)(value) )
#	endif
#	ifndef gen_pcast
#	define gen_pcast( type, value ) ( * (type*)(& value) )
#	endif
#	ifndef gen_rcast
#	define gen_rcast( type, value ) ( (type)(value) )
#	endif
#	ifndef gen_scast
#	define gen_scast( type, value ) ( (type)(value) )
#	endif
#endif

#ifndef gen_stringize
#define gen_stringize_va( ... ) #__VA_ARGS__
#define gen_stringize( ... )    gen_stringize_va( __VA_ARGS__ )
#endif

#define src_line_str gen_stringize(__LINE__)

#ifndef gen_do_once
#define gen_do_once()                                                                            \
	gen_local_persist int __do_once_counter_##src_line_str  = 0;                                 \
    for(;      __do_once_counter_##src_line_str != 1; __do_once_counter_##src_line_str = 1 ) \

#define do_once_defer( expression )                                                                 \
    gen_local_persist int __do_once_counter_##src_line_str  = 0;                                        \
    for(;__do_once_counter_##src_line_str != 1; __do_once_counter_##src_line_str = 1, (expression)) \

#define gen_do_once_start      \
	do                     \
	{                      \
		gen_local_persist      \
		bool done = false; \
		if ( done )        \
			break;         \
		done = true;

#define gen_do_once_end        \
	}                      \
	while(0);
#endif

#ifndef gen_labeled_scope_start
#define gen_labeled_scope_start if ( false ) {
#define gen_labeled_scope_end   }
#endif

#ifndef         gen_compiler_decorated_func_name
#   ifdef COMPILER_CLANG
#       define  gen_compiler_decorated_func_name __PRETTY_NAME__
#   elif defined(COMPILER_MSVC)
#   	define gen_compiler_decorated_func_name __FUNCDNAME__
#   endif
#endif

#ifndef gen_num_args_impl

// This is essentially an arg couneter version of GEN_SELECT_ARG macros
// See section : _Generic function overloading for that usage (explains this heavier case)

#define gen_num_args_impl( _0,                                 \
		_1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9, _10,   \
		_11, _12, _13, _14, _15, _16, _17, _18, _19, _20,  \
		_21, _22, _23, _24, _25, _26, _27, _28, _29, _30,  \
		_31, _32, _33, _34, _35, _36, _37, _38, _39, _40,  \
		_41, _42, _43, _44, _45, _46, _47, _48, _49, _50,  \
		_51, _52, _53, _54, _55, _56, _57, _58, _59, _60,  \
		_61, _62, _63, _64, _65, _66, _67, _68, _69, _70,  \
		_71, _72, _73, _74, _75, _76, _77, _78, _79, _80,  \
		_81, _82, _83, _84, _85, _86, _87, _88, _89, _90,  \
		_91, _92, _93, _94, _95, _96, _97, _98, _99, _100, \
		N, ...                                             \
	) N

// ## deletes preceding comma if _VA_ARGS__ is empty (GCC, Clang)
#define gen_num_args(...)                            \
	gen_num_args_impl(_, ## __VA_ARGS__,             \
		100, 99, 98, 97, 96, 95, 94, 93, 92, 91, \
		 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, \
		 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, \
		 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, \
		 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, \
		 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, \
		 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, \
		 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, \
		 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, \
		 10,  9,  8,  7,  6,  5,  4,  3,  2,  1, \
		 0                                       \
	)
#endif

#ifndef gen_clamp
#define gen_clamp( x, lower, upper )      gen_min( gen_max( ( x ), ( lower ) ), ( upper ) )
#endif
#ifndef gen_count_of
#define gen_count_of( x )                 ( ( gen_size_of( x ) / gen_size_of( 0 [ x ] ) ) / ( ( gen_ssize )( ! ( gen_size_of( x ) % gen_size_of( 0 [ x ] ) ) ) ) )
#endif
#ifndef gen_is_between
#define gen_is_between( x, lower, upper ) ( ( ( lower ) <= ( x ) ) && ( ( x ) <= ( upper ) ) )
#endif
#ifndef gen_size_of
#define gen_size_of( x )                  ( gen_ssize )( sizeof( x ) )
#endif

#ifndef gen_max
#define gen_max( a, b ) ( (a > b) ? (a) : (b) )
#endif
#ifndef gen_min
#define gen_min( a, b ) ( (a < b) ? (a) : (b) )
#endif

#if GEN_COMPILER_MSVC || GEN_COMPILER_TINYC
#	define gen_offset_of( Type, element ) ( ( GEN_NS( gen_ssize ) ) & ( ( ( Type* )0 )->element ) )
#else
#	define gen_offset_of( Type, element ) __builtin_offsetof( Type, element )
#endif

#ifndef        gen_forceinline
#	if GEN_COMPILER_MSVC
#		define gen_forceinline __forceinline
#		define gen_neverinline __declspec( noinline )
#	elif GEN_COMPILER_GCC
#		define gen_forceinline inline __attribute__((__always_inline__))
#		define gen_neverinline __attribute__( ( __noinline__ ) )
#	elif GEN_COMPILER_CLANG
#	if __has_attribute(__always_inline__)
#		define gen_forceinline inline __attribute__((__always_inline__))
#		define gen_neverinline __attribute__( ( __noinline__ ) )
#	else
#		define gen_forceinline
#		define gen_neverinline
#	endif
#	else
#		define gen_forceinline
#		define gen_neverinline
#	endif
#endif

#ifndef        gen_neverinline
#	if GEN_COMPILER_MSVC
#		define gen_neverinline __declspec( noinline )
#	elif GEN_COMPILER_GCC
#		define gen_neverinline __attribute__( ( __noinline__ ) )
#	elif GEN_COMPILER_CLANG
#	if __has_attribute(__always_inline__)
#		define gen_neverinline __attribute__( ( __noinline__ ) )
#	else
#		define gen_neverinline
#	endif
#	else
#		define gen_neverinline
#	endif
#endif

#if GEN_COMPILER_C
#ifndef gen_static_assert
#undef  gen_static_assert
    #if GEN_COMPILER_C && __STDC_VERSION__ >= 201112L
        #define gen_static_assert(condition, message) _Static_assert(condition, message)
    #else
        #define gen_static_assert(condition, message) typedef char static_assertion_##__LINE__[(condition)?1:-1]
	#endif
#endif
#endif

#if GEN_COMPILER_CPP
// Already Defined
#elif GEN_COMPILER_C && __STDC_VERSION__ >= 201112L
#	define gen_thread_local _Thread_local
#elif GEN_COMPILER_MSVC
#	define gen_thread_local __declspec(thread)
#elif GEN_COMPILER_CLANG
#	define gen_thread_local __thread
#else
#	error "No thread local support"
#endif

#if ! defined(gen_typeof) && (!GEN_COMPILER_C || __STDC_VERSION__ < 202311L)
#	if ! GEN_COMPILER_C
#		define gen_typeof decltype
#	elif defined(_MSC_VER)
#		define gen_typeof __typeof__
#	elif defined(__GNUC__) || defined(__clang__)
#		define gen_typeof __typeof__
#	else
#		error "Compiler not supported"
#	endif
#endif

#ifndef GEN_API_C_BEGIN
#	if GEN_COMPILER_C
#		define GEN_API_C_BEGIN
#		define GEN_API_C_END
#	else
#		define GEN_API_C_BEGIN extern "C" {
#		define GEN_API_C_END   }
#	endif
#endif

#if GEN_COMPILER_C
#	if __STDC_VERSION__ >= 202311L
#		define gen_enum_underlying(type) : type
#	else
#		define gen_enum_underlying(type)
#   endif
#else
#	define gen_enum_underlying(type) : type
#endif

#if GEN_COMPILER_C
#	ifndef gen_nullptr
#		define gen_nullptr NULL
#	endif

#	ifndef GEN_REMOVE_PTR
#		define GEN_REMOVE_PTR(type) gen_typeof(* ( (type) NULL) )
#	endif
#endif

#if ! defined(GEN_PARAM_DEFAULT) && GEN_COMPILER_CPP
#	define GEN_PARAM_DEFAULT = {}
#else
#	define GEN_PARAM_DEFAULT
#endif

#if GEN_COMPILER_CPP
    #define gen_struct_init(type, value) {value}
#else
    #define gen_struct_init(type, value) {value}
#endif

#if 0
#ifndef GEN_OPTIMIZE_MAPPINGS_BEGIN
#	define GEN_OPTIMIZE_MAPPINGS_BEGIN _pragma(optimize("gt", on))
#	define GEN_OPITMIZE_MAPPINGS_END   _pragma(optimize("", on))
#endif
#else
#	define GEN_OPTIMIZE_MAPPINGS_BEGIN
#	define GEN_OPITMIZE_MAPPINGS_END
#endif

#pragma endregion Macros

#pragma region _Generic Macros
//   ____                       _        ______                _   _                ____                  _                 __ _
//  / ___}                     (_)      |  ____}              | | (_)              / __ \                | |               | |(_)
// | | ___  ___ _ __   ___ _ __ _  ___  | |__ _   _ _ __   ___| |_ _  ___  _ __   | |  | |_   _____ _ __ | | ___   __ _  __| | _ _ __   __ _
// | |{__ |/ _ \ '_ \ / _ \ '__} |/ __| |  __} | | | '_ \ / __} __} |/ _ \| '_ \  | |  | \ \ / / _ \ '_ }| |/ _ \ / _` |/ _` || | '_ \ / _` |
// | |__j |  __/ | | |  __/ |  | | (__  | |  | |_| | | | | (__| l_| | (_) | | | | | l__| |\ V /  __/ |   | | (_) | (_| | (_| || | | | | (_| |
//  \____/ \___}_l l_l\___}_l  l_l\___| l_l   \__,_l_l l_l\___}\__}_l\___/l_l l_l  \____/  \_/ \___}_l   l_l\___/ \__,_l\__,_l|_|_| |_|\__, |
// This implemnents macros for utilizing "The Naive Extendible _Generic Macro" explained in:                                            __| |
// https://github.com/JacksonAllan/CC/blob/main/articles/Better_C_Generics_Part_1_The_Extendible_Generic.md                            {___/
// Since gencpp is used to generate the c-library, it was choosen over the more novel implementations to keep the macros as easy to understand and unobfuscated as possible.

#define GEN_COMMA_OPERATOR , // The comma operator is used by preprocessor macros to delimit arguments, so we have to represent it via a macro to prevent parsing incorrectly.

// Helper macros for argument selection
#define GEN_SELECT_ARG_1( _1, ... ) _1 // <-- Of all th args passed pick _1.
#define GEN_SELECT_ARG_2( _1, _2, ... ) _2 // <-- Of all the args passed pick _2.
#define GEN_SELECT_ARG_3( _1, _2, _3, ... ) _3 // etc..

#define GEN_GENERIC_SEL_ENTRY_TYPE             GEN_SELECT_ARG_1 // Use the arg expansion macro to select arg 1 which should have the type.
#define GEN_GENERIC_SEL_ENTRY_FUNCTION         GEN_SELECT_ARG_2 // Use the arg expansion macro to select arg 2 which should have the function.
#define GEN_GENERIC_SEL_ENTRY_COMMA_DELIMITER  GEN_SELECT_ARG_3 // Use the arg expansion macro to select arg 3 which should have the comma delimiter ','.

#define GEN_RESOLVED_FUNCTION_CALL // Just used to indicate where the call "occurs"

// ----------------------------------------------------------------------------------------------------------------------------------
// GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT( macro ) includes a _Generic slot only if the specified macro is defined (as type, function_name).
// It takes advantage of the fact that if the macro is defined, then the expanded text will contain a comma.
// Expands to ',' if it can find (type): (function) <comma_operator: ',' >
// Where GEN_GENERIC_SEL_ENTRY_COMMA_DELIMITER is specifically looking for that <comma> ,
#define GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT( slot_exp ) GEN_GENERIC_SEL_ENTRY_COMMA_DELIMITER( slot_exp, GEN_GENERIC_SEL_ENTRY_TYPE( slot_exp, ): GEN_GENERIC_SEL_ENTRY_FUNCTION( slot_exp, ) GEN_COMMA_OPERATOR, , )
//                                                          ^ Selects the comma                              ^ is the type                             ^ is the function                             ^ Insert a comma
// The slot won't exist if that comma is not found.

// For the occastion where an expression didn't resolve to a selection option the "default: <value>" will be set to:
typedef struct GENCPP_NO_RESOLVED_GENERIC_SELECTION GENCPP_NO_RESOLVED_GENERIC_SELECTION;
struct GENCPP_NO_RESOLVED_GENERIC_SELECTION {
	void* _THE_VOID_SLOT_;
};
GENCPP_NO_RESOLVED_GENERIC_SELECTION const gen_generic_selection_fail = {0};
// Which will provide the message:  error: called object type 'struct NO_RESOLVED_GENERIC_SELECTION' is not a function or function pointer
// ----------------------------------------------------------------------------------------------------------------------------------

// Below are generated on demand for an overlaod depdendent on a type:
// ----------------------------------------------------------------------------------------------------------------------------------
#define GEN_FUNCTION_GENERIC_EXAMPLE( selector_arg ) _Generic(             \
(selector_arg), /* Select Via Expression*/                                 \
  /* Extendibility slots: */                                               \
	GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT( GENERIC_SLOT_1__function_sig ) \
	GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT( GENERIC_SLOT_2__function_sig ) \
	default: gen_generic_selection_fail                                    \
) GEN_RESOLVED_FUNCTION_CALL( selector_arg )
// ----------------------------------------------------------------------------------------------------------------------------------

// Then each definiton of a function has an associated define:
#// #define GENERIC_SLOT_<#>_<generic identifier> <typename>, <function_to_resolve>

// Then somehwere later on
// <etc> <return_type> <function_id> ( <arguments> ) { <implementation> }

// Concrete example:

// To add support for long:
#define GENERIC_SLOT_1_gen_example_hash long, gen_example_hash__P_long
size_t gen_example_hash__P_long( long val ) { return val * 2654435761ull; }

// To add support for long long:
#define GENERIC_SLOT_2_gen_example_hash  long long, gen_example_hash__P_long_long
size_t gen_example_hash__P_long_long( long long val ) { return val * 2654435761ull; }

// If using an Editor with support for syntax hightlighting macros:
// GENERIC_SLOT_1_gen_example_hash and GENERIC_SLOT_2_gen_example_hash should show color highlighting indicating the slot is enabled,
// or, "defined" for usage during the compilation pass that handles the _Generic instrinsic.
#define gen_hash_example( function_arguments ) _Generic(                      \
(function_arguments), /* Select Via Expression*/                              \
  /* Extendibility slots: */                                                  \
	GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT( GENERIC_SLOT_1_gen_example_hash ) \
	GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT( GENERIC_SLOT_2_gen_example_hash ) \
	GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT( GENERIC_SLOT_3_gen_example_hash ) \
	GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT( GENERIC_SLOT_4_gen_example_hash ) \
	GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT( GENERIC_SLOT_5_gen_example_hash ) \
	GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT( GENERIC_SLOT_6_gen_example_hash ) \
	GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT( GENERIC_SLOT_7_gen_example_hash ) \
	GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT( GENERIC_SLOT_8_gen_example_hash ) \
	default: gen_generic_selection_fail                                       \
) GEN_RESOLVED_FUNCTION_CALL( function_arguments )

// Additional Variations:

// If the function takes more than one argument the following is used:
#define GEN_FUNCTION_GENERIC_EXAMPLE_VARADIC( selector_arg, ... ) _Generic( \
(selector_arg),                                                             \
	GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT( GENERIC_SLOT_1__function_sig )  \
	GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT( GENERIC_SLOT_2__function_sig )  \
	/* ... */                                                               \
	GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GENERIC_SLOT_N__function_sig )   \
	default: gen_generic_selection_fail                                     \
) GEN_RESOLVED_FUNCTION_CALL( selector_arg, __VA_ARG__ )

// If the function does not take the arugment as a parameter:
#define GEN_FUNCTION_GENERIC_EXAMPLE_DIRECT_TYPE( selector_arg ) _Generic( \
( GEN_TYPE_TO_EXP(selector_arg) ),                                         \
	GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT( GENERIC_SLOT_1__function_sig ) \
	GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT( GENERIC_SLOT_2__function_sig ) \
	/* ... */                                                              \
	GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GENERIC_SLOT_N__function_sig )  \
	default: gen_generic_selection_fail                                    \
) GEN_RESOLVED_FUNCTION_CALL()

// Used to keep the _Generic keyword happy as bare types are not considered "expressions"
#define GEN_TYPE_TO_EXP(type) (* (type*)NULL)
// Instead of using this macro, you'll see it directly expanded by the code generation.

// typedef void* GEN_GenericExampleType;
// GEN_FUNCTION_GENERIC_EXAMPLE_DIRECT_TYPE( GEN_GenericExampleType );
#pragma endregion _Generic Macros

#pragma region Basic Types

#define GEN_U8_MIN 0u
#define GEN_U8_MAX 0xffu
#define GEN_I8_MIN ( -0x7f - 1 )
#define GEN_I8_MAX 0x7f

#define GEN_U16_MIN 0u
#define GEN_U16_MAX 0xffffu
#define GEN_I16_MIN ( -0x7fff - 1 )
#define GEN_I16_MAX 0x7fff

#define GEN_U32_MIN 0u
#define GEN_U32_MAX 0xffffffffu
#define GEN_I32_MIN ( -0x7fffffff - 1 )
#define GEN_I32_MAX 0x7fffffff

#define GEN_U64_MIN 0ull
#define GEN_U64_MAX 0xffffffffffffffffull
#define GEN_I64_MIN ( -0x7fffffffffffffffll - 1 )
#define GEN_I64_MAX 0x7fffffffffffffffll

#if defined( GEN_ARCH_32_BIT )
#	define GEN_USIZE_MIN GEN_U32_MIN
#	define GEN_USIZE_MAX GEN_U32_MAX
#	define GEN_ISIZE_MIN GEN_S32_MIN
#	define GEN_ISIZE_MAX GEN_S32_MAX
#elif defined( GEN_ARCH_64_BIT )
#	define GEN_USIZE_MIN GEN_U64_MIN
#	define GEN_USIZE_MAX GEN_U64_MAX
#	define GEN_ISIZE_MIN GEN_I64_MIN
#	define GEN_ISIZE_MAX GEN_I64_MAX
#else
#	error Unknown architecture size. This library only supports 32 gen_bit and 64 gen_bit architectures.
#endif

#define GEN_F32_MIN 1.17549435e-38f
#define GEN_F32_MAX 3.40282347e+38f
#define GEN_F64_MIN 2.2250738585072014e-308
#define GEN_F64_MAX 1.7976931348623157e+308

#if defined( GEN_COMPILER_MSVC )
#	if _MSC_VER < 1300
typedef unsigned char  gen_u8;
typedef signed   char  gen_s8;
typedef unsigned short gen_u16;
typedef signed   short gen_s16;
typedef unsigned int   gen_u32;
typedef signed   int   gen_s32;
#    else
typedef unsigned __int8  gen_u8;
typedef signed   __int8  gen_s8;
typedef unsigned __int16 gen_u16;
typedef signed   __int16 gen_s16;
typedef unsigned __int32 gen_u32;
typedef signed   __int32 gen_s32;
#    endif
typedef unsigned __int64 gen_u64;
typedef signed   __int64 gen_s64;
#else
#	include <stdint.h>

typedef uint8_t  gen_u8;
typedef int8_t   gen_s8;
typedef uint16_t gen_u16;
typedef int16_t  gen_s16;
typedef uint32_t gen_u32;
typedef int32_t  gen_s32;
typedef uint64_t gen_u64;
typedef int64_t  gen_s64;
#endif

gen_static_assert( sizeof( gen_u8 )  == sizeof( gen_s8 ),  "sizeof(gen_u8) != sizeof(gen_s8)" );
gen_static_assert( sizeof( gen_u16 ) == sizeof( gen_s16 ), "sizeof(gen_u16) != sizeof(gen_s16)" );
gen_static_assert( sizeof( gen_u32 ) == sizeof( gen_s32 ), "sizeof(gen_u32) != sizeof(gen_s32)" );
gen_static_assert( sizeof( gen_u64 ) == sizeof( gen_s64 ), "sizeof(gen_u64) != sizeof(gen_s64)" );

gen_static_assert( sizeof( gen_u8 )  == 1, "sizeof(gen_u8) != 1" );
gen_static_assert( sizeof( gen_u16 ) == 2, "sizeof(gen_u16) != 2" );
gen_static_assert( sizeof( gen_u32 ) == 4, "sizeof(gen_u32) != 4" );
gen_static_assert( sizeof( gen_u64 ) == 8, "sizeof(gen_u64) != 8" );

typedef size_t    gen_usize;
typedef ptrdiff_t gen_ssize;

gen_static_assert( sizeof( gen_usize ) == sizeof( gen_ssize ), "sizeof(gen_usize) != sizeof(gen_ssize)" );

// NOTE: (u)zpl_intptr is only here for semantic reasons really as this library will only support 32/64 gen_bit OSes.
#if defined( _WIN64 )
typedef signed __int64   gen_sptr;
typedef unsigned __int64 gen_uptr;
#elif defined( _WIN32 )
// NOTE; To mark types changing their size, e.g. zpl_intptr
#	ifndef _W64
#		if ! defined( __midl ) && ( defined( _X86_ ) || defined( _M_IX86 ) ) && _MSC_VER >= 1300
#			define _W64 __w64
#		else
#			define _W64
#		endif
#	endif
typedef _W64 signed int   gen_sptr;
typedef _W64 unsigned int gen_uptr;
#else
typedef uintptr_t gen_uptr;
typedef intptr_t  gen_sptr;
#endif

gen_static_assert( sizeof( gen_uptr ) == sizeof( gen_sptr ), "sizeof(gen_uptr) != sizeof(gen_sptr)" );

typedef float  gen_f32;
typedef double gen_f64;

gen_static_assert( sizeof( gen_f32 ) == 4, "sizeof(gen_f32) != 4" );
gen_static_assert( sizeof( gen_f64 ) == 8, "sizeof(gen_f64) != 8" );

typedef gen_s8  gen_b8;
typedef gen_s16 gen_b16;
typedef gen_s32 gen_b32;

typedef void*       gen_mem_ptr;
typedef void const* gen_mem_ptr_const ;

#if GEN_COMPILER_CPP
template<typename Type> gen_uptr gen_to_uptr( Type* ptr ) { return (gen_uptr)ptr; }
template<typename Type> gen_sptr gen_to_sptr( Type* ptr ) { return (gen_sptr)ptr; }

template<typename Type> gen_mem_ptr       gen_to_mem_ptr      ( Type ptr ) { return (gen_mem_ptr)      ptr; }
template<typename Type> gen_mem_ptr_const gen_to_mem_ptr_const( Type ptr ) { return (gen_mem_ptr_const)ptr; }
#else
#define gen_to_uptr( ptr ) ((gen_uptr)(ptr))
#define gen_to_sptr( ptr ) ((gen_sptr)(ptr))

#define gen_to_mem_ptr( ptr)       ((gen_mem_ptr)ptr)
#define gen_to_mem_ptr_const( ptr) ((gen_mem_ptr)ptr)
#endif

#pragma endregion Basic Types

#pragma region Debug

#if GEN_BUILD_DEBUG
#	if defined( GEN_COMPILER_MSVC )
#		if _MSC_VER < 1300
// #pragma message("GEN_BUILD_DEBUG: __asm int 3")
#			define GEN_DEBUG_TRAP() __asm int 3 /* Trap to debugger! */
#		else
// #pragma message("GEN_BUILD_DEBUG: __debugbreak()")
#			define GEN_DEBUG_TRAP() __debugbreak()
#		endif
#	elif defined( GEN_COMPILER_TINYC )
#		define GEN_DEBUG_TRAP() gen_process_exit( 1 )
#	else
#		define GEN_DEBUG_TRAP() __builtin_trap()
#	endif
#else
// #pragma message("GEN_BUILD_DEBUG: omitted")
#	define GEN_DEBUG_TRAP()
#endif

#define GEN_ASSERT( cond ) GEN_ASSERT_MSG( cond, NULL )

#define GEN_ASSERT_MSG( cond, msg, ... )                                                              \
	do                                                                                                \
	{                                                                                                 \
		if ( ! ( cond ) )                                                                             \
		{                                                                                             \
			gen_assert_handler( #cond, __FILE__, __func__, gen_scast( gen_s64, __LINE__ ), msg, ##__VA_ARGS__ );  \
			GEN_DEBUG_TRAP();                                                                         \
		}                                                                                             \
	} while ( 0 )

#define GEN_ASSERT_NOT_NULL( ptr ) GEN_ASSERT_MSG( ( ptr ) != NULL, #ptr " must not be NULL" )

// NOTE: Things that shouldn't happen with a message!
#define GEN_PANIC( msg, ... ) GEN_ASSERT_MSG( 0, msg, ##__VA_ARGS__ )

#if GEN_BUILD_DEBUG
	#define GEN_FATAL( ... )                               \
	do                                                     \
	{                                                      \
		gen_local_persist gen_thread_local                         \
		char buf[GEN_PRINTF_MAXLEN] = { 0 };               \
		                                                   \
		gen_c_str_fmt(buf, GEN_PRINTF_MAXLEN, __VA_ARGS__);    \
		GEN_PANIC(buf);                                    \
	}                                                      \
	while (0)
#else

#	define GEN_FATAL( ... )                  \
	do                                       \
	{                                        \
		gen_c_str_fmt_out_err( __VA_ARGS__ );    \
		GEN_DEBUG_TRAP();                    \
		gen_process_exit(1);                     \
	}                                        \
	while (0)
#endif

GEN_API void gen_assert_handler( char const* condition, char const* file, char const* function, gen_s32 line, char const* msg, ... );
GEN_API gen_s32  gen_assert_crash( char const* condition );
GEN_API void gen_process_exit( gen_u32 code );

#pragma endregion Debug

#pragma region Memory


#define gen_kilobytes(x) ((x) * (gen_s64)(1024))
#define gen_megabytes(x) (gen_kilobytes(x) * (gen_s64)(1024))
#define gen_gigabytes(x) (gen_megabytes(x) * (gen_s64)(1024))
#define gen_terabytes(x) (gen_gigabytes(x) * (gen_s64)(1024))

#define GEN__ONES        (gen_scast(GEN_NS gen_usize, -1) / GEN_U8_MAX)
#define GEN__HIGHS       (GEN__ONES * (GEN_U8_MAX / 2 + 1))
#define GEN__HAS_ZERO(x) (((x) - GEN__ONES) & ~(x) & GEN__HIGHS)

#define gen_swap(a, b)             \
	do                             \
	{                              \
		gen_typeof(a) temp = (a);  \
		(a)                = (b);  \
		(b)                = temp; \
	} while (0)
//! Checks if value is power of 2.
gen_b32 gen_is_power_of_two(gen_ssize x);

//! Aligns address to specified alignment.
void* gen_align_forward(void* ptr, gen_ssize alignment);

//! Aligns value to a specified alignment.
gen_s64 gen_align_forward_by_value(gen_s64 value, gen_ssize alignment);

//! Moves pointer forward by bytes.
void* gen_pointer_add(void* ptr, gen_ssize bytes);

//! Moves pointer forward by bytes.
void const* gen_pointer_add_const(void const* ptr, gen_ssize bytes);

//! Calculates difference between two addresses.
gen_ssize gen_pointer_diff(void const* begin, void const* end);

//! Copy non-overlapping memory from source to destination.
GEN_API void* gen_mem_copy(void* dest, void const* source, gen_ssize size);

//! Search for a constant value within the size limit at memory location.
GEN_API void const* gen_mem_find(void const* data, gen_u8 byte_value, gen_ssize size);

//! Copy memory from source to destination.
void* gen_mem_move(void* dest, void const* source, gen_ssize size);

//! Set constant value at memory location with specified size.
void* gen_mem_set(void* data, gen_u8 byte_value, gen_ssize size);

//! @param ptr Memory location to clear up.
//! @param size The size to clear up with.
void gen_zero_size(void* ptr, gen_ssize size);

//! Clears up an item.
#define gen_zero_item(t) gen_zero_size((t), gen_size_of(*(t)))    // NOTE: Pass pointer of struct

//! Clears up an array.
#define gen_zero_array(a, count) gen_zero_size((a), gen_size_of(*(a)) * count)

enum gen_AllocType gen_enum_underlying(gen_u8)
{
	EAllocation_ALLOC,
	EAllocation_FREE,
	EAllocation_FREE_ALL,
	EAllocation_RESIZE,
};

typedef gen_u8 gen_AllocType;

typedef void*(gen_AllocatorProc)(void*         allocator_data,
                                 gen_AllocType type,
                                 gen_ssize     size,
                                 gen_ssize     alignment,
                                 void*         old_memory,
                                 gen_ssize     old_size,
                                 gen_u64       flags);

struct gen_AllocatorInfo
{
	gen_AllocatorProc* Proc;
	void*              Data;
};
typedef struct gen_AllocatorInfo gen_AllocatorInfo;

enum gen_AllocFlag
{
	ALLOCATOR_FLAG_CLEAR_TO_ZERO = gen_bit(0),
};
typedef enum gen_AllocFlag gen_AllocFlag;

#ifndef GEN_DEFAULT_MEMORY_ALIGNMENT
#define GEN_DEFAULT_MEMORY_ALIGNMENT (2 * gen_size_of(void*))
#endif

#ifndef GEN_DEFAULT_ALLOCATOR_FLAGS
#define GEN_DEFAULT_ALLOCATOR_FLAGS (ALLOCATOR_FLAG_CLEAR_TO_ZERO)
#endif

//! Allocate memory with default alignment.
void* gen_alloc(gen_AllocatorInfo a, gen_ssize size);

//! Allocate memory with specified alignment.
void* gen_alloc_align(gen_AllocatorInfo a, gen_ssize size, gen_ssize alignment);

//! Free allocated memory.
void gen_allocator_free(gen_AllocatorInfo a, void* ptr);

//! Free all memory allocated by an allocator.
void gen_free_all(gen_AllocatorInfo a);

//! Resize an allocated memory.
void* gen_resize(gen_AllocatorInfo a, void* ptr, gen_ssize old_size, gen_ssize new_size);

//! Resize an allocated memory with specified alignment.
void* gen_resize_align(gen_AllocatorInfo a, void* ptr, gen_ssize old_size, gen_ssize new_size, gen_ssize alignment);

//! Allocate memory for an item.
#define gen_alloc_item(allocator_, Type) (Type*)gen_alloc(allocator_, gen_size_of(Type))

//! Allocate memory for an array of items.
#define gen_alloc_array(allocator_, Type, count) (Type*)gen_alloc(allocator_, gen_size_of(Type) * (count))

/* gen_heap memory analysis tools */
/* define GEN_HEAP_ANALYSIS to enable this feature */
/* call zpl_heap_stats_init at the beginning of the entry point */
/* you can call zpl_heap_stats_check near the end of the execution to validate any possible leaks */
GEN_API void      gen_heap_stats_init(void);
GEN_API gen_ssize gen_heap_stats_used_memory(void);
GEN_API gen_ssize gen_heap_stats_alloc_count(void);
GEN_API void      gen_heap_stats_check(void);

//! Allocate/Resize memory using default options.

//! Use this if you don't need a "fancy" gen_resize allocation
void* gen_default_resize_align(gen_AllocatorInfo a, void* ptr, gen_ssize old_size, gen_ssize new_size, gen_ssize alignment);

GEN_API void*
    gen_heap_allocator_proc(void* allocator_data, gen_AllocType type, gen_ssize size, gen_ssize alignment, void* old_memory, gen_ssize old_size, gen_u64 flags);

//! The gen_heap allocator backed by operating system's memory manager.
#define gen_heap()                           \
	(gen_AllocatorInfo)                      \
	{                                        \
		gen_heap_allocator_proc, gen_nullptr \
	}
//! Helper to allocate memory using gen_heap allocator.
#define gen_malloc(sz) gen_alloc(gen_heap(), sz)

//! Helper to free memory allocated by gen_heap allocator.
#define gen_mfree(ptr) free(gen_heap(), ptr)

struct gen_VirtualMemory
{
	void*     data;
	gen_ssize size;
};
typedef struct gen_VirtualMemory gen_VirtualMemory;

//! Initialize virtual memory from existing data.
GEN_API gen_VirtualMemory gen_vm_from_memory(void* data, gen_ssize size);

//! Allocate virtual memory at address with size.

//! @param addr The starting address of the region to reserve. If NULL, it lets operating system to decide where to allocate it.
//! @param size The size to serve.
GEN_API gen_VirtualMemory gen_vm_alloc(void* addr, gen_ssize size);

//! Release the virtual memory.
GEN_API gen_b32 gen_vm_free(gen_VirtualMemory vm);

//! Trim virtual memory.
GEN_API gen_VirtualMemory gen_vm_trim(gen_VirtualMemory vm, gen_ssize lead_size, gen_ssize size);

//! Purge virtual memory.
GEN_API gen_b32 gen_vm_purge(gen_VirtualMemory vm);

//! Retrieve VM's page size and alignment.
GEN_API gen_ssize gen_virtual_memory_page_size(gen_ssize* alignment_out);

#pragma region gen_Arena

struct gen_Arena;
typedef struct gen_Arena gen_Arena;

gen_AllocatorInfo gen_arena_allocator_info(gen_Arena* arena);

// Remove static keyword and rename allocator_proc
GEN_API void* gen_arena_allocator_proc(
    void*         allocator_data,
    gen_AllocType type,
    gen_ssize     size,
    gen_ssize     alignment,
    void*         old_memory,
    gen_ssize     old_size,
    gen_u64       flags
);

// Add these declarations after the gen_Arena struct
gen_Arena gen_arena_init_from_allocator(gen_AllocatorInfo backing, gen_ssize size);
gen_Arena gen_arena_init_from_memory(void* start, gen_ssize size);

gen_Arena gen_arena_init_sub(gen_Arena* parent, gen_ssize size);
gen_ssize gen_arena_alignment_of(gen_Arena* arena, gen_ssize alignment);
void      gen_arena_check(gen_Arena* arena);
void      gen_arena_free(gen_Arena* arena);
gen_ssize gen_arena_size_remaining(gen_Arena* arena, gen_ssize alignment);

struct gen_Arena
{
	gen_AllocatorInfo Backing;
	void*             PhysicalStart;
	gen_ssize         TotalSize;
	gen_ssize         TotalUsed;
	gen_ssize         TempCount;
};
typedef struct gen_Arena gen_Arena;

inline gen_AllocatorInfo gen_arena_allocator_info(gen_Arena* arena)
{
	GEN_ASSERT(arena != gen_nullptr);
	gen_AllocatorInfo info = { gen_arena_allocator_proc, arena };
	return info;
}

inline gen_Arena gen_arena_init_from_memory(void* start, gen_ssize size)
{
	gen_Arena arena = {
		{ gen_nullptr, gen_nullptr },
		start,
		size,
		0,
		0
	};
	return arena;
}

inline gen_Arena gen_arena_init_from_allocator(gen_AllocatorInfo backing, gen_ssize size)
{
	gen_Arena result = { backing, gen_alloc(backing, size), size, 0, 0 };
	return result;
}

inline gen_Arena gen_arena_init_sub(gen_Arena* parent, gen_ssize size)
{
	GEN_ASSERT(parent != gen_nullptr);
	return gen_arena_init_from_allocator(parent->Backing, size);
}

inline gen_ssize gen_arena_alignment_of(gen_Arena* arena, gen_ssize alignment)
{
	GEN_ASSERT(arena != gen_nullptr);
	gen_ssize alignment_offset, result_pointer, mask;
	GEN_ASSERT(gen_is_power_of_two(alignment));

	alignment_offset = 0;
	result_pointer   = (gen_ssize)arena->PhysicalStart + arena->TotalUsed;
	mask             = alignment - 1;

	if (result_pointer & mask)
		alignment_offset = alignment - (result_pointer & mask);

	return alignment_offset;
}

inline void gen_arena_check(gen_Arena* arena)
{
	GEN_ASSERT(arena != gen_nullptr);
	GEN_ASSERT(arena->TempCount == 0);
}

inline void gen_arena_free(gen_Arena* arena)
{
	GEN_ASSERT(arena != gen_nullptr);
	if (arena->Backing.Proc)
	{
		gen_allocator_free(arena->Backing, arena->PhysicalStart);
		arena->PhysicalStart = gen_nullptr;
	}
}

inline gen_ssize gen_arena_size_remaining(gen_Arena* arena, gen_ssize alignment)
{
	GEN_ASSERT(arena != gen_nullptr);
	gen_ssize result = arena->TotalSize - (arena->TotalUsed + gen_arena_alignment_of(arena, alignment));
	return result;
}

#pragma endregion gen_Arena


#pragma region FixedArena

struct gen_FixedArena_1KB
{
	char      memory[gen_kilobytes(1)];
	gen_Arena arena;
};
typedef struct gen_FixedArena_1KB gen_FixedArena_1KB;

struct gen_FixedArena_4KB
{
	char      memory[gen_kilobytes(4)];
	gen_Arena arena;
};
typedef struct gen_FixedArena_4KB gen_FixedArena_4KB;

struct gen_FixedArena_8KB
{
	char      memory[gen_kilobytes(8)];
	gen_Arena arena;
};
typedef struct gen_FixedArena_8KB gen_FixedArena_8KB;

struct gen_FixedArena_16KB
{
	char      memory[gen_kilobytes(16)];
	gen_Arena arena;
};
typedef struct gen_FixedArena_16KB gen_FixedArena_16KB;

struct gen_FixedArena_32KB
{
	char      memory[gen_kilobytes(32)];
	gen_Arena arena;
};
typedef struct gen_FixedArena_32KB gen_FixedArena_32KB;

struct gen_FixedArena_64KB
{
	char      memory[gen_kilobytes(64)];
	gen_Arena arena;
};
typedef struct gen_FixedArena_64KB gen_FixedArena_64KB;

struct gen_FixedArena_128KB
{
	char      memory[gen_kilobytes(128)];
	gen_Arena arena;
};
typedef struct gen_FixedArena_128KB gen_FixedArena_128KB;

struct gen_FixedArena_256KB
{
	char      memory[gen_kilobytes(256)];
	gen_Arena arena;
};
typedef struct gen_FixedArena_256KB gen_FixedArena_256KB;

struct gen_FixedArena_512KB
{
	char      memory[gen_kilobytes(512)];
	gen_Arena arena;
};
typedef struct gen_FixedArena_512KB gen_FixedArena_512KB;

struct gen_FixedArena_1MB
{
	char      memory[gen_megabytes(1)];
	gen_Arena arena;
};
typedef struct gen_FixedArena_1MB gen_FixedArena_1MB;

struct gen_FixedArena_2MB
{
	char      memory[gen_megabytes(2)];
	gen_Arena arena;
};
typedef struct gen_FixedArena_2MB gen_FixedArena_2MB;

struct gen_FixedArena_4MB
{
	char      memory[gen_megabytes(4)];
	gen_Arena arena;
};
typedef struct gen_FixedArena_4MB gen_FixedArena_4MB;

inline void gen_fixed_arena_init_1KB(gen_FixedArena_1KB* result)
{
	result->arena = gen_arena_init_from_memory(&result->memory[0], gen_kilobytes(1));
}

inline gen_ssize gen_fixed_arena_size_remaining_1KB(gen_FixedArena_1KB* fixed_arena, gen_ssize alignment)
{
	return gen_arena_size_remaining(&fixed_arena->arena, alignment);
}

inline void gen_fixed_arena_free_1KB(gen_FixedArena_1KB* fixed_arena)
{
	gen_arena_free(&fixed_arena->arena);
}

inline void gen_fixed_arena_init_4KB(gen_FixedArena_4KB* result)
{
	result->arena = gen_arena_init_from_memory(&result->memory[0], gen_kilobytes(4));
}

inline gen_ssize gen_fixed_arena_size_remaining_4KB(gen_FixedArena_4KB* fixed_arena, gen_ssize alignment)
{
	return gen_arena_size_remaining(&fixed_arena->arena, alignment);
}

inline void gen_fixed_arena_free_4KB(gen_FixedArena_4KB* fixed_arena)
{
	gen_arena_free(&fixed_arena->arena);
}

inline void gen_fixed_arena_init_8KB(gen_FixedArena_8KB* result)
{
	result->arena = gen_arena_init_from_memory(&result->memory[0], gen_kilobytes(8));
}

inline gen_ssize gen_fixed_arena_size_remaining_8KB(gen_FixedArena_8KB* fixed_arena, gen_ssize alignment)
{
	return gen_arena_size_remaining(&fixed_arena->arena, alignment);
}

inline void gen_fixed_arena_free_8KB(gen_FixedArena_8KB* fixed_arena)
{
	gen_arena_free(&fixed_arena->arena);
}

inline void gen_fixed_arena_init_16KB(gen_FixedArena_16KB* result)
{
	result->arena = gen_arena_init_from_memory(&result->memory[0], gen_kilobytes(16));
}

inline gen_ssize gen_fixed_arena_size_remaining_16KB(gen_FixedArena_16KB* fixed_arena, gen_ssize alignment)
{
	return gen_arena_size_remaining(&fixed_arena->arena, alignment);
}

inline void gen_fixed_arena_free_16KB(gen_FixedArena_16KB* fixed_arena)
{
	gen_arena_free(&fixed_arena->arena);
}

inline void gen_fixed_arena_init_32KB(gen_FixedArena_32KB* result)
{
	result->arena = gen_arena_init_from_memory(&result->memory[0], gen_kilobytes(32));
}

inline gen_ssize gen_fixed_arena_size_remaining_32KB(gen_FixedArena_32KB* fixed_arena, gen_ssize alignment)
{
	return gen_arena_size_remaining(&fixed_arena->arena, alignment);
}

inline void gen_fixed_arena_free_32KB(gen_FixedArena_32KB* fixed_arena)
{
	gen_arena_free(&fixed_arena->arena);
}

inline void gen_fixed_arena_init_64KB(gen_FixedArena_64KB* result)
{
	result->arena = gen_arena_init_from_memory(&result->memory[0], gen_kilobytes(64));
}

inline gen_ssize gen_fixed_arena_size_remaining_64KB(gen_FixedArena_64KB* fixed_arena, gen_ssize alignment)
{
	return gen_arena_size_remaining(&fixed_arena->arena, alignment);
}

inline void gen_fixed_arena_free_64KB(gen_FixedArena_64KB* fixed_arena)
{
	gen_arena_free(&fixed_arena->arena);
}

inline void gen_fixed_arena_init_128KB(gen_FixedArena_128KB* result)
{
	result->arena = gen_arena_init_from_memory(&result->memory[0], gen_kilobytes(128));
}

inline gen_ssize gen_fixed_arena_size_remaining_128KB(gen_FixedArena_128KB* fixed_arena, gen_ssize alignment)
{
	return gen_arena_size_remaining(&fixed_arena->arena, alignment);
}

inline void gen_fixed_arena_free_128KB(gen_FixedArena_128KB* fixed_arena)
{
	gen_arena_free(&fixed_arena->arena);
}

inline void gen_fixed_arena_init_256KB(gen_FixedArena_256KB* result)
{
	result->arena = gen_arena_init_from_memory(&result->memory[0], gen_kilobytes(256));
}

inline gen_ssize gen_fixed_arena_size_remaining_256KB(gen_FixedArena_256KB* fixed_arena, gen_ssize alignment)
{
	return gen_arena_size_remaining(&fixed_arena->arena, alignment);
}

inline void gen_fixed_arena_free_256KB(gen_FixedArena_256KB* fixed_arena)
{
	gen_arena_free(&fixed_arena->arena);
}

inline void gen_fixed_arena_init_512KB(gen_FixedArena_512KB* result)
{
	result->arena = gen_arena_init_from_memory(&result->memory[0], gen_kilobytes(512));
}

inline gen_ssize gen_fixed_arena_size_remaining_512KB(gen_FixedArena_512KB* fixed_arena, gen_ssize alignment)
{
	return gen_arena_size_remaining(&fixed_arena->arena, alignment);
}

inline void gen_fixed_arena_free_512KB(gen_FixedArena_512KB* fixed_arena)
{
	gen_arena_free(&fixed_arena->arena);
}

inline void gen_fixed_arena_init_1MB(gen_FixedArena_1MB* result)
{
	result->arena = gen_arena_init_from_memory(&result->memory[0], gen_megabytes(1));
}

inline gen_ssize gen_fixed_arena_size_remaining_1MB(gen_FixedArena_1MB* fixed_arena, gen_ssize alignment)
{
	return gen_arena_size_remaining(&fixed_arena->arena, alignment);
}

inline void gen_fixed_arena_free_1MB(gen_FixedArena_1MB* fixed_arena)
{
	gen_arena_free(&fixed_arena->arena);
}

inline void gen_fixed_arena_init_2MB(gen_FixedArena_2MB* result)
{
	result->arena = gen_arena_init_from_memory(&result->memory[0], gen_megabytes(2));
}

inline gen_ssize gen_fixed_arena_size_remaining_2MB(gen_FixedArena_2MB* fixed_arena, gen_ssize alignment)
{
	return gen_arena_size_remaining(&fixed_arena->arena, alignment);
}

inline void gen_fixed_arena_free_2MB(gen_FixedArena_2MB* fixed_arena)
{
	gen_arena_free(&fixed_arena->arena);
}

inline void gen_fixed_arena_init_4MB(gen_FixedArena_4MB* result)
{
	result->arena = gen_arena_init_from_memory(&result->memory[0], gen_megabytes(4));
}

inline gen_ssize gen_fixed_arena_size_remaining_4MB(gen_FixedArena_4MB* fixed_arena, gen_ssize alignment)
{
	return gen_arena_size_remaining(&fixed_arena->arena, alignment);
}

inline void gen_fixed_arena_free_4MB(gen_FixedArena_4MB* fixed_arena)
{
	gen_arena_free(&fixed_arena->arena);
}

#define gen_fixed_arena_allocator_info(fixed_arena) ((gen_AllocatorInfo) { gen_arena_allocator_proc, &(fixed_arena)->arena })
#define gen_fixed_arena_init(expr)                          \
	_Generic(                                               \
	    (expr),                                             \
	    gen_FixedArena_1KB *: gen_fixed_arena_init_1KB,     \
	    gen_FixedArena_4KB *: gen_fixed_arena_init_4KB,     \
	    gen_FixedArena_8KB *: gen_fixed_arena_init_8KB,     \
	    gen_FixedArena_16KB *: gen_fixed_arena_init_16KB,   \
	    gen_FixedArena_32KB *: gen_fixed_arena_init_32KB,   \
	    gen_FixedArena_64KB *: gen_fixed_arena_init_64KB,   \
	    gen_FixedArena_128KB *: gen_fixed_arena_init_128KB, \
	    gen_FixedArena_256KB *: gen_fixed_arena_init_256KB, \
	    gen_FixedArena_512KB *: gen_fixed_arena_init_512KB, \
	    gen_FixedArena_1MB *: gen_fixed_arena_init_1MB,     \
	    gen_FixedArena_2MB *: gen_fixed_arena_init_2MB,     \
	    gen_FixedArena_4MB *: gen_fixed_arena_init_4MB,     \
	    default: gen_generic_selection_fail                 \
	) GEN_RESOLVED_FUNCTION_CALL(expr)

#define gen_fixed_arena_free(expr)                          \
	_Generic(                                               \
	    (expr),                                             \
	    gen_FixedArena_1KB *: gen_fixed_arena_free_1KB,     \
	    gen_FixedArena_4KB *: gen_fixed_arena_free_4KB,     \
	    gen_FixedArena_8KB *: gen_fixed_arena_free_8KB,     \
	    gen_FixedArena_16KB *: gen_fixed_arena_free_16KB,   \
	    gen_FixedArena_32KB *: gen_fixed_arena_free_32KB,   \
	    gen_FixedArena_64KB *: gen_fixed_arena_free_64KB,   \
	    gen_FixedArena_128KB *: gen_fixed_arena_free_128KB, \
	    gen_FixedArena_256KB *: gen_fixed_arena_free_256KB, \
	    gen_FixedArena_512KB *: gen_fixed_arena_free_512KB, \
	    gen_FixedArena_1MB *: gen_fixed_arena_free_1MB,     \
	    gen_FixedArena_2MB *: gen_fixed_arena_free_2MB,     \
	    gen_FixedArena_4MB *: gen_fixed_arena_free_4MB,     \
	    default: gen_generic_selection_fail                 \
	) GEN_RESOLVED_FUNCTION_CALL(expr)

#define gen_fixed_arena_size_remaining(expr, alignment)               \
	_Generic(                                                         \
	    (expr),                                                       \
	    gen_FixedArena_1KB *: gen_fixed_arena_size_remaining_1KB,     \
	    gen_FixedArena_4KB *: gen_fixed_arena_size_remaining_4KB,     \
	    gen_FixedArena_8KB *: gen_fixed_arena_size_remaining_8KB,     \
	    gen_FixedArena_16KB *: gen_fixed_arena_size_remaining_16KB,   \
	    gen_FixedArena_32KB *: gen_fixed_arena_size_remaining_32KB,   \
	    gen_FixedArena_64KB *: gen_fixed_arena_size_remaining_64KB,   \
	    gen_FixedArena_128KB *: gen_fixed_arena_size_remaining_128KB, \
	    gen_FixedArena_256KB *: gen_fixed_arena_size_remaining_256KB, \
	    gen_FixedArena_512KB *: gen_fixed_arena_size_remaining_512KB, \
	    gen_FixedArena_1MB *: gen_fixed_arena_size_remaining_1MB,     \
	    gen_FixedArena_2MB *: gen_fixed_arena_size_remaining_2MB,     \
	    gen_FixedArena_4MB *: gen_fixed_arena_size_remaining_4MB,     \
	    default: gen_generic_selection_fail                           \
	) GEN_RESOLVED_FUNCTION_CALL(expr, alignment)

#pragma endregion FixedArena


#pragma region gen_Pool

struct gen_Pool;
typedef struct gen_Pool gen_Pool;

GEN_API void*
    gen_pool_allocator_proc(void* allocator_data, gen_AllocType type, gen_ssize size, gen_ssize alignment, void* old_memory, gen_ssize old_size, gen_u64 flags);

gen_Pool          gen_pool_init(gen_AllocatorInfo backing, gen_ssize num_blocks, gen_ssize block_size);
gen_Pool          gen_pool_init_align(gen_AllocatorInfo backing, gen_ssize num_blocks, gen_ssize block_size, gen_ssize block_align);
gen_AllocatorInfo gen_pool_allocator_info(gen_Pool* pool);
GEN_API void      gen_pool_clear(gen_Pool* pool);
void              gen_pool_free(gen_Pool* pool);

struct gen_Pool
{
	gen_AllocatorInfo Backing;
	void*             PhysicalStart;
	void*             FreeList;
	gen_ssize         BlockSize;
	gen_ssize         BlockAlign;
	gen_ssize         TotalSize;
	gen_ssize         NumBlocks;
};
typedef struct gen_Pool gen_Pool;

inline gen_AllocatorInfo gen_pool_allocator_info(gen_Pool* pool)
{
	gen_AllocatorInfo info = { gen_pool_allocator_proc, pool };
	return info;
}

inline gen_Pool gen_pool_init(gen_AllocatorInfo backing, gen_ssize num_blocks, gen_ssize block_size)
{
	return gen_pool_init_align(backing, num_blocks, block_size, GEN_DEFAULT_MEMORY_ALIGNMENT);
}

inline void gen_pool_free(gen_Pool* pool)
{
	if (pool->Backing.Proc)
	{
		gen_allocator_free(pool->Backing, pool->PhysicalStart);
	}
}

#pragma endregion gen_Pool

inline gen_b32 gen_is_power_of_two(gen_ssize x)
{
	if (x <= 0)
		return false;
	return ! (x & (x - 1));
}

inline gen_mem_ptr gen_align_forward(void* ptr, gen_ssize alignment)
{
	GEN_ASSERT(gen_is_power_of_two(alignment));
	gen_uptr p       = gen_to_uptr(ptr);
	gen_uptr forward = (p + (alignment - 1)) & ~(alignment - 1);

	return gen_to_mem_ptr(forward);
}

inline gen_s64 align_forward_s64(gen_s64 value, gen_ssize alignment)
{
	return value + (alignment - value % alignment) % alignment;
}

inline void* gen_pointer_add(void* ptr, gen_ssize bytes)
{
	return gen_rcast(void*, gen_rcast(gen_u8*, ptr) + bytes);
}

inline void const* gen_pointer_add_const(void const* ptr, gen_ssize bytes)
{
	return gen_rcast(void const*, gen_rcast(gen_u8 const*, ptr) + bytes);
}

inline gen_sptr gen_pointer_diff(gen_mem_ptr_const begin, gen_mem_ptr_const end)
{
	return gen_scast(gen_ssize, gen_rcast(gen_u8 const*, end) - gen_rcast(gen_u8 const*, begin));
}

inline void* gen_mem_move(void* destination, void const* source, gen_ssize byte_count)
{
	if (destination == NULL)
	{
		return NULL;
	}

	gen_u8*       dest_ptr = gen_rcast(gen_u8*, destination);
	gen_u8 const* src_ptr  = gen_rcast(gen_u8 const*, source);

	if (dest_ptr == src_ptr)
		return dest_ptr;

	if (src_ptr + byte_count <= dest_ptr || dest_ptr + byte_count <= src_ptr)    // NOTE: Non-overlapping
		return gen_mem_copy(dest_ptr, src_ptr, byte_count);

	if (dest_ptr < src_ptr)
	{
		if (gen_to_uptr(src_ptr) % gen_size_of(gen_ssize) == gen_to_uptr(dest_ptr) % gen_size_of(gen_ssize))
		{
			while (gen_pcast(gen_uptr, dest_ptr) % gen_size_of(gen_ssize))
			{
				if (! byte_count--)
					return destination;

				*dest_ptr++ = *src_ptr++;
			}
			while (byte_count >= gen_size_of(gen_ssize))
			{
				*gen_rcast(gen_ssize*, dest_ptr)  = *gen_rcast(gen_ssize const*, src_ptr);
				byte_count                       -= gen_size_of(gen_ssize);
				dest_ptr                         += gen_size_of(gen_ssize);
				src_ptr                          += gen_size_of(gen_ssize);
			}
		}
		for (; byte_count; byte_count--)
			*dest_ptr++ = *src_ptr++;
	}
	else
	{
		if ((gen_to_uptr(src_ptr) % gen_size_of(gen_ssize)) == (gen_to_uptr(dest_ptr) % gen_size_of(gen_ssize)))
		{
			while (gen_to_uptr(dest_ptr + byte_count) % gen_size_of(gen_ssize))
			{
				if (! byte_count--)
					return destination;

				dest_ptr[byte_count] = src_ptr[byte_count];
			}
			while (byte_count >= gen_size_of(gen_ssize))
			{
				byte_count                                    -= gen_size_of(gen_ssize);
				*gen_rcast(gen_ssize*, dest_ptr + byte_count)  = *gen_rcast(gen_ssize const*, src_ptr + byte_count);
			}
		}
		while (byte_count)
			byte_count--, dest_ptr[byte_count] = src_ptr[byte_count];
	}

	return destination;
}

inline void* gen_mem_set(void* destination, gen_u8 fill_byte, gen_ssize byte_count)
{
	if (destination == NULL)
	{
		return NULL;
	}

	gen_ssize align_offset;
	gen_u8*   dest_ptr  = gen_rcast(gen_u8*, destination);
	gen_u32   fill_word = ((gen_u32)-1) / 255 * fill_byte;

	if (byte_count == 0)
		return destination;

	dest_ptr[0] = dest_ptr[byte_count - 1] = fill_byte;
	if (byte_count < 3)
		return destination;

	dest_ptr[1] = dest_ptr[byte_count - 2] = fill_byte;
	dest_ptr[2] = dest_ptr[byte_count - 3] = fill_byte;
	if (byte_count < 7)
		return destination;

	dest_ptr[3] = dest_ptr[byte_count - 4] = fill_byte;
	if (byte_count < 9)
		return destination;

	align_offset                                       = -gen_to_sptr(dest_ptr) & 3;
	dest_ptr                                          += align_offset;
	byte_count                                        -= align_offset;
	byte_count                                        &= -4;

	*gen_rcast(gen_u32*, (dest_ptr + 0))               = fill_word;
	*gen_rcast(gen_u32*, (dest_ptr + byte_count - 4))  = fill_word;
	if (byte_count < 9)
		return destination;

	*gen_rcast(gen_u32*, dest_ptr + 4)               = fill_word;
	*gen_rcast(gen_u32*, dest_ptr + 8)               = fill_word;
	*gen_rcast(gen_u32*, dest_ptr + byte_count - 12) = fill_word;
	*gen_rcast(gen_u32*, dest_ptr + byte_count - 8)  = fill_word;
	if (byte_count < 25)
		return destination;

	*gen_rcast(gen_u32*, dest_ptr + 12)               = fill_word;
	*gen_rcast(gen_u32*, dest_ptr + 16)               = fill_word;
	*gen_rcast(gen_u32*, dest_ptr + 20)               = fill_word;
	*gen_rcast(gen_u32*, dest_ptr + 24)               = fill_word;
	*gen_rcast(gen_u32*, dest_ptr + byte_count - 28)  = fill_word;
	*gen_rcast(gen_u32*, dest_ptr + byte_count - 24)  = fill_word;
	*gen_rcast(gen_u32*, dest_ptr + byte_count - 20)  = fill_word;
	*gen_rcast(gen_u32*, dest_ptr + byte_count - 16)  = fill_word;

	align_offset                                      = 24 + gen_to_uptr(dest_ptr) & 4;
	dest_ptr                                         += align_offset;
	byte_count                                       -= align_offset;

	{
		gen_u64 fill_doubleword = (gen_scast(gen_u64, fill_word) << 32) | fill_word;
		while (byte_count > 31)
		{
			*gen_rcast(gen_u64*, dest_ptr + 0)   = fill_doubleword;
			*gen_rcast(gen_u64*, dest_ptr + 8)   = fill_doubleword;
			*gen_rcast(gen_u64*, dest_ptr + 16)  = fill_doubleword;
			*gen_rcast(gen_u64*, dest_ptr + 24)  = fill_doubleword;

			byte_count                          -= 32;
			dest_ptr                            += 32;
		}
	}

	return destination;
}

inline void* gen_alloc_align(gen_AllocatorInfo a, gen_ssize size, gen_ssize alignment)
{
	return a.Proc(a.Data, EAllocation_ALLOC, size, alignment, gen_nullptr, 0, GEN_DEFAULT_ALLOCATOR_FLAGS);
}

inline void* gen_alloc(gen_AllocatorInfo a, gen_ssize size)
{
	return gen_alloc_align(a, size, GEN_DEFAULT_MEMORY_ALIGNMENT);
}

inline void gen_allocator_free(gen_AllocatorInfo a, void* ptr)
{
	if (ptr != gen_nullptr)
		a.Proc(a.Data, EAllocation_FREE, 0, 0, ptr, 0, GEN_DEFAULT_ALLOCATOR_FLAGS);
}

inline void gen_free_all(gen_AllocatorInfo a)
{
	a.Proc(a.Data, EAllocation_FREE_ALL, 0, 0, gen_nullptr, 0, GEN_DEFAULT_ALLOCATOR_FLAGS);
}

inline void* gen_resize(gen_AllocatorInfo a, void* ptr, gen_ssize old_size, gen_ssize new_size)
{
	return gen_resize_align(a, ptr, old_size, new_size, GEN_DEFAULT_MEMORY_ALIGNMENT);
}

inline void* gen_resize_align(gen_AllocatorInfo a, void* ptr, gen_ssize old_size, gen_ssize new_size, gen_ssize alignment)
{
	return a.Proc(a.Data, EAllocation_RESIZE, new_size, alignment, ptr, old_size, GEN_DEFAULT_ALLOCATOR_FLAGS);
}

inline void* gen_default_resize_align(gen_AllocatorInfo a, void* old_memory, gen_ssize old_size, gen_ssize new_size, gen_ssize alignment)
{
	if (! old_memory)
		return gen_alloc_align(a, new_size, alignment);

	if (new_size == 0)
	{
		gen_allocator_free(a, old_memory);
		return gen_nullptr;
	}

	if (new_size < old_size)
		new_size = old_size;

	if (old_size == new_size)
	{
		return old_memory;
	}
	else
	{
		void* new_memory = gen_alloc_align(a, new_size, alignment);
		if (! new_memory)
			return gen_nullptr;

		gen_mem_move(new_memory, old_memory, gen_min(new_size, old_size));
		gen_allocator_free(a, old_memory);
		return new_memory;
	}
}

inline void gen_zero_size(void* ptr, gen_ssize size)
{
	gen_mem_set(ptr, 0, size);
}

#pragma endregion Memory

#pragma region Printing


typedef struct gen_FileInfo gen_FileInfo;

#ifndef GEN_PRINTF_MAXLEN
#define GEN_PRINTF_MAXLEN gen_kilobytes(128)
#endif
typedef char gen_PrintF_Buffer[GEN_PRINTF_MAXLEN];

// NOTE: A locally persisting buffer is used internally
GEN_API char*     gen_c_str_fmt_buf(char const* fmt, ...);
GEN_API char*     gen_c_str_fmt_buf_va(char const* fmt, va_list va);
GEN_API gen_ssize gen_c_str_fmt(char* str, gen_ssize n, char const* fmt, ...);
GEN_API gen_ssize gen_c_str_fmt_va(char* str, gen_ssize n, char const* fmt, va_list va);
GEN_API gen_ssize gen_c_str_fmt_out_va(char const* fmt, va_list va);
GEN_API gen_ssize gen_c_str_fmt_out_err(char const* fmt, ...);
GEN_API gen_ssize gen_c_str_fmt_out_err_va(char const* fmt, va_list va);
GEN_API gen_ssize gen_c_str_fmt_file(gen_FileInfo* f, char const* fmt, ...);
GEN_API gen_ssize gen_c_str_fmt_file_va(gen_FileInfo* f, char const* fmt, va_list va);

#define gen_Msg_Invalid_Value "INVALID VALUE PROVIDED"

inline gen_ssize gen_log_fmt(char const* fmt, ...)
{
	gen_ssize res;
	va_list   va;

	va_start(va, fmt);
	res = gen_c_str_fmt_out_va(fmt, va);
	va_end(va);

	return res;
}

#pragma endregion Printing

#pragma region String Ops

const char* gen_char_first_occurence( const char* str, char c );

gen_b32   gen_char_is_alpha( char c );
gen_b32   gen_char_is_alphanumeric( char c );
gen_b32   gen_char_is_digit( char c );
gen_b32   gen_char_is_hex_digit( char c );
gen_b32   gen_char_is_space( char c );
char  gen_char_to_lower( char c );
char  gen_char_to_upper( char c );

gen_s32  gen_digit_to_int( char c );
gen_s32  hex_digit_to_int( char c );

gen_s32         gen_c_str_compare( const char* s1, const char* s2 );
gen_s32         gen_c_str_compare_len( const char* s1, const char* s2, gen_ssize len );
char*       gen_c_str_copy( char* dest, const char* source, gen_ssize len );
gen_ssize       gen_c_str_copy_nulpad( char* dest, const char* source, gen_ssize len );
gen_ssize       gen_c_str_len( const char* str );
gen_ssize       gen_c_str_len_capped( const char* str, gen_ssize max_len );
char*       gen_c_str_reverse( char* str );    // NOTE: ASCII only
char const* gen_c_str_skip( char const* str, char c );
char const* gen_c_str_skip_any( char const* str, char const* gen_char_list );
char const* gen_c_str_trim( char const* str, gen_b32 catch_newline );

// NOTE: ASCII only
void gen_c_str_to_lower( char* str );
void gen_c_str_to_upper( char* str );

GEN_API gen_s64  gen_c_str_to_i64( const char* str, char** gen_end_ptr, gen_s32 base );
GEN_API void gen_i64_to_str( gen_s64 value, char* string, gen_s32 base );
GEN_API void gen_u64_to_str( gen_u64 value, char* string, gen_s32 base );
GEN_API gen_f64  gen_c_str_to_f64( const char* str, char** gen_end_ptr );

inline
const char* gen_char_first_occurence( const char* s, char c )
{
	char ch = c;
	for ( ; *s != ch; s++ )
	{
		if ( *s == '\0' )
			return NULL;
	}
	return s;
}

inline
gen_b32 gen_char_is_alpha( char c )
{
	if ( ( c >= 'A' && c <= 'Z' ) || ( c >= 'a' && c <= 'z' ) )
		return true;
	return false;
}

inline
gen_b32 gen_char_is_alphanumeric( char c )
{
	return gen_char_is_alpha( c ) || gen_char_is_digit( c );
}

inline
gen_b32 gen_char_is_digit( char c )
{
	if ( c >= '0' && c <= '9' )
		return true;
	return false;
}

inline
gen_b32 gen_char_is_hex_digit( char c )
{
	if ( gen_char_is_digit( c ) || ( c >= 'a' && c <= 'f' ) || ( c >= 'A' && c <= 'F' ) )
		return true;
	return false;
}

inline
gen_b32 gen_char_is_space( char c )
{
	if ( c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v' )
		return true;
	return false;
}

inline
char gen_char_to_lower( char c )
{
	if ( c >= 'A' && c <= 'Z' )
		return 'a' + ( c - 'A' );
	return c;
}

inline char gen_char_to_upper( char c )
{
	if ( c >= 'a' && c <= 'z' )
		return 'A' + ( c - 'a' );
	return c;
}

inline
gen_s32 gen_digit_to_int( char c )
{
	return gen_char_is_digit( c ) ? c - '0' : c - 'W';
}

inline
gen_s32 hex_digit_to_int( char c )
{
	if ( gen_char_is_digit( c ) )
		return gen_digit_to_int( c );
	else if ( gen_is_between( c, 'a', 'f' ) )
		return c - 'a' + 10;
	else if ( gen_is_between( c, 'A', 'F' ) )
		return c - 'A' + 10;
	return -1;
}

inline
gen_s32 gen_c_str_compare( const char* s1, const char* s2 )
{
	while ( *s1 && ( *s1 == *s2 ) )
	{
		s1++, s2++;
	}
	return *( gen_u8* )s1 - *( gen_u8* )s2;
}

inline
gen_s32 gen_c_str_compare_len( const char* s1, const char* s2, gen_ssize len )
{
	for ( ; len > 0; s1++, s2++, len-- )
	{
		if ( *s1 != *s2 )
			return ( ( s1 < s2 ) ? -1 : +1 );
		else if ( *s1 == '\0' )
			return 0;
	}
	return 0;
}

inline
char* gen_c_str_copy( char* dest, const char* source, gen_ssize len )
{
	GEN_ASSERT_NOT_NULL( dest );
	if ( source )
	{
		char* str = dest;
		while ( len > 0 && *source )
		{
			*str++ = *source++;
			len--;
		}
		while ( len > 0 )
		{
			*str++ = '\0';
			len--;
		}
	}
	return dest;
}

inline
gen_ssize gen_c_str_copy_nulpad( char* dest, const char* source, gen_ssize len )
{
	gen_ssize result = 0;
	GEN_ASSERT_NOT_NULL( dest );
	if ( source )
	{
		const char* source_start = source;
		char*       str          = dest;
		while ( len > 0 && *source )
		{
			*str++ = *source++;
			len--;
		}
		while ( len > 0 )
		{
			*str++ = '\0';
			len--;
		}

		result = source - source_start;
	}
	return result;
}

inline
gen_ssize gen_c_str_len( const char* str )
{
	if ( str == NULL )
	{
		return 0;
	}
	const char* p = str;
	while ( *str )
		str++;
	return str - p;
}

inline
gen_ssize gen_c_str_len_capped( const char* str, gen_ssize max_len )
{
	const char* end = gen_rcast(const char*, gen_mem_find( str, 0, max_len ));
	if ( end )
		return end - str;
	return max_len;
}

inline
char* gen_c_str_reverse( char* str )
{
	gen_ssize    len  = gen_c_str_len( str );
	char* a    = str + 0;
	char* b    = str + len - 1;
	len       /= 2;
	while ( len-- )
	{
		gen_swap( *a, *b );
		a++, b--;
	}
	return str;
}

inline
char const* gen_c_str_skip( char const* str, char c )
{
	while ( *str && *str != c )
	{
		++str;
	}
	return str;
}

inline
char const* gen_c_str_skip_any( char const* str, char const* gen_char_list )
{
	char const* closest_ptr     = gen_rcast( char const*, gen_pointer_add_const( gen_rcast(gen_mem_ptr_const, str), gen_c_str_len( str ) ));
	gen_ssize       gen_char_list_count = gen_c_str_len( gen_char_list );
	for ( gen_ssize i = 0; i < gen_char_list_count; i++ )
	{
		char const* p = gen_c_str_skip( str, gen_char_list[ i ] );
		closest_ptr   = gen_min( closest_ptr, p );
	}
	return closest_ptr;
}

inline
char const* gen_c_str_trim( char const* str, gen_b32 catch_newline )
{
	while ( *str && gen_char_is_space( *str ) && ( ! catch_newline || ( catch_newline && *str != '\n' ) ) )
	{
		++str;
	}
	return str;
}

inline
void gen_c_str_to_lower( char* str )
{
	if ( ! str )
		return;
	while ( *str )
	{
		*str = gen_char_to_lower( *str );
		str++;
	}
}

inline
void gen_c_str_to_upper( char* str )
{
	if ( ! str )
		return;
	while ( *str )
	{
		*str = gen_char_to_upper( *str );
		str++;
	}
}

#pragma endregion String Ops

#pragma region Containers

typedef struct gen_ArrayHeader gen_ArrayHeader;

struct gen_ArrayHeader
{
	gen_AllocatorInfo Allocator;
	gen_usize         Capacity;
	gen_usize         Num;
};

#define gen_Array(Type)               gen_Array_##Type
#define gen_array_grow_formula(value) (2 * value + 8)
#define gen_array_get_header(self)    ((gen_ArrayHeader*)(self) - 1)
#define gen_array_begin(array)        (array)
#define gen_array_end(array)          (array + gen_array_get_header(array)->Num)
#define gen_array_next(array, entry)  (entry + 1)

#define gen_array_init(selector_arg, ...)                                                                                                                     \
	_Generic(                                                                                                                                                 \
	    (*(selector_arg*)NULL),                                                                                                                               \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_init) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_init          \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_init) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_init)       \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_init) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_init)     \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_init) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_init) \
	                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_init)                                                                    \
	                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_init) default: gen_generic_selection_fail                           \
	) GEN_RESOLVED_FUNCTION_CALL(__VA_ARGS__)

#define gen_array_init_reserve(selector_arg, ...)                                                                                                           \
	_Generic(                                                                                                                                               \
	    (*(selector_arg*)NULL),                                                                                                                             \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_init_reserve                                                                       \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_init_reserve)                                                                    \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_init_reserve)                                                                  \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_init_reserve)                                                              \
	                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_init_reserve)                                                          \
	                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_init_reserve)                                                      \
	                        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_init_reserve)                                                  \
	                            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_init_reserve)                                              \
	                                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_init_reserve)                                          \
	                                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_init_reserve) default: gen_generic_selection_fail \
	) GEN_RESOLVED_FUNCTION_CALL(__VA_ARGS__)

#define gen_array_append(selector_arg, ...)                                                                                                                   \
	_Generic(                                                                                                                                                 \
	    (selector_arg),                                                                                                                                       \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_append) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_append      \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_append) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_append    \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_append) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_append)   \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_append) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_append) \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_append)                                                                      \
	                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_append) default: gen_generic_selection_fail                             \
	) GEN_RESOLVED_FUNCTION_CALL(&selector_arg, __VA_ARGS__)

#define gen_array_append_at(selector_arg, ...)                                                                                                                 \
	_Generic(                                                                                                                                                  \
	    (selector_arg),                                                                                                                                        \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_append_at) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_append_at \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_append_at)                                                                          \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_append_at)                                                                        \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_append_at)                                                                    \
	                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_append_at)                                                                \
	                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_append_at)                                                            \
	                        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_append_at)                                                        \
	                            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_append_at)                                                    \
	                                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_append_at) default: gen_generic_selection_fail           \
	) GEN_RESOLVED_FUNCTION_CALL(&selector_arg, __VA_ARGS__)

#define gen_array_append_items(selector_arg, ...)                                                                                                           \
	_Generic(                                                                                                                                               \
	    (selector_arg),                                                                                                                                     \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_append_items                                                                       \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_append_items)                                                                    \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_append_items)                                                                  \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_append_items)                                                              \
	                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_append_items)                                                          \
	                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_append_items)                                                      \
	                        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_append_items)                                                  \
	                            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_append_items)                                              \
	                                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_append_items)                                          \
	                                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_append_items) default: gen_generic_selection_fail \
	) GEN_RESOLVED_FUNCTION_CALL(&selector_arg, __VA_ARGS__)

#define gen_array_append_items_at(selector_arg, ...)                                                                                                           \
	_Generic(                                                                                                                                                  \
	    (selector_arg),                                                                                                                                        \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_append_items_at                                                                       \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_append_items_at)                                                                    \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_append_items_at)                                                                  \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_append_items_at)                                                              \
	                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_append_items_at)                                                          \
	                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_append_items_at)                                                      \
	                        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_append_items_at)                                                  \
	                            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_append_items_at)                                              \
	                                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_append_items_at)                                          \
	                                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_append_items_at) default: gen_generic_selection_fail \
	) GEN_RESOLVED_FUNCTION_CALL(&selector_arg, __VA_ARGS__)

#define gen_array_back(selector_arg, ...)                                                                                                                     \
	_Generic(                                                                                                                                                 \
	    (selector_arg),                                                                                                                                       \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_back) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_back          \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_back) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_back)       \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_back) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_back)     \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_back) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_back) \
	                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_back)                                                                    \
	                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_back) default: gen_generic_selection_fail                           \
	) GEN_RESOLVED_FUNCTION_CALL(selector_arg)

#define gen_array_clear(selector_arg, ...)                                                                                                                  \
	_Generic(                                                                                                                                               \
	    (selector_arg),                                                                                                                                     \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_clear) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_clear      \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_clear) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_clear    \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_clear) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_clear)   \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_clear) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_clear) \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_clear)                                                                     \
	                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_clear) default: gen_generic_selection_fail                            \
	) GEN_RESOLVED_FUNCTION_CALL(selector_arg)

#define gen_array_fill(selector_arg, ...)                                                                                                                     \
	_Generic(                                                                                                                                                 \
	    (selector_arg),                                                                                                                                       \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_fill) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_fill          \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_fill) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_fill)       \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_fill) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_fill)     \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_fill) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_fill) \
	                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_fill)                                                                    \
	                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_fill) default: gen_generic_selection_fail                           \
	) GEN_RESOLVED_FUNCTION_CALL(selector_arg, __VA_ARGS__)

#define gen_array_free(selector_arg, ...)                                                                                                                     \
	_Generic(                                                                                                                                                 \
	    (selector_arg),                                                                                                                                       \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_free) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_free          \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_free) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_free)       \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_free) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_free)     \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_free) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_free) \
	                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_free)                                                                    \
	                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_free) default: gen_generic_selection_fail                           \
	) GEN_RESOLVED_FUNCTION_CALL(&selector_arg)

#define gen_array_grow(selector_arg, ...)                                                                                                                     \
	_Generic(                                                                                                                                                 \
	    (selector_arg),                                                                                                                                       \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_grow) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_grow          \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_grow) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_grow)       \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_grow) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_grow)     \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_grow) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_grow) \
	                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_grow)                                                                    \
	                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_grow) default: gen_generic_selection_fail                           \
	) GEN_RESOLVED_FUNCTION_CALL(selector_arg, __VA_ARGS__)

#define gen_array_num(selector_arg, ...)                                                                                                                    \
	_Generic(                                                                                                                                               \
	    (selector_arg),                                                                                                                                     \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_num) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_num          \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_num) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_num)       \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_num) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_num)     \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_num) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_num) \
	                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_num)                                                                   \
	                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_num) default: gen_generic_selection_fail                          \
	) GEN_RESOLVED_FUNCTION_CALL(selector_arg)

#define gen_array_pop(selector_arg, ...)                                                                                                                    \
	_Generic(                                                                                                                                               \
	    (selector_arg),                                                                                                                                     \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_pop) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_pop          \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_pop) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_pop)       \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_pop) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_pop)     \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_pop) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_pop) \
	                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_pop)                                                                   \
	                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_pop) default: gen_generic_selection_fail                          \
	) GEN_RESOLVED_FUNCTION_CALL(selector_arg)

#define gen_array_remove_at(selector_arg, ...)                                                                                                                 \
	_Generic(                                                                                                                                                  \
	    (selector_arg),                                                                                                                                        \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_remove_at) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_remove_at \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_remove_at)                                                                          \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_remove_at)                                                                        \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_remove_at)                                                                    \
	                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_remove_at)                                                                \
	                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_remove_at)                                                            \
	                        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_remove_at)                                                        \
	                            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_remove_at)                                                    \
	                                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_remove_at) default: gen_generic_selection_fail           \
	) GEN_RESOLVED_FUNCTION_CALL(selector_arg, __VA_ARGS__)

#define gen_array_reserve(selector_arg, ...)                                                                                                                  \
	_Generic(                                                                                                                                                 \
	    (selector_arg),                                                                                                                                       \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_reserve) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_reserve    \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_reserve) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_reserve  \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_reserve) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_reserve  \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_reserve) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_reserve) \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_reserve)                                                                         \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_reserve) default: gen_generic_selection_fail                                \
	) GEN_RESOLVED_FUNCTION_CALL(&selector_arg, __VA_ARGS__)

#define gen_array_resize(selector_arg, ...)                                                                                                                   \
	_Generic(                                                                                                                                                 \
	    (selector_arg),                                                                                                                                       \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_resize) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_resize      \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_resize) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_resize    \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_resize) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_resize)   \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_resize) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_resize) \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_resize)                                                                      \
	                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_resize) default: gen_generic_selection_fail                             \
	) GEN_RESOLVED_FUNCTION_CALL(&selector_arg, __VA_ARGS__)

#define gen_array_set_capacity(selector_arg, ...)                                                                                                           \
	_Generic(                                                                                                                                               \
	    (selector_arg),                                                                                                                                     \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__array_set_capacity                                                                       \
	    ) GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__array_set_capacity)                                                                    \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_3__array_set_capacity)                                                                  \
	            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_4__array_set_capacity)                                                              \
	                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_5__array_set_capacity)                                                          \
	                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_6__array_set_capacity)                                                      \
	                        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_7__array_set_capacity)                                                  \
	                            GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_8__array_set_capacity)                                              \
	                                GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_9__array_set_capacity)                                          \
	                                    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_10__array_set_capacity) default: gen_generic_selection_fail \
	) GEN_RESOLVED_FUNCTION_CALL(selector_arg, __VA_ARGS__)

typedef struct gen_HT_FindResult_Def gen_HT_FindResult;

struct gen_HT_FindResult_Def
{
	gen_ssize HashIndex;
	gen_ssize PrevIndex;
	gen_ssize EntryIndex;
};

#define gen_HashTable(_type)            struct gen_HashTable_##_type
#define gen_HashTable_CriticalLoadScale 0.7f

#define gen_hashtable_init(selector_arg, ...)                                                                              \
	_Generic(                                                                                                              \
	    (*(selector_arg*)NULL),                                                                                            \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__hashtable_init)                                         \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__hashtable_init) default: gen_generic_selection_fail \
	) GEN_RESOLVED_FUNCTION_CALL(__VA_ARGS__)

#define gen_hashtable_init_reserve(selector_arg, ...)                                                                              \
	_Generic(                                                                                                                      \
	    (*(selector_arg*)NULL),                                                                                                    \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__hashtable_init_reserve)                                         \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__hashtable_init_reserve) default: gen_generic_selection_fail \
	) GEN_RESOLVED_FUNCTION_CALL(__VA_ARGS__)

#define gen_hashtable_clear(selector_arg, ...)                                                                              \
	_Generic(                                                                                                               \
	    (selector_arg),                                                                                                     \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__hashtable_clear)                                         \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__hashtable_clear) default: gen_generic_selection_fail \
	) GEN_RESOLVED_FUNCTION_CALL(selector_arg)

#define gen_hashtable_destroy(selector_arg, ...)                                                                              \
	_Generic(                                                                                                                 \
	    (selector_arg),                                                                                                       \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__hashtable_destroy)                                         \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__hashtable_destroy) default: gen_generic_selection_fail \
	) GEN_RESOLVED_FUNCTION_CALL(&selector_arg)

#define gen_hashtable_get(selector_arg, ...)                                                                              \
	_Generic(                                                                                                             \
	    (selector_arg),                                                                                                   \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__hashtable_get)                                         \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__hashtable_get) default: gen_generic_selection_fail \
	) GEN_RESOLVED_FUNCTION_CALL(selector_arg, __VA_ARGS__)

#define gen_hashtable_grow(selector_arg, ...)                                                                              \
	_Generic(                                                                                                              \
	    (selector_arg),                                                                                                    \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__hashtable_grow)                                         \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__hashtable_grow) default: gen_generic_selection_fail \
	) GEN_RESOLVED_FUNCTION_CALL(selector_arg)

#define gen_hashtable_rehash(selector_arg, ...)                                                                              \
	_Generic(                                                                                                                \
	    (selector_arg),                                                                                                      \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__hashtable_rehash)                                         \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__hashtable_rehash) default: gen_generic_selection_fail \
	) GEN_RESOLVED_FUNCTION_CALL(selector_arg, __VA_ARGS__)

#define gen_hashtable_rehash_fast(selector_arg, ...)                                                                              \
	_Generic(                                                                                                                     \
	    (selector_arg),                                                                                                           \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__hashtable_rehash_fast)                                         \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__hashtable_rehash_fast) default: gen_generic_selection_fail \
	) GEN_RESOLVED_FUNCTION_CALL(selector_arg)

#define gen_hashtable_remove(selector_arg, ...)                                                                              \
	_Generic(                                                                                                                \
	    (selector_arg),                                                                                                      \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__hashtable_remove)                                         \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__hashtable_remove) default: gen_generic_selection_fail \
	) GEN_RESOLVED_FUNCTION_CALL(selector_arg, __VA_ARGS__)

#define gen_hashtable_remove_entry(selector_arg, ...)                                                                              \
	_Generic(                                                                                                                      \
	    (selector_arg),                                                                                                            \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__hashtable_remove_entry)                                         \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__hashtable_remove_entry) default: gen_generic_selection_fail \
	) GEN_RESOLVED_FUNCTION_CALL(selector_arg, __VA_ARGS__)

#define gen_hashtable_set(selector_arg, ...)                                                                              \
	_Generic(                                                                                                             \
	    (selector_arg),                                                                                                   \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__hashtable_set)                                         \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__hashtable_set) default: gen_generic_selection_fail \
	) GEN_RESOLVED_FUNCTION_CALL(&selector_arg, __VA_ARGS__)

#define gen_hashtable_slot(selector_arg, ...)                                                                              \
	_Generic(                                                                                                              \
	    (selector_arg),                                                                                                    \
	    GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_1__hashtable_slot)                                         \
	        GEN_IF_MACRO_DEFINED_INCLUDE_THIS_SLOT(GEN_GENERIC_SLOT_2__hashtable_slot) default: gen_generic_selection_fail \
	) GEN_RESOLVED_FUNCTION_CALL(selector_arg, __VA_ARGS__)

#pragma region gen_Array_gen_ssize

#define GEN_GENERIC_SLOT_1__array_init            gen_ssize, gen_Array_gen_ssize_init
#define GEN_GENERIC_SLOT_1__array_init_reserve    gen_ssize, gen_Array_gen_ssize_init_reserve
#define GEN_GENERIC_SLOT_1__array_append          gen_Array_gen_ssize, gen_Array_gen_ssize_append
#define GEN_GENERIC_SLOT_1__array_append_items    gen_Array_gen_ssize, gen_Array_gen_ssize_append_items
#define GEN_GENERIC_SLOT_1__array_append_at       gen_Array_gen_ssize, gen_Array_gen_ssize_append_at
#define GEN_GENERIC_SLOT_1__array_append_items_at gen_Array_gen_ssize, gen_Array_gen_ssize_append_items_at
#define GEN_GENERIC_SLOT_1__array_back            gen_Array_gen_ssize, gen_Array_gen_ssize_back
#define GEN_GENERIC_SLOT_1__array_clear           gen_Array_gen_ssize, gen_Array_gen_ssize_clear
#define GEN_GENERIC_SLOT_1__array_fill            gen_Array_gen_ssize, gen_Array_gen_ssize_fill
#define GEN_GENERIC_SLOT_1__array_free            gen_Array_gen_ssize, gen_Array_gen_ssize_free
#define GEN_GENERIC_SLOT_1__array_grow            gen_Array_gen_ssize*, gen_Array_gen_ssize_grow
#define GEN_GENERIC_SLOT_1__array_num             gen_Array_gen_ssize, gen_Array_gen_ssize_num
#define GEN_GENERIC_SLOT_1__array_pop             gen_Array_gen_ssize, gen_Array_gen_ssize_pop
#define GEN_GENERIC_SLOT_1__array_remove_at       gen_Array_gen_ssize, gen_Array_gen_ssize_remove_at
#define GEN_GENERIC_SLOT_1__array_reserve         gen_Array_gen_ssize, gen_Array_gen_ssize_reserve
#define GEN_GENERIC_SLOT_1__array_resize          gen_Array_gen_ssize, gen_Array_gen_ssize_resize
#define GEN_GENERIC_SLOT_1__array_set_capacity    gen_Array_gen_ssize*, gen_Array_gen_ssize_set_capacity

typedef gen_ssize*  gen_Array_gen_ssize;
gen_Array_gen_ssize gen_Array_gen_ssize_init(gen_AllocatorInfo allocator);
gen_Array_gen_ssize gen_Array_gen_ssize_init_reserve(gen_AllocatorInfo allocator, gen_usize capacity);
bool                gen_Array_gen_ssize_append_array(gen_Array_gen_ssize* self, gen_Array_gen_ssize other);
bool                gen_Array_gen_ssize_append(gen_Array_gen_ssize* self, gen_ssize value);
bool                gen_Array_gen_ssize_append_items(gen_Array_gen_ssize* self, gen_ssize* items, gen_usize item_num);
bool                gen_Array_gen_ssize_append_at(gen_Array_gen_ssize* self, gen_ssize item, gen_usize idx);
bool                gen_Array_gen_ssize_append_items_at(gen_Array_gen_ssize* self, gen_ssize* items, gen_usize item_num, gen_usize idx);
gen_ssize*          gen_Array_gen_ssize_back(gen_Array_gen_ssize self);
void                gen_Array_gen_ssize_clear(gen_Array_gen_ssize self);
bool                gen_Array_gen_ssize_fill(gen_Array_gen_ssize self, gen_usize begin, gen_usize end, gen_ssize value);
void                gen_Array_gen_ssize_free(gen_Array_gen_ssize* self);
bool                gen_Array_gen_ssize_grow(gen_Array_gen_ssize* self, gen_usize min_capacity);
gen_usize           gen_Array_gen_ssize_num(gen_Array_gen_ssize self);
gen_ssize           gen_Array_gen_ssize_pop(gen_Array_gen_ssize self);
void                gen_Array_gen_ssize_remove_at(gen_Array_gen_ssize self, gen_usize idx);
bool                gen_Array_gen_ssize_reserve(gen_Array_gen_ssize* self, gen_usize new_capacity);
bool                gen_Array_gen_ssize_resize(gen_Array_gen_ssize* self, gen_usize num);
bool                gen_Array_gen_ssize_set_capacity(gen_Array_gen_ssize* self, gen_usize new_capacity);

gen_forceinline gen_Array_gen_ssize gen_Array_gen_ssize_init(gen_AllocatorInfo allocator)
{
	size_t initial_size = gen_array_grow_formula(0);
	return gen_array_init_reserve(gen_ssize, allocator, initial_size);
}

inline gen_Array_gen_ssize gen_Array_gen_ssize_init_reserve(gen_AllocatorInfo allocator, gen_usize capacity)
{
	GEN_ASSERT(capacity > 0);
	gen_ArrayHeader* header = gen_rcast(gen_ArrayHeader*, gen_alloc(allocator, sizeof(gen_ArrayHeader) + sizeof(gen_ssize) * capacity));
	if (header == gen_nullptr)
		return gen_nullptr;
	header->Allocator = allocator;
	header->Capacity  = capacity;
	header->Num       = 0;
	return gen_rcast(gen_ssize*, header + 1);
}

gen_forceinline bool gen_Array_gen_ssize_append_array(gen_Array_gen_ssize* self, gen_Array_gen_ssize other)
{
	return gen_array_append_items(*self, (gen_Array_gen_ssize)other, gen_Array_gen_ssize_num(other));
}

inline bool gen_Array_gen_ssize_append(gen_Array_gen_ssize* self, gen_ssize value)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Num == header->Capacity)
	{
		if (! gen_array_grow(self, header->Capacity))
			return false;
		header = gen_array_get_header(*self);
	}
	(*self)[header->Num] = value;
	header->Num++;
	return true;
}

inline bool gen_Array_gen_ssize_append_items(gen_Array_gen_ssize* self, gen_ssize* items, gen_usize item_num)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(items != gen_nullptr);
	GEN_ASSERT(item_num > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Num + item_num > header->Capacity)
	{
		if (! gen_array_grow(self, header->Capacity + item_num))
			return false;
		header = gen_array_get_header(*self);
	}
	gen_mem_copy((*self) + header->Num, items, sizeof(gen_ssize) * item_num);
	header->Num += item_num;
	return true;
}

inline bool gen_Array_gen_ssize_append_at(gen_Array_gen_ssize* self, gen_ssize item, gen_usize idx)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (idx >= header->Num)
		idx = header->Num - 1;
	if (idx < 0)
		idx = 0;
	if (header->Capacity < header->Num + 1)
	{
		if (! gen_array_grow(self, header->Capacity + 1))
			return false;
		header = gen_array_get_header(*self);
	}
	gen_Array_gen_ssize target = (*self) + idx;
	gen_mem_move(target + 1, target, (header->Num - idx) * sizeof(gen_ssize));
	header->Num++;
	return true;
}

inline bool gen_Array_gen_ssize_append_items_at(gen_Array_gen_ssize* self, gen_ssize* items, gen_usize item_num, gen_usize idx)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (idx >= header->Num)
	{
		return gen_array_append_items(*self, items, item_num);
	}
	if (item_num > header->Capacity)
	{
		if (! gen_array_grow(self, item_num + header->Capacity))
			return false;
		header = gen_array_get_header(*self);
	}
	gen_ssize* target = (*self) + idx + item_num;
	gen_ssize* src    = (*self) + idx;
	gen_mem_move(target, src, (header->Num - idx) * sizeof(gen_ssize));
	gen_mem_copy(src, items, item_num * sizeof(gen_ssize));
	header->Num += item_num;
	return true;
}

inline gen_ssize* gen_Array_gen_ssize_back(gen_Array_gen_ssize self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	if (header->Num == 0)
		return 0;
	return self + header->Num - 1;
}

inline void gen_Array_gen_ssize_clear(gen_Array_gen_ssize self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	header->Num             = 0;
}

inline bool gen_Array_gen_ssize_fill(gen_Array_gen_ssize self, gen_usize begin, gen_usize end, gen_ssize value)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(begin <= end);
	gen_ArrayHeader* header = gen_array_get_header(self);
	if (begin < 0 || end > header->Num)
		return false;
	for (gen_ssize idx = (gen_ssize)begin; idx < (gen_ssize)end; idx++)
		self[idx] = value;
	return true;
}

inline void gen_Array_gen_ssize_free(gen_Array_gen_ssize* self)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	gen_allocator_free(header->Allocator, header);
	self = 0;
}

inline bool gen_Array_gen_ssize_grow(gen_Array_gen_ssize* self, gen_usize min_capacity)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(min_capacity > 0);
	gen_ArrayHeader* header       = gen_array_get_header(*self);
	gen_usize        new_capacity = gen_array_grow_formula(header->Capacity);
	if (new_capacity < min_capacity)
		new_capacity = min_capacity;
	return gen_array_set_capacity(self, new_capacity);
}

gen_forceinline gen_usize gen_Array_gen_ssize_num(gen_Array_gen_ssize self)
{
	GEN_ASSERT(self != gen_nullptr);
	return gen_array_get_header(self)->Num;
}

inline gen_ssize gen_Array_gen_ssize_pop(gen_Array_gen_ssize self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	GEN_ASSERT(header->Num > 0);
	gen_ssize result = self[header->Num - 1];
	header->Num--;
	return result;
}

gen_forceinline void gen_Array_gen_ssize_remove_at(gen_Array_gen_ssize self, gen_usize idx)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	GEN_ASSERT(idx < header->Num);
	gen_mem_move(self + idx, self + idx + 1, sizeof(gen_ssize) * (header->Num - idx - 1));
	header->Num--;
}

inline bool gen_Array_gen_ssize_reserve(gen_Array_gen_ssize* self, gen_usize new_capacity)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(new_capacity > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Capacity < new_capacity)
		return gen_array_set_capacity(self, new_capacity);
	return true;
}

inline bool gen_Array_gen_ssize_resize(gen_Array_gen_ssize* self, gen_usize num)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(num > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Capacity < num)
	{
		if (! gen_array_grow(self, num))
			return false;
		header = gen_array_get_header(*self);
	}
	header->Num = num;
	return true;
}

inline bool gen_Array_gen_ssize_set_capacity(gen_Array_gen_ssize* self, gen_usize new_capacity)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(new_capacity > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (new_capacity == header->Capacity)
		return true;
	if (new_capacity < header->Num)
	{
		header->Num = new_capacity;
		return true;
	}
	gen_usize        size       = sizeof(gen_ArrayHeader) + sizeof(gen_ssize) * new_capacity;
	gen_ArrayHeader* new_header = gen_cast(gen_ArrayHeader*, gen_alloc(header->Allocator, size));
	if (new_header == 0)
		return false;
	gen_mem_move(new_header, header, sizeof(gen_ArrayHeader) + sizeof(gen_ssize) * header->Num);
	new_header->Capacity = new_capacity;
	gen_allocator_free(header->Allocator, &header);
	*self = gen_cast(gen_ssize*, new_header + 1);
	return true;
}

#pragma endregion gen_Array_gen_ssize

#pragma region gen_Array_gen_u8

#define GEN_GENERIC_SLOT_4__array_init            gen_u8, gen_Array_gen_u8_init
#define GEN_GENERIC_SLOT_4__array_init_reserve    gen_u8, gen_Array_gen_u8_init_reserve
#define GEN_GENERIC_SLOT_4__array_append          gen_Array_gen_u8, gen_Array_gen_u8_append
#define GEN_GENERIC_SLOT_4__array_append_items    gen_Array_gen_u8, gen_Array_gen_u8_append_items
#define GEN_GENERIC_SLOT_4__array_append_at       gen_Array_gen_u8, gen_Array_gen_u8_append_at
#define GEN_GENERIC_SLOT_4__array_append_items_at gen_Array_gen_u8, gen_Array_gen_u8_append_items_at
#define GEN_GENERIC_SLOT_4__array_back            gen_Array_gen_u8, gen_Array_gen_u8_back
#define GEN_GENERIC_SLOT_4__array_clear           gen_Array_gen_u8, gen_Array_gen_u8_clear
#define GEN_GENERIC_SLOT_4__array_fill            gen_Array_gen_u8, gen_Array_gen_u8_fill
#define GEN_GENERIC_SLOT_4__array_free            gen_Array_gen_u8, gen_Array_gen_u8_free
#define GEN_GENERIC_SLOT_4__array_grow            gen_Array_gen_u8*, gen_Array_gen_u8_grow
#define GEN_GENERIC_SLOT_4__array_num             gen_Array_gen_u8, gen_Array_gen_u8_num
#define GEN_GENERIC_SLOT_4__array_pop             gen_Array_gen_u8, gen_Array_gen_u8_pop
#define GEN_GENERIC_SLOT_4__array_remove_at       gen_Array_gen_u8, gen_Array_gen_u8_remove_at
#define GEN_GENERIC_SLOT_4__array_reserve         gen_Array_gen_u8, gen_Array_gen_u8_reserve
#define GEN_GENERIC_SLOT_4__array_resize          gen_Array_gen_u8, gen_Array_gen_u8_resize
#define GEN_GENERIC_SLOT_4__array_set_capacity    gen_Array_gen_u8*, gen_Array_gen_u8_set_capacity

typedef gen_u8*  gen_Array_gen_u8;
gen_Array_gen_u8 gen_Array_gen_u8_init(gen_AllocatorInfo allocator);
gen_Array_gen_u8 gen_Array_gen_u8_init_reserve(gen_AllocatorInfo allocator, gen_usize capacity);
bool             gen_Array_gen_u8_append_array(gen_Array_gen_u8* self, gen_Array_gen_u8 other);
bool             gen_Array_gen_u8_append(gen_Array_gen_u8* self, gen_u8 value);
bool             gen_Array_gen_u8_append_items(gen_Array_gen_u8* self, gen_u8* items, gen_usize item_num);
bool             gen_Array_gen_u8_append_at(gen_Array_gen_u8* self, gen_u8 item, gen_usize idx);
bool             gen_Array_gen_u8_append_items_at(gen_Array_gen_u8* self, gen_u8* items, gen_usize item_num, gen_usize idx);
gen_u8*          gen_Array_gen_u8_back(gen_Array_gen_u8 self);
void             gen_Array_gen_u8_clear(gen_Array_gen_u8 self);
bool             gen_Array_gen_u8_fill(gen_Array_gen_u8 self, gen_usize begin, gen_usize end, gen_u8 value);
void             gen_Array_gen_u8_free(gen_Array_gen_u8* self);
bool             gen_Array_gen_u8_grow(gen_Array_gen_u8* self, gen_usize min_capacity);
gen_usize        gen_Array_gen_u8_num(gen_Array_gen_u8 self);
gen_u8           gen_Array_gen_u8_pop(gen_Array_gen_u8 self);
void             gen_Array_gen_u8_remove_at(gen_Array_gen_u8 self, gen_usize idx);
bool             gen_Array_gen_u8_reserve(gen_Array_gen_u8* self, gen_usize new_capacity);
bool             gen_Array_gen_u8_resize(gen_Array_gen_u8* self, gen_usize num);
bool             gen_Array_gen_u8_set_capacity(gen_Array_gen_u8* self, gen_usize new_capacity);

gen_forceinline gen_Array_gen_u8 gen_Array_gen_u8_init(gen_AllocatorInfo allocator)
{
	size_t initial_size = gen_array_grow_formula(0);
	return gen_array_init_reserve(gen_u8, allocator, initial_size);
}

inline gen_Array_gen_u8 gen_Array_gen_u8_init_reserve(gen_AllocatorInfo allocator, gen_usize capacity)
{
	GEN_ASSERT(capacity > 0);
	gen_ArrayHeader* header = gen_rcast(gen_ArrayHeader*, gen_alloc(allocator, sizeof(gen_ArrayHeader) + sizeof(gen_u8) * capacity));
	if (header == gen_nullptr)
		return gen_nullptr;
	header->Allocator = allocator;
	header->Capacity  = capacity;
	header->Num       = 0;
	return gen_rcast(gen_u8*, header + 1);
}

gen_forceinline bool gen_Array_gen_u8_append_array(gen_Array_gen_u8* self, gen_Array_gen_u8 other)
{
	return gen_array_append_items(*self, (gen_Array_gen_u8)other, gen_Array_gen_u8_num(other));
}

inline bool gen_Array_gen_u8_append(gen_Array_gen_u8* self, gen_u8 value)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Num == header->Capacity)
	{
		if (! gen_array_grow(self, header->Capacity))
			return false;
		header = gen_array_get_header(*self);
	}
	(*self)[header->Num] = value;
	header->Num++;
	return true;
}

inline bool gen_Array_gen_u8_append_items(gen_Array_gen_u8* self, gen_u8* items, gen_usize item_num)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(items != gen_nullptr);
	GEN_ASSERT(item_num > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Num + item_num > header->Capacity)
	{
		if (! gen_array_grow(self, header->Capacity + item_num))
			return false;
		header = gen_array_get_header(*self);
	}
	gen_mem_copy((*self) + header->Num, items, sizeof(gen_u8) * item_num);
	header->Num += item_num;
	return true;
}

inline bool gen_Array_gen_u8_append_at(gen_Array_gen_u8* self, gen_u8 item, gen_usize idx)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (idx >= header->Num)
		idx = header->Num - 1;
	if (idx < 0)
		idx = 0;
	if (header->Capacity < header->Num + 1)
	{
		if (! gen_array_grow(self, header->Capacity + 1))
			return false;
		header = gen_array_get_header(*self);
	}
	gen_Array_gen_u8 target = (*self) + idx;
	gen_mem_move(target + 1, target, (header->Num - idx) * sizeof(gen_u8));
	header->Num++;
	return true;
}

inline bool gen_Array_gen_u8_append_items_at(gen_Array_gen_u8* self, gen_u8* items, gen_usize item_num, gen_usize idx)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (idx >= header->Num)
	{
		return gen_array_append_items(*self, items, item_num);
	}
	if (item_num > header->Capacity)
	{
		if (! gen_array_grow(self, item_num + header->Capacity))
			return false;
		header = gen_array_get_header(*self);
	}
	gen_u8* target = (*self) + idx + item_num;
	gen_u8* src    = (*self) + idx;
	gen_mem_move(target, src, (header->Num - idx) * sizeof(gen_u8));
	gen_mem_copy(src, items, item_num * sizeof(gen_u8));
	header->Num += item_num;
	return true;
}

inline gen_u8* gen_Array_gen_u8_back(gen_Array_gen_u8 self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	if (header->Num == 0)
		return 0;
	return self + header->Num - 1;
}

inline void gen_Array_gen_u8_clear(gen_Array_gen_u8 self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	header->Num             = 0;
}

inline bool gen_Array_gen_u8_fill(gen_Array_gen_u8 self, gen_usize begin, gen_usize end, gen_u8 value)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(begin <= end);
	gen_ArrayHeader* header = gen_array_get_header(self);
	if (begin < 0 || end > header->Num)
		return false;
	for (gen_ssize idx = (gen_ssize)begin; idx < (gen_ssize)end; idx++)
		self[idx] = value;
	return true;
}

inline void gen_Array_gen_u8_free(gen_Array_gen_u8* self)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	gen_allocator_free(header->Allocator, header);
	self = 0;
}

inline bool gen_Array_gen_u8_grow(gen_Array_gen_u8* self, gen_usize min_capacity)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(min_capacity > 0);
	gen_ArrayHeader* header       = gen_array_get_header(*self);
	gen_usize        new_capacity = gen_array_grow_formula(header->Capacity);
	if (new_capacity < min_capacity)
		new_capacity = min_capacity;
	return gen_array_set_capacity(self, new_capacity);
}

gen_forceinline gen_usize gen_Array_gen_u8_num(gen_Array_gen_u8 self)
{
	GEN_ASSERT(self != gen_nullptr);
	return gen_array_get_header(self)->Num;
}

inline gen_u8 gen_Array_gen_u8_pop(gen_Array_gen_u8 self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	GEN_ASSERT(header->Num > 0);
	gen_u8 result = self[header->Num - 1];
	header->Num--;
	return result;
}

gen_forceinline void gen_Array_gen_u8_remove_at(gen_Array_gen_u8 self, gen_usize idx)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	GEN_ASSERT(idx < header->Num);
	gen_mem_move(self + idx, self + idx + 1, sizeof(gen_u8) * (header->Num - idx - 1));
	header->Num--;
}

inline bool gen_Array_gen_u8_reserve(gen_Array_gen_u8* self, gen_usize new_capacity)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(new_capacity > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Capacity < new_capacity)
		return gen_array_set_capacity(self, new_capacity);
	return true;
}

inline bool gen_Array_gen_u8_resize(gen_Array_gen_u8* self, gen_usize num)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(num > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Capacity < num)
	{
		if (! gen_array_grow(self, num))
			return false;
		header = gen_array_get_header(*self);
	}
	header->Num = num;
	return true;
}

inline bool gen_Array_gen_u8_set_capacity(gen_Array_gen_u8* self, gen_usize new_capacity)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(new_capacity > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (new_capacity == header->Capacity)
		return true;
	if (new_capacity < header->Num)
	{
		header->Num = new_capacity;
		return true;
	}
	gen_usize        size       = sizeof(gen_ArrayHeader) + sizeof(gen_u8) * new_capacity;
	gen_ArrayHeader* new_header = gen_cast(gen_ArrayHeader*, gen_alloc(header->Allocator, size));
	if (new_header == 0)
		return false;
	gen_mem_move(new_header, header, sizeof(gen_ArrayHeader) + sizeof(gen_u8) * header->Num);
	new_header->Capacity = new_capacity;
	gen_allocator_free(header->Allocator, &header);
	*self = gen_cast(gen_u8*, new_header + 1);
	return true;
}

#pragma endregion gen_Array_gen_u8

#pragma endregion Containers

#pragma region Hashing

GEN_API gen_u32 gen_crc32( void const* data, gen_ssize len );
GEN_API gen_u64 gen_crc64( void const* data, gen_ssize len );

#pragma endregion Hashing

#pragma region Strings


typedef struct gen_Str gen_Str;
struct gen_Str;

gen_Str     gen_to_str_from_c_str(char const* bad_string);
bool        gen_str_are_equal(gen_Str lhs, gen_Str rhs);
char const* gen_str_back(gen_Str str);
bool        gen_str_contains(gen_Str str, gen_Str substring);
gen_Str     gen_str_duplicate(gen_Str str, gen_AllocatorInfo allocator);
gen_b32     gen_str_starts_with(gen_Str str, gen_Str substring);
gen_Str     gen_str_visualize_whitespace(gen_Str str, gen_AllocatorInfo allocator);

// Constant string with length.
struct gen_Str
{
	char const* Ptr;
	gen_ssize   Len;
};

#define gen_cast_to_str(str) *gen_rcast(gen_Str*, (str) - sizeof(gen_ssize))

#ifndef txt
#define txt(text)                \
	(GEN_NS gen_Str)             \
	{                            \
		(text), sizeof(text) - 1 \
	}
#endif

GEN_API_C_BEGIN

gen_forceinline char const* gen_str_begin(gen_Str str)
{
	return str.Ptr;
}

gen_forceinline char const* gen_str_end(gen_Str str)
{
	return str.Ptr + str.Len;
}

gen_forceinline char const* gen_str_next(gen_Str str, char const* iter)
{
	return iter + 1;
}

GEN_API_C_END

inline bool gen_str_are_equal(gen_Str lhs, gen_Str rhs)
{
	if (lhs.Len != rhs.Len)
		return false;

	for (gen_ssize idx = 0; idx < lhs.Len; ++idx)
		if (lhs.Ptr[idx] != rhs.Ptr[idx])
			return false;

	return true;
}

inline char const* gen_str_back(gen_Str str)
{
	return &str.Ptr[str.Len - 1];
}

inline bool gen_str_contains(gen_Str str, gen_Str substring)
{
	if (substring.Len > str.Len)
		return false;

	gen_ssize main_len = str.Len;
	gen_ssize sub_len  = substring.Len;
	for (gen_ssize idx = 0; idx <= main_len - sub_len; ++idx)
	{
		if (gen_c_str_compare_len(str.Ptr + idx, substring.Ptr, sub_len) == 0)
			return true;
	}
	return false;
}

inline gen_b32 gen_str_starts_with(gen_Str str, gen_Str substring)
{
	if (substring.Len > str.Len)
		return false;

	gen_b32 result = gen_c_str_compare_len(str.Ptr, substring.Ptr, substring.Len) == 0;
	return result;
}

inline gen_Str gen_to_str_from_c_str(char const* bad_str)
{
	gen_Str result = { bad_str, gen_c_str_len(bad_str) };
	return result;
}

// Dynamic gen_StrBuilder
// This is directly based off the ZPL string api.
// They used a header pattern
// I kept it for simplicty of porting but its not necessary to keep it that way.
#pragma region gen_StrBuilder

typedef struct gen_StrBuilderHeader gen_StrBuilderHeader;
struct gen_StrBuilderHeader;


typedef char* gen_StrBuilder;

gen_forceinline gen_usize gen_strbuilder_grow_formula(gen_usize value);

GEN_API gen_StrBuilder gen_strbuilder_make_reserve(gen_AllocatorInfo allocator, gen_ssize capacity);
GEN_API gen_StrBuilder gen_strbuilder_make_length(gen_AllocatorInfo allocator, char const* str, gen_ssize length);

gen_StrBuilder        gen_strbuilder_make_c_str(gen_AllocatorInfo allocator, char const* str);
gen_StrBuilder        gen_strbuilder_make_str(gen_AllocatorInfo allocator, gen_Str str);
gen_StrBuilder        gen_strbuilder_fmt(gen_AllocatorInfo allocator, char* buf, gen_ssize buf_size, char const* fmt, ...);
gen_StrBuilder        gen_strbuilder_fmt_buf(gen_AllocatorInfo allocator, char const* fmt, ...);
gen_StrBuilder        gen_strbuilder_join(gen_AllocatorInfo allocator, char const** parts, gen_ssize num_parts, char const* glue);
bool                  gen_strbuilder_are_equal(gen_StrBuilder const lhs, gen_StrBuilder const rhs);
bool                  gen_strbuilder_are_equal_str(gen_StrBuilder const lhs, gen_Str rhs);
bool                  gen_strbuilder_make_space_for(gen_StrBuilder* str, char const* to_append, gen_ssize add_len);
bool                  gen_strbuilder_append_char(gen_StrBuilder* str, char c);
bool                  gen_strbuilder_append_c_str(gen_StrBuilder* str, char const* gen_c_str_to_append);
bool                  gen_strbuilder_append_c_str_len(gen_StrBuilder* str, char const* gen_c_str_to_append, gen_ssize length);
bool                  gen_strbuilder_append_str(gen_StrBuilder* str, gen_Str gen_c_str_to_append);
bool                  gen_strbuilder_append_string(gen_StrBuilder* str, gen_StrBuilder const other);
bool                  gen_strbuilder_append_fmt(gen_StrBuilder* str, char const* fmt, ...);
gen_ssize             gen_strbuilder_avail_space(gen_StrBuilder const str);
char*                 gen_strbuilder_back(gen_StrBuilder str);
bool                  gen_strbuilder_contains_str(gen_StrBuilder const str, gen_Str substring);
bool                  gen_strbuilder_contains_string(gen_StrBuilder const str, gen_StrBuilder const substring);
gen_ssize             gen_strbuilder_capacity(gen_StrBuilder const str);
void                  gen_strbuilder_clear(gen_StrBuilder str);
gen_StrBuilder        gen_strbuilder_duplicate(gen_StrBuilder const str, gen_AllocatorInfo allocator);
void                  gen_strbuilder_free(gen_StrBuilder* str);
gen_StrBuilderHeader* gen_strbuilder_get_header(gen_StrBuilder str);
gen_ssize             gen_strbuilder_length(gen_StrBuilder const str);
gen_b32               gen_strbuilder_starts_with_str(gen_StrBuilder const str, gen_Str substring);
gen_b32               gen_strbuilder_starts_with_string(gen_StrBuilder const str, gen_StrBuilder substring);
void                  gen_strbuilder_skip_line(gen_StrBuilder str);
void                  gen_strbuilder_strip_space(gen_StrBuilder str);
gen_Str               gen_strbuilder_to_str(gen_StrBuilder str);
void                  gen_strbuilder_trim(gen_StrBuilder str, char const* cut_set);
void                  gen_strbuilder_trim_space(gen_StrBuilder str);
gen_StrBuilder        gen_strbuilder_visualize_whitespace(gen_StrBuilder const str);

struct gen_StrBuilderHeader
{
	gen_AllocatorInfo Allocator;
	gen_ssize         Capacity;
	gen_ssize         Length;
};

gen_forceinline char* gen_strbuilder_begin(gen_StrBuilder str)
{
	return ((char*)str);
}

gen_forceinline char* gen_strbuilder_end(gen_StrBuilder str)
{
	return ((char*)str + gen_strbuilder_length(str));
}

gen_forceinline char* gen_strbuilder_next(gen_StrBuilder str, char const* iter)
{
	return ((char*)iter + 1);
}

gen_forceinline gen_usize gen_strbuilder_grow_formula(gen_usize value)
{
	// Using a very aggressive growth formula to reduce time mem_copying with recursive calls to append in this library.
	return 4 * value + 8;
}

gen_forceinline gen_StrBuilder gen_strbuilder_make_c_str(gen_AllocatorInfo allocator, char const* str)
{
	gen_ssize length = str ? gen_c_str_len(str) : 0;
	return gen_strbuilder_make_length(allocator, str, length);
}

gen_forceinline gen_StrBuilder gen_strbuilder_make_str(gen_AllocatorInfo allocator, gen_Str str)
{
	return gen_strbuilder_make_length(allocator, str.Ptr, str.Len);
}

inline gen_StrBuilder gen_strbuilder_fmt(gen_AllocatorInfo allocator, char* buf, gen_ssize buf_size, char const* fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	gen_ssize res = gen_c_str_fmt_va(buf, buf_size, fmt, va) - 1;
	va_end(va);

	return gen_strbuilder_make_length(allocator, buf, res);
}

inline gen_StrBuilder gen_strbuilder_fmt_buf(gen_AllocatorInfo allocator, char const* fmt, ...)
{
	gen_local_persist gen_thread_local gen_PrintF_Buffer buf = gen_struct_init(gen_PrintF_Buffer, { 0 });

	va_list va;
	va_start(va, fmt);
	gen_ssize res = gen_c_str_fmt_va(buf, GEN_PRINTF_MAXLEN, fmt, va) - 1;
	va_end(va);

	return gen_strbuilder_make_length(allocator, buf, res);
}

inline gen_StrBuilder gen_strbuilder_join(gen_AllocatorInfo allocator, char const** parts, gen_ssize num_parts, char const* glue)
{
	gen_StrBuilder result = gen_strbuilder_make_c_str(allocator, "");

	for (gen_ssize idx = 0; idx < num_parts; ++idx)
	{
		gen_strbuilder_append_c_str(&result, parts[idx]);

		if (idx < num_parts - 1)
			gen_strbuilder_append_c_str(&result, glue);
	}

	return result;
}

gen_forceinline bool gen_strbuilder_append_char(gen_StrBuilder* str, char c)
{
	GEN_ASSERT(str != gen_nullptr);
	return gen_strbuilder_append_c_str_len(str, (char const*)&c, (gen_ssize)1);
}

gen_forceinline bool gen_strbuilder_append_c_str(gen_StrBuilder* str, char const* gen_c_str_to_append)
{
	GEN_ASSERT(str != gen_nullptr);
	return gen_strbuilder_append_c_str_len(str, gen_c_str_to_append, gen_c_str_len(gen_c_str_to_append));
}

inline bool gen_strbuilder_append_c_str_len(gen_StrBuilder* str, char const* gen_c_str_to_append, gen_ssize append_length)
{
	GEN_ASSERT(str != gen_nullptr);
	if (gen_rcast(gen_sptr, gen_c_str_to_append) > 0)
	{
		gen_ssize curr_len = gen_strbuilder_length(*str);

		if (! gen_strbuilder_make_space_for(str, gen_c_str_to_append, append_length))
			return false;

		gen_StrBuilderHeader* header = gen_strbuilder_get_header(*str);

		char* Data                   = *str;
		gen_mem_copy(Data + curr_len, gen_c_str_to_append, append_length);

		Data[curr_len + append_length] = '\0';

		header->Length                 = curr_len + append_length;
	}
	return gen_c_str_to_append != gen_nullptr;
}

gen_forceinline bool gen_strbuilder_append_str(gen_StrBuilder* str, gen_Str gen_c_str_to_append)
{
	GEN_ASSERT(str != gen_nullptr);
	return gen_strbuilder_append_c_str_len(str, gen_c_str_to_append.Ptr, gen_c_str_to_append.Len);
}

gen_forceinline bool gen_strbuilder_append_string(gen_StrBuilder* str, gen_StrBuilder const other)
{
	GEN_ASSERT(str != gen_nullptr);
	return gen_strbuilder_append_c_str_len(str, (char const*)other, gen_strbuilder_length(other));
}

inline bool gen_strbuilder_append_fmt(gen_StrBuilder* str, char const* fmt, ...)
{
	GEN_ASSERT(str != gen_nullptr);
	gen_ssize res;
	char      buf[GEN_PRINTF_MAXLEN] = { 0 };

	va_list va;
	va_start(va, fmt);
	res = gen_c_str_fmt_va(buf, gen_count_of(buf) - 1, fmt, va) - 1;
	va_end(va);

	return gen_strbuilder_append_c_str_len(str, (char const*)buf, res);
}

inline bool gen_strbuilder_are_equal_string(gen_StrBuilder const lhs, gen_StrBuilder const rhs)
{
	if (gen_strbuilder_length(lhs) != gen_strbuilder_length(rhs))
		return false;

	for (gen_ssize idx = 0; idx < gen_strbuilder_length(lhs); ++idx)
		if (lhs[idx] != rhs[idx])
			return false;

	return true;
}

inline bool gen_strbuilder_are_equal_str(gen_StrBuilder const lhs, gen_Str rhs)
{
	if (gen_strbuilder_length(lhs) != (rhs.Len))
		return false;

	for (gen_ssize idx = 0; idx < gen_strbuilder_length(lhs); ++idx)
		if (lhs[idx] != rhs.Ptr[idx])
			return false;

	return true;
}

gen_forceinline gen_ssize gen_strbuilder_avail_space(gen_StrBuilder const str)
{
	gen_StrBuilderHeader const* header = gen_rcast(gen_StrBuilderHeader const*, gen_scast(char const*, str) - sizeof(gen_StrBuilderHeader));
	return header->Capacity - header->Length;
}

gen_forceinline char* gen_strbuilder_back(gen_StrBuilder str)
{
	return &(str)[gen_strbuilder_length(str) - 1];
}

inline bool gen_strbuilder_contains_StrC(gen_StrBuilder const str, gen_Str substring)
{
	gen_StrBuilderHeader const* header = gen_rcast(gen_StrBuilderHeader const*, gen_scast(char const*, str) - sizeof(gen_StrBuilderHeader));

	if (substring.Len > header->Length)
		return false;

	gen_ssize main_len = header->Length;
	gen_ssize sub_len  = substring.Len;

	for (gen_ssize idx = 0; idx <= main_len - sub_len; ++idx)
	{
		if (gen_c_str_compare_len(str + idx, substring.Ptr, sub_len) == 0)
			return true;
	}

	return false;
}

inline bool gen_strbuilder_contains_string(gen_StrBuilder const str, gen_StrBuilder const substring)
{
	gen_StrBuilderHeader const* header = gen_rcast(gen_StrBuilderHeader const*, gen_scast(char const*, str) - sizeof(gen_StrBuilderHeader));

	if (gen_strbuilder_length(substring) > header->Length)
		return false;

	gen_ssize main_len = header->Length;
	gen_ssize sub_len  = gen_strbuilder_length(substring);

	for (gen_ssize idx = 0; idx <= main_len - sub_len; ++idx)
	{
		if (gen_c_str_compare_len(str + idx, substring, sub_len) == 0)
			return true;
	}

	return false;
}

gen_forceinline gen_ssize gen_strbuilder_capacity(gen_StrBuilder const str)
{
	gen_StrBuilderHeader const* header = gen_rcast(gen_StrBuilderHeader const*, gen_scast(char const*, str) - sizeof(gen_StrBuilderHeader));
	return header->Capacity;
}

gen_forceinline void gen_strbuilder_clear(gen_StrBuilder str)
{
	gen_strbuilder_get_header(str)->Length = 0;
}

gen_forceinline gen_StrBuilder gen_strbuilder_duplicate(gen_StrBuilder const str, gen_AllocatorInfo allocator)
{
	return gen_strbuilder_make_length(allocator, str, gen_strbuilder_length(str));
}

gen_forceinline void gen_strbuilder_free(gen_StrBuilder* str)
{
	GEN_ASSERT(str != gen_nullptr);
	if (! (*str))
		return;

	gen_StrBuilderHeader* header = gen_strbuilder_get_header(*str);
	gen_allocator_free(header->Allocator, header);
}

gen_forceinline gen_StrBuilderHeader* gen_strbuilder_get_header(gen_StrBuilder str)
{
	return (gen_StrBuilderHeader*)(gen_scast(char*, str) - sizeof(gen_StrBuilderHeader));
}

gen_forceinline gen_ssize gen_strbuilder_length(gen_StrBuilder const str)
{
	gen_StrBuilderHeader const* header = gen_rcast(gen_StrBuilderHeader const*, gen_scast(char const*, str) - sizeof(gen_StrBuilderHeader));
	return header->Length;
}

inline bool gen_strbuilder_make_space_for(gen_StrBuilder* str, char const* to_append, gen_ssize add_len)
{
	gen_ssize available = gen_strbuilder_avail_space(*str);

	if (available >= add_len)
	{
		return true;
	}
	else
	{
		gen_ssize new_len, old_size, new_size;
		void*     ptr;
		void*     new_ptr;

		gen_AllocatorInfo     allocator = gen_strbuilder_get_header(*str)->Allocator;
		gen_StrBuilderHeader* header    = gen_nullptr;

		new_len                         = gen_strbuilder_grow_formula(gen_strbuilder_length(*str) + add_len);
		ptr                             = gen_strbuilder_get_header(*str);
		old_size                        = gen_size_of(gen_StrBuilderHeader) + gen_strbuilder_length(*str) + 1;
		new_size                        = gen_size_of(gen_StrBuilderHeader) + new_len + 1;

		new_ptr                         = gen_resize(allocator, ptr, old_size, new_size);

		if (new_ptr == gen_nullptr)
			return false;

		header            = gen_rcast(gen_StrBuilderHeader*, new_ptr);
		header->Allocator = allocator;
		header->Capacity  = new_len;

		char** Data       = gen_rcast(char**, str);
		*Data             = gen_rcast(char*, header + 1);

		return true;
	}
}

gen_forceinline gen_b32 gen_strbuilder_starts_with_str(gen_StrBuilder const str, gen_Str substring)
{
	if (substring.Len > gen_strbuilder_length(str))
		return false;

	gen_b32 result = gen_c_str_compare_len(str, substring.Ptr, substring.Len) == 0;
	return result;
}

gen_forceinline gen_b32 gen_strbuilder_starts_with_string(gen_StrBuilder const str, gen_StrBuilder substring)
{
	if (gen_strbuilder_length(substring) > gen_strbuilder_length(str))
		return false;

	gen_b32 result = gen_c_str_compare_len(str, substring, gen_strbuilder_length(substring) - 1) == 0;
	return result;
}

inline void gen_strbuilder_skip_line(gen_StrBuilder str)
{
#define current (*scanner)
	char* scanner = str;
	while (current != '\r' && current != '\n')
	{
		++scanner;
	}

	gen_s32 new_length = scanner - str;

	if (current == '\r')
	{
		new_length += 1;
	}

	gen_mem_move((char*)str, scanner, new_length);

	gen_StrBuilderHeader* header = gen_strbuilder_get_header(str);
	header->Length               = new_length;
#undef current
}

inline void gen_strbuilder_strip_space(gen_StrBuilder str)
{
	char* write_pos = str;
	char* read_pos  = str;

	while (*read_pos)
	{
		if (! gen_char_is_space(*read_pos))
		{
			*write_pos = *read_pos;
			write_pos++;
		}
		read_pos++;
	}
	write_pos[0] = '\0';    // Null-terminate the modified string

	// Update the length if needed
	gen_strbuilder_get_header(str)->Length = write_pos - str;
}

gen_forceinline gen_Str gen_strbuilder_to_str(gen_StrBuilder str)
{
	gen_Str result = { (char const*)str, gen_strbuilder_length(str) };
	return result;
}

inline void gen_strbuilder_trim(gen_StrBuilder str, char const* cut_set)
{
	gen_ssize len     = 0;

	char* start_pos   = str;
	char* gen_end_pos = gen_scast(char*, str) + gen_strbuilder_length(str) - 1;

	while (start_pos <= gen_end_pos && gen_char_first_occurence(cut_set, *start_pos))
		start_pos++;

	while (gen_end_pos > start_pos && gen_char_first_occurence(cut_set, *gen_end_pos))
		gen_end_pos--;

	len = gen_scast(gen_ssize, (start_pos > gen_end_pos) ? 0 : ((gen_end_pos - start_pos) + 1));

	if (str != start_pos)
		gen_mem_move(str, start_pos, len);

	str[len]                               = '\0';

	gen_strbuilder_get_header(str)->Length = len;
}

gen_forceinline void gen_strbuilder_trim_space(gen_StrBuilder str)
{
	gen_strbuilder_trim(str, " \t\r\n\v\f");
}

inline gen_StrBuilder gen_strbuilder_visualize_whitespace(gen_StrBuilder const str)
{
	gen_StrBuilderHeader* header = (gen_StrBuilderHeader*)(gen_scast(char const*, str) - sizeof(gen_StrBuilderHeader));
	gen_StrBuilder result = gen_strbuilder_make_reserve(header->Allocator, gen_strbuilder_length(str) * 2);    // Assume worst case for space requirements.

	for (char const* c = gen_strbuilder_begin(str); c != gen_strbuilder_end(str); c = gen_strbuilder_next(str, c))
		switch (*c)
		{
			case ' ':
				gen_strbuilder_append_str(&result, txt("·"));
				break;
			case '\t':
				gen_strbuilder_append_str(&result, txt("→"));
				break;
			case '\n':
				gen_strbuilder_append_str(&result, txt("↵"));
				break;
			case '\r':
				gen_strbuilder_append_str(&result, txt("⏎"));
				break;
			case '\v':
				gen_strbuilder_append_str(&result, txt("⇕"));
				break;
			case '\f':
				gen_strbuilder_append_str(&result, txt("⌂"));
				break;
			default:
				gen_strbuilder_append_char(&result, *c);
				break;
		}

	return result;
}

#pragma endregion gen_StrBuilder

gen_forceinline gen_Str gen_str_duplicate(gen_Str str, gen_AllocatorInfo allocator)
{
	gen_Str result = gen_strbuilder_to_str(gen_strbuilder_make_length(allocator, str.Ptr, str.Len));
	return result;
}

inline gen_Str gen_str_visualize_whitespace(gen_Str str, gen_AllocatorInfo allocator)
{
	gen_StrBuilder result = gen_strbuilder_make_reserve(allocator, str.Len * 2);    // Assume worst case for space requirements.
	for (char const* c = gen_str_begin(str); c != gen_str_end(str); c = gen_str_next(str, c))
		switch (*c)
		{
			case ' ':
				gen_strbuilder_append_str(&result, txt("·"));
				break;
			case '\t':
				gen_strbuilder_append_str(&result, txt("→"));
				break;
			case '\n':
				gen_strbuilder_append_str(&result, txt("↵"));
				break;
			case '\r':
				gen_strbuilder_append_str(&result, txt("⏎"));
				break;
			case '\v':
				gen_strbuilder_append_str(&result, txt("⇕"));
				break;
			case '\f':
				gen_strbuilder_append_str(&result, txt("⌂"));
				break;
			default:
				gen_strbuilder_append_char(&result, *c);
				break;
		}
	return gen_strbuilder_to_str(result);
}

// Represents strings cached with the string table.
// Should never be modified, if changed string is desired, cache_string( str ) another.
typedef gen_Str gen_StrCached;

// Implements basic string interning. Data structure is based off the ZPL Hashtable.
#pragma region gen_StringTable

#define GEN_GENERIC_SLOT_1__hashtable_init         gen_Str, gen_StringTable_init
#define GEN_GENERIC_SLOT_1__hashtable_init_reserve gen_Str, gen_StringTable_init_reserve
#define GEN_GENERIC_SLOT_1__hashtable_clear        gen_StringTable, gen_StringTable_clear
#define GEN_GENERIC_SLOT_1__hashtable_destroy      gen_StringTable, gen_StringTable_destroy
#define GEN_GENERIC_SLOT_1__hashtable_get          gen_StringTable, gen_StringTable_get
#define GEN_GENERIC_SLOT_1__hashtable_map          gen_StringTable, gen_StringTable_map
#define GEN_GENERIC_SLOT_1__hashtable_map_mut      gen_StringTable, gen_StringTable_map_mut
#define GEN_GENERIC_SLOT_1__hashtable_grow         gen_StringTable*, gen_StringTable_grow
#define GEN_GENERIC_SLOT_1__hashtable_rehash       gen_StringTable*, gen_StringTable_rehash
#define GEN_GENERIC_SLOT_1__hashtable_rehash_fast  gen_StringTable, gen_StringTable_rehash_fast
#define GEN_GENERIC_SLOT_1__hashtable_remove_entry gen_StringTable, gen_StringTable_remove_entry
#define GEN_GENERIC_SLOT_1__hashtable_set          gen_StringTable, gen_StringTable_set
#define GEN_GENERIC_SLOT_1__hashtable_slot         gen_StringTable, gen_StringTable_slot

#define GEN_GENERIC_SLOT_1__hashtable__add_entry   gen_StringTable*, gen_StringTable__add_entry
#define GEN_GENERIC_SLOT_1__hashtable__find        gen_StringTable, gen_StringTable__find
#define GEN_GENERIC_SLOT_1__hashtable__full        gen_StringTable, gen_StringTable__full

typedef struct gen_HashTable_gen_Str gen_StringTable;
typedef struct gen_HTE_StringTable   gen_HTE_StringTable;

struct gen_HTE_StringTable
{
	gen_u64   Key;
	gen_ssize Next;
	gen_Str   Value;
};

typedef void (*gen_StringTable_MapProc)(gen_StringTable self, gen_u64 key, gen_Str value);
typedef void (*gen_StringTable_MapMutProc)(gen_StringTable self, gen_u64 key, gen_Str* value);

#pragma region gen_Arr_HTE_StringTable

#define GEN_GENERIC_SLOT_3__array_init            gen_HTE_StringTable, gen_Arr_HTE_StringTable_init
#define GEN_GENERIC_SLOT_3__array_init_reserve    gen_HTE_StringTable, gen_Arr_HTE_StringTable_init_reserve
#define GEN_GENERIC_SLOT_3__array_append          gen_Arr_HTE_StringTable, gen_Arr_HTE_StringTable_append
#define GEN_GENERIC_SLOT_3__array_append_items    gen_Arr_HTE_StringTable, gen_Arr_HTE_StringTable_append_items
#define GEN_GENERIC_SLOT_3__array_append_at       gen_Arr_HTE_StringTable, gen_Arr_HTE_StringTable_append_at
#define GEN_GENERIC_SLOT_3__array_append_items_at gen_Arr_HTE_StringTable, gen_Arr_HTE_StringTable_append_items_at
#define GEN_GENERIC_SLOT_3__array_back            gen_Arr_HTE_StringTable, gen_Arr_HTE_StringTable_back
#define GEN_GENERIC_SLOT_3__array_clear           gen_Arr_HTE_StringTable, gen_Arr_HTE_StringTable_clear
#define GEN_GENERIC_SLOT_3__array_fill            gen_Arr_HTE_StringTable, gen_Arr_HTE_StringTable_fill
#define GEN_GENERIC_SLOT_3__array_free            gen_Arr_HTE_StringTable, gen_Arr_HTE_StringTable_free
#define GEN_GENERIC_SLOT_3__array_grow            gen_Arr_HTE_StringTable*, gen_Arr_HTE_StringTable_grow
#define GEN_GENERIC_SLOT_3__array_num             gen_Arr_HTE_StringTable, gen_Arr_HTE_StringTable_num
#define GEN_GENERIC_SLOT_3__array_pop             gen_Arr_HTE_StringTable, gen_Arr_HTE_StringTable_pop
#define GEN_GENERIC_SLOT_3__array_remove_at       gen_Arr_HTE_StringTable, gen_Arr_HTE_StringTable_remove_at
#define GEN_GENERIC_SLOT_3__array_reserve         gen_Arr_HTE_StringTable, gen_Arr_HTE_StringTable_reserve
#define GEN_GENERIC_SLOT_3__array_resize          gen_Arr_HTE_StringTable, gen_Arr_HTE_StringTable_resize
#define GEN_GENERIC_SLOT_3__array_set_capacity    gen_Arr_HTE_StringTable*, gen_Arr_HTE_StringTable_set_capacity

typedef gen_HTE_StringTable* gen_Arr_HTE_StringTable;
gen_Arr_HTE_StringTable      gen_Arr_HTE_StringTable_init(gen_AllocatorInfo allocator);
gen_Arr_HTE_StringTable      gen_Arr_HTE_StringTable_init_reserve(gen_AllocatorInfo allocator, gen_usize capacity);
bool                         gen_Arr_HTE_StringTable_append_array(gen_Arr_HTE_StringTable* self, gen_Arr_HTE_StringTable other);
bool                         gen_Arr_HTE_StringTable_append(gen_Arr_HTE_StringTable* self, gen_HTE_StringTable value);
bool                         gen_Arr_HTE_StringTable_append_items(gen_Arr_HTE_StringTable* self, gen_HTE_StringTable* items, gen_usize item_num);
bool                         gen_Arr_HTE_StringTable_append_at(gen_Arr_HTE_StringTable* self, gen_HTE_StringTable item, gen_usize idx);
bool                 gen_Arr_HTE_StringTable_append_items_at(gen_Arr_HTE_StringTable* self, gen_HTE_StringTable* items, gen_usize item_num, gen_usize idx);
gen_HTE_StringTable* gen_Arr_HTE_StringTable_back(gen_Arr_HTE_StringTable self);
void                 gen_Arr_HTE_StringTable_clear(gen_Arr_HTE_StringTable self);
bool                 gen_Arr_HTE_StringTable_fill(gen_Arr_HTE_StringTable self, gen_usize begin, gen_usize end, gen_HTE_StringTable value);
void                 gen_Arr_HTE_StringTable_free(gen_Arr_HTE_StringTable* self);
bool                 gen_Arr_HTE_StringTable_grow(gen_Arr_HTE_StringTable* self, gen_usize min_capacity);
gen_usize            gen_Arr_HTE_StringTable_num(gen_Arr_HTE_StringTable self);
gen_HTE_StringTable  gen_Arr_HTE_StringTable_pop(gen_Arr_HTE_StringTable self);
void                 gen_Arr_HTE_StringTable_remove_at(gen_Arr_HTE_StringTable self, gen_usize idx);
bool                 gen_Arr_HTE_StringTable_reserve(gen_Arr_HTE_StringTable* self, gen_usize new_capacity);
bool                 gen_Arr_HTE_StringTable_resize(gen_Arr_HTE_StringTable* self, gen_usize num);
bool                 gen_Arr_HTE_StringTable_set_capacity(gen_Arr_HTE_StringTable* self, gen_usize new_capacity);

gen_forceinline gen_Arr_HTE_StringTable gen_Arr_HTE_StringTable_init(gen_AllocatorInfo allocator)
{
	size_t initial_size = gen_array_grow_formula(0);
	return gen_array_init_reserve(gen_HTE_StringTable, allocator, initial_size);
}

inline gen_Arr_HTE_StringTable gen_Arr_HTE_StringTable_init_reserve(gen_AllocatorInfo allocator, gen_usize capacity)
{
	GEN_ASSERT(capacity > 0);
	gen_ArrayHeader* header = gen_rcast(gen_ArrayHeader*, gen_alloc(allocator, sizeof(gen_ArrayHeader) + sizeof(gen_HTE_StringTable) * capacity));
	if (header == gen_nullptr)
		return gen_nullptr;
	header->Allocator = allocator;
	header->Capacity  = capacity;
	header->Num       = 0;
	return gen_rcast(gen_HTE_StringTable*, header + 1);
}

gen_forceinline bool gen_Arr_HTE_StringTable_append_array(gen_Arr_HTE_StringTable* self, gen_Arr_HTE_StringTable other)
{
	return gen_array_append_items(*self, (gen_Arr_HTE_StringTable)other, gen_Arr_HTE_StringTable_num(other));
}

inline bool gen_Arr_HTE_StringTable_append(gen_Arr_HTE_StringTable* self, gen_HTE_StringTable value)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Num == header->Capacity)
	{
		if (! gen_array_grow(self, header->Capacity))
			return false;
		header = gen_array_get_header(*self);
	}
	(*self)[header->Num] = value;
	header->Num++;
	return true;
}

inline bool gen_Arr_HTE_StringTable_append_items(gen_Arr_HTE_StringTable* self, gen_HTE_StringTable* items, gen_usize item_num)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(items != gen_nullptr);
	GEN_ASSERT(item_num > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Num + item_num > header->Capacity)
	{
		if (! gen_array_grow(self, header->Capacity + item_num))
			return false;
		header = gen_array_get_header(*self);
	}
	gen_mem_copy((*self) + header->Num, items, sizeof(gen_HTE_StringTable) * item_num);
	header->Num += item_num;
	return true;
}

inline bool gen_Arr_HTE_StringTable_append_at(gen_Arr_HTE_StringTable* self, gen_HTE_StringTable item, gen_usize idx)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (idx >= header->Num)
		idx = header->Num - 1;
	if (idx < 0)
		idx = 0;
	if (header->Capacity < header->Num + 1)
	{
		if (! gen_array_grow(self, header->Capacity + 1))
			return false;
		header = gen_array_get_header(*self);
	}
	gen_Arr_HTE_StringTable target = (*self) + idx;
	gen_mem_move(target + 1, target, (header->Num - idx) * sizeof(gen_HTE_StringTable));
	header->Num++;
	return true;
}

inline bool gen_Arr_HTE_StringTable_append_items_at(gen_Arr_HTE_StringTable* self, gen_HTE_StringTable* items, gen_usize item_num, gen_usize idx)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (idx >= header->Num)
	{
		return gen_array_append_items(*self, items, item_num);
	}
	if (item_num > header->Capacity)
	{
		if (! gen_array_grow(self, item_num + header->Capacity))
			return false;
		header = gen_array_get_header(*self);
	}
	gen_HTE_StringTable* target = (*self) + idx + item_num;
	gen_HTE_StringTable* src    = (*self) + idx;
	gen_mem_move(target, src, (header->Num - idx) * sizeof(gen_HTE_StringTable));
	gen_mem_copy(src, items, item_num * sizeof(gen_HTE_StringTable));
	header->Num += item_num;
	return true;
}

inline gen_HTE_StringTable* gen_Arr_HTE_StringTable_back(gen_Arr_HTE_StringTable self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	if (header->Num == 0)
		return 0;
	return self + header->Num - 1;
}

inline void gen_Arr_HTE_StringTable_clear(gen_Arr_HTE_StringTable self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	header->Num             = 0;
}

inline bool gen_Arr_HTE_StringTable_fill(gen_Arr_HTE_StringTable self, gen_usize begin, gen_usize end, gen_HTE_StringTable value)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(begin <= end);
	gen_ArrayHeader* header = gen_array_get_header(self);
	if (begin < 0 || end > header->Num)
		return false;
	for (gen_ssize idx = (gen_ssize)begin; idx < (gen_ssize)end; idx++)
		self[idx] = value;
	return true;
}

inline void gen_Arr_HTE_StringTable_free(gen_Arr_HTE_StringTable* self)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	gen_allocator_free(header->Allocator, header);
	self = 0;
}

inline bool gen_Arr_HTE_StringTable_grow(gen_Arr_HTE_StringTable* self, gen_usize min_capacity)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(min_capacity > 0);
	gen_ArrayHeader* header       = gen_array_get_header(*self);
	gen_usize        new_capacity = gen_array_grow_formula(header->Capacity);
	if (new_capacity < min_capacity)
		new_capacity = min_capacity;
	return gen_array_set_capacity(self, new_capacity);
}

gen_forceinline gen_usize gen_Arr_HTE_StringTable_num(gen_Arr_HTE_StringTable self)
{
	GEN_ASSERT(self != gen_nullptr);
	return gen_array_get_header(self)->Num;
}

inline gen_HTE_StringTable gen_Arr_HTE_StringTable_pop(gen_Arr_HTE_StringTable self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	GEN_ASSERT(header->Num > 0);
	gen_HTE_StringTable result = self[header->Num - 1];
	header->Num--;
	return result;
}

gen_forceinline void gen_Arr_HTE_StringTable_remove_at(gen_Arr_HTE_StringTable self, gen_usize idx)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	GEN_ASSERT(idx < header->Num);
	gen_mem_move(self + idx, self + idx + 1, sizeof(gen_HTE_StringTable) * (header->Num - idx - 1));
	header->Num--;
}

inline bool gen_Arr_HTE_StringTable_reserve(gen_Arr_HTE_StringTable* self, gen_usize new_capacity)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(new_capacity > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Capacity < new_capacity)
		return gen_array_set_capacity(self, new_capacity);
	return true;
}

inline bool gen_Arr_HTE_StringTable_resize(gen_Arr_HTE_StringTable* self, gen_usize num)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(num > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Capacity < num)
	{
		if (! gen_array_grow(self, num))
			return false;
		header = gen_array_get_header(*self);
	}
	header->Num = num;
	return true;
}

inline bool gen_Arr_HTE_StringTable_set_capacity(gen_Arr_HTE_StringTable* self, gen_usize new_capacity)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(new_capacity > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (new_capacity == header->Capacity)
		return true;
	if (new_capacity < header->Num)
	{
		header->Num = new_capacity;
		return true;
	}
	gen_usize        size       = sizeof(gen_ArrayHeader) + sizeof(gen_HTE_StringTable) * new_capacity;
	gen_ArrayHeader* new_header = gen_cast(gen_ArrayHeader*, gen_alloc(header->Allocator, size));
	if (new_header == 0)
		return false;
	gen_mem_move(new_header, header, sizeof(gen_ArrayHeader) + sizeof(gen_HTE_StringTable) * header->Num);
	new_header->Capacity = new_capacity;
	gen_allocator_free(header->Allocator, &header);
	*self = gen_cast(gen_HTE_StringTable*, new_header + 1);
	return true;
}

#pragma endregion gen_Arr_HTE_StringTable

struct gen_HashTable_gen_Str
{
	gen_Array_gen_ssize     Hashes;
	gen_Arr_HTE_StringTable Entries;
};

gen_StringTable   gen_StringTable_init(gen_AllocatorInfo allocator);
gen_StringTable   gen_StringTable_init_reserve(gen_AllocatorInfo allocator, gen_ssize num);
void              gen_StringTable_clear(gen_StringTable self);
void              gen_StringTable_destroy(gen_StringTable* self);
gen_Str*          gen_StringTable_get(gen_StringTable self, gen_u64 key);
void              gen_StringTable_map(gen_StringTable self, gen_StringTable_MapProc map_proc);
void              gen_StringTable_map_mut(gen_StringTable self, gen_StringTable_MapMutProc map_proc);
void              gen_StringTable_grow(gen_StringTable* self);
void              gen_StringTable_rehash(gen_StringTable* self, gen_ssize new_num);
void              gen_StringTable_rehash_fast(gen_StringTable self);
void              gen_StringTable_remove(gen_StringTable self, gen_u64 key);
void              gen_StringTable_remove_entry(gen_StringTable self, gen_ssize idx);
void              gen_StringTable_set(gen_StringTable* self, gen_u64 key, gen_Str value);
gen_ssize         gen_StringTable_slot(gen_StringTable self, gen_u64 key);
gen_ssize         gen_StringTable__add_entry(gen_StringTable* self, gen_u64 key);
gen_HT_FindResult gen_StringTable__find(gen_StringTable self, gen_u64 key);
gen_b32           gen_StringTable__full(gen_StringTable self);

gen_StringTable gen_StringTable_init(gen_AllocatorInfo allocator)
{
	gen_StringTable result = gen_hashtable_init_reserve(gen_Str, allocator, 8);
	return result;
}

gen_StringTable gen_StringTable_init_reserve(gen_AllocatorInfo allocator, gen_ssize num)
{
	gen_StringTable result                   = { 0, 0 };
	result.Hashes                            = gen_array_init_reserve(gen_ssize, allocator, num);
	gen_array_get_header(result.Hashes)->Num = num;
	gen_array_resize(result.Hashes, num);
	gen_array_fill(result.Hashes, 0, num, -1);
	result.Entries = gen_array_init_reserve(gen_HTE_StringTable, allocator, num);
	return result;
}

void gen_StringTable_clear(gen_StringTable self)
{
	GEN_ASSERT_NOT_NULL(self.Hashes);
	GEN_ASSERT_NOT_NULL(self.Entries);
	gen_array_clear(self.Entries);
	gen_s32 what = gen_array_num(self.Hashes);
	gen_array_fill(self.Hashes, 0, what, (gen_ssize)-1);
}

void gen_StringTable_destroy(gen_StringTable* self)
{
	GEN_ASSERT_NOT_NULL(self);
	GEN_ASSERT_NOT_NULL(self->Hashes);
	GEN_ASSERT_NOT_NULL(self->Entries);
	if (self->Hashes && gen_array_get_header(self->Hashes)->Capacity)
	{
		gen_array_free(self->Hashes);
		gen_array_free(self->Entries);
	}
}

gen_Str* gen_StringTable_get(gen_StringTable self, gen_u64 key)
{
	GEN_ASSERT_NOT_NULL(self.Hashes);
	GEN_ASSERT_NOT_NULL(self.Entries);
	gen_ssize idx = gen_StringTable__find(self, key).EntryIndex;
	if (idx > 0)
		return &self.Entries[idx].Value;
	return gen_nullptr;
}

void gen_StringTable_map(gen_StringTable self, gen_StringTable_MapProc map_proc)
{
	GEN_ASSERT_NOT_NULL(self.Hashes);
	GEN_ASSERT_NOT_NULL(self.Entries);
	GEN_ASSERT_NOT_NULL(map_proc);
	for (gen_ssize idx = 0; idx < gen_array_get_header(self.Entries)->Num; idx++)
	{
		map_proc(self, self.Entries[idx].Key, self.Entries[idx].Value);
	}
}

void gen_StringTable_map_mut(gen_StringTable self, gen_StringTable_MapMutProc map_proc)
{
	GEN_ASSERT_NOT_NULL(self.Hashes);
	GEN_ASSERT_NOT_NULL(self.Entries);
	GEN_ASSERT_NOT_NULL(map_proc);
	for (gen_ssize idx = 0; idx < gen_array_get_header(self.Entries)->Num; idx++)
	{
		map_proc(self, self.Entries[idx].Key, &self.Entries[idx].Value);
	}
}

void gen_StringTable_grow(gen_StringTable* self)
{
	GEN_ASSERT_NOT_NULL(self);
	GEN_ASSERT_NOT_NULL(self->Hashes);
	GEN_ASSERT_NOT_NULL(self->Entries);
	gen_ssize new_num = gen_array_grow_formula(gen_array_get_header(self->Entries)->Num);
	gen_hashtable_rehash(self, new_num);
}

void gen_StringTable_rehash(gen_StringTable* self, gen_ssize new_num)
{
	GEN_ASSERT_NOT_NULL(self);
	GEN_ASSERT_NOT_NULL(self->Hashes);
	GEN_ASSERT_NOT_NULL(self->Entries);
	GEN_ASSERT(new_num > 0);
	gen_ssize        idx;
	gen_ssize        last_added_index;
	gen_ArrayHeader* old_hash_header    = gen_array_get_header(self->Hashes);
	gen_ArrayHeader* old_entries_header = gen_array_get_header(self->Entries);
	gen_StringTable  new_tbl            = gen_hashtable_init_reserve(gen_Str, old_hash_header->Allocator, old_hash_header->Num);
	gen_ArrayHeader* new_hash_header    = gen_array_get_header(new_tbl.Hashes);
	for (gen_ssize idx = 0; idx < gen_cast(gen_ssize, old_hash_header->Num); ++idx)
	{
		gen_HTE_StringTable* entry = &self->Entries[idx];
		gen_HT_FindResult    find_result;
		find_result      = gen_StringTable__find(new_tbl, entry->Key);
		last_added_index = gen_StringTable__add_entry(&new_tbl, entry->Key);
		if (find_result.PrevIndex < 0)
			new_tbl.Hashes[find_result.HashIndex] = last_added_index;
		else
			new_tbl.Entries[find_result.PrevIndex].Next = last_added_index;
		new_tbl.Entries[last_added_index].Next  = find_result.EntryIndex;
		new_tbl.Entries[last_added_index].Value = entry->Value;
	}
	gen_StringTable_destroy(self);
	*self = new_tbl;
}

void gen_StringTable_rehash_fast(gen_StringTable self)
{
	GEN_ASSERT_NOT_NULL(self.Hashes);
	GEN_ASSERT_NOT_NULL(self.Entries);
	gen_ssize idx;
	for (idx = 0; idx < gen_array_get_header(self.Entries)->Num; idx++)
		self.Entries[idx].Next = -1;
	for (idx = 0; idx < gen_array_get_header(self.Hashes)->Num; idx++)
		self.Hashes[idx] = -1;
	for (idx = 0; idx < gen_array_get_header(self.Entries)->Num; idx++)
	{
		gen_HTE_StringTable* entry;
		gen_HT_FindResult    find_result;
		entry       = &self.Entries[idx];
		find_result = gen_StringTable__find(self, entry->Key);
		if (find_result.PrevIndex < 0)
			self.Hashes[find_result.HashIndex] = idx;
		else
			self.Entries[find_result.PrevIndex].Next = idx;
	}
}

void gen_StringTable_remove(gen_StringTable self, gen_u64 key)
{
	GEN_ASSERT_NOT_NULL(self.Hashes);
	GEN_ASSERT_NOT_NULL(self.Entries);
	gen_HT_FindResult find_result = gen_StringTable__find(self, key);
	if (find_result.EntryIndex >= 0)
	{
		gen_array_remove_at(self.Entries, find_result.EntryIndex);
		gen_hashtable_rehash_fast(self);
	}
}

void gen_StringTable_remove_entry(gen_StringTable self, gen_ssize idx)
{
	GEN_ASSERT_NOT_NULL(self.Hashes);
	GEN_ASSERT_NOT_NULL(self.Entries);
	gen_array_remove_at(self.Entries, idx);
}

void gen_StringTable_set(gen_StringTable* self, gen_u64 key, gen_Str value)
{
	GEN_ASSERT_NOT_NULL(self);
	GEN_ASSERT_NOT_NULL(self->Hashes);
	GEN_ASSERT_NOT_NULL(self->Entries);
	gen_ssize         idx;
	gen_HT_FindResult find_result;
	if (gen_array_get_header(self->Hashes)->Num == 0)
		gen_hashtable_grow(self);
	find_result = gen_StringTable__find(*self, key);
	if (find_result.EntryIndex >= 0)
	{
		idx = find_result.EntryIndex;
	}
	else
	{
		idx = gen_StringTable__add_entry(self, key);
		if (find_result.PrevIndex >= 0)
		{
			self->Entries[find_result.PrevIndex].Next = idx;
		}
		else
		{
			self->Hashes[find_result.HashIndex] = idx;
		}
	}
	self->Entries[idx].Value = value;
	if (gen_StringTable__full(*self))
		gen_hashtable_grow(self);
}

gen_ssize gen_StringTable_slot(gen_StringTable self, gen_u64 key)
{
	GEN_ASSERT_NOT_NULL(self.Hashes);
	GEN_ASSERT_NOT_NULL(self.Entries);
	for (gen_ssize idx = 0; idx < gen_array_get_header(self.Hashes)->Num; ++idx)
		if (self.Hashes[idx] == key)
			return idx;
	return -1;
}

gen_ssize gen_StringTable__add_entry(gen_StringTable* self, gen_u64 key)
{
	GEN_ASSERT_NOT_NULL(self);
	GEN_ASSERT_NOT_NULL(self->Hashes);
	GEN_ASSERT_NOT_NULL(self->Entries);
	gen_ssize           idx;
	gen_HTE_StringTable entry = { key, -1 };
	idx                       = gen_array_get_header(self->Entries)->Num;
	gen_array_append(self->Entries, entry);
	return idx;
}

gen_HT_FindResult gen_StringTable__find(gen_StringTable self, gen_u64 key)
{
	GEN_ASSERT_NOT_NULL(self.Hashes);
	GEN_ASSERT_NOT_NULL(self.Entries);
	gen_HT_FindResult result      = { -1, -1, -1 };
	gen_ArrayHeader*  hash_header = gen_array_get_header(self.Hashes);
	if (hash_header->Num > 0)
	{
		result.HashIndex  = key % hash_header->Num;
		result.EntryIndex = self.Hashes[result.HashIndex];
		while (result.EntryIndex >= 0)
		{
			if (self.Entries[result.EntryIndex].Key == key)
				break;
			result.PrevIndex  = result.EntryIndex;
			result.EntryIndex = self.Entries[result.EntryIndex].Next;
		}
	}
	return result;
}

gen_b32 gen_StringTable__full(gen_StringTable self)
{
	GEN_ASSERT_NOT_NULL(self.Hashes);
	GEN_ASSERT_NOT_NULL(self.Entries);
	gen_ArrayHeader* hash_header    = gen_array_get_header(self.Hashes);
	gen_ArrayHeader* entries_header = gen_array_get_header(self.Entries);
	gen_usize        critical_load  = gen_cast(gen_usize, gen_HashTable_CriticalLoadScale * gen_cast(gen_f32, hash_header->Num));
	gen_b32          result         = entries_header->Num > critical_load;
	return result;
}

#pragma endregion gen_StringTable

#pragma endregion Strings

#pragma region File Handling

enum gen_FileModeFlag
{
	EFileMode_READ   = gen_bit(0),
	EFileMode_WRITE  = gen_bit(1),
	EFileMode_APPEND = gen_bit(2),
	EFileMode_RW     = gen_bit(3),
	GEN_FILE_MODES   = EFileMode_READ | EFileMode_WRITE | EFileMode_APPEND | EFileMode_RW,
};
typedef enum gen_FileModeFlag gen_FileModeFlag;

// NOTE: Only used internally and for the file operations
enum gen_SeekWhenceType
{
	ESeekWhence_BEGIN   = 0,
	ESeekWhence_CURRENT = 1,
	ESeekWhence_END     = 2,
};
typedef enum gen_SeekWhenceType gen_SeekWhenceType;

enum gen_FileError
{
	EFileError_NONE,
	EFileError_INVALID,
	EFileError_INVALID_FILENAME,
	EFileError_EXISTS,
	EFileError_NOT_EXISTS,
	EFileError_PERMISSION,
	EFileError_TRUNCATION_FAILURE,
	EFileError_NOT_EMPTY,
	EFileError_NAME_TOO_LONG,
	EFileError_UNKNOWN,
};
typedef enum gen_FileError gen_FileError;

union gen_FileDescriptor
{
	void*    p;
	gen_sptr i;
	gen_uptr u;
};
typedef union gen_FileDescriptor gen_FileDescriptor;

typedef gen_u32                   gen_FileMode;
typedef struct gen_FileOperations gen_FileOperations;

#define GEN_FILE_OPEN_PROC(name) gen_FileError name(gen_FileDescriptor* fd, gen_FileOperations* ops, gen_FileMode mode, char const* filename)
#define GEN_FILE_READ_AT_PROC(name) \
	gen_b32 name(gen_FileDescriptor fd, void* buffer, gen_ssize size, gen_s64 offset, gen_ssize* bytes_read, gen_b32 stop_at_newline)
#define GEN_FILE_WRITE_AT_PROC(name) gen_b32 name(gen_FileDescriptor fd, gen_mem_ptr_const buffer, gen_ssize size, gen_s64 offset, gen_ssize* bytes_written)
#define GEN_FILE_SEEK_PROC(name)     gen_b32 name(gen_FileDescriptor fd, gen_s64 offset, gen_SeekWhenceType whence, gen_s64* new_offset)
#define GEN_FILE_CLOSE_PROC(name)    void name(gen_FileDescriptor fd)

typedef GEN_FILE_OPEN_PROC(gen_file_open_proc);
typedef GEN_FILE_READ_AT_PROC(FileReadProc);
typedef GEN_FILE_WRITE_AT_PROC(FileWriteProc);
typedef GEN_FILE_SEEK_PROC(FileSeekProc);
typedef GEN_FILE_CLOSE_PROC(FileCloseProc);

struct gen_FileOperations
{
	FileReadProc*  read_at;
	FileWriteProc* write_at;
	FileSeekProc*  seek;
	FileCloseProc* close;
};
typedef struct gen_FileOperations gen_FileOperations;

extern gen_FileOperations const default_file_operations;

typedef gen_u64 word;

enum gen_DirType
{
	GEN_DIR_TYPE_FILE,
	GEN_DIR_TYPE_FOLDER,
	GEN_DIR_TYPE_UNKNOWN,
};
typedef enum gen_DirType gen_DirType;

struct gen_DirInfo;
typedef struct gen_DirInfo gen_DirInfo;

struct gen_DirEntry
{
	char const*  filename;
	gen_DirInfo* dir_info;
	gen_u8       type;
};
typedef struct gen_DirEntry gen_DirEntry;

struct gen_DirInfo
{
	char const*   fullpath;
	gen_DirEntry* entries;    // zpl_array

	// Internals
	char**         filenames;    // zpl_array
	gen_StrBuilder buf;
};
typedef struct gen_DirInfo gen_DirInfo;

struct gen_FileInfo
{
	gen_FileOperations ops;
	gen_FileDescriptor fd;
	gen_b32            is_temp;

	char const*   filename;
	word          last_write_time;
	gen_DirEntry* dir;
};
typedef struct gen_FileInfo gen_FileInfo;

enum gen_FileStandardType
{
	EFileStandard_INPUT,
	EFileStandard_OUTPUT,
	EFileStandard_ERROR,
	EFileStandard_COUNT,
};
typedef enum gen_FileStandardType gen_FileStandardType;

/**
	* Get standard file I/O.
	* @param  std Check zpl_file_standard_type
	* @return     File handle to standard I/O
	*/
GEN_API gen_FileInfo* gen_file_get_standard(gen_FileStandardType std);

/**
	* Closes the file
	* @param  file
	*/
GEN_API gen_FileError gen_file_close(gen_FileInfo* file);

/**
	* Returns the currently opened file's name
	* @param  file
	*/
inline char const* gen_file_name(gen_FileInfo* file)
{
	return file->filename ? file->filename : "";
}

/**
	* Opens a file
	* @param  file
	* @param  filename
	*/
GEN_API gen_FileError gen_file_open(gen_FileInfo* file, char const* filename);

/**
	* Opens a file using a specified mode
	* @param  file
	* @param  mode     Access mode to use
	* @param  filename
	*/
GEN_API gen_FileError gen_file_open_mode(gen_FileInfo* file, gen_FileMode mode, char const* filename);

/**
	* Reads from a file
	* @param  file
	* @param  buffer Buffer to read to
	* @param  size   Size to read
	*/
gen_b32 gen_file_read(gen_FileInfo* file, void* buffer, gen_ssize size);

/**
	* Reads file at a specific offset
	* @param  file
	* @param  buffer     Buffer to read to
	* @param  size       Size to read
	* @param  offset     Offset to read from
	* @param  bytes_read How much data we've actually read
	*/
gen_b32 gen_file_read_at(gen_FileInfo* file, void* buffer, gen_ssize size, gen_s64 offset);

/**
	* Reads file safely
	* @param  file
	* @param  buffer     Buffer to read to
	* @param  size       Size to read
	* @param  offset     Offset to read from
	* @param  bytes_read How much data we've actually read
	*/
gen_b32 gen_file_read_at_check(gen_FileInfo* file, void* buffer, gen_ssize size, gen_s64 offset, gen_ssize* bytes_read);

typedef struct FileContents FileContents;

struct FileContents
{
	gen_AllocatorInfo allocator;
	void*             data;
	gen_ssize         size;
};
typedef struct FileContents FileContents;

#define gen_file_zero_terminate    true
#define gen_file_no_zero_terminate false

/**
	* Reads the whole file contents
	* @param  a              Allocator to use
	* @param  zero_terminate End the read data with null terminator
	* @param  filepath       Path to the file
	* @return                File contents data
	*/
GEN_API FileContents gen_file_read_contents(gen_AllocatorInfo a, gen_b32 zero_terminate, char const* filepath);

/**
	* Returns a size of the file
	* @param  file
	* @return      File size
	*/
GEN_API gen_s64 gen_file_size(gen_FileInfo* file);

/**
	* Seeks the file cursor from the beginning of file to a specific position
	* @param  file
	* @param  offset Offset to seek to
	*/
gen_s64 gen_file_seek(gen_FileInfo* file, gen_s64 offset);

/**
	* Seeks the file cursor to the end of the file
	* @param  file
	*/
gen_s64 gen_file_seek_to_end(gen_FileInfo* file);

/**
	* Returns the length from the beginning of the file we've read so far
	* @param  file
	* @return      Our current position in file
	*/
gen_s64 gen_file_tell(gen_FileInfo* file);

/**
	* Writes to a file
	* @param  file
	* @param  buffer Buffer to read from
	* @param  size   Size to read
	*/
gen_b32 gen_file_write(gen_FileInfo* file, void const* buffer, gen_ssize size);

/**
	* Writes to file at a specific offset
	* @param  file
	* @param  buffer        Buffer to read from
	* @param  size          Size to write
	* @param  offset        Offset to write to
	* @param  bytes_written How much data we've actually written
	*/
gen_b32 gen_file_write_at(gen_FileInfo* file, void const* buffer, gen_ssize size, gen_s64 offset);

/**
	* Writes to file safely
	* @param  file
	* @param  buffer        Buffer to read from
	* @param  size          Size to write
	* @param  offset        Offset to write to
	* @param  bytes_written How much data we've actually written
	*/
gen_b32 gen_file_write_at_check(gen_FileInfo* file, void const* buffer, gen_ssize size, gen_s64 offset, gen_ssize* bytes_written);

enum FileStreamFlags gen_enum_underlying(gen_u32)
{
	/* Allows us to write to the buffer directly. Beware: you can not append a new data! */
	EFileStream_WRITABLE = gen_bit(0), /* Clones the input buffer so you can write (zpl_file_write*) data into it. */
	/* Since we work with a clone, the buffer size can dynamically grow as well. */
	EFileStream_CLONE_WRITABLE = gen_bit(1),
	EFileStream_UNDERLYING     = GEN_U32_MAX,
};

typedef gen_u32 FileStreamFlags;

/**
	* Opens a new memory stream
	* @param file
	* @param allocator
	*/
GEN_API gen_b8 gen_file_stream_new(gen_FileInfo* file, gen_AllocatorInfo allocator);

/**
	* Opens a memory stream over an existing buffer
	* @param  file
	* @param  allocator
	* @param  buffer   Memory to create stream from
	* @param  size     Buffer's size
	* @param  flags
	*/
GEN_API gen_b8 gen_file_stream_open(gen_FileInfo* file, gen_AllocatorInfo allocator, gen_u8* buffer, gen_ssize size, FileStreamFlags flags);

/**
	* Retrieves the stream's underlying buffer and buffer size.
	* @param file memory stream
	* @param size (Optional) buffer size
	*/
GEN_API gen_u8* gen_file_stream_buf(gen_FileInfo* file, gen_ssize* size);

extern gen_FileOperations const memory_file_operations;

inline gen_s64 gen_file_seek(gen_FileInfo* f, gen_s64 offset)
{
	gen_s64 new_offset = 0;

	if (! f->ops.read_at)
		f->ops = default_file_operations;

	f->ops.seek(f->fd, offset, ESeekWhence_BEGIN, &new_offset);

	return new_offset;
}

inline gen_s64 gen_file_seek_to_end(gen_FileInfo* f)
{
	gen_s64 new_offset = 0;

	if (! f->ops.read_at)
		f->ops = default_file_operations;

	f->ops.seek(f->fd, 0, ESeekWhence_END, &new_offset);

	return new_offset;
}

inline gen_s64 gen_file_tell(gen_FileInfo* f)
{
	gen_s64 new_offset = 0;

	if (! f->ops.read_at)
		f->ops = default_file_operations;

	f->ops.seek(f->fd, 0, ESeekWhence_CURRENT, &new_offset);

	return new_offset;
}

inline gen_b32 gen_file_read(gen_FileInfo* f, void* buffer, gen_ssize size)
{
	gen_s64 cur_offset = gen_file_tell(f);
	gen_b32 result     = gen_file_read_at(f, buffer, size, gen_file_tell(f));
	gen_file_seek(f, cur_offset + size);
	return result;
}

inline gen_b32 gen_file_read_at(gen_FileInfo* f, void* buffer, gen_ssize size, gen_s64 offset)
{
	return gen_file_read_at_check(f, buffer, size, offset, NULL);
}

inline gen_b32 gen_file_read_at_check(gen_FileInfo* f, void* buffer, gen_ssize size, gen_s64 offset, gen_ssize* bytes_read)
{
	if (! f->ops.read_at)
		f->ops = default_file_operations;
	return f->ops.read_at(f->fd, buffer, size, offset, bytes_read, false);
}

inline gen_b32 gen_file_write(gen_FileInfo* f, void const* buffer, gen_ssize size)
{
	gen_s64 cur_offset = gen_file_tell(f);
	gen_b32 result     = gen_file_write_at(f, buffer, size, gen_file_tell(f));

	gen_file_seek(f, cur_offset + size);

	return result;
}

inline gen_b32 gen_file_write_at(gen_FileInfo* f, void const* buffer, gen_ssize size, gen_s64 offset)
{
	return gen_file_write_at_check(f, buffer, size, offset, NULL);
}

inline gen_b32 gen_file_write_at_check(gen_FileInfo* f, void const* buffer, gen_ssize size, gen_s64 offset, gen_ssize* bytes_written)
{
	if (! f->ops.read_at)
		f->ops = default_file_operations;

	return f->ops.write_at(f->fd, buffer, size, offset, bytes_written);
}

#pragma endregion File Handling

#pragma region Timing

#ifdef GEN_BENCHMARK
//! Return CPU timestamp.
GEN_API gen_u64 gen_read_cpu_time_stamp_counter( void );

//! Return relative time (in seconds) since the application start.
GEN_API gen_f64 gen_time_rel( void );

//! Return relative time since the application start.
GEN_API gen_u64 gen_time_rel_ms( void );
#endif

#pragma endregion Timing

#pragma region ADT

struct gen_ADT_Node;
typedef struct gen_ADT_Node gen_ADT_Node;
typedef gen_ADT_Node*       gen_Array_gen_ADT_Node;

enum gen_ADT_Type gen_enum_underlying(gen_u32)
{
	EADT_TYPE_UNINITIALISED, /* node was not initialised, this is a programming error! */
	EADT_TYPE_ARRAY,
	EADT_TYPE_OBJECT,
	EADT_TYPE_STRING,
	EADT_TYPE_MULTISTRING,
	EADT_TYPE_INTEGER,
	EADT_TYPE_REAL,
};

typedef gen_u32 gen_ADT_Type;

enum gen_ADT_Props gen_enum_underlying(gen_u32)
{
	EADT_PROPS_NONE,
	EADT_PROPS_NAN,
	EADT_PROPS_NAN_NEG,
	EADT_PROPS_INFINITY,
	EADT_PROPS_INFINITY_NEG,
	EADT_PROPS_FALSE,
	EADT_PROPS_TRUE,
	EADT_PROPS_NULL,
	EADT_PROPS_IS_EXP,
	EADT_PROPS_IS_HEX,    // Used internally so that people can fill in real numbers they plan to write.
	EADT_PROPS_IS_PARSED_REAL,
};

typedef gen_u32 gen_ADT_Props;

enum gen_ADT_NamingStyle gen_enum_underlying(gen_u32)
{
	EADT_NAME_STYLE_DOUBLE_QUOTE,
	EADT_NAME_STYLE_SINGLE_QUOTE,
	EADT_NAME_STYLE_NO_QUOTES,
};

typedef gen_u32 gen_ADT_NamingStyle;

enum gen_ADT_AssignStyle gen_enum_underlying(gen_u32)
{
	EADT_ASSIGN_STYLE_COLON,
	EADT_ASSIGN_STYLE_EQUALS,
	EADT_ASSIGN_STYLE_LINE,
};

typedef gen_u32 gen_ADT_AssignStyle;

enum gen_ADT_DelimStyle gen_enum_underlying(gen_u32)
{
	EADT_DELIM_STYLE_COMMA,
	EADT_DELIM_STYLE_LINE,
	EADT_DELIM_STYLE_NEWLINE,
};

typedef gen_u32 gen_ADT_DelimStyle;

enum gen_ADT_Error gen_enum_underlying(gen_u32)
{
	EADT_ERROR_NONE,
	EADT_ERROR_INTERNAL,
	EADT_ERROR_ALREADY_CONVERTED,
	EADT_ERROR_INVALID_TYPE,
	EADT_ERROR_OUT_OF_MEMORY,
};

typedef gen_u32 gen_ADT_Error;

struct gen_ADT_Node
{
	char const*          name;
	struct gen_ADT_Node* parent;

	/* properties */
	gen_ADT_Type type  : 4;
	gen_u8       props : 4;
#ifndef GEN_PARSER_DISABLE_ANALYSIS
	gen_u8 cfg_mode          : 1;
	gen_u8 name_style        : 2;
	gen_u8 assign_style      : 2;
	gen_u8 delim_style       : 2;
	gen_u8 delim_line_width  : 4;
	gen_u8 assign_line_width : 4;
#endif

	/* adt data */
	union
	{
		char const* string;
		gen_Array(gen_ADT_Node) nodes;    ///< zpl_array

		struct
		{
			union
			{
				gen_f64 real;
				gen_s64 integer;
			};

#ifndef GEN_PARSER_DISABLE_ANALYSIS
			/* number analysis */
			gen_s32 base;
			gen_s32 base2;
			gen_u8  base2_offset : 4;
			gen_s8  exp          : 4;
			gen_u8  neg_zero     : 1;
			gen_u8  lead_digit   : 1;
#endif
		};
	};
};

#pragma region gen_Array_gen_ADT_Node

#define GEN_GENERIC_SLOT_5__array_init            gen_ADT_Node, gen_Array_gen_ADT_Node_init
#define GEN_GENERIC_SLOT_5__array_init_reserve    gen_ADT_Node, gen_Array_gen_ADT_Node_init_reserve
#define GEN_GENERIC_SLOT_5__array_append          gen_Array_gen_ADT_Node, gen_Array_gen_ADT_Node_append
#define GEN_GENERIC_SLOT_5__array_append_items    gen_Array_gen_ADT_Node, gen_Array_gen_ADT_Node_append_items
#define GEN_GENERIC_SLOT_5__array_append_at       gen_Array_gen_ADT_Node, gen_Array_gen_ADT_Node_append_at
#define GEN_GENERIC_SLOT_5__array_append_items_at gen_Array_gen_ADT_Node, gen_Array_gen_ADT_Node_append_items_at
#define GEN_GENERIC_SLOT_5__array_back            gen_Array_gen_ADT_Node, gen_Array_gen_ADT_Node_back
#define GEN_GENERIC_SLOT_5__array_clear           gen_Array_gen_ADT_Node, gen_Array_gen_ADT_Node_clear
#define GEN_GENERIC_SLOT_5__array_fill            gen_Array_gen_ADT_Node, gen_Array_gen_ADT_Node_fill
#define GEN_GENERIC_SLOT_5__array_free            gen_Array_gen_ADT_Node, gen_Array_gen_ADT_Node_free
#define GEN_GENERIC_SLOT_5__array_grow            gen_Array_gen_ADT_Node*, gen_Array_gen_ADT_Node_grow
#define GEN_GENERIC_SLOT_5__array_num             gen_Array_gen_ADT_Node, gen_Array_gen_ADT_Node_num
#define GEN_GENERIC_SLOT_5__array_pop             gen_Array_gen_ADT_Node, gen_Array_gen_ADT_Node_pop
#define GEN_GENERIC_SLOT_5__array_remove_at       gen_Array_gen_ADT_Node, gen_Array_gen_ADT_Node_remove_at
#define GEN_GENERIC_SLOT_5__array_reserve         gen_Array_gen_ADT_Node, gen_Array_gen_ADT_Node_reserve
#define GEN_GENERIC_SLOT_5__array_resize          gen_Array_gen_ADT_Node, gen_Array_gen_ADT_Node_resize
#define GEN_GENERIC_SLOT_5__array_set_capacity    gen_Array_gen_ADT_Node*, gen_Array_gen_ADT_Node_set_capacity

gen_Array_gen_ADT_Node gen_Array_gen_ADT_Node_init(gen_AllocatorInfo allocator);
gen_Array_gen_ADT_Node gen_Array_gen_ADT_Node_init_reserve(gen_AllocatorInfo allocator, gen_usize capacity);
bool                   gen_Array_gen_ADT_Node_append_array(gen_Array_gen_ADT_Node* self, gen_Array_gen_ADT_Node other);
bool                   gen_Array_gen_ADT_Node_append(gen_Array_gen_ADT_Node* self, gen_ADT_Node value);
bool                   gen_Array_gen_ADT_Node_append_items(gen_Array_gen_ADT_Node* self, gen_ADT_Node* items, gen_usize item_num);
bool                   gen_Array_gen_ADT_Node_append_at(gen_Array_gen_ADT_Node* self, gen_ADT_Node item, gen_usize idx);
bool                   gen_Array_gen_ADT_Node_append_items_at(gen_Array_gen_ADT_Node* self, gen_ADT_Node* items, gen_usize item_num, gen_usize idx);
gen_ADT_Node*          gen_Array_gen_ADT_Node_back(gen_Array_gen_ADT_Node self);
void                   gen_Array_gen_ADT_Node_clear(gen_Array_gen_ADT_Node self);
bool                   gen_Array_gen_ADT_Node_fill(gen_Array_gen_ADT_Node self, gen_usize begin, gen_usize end, gen_ADT_Node value);
void                   gen_Array_gen_ADT_Node_free(gen_Array_gen_ADT_Node* self);
bool                   gen_Array_gen_ADT_Node_grow(gen_Array_gen_ADT_Node* self, gen_usize min_capacity);
gen_usize              gen_Array_gen_ADT_Node_num(gen_Array_gen_ADT_Node self);
gen_ADT_Node           gen_Array_gen_ADT_Node_pop(gen_Array_gen_ADT_Node self);
void                   gen_Array_gen_ADT_Node_remove_at(gen_Array_gen_ADT_Node self, gen_usize idx);
bool                   gen_Array_gen_ADT_Node_reserve(gen_Array_gen_ADT_Node* self, gen_usize new_capacity);
bool                   gen_Array_gen_ADT_Node_resize(gen_Array_gen_ADT_Node* self, gen_usize num);
bool                   gen_Array_gen_ADT_Node_set_capacity(gen_Array_gen_ADT_Node* self, gen_usize new_capacity);

gen_forceinline gen_Array_gen_ADT_Node gen_Array_gen_ADT_Node_init(gen_AllocatorInfo allocator)
{
	size_t initial_size = gen_array_grow_formula(0);
	return gen_array_init_reserve(gen_ADT_Node, allocator, initial_size);
}

inline gen_Array_gen_ADT_Node gen_Array_gen_ADT_Node_init_reserve(gen_AllocatorInfo allocator, gen_usize capacity)
{
	GEN_ASSERT(capacity > 0);
	gen_ArrayHeader* header = gen_rcast(gen_ArrayHeader*, gen_alloc(allocator, sizeof(gen_ArrayHeader) + sizeof(gen_ADT_Node) * capacity));
	if (header == gen_nullptr)
		return gen_nullptr;
	header->Allocator = allocator;
	header->Capacity  = capacity;
	header->Num       = 0;
	return gen_rcast(gen_ADT_Node*, header + 1);
}

gen_forceinline bool gen_Array_gen_ADT_Node_append_array(gen_Array_gen_ADT_Node* self, gen_Array_gen_ADT_Node other)
{
	return gen_array_append_items(*self, (gen_Array_gen_ADT_Node)other, gen_Array_gen_ADT_Node_num(other));
}

inline bool gen_Array_gen_ADT_Node_append(gen_Array_gen_ADT_Node* self, gen_ADT_Node value)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Num == header->Capacity)
	{
		if (! gen_array_grow(self, header->Capacity))
			return false;
		header = gen_array_get_header(*self);
	}
	(*self)[header->Num] = value;
	header->Num++;
	return true;
}

inline bool gen_Array_gen_ADT_Node_append_items(gen_Array_gen_ADT_Node* self, gen_ADT_Node* items, gen_usize item_num)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(items != gen_nullptr);
	GEN_ASSERT(item_num > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Num + item_num > header->Capacity)
	{
		if (! gen_array_grow(self, header->Capacity + item_num))
			return false;
		header = gen_array_get_header(*self);
	}
	gen_mem_copy((*self) + header->Num, items, sizeof(gen_ADT_Node) * item_num);
	header->Num += item_num;
	return true;
}

inline bool gen_Array_gen_ADT_Node_append_at(gen_Array_gen_ADT_Node* self, gen_ADT_Node item, gen_usize idx)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (idx >= header->Num)
		idx = header->Num - 1;
	if (idx < 0)
		idx = 0;
	if (header->Capacity < header->Num + 1)
	{
		if (! gen_array_grow(self, header->Capacity + 1))
			return false;
		header = gen_array_get_header(*self);
	}
	gen_Array_gen_ADT_Node target = (*self) + idx;
	gen_mem_move(target + 1, target, (header->Num - idx) * sizeof(gen_ADT_Node));
	header->Num++;
	return true;
}

inline bool gen_Array_gen_ADT_Node_append_items_at(gen_Array_gen_ADT_Node* self, gen_ADT_Node* items, gen_usize item_num, gen_usize idx)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (idx >= header->Num)
	{
		return gen_array_append_items(*self, items, item_num);
	}
	if (item_num > header->Capacity)
	{
		if (! gen_array_grow(self, item_num + header->Capacity))
			return false;
		header = gen_array_get_header(*self);
	}
	gen_ADT_Node* target = (*self) + idx + item_num;
	gen_ADT_Node* src    = (*self) + idx;
	gen_mem_move(target, src, (header->Num - idx) * sizeof(gen_ADT_Node));
	gen_mem_copy(src, items, item_num * sizeof(gen_ADT_Node));
	header->Num += item_num;
	return true;
}

inline gen_ADT_Node* gen_Array_gen_ADT_Node_back(gen_Array_gen_ADT_Node self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	if (header->Num == 0)
		return 0;
	return self + header->Num - 1;
}

inline void gen_Array_gen_ADT_Node_clear(gen_Array_gen_ADT_Node self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	header->Num             = 0;
}

inline bool gen_Array_gen_ADT_Node_fill(gen_Array_gen_ADT_Node self, gen_usize begin, gen_usize end, gen_ADT_Node value)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(begin <= end);
	gen_ArrayHeader* header = gen_array_get_header(self);
	if (begin < 0 || end > header->Num)
		return false;
	for (gen_ssize idx = (gen_ssize)begin; idx < (gen_ssize)end; idx++)
		self[idx] = value;
	return true;
}

inline void gen_Array_gen_ADT_Node_free(gen_Array_gen_ADT_Node* self)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	gen_allocator_free(header->Allocator, header);
	self = 0;
}

inline bool gen_Array_gen_ADT_Node_grow(gen_Array_gen_ADT_Node* self, gen_usize min_capacity)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(min_capacity > 0);
	gen_ArrayHeader* header       = gen_array_get_header(*self);
	gen_usize        new_capacity = gen_array_grow_formula(header->Capacity);
	if (new_capacity < min_capacity)
		new_capacity = min_capacity;
	return gen_array_set_capacity(self, new_capacity);
}

gen_forceinline gen_usize gen_Array_gen_ADT_Node_num(gen_Array_gen_ADT_Node self)
{
	GEN_ASSERT(self != gen_nullptr);
	return gen_array_get_header(self)->Num;
}

inline gen_ADT_Node gen_Array_gen_ADT_Node_pop(gen_Array_gen_ADT_Node self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	GEN_ASSERT(header->Num > 0);
	gen_ADT_Node result = self[header->Num - 1];
	header->Num--;
	return result;
}

gen_forceinline void gen_Array_gen_ADT_Node_remove_at(gen_Array_gen_ADT_Node self, gen_usize idx)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	GEN_ASSERT(idx < header->Num);
	gen_mem_move(self + idx, self + idx + 1, sizeof(gen_ADT_Node) * (header->Num - idx - 1));
	header->Num--;
}

inline bool gen_Array_gen_ADT_Node_reserve(gen_Array_gen_ADT_Node* self, gen_usize new_capacity)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(new_capacity > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Capacity < new_capacity)
		return gen_array_set_capacity(self, new_capacity);
	return true;
}

inline bool gen_Array_gen_ADT_Node_resize(gen_Array_gen_ADT_Node* self, gen_usize num)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(num > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Capacity < num)
	{
		if (! gen_array_grow(self, num))
			return false;
		header = gen_array_get_header(*self);
	}
	header->Num = num;
	return true;
}

inline bool gen_Array_gen_ADT_Node_set_capacity(gen_Array_gen_ADT_Node* self, gen_usize new_capacity)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(new_capacity > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (new_capacity == header->Capacity)
		return true;
	if (new_capacity < header->Num)
	{
		header->Num = new_capacity;
		return true;
	}
	gen_usize        size       = sizeof(gen_ArrayHeader) + sizeof(gen_ADT_Node) * new_capacity;
	gen_ArrayHeader* new_header = gen_cast(gen_ArrayHeader*, gen_alloc(header->Allocator, size));
	if (new_header == 0)
		return false;
	gen_mem_move(new_header, header, sizeof(gen_ArrayHeader) + sizeof(gen_ADT_Node) * header->Num);
	new_header->Capacity = new_capacity;
	gen_allocator_free(header->Allocator, &header);
	*self = gen_cast(gen_ADT_Node*, new_header + 1);
	return true;
}

#pragma endregion gen_Array_gen_ADT_Node



/* ADT NODE LIMITS
	* delimiter and assignment segment width is limited to 128 whitespace symbols each.
	* real number limits decimal position to 128 places.
	* real number exponent is limited to 64 digits.
	*/

/**
	* @brief Initialise an ADT object or array
	*
	* @param node
	* @param backing Memory allocator used for descendants
	* @param name Node's name
	* @param is_array
	* @return error code
	*/
GEN_API gen_u8 gen_adt_make_branch(gen_ADT_Node* node, gen_AllocatorInfo backing, char const* name, gen_b32 is_array);

/**
	* @brief Destroy an ADT branch and its descendants
	*
	* @param node
	* @return error code
	*/
GEN_API gen_u8 gen_adt_destroy_branch(gen_ADT_Node* node);

/**
	* @brief Initialise an ADT leaf
	*
	* @param node
	* @param name Node's name
	* @param type Node's type (use zpl_adt_make_branch for container nodes)
	* @return error code
	*/
GEN_API gen_u8 gen_adt_make_leaf(gen_ADT_Node* node, char const* name, gen_ADT_Type type);


/**
	* @brief Fetch a node using provided URI string.
	*
	* This method uses a basic syntax to fetch a node from the ADT. The following features are available
	* to retrieve the data:
	*
	* - "a/b/c" navigates through objects "a" and "b" to get to "c"
	* - "arr/[foo=123]/bar" iterates over "arr" to find any object with param "foo" that matches the value "123", then gets its field called "bar"
	* - "arr/3" retrieves the 4th element in "arr"
	* - "arr/[apple]" retrieves the first element of value "apple" in "arr"
	*
	* @param node ADT node
	* @param uri Locator string as described above
	* @return zpl_adt_node*
	*
	* @see code/apps/examples/json_get.c
	*/
GEN_API gen_ADT_Node* gen_adt_query(gen_ADT_Node* node, char const* uri);

/**
	* @brief Find a field node within an object by the given name.
	*
	* @param node
	* @param name
	* @param deep_search Perform search recursively
	* @return zpl_adt_node * node
	*/
GEN_API gen_ADT_Node* gen_adt_find(gen_ADT_Node* node, char const* name, gen_b32 deep_search);

/**
	* @brief Allocate an unitialised node within a container at a specified index.
	*
	* @param parent
	* @param index
	* @return zpl_adt_node * node
	*/
GEN_API gen_ADT_Node* gen_adt_alloc_at(gen_ADT_Node* parent, gen_ssize index);

/**
	* @brief Allocate an unitialised node within a container.
	*
	* @param parent
	* @return zpl_adt_node * node
	*/
GEN_API gen_ADT_Node* gen_adt_alloc(gen_ADT_Node* parent);

/**
	* @brief Move an existing node to a new container at a specified index.
	*
	* @param node
	* @param new_parent
	* @param index
	* @return zpl_adt_node * node
	*/
GEN_API gen_ADT_Node* gen_adt_move_node_at(gen_ADT_Node* node, gen_ADT_Node* new_parent, gen_ssize index);

/**
	* @brief Move an existing node to a new container.
	*
	* @param node
	* @param new_parent
	* @return zpl_adt_node * node
	*/
GEN_API gen_ADT_Node* gen_adt_move_node(gen_ADT_Node* node, gen_ADT_Node* new_parent);

/**
	* @brief Swap two nodes.
	*
	* @param node
	* @param other_node
	* @return
	*/
GEN_API void gen_adt_swap_nodes(gen_ADT_Node* node, gen_ADT_Node* other_node);

/**
	* @brief Remove node from container.
	*
	* @param node
	* @return
	*/
GEN_API void gen_adt_remove_node(gen_ADT_Node* node);

/**
	* @brief Initialise a node as an object
	*
	* @param obj
	* @param name
	* @param backing
	* @return
	*/
GEN_API gen_b8 gen_adt_set_obj(gen_ADT_Node* obj, char const* name, gen_AllocatorInfo backing);

/**
	* @brief Initialise a node as an array
	*
	* @param obj
	* @param name
	* @param backing
	* @return
	*/
GEN_API gen_b8 gen_adt_set_arr(gen_ADT_Node* obj, char const* name, gen_AllocatorInfo backing);

/**
	* @brief Initialise a node as a string
	*
	* @param obj
	* @param name
	* @param value
	* @return
	*/
GEN_API gen_b8 gen_adt_set_str(gen_ADT_Node* obj, char const* name, char const* value);

/**
	* @brief Initialise a node as a float
	*
	* @param obj
	* @param name
	* @param value
	* @return
	*/
GEN_API gen_b8 gen_adt_set_flt(gen_ADT_Node* obj, char const* name, gen_f64 value);

/**
	* @brief Initialise a node as a signed integer
	*
	* @param obj
	* @param name
	* @param value
	* @return
	*/
GEN_API gen_b8 gen_adt_set_int(gen_ADT_Node* obj, char const* name, gen_s64 value);

/**
	* @brief Append a new node to a container as an object
	*
	* @param parent
	* @param name
	* @return*
	*/
GEN_API gen_ADT_Node* gen_adt_append_obj(gen_ADT_Node* parent, char const* name);

/**
	* @brief Append a new node to a container as an array
	*
	* @param parent
	* @param name
	* @return*
	*/
GEN_API gen_ADT_Node* gen_adt_append_arr(gen_ADT_Node* parent, char const* name);

/**
	* @brief Append a new node to a container as a string
	*
	* @param parent
	* @param name
	* @param value
	* @return*
	*/
GEN_API gen_ADT_Node* gen_adt_append_str(gen_ADT_Node* parent, char const* name, char const* value);

/**
	* @brief Append a new node to a container as a float
	*
	* @param parent
	* @param name
	* @param value
	* @return*
	*/
GEN_API gen_ADT_Node* gen_adt_append_flt(gen_ADT_Node* parent, char const* name, gen_f64 value);

/**
	* @brief Append a new node to a container as a signed integer
	*
	* @param parent
	* @param name
	* @param value
	* @return*
	*/
GEN_API gen_ADT_Node* gen_adt_append_int(gen_ADT_Node* parent, char const* name, gen_s64 value);

/* parser helpers */

/**
	* @brief Parses a text and stores the result into an unitialised node.
	*
	* @param node
	* @param base
	* @return*
	*/
GEN_API char* gen_adt_parse_number(gen_ADT_Node* node, char* base);

/**
	* @brief Parses a text and stores the result into an unitialised node.
	* This function expects the entire input to be a number.
	*
	* @param node
	* @param base
	* @return*
	*/
GEN_API char* gen_adt_parse_number_strict(gen_ADT_Node* node, char* base_str);

/**
	* @brief Parses and converts an existing string node into a number.
	*
	* @param node
	* @return
	*/
GEN_API gen_ADT_Error gen_adt_c_str_to_number(gen_ADT_Node* node);

/**
	* @brief Parses and converts an existing string node into a number.
	* This function expects the entire input to be a number.
	*
	* @param node
	* @return
	*/
GEN_API gen_ADT_Error gen_adt_c_str_to_number_strict(gen_ADT_Node* node);

/**
	* @brief Prints a number into a file stream.
	*
	* The provided file handle can also be a memory mapped stream.
	*
	* @see zpl_file_stream_new
	* @param file
	* @param node
	* @return
	*/
GEN_API gen_ADT_Error gen_adt_print_number(gen_FileInfo* file, gen_ADT_Node* node);

/**
	* @brief Prints a string into a file stream.
	*
	* The provided file handle can also be a memory mapped stream.
	*
	* @see zpl_file_stream_new
	* @param file
	* @param node
	* @param escaped_chars
	* @param escape_symbol
	* @return
	*/
GEN_API gen_ADT_Error gen_adt_print_string(gen_FileInfo* file, gen_ADT_Node* node, char const* escaped_chars, char const* escape_symbol);

#pragma endregion ADT

struct gen_ADT_Node;
typedef struct gen_ADT_Node gen_ADT_Node;

enum gen_CSV_Error gen_enum_underlying(gen_u32)
{
	ECSV_Error__NONE,
	ECSV_Error__INTERNAL,
	ECSV_Error__UNEXPECTED_END_OF_INPUT,
	ECSV_Error__MISMATCHED_ROWS,
};

typedef gen_u32 gen_CSV_Error;

typedef gen_ADT_Node gen_CSV_Object;

gen_u8         gen_csv_parse(gen_CSV_Object* root, char* text, gen_AllocatorInfo allocator, gen_b32 has_header);
GEN_API gen_u8 gen_csv_parse_delimiter(gen_CSV_Object* root, char* text, gen_AllocatorInfo allocator, gen_b32 has_header, char delim);
void           gen_csv_free(gen_CSV_Object* obj);

void                   gen_csv_write(gen_FileInfo* file, gen_CSV_Object* obj);
gen_StrBuilder         gen_csv_write_string(gen_AllocatorInfo a, gen_CSV_Object* obj);
GEN_API void           gen_csv_write_delimiter(gen_FileInfo* file, gen_CSV_Object* obj, char delim);
GEN_API gen_StrBuilder gen_csv_write_strbuilder_delimiter(gen_AllocatorInfo a, gen_CSV_Object* obj, char delim);

/* inline */

inline gen_u8 gen_csv_parse(gen_CSV_Object* root, char* text, gen_AllocatorInfo allocator, gen_b32 has_header)
{
	return gen_csv_parse_delimiter(root, text, allocator, has_header, ',');
}

inline void gen_csv_write(gen_FileInfo* file, gen_CSV_Object* obj)
{
	gen_csv_write_delimiter(file, obj, ',');
}

inline gen_StrBuilder gen_csv_write_string(gen_AllocatorInfo a, gen_CSV_Object* obj)
{
	return gen_csv_write_strbuilder_delimiter(a, obj, ',');
}

GEN_NS_END
