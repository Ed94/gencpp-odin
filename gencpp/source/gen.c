// This file was generated automatially by gencpp's c_library.cpp  (See: https://github.com/Ed94/gencpp)

#ifdef __clang__
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wunused-const-variable"
#	pragma clang diagnostic ignored "-Wunused-but-set-variable"
#	pragma clang diagnostic ignored "-Wswitch"
#	pragma clang diagnostic ignored "-Wunused-variable"
#   pragma clang diagnostic ignored "-Wunknown-pragmas"
#	pragma clang diagnostic ignored "-Wvarargs"
#	pragma clang diagnostic ignored "-Wunused-function"
#	pragma clang diagnostic ignored "-Wbraced-scalar-init"
#   pragma clang diagnostic ignored "-W#pragma-messages"
#	pragma clang diagnostic ignored "-Wstatic-in-inline"
#endif

#ifdef __GNUC__
#	pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunknown-pragmas"
#	pragma GCC diagnostic ignored "-Wcomment"
#	pragma GCC diagnostic ignored "-Wswitch"
#	pragma GCC diagnostic ignored "-Wunused-variable"
#endif
#if ! defined(GEN_DONT_ENFORCE_GEN_TIME_GUARD) && ! defined(GEN_TIME)
#	error Gen.hpp : GEN_TIME not defined
#endif

#include "gen.h"

//! If its desired to roll your own dependencies, define GEN_ROLL_OWN_DEPENDENCIES before including this file.
//! Dependencies are derived from the c-zpl library: https://github.com/zpl-c/zpl
#ifndef GEN_ROLL_OWN_DEPENDENCIES
#	include "gen.dep.c"
#endif

GEN_NS_BEGIN

#pragma region StaticData
GEN_API gen_global gen_Context* gen__ctx;
GEN_API gen_global gen_u32      context_counter;

#pragma region Constants
GEN_API gen_global gen_Macro gen_enum_underlying_macro;

GEN_API gen_global gen_Code gen_Code_Global;
GEN_API gen_global gen_Code gen_Code_Invalid;

GEN_API gen_global gen_Code gen_access_public;
GEN_API gen_global gen_Code gen_access_protected;
GEN_API gen_global gen_Code gen_access_private;

GEN_API gen_global gen_CodeAttributes gen_attrib_api_export;
GEN_API gen_global gen_CodeAttributes gen_attrib_api_import;

GEN_API gen_global gen_Code gen_module_global_fragment;
GEN_API gen_global gen_Code gen_module_private_fragment;

GEN_API gen_global gen_Code gen_fmt_newline;

GEN_API gen_global gen_CodeParams gen_param_varadic;

GEN_API gen_global gen_CodePragma gen_pragma_once;

GEN_API gen_global gen_CodePreprocessCond gen_preprocess_else;
GEN_API gen_global gen_CodePreprocessCond gen_preprocess_endif;

GEN_API gen_global gen_CodeSpecifiers gen_spec_const;
GEN_API gen_global gen_CodeSpecifiers gen_spec_consteval;
GEN_API gen_global gen_CodeSpecifiers gen_spec_constexpr;
GEN_API gen_global gen_CodeSpecifiers gen_spec_constinit;
GEN_API gen_global gen_CodeSpecifiers gen_spec_extern_linkage;
GEN_API gen_global gen_CodeSpecifiers gen_spec_final;
GEN_API gen_global gen_CodeSpecifiers gen_spec_forceinline;
GEN_API gen_global gen_CodeSpecifiers gen_spec_global;
GEN_API gen_global gen_CodeSpecifiers gen_spec_inline;
GEN_API gen_global gen_CodeSpecifiers gen_spec_internal_linkage;
GEN_API gen_global gen_CodeSpecifiers gen_spec_local_persist;
GEN_API gen_global gen_CodeSpecifiers gen_spec_mutable;
GEN_API gen_global gen_CodeSpecifiers gen_spec_noexcept;
GEN_API gen_global gen_CodeSpecifiers gen_spec_neverinline;
GEN_API gen_global gen_CodeSpecifiers gen_spec_override;
GEN_API gen_global gen_CodeSpecifiers gen_spec_ptr;
GEN_API gen_global gen_CodeSpecifiers gen_spec_pure;
GEN_API gen_global gen_CodeSpecifiers gen_spec_ref;
GEN_API gen_global gen_CodeSpecifiers gen_spec_register;
GEN_API gen_global gen_CodeSpecifiers gen_spec_rvalue;
GEN_API gen_global gen_CodeSpecifiers gen_spec_static_member;
GEN_API gen_global gen_CodeSpecifiers gen_spec_thread_local;
GEN_API gen_global gen_CodeSpecifiers gen_spec_virtual;
GEN_API gen_global gen_CodeSpecifiers gen_spec_volatile;

GEN_API gen_global gen_CodeTypename gen_t_empty;
GEN_API gen_global gen_CodeTypename gen_t_auto;
GEN_API gen_global gen_CodeTypename gen_t_void;
GEN_API gen_global gen_CodeTypename gen_t_int;
GEN_API gen_global gen_CodeTypename gen_t_bool;
GEN_API gen_global gen_CodeTypename gen_t_char;
GEN_API gen_global gen_CodeTypename gen_t_wchar_t;
GEN_API gen_global gen_CodeTypename gen_t_class;
GEN_API gen_global gen_CodeTypename gen_t_typename;

#ifdef GEN_DEFINE_LIBRARY_CODE_CONSTANTS
GEN_API gen_global gen_CodeTypename gen_t_b32;

GEN_API gen_global gen_CodeTypename gen_t_s8;
GEN_API gen_global gen_CodeTypename gen_t_s16;
GEN_API gen_global gen_CodeTypename gen_t_s32;
GEN_API gen_global gen_CodeTypename gen_t_s64;

GEN_API gen_global gen_CodeTypename gen_t_u8;
GEN_API gen_global gen_CodeTypename gen_t_u16;
GEN_API gen_global gen_CodeTypename gen_t_u32;
GEN_API gen_global gen_CodeTypename gen_t_u64;

GEN_API gen_global gen_CodeTypename gen_t_ssize;
GEN_API gen_global gen_CodeTypename gen_t_usize;

GEN_API gen_global gen_CodeTypename gen_t_f32;
GEN_API gen_global gen_CodeTypename gen_t_f64;
#endif

#pragma endregion Constants

#pragma endregion StaticData

#pragma region AST

// These macros are used in the swtich cases within ast.cpp, inteface.upfront.cpp, parser.cpp

#	define GEN_AST_BODY_CLASS_UNALLOWED_TYPES_CASES    \
	case CT_PlatformAttributes:                  \
	case CT_Class_Body:                          \
	case CT_Enum_Body:                           \
	case CT_Extern_Linkage:                      \
	case CT_Function_Body:                       \
	case CT_Function_Fwd:                        \
	case CT_Global_Body:                         \
	case CT_Namespace:                           \
	case CT_Namespace_Body:                      \
	case CT_Operator:                            \
	case CT_Operator_Fwd:                        \
	case CT_Parameters:                          \
	case CT_Specifiers:                          \
	case CT_Struct_Body:                         \
	case CT_Typename
#	define GEN_AST_BODY_STRUCT_UNALLOWED_TYPES_CASES GEN_AST_BODY_CLASS_UNALLOWED_TYPES_CASES

#	define GEN_AST_BODY_FUNCTION_UNALLOWED_TYPES_CASES \
	case CT_Access_Public:                          \
	case CT_Access_Protected:                       \
	case CT_Access_Private:                         \
	case CT_PlatformAttributes:                     \
	case CT_Class_Body:                             \
	case CT_Enum_Body:                              \
	case CT_Extern_Linkage:                         \
	case CT_Friend:                                 \
	case CT_Function_Body:                          \
	case CT_Function_Fwd:                           \
	case CT_Global_Body:                            \
	case CT_Namespace:                              \
	case CT_Namespace_Body:                         \
	case CT_Operator:                               \
	case CT_Operator_Fwd:                           \
	case CT_Operator_Member:                        \
	case CT_Operator_Member_Fwd:                    \
	case CT_Parameters:                             \
	case CT_Specifiers:                             \
	case CT_Struct_Body:                            \
	case CT_Typename

#	define GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES_CASES     \
	case CT_Access_Public:                         \
	case CT_Access_Protected:                      \
	case CT_Access_Private:                        \
	case CT_PlatformAttributes:                    \
	case CT_Class_Body:                            \
	case CT_Enum_Body:                             \
	case CT_Execution:                             \
	case CT_Friend:                                \
	case CT_Function_Body:                         \
	case CT_Namespace_Body:                        \
	case CT_Operator_Member:                       \
	case CT_Operator_Member_Fwd:                   \
	case CT_Parameters:                            \
	case CT_Specifiers:                            \
	case CT_Struct_Body:                           \
	case CT_Typename
#	define GEN_AST_BODY_EXPORT_UNALLOWED_TYPES_CASES         GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES_CASES
#	define GEN_AST_BODY_EXTERN_LINKAGE_UNALLOWED_TYPES_CASES GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES_CASES

#	define GEN_AST_BODY_NAMESPACE_UNALLOWED_TYPES_CASES \
	case CT_Access_Public:                        \
	case CT_Access_Protected:                     \
	case CT_Access_Private:                       \
	case CT_PlatformAttributes:                   \
	case CT_Class_Body:                           \
	case CT_Enum_Body:                            \
	case CT_Execution:                            \
	case CT_Friend:                               \
	case CT_Function_Body:                        \
	case CT_Namespace_Body:                       \
	case CT_Operator_Member:                      \
	case CT_Operator_Member_Fwd:                  \
	case CT_Parameters:                           \
	case CT_Specifiers:                           \
	case CT_Struct_Body:                          \
	case CT_Typename

// This serializes all the data-members in a "debug" format, where each member is printed with its associated value.
gen_Str gen_code__debug_str( gen_Code self)
{
GEN_ASSERT(self != gen_nullptr);
	gen_StrBuilder  result_stack = gen_strbuilder_make_reserve( gen__ctx->Allocator_Temp, gen_kilobytes(1) );
	gen_StrBuilder* result       = & result_stack;

	if ( self->Parent )
		gen_strbuilder_append_fmt( result, "\n\tParent       : %S %S", gen_code_type_str(self->Parent), self->Name.Len ? self->Name : txt("Null") );
	else
		gen_strbuilder_append_fmt( result, "\n\tParent       : %S", txt("Null") );

	gen_strbuilder_append_fmt( result, "\n\tName         : %S", self->Name.Len ? self->Name : txt("Null") );
	gen_strbuilder_append_fmt( result, "\n\tType         : %S", gen_code_type_str(self) );
	gen_strbuilder_append_fmt( result, "\n\tModule Flags : %S", gen_module_flag_to_str( self->ModuleFlags ) );

	switch ( self->Type )
	{
		case CT_Invalid:
		case CT_NewLine:
		case CT_Access_Private:
		case CT_Access_Protected:
		case CT_Access_Public:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
		break;

		case CT_Untyped:
		case CT_Execution:
		case CT_Comment:
		case CT_PlatformAttributes:
		case CT_Preprocess_Include:
		case CT_Preprocess_Pragma:
		case CT_Preprocess_If:
		case CT_Preprocess_ElIf:
		case CT_Preprocess_Else:
		case CT_Preprocess_IfDef:
		case CT_Preprocess_IfNotDef:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tContent: %S", self->Content );
		break;

		case CT_Preprocess_Define:
			// TODO(ED): Needs implementaton
			gen_log_failure("gen_code_debug_str: NOT IMPLEMENTED for CT_Preprocess_Define");
		break;

		case CT_Class:
		case CT_Struct:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt   : %S", self->InlineCmt  ? self->InlineCmt->Content                                  : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tAttributes  : %S", self->Attributes ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Attributes) ) : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tParentAccess: %S", self->ParentType ? gen_access_spec_to_str( self->ParentAccess )                  : txt("No Parent") );
			gen_strbuilder_append_fmt( result, "\n\tParentType  : %S", self->ParentType ? gen_code_type_str(self->ParentType)                           : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tBody        : %S", self->Body       ? gen_code_debug_str(self->Body)                                : txt("Null") );
		break;

		case CT_Class_Fwd:
		case CT_Struct_Fwd:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt   : %S", self->InlineCmt  ? self->InlineCmt->Content                                  : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tAttributes  : %S", self->Attributes ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Attributes) ) : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tParentAccess: %S", self->ParentType ? gen_access_spec_to_str( self->ParentAccess )                  : txt("No Parent") );
			gen_strbuilder_append_fmt( result, "\n\tParentType  : %S", self->ParentType ? gen_code_type_str(self->ParentType)                           : txt("Null") );
		break;

		case CT_Constructor:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt      : %S", self->InlineCmt       ? self->InlineCmt->Content                                       : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tSpecs          : %S", self->Specs           ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Specs) )           : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tInitializerList: %S", self->InitializerList ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->InitializerList) ) : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tParams         : %S", self->Params          ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Params) )          : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tBody           : %S", self->Body            ? gen_code_debug_str(self->Body)                                     : txt("Null") );
		break;

		case CT_Constructor_Fwd:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt      : %S", self->InlineCmt       ? self->InlineCmt->Content                                       : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tSpecs          : %S", self->Specs           ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Specs) )           : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tInitializerList: %S", self->InitializerList ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->InitializerList) ) : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tParams         : %S", self->Params          ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Params) )          : txt("Null") );
		break;

		case CT_Destructor:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt      : %S", self->InlineCmt       ? self->InlineCmt->Content                             : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tSpecs          : %S", self->Specs           ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Specs) ) : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tBody           : %S", self->Body            ? gen_code_debug_str(self->Body)                           : txt("Null") );
		break;

		case CT_Destructor_Fwd:
		break;

		case CT_Enum:
		case CT_Enum_Class:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt       : %S", self->InlineCmt      ? self->InlineCmt->Content                                     : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tAttributes      : %S", self->Attributes     ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Attributes) )    : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tUnderlying Type : %S", self->UnderlyingType ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->UnderlyingType)) : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tBody            : %S", self->Body           ? gen_code_debug_str(self->Body)                                   : txt("Null") );
		break;

		case CT_Enum_Fwd:
		case CT_Enum_Class_Fwd:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt       : %S", self->InlineCmt      ? self->InlineCmt->Content                                     : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tAttributes      : %S", self->Attributes     ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Attributes) )    : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tUnderlying Type : %S", self->UnderlyingType ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->UnderlyingType)) : txt("Null") );
		break;

		case CT_Extern_Linkage:
		case CT_Namespace:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tBody: %S", self->Body ? gen_code_debug_str(self->Body) : txt("Null") );
		break;

		case CT_Friend:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt  : %S", self->InlineCmt   ? self->InlineCmt->Content                                  : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tDeclaration: %S", self->Declaration ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Declaration)) : txt("Null") );
		break;

		case CT_Function:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt : %S", self->InlineCmt  ? self->InlineCmt->Content                                  : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tAttributes: %S", self->Attributes ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Attributes) ) : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tSpecs     : %S", self->Specs      ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Specs))       : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tReturnType: %S", self->ReturnType ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->ReturnType))  : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tParams    : %S", self->Params     ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Params))      : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tBody      : %S", self->Body       ? gen_code_debug_str(self->Body)                                : txt("Null") );
		break;

		case CT_Function_Fwd:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt : %S", self->InlineCmt  ? self->InlineCmt->Content                                  : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tAttributes: %S", self->Attributes ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Attributes) ) : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tSpecs     : %S", self->Specs      ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Specs))       : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tReturnType: %S", self->ReturnType ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->ReturnType))  : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tParams    : %S", self->Params     ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Params))      : txt("Null") );
		break;

		case CT_Module:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
		break;

		case CT_Operator:
		case CT_Operator_Member:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt : %S", self->InlineCmt  ? self->InlineCmt->Content                                  : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tAttributes: %S", self->Attributes ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Attributes) ) : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tSpecs     : %S", self->Specs      ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Specs))       : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tReturnType: %S", self->ReturnType ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->ReturnType))  : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tParams    : %S", self->Params     ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Params))      : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tBody      : %S", self->Body       ? gen_code_debug_str(self->Body)                                : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tOp        : %S", gen_operator_to_str( self->Op ) );
		break;

		case CT_Operator_Fwd:
		case CT_Operator_Member_Fwd:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt : %S", self->InlineCmt  ? self->InlineCmt->Content                                  : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tAttributes: %S", self->Attributes ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Attributes) ) : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tSpecs     : %S", self->Specs      ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Specs) )      : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tReturnType: %S", self->ReturnType ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->ReturnType) ) : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tParams    : %S", self->Params     ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Params) )     : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tOp        : %S", gen_operator_to_str( self->Op ) );
		break;

		case CT_Operator_Cast:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt : %S", self->InlineCmt  ? self->InlineCmt->Content                                : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tSpecs     : %S", self->Specs      ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Specs))     : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tValueType : %S", self->ValueType  ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->ValueType)) : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tBody      : %S", self->Body       ? gen_code_debug_str(self->Body)                              : txt("Null") );
		break;

		case CT_Operator_Cast_Fwd:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt : %S", self->InlineCmt  ? self->InlineCmt->Content                                : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tSpecs     : %S", self->Specs      ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Specs))     : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tValueType : %S", self->ValueType  ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->ValueType)) : txt("Null") );
		break;

		case CT_Parameters:
			gen_strbuilder_append_fmt( result, "\n\tNumEntries: %d", self->NumEntries );
			gen_strbuilder_append_fmt( result, "\n\tLast      : %S", self->Last->Name );
			gen_strbuilder_append_fmt( result, "\n\tNext      : %S", self->Next->Name );
			gen_strbuilder_append_fmt( result, "\n\tValueType : %S", self->ValueType ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->ValueType)) : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tValue     : %S", self->Value     ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Value))     : txt("Null") );
		break;

		case CT_Parameters_Define:
			// TODO(ED): Needs implementaton
			gen_log_failure("gen_code_debug_str: NOT IMPLEMENTED for CT_Parameters_Define");
		break;

		case CT_Specifiers:
		{
			gen_strbuilder_append_fmt( result, "\n\tNumEntries: %d", self->NumEntries );
			gen_strbuilder_append_str( result, txt("\n\tArrSpecs: ") );

			gen_s32 idx  = 0;
			gen_s32 left = self->NumEntries;
			while ( left-- )
			{
				gen_Str spec = gen_spec_to_str( self->ArrSpecs[idx] );
				gen_strbuilder_append_fmt( result, "%.*s, ", spec.Len, spec.Ptr );
				idx++;
			}
			gen_strbuilder_append_fmt( result, "\n\tNextSpecs: %S", self->NextSpecs ? gen_code_debug_str(self->NextSpecs) : txt("Null") );
		}
		break;

		case CT_Template:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tParams     : %S", self->Params      ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Params))      : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tDeclaration: %S", self->Declaration ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Declaration)) : txt("Null") );
		break;

		case CT_Typedef:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt     : %S", self->InlineCmt      ? self->InlineCmt->Content                                     : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tUnderlyingType: %S", self->UnderlyingType ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->UnderlyingType)) : txt("Null") );
		break;

		case CT_Typename:
			gen_strbuilder_append_fmt( result, "\n\tAttributes     : %S", self->Attributes ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Attributes) ) : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tSpecs          : %S", self->Specs      ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Specs))       : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tReturnType     : %S", self->ReturnType ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->ReturnType))  : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tParams         : %S", self->Params     ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Params))      : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tArrExpr        : %S", self->ArrExpr    ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->ArrExpr))     : txt("Null") );
		break;

		case CT_Union:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tAttributes: %S", self->Attributes ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Attributes) ) : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tBody      : %S", self->Body       ? gen_code_debug_str(self->Body)                                : txt("Null") );
		break;

		case CT_Using:
			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt     : %S", self->InlineCmt      ? self->InlineCmt->Content                                      : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tAttributes    : %S", self->Attributes     ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Attributes) )     : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tUnderlyingType: %S", self->UnderlyingType ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->UnderlyingType))  : txt("Null") );
		break;

		case CT_Variable:

			if ( self->Parent && self->Parent->Type == CT_Variable )
			{
				// Its a NextVar
				gen_strbuilder_append_fmt( result, "\n\tSpecs       : %S", self->Specs        ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Specs))        : txt("Null") );
				gen_strbuilder_append_fmt( result, "\n\tValue       : %S", self->Value        ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Value))        : txt("Null") );
				gen_strbuilder_append_fmt( result, "\n\tBitfieldSize: %S", self->BitfieldSize ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->BitfieldSize)) : txt("Null") );
				gen_strbuilder_append_fmt( result, "\n\tNextVar     : %S", self->NextVar      ? gen_code_debug_str(self->NextVar)                              : txt("Null") );
				break;
			}

			if ( self->Prev )
				gen_strbuilder_append_fmt( result, "\n\tPrev: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				gen_strbuilder_append_fmt( result, "\n\tNext: %S %S", gen_code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			gen_strbuilder_append_fmt( result, "\n\tInlineCmt   : %S", self->InlineCmt    ? self->InlineCmt->Content                                    : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tAttributes  : %S", self->Attributes   ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Attributes) )   : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tSpecs       : %S", self->Specs        ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Specs))         : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tValueType   : %S", self->ValueType    ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->ValueType))     : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tBitfieldSize: %S", self->BitfieldSize ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->BitfieldSize))  : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tValue       : %S", self->Value        ? gen_strbuilder_to_str( gen_code_to_strbuilder(self->Value))         : txt("Null") );
			gen_strbuilder_append_fmt( result, "\n\tNextVar     : %S", self->NextVar      ? gen_code_debug_str(self->NextVar)                               : txt("Null") );
		break;
	}

	return gen_strbuilder_to_str( * result );
}

gen_Code gen_code__duplicate( gen_Code self)
{
gen_Code result = gen_make_code();

	void* mem_result = gen_rcast(void*, gen_cast(gen_AST*, result));
	void* mem_self   = gen_rcast(void*, gen_cast(gen_AST*, self));
	gen_mem_copy( mem_result, mem_self, sizeof( gen_AST ) );

	result->Parent = gen_NullCode;
	return result;
}

gen_StrBuilder gen_code__to_strbuilder( gen_Code self)
{
gen_StrBuilder result = gen_strbuilder_make_str( gen__ctx->Allocator_Temp, txt("") );
	gen_code_to_strbuilder_ref( self, & result );
	return result;
}

void gen_code__to_strbuilder_ref( gen_Code self,  gen_StrBuilder *  result)
{
GEN_ASSERT(self != gen_nullptr);
	gen_local_persist gen_thread_local
	char SerializationLevel = 0;

	switch ( self->Type )
	{
		case CT_Invalid:
		#ifdef GEN_DONT_ALLOW_INVALID_CODE
			gen_log_failure("Attempted to serialize invalid code! - %S", Parent ? Parent->gen_code_debug_str() : Name );
		#else
			gen_strbuilder_append_fmt( result, "Invalid gen_Code!" );
		#endif
		break;

		case CT_NewLine:
			gen_strbuilder_append_str( result, txt("\n"));
		break;

		case CT_Untyped:
		case CT_Execution:
		case CT_Comment:
		case CT_PlatformAttributes:
			gen_strbuilder_append_str( result, self->Content );
		break;

		case CT_Access_Private:
		case CT_Access_Protected:
		case CT_Access_Public:
			gen_strbuilder_append_str( result, self->Name );
		break;

		case CT_Class:
			gen_class_to_strbuilder_def(gen_cast(gen_CodeClass, self), result );
		break;

		case CT_Class_Fwd:
			gen_class_to_strbuilder_fwd(gen_cast(gen_CodeClass, self), result );
		break;

		case CT_Constructor:
			gen_constructor__to_strbuilder_def(gen_cast(gen_CodeConstructor, self), result );
		break;

		case CT_Constructor_Fwd:
			gen_constructor__to_strbuilder_fwd(gen_cast(gen_CodeConstructor, self), result );
		break;

		case CT_Destructor:
			gen_destructor__to_strbuilder_def(gen_cast(gen_CodeDestructor, self), result );
		break;

		case CT_Destructor_Fwd:
			gen_destructor__to_strbuilder_fwd(gen_cast(gen_CodeDestructor, self), result );
		break;

		case CT_Enum:
			gen_enum_to_strbuilder_def(gen_cast(gen_CodeEnum, self), result );
		break;

		case CT_Enum_Fwd:
			gen_enum_to_strbuilder_fwd(gen_cast(gen_CodeEnum, self), result );
		break;

		case CT_Enum_Class:
			gen_enum_to_strbuilder_class_def(gen_cast(gen_CodeEnum, self), result );
		break;

		case CT_Enum_Class_Fwd:
			gen_enum_to_strbuilder_class_fwd(gen_cast(gen_CodeEnum, self), result );
		break;

		case CT_Export_Body:
			gen_body_to_strbuilder_export(gen_cast(gen_CodeBody, self), result );
		break;

		case CT_Extern_Linkage:
			gen_extern_to_strbuilder(gen_cast(gen_CodeExtern, self), result );
		break;

		case CT_Friend:
			gen_friend_to_strbuilder_ref(gen_cast(gen_CodeFriend, self), result );
		break;

		case CT_Function:
			gen_fn_to_strbuilder_def(gen_cast(gen_CodeFn, self), result );
		break;

		case CT_Function_Fwd:
			gen_fn_to_strbuilder_fwd(gen_cast(gen_CodeFn, self), result );
		break;

		case CT_Module:
			gen_module_to_strbuilder_ref(gen_cast(gen_CodeModule, self), result );
		break;

		case CT_Namespace:
			namespace_to_strbuilder_ref(gen_cast(gen_CodeNS, self), result );
		break;

		case CT_Operator:
		case CT_Operator_Member:
			gen_code_op_to_strbuilder_def(gen_cast(gen_CodeOperator, self), result );
		break;

		case CT_Operator_Fwd:
		case CT_Operator_Member_Fwd:
			gen_code_op_to_strbuilder_fwd(gen_cast(gen_CodeOperator, self), result );
		break;

		case CT_Operator_Cast:
			gen_opcast_to_strbuilder_def(gen_cast(gen_CodeOpCast, self), result );
		break;

		case CT_Operator_Cast_Fwd:
			gen_opcast_to_strbuilder_fwd(gen_cast(gen_CodeOpCast, self), result );
		break;

		case CT_Parameters:
			gen_params_to_strbuilder_ref(gen_cast(gen_CodeParams, self), result );
		break;

		case CT_Parameters_Define:
			gen_define_params_to_strbuilder_ref(gen_cast(gen_CodeDefineParams, self), result);
		break;

		case CT_Preprocess_Define:
			gen_define_to_strbuilder_ref(gen_cast(gen_CodeDefine, self), result );
		break;

		case CT_Preprocess_If:
			gen_preprocess_to_strbuilder_if(gen_cast(gen_CodePreprocessCond, self), result );
		break;

		case CT_Preprocess_IfDef:
			gen_preprocess_to_strbuilder_ifdef(gen_cast(gen_CodePreprocessCond, self), result );
		break;

		case CT_Preprocess_IfNotDef:
			gen_preprocess_to_strbuilder_ifndef(gen_cast(gen_CodePreprocessCond, self), result );
		break;

		case CT_Preprocess_Include:
			gen_include_to_strbuilder_ref(gen_cast(gen_CodeInclude, self), result );
		break;

		case CT_Preprocess_ElIf:
			gen_preprocess_to_strbuilder_elif(gen_cast(gen_CodePreprocessCond, self), result );
		break;

		case CT_Preprocess_Else:
			gen_preprocess_to_strbuilder_else(gen_cast(gen_CodePreprocessCond, self), result );
		break;

		case CT_Preprocess_EndIf:
			gen_preprocess_to_strbuilder_endif(gen_cast(gen_CodePreprocessCond, self), result );
		break;

		case CT_Preprocess_Pragma:
			gen_pragma_to_strbuilder_ref(gen_cast(gen_CodePragma, self), result );
		break;

		case CT_Specifiers:
			gen_specifiers_to_strbuilder_ref(gen_cast(gen_CodeSpecifiers, self), result );
		break;

		case CT_Struct:
			gen_struct_to_strbuilder_def(gen_cast(gen_CodeStruct, self), result );
		break;

		case CT_Struct_Fwd:
			gen_struct_to_strbuilder_fwd(gen_cast(gen_CodeStruct, self), result );
		break;

		case CT_Template:
			gen_template_to_strbuilder_ref(gen_cast(gen_CodeTemplate, self), result );
		break;

		case CT_Typedef:
			gen_typedef_to_strbuilder_ref(gen_cast(gen_CodeTypedef, self), result );
		break;

		case CT_Typename:
			gen_typename_to_strbuilder_ref(gen_cast(gen_CodeTypename, self), result );
		break;

		case CT_Union:
			union_to_strbuilder_def( gen_cast(gen_CodeUnion, self), result );
		break;

		case CT_Union_Fwd:
			union_to_strbuilder_fwd( gen_cast(gen_CodeUnion, self), result );
		break;

		case CT_Using:
			gen_using_to_strbuilder_ref(gen_cast(gen_CodeUsing, self), result );
		break;

		case CT_Using_Namespace:
			gen_using_to_strbuilder_ns(gen_cast(gen_CodeUsing, self), result );
		break;

		case CT_Variable:
			gen_var_to_strbuilder_ref(gen_cast(gen_CodeVar, self), result );
		break;

		case CT_Enum_Body:
		case CT_Class_Body:
		case CT_Extern_Linkage_Body:
		case CT_Function_Body:
		case CT_Global_Body:
		case CT_Namespace_Body:
		case CT_Struct_Body:
		case CT_Union_Body:
			gen_body_to_strbuilder_ref( gen_cast(gen_CodeBody, self), result );
		break;
	}
}

bool gen_code__is_equal( gen_Code self,  gen_Code other)
{
/*
	gen_AST values are either some gen_u32 value, a cached string, or a pointer to another gen_AST.

	gen_u32 values are compared by value.
	Cached strings are compared by pointer.
	gen_AST nodes are compared with gen_AST::is_equal.
*/
	if ( other == gen_nullptr )
	{
		gen_log_fmt( "gen_AST::is_equal: other is null\nAST: %S", gen_code_debug_str(self) );
		return false;
	}

	if ( self->Type != other->Type )
	{
		gen_log_fmt("gen_AST::is_equal: Type check failure with other\nAST: %S\nOther: %S"
			, gen_code_debug_str(self)
			, gen_code_debug_str(other)
		);

		return false;
	}

	switch ( self->Type )
	{
	#define check_member_val( val )                           \
	if ( self->val != other->val )                            \
	{                                                         \
		gen_log_fmt("\nAST::is_equal: Member - " #val " failed\n" \
		        "gen_AST  : %S\n"                                 \
		        "Other: %S\n"                                 \
		    , gen_code_debug_str(self)                            \
		    ,gen_code_debug_str(other)                            \
		);                                                    \
                                                              \
		return false;                                         \
	}

	#define check_member_str( str )                                 \
	if ( ! gen_str_are_equal( self->str, other->str ) )                 \
	{                                                               \
		gen_log_fmt("\nAST::is_equal: Member string - "#str " failed\n" \
				"gen_AST  : %S\n"                                       \
				"Other: %S\n"                                       \
			, gen_code_debug_str(self)                                  \
			,gen_code_debug_str(other)                                  \
		);                                                          \
	                                                                \
		return false;                                               \
	}

	#define check_member_content( content )                                  \
	if ( ! gen_str_are_equal( self->content, other->content ))                   \
	{                                                                        \
		gen_log_fmt("\nAST::is_equal: Member content - "#content " failed\n"     \
				"gen_AST  : %S\n"                                                \
				"Other: %S\n"                                                \
			, gen_code_debug_str(self)                                           \
			, gen_code_debug_str(other)                                          \
		);                                                                   \
                                                                             \
		gen_log_fmt("Content cannot be trusted to be unique with this check "    \
			"so it must be verified by eye for now\n"                        \
			"gen_AST   Content:\n%S\n"                                           \
			"Other Content:\n%S\n"                                           \
			, gen_str_visualize_whitespace(self->content, gen__ctx->Allocator_Temp)  \
			, gen_str_visualize_whitespace(other->content, gen__ctx->Allocator_Temp) \
		);                                                                   \
	}

	#define check_member_ast( ast )                                                                \
	if ( self->ast )                                                                               \
	{                                                                                              \
		if ( other->ast == gen_nullptr )                                                               \
		{                                                                                          \
			gen_log_fmt("\nAST::is_equal: Failed for member " #ast " other equivalent param is null\n" \
					"gen_AST  : %S\n"                                                                  \
					"Other: %S\n"                                                                  \
					"For ast member: %S\n"                                                         \
				, gen_code_debug_str(self)                                                             \
				, gen_code_debug_str(other)                                                            \
				, gen_code_debug_str(self->ast)                                                        \
			);                                                                                     \
                                                                                                   \
			return false;                                                                          \
		}                                                                                          \
                                                                                                   \
		if ( ! gen_code_is_equal(self->ast, other->ast ) )                                             \
		{                                                                                          \
			gen_log_fmt( "\nAST::is_equal: Failed for " #ast"\n"                                       \
					"gen_AST  : %S\n"                                                                  \
					"Other: %S\n"                                                                  \
					"For     ast member: %S\n"                                                     \
					"other's ast member: %S\n"                                                     \
				, gen_code_debug_str(self)                                                             \
				, gen_code_debug_str(other)                                                            \
				, gen_code_debug_str(self->ast)                                                        \
				, gen_code_debug_str(other->ast)                                                       \
			);                                                                                     \
		                                                                                           \
			return false;                                                                          \
		}                                                                                          \
	}

		case CT_NewLine:
		case CT_Access_Public:
		case CT_Access_Protected:
		case CT_Access_Private:
		case CT_Preprocess_Else:
		case CT_Preprocess_EndIf:
			return true;


		// Comments are not validated.
		case CT_Comment:
			return true;

		case CT_Execution:
		case CT_PlatformAttributes:
		case CT_Untyped:
		{
			check_member_content( Content );
			return true;
		}

		case CT_Class_Fwd:
		case CT_Struct_Fwd:
		{
			check_member_str( Name );
			check_member_ast( ParentType );
			check_member_val( ParentAccess );
			check_member_ast( Attributes );

			return true;
		}

		case CT_Class:
		case CT_Struct:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( ParentType );
			check_member_val( ParentAccess );
			check_member_ast( Attributes );
			check_member_ast( Body );

			return true;
		}

		case CT_Constructor:
		{
			check_member_ast( InitializerList );
			check_member_ast( Params );
			check_member_ast( Body );

			return true;
		}

		case CT_Constructor_Fwd:
		{
			check_member_ast( InitializerList );
			check_member_ast( Params );

			return true;
		}

		case CT_Destructor:
		{
			check_member_ast( Specs );
			check_member_ast( Body );

			return true;
		}

		case CT_Destructor_Fwd:
		{
			check_member_ast( Specs );

			return true;
		}

		case CT_Enum:
		case CT_Enum_Class:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Attributes );
			check_member_ast( UnderlyingType );
			check_member_ast( Body );
			check_member_ast( UnderlyingTypeMacro );

			return true;
		}

		case CT_Enum_Fwd:
		case CT_Enum_Class_Fwd:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Attributes );
			check_member_ast( UnderlyingType );
			check_member_ast( UnderlyingTypeMacro );

			return true;
		}

		case CT_Extern_Linkage:
		{
			check_member_str( Name );
			check_member_ast( Body );

			return true;
		}

		case CT_Friend:
		{
			check_member_str( Name );
			check_member_ast( Declaration );

			return true;
		}

		case CT_Function:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( ReturnType );
			check_member_ast( Attributes );
			check_member_ast( Specs );
			check_member_ast( Params );
			check_member_ast( Body );

			return true;
		}

		case CT_Function_Fwd:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( ReturnType );
			check_member_ast( Attributes );
			check_member_ast( Specs );
			check_member_ast( Params );

			return true;
		}

		case CT_Module:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );

			return true;
		}

		case CT_Namespace:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Body );

			return true;
		}

		case CT_Operator:
		case CT_Operator_Member:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( ReturnType );
			check_member_ast( Attributes );
			check_member_ast( Specs );
			check_member_ast( Params );
			check_member_ast( Body );

			return true;
		}

		case CT_Operator_Fwd:
		case CT_Operator_Member_Fwd:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( ReturnType );
			check_member_ast( Attributes );
			check_member_ast( Specs );
			check_member_ast( Params );

			return true;
		}

		case CT_Operator_Cast:
		{
			check_member_str( Name );
			check_member_ast( Specs );
			check_member_ast( ValueType );
			check_member_ast( Body );

			return true;
		}

		case CT_Operator_Cast_Fwd:
		{
			check_member_str( Name );
			check_member_ast( Specs );
			check_member_ast( ValueType );

			return true;
		}

		case CT_Parameters:
		{
			if ( self->NumEntries > 1 )
			{
				gen_Code curr       = self;
				gen_Code curr_other = other;
				while ( curr != gen_nullptr  )
				{
					if ( curr )
					{
						if ( curr_other == gen_nullptr )
						{
							gen_log_fmt("\nAST::is_equal: Failed for parameter, other equivalent param is null\n"
									"gen_AST  : %S\n"
									"Other: %S\n"
									"For ast member: %S\n"
								, gen_code_debug_str(curr)
							);

							return false;
						}

						if ( gen_str_are_equal(curr->Name, curr_other->Name) )
						{
							gen_log_fmt( "\nAST::is_equal: Failed for parameter name check\n"
									"gen_AST  : %S\n"
									"Other: %S\n"
									"For     ast member: %S\n"
									"other's ast member: %S\n"
								, gen_code_debug_str(self)
								, gen_code_debug_str(other)
								, gen_code_debug_str(curr)
								, gen_code_debug_str(curr_other)
							);
							return false;
						}

						if ( curr->ValueType && ! gen_code_is_equal(curr->ValueType, curr_other->ValueType) )
						{
							gen_log_fmt( "\nAST::is_equal: Failed for parameter value type check\n"
									"gen_AST  : %S\n"
									"Other: %S\n"
									"For     ast member: %S\n"
									"other's ast member: %S\n"
								, gen_code_debug_str(self)
								, gen_code_debug_str(other)
								, gen_code_debug_str(curr)
								, gen_code_debug_str(curr_other)
							);
							return false;
						}

						if ( curr->Value && ! gen_code_is_equal(curr->Value, curr_other->Value) )
						{
							gen_log_fmt( "\nAST::is_equal: Failed for parameter value check\n"
									"gen_AST  : %S\n"
									"Other: %S\n"
									"For     ast member: %S\n"
									"other's ast member: %S\n"
								, gen_code_debug_str(self)
								, gen_code_debug_str(other)
								, gen_code_debug_str(curr)
								, gen_code_debug_str(curr_other)
							);
							return false;
						}
					}

					curr       = curr->Next;
					curr_other = curr_other->Next;
				}

				check_member_val( NumEntries );

				return true;
			}

			check_member_str( Name );
			check_member_ast( ValueType );
			check_member_ast( Value );
			check_member_ast( ArrExpr );

			return true;
		}

		case CT_Parameters_Define:
		{
			// TODO(ED): Needs implementaton
			gen_log_failure("gen_code_is_equal: NOT IMPLEMENTED for CT_Parameters_Define");
			return false;
		}

		case CT_Preprocess_Define:
		{
			check_member_str( Name );
			check_member_content( Body->Content );
			return true;
		}

		case CT_Preprocess_If:
		case CT_Preprocess_IfDef:
		case CT_Preprocess_IfNotDef:
		case CT_Preprocess_ElIf:
		{
			check_member_content( Content );

			return true;
		}

		case CT_Preprocess_Include:
		case CT_Preprocess_Pragma:
		{
			check_member_content( Content );

			return true;
		}

		case CT_Specifiers:
		{
			check_member_val( NumEntries );
			check_member_str( Name );
			for ( gen_s32 idx = 0; idx < self->NumEntries; ++idx )
			{
				check_member_val( ArrSpecs[ idx ] );
			}
			return true;
		}

		case CT_Template:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Params );
			check_member_ast( Declaration );

			return true;
		}

		case CT_Typedef:
		{
			check_member_val( IsFunction );
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Specs );
			check_member_ast( UnderlyingType );

			return true;
		}
		case CT_Typename:
		{
			check_member_val( IsParamPack );
			check_member_str( Name );
			check_member_ast( Specs );
			check_member_ast( ArrExpr );

			return true;
		}

		case CT_Union:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Attributes );
			check_member_ast( Body );

			return true;
		}

		case CT_Union_Fwd:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Attributes );
		}

		case CT_Using:
		case CT_Using_Namespace:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( UnderlyingType );
			check_member_ast( Attributes );

			return true;
		}

		case CT_Variable:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( ValueType );
			check_member_ast( BitfieldSize );
			check_member_ast( Value );
			check_member_ast( Attributes );
			check_member_ast( Specs );
			check_member_ast( NextVar );

			return true;
		}

		case CT_Class_Body:
		case CT_Enum_Body:
		case CT_Export_Body:
		case CT_Global_Body:
		case CT_Namespace_Body:
		case CT_Struct_Body:
		case CT_Union_Body:
		{
			check_member_ast( Front );
			check_member_ast( Back );

			gen_Code curr       = self->Front;
			gen_Code curr_other = other->Front;
			while ( curr != gen_nullptr )
			{
				if ( curr_other == gen_nullptr )
				{
					gen_log_fmt("\nAST::is_equal: Failed for body, other equivalent param is null\n"
							"gen_AST  : %S\n"
							"Other: %S\n"
						, gen_code_debug_str(curr)
						, gen_code_debug_str(other)
					);

					return false;
				}

				if ( ! gen_code_is_equal( curr, curr_other ) )
				{
					gen_log_fmt( "\nAST::is_equal: Failed for body\n"
							"gen_AST  : %S\n"
							"Other: %S\n"
							"For     ast member: %S\n"
							"other's ast member: %S\n"
						, gen_code_debug_str(self)
						, gen_code_debug_str(other)
						, gen_code_debug_str(curr)
						, gen_code_debug_str(curr_other)
					);

					return false;
				}

				curr       = curr->Next;
				curr_other = curr_other->Next;
			}

			check_member_val( NumEntries );

			return true;
		}

	#undef check_member_val
	#undef check_member_str
	#undef check_member_ast
	}

	return true;
}

bool gen_code__validate_body( gen_Code self)
{
switch ( self->Type )
	{
		case CT_Class_Body:
		{
			gen_CodeBody body = gen_cast(gen_CodeBody, self);
			for (gen_Code gen_code_entry = gen_begin_CodeBody(body); gen_code_entry != gen_end_CodeBody(body); gen_next_CodeBody(body, gen_code_entry)) switch (gen_code_entry->Type)
			{
				GEN_AST_BODY_CLASS_UNALLOWED_TYPES_CASES:
					gen_log_failure("gen_AST::validate_body: Invalid entry in body %S", gen_code_debug_str(gen_code_entry));
				return false;

				default:
				continue;
			}
		}
		break;
		case CT_Enum_Body:
		{
			gen_CodeBody body = gen_cast(gen_CodeBody, self);
			for ( gen_Code entry = gen_begin_CodeBody(body); entry != gen_end_CodeBody(body); gen_next_CodeBody(body, entry) )
			{
				if ( entry->Type != CT_Untyped )
				{
					gen_log_failure( "gen_AST::validate_body: Invalid entry in enum body (needs to be untyped or comment) %S", gen_code_debug_str(entry) );
					return false;
				}
			}
		}
		break;
		case CT_Export_Body:
		{
			gen_CodeBody body = gen_cast(gen_CodeBody, self);
			for (gen_Code gen_code_entry = gen_begin_CodeBody(body); gen_code_entry != gen_end_CodeBody(body); gen_next_CodeBody(body, gen_code_entry)) switch (gen_code_entry->Type)
			{
				GEN_AST_BODY_EXPORT_UNALLOWED_TYPES_CASES:
					gen_log_failure("gen_AST::validate_body: Invalid entry in body %S", gen_code_debug_str(gen_code_entry));
				return false;

				default:
				continue;
			}
		}
		break;
		case CT_Extern_Linkage:
		{
			gen_CodeBody body = gen_cast(gen_CodeBody, self);
			for (gen_Code gen_code_entry = gen_begin_CodeBody(body); gen_code_entry != gen_end_CodeBody(body); gen_next_CodeBody(body, gen_code_entry)) switch (gen_code_entry->Type)
			{
				GEN_AST_BODY_EXTERN_LINKAGE_UNALLOWED_TYPES_CASES:
					gen_log_failure("gen_AST::validate_body: Invalid entry in body %S", gen_code_debug_str(gen_code_entry));
				return false;

				default:
				continue;
			}
		}
		break;
		case CT_Function_Body:
		{
			gen_CodeBody body = gen_cast(gen_CodeBody, self);
			for (gen_Code gen_code_entry = gen_begin_CodeBody(body); gen_code_entry != gen_end_CodeBody(body); gen_next_CodeBody(body, gen_code_entry)) switch (gen_code_entry->Type)
			{
				GEN_AST_BODY_FUNCTION_UNALLOWED_TYPES_CASES:
					gen_log_failure("gen_AST::validate_body: Invalid entry in body %S", gen_code_debug_str(gen_code_entry));
				return false;

				default:
				continue;
			}
		}
		break;
		case CT_Global_Body:
		{
			gen_CodeBody body = gen_cast(gen_CodeBody, self);
			for ( gen_Code entry = gen_begin_CodeBody(body); entry != gen_end_CodeBody(body); gen_next_CodeBody(body, entry) )switch (entry->Type)
			{
				GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES_CASES:
					gen_log_failure("gen_AST::validate_body: Invalid entry in body %S", gen_code_debug_str(entry));
				return false;
			}
		}
		break;
		case CT_Namespace_Body:
		{
			gen_CodeBody body = gen_cast(gen_CodeBody, self);
			for ( gen_Code entry = gen_begin_CodeBody(body); entry != gen_end_CodeBody(body); gen_next_CodeBody(body, entry) ) switch (entry->Type)
			{
				GEN_AST_BODY_NAMESPACE_UNALLOWED_TYPES_CASES:
					gen_log_failure("gen_AST::validate_body: Invalid entry in body %S", gen_code_debug_str(entry));
				return false;
			}
		}
		break;
		case CT_Struct_Body:
		{
			gen_CodeBody body = gen_cast(gen_CodeBody, self);
			for ( gen_Code entry = gen_begin_CodeBody(body); entry != gen_end_CodeBody(body); gen_next_CodeBody(body, entry) ) switch (entry->Type)
			{
				GEN_AST_BODY_STRUCT_UNALLOWED_TYPES_CASES:
					gen_log_failure("gen_AST::validate_body: Invalid entry in body %S", gen_code_debug_str(entry));
				return false;
			}
		}
		break;
		case CT_Union_Body:
		{
			gen_CodeBody body = gen_cast(gen_CodeBody, self);
			for ( gen_Code entry = gen_begin_CodeBody(body); entry != gen_end_CodeBody(body); gen_next_CodeBody(body, entry) )
			{
				if ( entry->Type != CT_Untyped )
				{
					gen_log_failure( "gen_AST::validate_body: Invalid entry in union body (needs to be untyped or comment) %S", gen_code_debug_str(entry) );
					return false;
				}
			}
		}
		break;

		default:
			gen_log_failure( "gen_AST::validate_body: Invalid this gen_AST does not have a body %S", gen_code_debug_str(self) );
			return false;
	}
	return false;
}

gen_StrBuilder gen_body_to_strbuilder(gen_CodeBody body)
{
	GEN_ASSERT(body);
	gen_StrBuilder result = gen_strbuilder_make_reserve( gen__ctx->Allocator_Temp, 128 );
	switch ( body->Type )
	{
		case CT_Untyped:
		case CT_Execution:
			gen_strbuilder_append_str( & result, gen_cast(gen_Code, body)->Content );
		break;

		case CT_Enum_Body:
		case CT_Class_Body:
		case CT_Extern_Linkage_Body:
		case CT_Function_Body:
		case CT_Global_Body:
		case CT_Namespace_Body:
		case CT_Struct_Body:
		case CT_Union_Body:
			gen_body_to_strbuilder_ref( body, & result );
		break;

		case CT_Export_Body:
			gen_body_to_strbuilder_export( body, & result );
		break;
	}
	return result;
}

void gen_body_to_strbuilder_export( gen_CodeBody body, gen_StrBuilder* result )
{
	GEN_ASSERT(body   != gen_nullptr);
	GEN_ASSERT(result != gen_nullptr);
	gen_strbuilder_append_fmt( result, "export\n{\n" );

	gen_Code curr = gen_cast(gen_Code, body);
	gen_s32  left = body->NumEntries;
	while ( left-- )
	{
		gen_code_to_strbuilder_ref(curr, result);
		// gen_strbuilder_append_fmt( result, "%SB", gen_code_to_strbuilder(curr) );
		++curr;
	}

	gen_strbuilder_append_fmt( result, "};\n" );
}

gen_StrBuilder gen_constructor__to_strbuilder(gen_CodeConstructor self)
{
	GEN_ASSERT(self);
	gen_StrBuilder result = gen_strbuilder_make_reserve( gen__ctx->Allocator_Temp, 128 );
	switch (self->Type)
	{
		case CT_Constructor:
			gen_constructor__to_strbuilder_def( self, & result );
		break;
		case CT_Constructor_Fwd:
			gen_constructor__to_strbuilder_fwd( self, & result );
		break;
	}
	return result;
}

void gen_constructor__to_strbuilder_def(gen_CodeConstructor self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	gen_Code ClassStructParent = self->Parent->Parent;
	if (ClassStructParent) {
		gen_strbuilder_append_str( result, ClassStructParent->Name );
	}
	else {
		gen_strbuilder_append_str( result, self->Name );
	}

	if ( self->Params )
		gen_strbuilder_append_fmt( result, "( %SB )", gen_params_to_strbuilder(self->Params) );
	else
		gen_strbuilder_append_str( result, txt("()") );

	if ( self->InitializerList )
		gen_strbuilder_append_fmt( result, " : %SB", gen_code_to_strbuilder(self->InitializerList) );

	if ( self->InlineCmt )
		gen_strbuilder_append_fmt( result, " // %S", self->InlineCmt->Content );

	gen_strbuilder_append_fmt( result, "\n{\n%SB\n}\n", gen_code_to_strbuilder(self->Body) );
}

void gen_constructor__to_strbuilder_fwd(gen_CodeConstructor self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	gen_Code ClassStructParent = self->Parent->Parent;
	if (ClassStructParent) {
		gen_strbuilder_append_str( result, ClassStructParent->Name );
	}
	else {
		gen_strbuilder_append_str( result, self->Name );
	}

	if ( self->Params )
		gen_strbuilder_append_fmt( result, "( %SB )", gen_params_to_strbuilder(self->Params) );
	else
		gen_strbuilder_append_fmt( result, "()");

	if (self->Body)
		gen_strbuilder_append_fmt( result, " = %SB", gen_code_to_strbuilder(self->Body) );

	if ( self->InlineCmt )
		gen_strbuilder_append_fmt( result, "; // %S\n", self->InlineCmt->Content );
	else
		gen_strbuilder_append_str( result, txt(";\n") );
}

gen_StrBuilder gen_class_to_strbuilder( gen_CodeClass self )
{
	GEN_ASSERT(self);
	gen_StrBuilder result = gen_strbuilder_make_reserve( gen__ctx->Allocator_Temp, 512 );
	switch ( self->Type )
	{
		case CT_Class:
			gen_class_to_strbuilder_def(self, & result );
		break;
		case CT_Class_Fwd:
			gen_class_to_strbuilder_fwd(self, & result );
		break;
	}
	return result;
}

void gen_class_to_strbuilder_def( gen_CodeClass self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);

	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	gen_strbuilder_append_str( result, txt("class ") );

	if ( self->Attributes )
	{
		gen_strbuilder_append_fmt( result, "%SB ", gen_attributes_to_strbuilder(self->Attributes) );
	}

	if ( self->Name.Len )
		gen_strbuilder_append_str( result, self->Name );

	if (self->Specs && gen_specifiers_has(self->Specs, Spec_Final))
		gen_strbuilder_append_str(result, txt(" final"));

	if ( self->ParentType )
	{
		gen_Str access_level = gen_access_spec_to_str( self->ParentAccess );
		gen_strbuilder_append_fmt( result, " : %S %SB", self->Name, access_level, gen_typename_to_strbuilder(self->ParentType) );

		gen_CodeTypename interface = gen_cast(gen_CodeTypename, self->ParentType->Next);
		if ( interface )
			gen_strbuilder_append_str( result, txt("\n") );

		while ( interface )
		{
			gen_strbuilder_append_fmt( result, ", public %SB", gen_typename_to_strbuilder(interface) );
			interface = interface->Next ? gen_cast(gen_CodeTypename, interface->Next) : gen_NullCode;
		}
	}

	if ( self->InlineCmt )
	{
		gen_strbuilder_append_fmt( result, " // %S", self->InlineCmt->Content );
	}

	gen_strbuilder_append_fmt( result, "\n{\n%SB\n}", gen_body_to_strbuilder(self->Body) );

	if ( self->Parent == gen_nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
		gen_strbuilder_append_str( result, txt(";\n") );
}

void gen_class_to_strbuilder_fwd( gen_CodeClass self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);

	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes )
		gen_strbuilder_append_fmt( result, "class %SB %S", gen_attributes_to_strbuilder(self->Attributes), self->Name );

	else gen_strbuilder_append_fmt( result, "class %S", self->Name );

	// Check if it can have an end-statement
	if ( self->Parent == gen_nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
	{
		if ( self->InlineCmt )
			gen_strbuilder_append_fmt( result, "; // %S\n", self->InlineCmt->Content );
		else
			gen_strbuilder_append_str( result, txt(";\n") );
	}
}

void gen_define_to_strbuilder_ref(gen_CodeDefine define, gen_StrBuilder* result )
{
	GEN_ASSERT(define);
	GEN_ASSERT(define->Body);
	GEN_ASSERT(define->Body->Content.Ptr && define->Body->Content.Len > 0);
	if (define->Params) {
		gen_StrBuilder gen_params_builder = gen_define_params_to_strbuilder(define->Params);
		gen_strbuilder_append_fmt( result, "#define %S(%S) %S", define->Name, gen_strbuilder_to_str(gen_params_builder), define->Body->Content );
	}
	else {
		gen_strbuilder_append_fmt( result, "#define %S %S", define->Name, define->Body->Content );
	}
}

void gen_define_params_to_strbuilder_ref(gen_CodeDefineParams self, gen_StrBuilder* result)
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( self->Name.Ptr && self->Name.Len )
	{
		gen_strbuilder_append_fmt( result, " %S", self->Name );
	}
	if ( self->NumEntries - 1 > 0 )
	{
		for ( gen_CodeDefineParams param = gen_begin_CodeDefineParams(self->Next); param != gen_end_CodeDefineParams(self->Next); param = gen_next_CodeDefineParams(self->Next, param) )
		{
			gen_strbuilder_append_fmt( result, ", %SB", gen_define_params_to_strbuilder(param) );
		}
	}
}

gen_StrBuilder gen_destructor__to_strbuilder(gen_CodeDestructor self)
{
	GEN_ASSERT(self);
	gen_StrBuilder result = gen_strbuilder_make_reserve( gen__ctx->Allocator_Temp, 128 );
	switch ( self->Type )
	{
		case CT_Destructor:
			gen_destructor__to_strbuilder_def( self, & result );
		break;
		case CT_Destructor_Fwd:
			gen_destructor__to_strbuilder_fwd( self, & result );
		break;
	}
	return result;
}

void gen_destructor__to_strbuilder_def(gen_CodeDestructor self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( self->Name.Len )
	{
		gen_strbuilder_append_fmt( result, "%S()", self->Name );
	}
	else if ( self->Specs )
	{
		if ( gen_specifiers_has(self->Specs, Spec_Virtual ) )
			gen_strbuilder_append_fmt( result, "virtual ~%S()", self->Parent->Name );
		else
			gen_strbuilder_append_fmt( result, "~%S()", self->Parent->Name );
	}
	else
		gen_strbuilder_append_fmt( result, "~%S()", self->Parent->Name );

	gen_strbuilder_append_fmt( result, "\n{\n%SB\n}\n", gen_code_to_strbuilder(self->Body) );
}

void gen_destructor__to_strbuilder_fwd(gen_CodeDestructor self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( self->Specs )
	{
		if ( gen_specifiers_has(self->Specs, Spec_Virtual ) )
			gen_strbuilder_append_fmt( result, "virtual ~%S();\n", self->Parent->Name );
		else
			gen_strbuilder_append_fmt( result, "~%S()", self->Parent->Name );

		if ( gen_specifiers_has(self->Specs, Spec_Pure ) )
			gen_strbuilder_append_str( result, txt(" = 0;") );
		else if (self->Body)
			gen_strbuilder_append_fmt( result, " = %SB;", gen_code_to_strbuilder(self->Body) );
	}
	else
		gen_strbuilder_append_fmt( result, "~%S();", self->Parent->Name );

	if ( self->InlineCmt )
		gen_strbuilder_append_fmt( result, "  %S", self->InlineCmt->Content );
	else
		gen_strbuilder_append_str( result, txt("\n"));
}

gen_StrBuilder gen_enum_to_strbuilder(gen_CodeEnum self)
{
	GEN_ASSERT(self);
	gen_StrBuilder result = gen_strbuilder_make_reserve( gen__ctx->Allocator_Temp, 512 );
	switch ( self->Type )
	{
		case CT_Enum:
			gen_enum_to_strbuilder_def(self, & result );
		break;
		case CT_Enum_Fwd:
			gen_enum_to_strbuilder_fwd(self, & result );
		break;
		case CT_Enum_Class:
			gen_enum_to_strbuilder_class_def(self, & result );
		break;
		case CT_Enum_Class_Fwd:
			gen_enum_to_strbuilder_class_fwd(self, & result );
		break;
	}
	return result;
}

void gen_enum_to_strbuilder_def(gen_CodeEnum self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes || self->UnderlyingType || self->UnderlyingTypeMacro )
	{
		gen_strbuilder_append_str( result, txt("enum ") );

		if ( self->Attributes )
			gen_strbuilder_append_fmt( result, "%SB ", gen_attributes_to_strbuilder(self->Attributes) );

		if ( self->UnderlyingType )
			gen_strbuilder_append_fmt( result, "%S : %SB\n{\n%SB\n}"
				, self->Name
				, gen_typename_to_strbuilder(self->UnderlyingType)
				, gen_body_to_strbuilder(self->Body)
			);
		else if ( self->UnderlyingTypeMacro )
			gen_strbuilder_append_fmt( result, "%S %SB\n{\n%SB\n}"
				, self->Name
				, gen_code_to_strbuilder(self->UnderlyingTypeMacro)
				, gen_body_to_strbuilder(self->Body)
			);

		else gen_strbuilder_append_fmt( result, "%S\n{\n%SB\n}", self->Name, gen_body_to_strbuilder(self->Body) );
	}
	else gen_strbuilder_append_fmt( result, "enum %S\n{\n%SB\n}", self->Name, gen_body_to_strbuilder(self->Body) );

	if ( self->Parent == gen_nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
		gen_strbuilder_append_str( result, txt(";\n"));
}

void gen_enum_to_strbuilder_fwd(gen_CodeEnum self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes )
		gen_strbuilder_append_fmt( result, "%SB ", gen_attributes_to_strbuilder(self->Attributes) );

	if ( self->UnderlyingType )
		gen_strbuilder_append_fmt( result, "enum %S : %SB", self->Name, gen_typename_to_strbuilder(self->UnderlyingType) );
	else if (self->UnderlyingTypeMacro)
	{
		gen_log_fmt("IDENTIFIED A UNDERLYING ENUM MACRO");
		gen_strbuilder_append_fmt( result, "enum %S %SB", self->Name, gen_code_to_strbuilder(self->UnderlyingTypeMacro) );
	}
	else
		gen_strbuilder_append_fmt( result, "enum %S", self->Name );

	if ( self->Parent == gen_nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
	{
		if ( self->InlineCmt )
			gen_strbuilder_append_fmt( result, ";  %S", self->InlineCmt->Content );
		else
			gen_strbuilder_append_str( result, txt(";\n"));
	}
}

void gen_enum_to_strbuilder_class_def(gen_CodeEnum self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes || self->UnderlyingType )
	{
		gen_strbuilder_append_str( result, txt("enum class ") );

		if ( self->Attributes )
		{
			gen_strbuilder_append_fmt( result, "%SB ", gen_attributes_to_strbuilder(self->Attributes) );
		}

		if ( self->UnderlyingType )
		{
			gen_strbuilder_append_fmt( result, "%S : %SB\n{\n%SB\n}", self->Name, gen_typename_to_strbuilder(self->UnderlyingType), gen_body_to_strbuilder(self->Body) );
		}
		else
		{
			gen_strbuilder_append_fmt( result, "%S\n{\n%SB\n}", self->Name, gen_body_to_strbuilder(self->Body) );
		}
	}
	else
	{
		gen_strbuilder_append_fmt( result, "enum %S\n{\n%SB\n}", self->Name, gen_body_to_strbuilder(self->Body) );
	}

	if ( self->Parent == gen_nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
		gen_strbuilder_append_str( result, txt(";\n"));
}

void gen_enum_to_strbuilder_class_fwd(gen_CodeEnum self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	gen_strbuilder_append_str( result, txt("enum class ") );

	if ( self->Attributes )
		gen_strbuilder_append_fmt( result, "%SB ", gen_attributes_to_strbuilder(self->Attributes) );

	gen_strbuilder_append_fmt( result, "%S : %SB", self->Name, gen_typename_to_strbuilder(self->UnderlyingType) );

	if ( self->Parent == gen_nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
	{
		if ( self->InlineCmt )
			gen_strbuilder_append_fmt( result, ";  %S", self->InlineCmt->Content );
		else
			gen_strbuilder_append_str( result, txt(";\n"));
	}
}

gen_StrBuilder gen_fn_to_strbuilder(gen_CodeFn self)
{
	GEN_ASSERT(self);
	gen_StrBuilder result = gen_strbuilder_make_reserve( gen__ctx->Allocator_Temp, 512 );
	switch ( self->Type )
	{
		case CT_Function:
			gen_fn_to_strbuilder_def(self, & result );
		break;
		case CT_Function_Fwd:
			gen_fn_to_strbuilder_fwd(self, & result );
		break;
	}
	return result;
}

void gen_fn_to_strbuilder_def(gen_CodeFn self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export") );

	if ( self->Attributes )
		gen_strbuilder_append_fmt( result, " %SB ", gen_attributes_to_strbuilder(self->Attributes) );

	bool prefix_specs = false;
	if ( self->Specs )
	{
		for ( gen_Specifier* spec = gen_begin_CodeSpecifiers(self->Specs); spec != gen_end_CodeSpecifiers(self->Specs); spec = gen_next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( ! gen_spec_is_trailing( * spec ) )
			{
				gen_Str gen_spec_str = gen_spec_to_str( * spec );
				gen_strbuilder_append_fmt( result, " %.*s", gen_spec_str.Len, gen_spec_str.Ptr );

				prefix_specs = true;
			}
		}
	}

	if ( self->Attributes || prefix_specs )
		gen_strbuilder_append_str( result, txt("\n") );

	if ( self->ReturnType )
		gen_strbuilder_append_fmt( result, "%SB %S(", gen_typename_to_strbuilder(self->ReturnType), self->Name );

	else
		gen_strbuilder_append_fmt( result, "%S(", self->Name );

	if ( self->Params )
		gen_strbuilder_append_fmt( result, "%SB)", gen_params_to_strbuilder(self->Params) );

	else
		gen_strbuilder_append_str( result, txt(")") );

	if ( self->Specs )
	{
		for ( gen_Specifier* spec = gen_begin_CodeSpecifiers(self->Specs); spec != gen_end_CodeSpecifiers(self->Specs); spec = gen_next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( gen_spec_is_trailing( * spec ) )
			{
				gen_Str gen_spec_str = gen_spec_to_str( * spec );
				gen_strbuilder_append_fmt( result, " %.*s", gen_spec_str.Len, gen_spec_str.Ptr );
			}
		}
	}

	// This is bodged in for now SOLEY for Unreal's PURE_VIRTUAL functional macro
	if ( self->SuffixSpecs )
		gen_strbuilder_append_fmt( result, " %SB", gen_code_to_strbuilder(self->SuffixSpecs) );

	gen_strbuilder_append_fmt( result, "\n{\n%SB\n}\n", gen_body_to_strbuilder(self->Body) );
}

void gen_fn_to_strbuilder_fwd(gen_CodeFn self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes )
		gen_strbuilder_append_fmt( result, "%SB ", gen_attributes_to_strbuilder(self->Attributes) );

	gen_b32 prefix_specs = false;
	if ( self->Specs )
	{
		for ( gen_Specifier* spec = gen_begin_CodeSpecifiers(self->Specs); spec != gen_end_CodeSpecifiers(self->Specs); spec = gen_next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( ! gen_spec_is_trailing( * spec ) || ! ( * spec != Spec_Pure) )
			{
				gen_Str gen_spec_str = gen_spec_to_str( * spec );
				gen_strbuilder_append_fmt( result, " %.*s", gen_spec_str.Len, gen_spec_str.Ptr );

				prefix_specs = true;
			}
		}
	}

	if ( self->Attributes || prefix_specs )
	{
		gen_strbuilder_append_str( result, txt("\n") );
	}

	if ( self->ReturnType )
		gen_strbuilder_append_fmt( result, "%SB %S(", gen_typename_to_strbuilder(self->ReturnType), self->Name );

	else
		gen_strbuilder_append_fmt( result, "%S(", self->Name );

	if ( self->Params )
		gen_strbuilder_append_fmt( result, "%SB)", gen_params_to_strbuilder(self->Params) );

	else
		gen_strbuilder_append_str( result, txt(")") );

	if ( self->Specs )
	{
		for ( gen_Specifier* spec = gen_begin_CodeSpecifiers(self->Specs); spec != gen_end_CodeSpecifiers(self->Specs); spec = gen_next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( gen_spec_is_trailing( * spec ) )
			{
				gen_Str gen_spec_str = gen_spec_to_str( * spec );
				gen_strbuilder_append_fmt( result, " %.*s", gen_spec_str.Len, gen_spec_str.Ptr );
			}
		}

		if ( gen_specifiers_has(self->Specs, Spec_Pure ) )
			gen_strbuilder_append_str( result, txt(" = 0") );
		else if ( gen_specifiers_has(self->Specs, Spec_Delete ) )
			gen_strbuilder_append_str( result, txt(" = delete") );
	}

	// This is bodged in for now SOLEY for Unreal's PURE_VIRTUAL functional macro (I kept it open ended for other jank)
	if ( self->SuffixSpecs )
		gen_strbuilder_append_fmt( result, " %SB", gen_code_to_strbuilder(self->SuffixSpecs) );

	if (self->Body)
		gen_strbuilder_append_fmt( result, " = %SB;", gen_body_to_strbuilder(self->Body) );

	if ( self->InlineCmt )
		gen_strbuilder_append_fmt( result, ";  %S", self->InlineCmt->Content );
	else
		gen_strbuilder_append_str( result, txt(";\n") );
}

void gen_module_to_strbuilder_ref(gen_CodeModule self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if (((gen_scast(gen_u32, ModuleFlag_Export) & gen_scast(gen_u32, self->ModuleFlags)) == gen_scast(gen_u32, ModuleFlag_Export)))
		gen_strbuilder_append_str( result, txt("export "));

	if (((gen_scast(gen_u32, ModuleFlag_Import) & gen_scast(gen_u32, self->ModuleFlags)) == gen_scast(gen_u32, ModuleFlag_Import)))
		gen_strbuilder_append_str( result, txt("import "));

	gen_strbuilder_append_fmt( result, "%S;\n", self->Name );
}

gen_StrBuilder gen_code_op_to_strbuilder(gen_CodeOperator self)
{
	GEN_ASSERT(self);
	gen_StrBuilder result = gen_strbuilder_make_reserve( gen__ctx->Allocator_Temp, 512 );
	switch ( self->Type )
	{
		case CT_Operator:
		case CT_Operator_Member:
			gen_code_op_to_strbuilder_def( self, & result );
		break;
		case CT_Operator_Fwd:
		case CT_Operator_Member_Fwd:
			gen_code_op_to_strbuilder_fwd( self, & result );
		break;
	}
	return result;
}

void gen_code_op_to_strbuilder_def(gen_CodeOperator self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes )
		gen_strbuilder_append_fmt( result, "%SB ", gen_attributes_to_strbuilder(self->Attributes) );

	if ( self->Attributes )
		gen_strbuilder_append_fmt( result, "%SB ", gen_attributes_to_strbuilder(self->Attributes) );

	if ( self->Specs )
	{
		for ( gen_Specifier* spec = gen_begin_CodeSpecifiers(self->Specs); spec != gen_end_CodeSpecifiers(self->Specs); spec = gen_next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( ! gen_spec_is_trailing( * spec ) )
			{
				gen_Str gen_spec_str = gen_spec_to_str( * spec );
				gen_strbuilder_append_fmt( result, " %.*s", gen_spec_str.Len, gen_spec_str.Ptr );
			}
		}
	}

	if ( self->Attributes || self->Specs )
	{
		gen_strbuilder_append_str( result, txt("\n") );
	}

	if ( self->ReturnType )
		gen_strbuilder_append_fmt( result, "%SB %S (", gen_typename_to_strbuilder(self->ReturnType), self->Name );

	if ( self->Params )
		gen_strbuilder_append_fmt( result, "%SB)", gen_params_to_strbuilder(self->Params) );

	else
		gen_strbuilder_append_str( result, txt(")") );

	if ( self->Specs )
	{
		for ( gen_Specifier* spec = gen_begin_CodeSpecifiers(self->Specs); spec != gen_end_CodeSpecifiers(self->Specs); spec = gen_next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( gen_spec_is_trailing( * spec ) )
			{
				gen_Str gen_spec_str = gen_spec_to_str( * spec );
				gen_strbuilder_append_fmt( result, " %.*s", gen_spec_str.Len, gen_spec_str.Ptr );
			}
		}
	}

	gen_strbuilder_append_fmt( result, "\n{\n%SB\n}\n"
		, gen_body_to_strbuilder(self->Body)
	);
}

void gen_code_op_to_strbuilder_fwd(gen_CodeOperator self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes )
		gen_strbuilder_append_fmt( result, "%SB\n", gen_attributes_to_strbuilder(self->Attributes) );

	if ( self->Specs )
	{
		for ( gen_Specifier* spec = gen_begin_CodeSpecifiers(self->Specs); spec != gen_end_CodeSpecifiers(self->Specs); spec = gen_next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( ! gen_spec_is_trailing( * spec ) )
			{
				gen_Str gen_spec_str = gen_spec_to_str( * spec );
				gen_strbuilder_append_fmt( result, " %.*s", gen_spec_str.Len, gen_spec_str.Ptr );
			}
		}
	}

	if ( self->Attributes || self->Specs )
	{
		gen_strbuilder_append_str( result, txt("\n") );
	}

	gen_strbuilder_append_fmt( result, "%SB %S (", gen_typename_to_strbuilder(self->ReturnType), self->Name );

	if ( self->Params )
		gen_strbuilder_append_fmt( result, "%SB)", gen_params_to_strbuilder(self->Params) );

	else
		gen_strbuilder_append_fmt( result, ")" );

	if ( self->Specs )
	{
		for ( gen_Specifier* spec = gen_begin_CodeSpecifiers(self->Specs); spec != gen_end_CodeSpecifiers(self->Specs); spec = gen_next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( gen_spec_is_trailing( * spec ) )
			{
				gen_Str gen_spec_str = gen_spec_to_str( * spec );
				gen_strbuilder_append_fmt( result, " %.*s", gen_spec_str.Len, gen_spec_str.Ptr );
			}
		}
	}

	if ( self->InlineCmt )
		gen_strbuilder_append_fmt( result, ";  %S", self->InlineCmt->Content );
	else
		gen_strbuilder_append_str( result, txt(";\n") );
}

gen_StrBuilder gen_opcast_to_strbuilder(gen_CodeOpCast self)
{
	GEN_ASSERT(self);
	gen_StrBuilder result = gen_strbuilder_make_reserve( gen__ctx->Allocator_Temp, 128 );
	switch ( self->Type )
	{
		case CT_Operator_Cast:
			gen_opcast_to_strbuilder_def(self, & result );
		break;
		case CT_Operator_Cast_Fwd:
			gen_opcast_to_strbuilder_fwd(self, & result );
		break;
	}
	return result;
}

void gen_opcast_to_strbuilder_def(gen_CodeOpCast self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( self->Specs )
	{
		for ( gen_Specifier* spec = gen_begin_CodeSpecifiers(self->Specs); spec != gen_end_CodeSpecifiers(self->Specs); spec = gen_next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( ! gen_spec_is_trailing( * spec ) )
			{
				gen_Str gen_spec_str = gen_spec_to_str( * spec );
				gen_strbuilder_append_fmt( result, "%*s ", gen_spec_str.Len, gen_spec_str.Ptr );
			}
		}

		if ( self->Name.Ptr && self->Name.Len )
			gen_strbuilder_append_fmt( result, "%S operator %SB()", self->Name, gen_typename_to_strbuilder(self->ValueType) );
		else
			gen_strbuilder_append_fmt( result, "operator %SB()", gen_typename_to_strbuilder(self->ValueType) );

		for ( gen_Specifier* spec = gen_begin_CodeSpecifiers(self->Specs); spec != gen_end_CodeSpecifiers(self->Specs); spec = gen_next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( gen_spec_is_trailing( * spec ) )
			{
				gen_Str gen_spec_str = gen_spec_to_str( * spec );
				gen_strbuilder_append_fmt( result, " %.*s", gen_spec_str.Len, gen_spec_str.Ptr );
			}
		}

		gen_strbuilder_append_fmt( result, "\n{\n%SB\n}\n", gen_body_to_strbuilder(self->Body) );
		return;
	}

	if ( self->Name.Ptr && self->Name.Len )
		gen_strbuilder_append_fmt( result, "%S operator %SB()\n{\n%SB\n}\n", self->Name, gen_typename_to_strbuilder(self->ValueType), gen_body_to_strbuilder(self->Body) );
	else
		gen_strbuilder_append_fmt( result, "operator %SB()\n{\n%SB\n}\n", gen_typename_to_strbuilder(self->ValueType), gen_body_to_strbuilder(self->Body) );
}

void gen_opcast_to_strbuilder_fwd(gen_CodeOpCast self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( self->Specs )
	{
		for ( gen_Specifier* spec = gen_begin_CodeSpecifiers(self->Specs); spec != gen_end_CodeSpecifiers(self->Specs); spec = gen_next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( ! gen_spec_is_trailing( * spec ) )
			{
				gen_Str gen_spec_str = gen_spec_to_str( * spec );
				gen_strbuilder_append_fmt( result, "%*s ", gen_spec_str.Len, gen_spec_str.Ptr );
			}
		}

		gen_strbuilder_append_fmt( result, "operator %SB()", gen_typename_to_strbuilder(self->ValueType) );

		for ( gen_Specifier* spec = gen_begin_CodeSpecifiers(self->Specs); spec != gen_end_CodeSpecifiers(self->Specs); spec = gen_next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( gen_spec_is_trailing( * spec ) )
			{
				gen_Str gen_spec_str = gen_spec_to_str( * spec );
				gen_strbuilder_append_fmt( result, " %*s", gen_spec_str.Len, gen_spec_str.Ptr );
			}
		}

		if ( self->InlineCmt )
			gen_strbuilder_append_fmt( result, ";  %S", self->InlineCmt->Content );
		else
			gen_strbuilder_append_str( result, txt(";\n") );
		return;
	}

	if ( self->InlineCmt )
		gen_strbuilder_append_fmt( result, "operator %SB();  %SB", gen_typename_to_strbuilder(self->ValueType) );
	else
		gen_strbuilder_append_fmt( result, "operator %SB();\n", gen_typename_to_strbuilder(self->ValueType) );
}

void gen_params_to_strbuilder_ref( gen_CodeParams self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( self->gen_Macro )
	{
		// Related to parsing: ( <macro>, ... )
		gen_strbuilder_append_str( result, self->gen_Macro->Content );
		// Could also be: ( <macro> <type <name>, ... )
	}

	if ( self->Name.Ptr && self->Name.Len )
	{
		if ( self->ValueType == gen_nullptr )
			gen_strbuilder_append_fmt( result, " %S", self->Name );
		else
			gen_strbuilder_append_fmt( result, " %SB %S", gen_typename_to_strbuilder(self->ValueType), self->Name );

	}
	else if ( self->ValueType )
		gen_strbuilder_append_fmt( result, " %SB", gen_typename_to_strbuilder(self->ValueType) );

	if ( self->PostNameMacro )
	{
		gen_strbuilder_append_fmt( result, " %SB", gen_code_to_strbuilder(self->PostNameMacro) );
	}

	if ( self->Value )
		gen_strbuilder_append_fmt( result, " = %SB", gen_code_to_strbuilder(self->Value) );

	if ( self->NumEntries - 1 > 0 )
	{
		for ( gen_CodeParams param = gen_begin_CodeParams(self->Next); param != gen_end_CodeParams(self->Next); param = gen_next_CodeParams(self->Next, param) )
		{
			gen_strbuilder_append_fmt( result, ", %SB", gen_params_to_strbuilder(param) );
		}
	}
}

gen_StrBuilder gen_preprocess_to_strbuilder(gen_CodePreprocessCond self)
{
	GEN_ASSERT(self);
	gen_StrBuilder result = gen_strbuilder_make_reserve( gen__ctx->Allocator_Temp, 256 );
	switch ( self->Type )
	{
		case CT_Preprocess_If:
			gen_preprocess_to_strbuilder_if( self, & result );
		break;
		case CT_Preprocess_IfDef:
			gen_preprocess_to_strbuilder_ifdef( self, & result );
		break;
		case CT_Preprocess_IfNotDef:
			gen_preprocess_to_strbuilder_ifndef( self, & result );
		break;
		case CT_Preprocess_ElIf:
			gen_preprocess_to_strbuilder_elif( self, & result );
		break;
		case CT_Preprocess_Else:
			gen_preprocess_to_strbuilder_else( self, & result );
		break;
		case CT_Preprocess_EndIf:
			gen_preprocess_to_strbuilder_endif( self, & result );
		break;
	}
	return result;
}

void gen_specifiers_to_strbuilder_ref( gen_CodeSpecifiers self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	gen_s32 idx  = 0;
	gen_s32 left = self->NumEntries;
	while ( left -- )
	{
		gen_Specifier spec     = self->ArrSpecs[idx];
		gen_Str       gen_spec_str = gen_spec_to_str( spec );
		if ( idx > 0 ) switch (spec) {
			case Spec_Ptr:
			case Spec_Ref:
			case Spec_RValue:
			break;

			default:
				gen_strbuilder_append_str(result, txt(" "));
			break;
		}
		gen_strbuilder_append_fmt( result, "%S", gen_spec_str );
		idx++;
	}
	gen_strbuilder_append_str(result, txt(" "));
}

gen_StrBuilder gen_struct_to_strbuilder(gen_CodeStruct self)
{
	GEN_ASSERT(self);
	GEN_ASSERT(self);
	gen_StrBuilder result = gen_strbuilder_make_reserve( gen__ctx->Allocator_Temp, 512 );
	switch ( self->Type )
	{
		case CT_Struct:
			gen_struct_to_strbuilder_def( self, & result );
		break;
		case CT_Struct_Fwd:
			gen_struct_to_strbuilder_fwd( self, & result );
		break;
	}
	return result;
}

void gen_struct_to_strbuilder_def( gen_CodeStruct self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	gen_strbuilder_append_str( result, txt("struct ") );

	if ( self->Attributes )
	{
		gen_strbuilder_append_fmt( result, "%SB ", gen_attributes_to_strbuilder(self->Attributes) );
	}

	if ( self->Name.Len )
		gen_strbuilder_append_str( result, self->Name );

	if (self->Specs && gen_specifiers_has(self->Specs, Spec_Final))
		gen_strbuilder_append_str( result, txt(" final"));

	if ( self->ParentType )
	{
		gen_Str access_level = gen_access_spec_to_str( self->ParentAccess );

		gen_strbuilder_append_fmt( result, " : %S %SB", access_level, gen_typename_to_strbuilder(self->ParentType) );

		gen_CodeTypename interface = gen_cast(gen_CodeTypename, self->ParentType->Next);
		if ( interface )
			gen_strbuilder_append_str( result, txt("\n") );

		while ( interface )
		{
			gen_strbuilder_append_fmt( result, ", %SB", gen_typename_to_strbuilder(interface) );
			interface = interface->Next ? gen_cast( gen_CodeTypename, interface->Next) : gen_NullCode;
		}
	}

	if ( self->InlineCmt )
	{
		gen_strbuilder_append_fmt( result, " // %S", self->InlineCmt->Content );
	}

	gen_strbuilder_append_fmt( result, "\n{\n%SB\n}", gen_body_to_strbuilder(self->Body) );

	if ( self->Parent == gen_nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
		gen_strbuilder_append_str( result, txt(";\n"));
}

void gen_struct_to_strbuilder_fwd( gen_CodeStruct self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes )
		gen_strbuilder_append_fmt( result, "struct %SB %S", gen_attributes_to_strbuilder(self->Attributes), self->Name );

	else gen_strbuilder_append_fmt( result, "struct %S", self->Name );

	if ( self->Parent == gen_nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
	{
		if ( self->InlineCmt )
			gen_strbuilder_append_fmt( result, ";  %S", self->InlineCmt->Content );
		else
			gen_strbuilder_append_str( result, txt( ";\n") );
	}
}

void gen_template_to_strbuilder_ref(gen_CodeTemplate self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	if ( self->Params )
		gen_strbuilder_append_fmt( result, "template< %SB >\n%SB", gen_params_to_strbuilder(self->Params), gen_code_to_strbuilder(self->Declaration) );
	else
		gen_strbuilder_append_fmt( result, "template<>\n%SB", gen_code_to_strbuilder(self->Declaration) );
}

void gen_typedef_to_strbuilder_ref(gen_CodeTypedef self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	gen_strbuilder_append_str( result, txt("typedef "));

	// Determines if the typedef is a function typename
	if ( self->UnderlyingType->ReturnType )
		gen_strbuilder_append_string( result, gen_code_to_strbuilder(self->UnderlyingType) );
	else
		gen_strbuilder_append_fmt( result, "%SB %S", gen_code_to_strbuilder(self->UnderlyingType), self->Name );

	if ( self->UnderlyingType->Type == CT_Typename && self->UnderlyingType->ArrExpr )
	{
		gen_strbuilder_append_fmt( result, "[ %SB ];", gen_code_to_strbuilder(self->UnderlyingType->ArrExpr) );

		gen_Code gen_next_arr_expr = self->UnderlyingType->ArrExpr->Next;
		while ( gen_next_arr_expr )
		{
			gen_strbuilder_append_fmt( result, "[ %SB ];", gen_code_to_strbuilder(gen_next_arr_expr) );
			gen_next_arr_expr = gen_next_arr_expr->Next;
		}
	}
	else
	{
		gen_strbuilder_append_str( result, txt(";") );
	}

	if ( self->InlineCmt )
		gen_strbuilder_append_fmt( result, "  %S", self->InlineCmt->Content);
	else
		gen_strbuilder_append_str( result, txt("\n"));
}

void gen_typename_to_strbuilder_ref(gen_CodeTypename self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	#if defined(GEN_USE_NEW_TYPENAME_PARSING)
		if ( self->ReturnType && self->Params )
		{
			if ( self->Attributes )
				gen_strbuilder_append_fmt( result, "%SB ", gen_attributes_to_strbuilder(self->Attributes) );
			else
			{
				if ( self->Specs )
					gen_strbuilder_append_fmt( result, "%SB ( %S ) ( %SB ) %SB", gen_typename_to_strbuilder(self->ReturnType), self->Name, gen_params_to_strbuilder(self->Params), gen_specifiers_to_strbuilder(self->Specs) );
				else
					gen_strbuilder_append_fmt( result, "%SB ( %S ) ( %SB )", gen_typename_to_strbuilder(self->ReturnType), self->Name, gen_params_to_strbuilder(self->Params) );
			}

			break;
		}
	#else
		if ( self->ReturnType && self->Params )
		{
			if ( self->Attributes )
				gen_strbuilder_append_fmt( result, "%SB ", gen_attributes_to_strbuilder(self->Attributes) );
			else
			{
				if ( self->Specs )
					gen_strbuilder_append_fmt( result, "%SB %S ( %SB ) %SB", gen_typename_to_strbuilder(self->ReturnType), self->Name, gen_params_to_strbuilder(self->Params), gen_specifiers_to_strbuilder(self->Specs) );
				else
					gen_strbuilder_append_fmt( result, "%SB %S ( %SB )", gen_typename_to_strbuilder(self->ReturnType), self->Name, gen_params_to_strbuilder(self->Params) );
			}

			return;
		}
	#endif

	if ( self->Attributes )
		gen_strbuilder_append_fmt( result, "%SB ", gen_attributes_to_strbuilder(self->Attributes) );

	switch ( self->TypeTag )
	{
		case Tag_Class  : gen_strbuilder_append_str( result, txt("class "));  break;
		case Tag_Enum   : gen_strbuilder_append_str( result, txt("enum "));   break;
		case Tag_Struct : gen_strbuilder_append_str( result, txt("struct ")); break;
		case Tag_Union  : gen_strbuilder_append_str( result, txt("union "));  break;
		default:
			break;
	}

	if ( self->Specs )
		gen_strbuilder_append_fmt( result, "%S %SB", self->Name, gen_specifiers_to_strbuilder(self->Specs) );
	else
		gen_strbuilder_append_fmt( result, "%S", self->Name );

	if ( self->IsParamPack )
		gen_strbuilder_append_str( result, txt("..."));
}

gen_StrBuilder union_to_strbuilder(gen_CodeUnion self)
{
	GEN_ASSERT(self);
	gen_StrBuilder result = gen_strbuilder_make_reserve( gen__ctx->Allocator_Temp, 512 );
	switch ( self->Type )
	{
		case CT_Union:
			union_to_strbuilder_def( self, & result );
		break;
		case CT_Union_Fwd:
			union_to_strbuilder_fwd( self, & result );
		break;
	}
	return result;
}

void union_to_strbuilder_def(gen_CodeUnion self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	gen_strbuilder_append_str( result, txt("union ") );

	if ( self->Attributes )
		gen_strbuilder_append_fmt( result, "%SB ", gen_attributes_to_strbuilder(self->Attributes) );

	if ( self->Name.Len )
	{
		gen_strbuilder_append_fmt( result, "%S\n{\n%SB\n}"
			, self->Name
			, gen_body_to_strbuilder(self->Body)
		);
	}
	else
	{
		// Anonymous union
		gen_strbuilder_append_fmt( result, "\n{\n%SB\n}"
			, gen_body_to_strbuilder(self->Body)
		);
	}

	if ( self->Parent == gen_nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
		gen_strbuilder_append_str( result, txt(";\n"));
}

void union_to_strbuilder_fwd(gen_CodeUnion self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	gen_strbuilder_append_str( result, txt("union ") );

	if ( self->Attributes )
		gen_strbuilder_append_fmt( result, "%SB ", gen_attributes_to_strbuilder(self->Attributes) );

	if ( self->Name.Len )
	{
		gen_strbuilder_append_fmt( result, "%S", self->Name);
	}

	if ( self->Parent == gen_nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
		gen_strbuilder_append_str( result, txt(";\n"));
}

void gen_using_to_strbuilder_ref(gen_CodeUsing self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes )
		gen_strbuilder_append_fmt( result, "%SB ", gen_attributes_to_strbuilder(self->Attributes) );

	if ( self->UnderlyingType )
	{
		gen_strbuilder_append_fmt( result, "using %S = %SB", self->Name, gen_typename_to_strbuilder(self->UnderlyingType) );

		if ( self->UnderlyingType->ArrExpr )
		{
			gen_strbuilder_append_fmt( result, "[ %SB ]", gen_code_to_strbuilder(self->UnderlyingType->ArrExpr) );

			gen_Code gen_next_arr_expr = self->UnderlyingType->ArrExpr->Next;
			while ( gen_next_arr_expr )
			{
				gen_strbuilder_append_fmt( result, "[ %SB ]", gen_code_to_strbuilder(gen_next_arr_expr) );
				gen_next_arr_expr = gen_next_arr_expr->Next;
			}
		}

		gen_strbuilder_append_str( result, txt(";") );
	}
	else
		gen_strbuilder_append_fmt( result, "using %S;", self->Name );

	if ( self->InlineCmt )
		gen_strbuilder_append_fmt( result, "  %S\n", self->InlineCmt->Content );
	else
		gen_strbuilder_append_str( result, txt("\n"));
}

gen_neverinline
void gen_var_to_strbuilder_ref(gen_CodeVar self, gen_StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( self->Parent && self->Parent->Type == CT_Variable )
	{
		// Its a comma-separated variable ( a NextVar )

		if ( self->Specs )
			gen_strbuilder_append_fmt( result, "%SB ", gen_specifiers_to_strbuilder(self->Specs) );

		gen_strbuilder_append_str( result, self->Name );

		if ( self->ValueType && self->ValueType->ArrExpr )
		{
			gen_strbuilder_append_fmt( result, "[ %SB ]", gen_code_to_strbuilder(self->ValueType->ArrExpr) );

			gen_Code gen_next_arr_expr = self->ValueType->ArrExpr->Next;
			while ( gen_next_arr_expr )
			{
				gen_strbuilder_append_fmt( result, "[ %SB ]", gen_code_to_strbuilder(gen_next_arr_expr) );
				gen_next_arr_expr = gen_next_arr_expr->Next;
			}
		}

		if ( self->Value )
		{
			if ( self->VarParenthesizedInit )
				gen_strbuilder_append_fmt( result, "( %SB ", gen_code_to_strbuilder(self->Value) );
			else
				gen_strbuilder_append_fmt( result, " = %SB", gen_code_to_strbuilder(self->Value) );
		}

		// Keep the chain going...
		if ( self->NextVar )
			gen_strbuilder_append_fmt( result, ", %SB", gen_var_to_strbuilder(self->NextVar) );

		if ( self->VarParenthesizedInit )
			gen_strbuilder_append_str( result, txt(" )"));

		return;
	}

	if ( gen_bitfield_is_set( gen_u32, self->ModuleFlags, ModuleFlag_Export ))
		gen_strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes || self->Specs )
	{
		if ( self->Attributes )
			gen_strbuilder_append_fmt( result, "%SB ", gen_attributes_to_strbuilder(self->Attributes) );

		if ( self->Specs )
			gen_strbuilder_append_fmt( result, "%SB", gen_specifiers_to_strbuilder(self->Specs) );

		gen_strbuilder_append_fmt( result, "%SB %S", gen_typename_to_strbuilder(self->ValueType), self->Name );

		if ( self->ValueType && self->ValueType->ArrExpr )
		{
			gen_strbuilder_append_fmt( result, "[ %SB ]", gen_code_to_strbuilder(self->ValueType->ArrExpr) );

			gen_Code gen_next_arr_expr = self->ValueType->ArrExpr->Next;
			while ( gen_next_arr_expr )
			{
				gen_strbuilder_append_fmt( result, "[ %SB ]", gen_code_to_strbuilder(gen_next_arr_expr) );
				gen_next_arr_expr = gen_next_arr_expr->Next;
			}
		}

		if ( self->BitfieldSize )
			gen_strbuilder_append_fmt( result, " : %SB", gen_code_to_strbuilder(self->BitfieldSize) );

		if ( self->Value )
		{
			if ( self->VarParenthesizedInit )
				gen_strbuilder_append_fmt( result, "( %SB ", gen_code_to_strbuilder(self->Value) );
			else
				gen_strbuilder_append_fmt( result, " = %SB", gen_code_to_strbuilder(self->Value) );
		}

		if ( self->NextVar )
			gen_strbuilder_append_fmt( result, ", %SB", gen_var_to_strbuilder(self->NextVar) );

		if ( self->VarParenthesizedInit )
			gen_strbuilder_append_str( result, txt(" )"));

		if ( self->InlineCmt )
			gen_strbuilder_append_fmt( result, ";  %S", self->InlineCmt->Content);
		else
			gen_strbuilder_append_str( result, txt(";\n") );

		return;
	}

	if ( self->BitfieldSize )
		gen_strbuilder_append_fmt( result, "%SB %S : %SB", gen_typename_to_strbuilder(self->ValueType), self->Name, gen_code_to_strbuilder(self->BitfieldSize) );

	else if ( self->ValueType && self->ValueType->ArrExpr )
	{
		gen_strbuilder_append_fmt( result, "%SB %S[ %SB ]", gen_typename_to_strbuilder(self->ValueType), self->Name, gen_code_to_strbuilder(self->ValueType->ArrExpr) );

		gen_Code gen_next_arr_expr = self->ValueType->ArrExpr->Next;
		while ( gen_next_arr_expr )
		{
			gen_strbuilder_append_fmt( result, "[ %SB ]", gen_code_to_strbuilder(gen_next_arr_expr) );
			gen_next_arr_expr = gen_next_arr_expr->Next;
		}
	}

	else
		gen_strbuilder_append_fmt( result, "%SB %S", gen_typename_to_strbuilder(self->ValueType), self->Name );

	if ( self->Value )
	{
		if ( self->VarParenthesizedInit )
			gen_strbuilder_append_fmt( result, "( %SB ", gen_code_to_strbuilder(self->Value) );
		else
			gen_strbuilder_append_fmt( result, " = %SB", gen_code_to_strbuilder(self->Value) );
	}

	if ( self->NextVar )
		gen_strbuilder_append_fmt( result, ", %SB", gen_var_to_strbuilder( self->NextVar) );

	if ( self->VarParenthesizedInit )
		gen_strbuilder_append_str( result, txt(" )"));

	gen_strbuilder_append_str( result, txt(";") );

	if ( self->InlineCmt )
		gen_strbuilder_append_fmt( result, "  %S", self->InlineCmt->Content);
	else
		gen_strbuilder_append_str( result, txt("\n"));
}
#pragma endregion AST

#pragma region Interface

gen_internal void gen_parser_init();
gen_internal void gen_parser_deinit();

gen_internal void* gen_Global_Allocator_Proc(
    void*         allocator_data,
    gen_AllocType type,
    gen_ssize     size,
    gen_ssize     alignment,
    void*         old_memory,
    gen_ssize     old_size,
    gen_u64       flags
)
{
	GEN_ASSERT(gen__ctx);
	GEN_ASSERT(gen__ctx->Fallback_AllocatorBuckets);
	gen_Arena* last = gen_array_back(gen__ctx->Fallback_AllocatorBuckets);

	switch (type)
	{
		case EAllocation_ALLOC:
		{
			if ((last->TotalUsed + size) > last->TotalSize)
			{
				gen_Arena bucket = gen_arena_init_from_allocator(gen_heap(), gen__ctx->InitSize_Fallback_Allocator_Bucket_Size);

				if (bucket.PhysicalStart == gen_nullptr)
					GEN_FATAL("Failed to create bucket for Fallback_AllocatorBuckets");

				if (! gen_array_append(gen__ctx->Fallback_AllocatorBuckets, bucket))
					GEN_FATAL("Failed to append bucket to Fallback_AllocatorBuckets");

				last = gen_array_back(gen__ctx->Fallback_AllocatorBuckets);
			}

			return gen_alloc_align(gen_arena_allocator_info(last), size, alignment);
		}
		case EAllocation_FREE:
		{
			// Doesn't recycle.
		}
		break;
		case EAllocation_FREE_ALL:
		{
			// Memory::cleanup instead.
		}
		break;
		case EAllocation_RESIZE:
		{
			if (last->TotalUsed + size > last->TotalSize)
			{
				gen_Arena bucket = gen_arena_init_from_allocator(gen_heap(), gen__ctx->InitSize_Fallback_Allocator_Bucket_Size);

				if (bucket.PhysicalStart == gen_nullptr)
					GEN_FATAL("Failed to create bucket for Fallback_AllocatorBuckets");

				if (! gen_array_append(gen__ctx->Fallback_AllocatorBuckets, bucket))
					GEN_FATAL("Failed to append bucket to Fallback_AllocatorBuckets");

				last = gen_array_back(gen__ctx->Fallback_AllocatorBuckets);
			}

			void* result = gen_alloc_align(last->Backing, size, alignment);

			if (result != gen_nullptr && old_memory != gen_nullptr)
			{
				gen_mem_copy(result, old_memory, old_size);
			}

			return result;
		}
	}

	return gen_nullptr;
}

gen_internal void gen_define_constants()
{
	// We only initalize these if there is no base context.
	if (context_counter > 0)
		return;

	gen_Code_Global          = gen_make_code();
	gen_Code_Global->Name    = gen_cache_str(txt("Global gen_Code"));
	gen_Code_Global->Content = gen_Code_Global->Name;

	gen_Code_Invalid         = gen_make_code();
	gen_code_set_global(gen_Code_Invalid);

	gen_t_empty       = (gen_CodeTypename)gen_make_code();
	gen_t_empty->Type = CT_Typename;
	gen_t_empty->Name = gen_cache_str(txt(""));
	gen_code_set_global(gen_cast(gen_Code, gen_t_empty));

	gen_access_private       = gen_make_code();
	gen_access_private->Type = CT_Access_Private;
	gen_access_private->Name = gen_cache_str(txt("private:\n"));
	gen_code_set_global(gen_cast(gen_Code, gen_access_private));

	gen_access_protected       = gen_make_code();
	gen_access_protected->Type = CT_Access_Protected;
	gen_access_protected->Name = gen_cache_str(txt("protected:\n"));
	gen_code_set_global(gen_access_protected);

	gen_access_public       = gen_make_code();
	gen_access_public->Type = CT_Access_Public;
	gen_access_public->Name = gen_cache_str(txt("public:\n"));
	gen_code_set_global(gen_access_public);

	gen_Str api_export_str = code(GEN_API_Export_Code);
	gen_attrib_api_export  = gen_def_attributes(api_export_str);
	gen_code_set_global(gen_cast(gen_Code, gen_attrib_api_export));

	gen_Str api_import_str = code(GEN_API_Import_Code);
	gen_attrib_api_import  = gen_def_attributes(api_import_str);
	gen_code_set_global(gen_cast(gen_Code, gen_attrib_api_import));

	gen_module_global_fragment          = gen_make_code();
	gen_module_global_fragment->Type    = CT_Untyped;
	gen_module_global_fragment->Name    = gen_cache_str(txt("module;"));
	gen_module_global_fragment->Content = gen_module_global_fragment->Name;
	gen_code_set_global(gen_cast(gen_Code, gen_module_global_fragment));

	gen_module_private_fragment          = gen_make_code();
	gen_module_private_fragment->Type    = CT_Untyped;
	gen_module_private_fragment->Name    = gen_cache_str(txt("module : private;"));
	gen_module_private_fragment->Content = gen_module_private_fragment->Name;
	gen_code_set_global(gen_cast(gen_Code, gen_module_private_fragment));

	gen_fmt_newline       = gen_make_code();
	gen_fmt_newline->Type = CT_NewLine;
	gen_code_set_global((gen_Code)gen_fmt_newline);

	gen_pragma_once          = (gen_CodePragma)gen_make_code();
	gen_pragma_once->Type    = CT_Preprocess_Pragma;
	gen_pragma_once->Name    = gen_cache_str(txt("once"));
	gen_pragma_once->Content = gen_pragma_once->Name;
	gen_code_set_global((gen_Code)gen_pragma_once);

	gen_param_varadic            = (gen_CodeParams)gen_make_code();
	gen_param_varadic->Type      = CT_Parameters;
	gen_param_varadic->Name      = gen_cache_str(txt("..."));
	gen_param_varadic->ValueType = gen_t_empty;
	gen_code_set_global((gen_Code)gen_param_varadic);

	gen_preprocess_else       = (gen_CodePreprocessCond)gen_make_code();
	gen_preprocess_else->Type = CT_Preprocess_Else;
	gen_code_set_global((gen_Code)gen_preprocess_else);

	gen_preprocess_endif       = (gen_CodePreprocessCond)gen_make_code();
	gen_preprocess_endif->Type = CT_Preprocess_EndIf;
	gen_code_set_global((gen_Code)gen_preprocess_endif);

	gen_Str auto_str = txt("auto");
	gen_t_auto       = gen_def_type(auto_str);
	gen_code_set_global(gen_t_auto);
	gen_Str void_str = txt("void");
	gen_t_void       = gen_def_type(void_str);
	gen_code_set_global(gen_t_void);
	gen_Str int_str = txt("int");
	gen_t_int       = gen_def_type(int_str);
	gen_code_set_global(gen_t_int);
	gen_Str bool_str = txt("bool");
	gen_t_bool       = gen_def_type(bool_str);
	gen_code_set_global(gen_t_bool);
	gen_Str gen_char_str = txt("char");
	gen_t_char           = gen_def_type(gen_char_str);
	gen_code_set_global(gen_t_char);
	gen_Str wchar_str = txt("wchar_t");
	gen_t_wchar_t     = gen_def_type(wchar_str);
	gen_code_set_global(gen_t_wchar_t);
	gen_Str gen_class_str = txt("class");
	gen_t_class           = gen_def_type(gen_class_str);
	gen_code_set_global(gen_t_class);
	gen_Str gen_typename_str = txt("typename");
	gen_t_typename           = gen_def_type(gen_typename_str);
	gen_code_set_global(gen_t_typename);

#ifdef GEN_DEFINE_LIBRARY_CODE_CONSTANTS
	gen_t_b32 = gen_def_type(name(gen_b32));
	gen_code_set_global(gen_t_b32);

	gen_Str s8_str = txt("gen_s8");
	gen_t_s8       = gen_def_type(s8_str);
	gen_code_set_global(gen_t_s8);
	gen_Str s16_str = txt("gen_s16");
	gen_t_s16       = gen_def_type(s16_str);
	gen_code_set_global(gen_t_s16);
	gen_Str s32_str = txt("gen_s32");
	gen_t_s32       = gen_def_type(s32_str);
	gen_code_set_global(gen_t_s32);
	gen_Str s64_str = txt("gen_s64");
	gen_t_s64       = gen_def_type(s64_str);
	gen_code_set_global(gen_t_s64);

	gen_Str u8_str = txt("gen_u8");
	gen_t_u8       = gen_def_type(u8_str);
	gen_code_set_global(gen_t_u8);
	gen_Str u16_str = txt("gen_u16");
	gen_t_u16       = gen_def_type(u16_str);
	gen_code_set_global(gen_t_u16);
	gen_Str u32_str = txt("gen_u32");
	gen_t_u32       = gen_def_type(u32_str);
	gen_code_set_global(gen_t_u32);
	gen_Str u64_str = txt("gen_u64");
	gen_t_u64       = gen_def_type(u64_str);
	gen_code_set_global(gen_t_u64);

	gen_Str ssize_str = txt("gen_ssize");
	gen_t_ssize       = gen_def_type(ssize_str);
	gen_code_set_global(gen_t_ssize);
	gen_Str usize_str = txt("gen_usize");
	gen_t_usize       = gen_def_type(usize_str);
	gen_code_set_global(gen_t_usize);

	gen_Str f32_str = txt("gen_f32");
	gen_t_f32       = gen_def_type(f32_str);
	gen_code_set_global(gen_t_f32);
	gen_Str f64_str = txt("gen_f64");
	gen_t_f64       = gen_def_type(f64_str);
	gen_code_set_global(gen_t_f64);
#endif

	gen_spec_const = gen_def_specifier(Spec_Const);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_const));
	gen_spec_consteval = gen_def_specifier(Spec_Consteval);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_consteval));
	gen_spec_constexpr = gen_def_specifier(Spec_Constexpr);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_constexpr));
	gen_spec_constinit = gen_def_specifier(Spec_Constinit);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_constinit));
	gen_spec_extern_linkage = gen_def_specifier(Spec_External_Linkage);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_extern_linkage));
	gen_spec_final = gen_def_specifier(Spec_Final);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_final));
	gen_spec_forceinline = gen_def_specifier(Spec_ForceInline);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_forceinline));
	gen_spec_global = gen_def_specifier(Spec_Global);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_global));
	gen_spec_inline = gen_def_specifier(Spec_Inline);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_inline));
	gen_spec_internal_linkage = gen_def_specifier(Spec_Internal_Linkage);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_internal_linkage));
	gen_spec_local_persist = gen_def_specifier(Spec_Local_Persist);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_local_persist));
	gen_spec_mutable = gen_def_specifier(Spec_Mutable);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_mutable));
	gen_spec_neverinline = gen_def_specifier(Spec_NeverInline);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_neverinline));
	gen_spec_noexcept = gen_def_specifier(Spec_NoExceptions);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_noexcept));
	gen_spec_override = gen_def_specifier(Spec_Override);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_override));
	gen_spec_ptr = gen_def_specifier(Spec_Ptr);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_ptr));
	gen_spec_pure = gen_def_specifier(Spec_Pure);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_pure));
	gen_spec_ref = gen_def_specifier(Spec_Ref);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_ref));
	gen_spec_register = gen_def_specifier(Spec_Register);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_register));
	gen_spec_rvalue = gen_def_specifier(Spec_RValue);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_rvalue));
	gen_spec_static_member = gen_def_specifier(Spec_Static);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_static_member));
	gen_spec_thread_local = gen_def_specifier(Spec_Thread_Local);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_thread_local));
	gen_spec_virtual = gen_def_specifier(Spec_Virtual);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_virtual));
	gen_spec_volatile = gen_def_specifier(Spec_Volatile);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_volatile));

	gen_spec_local_persist = gen_def_specifiers(1, Spec_Local_Persist);
	gen_code_set_global(gen_cast(gen_Code, gen_spec_local_persist));

	if (gen_enum_underlying_macro.Name.Len == 0)
	{
		gen_enum_underlying_macro.Name  = txt("gen_enum_underlying");
		gen_enum_underlying_macro.Type  = MT_Expression;
		gen_enum_underlying_macro.Flags = MF_Functional;
	}
	gen_register_macro(gen_enum_underlying_macro);
}

void gen_init(gen_Context* ctx)
{
	gen_do_once()
	{
		context_counter = 0;
	}
	gen_AllocatorInfo fallback_allocator = { &gen_Global_Allocator_Proc, gen_nullptr };

	gen_b32 gen_using_fallback_allocator = false;
	if (ctx->Allocator_DyanmicContainers.Proc == gen_nullptr)
	{
		ctx->Allocator_DyanmicContainers = fallback_allocator;
		gen_using_fallback_allocator     = true;
	}
	if (ctx->Allocator_Pool.Proc == gen_nullptr)
	{
		ctx->Allocator_Pool          = fallback_allocator;
		gen_using_fallback_allocator = true;
	}
	if (ctx->Allocator_StrCache.Proc == gen_nullptr)
	{
		ctx->Allocator_StrCache      = fallback_allocator;
		gen_using_fallback_allocator = true;
	}
	if (ctx->Allocator_Temp.Proc == gen_nullptr)
	{
		ctx->Allocator_Temp          = fallback_allocator;
		gen_using_fallback_allocator = true;
	}
	// Setup fallback allocator
	if (gen_using_fallback_allocator)
	{
		ctx->Fallback_AllocatorBuckets = gen_array_init_reserve(gen_Arena, gen_heap(), 128);
		if (ctx->Fallback_AllocatorBuckets == gen_nullptr)
			GEN_FATAL("Failed to reserve memory for Fallback_AllocatorBuckets");

		gen_Arena bucket = gen_arena_init_from_allocator(gen_heap(), ctx->InitSize_Fallback_Allocator_Bucket_Size);
		if (bucket.PhysicalStart == gen_nullptr)
			GEN_FATAL("Failed to create first bucket for Fallback_AllocatorBuckets");

		gen_array_append(ctx->Fallback_AllocatorBuckets, bucket);
	}

	if (ctx->Max_CommentLineLength == 0)
	{
		ctx->Max_CommentLineLength = 1024;
	}
	if (ctx->Max_StrCacheLength == 0)
	{
		ctx->Max_StrCacheLength = gen_kilobytes(512);
	}

	if (ctx->InitSize_BuilderBuffer == 0)
	{
		ctx->InitSize_BuilderBuffer = gen_megabytes(2);
	}
	if (ctx->InitSize_CodePoolsArray == 0)
	{
		ctx->InitSize_CodePoolsArray = 16;
	}
	if (ctx->InitSize_StringArenasArray == 0)
	{
		ctx->InitSize_StringArenasArray = 16;
	}
	if (ctx->CodePool_NumBlocks == 0)
	{
		ctx->CodePool_NumBlocks = gen_kilobytes(16);
	}

	if (ctx->InitSize_LexerTokens == 0)
	{
		ctx->InitSize_LexerTokens = gen_kilobytes(64);
	}
	if (ctx->SizePer_StringArena == 0)
	{
		ctx->SizePer_StringArena = gen_megabytes(1);
	}

	if (ctx->InitSize_Fallback_Allocator_Bucket_Size == 0)
	{
		ctx->InitSize_Fallback_Allocator_Bucket_Size = gen_megabytes(8);
	}

	// Override the current context (user has to put it back if unwanted).
	gen__ctx = ctx;

	// Setup the arrays
	{
		ctx->CodePools = gen_array_init_reserve(gen_Pool, ctx->Allocator_DyanmicContainers, ctx->InitSize_CodePoolsArray);
		if (ctx->CodePools == gen_nullptr)
			GEN_FATAL("gen::gen_init: Failed to initialize the CodePools array");

		ctx->StringArenas = gen_array_init_reserve(gen_Arena, ctx->Allocator_DyanmicContainers, ctx->InitSize_StringArenasArray);
		if (ctx->StringArenas == gen_nullptr)
			GEN_FATAL("gen::gen_init: Failed to initialize the StringArenas array");
	}
	// Setup the code pool and code entries arena.
	{
		gen_Pool gen_code_pool = gen_pool_init(ctx->Allocator_Pool, ctx->CodePool_NumBlocks, sizeof(gen_AST));
		if (gen_code_pool.PhysicalStart == gen_nullptr)
			GEN_FATAL("gen::gen_init: Failed to initialize the code pool");
		gen_array_append(ctx->CodePools, gen_code_pool);

		// TODO(Ed): Eventually the string arenas needs to be phased out for a dedicated string slab allocator
		gen_Arena gen_strbuilder_arena = gen_arena_init_from_allocator(ctx->Allocator_StrCache, ctx->SizePer_StringArena);
		if (gen_strbuilder_arena.PhysicalStart == gen_nullptr)
			GEN_FATAL("gen::gen_init: Failed to initialize the string arena");
		gen_array_append(ctx->StringArenas, gen_strbuilder_arena);
	}
	// Setup the gen_hash tables
	{
		ctx->StrCache = gen_hashtable_init(gen_StrCached, ctx->Allocator_DyanmicContainers);
		if (ctx->StrCache.Entries == gen_nullptr)
			GEN_FATAL("gen::gen_init: Failed to initialize the StringCache");

		ctx->Macros = gen_hashtable_init(gen_Macro, ctx->Allocator_DyanmicContainers);
		if (ctx->Macros.Hashes == gen_nullptr || ctx->Macros.Entries == gen_nullptr)
		{
			GEN_FATAL("gen::gen_init: Failed to initialize the PreprocessMacros table");
		}
	}

	gen_define_constants();
	gen_parser_init();

	++context_counter;
}

void gen_deinit(gen_Context* ctx)
{
	GEN_ASSERT(context_counter);
	GEN_ASSERT_MSG(context_counter > 0, "Attempted to gen_deinit a context that for some reason wan't accounted for!");
	gen_usize index = 0;
	gen_usize left  = gen_array_num(ctx->CodePools);
	do
	{
		gen_Pool* gen_code_pool = &ctx->CodePools[index];
		gen_pool_free(gen_code_pool);
		index++;
	} while (left--, left);

	index = 0;
	left  = gen_array_num(ctx->StringArenas);
	do
	{
		gen_Arena* gen_strbuilder_arena = &ctx->StringArenas[index];
		gen_arena_free(gen_strbuilder_arena);
		index++;
	} while (left--, left);

	gen_hashtable_destroy(ctx->StrCache);

	gen_array_free(ctx->CodePools);
	gen_array_free(ctx->StringArenas);

	gen_hashtable_destroy(ctx->Macros);

	left = gen_array_num(ctx->Fallback_AllocatorBuckets);
	if (left)
	{
		index = 0;
		do
		{
			gen_Arena* bucket = &ctx->Fallback_AllocatorBuckets[index];
			gen_arena_free(bucket);
			index++;
		} while (left--, left);
		gen_array_free(ctx->Fallback_AllocatorBuckets);
	}
	gen_parser_deinit();

	if (gen__ctx == ctx)
		gen__ctx = gen_nullptr;
	--context_counter;

	gen_Context wipe = {};
	*ctx             = wipe;
}

gen_Context* get_context()
{
	return gen__ctx;
}

void gen_reset(gen_Context* ctx)
{
	gen_s32 index = 0;
	gen_s32 left  = gen_array_num(ctx->CodePools);
	do
	{
		gen_Pool* gen_code_pool = &ctx->CodePools[index];
		gen_pool_clear(gen_code_pool);
		index++;
	} while (left--, left);

	index = 0;
	left  = gen_array_num(ctx->StringArenas);
	do
	{
		gen_Arena* gen_strbuilder_arena = &ctx->StringArenas[index];
		gen_strbuilder_arena->TotalUsed = 0;
		;
		index++;
	} while (left--, left);

	gen_hashtable_clear(ctx->StrCache);
	gen_hashtable_clear(ctx->Macros);
	gen_define_constants();
}

void set_context(gen_Context* new_ctx)
{
	GEN_ASSERT(new_ctx);
	gen__ctx = new_ctx;
}

gen_AllocatorInfo get_cached_str_allocator(gen_s32 gen_str_length)
{
	gen_Arena* last     = gen_array_back(gen__ctx->StringArenas);
	gen_usize  size_req = gen_str_length + sizeof(gen_StrBuilderHeader) + sizeof(char*);
	if (last->TotalUsed + gen_scast(gen_ssize, size_req) > last->TotalSize)
	{
		gen_Arena new_arena = gen_arena_init_from_allocator(gen__ctx->Allocator_StrCache, gen__ctx->SizePer_StringArena);
		if (! gen_array_append(gen__ctx->StringArenas, new_arena))
			GEN_FATAL("gen::get_cached_str_allocator: Failed to allocate a new string arena");

		last = gen_array_back(gen__ctx->StringArenas);
	}
	return gen_arena_allocator_info(last);
}

// Will either make or retrive a code string.
gen_StrCached gen_cache_str(gen_Str str)
{
	if (str.Len > gen__ctx->Max_StrCacheLength)
	{
		// Do not cache the string, just shove into the arena and and return it.
		gen_Str result = gen_strbuilder_to_str(gen_strbuilder_make_str(get_cached_str_allocator(str.Len), str));
		return result;
	}
	gen_u64 key = gen_crc32(str.Ptr, str.Len);
	{
		gen_StrCached* result = gen_hashtable_get(gen__ctx->StrCache, key);
		if (result)
			return *result;
	}
	gen_Str result = gen_strbuilder_to_str(gen_strbuilder_make_str(get_cached_str_allocator(str.Len), str));
	gen_hashtable_set(gen__ctx->StrCache, key, result);
	return result;
}

// Used internally to retireve a gen_Code object form the CodePool.
gen_Code gen_make_code()
{
	gen_Pool* allocator = gen_array_back(gen__ctx->CodePools);
	if (allocator->FreeList == gen_nullptr)
	{
		gen_Pool gen_code_pool = gen_pool_init(gen__ctx->Allocator_Pool, gen__ctx->CodePool_NumBlocks, sizeof(gen_AST));

		if (gen_code_pool.PhysicalStart == gen_nullptr)
			GEN_FATAL("gen::gen_make_code: Failed to allocate a new code pool - CodePool allcoator returned gen_nullptr.");

		if (! gen_array_append(gen__ctx->CodePools, gen_code_pool))
			GEN_FATAL("gen::gen_make_code: Failed to allocate a new code pool - CodePools failed to append new pool.");

		allocator = gen_array_back(gen__ctx->CodePools);
	}
	gen_Code result = { gen_rcast(gen_AST*, gen_alloc(gen_pool_allocator_info(allocator), sizeof(gen_AST))) };
	gen_mem_set(gen_rcast(void*, gen_cast(gen_AST*, result)), 0, sizeof(gen_AST));
	return result;
}

gen_Macro* lookup_macro(gen_Str name)
{
	gen_u32 key = gen_crc32(name.Ptr, name.Len);
	return gen_hashtable_get(gen__ctx->Macros, key);
}

void gen_register_macro(gen_Macro macro)
{
	GEN_ASSERT_NOT_NULL(macro.Name.Ptr);
	GEN_ASSERT(macro.Name.Len > 0);
	gen_u32 key = gen_crc32(macro.Name.Ptr, macro.Name.Len);
	macro.Name  = gen_cache_str(macro.Name);
	gen_hashtable_set(gen__ctx->Macros, key, macro);
}

void gen_register_macros(gen_s32 num, ...)
{
	GEN_ASSERT(num > 0);
	va_list va;
	va_start(va, num);
	do
	{
		gen_Macro macro = va_arg(va, gen_Macro);
		GEN_ASSERT_NOT_NULL(macro.Name.Ptr);
		GEN_ASSERT(macro.Name.Len > 0);
		macro.Name  = gen_cache_str(macro.Name);

		gen_u32 key = gen_crc32(macro.Name.Ptr, macro.Name.Len);
		gen_hashtable_set(gen__ctx->Macros, key, macro);
	} while (num--, num > 0);
	va_end(va);
}

void gen_register_macros_arr(gen_s32 num, gen_Macro* macros)
{
	GEN_ASSERT(num > 0);
	do
	{
		gen_Macro macro = *macros;
		GEN_ASSERT_NOT_NULL(macro.Name.Ptr);
		GEN_ASSERT(macro.Name.Len > 0);
		macro.Name  = gen_cache_str(macro.Name);

		gen_u32 key = gen_crc32(macro.Name.Ptr, macro.Name.Len);
		gen_hashtable_set(gen__ctx->Macros, key, macro);
		++macros;
	} while (num--, num > 0);
}

#pragma region Upfront

enum OpValidateResult gen_enum_underlying(gen_u32)
{
	OpValResult_Fail,
	OpValResult_Global,
	OpValResult_Member
};

typedef gen_u32 OpValidateResult;

gen_internal gen_neverinline OpValidateResult
    gen_operator__validate(gen_Operator op, gen_CodeParams gen_params_code, gen_CodeTypename ret_type, gen_CodeSpecifiers specifier)
{
	if (op == Op_Invalid)
	{
		gen_log_failure("gen::gen_def_operator: op cannot be invalid");
		return OpValResult_Fail;
	}

#pragma region Helper Macros
#define check_params()                                                                                                                            \
	if (! gen_params_code)                                                                                                                        \
	{                                                                                                                                             \
		gen_log_failure("gen::gen_def_operator: params is null and operator %S requires it", gen_operator_to_str(op));                            \
		return OpValResult_Fail;                                                                                                                  \
	}                                                                                                                                             \
	if (gen_params_code->Type != CT_Parameters)                                                                                                   \
	{                                                                                                                                             \
		gen_log_failure("gen::gen_def_operator: params is not of Parameters type - %S", gen_code_debug_str(gen_cast(gen_Code, gen_params_code))); \
		return OpValResult_Fail;                                                                                                                  \
	}

#define check_param_eq_ret()                                                                                                     \
	if (! is_member_symbol && ! gen_code_is_equal(gen_cast(gen_Code, gen_params_code->ValueType), gen_cast(gen_Code, ret_type))) \
	{                                                                                                                            \
		gen_log_failure(                                                                                                         \
		    "gen::gen_def_operator: operator %S requires first parameter to equal return type\n"                                 \
		    "param types: %S\n"                                                                                                  \
		    "return type: %S",                                                                                                   \
		    gen_operator_to_str(op),                                                                                             \
		    gen_code_debug_str(gen_cast(gen_Code, gen_params_code)),                                                             \
		    gen_code_debug_str(gen_cast(gen_Code, ret_type))                                                                     \
		);                                                                                                                       \
		return OpValResult_Fail;                                                                                                 \
	}
#pragma endregion Helper Macros

	if (! ret_type)
	{
		gen_log_failure("gen::gen_def_operator: ret_type is null but is required by operator %S", gen_operator_to_str(op));
	}

	if (ret_type->Type != CT_Typename)
	{
		gen_log_failure(
		    "gen::gen_def_operator: operator %S - ret_type is not of typename type - %S",
		    gen_operator_to_str(op),
		    gen_code_debug_str(gen_cast(gen_Code, ret_type))
		);
		return OpValResult_Fail;
	}

	bool is_member_symbol = false;

	switch (op)
	{
#define specs(...) gen_num_args(__VA_ARGS__), __VA_ARGS__
		case Op_Assign:
			check_params();

			if (gen_params_code->NumEntries > 1)
			{
				gen_log_failure(
				    "gen::gen_def_operator: "
				    "operator %S does not support non-member definition (more than one parameter provided) - %S",
				    gen_operator_to_str(op),
				    gen_code_debug_str(gen_cast(gen_Code, gen_params_code))
				);
				return OpValResult_Fail;
			}

			is_member_symbol = true;
			break;

		case Op_Assign_Add:
		case Op_Assign_Subtract:
		case Op_Assign_Multiply:
		case Op_Assign_Divide:
		case Op_Assign_Modulo:
		case Op_Assign_BAnd:
		case Op_Assign_BOr:
		case Op_Assign_BXOr:
		case Op_Assign_LShift:
		case Op_Assign_RShift:
			check_params();

			if (gen_params_code->NumEntries == 1)
				is_member_symbol = true;

			else
				check_param_eq_ret();

			if (gen_params_code->NumEntries > 2)
			{
				gen_log_failure(
				    "gen::gen_def_operator: operator %S may not be defined with more than two parametes - param count; %d\n%S",
				    gen_operator_to_str(op),
				    gen_params_code->NumEntries,
				    gen_code_debug_str(gen_cast(gen_Code, gen_params_code))
				);
				return OpValResult_Fail;
			}
			break;

		case Op_Increment:
		case Op_Decrement:
			// If its not set, it just means its a prefix member op.
			if (gen_params_code)
			{
				if (gen_params_code->Type != CT_Parameters)
				{
					gen_log_failure(
					    "gen::gen_def_operator: operator %S params code provided is not of Parameters type - %S",
					    gen_operator_to_str(op),
					    gen_code_debug_str(gen_cast(gen_Code, gen_params_code))
					);
					return OpValResult_Fail;
				}

				switch (gen_params_code->NumEntries)
				{
					case 1:
						if (gen_code_is_equal((gen_Code)gen_params_code->ValueType, (gen_Code)gen_t_int))
							is_member_symbol = true;

						else
							check_param_eq_ret();
						break;

					case 2:
						check_param_eq_ret();

						if (! gen_code_is_equal((gen_Code)gen_params_get(gen_params_code, 1), (gen_Code)gen_t_int))
						{
							gen_log_failure(
							    "gen::gen_def_operator: "
							    "operator %S requires second parameter of non-member definition to be int for post-decrement",
							    gen_operator_to_str(op)
							);
							return OpValResult_Fail;
						}
						break;

					default:
						gen_log_failure(
						    "gen::gen_def_operator: operator %S recieved unexpected number of parameters recived %d instead of 0-2",
						    gen_operator_to_str(op),
						    gen_params_code->NumEntries
						);
						return OpValResult_Fail;
				}
			}
			break;

		case Op_Unary_Plus:
		case Op_Unary_Minus:
			if (! gen_params_code)
				is_member_symbol = true;

			else
			{
				if (gen_params_code->Type != CT_Parameters)
				{
					gen_log_failure("gen::gen_def_operator: params is not of Parameters type - %S", gen_code_debug_str((gen_Code)gen_params_code));
					return OpValResult_Fail;
				}

				if (gen_code_is_equal((gen_Code)gen_params_code->ValueType, (gen_Code)ret_type))
				{
					gen_log_failure(
					    "gen::gen_def_operator: "
					    "operator %S is non-member symbol yet first paramter does not equal return type\n"
					    "param type: %S\n"
					    "return type: %S\n",
					    gen_code_debug_str((gen_Code)gen_params_code),
					    gen_code_debug_str((gen_Code)ret_type)
					);
					return OpValResult_Fail;
				}

				if (gen_params_code->NumEntries > 1)
				{
					gen_log_failure(
					    "gen::gen_def_operator: operator %S may not have more than one parameter - param count: %d",
					    gen_operator_to_str(op),
					    gen_params_code->NumEntries
					);
					return OpValResult_Fail;
				}
			}
			break;

		case Op_BNot:
		{
			// Some compilers let you do this...
#if 0
			if ( ! ret_type.is_equal( gen_t_bool) )
			{
				gen_log_failure( "gen::gen_def_operator: operator %S return type is not a boolean - %S", gen_operator_to_str(op) gen_code_debug_str(gen_params_code) );
				return OpValidateResult::Fail;
			}
#endif

			if (! gen_params_code)
				is_member_symbol = true;

			else
			{
				if (gen_params_code->Type != CT_Parameters)
				{
					gen_log_failure(
					    "gen::gen_def_operator: operator %S - params is not of Parameters type - %S",
					    gen_operator_to_str(op),
					    gen_code_debug_str((gen_Code)gen_params_code)
					);
					return OpValResult_Fail;
				}

				if (gen_params_code->NumEntries > 1)
				{
					gen_log_failure(
					    "gen::gen_def_operator: operator %S may not have more than one parameter - param count: %d",
					    gen_operator_to_str(op),
					    gen_params_code->NumEntries
					);
					return OpValResult_Fail;
				}
			}
			break;
		}

		case Op_Add:
		case Op_Subtract:
		case Op_Multiply:
		case Op_Divide:
		case Op_Modulo:
		case Op_BAnd:
		case Op_BOr:
		case Op_BXOr:
		case Op_LShift:
		case Op_RShift:
			check_params();

			switch (gen_params_code->NumEntries)
			{
				case 1:
					is_member_symbol = true;
					break;

				case 2:
					// This is allowed for arithemtic operators
					// if ( ! gen_code_is_equal((gen_Code)gen_params_code->ValueType, (gen_Code)ret_type ) )
					// {
					// 	gen_log_failure("gen::gen_def_operator: "
					// 		"operator %S is non-member symbol yet first paramter does not equal return type\n"
					// 		"param type: %S\n"
					// 		"return type: %S\n"
					// 		, gen_code_debug_str((gen_Code)gen_params_code)
					// 		, gen_code_debug_str((gen_Code)ret_type)
					// 	);
					// 	return OpValResult_Fail;
					// }
					break;

				default:
					gen_log_failure(
					    "gen::gen_def_operator: operator %S recieved unexpected number of paramters recived %d instead of 0-2",
					    gen_operator_to_str(op),
					    gen_params_code->NumEntries
					);
					return OpValResult_Fail;
			}
			break;

		case Op_UnaryNot:
			if (! gen_params_code)
				is_member_symbol = true;

			else
			{
				if (gen_params_code->Type != CT_Parameters)
				{
					gen_log_failure(
					    "gen::gen_def_operator: operator %S - params is not of Parameters type - %S",
					    gen_operator_to_str(op),
					    gen_code_debug_str((gen_Code)gen_params_code)
					);
					return OpValResult_Fail;
				}

				if (gen_params_code->NumEntries != 1)
				{
					gen_log_failure(
					    "gen::gen_def_operator: operator %S recieved unexpected number of paramters recived %d instead of 0-1",
					    gen_operator_to_str(op),
					    gen_params_code->NumEntries
					);
					return OpValResult_Fail;
				}
			}

			if (! gen_code_is_equal((gen_Code)ret_type, (gen_Code)gen_t_bool))
			{
				gen_log_failure(
				    "gen::gen_def_operator: operator %S return type must be of type bool - %S",
				    gen_operator_to_str(op),
				    gen_code_debug_str((gen_Code)ret_type)
				);
				return OpValResult_Fail;
			}
			break;

		case Op_LAnd:
		case Op_LOr:
		case Op_LEqual:
		case Op_LNot:
		case Op_Lesser:
		case Op_Greater:
		case Op_LesserEqual:
		case Op_GreaterEqual:
			check_params();

			switch (gen_params_code->NumEntries)
			{
				case 1:
					is_member_symbol = true;
					break;

				case 2:
					break;

				default:
					gen_log_failure(
					    "gen::gen_def_operator: operator %S recieved unexpected number of paramters recived %d instead of 1-2",
					    gen_operator_to_str(op),
					    gen_params_code->NumEntries
					);
					return OpValResult_Fail;
			}
			break;

		case Op_Indirection:
		case Op_AddressOf:
		case Op_MemberOfPointer:
			if (gen_params_code && gen_params_code->NumEntries > 1)
			{
				gen_log_failure(
				    "gen::gen_def_operator: operator %S recieved unexpected number of paramters recived %d instead of 0-1",
				    gen_operator_to_str(op),
				    gen_params_code->NumEntries
				);
				return OpValResult_Fail;
			}
			else
			{
				is_member_symbol = true;
			}
			break;

		case Op_PtrToMemOfPtr:
			if (gen_params_code)
			{
				gen_log_failure(
				    "gen::gen_def_operator: operator %S expects no paramters - %S",
				    gen_operator_to_str(op),
				    gen_code_debug_str((gen_Code)gen_params_code)
				);
				return OpValResult_Fail;
			}
			break;

		case Op_Subscript:
		case Op_FunctionCall:
		case Op_Comma:
			check_params();
			break;

		case Op_New:
		case Op_Delete:
			// This library doesn't support validating new and delete yet.
			break;
#undef specs
	}

	return is_member_symbol ? OpValResult_Member : OpValResult_Global;
#undef check_params
#undef check_ret_type
#undef check_param_eq_ret
}

gen_forceinline bool name__check(char const* context, gen_Str name)
{
	if (name.Len <= 0)
	{
		gen_log_failure("gen::%s: Invalid name length provided - %d", name.Len);
		return false;
	}
	if (name.Ptr == gen_nullptr)
	{
		gen_log_failure("gen::%s: name is null");
		return false;
	}
	return true;
}

#define name_check(context, name) name__check(#context, name)

gen_forceinline bool null__check(char const* context, char const* gen_code_id, gen_Code code)
{
	if (code == gen_nullptr)
	{
		gen_log_failure("gen::%s: %s provided is null", context, gen_code_id);
		return false;
	}
	return true;
}

#define null_check(context, code) null__check(#context, #code, gen_cast(gen_Code, code))

/*
The implementation of the upfront gen_constructor_s involves doing three things:
* Validate the arguments given to construct the intended type of gen_AST is valid.
* Construct said gen_AST type.
* Lock the gen_AST (set to readonly) and return the valid object.

If any of the validation fails, it triggers a call to gen_log_failure with as much info the give the user so that they can hopefully
identify the issue without having to debug too much (at least they can debug though...)

The largest of the functions is related to operator overload definitions.
The library validates a good protion of their form and thus the argument processing for is quite a gen_bit.
*/
gen_CodeAttributes gen_def_attributes(gen_Str content)
{
	if (content.Len <= 0 || content.Ptr == gen_nullptr)
	{
		gen_log_failure("gen::gen_def_attributes: Invalid attributes provided");
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	gen_Code result = gen_make_code();
	result->Type    = CT_PlatformAttributes;
	result->Name    = gen_cache_str(content);
	result->Content = result->Name;
	return (gen_CodeAttributes)result;
}

gen_CodeComment gen_def_comment(gen_Str content)
{
	if (content.Len <= 0 || content.Ptr == gen_nullptr)
	{
		gen_log_failure("gen::gen_def_comment: Invalid comment provided:");
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}

	gen_StrBuilder cmt_formatted = gen_strbuilder_make_reserve(gen__ctx->Allocator_Temp, gen_kilobytes(1));
	char const*    end           = content.Ptr + content.Len;
	char const*    scanner       = content.Ptr;
	gen_s32        curr          = 0;
	do
	{
		char const* next   = scanner;
		gen_s32     length = 0;
		while (next != end && scanner[length] != '\n')
		{
			next = scanner + length;
			length++;
		}
		length++;

		gen_strbuilder_append_fmt(&cmt_formatted, "//%.*s", length, scanner);
		scanner += length;
	} while (scanner <= end);

	if (*gen_strbuilder_back(cmt_formatted) != '\n')
		gen_strbuilder_append_str(&cmt_formatted, txt("\n"));

	gen_Str name    = gen_strbuilder_to_str(cmt_formatted);

	gen_Code result = gen_make_code();
	result->Type    = CT_Comment;
	result->Name    = gen_cache_str(name);
	result->Content = result->Name;

	gen_strbuilder_free(&cmt_formatted);

	return (gen_CodeComment)result;
}

gen_CodeConstructor gen_def__constructor(gen_Opts_def_constructor p)
{
	if (p.params && p.params->Type != CT_Parameters)
	{
		gen_log_failure("gen::gen_def_constructor: params must be of Parameters type - %s", gen_code_debug_str((gen_Code)p.params));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}

	gen_CodeConstructor result = (gen_CodeConstructor)gen_make_code();
	if (p.params)
	{
		result->Params = p.params;
	}
	if (p.initializer_list)
	{
		result->InitializerList = p.initializer_list;
	}
	if (p.body)
	{
		switch (p.body->Type)
		{
			case CT_Function_Body:
			case CT_Untyped:
				break;

			default:
				gen_log_failure("gen::gen_def_constructor: body must be either of Function_Body or Untyped type - %s", gen_code_debug_str(p.body));
				return gen_InvalidCode;
		}

		result->Type = CT_Constructor;
		result->Body = p.body;
	}
	else
	{
		result->Type = CT_Constructor_Fwd;
	}
	return result;
}

gen_CodeClass gen_def__class(gen_Str name, gen_Opts_def_struct p)
{
	if (! name_check(gen_def_class, name))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (p.attributes && p.attributes->Type != CT_PlatformAttributes)
	{
		gen_log_failure("gen::gen_def_class: attributes was not a 'PlatformAttributes' type: %s", gen_code_debug_str(p.attributes));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (p.parent && (p.parent->Type != CT_Class && p.parent->Type != CT_Struct && p.parent->Type != CT_Typename && p.parent->Type != CT_Untyped))
	{
		gen_log_failure("gen::gen_def_class: parent provided is not type 'Class', 'Struct', 'Typeanme', or 'Untyped': %s", gen_code_debug_str(p.parent));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}

	gen_CodeClass result = (gen_CodeClass)gen_make_code();
	result->Name         = gen_cache_str(name);
	result->ModuleFlags  = p.mflags;
	result->Attributes   = p.attributes;
	result->Specs        = p.specifiers;
	result->ParentAccess = p.parent_access;
	result->ParentType   = p.parent;
	if (p.body)
	{
		switch (p.body->Type)
		{
			case CT_Class_Body:
			case CT_Untyped:
				break;

			default:
				gen_log_failure("gen::gen_def_class: body must be either of Class_Body or Untyped type - %s", gen_code_debug_str(p.body));
				return gen_InvalidCode;
		}

		result->Type         = CT_Class;
		result->Body         = p.body;
		result->Body->Parent = gen_cast(gen_Code, result);
	}
	else
	{
		result->Type = CT_Class_Fwd;
	}
	for (gen_s32 idx = 0; idx < p.num_interfaces; idx++)
	{
		gen_class_add_interface(result, p.interfaces[idx]);
	}
	return result;
}

gen_CodeDefine gen_def__define(gen_Str name, gen_MacroType type, gen_Opts_def_define p)
{
	if (! name_check(gen_def_define, name))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	gen_CodeDefine result = (gen_CodeDefine)gen_make_code();
	result->Type          = CT_Preprocess_Define;
	result->Name          = gen_cache_str(name);
	result->Params        = p.params;
	if (p.content.Len <= 0 || p.content.Ptr == gen_nullptr)
		result->Body = gen_untyped_str(txt("\n"));
	else
		result->Body = gen_untyped_str(gen_strbuilder_to_str(gen_strbuilder_fmt_buf(gen__ctx->Allocator_Temp, "%S\n", p.content)));

	gen_b32 register_define = ! p.dont_register_to_preprocess_macros;
	if (register_define)
	{
		gen_Macro gen_macro_entry = { result->Name, type, p.flags };
		gen_register_macro(gen_macro_entry);
	}
	return result;
}

gen_CodeDestructor gen_def__destructor(gen_Opts_def_destructor p)
{
	if (p.specifiers && p.specifiers->Type != CT_Specifiers)
	{
		gen_log_failure("gen::gen_def_destructor: specifiers was not a 'Specifiers' type: %s", gen_code_debug_str(p.specifiers));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}

	gen_CodeDestructor result = (gen_CodeDestructor)gen_make_code();
	result->Specs             = p.specifiers;
	if (p.body)
	{
		switch (p.body->Type)
		{
			case CT_Function_Body:
			case CT_Untyped:
				break;

			default:
				gen_log_failure("gen::gen_def_destructor: body must be either of Function_Body or Untyped type - %s", gen_code_debug_str(p.body));
				return gen_InvalidCode;
		}

		result->Type = CT_Destructor;
		result->Body = p.body;
	}
	else
	{
		result->Type = CT_Destructor_Fwd;
	}
	return result;
}

gen_CodeEnum gen_def__enum(gen_Str name, gen_Opts_def_enum p)
{
	if (! name_check(gen_def_enum, name))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (p.type && p.type->Type != CT_Typename)
	{
		gen_log_failure("gen::gen_def_enum: enum underlying type provided was not of type Typename: %s", gen_code_debug_str(p.type));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (p.attributes && p.attributes->Type != CT_PlatformAttributes)
	{
		gen_log_failure("gen::gen_def_enum: attributes was not a 'PlatformAttributes' type: %s", gen_code_debug_str(p.attributes));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}

	gen_CodeEnum result = (gen_CodeEnum)gen_make_code();
	result->Name        = gen_cache_str(name);
	result->ModuleFlags = p.mflags;
	if (p.body)
	{
		switch (p.body->Type)
		{
			case CT_Enum_Body:
			case CT_Untyped:
				break;

			default:
				gen_log_failure("gen::gen_def_enum: body must be of Enum_Body or Untyped type %s", gen_code_debug_str(p.body));
				return gen_InvalidCode;
		}

		result->Type = p.specifier == EnumDecl_Class ? CT_Enum_Class : CT_Enum;

		result->Body = p.body;
	}
	else
	{
		result->Type = p.specifier == EnumDecl_Class ? CT_Enum_Class_Fwd : CT_Enum_Fwd;
	}
	result->Attributes = p.attributes;

	if (p.type)
	{
		result->UnderlyingType = p.type;
	}
	else if (p.type_macro)
	{
		result->UnderlyingTypeMacro = p.type_macro;
	}
	else if (result->Type != CT_Enum_Class_Fwd && result->Type != CT_Enum_Fwd)
	{
		gen_log_failure("gen::gen_def_enum: enum forward declaration must have an underlying type");
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	return result;
}

gen_CodeExec gen_def_execution(gen_Str content)
{
	if (content.Len <= 0 || content.Ptr == gen_nullptr)
	{
		gen_log_failure("gen::gen_def_execution: Invalid execution provided");
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	gen_CodeExec result = (gen_CodeExec)gen_make_code();
	result->Type        = CT_Execution;
	result->Content     = gen_cache_str(content);
	return result;
}

gen_CodeExtern gen_def_extern_link(gen_Str name, gen_CodeBody body)
{
	if (! name_check(gen_def_extern_link, name) || ! null_check(gen_def_extern_link, body))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (body->Type != CT_Extern_Linkage_Body && body->Type != CT_Untyped)
	{
		gen_log_failure("gen::gen_def_extern_linkage: body is not of gen_extern_linkage or untyped type %s", gen_code_debug_str(body));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	gen_CodeExtern result = (gen_CodeExtern)gen_make_code();
	result->Type          = CT_Extern_Linkage;
	result->Name          = gen_cache_str(name);
	result->Body          = body;
	return result;
}

gen_CodeFriend gen_def_friend(gen_Code declaration)
{
	if (! null_check(gen_def_friend, declaration))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	switch (declaration->Type)
	{
		case CT_Class_Fwd:
		case CT_Function_Fwd:
		case CT_Operator_Fwd:
		case CT_Struct_Fwd:
		case CT_Class:
		case CT_Function:
		case CT_Operator:
		case CT_Struct:
			break;

		default:
			gen_log_failure("gen::gen_def_friend: requires declartion to have class, function, operator, or struct - %s", gen_code_debug_str(declaration));
			return gen_InvalidCode;
	}
	gen_CodeFriend result = (gen_CodeFriend)gen_make_code();
	result->Type          = CT_Friend;
	result->Declaration   = declaration;
	return result;
}

gen_CodeFn gen_def__function(gen_Str name, gen_Opts_def_function p)
{
	if (! name_check(gen_def_function, name))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (p.params && p.params->Type != CT_Parameters)
	{
		gen_log_failure("gen::gen_def_function: params was not a `Parameters` type: %s", gen_code_debug_str(p.params));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (p.ret_type && p.ret_type->Type != CT_Typename)
	{
		gen_log_failure("gen::gen_def_function: ret_type was not a Typename: %s", gen_code_debug_str(p.ret_type));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (p.specs && p.specs->Type != CT_Specifiers)
	{
		gen_log_failure("gen::gen_def_function: specifiers was not a `Specifiers` type: %s", gen_code_debug_str(p.specs));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (p.attrs && p.attrs->Type != CT_PlatformAttributes)
	{
		gen_log_failure("gen::gen_def_function: attributes was not a `PlatformAttributes` type: %s", gen_code_debug_str(p.attrs));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}

	gen_CodeFn result   = (gen_CodeFn)gen_make_code();
	result->Name        = gen_cache_str(name);
	result->ModuleFlags = p.mflags;
	if (p.body)
	{
		switch (p.body->Type)
		{
			case CT_Function_Body:
			case CT_Execution:
			case CT_Untyped:
				break;

			default:
			{
				gen_log_failure("gen::gen_def_function: body must be either of Function_Body, Execution, or Untyped type. %s", gen_code_debug_str(p.body));
				return gen_InvalidCode;
			}
		}
		result->Type = CT_Function;
		result->Body = p.body;
	}
	else
	{
		result->Type = CT_Function_Fwd;
	}
	result->Attributes = p.attrs;
	result->Specs      = p.specs;
	result->Params     = p.params;
	result->ReturnType = p.ret_type ? p.ret_type : gen_t_void;
	return result;
}

gen_CodeInclude gen_def__include(gen_Str path, gen_Opts_def_include p)
{
	if (path.Len <= 0 || path.Ptr == gen_nullptr)
	{
		gen_log_failure("gen::gen_def_include: Invalid path provided - %d");
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	gen_StrBuilder content = p.foreign ? gen_strbuilder_fmt_buf(gen__ctx->Allocator_Temp, "<%.*s>", path.Len, path.Ptr)
	                                   : gen_strbuilder_fmt_buf(gen__ctx->Allocator_Temp, "\"%.*s\"", path.Len, path.Ptr);

	gen_CodeInclude result = (gen_CodeInclude)gen_make_code();
	result->Type           = CT_Preprocess_Include;
	result->Name           = gen_cache_str(gen_strbuilder_to_str(content));
	result->Content        = result->Name;
	return result;
}

gen_CodeModule gen_def__module(gen_Str name, gen_Opts_def_module p)
{
	if (! name_check(gen_def_module, name))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	gen_CodeModule result = (gen_CodeModule)gen_make_code();
	result->Type          = CT_Module;
	result->Name          = gen_cache_str(name);
	result->ModuleFlags   = p.mflags;
	return result;
}

gen_CodeNS gen_def__namespace(gen_Str name, gen_CodeBody body, gen_Opts_def_namespace p)
{
	if (! name_check(gen_def_namespace, name))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (! null_check(gen_def_namespace, body))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (body && body->Type != CT_Namespace_Body && body->Type != CT_Untyped)
	{
		gen_log_failure("gen::gen_def_namespace: body is not of namespace or untyped type %s", gen_code_debug_str(body));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	gen_CodeNS result   = (gen_CodeNS)gen_make_code();
	result->Type        = CT_Namespace;
	result->Name        = gen_cache_str(name);
	result->ModuleFlags = p.mflags;
	result->Body        = body;
	return result;
}

gen_CodeOperator gen_def__operator(gen_Operator op, gen_Str nspace, gen_Opts_def_operator p)
{
	if (p.attributes && p.attributes->Type != CT_PlatformAttributes)
	{
		gen_log_failure("gen::gen_def_operator: PlatformAttributes was provided but its not of attributes type: %s", gen_code_debug_str(p.attributes));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (p.specifiers && p.specifiers->Type != CT_Specifiers)
	{
		gen_log_failure("gen::gen_def_operator: Specifiers was provided but its not of specifiers type: %s", gen_code_debug_str(p.specifiers));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}

	OpValidateResult check_result = gen_operator__validate(op, p.params, p.ret_type, p.specifiers);
	if (check_result == OpValResult_Fail)
	{
		return gen_InvalidCode;
	}

	char const* name = gen_nullptr;

	gen_Str op_str   = gen_operator_to_str(op);
	if (nspace.Len > 0)
		name = gen_c_str_fmt_buf("%.*soperator %.*s", nspace.Len, nspace.Ptr, op_str.Len, op_str.Ptr);
	else
		name = gen_c_str_fmt_buf("operator %.*s", op_str.Len, op_str.Ptr);

	gen_Str name_resolved   = { name, gen_c_str_len(name) };

	gen_CodeOperator result = (gen_CodeOperator)gen_make_code();
	result->Name            = gen_cache_str(name_resolved);
	result->ModuleFlags     = p.mflags;
	result->Op              = op;
	if (p.body)
	{
		switch (p.body->Type)
		{
			case CT_Function_Body:
			case CT_Execution:
			case CT_Untyped:
				break;

			default:
			{
				gen_log_failure("gen::gen_def_operator: body must be either of Function_Body, Execution, or Untyped type. %s", gen_code_debug_str(p.body));
				GEN_DEBUG_TRAP();
				return gen_InvalidCode;
			}
		}

		result->Type = check_result == OpValResult_Global ? CT_Operator : CT_Operator_Member;

		result->Body = p.body;
	}
	else
	{
		result->Type = check_result == OpValResult_Global ? CT_Operator_Fwd : CT_Operator_Member_Fwd;
	}
	result->Attributes = p.attributes;
	result->Specs      = p.specifiers;
	result->ReturnType = p.ret_type;
	result->Params     = p.params;
	return result;
}

gen_CodeOpCast gen_def__operator_cast(gen_CodeTypename type, gen_Opts_def_operator_cast p)
{
	if (! null_check(gen_def_operator_cast, type))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (type->Type != CT_Typename)
	{
		gen_log_failure("gen::gen_def_operator_cast: type is not a typename - %s", gen_code_debug_str(type));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}

	gen_CodeOpCast result = (gen_CodeOpCast)gen_make_code();
	if (p.body)
	{
		result->Type = CT_Operator_Cast;

		if (p.body->Type != CT_Function_Body && p.body->Type != CT_Execution)
		{
			gen_log_failure("gen::gen_def_operator_cast: body is not of function body or execution type - %s", gen_code_debug_str(p.body));
			GEN_DEBUG_TRAP();
			return gen_InvalidCode;
		}
		result->Body = p.body;
	}
	else
	{
		result->Type = CT_Operator_Cast_Fwd;
	}
	result->Specs     = p.specs;
	result->ValueType = type;
	return result;
}

gen_CodeParams gen_def__param(gen_CodeTypename type, gen_Str name, gen_Opts_def_param p)
{
	if (! name_check(gen_def_param, name) || ! null_check(gen_def_param, type))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (type->Type != CT_Typename)
	{
		gen_log_failure("gen::gen_def_param: type is not a typename - %s", gen_code_debug_str(type));
		return gen_InvalidCode;
	}
	if (p.value && p.value->Type != CT_Untyped)
	{
		gen_log_failure("gen::gen_def_param: value is not untyped - %s", gen_code_debug_str(p.value));
		return gen_InvalidCode;
	}
	gen_CodeParams result = (gen_CodeParams)gen_make_code();
	result->Type          = CT_Parameters;
	result->Name          = gen_cache_str(name);
	result->ValueType     = type;
	result->Value         = p.value;
	result->NumEntries++;
	return result;
}

gen_CodePragma gen_def_pragma(gen_Str directive)
{
	if (directive.Len <= 0 || directive.Ptr == gen_nullptr)
	{
		gen_log_failure("gen::gen_def_comment: Invalid comment provided:");
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	gen_CodePragma result = (gen_CodePragma)gen_make_code();
	result->Type          = CT_Preprocess_Pragma;
	result->Content       = gen_cache_str(directive);
	return result;
}

gen_CodePreprocessCond gen_def_preprocess_cond(gen_EPreprocessCOnd type, gen_Str expr)
{
	if (expr.Len <= 0 || expr.Ptr == gen_nullptr)
	{
		gen_log_failure("gen::gen_def_comment: Invalid comment provided:");
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	gen_CodePreprocessCond result = (gen_CodePreprocessCond)gen_make_code();
	result->Content               = gen_cache_str(expr);
	switch (type)
	{
		case PreprocessCond_If:
			result->Type = CT_Preprocess_If;
			break;
		case PreprocessCond_IfDef:
			result->Type = CT_Preprocess_IfDef;
			break;
		case PreprocessCond_IfNotDef:
			result->Type = CT_Preprocess_IfNotDef;
			break;
		case PreprocessCond_ElIf:
			result->Type = CT_Preprocess_ElIf;
			break;
	}
	return result;
}

gen_CodeSpecifiers gen_def_specifier(gen_Specifier spec)
{
	gen_CodeSpecifiers result = (gen_CodeSpecifiers)gen_make_code();
	result->Type              = CT_Specifiers;
	gen_specifiers_append(result, spec);
	return result;
}

gen_CodeStruct gen_def__struct(gen_Str name, gen_Opts_def_struct p)
{
	if (p.attributes && p.attributes->Type != CT_PlatformAttributes)
	{
		gen_log_failure("gen::gen_def_struct: attributes was not a `PlatformAttributes` type - %s", gen_code_debug_str(gen_cast(gen_Code, p.attributes)));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (p.parent && p.parent->Type != CT_Typename)
	{
		gen_log_failure("gen::gen_def_struct: parent was not a `Struct` type - %s", gen_code_debug_str(p.parent));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (p.body && p.body->Type != CT_Struct_Body)
	{
		gen_log_failure("gen::gen_def_struct: body was not a Struct_Body type - %s", gen_code_debug_str(p.body));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}

	gen_CodeStruct result = (gen_CodeStruct)gen_make_code();
	result->ModuleFlags   = p.mflags;
	if (name.Len)
		result->Name = gen_cache_str(name);

	if (p.body)
	{
		result->Type = CT_Struct;
		result->Body = p.body;
	}
	else
	{
		result->Type = CT_Struct_Fwd;
	}
	result->Attributes   = p.attributes;
	result->Specs        = p.specifiers;
	result->ParentAccess = p.parent_access;
	result->ParentType   = p.parent;

	for (gen_s32 idx = 0; idx < p.num_interfaces; idx++)
	{
		gen_struct_add_interface(result, p.interfaces[idx]);
	}
	return result;
}

gen_CodeTemplate gen_def__template(gen_CodeParams params, gen_Code declaration, gen_Opts_def_template p)
{
	if (! null_check(gen_def_template, declaration))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (params && params->Type != CT_Parameters)
	{
		gen_log_failure("gen::gen_def_template: params is not of parameters type - %s", gen_code_debug_str(params));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	switch (declaration->Type)
	{
		case CT_Class:
		case CT_Function:
		case CT_Struct:
		case CT_Variable:
		case CT_Using:
			break;

		default:
			gen_log_failure(
			    "gen::gen_def_template: declaration is not of class, function, struct, variable, or using type - %s",
			    gen_code_debug_str(declaration)
			);
	}
	gen_CodeTemplate result = (gen_CodeTemplate)gen_make_code();
	result->Type            = CT_Template;
	result->ModuleFlags     = p.mflags;
	result->Params          = params;
	result->Declaration     = declaration;
	return result;
}

gen_CodeTypename gen_def__type(gen_Str name, gen_Opts_def_type p)
{
	if (! name_check(gen_def_type, name))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	gen_Code           gen_array_expr = p.gen_array_expr;
	gen_CodeSpecifiers specifiers     = p.specifiers;
	gen_CodeAttributes attributes     = p.attributes;
	if (p.attributes && p.attributes->Type != CT_PlatformAttributes)
	{
		gen_log_failure("gen::gen_def_type: attributes is not of attributes type - %s", gen_code_debug_str((gen_Code)p.attributes));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (p.specifiers && p.specifiers->Type != CT_Specifiers)
	{
		gen_log_failure("gen::gen_def_type: specifiers is not of specifiers type - %s", gen_code_debug_str((gen_Code)p.specifiers));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (p.gen_array_expr && p.gen_array_expr->Type != CT_Untyped)
	{
		gen_log_failure("gen::gen_def_type: arrayexpr is not of untyped type - %s", gen_code_debug_str((gen_Code)p.gen_array_expr));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	gen_CodeTypename result = (gen_CodeTypename)gen_make_code();
	result->Name            = gen_cache_str(name);
	result->Type            = CT_Typename;
	result->Attributes      = p.attributes;
	result->Specs           = p.specifiers;
	result->ArrExpr         = p.gen_array_expr;
	result->TypeTag         = p.type_tag;
	return result;
}

gen_CodeTypedef gen_def__typedef(gen_Str name, gen_Code type, gen_Opts_def_typedef p)
{
	if (! null_check(gen_def_typedef, type))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	switch (type->Type)
	{
		case CT_Class:
		case CT_Class_Fwd:
		case CT_Enum:
		case CT_Enum_Fwd:
		case CT_Enum_Class:
		case CT_Enum_Class_Fwd:
		case CT_Function_Fwd:
		case CT_Struct:
		case CT_Struct_Fwd:
		case CT_Union:
		case CT_Typename:
			break;
		default:
			gen_log_failure(
			    "gen::gen_def_typedef: type was not a Class, Enum, Function Forward, Struct, Typename, or Union - %s",
			    gen_code_debug_str((gen_Code)type)
			);
			GEN_DEBUG_TRAP();
			return gen_InvalidCode;
	}
	if (p.attributes && p.attributes->Type != CT_PlatformAttributes)
	{
		gen_log_failure("gen::gen_def_typedef: attributes was not a PlatformAttributes - %s", gen_code_debug_str((gen_Code)p.attributes));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}

	// Registering the type.
	gen_CodeTypename registered_type = gen_def_type(name);
	if (! registered_type)
	{
		gen_log_failure("gen::gen_def_typedef: failed to register type");
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}

	gen_CodeTypedef result = (gen_CodeTypedef)gen_make_code();
	result->Type           = CT_Typedef;
	result->ModuleFlags    = p.mflags;
	result->UnderlyingType = type;

	if (name.Len <= 0)
	{
		if (type->Type != CT_Untyped)
		{
			gen_log_failure("gen::gen_def_typedef: name was empty and type was not untyped (indicating its a function typedef) - %s", gen_code_debug_str(type));
			GEN_DEBUG_TRAP();
			return gen_InvalidCode;
		}
		result->Name       = gen_cache_str(type->Name);
		result->IsFunction = true;
	}
	else
	{
		result->Name       = gen_cache_str(name);
		result->IsFunction = false;
	}
	return result;
}

gen_CodeUnion gen_def__union(gen_Str name, gen_CodeBody body, gen_Opts_def_union p)
{
	if (! null_check(gen_def_union, body))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (body->Type != CT_Union_Body)
	{
		gen_log_failure("gen::gen_def_union: body was not a Union_Body type - %s", gen_code_debug_str(body));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (p.attributes && p.attributes->Type != CT_PlatformAttributes)
	{
		gen_log_failure("gen::gen_def_union: attributes was not a PlatformAttributes type - %s", gen_code_debug_str(p.attributes));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	gen_CodeUnion result = (gen_CodeUnion)gen_make_code();
	result->ModuleFlags  = p.mflags;
	result->Type         = CT_Union;
	result->Body         = body;
	result->Attributes   = p.attributes;
	if (name.Ptr)
		result->Name = gen_cache_str(name);
	return result;
}

gen_CodeUsing gen_def__using(gen_Str name, gen_CodeTypename type, gen_Opts_def_using p)
{
	if (! name_check(gen_def_using, name) || null_check(gen_def_using, type))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}

	gen_CodeTypename register_type = gen_def_type(name);
	if (! register_type)
	{
		gen_log_failure("gen::gen_def_using: failed to register type");
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (p.attributes && p.attributes->Type != CT_PlatformAttributes)
	{
		gen_log_failure("gen::gen_def_using: attributes was not a PlatformAttributes type - %s", gen_code_debug_str(p.attributes));
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	gen_CodeUsing result   = (gen_CodeUsing)gen_make_code();
	result->Name           = gen_cache_str(name);
	result->ModuleFlags    = p.mflags;
	result->Type           = CT_Using;
	result->UnderlyingType = type;
	result->Attributes     = p.attributes;
	return result;
}

gen_CodeUsing gen_def_using_namespace(gen_Str name)
{
	if (! name_check(gen_def_using_namespace, name))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	gen_CodeUsing result = (gen_CodeUsing)gen_make_code();
	result->Name         = gen_cache_str(name);
	result->Type         = CT_Using_Namespace;
	return result;
}

gen_CodeVar gen_def__variable(gen_CodeTypename type, gen_Str name, gen_Opts_def_variable p)
{
	if (! name_check(gen_def_variable, name) || ! null_check(gen_def_variable, type))
	{
		GEN_DEBUG_TRAP();
		return gen_InvalidCode;
	}
	if (p.attributes && p.attributes->Type != CT_PlatformAttributes)
	{
		gen_log_failure("gen::gen_def_variable: attributes was not a `PlatformAttributes` type - %s", gen_code_debug_str(p.attributes));
		return gen_InvalidCode;
	}
	if (p.specifiers && p.specifiers->Type != CT_Specifiers)
	{
		gen_log_failure("gen::gen_def_variable: specifiers was not a `Specifiers` type - %s", gen_code_debug_str(p.specifiers));
		return gen_InvalidCode;
	}
	if (type->Type != CT_Typename)
	{
		gen_log_failure("gen::gen_def_variable: type was not a Typename - %s", gen_code_debug_str(type));
		return gen_InvalidCode;
	}
	if (p.value && p.value->Type != CT_Untyped)
	{
		gen_log_failure("gen::gen_def_variable: value was not a `Untyped` type - %s", gen_code_debug_str(p.value));
		return gen_InvalidCode;
	}
	gen_CodeVar result  = (gen_CodeVar)gen_make_code();
	result->Name        = gen_cache_str(name);
	result->Type        = CT_Variable;
	result->ModuleFlags = p.mflags;
	result->ValueType   = type;
	result->Attributes  = p.attributes;
	result->Specs       = p.specifiers;
	result->Value       = p.value;
	return result;
}

#pragma region Helper Macros for gen_def_**_body functions

#define gen_def_body_start(Name_)                                                         \
	if (num <= 0)                                                                         \
	{                                                                                     \
		gen_log_failure("gen::" gen_stringize(Name_) ": num cannot be zero or negative"); \
		return gen_InvalidCode;                                                           \
	}

#define gen_def_body_code_array_start(Name_)                                               \
	if (num <= 0)                                                                          \
	{                                                                                      \
		gen_log_failure("gen::" gen_stringize(Name_) ": num cannot be zero or negative");  \
		return gen_InvalidCode;                                                            \
	}                                                                                      \
	if (codes == gen_nullptr)                                                              \
	{                                                                                      \
		gen_log_failure("gen::" gen_stringize(Name_) " : Provided a null array of codes"); \
		return gen_InvalidCode;                                                            \
	}

#pragma endregion Helper Macros for gen_def_** _body functions

gen_CodeBody gen_def_class_body(gen_s32 num, ...)
{
	gen_def_body_start(gen_def_class_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Class_Body;

	va_list va;
	va_start(va, num);
	do
	{
		gen_Code_POD pod   = va_arg(va, gen_Code_POD);
		gen_Code     entry = gen_pcast(gen_Code, pod);
		if (! entry)
		{
			gen_log_failure(
			    "gen::"
			    "gen_def_class_body"
			    ": Provided an null entry"
			);
			return gen_InvalidCode;
		}
		switch (entry->Type)
		{
		GEN_AST_BODY_CLASS_UNALLOWED_TYPES_CASES:
			gen_log_failure(
			    "gen::"
			    "gen_def_class_body"
			    ": Entry type is not allowed: %s",
			    gen_code_debug_str(entry)
			);
			return gen_InvalidCode;

			default:
				break;
		}
		gen_body_append(result, entry);
	} while (num--, num > 0);
	va_end(va);

	return result;
}

gen_CodeBody gen_def_class_body_arr(gen_s32 num, gen_Code* codes)
{
	gen_def_body_code_array_start(gen_def_class_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Function_Body;
	do
	{
		gen_Code entry = *codes;
		codes++;
		if (! entry)
		{
			gen_log_failure(
			    "gen::"
			    "gen_def_class_body"
			    ": Provided an null entry"
			);
			return gen_InvalidCode;
		}
		switch (entry->Type)
		{
		GEN_AST_BODY_CLASS_UNALLOWED_TYPES_CASES:
			gen_log_failure(
			    "gen::"
			    "gen_def_class_body"
			    ": Entry type is not allowed: %s",
			    gen_code_debug_str(entry)
			);
			return gen_InvalidCode;

			default:
				break;
		}
		gen_body_append(result, entry);
	} while (num--, num > 0);

	return result;
}

gen_CodeDefineParams gen_def_define_params(gen_s32 num, ...)
{
	gen_def_body_start(gen_def_define_params);

	va_list va;
	va_start(va, num);

	gen_Code_POD         pod   = va_arg(va, gen_Code_POD);
	gen_CodeDefineParams param = gen_pcast(gen_CodeDefineParams, pod);

	null_check(gen_def_define_params, param);
	if (param->Type != CT_Parameters_Define)
	{
		gen_log_failure("gen::gen_def_define_params: param %d is not a parameter for a preprocessor define", num - num + 1);
		return gen_InvalidCode;
	}

	gen_CodeDefineParams result = (gen_CodeDefineParams)gen_code_duplicate(param);
	while (--num)
	{
		pod   = va_arg(va, gen_Code_POD);
		param = gen_pcast(gen_CodeDefineParams, pod);
		if (param->Type != CT_Parameters_Define)
		{
			gen_log_failure("gen::gen_def_define_params: param %d is not a parameter for a preprocessor define", num - num + 1);
			return gen_InvalidCode;
		}
		gen_define_params_append(result, param);
	}
	va_end(va);

	return result;
}

gen_CodeDefineParams gen_def_define_params_arr(gen_s32 num, gen_CodeDefineParams* codes)
{
	gen_def_body_code_array_start(gen_def_define_params);

#define check_current(current)                                                                                         \
	if (current == gen_nullptr)                                                                                        \
	{                                                                                                                  \
		gen_log_failure("gen::gen_def_define_params: Provide a null code in codes array");                             \
		return gen_InvalidCode;                                                                                        \
	}                                                                                                                  \
	if (current->Type != CT_Parameters_Define)                                                                         \
	{                                                                                                                  \
		gen_log_failure(                                                                                               \
		    "gen::gen_def_define_params: gen_Code in coes array is not of paramter for preprocessor define type - %s", \
		    gen_code_debug_str(current)                                                                                \
		);                                                                                                             \
		return gen_InvalidCode;                                                                                        \
	}
	gen_CodeDefineParams current = (gen_CodeDefineParams)gen_code_duplicate(*codes);
	check_current(current);

	gen_CodeDefineParams result = (gen_CodeDefineParams)gen_make_code();
	result->Name                = current->Name;
	result->Type                = current->Type;
	while (codes++, current = *codes, num--, num > 0)
	{
		check_current(current);
		gen_define_params_append(result, current);
	}
#undef check_current

	return result;
}

gen_CodeBody gen_def_enum_body(gen_s32 num, ...)
{
	gen_def_body_start(gen_def_enum_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Enum_Body;

	va_list va;
	va_start(va, num);
	do
	{
		gen_Code_POD pod   = va_arg(va, gen_Code_POD);
		gen_Code     entry = gen_pcast(gen_Code, pod);
		if (! entry)
		{
			gen_log_failure("gen::gen_def_enum_body: Provided a null entry");
			return gen_InvalidCode;
		}
		if (entry->Type != CT_Untyped && entry->Type != CT_Comment)
		{
			gen_log_failure("gen::gen_def_enum_body: Entry type is not allowed - %s. Must be of untyped or comment type.", gen_code_debug_str(entry));
			return gen_InvalidCode;
		}
		gen_body_append(result, entry);
	} while (num--, num > 0);
	va_end(va);

	return (gen_CodeBody)result;
}

gen_CodeBody gen_def_enum_body_arr(gen_s32 num, gen_Code* codes)
{
	gen_def_body_code_array_start(gen_def_enum_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Enum_Body;
	do
	{
		gen_Code entry = *codes;
		if (! entry)
		{
			gen_log_failure("gen::gen_def_enum_body: Provided a null entry");
			return gen_InvalidCode;
		}
		if (entry->Type != CT_Untyped && entry->Type != CT_Comment)
		{
			gen_log_failure("gen::gen_def_enum_body: Entry type is not allowed: %s", gen_code_debug_str(entry));
			return gen_InvalidCode;
		}
		gen_body_append(result, entry);
	} while (codes++, num--, num > 0);

	return result;
}

gen_CodeBody gen_def_export_body(gen_s32 num, ...)
{
	gen_def_body_start(gen_def_export_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Export_Body;

	va_list va;
	va_start(va, num);
	do
	{
		gen_Code_POD pod   = va_arg(va, gen_Code_POD);
		gen_Code     entry = gen_pcast(gen_Code, pod);
		if (! entry)
		{
			gen_log_failure(
			    "gen::"
			    "gen_def_export_body"
			    ": Provided an null entry"
			);
			return gen_InvalidCode;
		}
		switch (entry->Type)
		{
		GEN_AST_BODY_EXPORT_UNALLOWED_TYPES_CASES:
			gen_log_failure(
			    "gen::"
			    "gen_def_export_body"
			    ": Entry type is not allowed: %s",
			    gen_code_debug_str(entry)
			);
			return gen_InvalidCode;

			default:
				break;
		}
		gen_body_append(result, entry);
	} while (num--, num > 0);
	va_end(va);

	return result;
}

gen_CodeBody gen_def_export_body_arr(gen_s32 num, gen_Code* codes)
{
	gen_def_body_code_array_start(gen_def_export_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Export_Body;
	do
	{
		gen_Code entry = *codes;
		codes++;
		if (! entry)
		{
			gen_log_failure(
			    "gen::"
			    "gen_def_export_body"
			    ": Provided an null entry"
			);
			return gen_InvalidCode;
		}
		switch (entry->Type)
		{
		GEN_AST_BODY_EXPORT_UNALLOWED_TYPES_CASES:
			gen_log_failure(
			    "gen::"
			    "gen_def_export_body"
			    ": Entry type is not allowed: %s",
			    gen_code_debug_str(entry)
			);
			return gen_InvalidCode;

			default:
				break;
		}
		gen_body_append(result, entry);
	} while (num--, num > 0);

	return result;
}

gen_CodeBody gen_def_extern_link_body(gen_s32 num, ...)
{
	gen_def_body_start(gen_def_extern_linkage_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Extern_Linkage_Body;

	va_list va;
	va_start(va, num);
	do
	{
		gen_Code_POD pod   = va_arg(va, gen_Code_POD);
		gen_Code     entry = gen_pcast(gen_Code, pod);
		if (! entry)
		{
			gen_log_failure(
			    "gen::"
			    "gen_def_extern_linkage_body"
			    ": Provided an null entry"
			);
			return gen_InvalidCode;
		}
		switch (entry->Type)
		{
		GEN_AST_BODY_EXTERN_LINKAGE_UNALLOWED_TYPES_CASES:
			gen_log_failure(
			    "gen::"
			    "gen_def_extern_linkage_body"
			    ": Entry type is not allowed: %s",
			    gen_code_debug_str(entry)
			);
			return gen_InvalidCode;

			default:
				break;
		}
		gen_body_append(result, entry);
	} while (num--, num > 0);
	va_end(va);

	return result;
}

gen_CodeBody gen_def_extern_link_body_arr(gen_s32 num, gen_Code* codes)
{
	gen_def_body_code_array_start(gen_def_extern_linkage_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Extern_Linkage_Body;
	do
	{
		gen_Code entry = *codes;
		codes++;
		if (! entry)
		{
			gen_log_failure(
			    "gen::"
			    "gen_def_extern_linkage_body"
			    ": Provided an null entry"
			);
			return gen_InvalidCode;
		}
		switch (entry->Type)
		{
		GEN_AST_BODY_EXTERN_LINKAGE_UNALLOWED_TYPES_CASES:
			gen_log_failure(
			    "gen::"
			    "gen_def_extern_linkage_body"
			    ": Entry type is not allowed: %s",
			    gen_code_debug_str(entry)
			);
			return gen_InvalidCode;

			default:
				break;
		}
		gen_body_append(result, entry);
	} while (num--, num > 0);

	return result;
}

gen_CodeBody gen_def_function_body(gen_s32 num, ...)
{
	gen_def_body_start(gen_def_function_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Function_Body;

	va_list va;
	va_start(va, num);
	do
	{
		gen_Code_POD pod   = va_arg(va, gen_Code_POD);
		gen_Code     entry = gen_pcast(gen_Code, pod);
		if (! entry)
		{
			gen_log_failure("gen::" gen_stringize(gen_def_function_body) ": Provided an null entry");
			return gen_InvalidCode;
		}
		switch (entry->Type)
		{
		GEN_AST_BODY_FUNCTION_UNALLOWED_TYPES_CASES:
			gen_log_failure("gen::" gen_stringize(gen_def_function_body) ": Entry type is not allowed: %s", gen_code_debug_str(entry));
			return gen_InvalidCode;

			default:
				break;
		}
		gen_body_append(result, entry);
	} while (num--, num > 0);
	va_end(va);

	return result;
}

gen_CodeBody gen_def_function_body_arr(gen_s32 num, gen_Code* codes)
{
	gen_def_body_code_array_start(gen_def_function_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Function_Body;
	do
	{
		gen_Code entry = *codes;
		codes++;
		if (! entry)
		{
			gen_log_failure(
			    "gen::"
			    "gen_def_function_body"
			    ": Provided an null entry"
			);
			return gen_InvalidCode;
		}
		switch (entry->Type)
		{
		GEN_AST_BODY_FUNCTION_UNALLOWED_TYPES_CASES:
			gen_log_failure(
			    "gen::"
			    "gen_def_function_body"
			    ": Entry type is not allowed: %s",
			    gen_code_debug_str(entry)
			);
			return gen_InvalidCode;

			default:
				break;
		}
		gen_body_append(result, entry);
	} while (num--, num > 0);

	return result;
}

gen_CodeBody gen_def_global_body(gen_s32 num, ...)
{
	gen_def_body_start(gen_def_global_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Global_Body;

	va_list va;
	va_start(va, num);
	do
	{
		gen_Code_POD pod   = va_arg(va, gen_Code_POD);
		gen_Code     entry = gen_pcast(gen_Code, pod);
		if (! entry)
		{
			gen_log_failure(
			    "gen::"
			    "gen_def_global_body"
			    ": Provided an null entry"
			);
			return gen_InvalidCode;
		}
		switch (entry->Type)
		{
			case CT_Global_Body:
				// result.gen_body_append( entry.gen_code_cast<gen_CodeBody>() ) ;
				gen_body_append_body(result, gen_cast(gen_CodeBody, entry));
				continue;

			GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES_CASES:
				gen_log_failure(
				    "gen::"
				    "gen_def_global_body"
				    ": Entry type is not allowed: %s",
				    gen_code_debug_str(entry)
				);
				return gen_InvalidCode;

			default:
				break;
		}
		gen_body_append(result, entry);
	} while (num--, num > 0);
	va_end(va);

	return result;
}

gen_CodeBody gen_def_global_body_arr(gen_s32 num, gen_Code* codes)
{
	gen_def_body_code_array_start(gen_def_global_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Global_Body;
	do
	{
		gen_Code entry = *codes;
		codes++;
		if (! entry)
		{
			gen_log_failure(
			    "gen::"
			    "gen_def_global_body"
			    ": Provided an null entry"
			);
			return gen_InvalidCode;
		}
		switch (entry->Type)
		{
			case CT_Global_Body:
				gen_body_append_body(result, gen_cast(gen_CodeBody, entry));
				continue;

			GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES_CASES:
				gen_log_failure(
				    "gen::"
				    "gen_def_global_body"
				    ": Entry type is not allowed: %s",
				    gen_code_debug_str(entry)
				);
				return gen_InvalidCode;

			default:
				break;
		}

		gen_body_append(result, entry);
	} while (num--, num > 0);

	return result;
}

gen_CodeBody gen_def_namespace_body(gen_s32 num, ...)
{
	gen_def_body_start(gen_def_namespace_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Namespace_Body;

	va_list va;
	va_start(va, num);
	do
	{
		gen_Code_POD pod   = va_arg(va, gen_Code_POD);
		gen_Code     entry = gen_pcast(gen_Code, pod);
		if (! entry)
		{
			gen_log_failure(
			    "gen::"
			    "gen_def_namespace_body"
			    ": Provided an null entry"
			);
			return gen_InvalidCode;
		}
		switch (entry->Type)
		{
		GEN_AST_BODY_NAMESPACE_UNALLOWED_TYPES_CASES:
			gen_log_failure(
			    "gen::"
			    "gen_def_namespace_body"
			    ": Entry type is not allowed: %s",
			    gen_code_debug_str(entry)
			);
			return gen_InvalidCode;

			default:
				break;
		}
		gen_body_append(result, entry);
	} while (num--, num > 0);
	va_end(va);

	return result;
}

gen_CodeBody gen_def_namespace_body_arr(gen_s32 num, gen_Code* codes)
{
	gen_def_body_code_array_start(gen_def_namespace_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Global_Body;
	do
	{
		gen_Code entry = *codes;
		codes++;
		if (! entry)
		{
			gen_log_failure(
			    "gen::"
			    "gen_def_namespace_body"
			    ": Provided an null entry"
			);
			return gen_InvalidCode;
		}
		switch (entry->Type)
		{
		GEN_AST_BODY_NAMESPACE_UNALLOWED_TYPES_CASES:
			gen_log_failure(
			    "gen::"
			    "gen_def_namespace_body"
			    ": Entry type is not allowed: %s",
			    gen_code_debug_str(entry)
			);
			return gen_InvalidCode;

			default:
				break;
		}
		gen_body_append(result, entry);
	} while (num--, num > 0);

	return result;
}

gen_CodeParams gen_def_params(gen_s32 num, ...)
{
	gen_def_body_start(gen_def_params);

	va_list va;
	va_start(va, num);

	gen_Code_POD   pod   = va_arg(va, gen_Code_POD);
	gen_CodeParams param = gen_pcast(gen_CodeParams, pod);

	null_check(gen_def_params, param);
	if (param->Type != CT_Parameters)
	{
		gen_log_failure("gen::gen_def_params: param %d is not a Parameters", num - num + 1);
		return gen_InvalidCode;
	}

	gen_CodeParams result = (gen_CodeParams)gen_code_duplicate(param);
	while (--num)
	{
		pod   = va_arg(va, gen_Code_POD);
		param = gen_pcast(gen_CodeParams, pod);
		if (param->Type != CT_Parameters)
		{
			gen_log_failure("gen::gen_def_params: param %d is not a Parameters", num - num + 1);
			return gen_InvalidCode;
		}
		gen_params_append(result, param);
	}
	va_end(va);

	return result;
}

gen_CodeParams gen_def_params_arr(gen_s32 num, gen_CodeParams* codes)
{
	gen_def_body_code_array_start(gen_def_params);

#define check_current(current)                                                                                                    \
	if (current == gen_nullptr)                                                                                                   \
	{                                                                                                                             \
		gen_log_failure("gen::gen_def_params: Provide a null code in codes array");                                               \
		return gen_InvalidCode;                                                                                                   \
	}                                                                                                                             \
	if (current->Type != CT_Parameters)                                                                                           \
	{                                                                                                                             \
		gen_log_failure("gen::gen_def_params: gen_Code in coes array is not of paramter type - %s", gen_code_debug_str(current)); \
		return gen_InvalidCode;                                                                                                   \
	}
	gen_CodeParams current = (gen_CodeParams)gen_code_duplicate(*codes);
	check_current(current);

	gen_CodeParams result = (gen_CodeParams)gen_make_code();
	result->Name          = current->Name;
	result->Type          = current->Type;
	result->ValueType     = current->ValueType;
	while (codes++, current = *codes, num--, num > 0)
	{
		check_current(current);
		gen_params_append(result, current);
	}
#undef check_current

	return result;
}

gen_CodeSpecifiers gen_def_specifiers(gen_s32 num, ...)
{
	if (num <= 0)
	{
		gen_log_failure("gen::gen_def_specifiers: num cannot be zero or less");
		return gen_InvalidCode;
	}
	if (num > gen_AST_ArrSpecs_Cap)
	{
		gen_log_failure("gen::gen_def_specifiers: num of speciifers to define gen_AST larger than gen_AST specicifier capacity - %d", num);
		return gen_InvalidCode;
	}
	gen_CodeSpecifiers result = (gen_CodeSpecifiers)gen_make_code();
	result->Type              = CT_Specifiers;

	va_list va;
	va_start(va, num);
	do
	{
		gen_Specifier type = (gen_Specifier)va_arg(va, int);
		gen_specifiers_append(result, type);
	} while (--num, num);
	va_end(va);

	return result;
}

gen_CodeSpecifiers gen_def_specifiers_arr(gen_s32 num, gen_Specifier* specs)
{
	if (num <= 0)
	{
		gen_log_failure("gen::gen_def_specifiers: num cannot be zero or less");
		return gen_InvalidCode;
	}
	if (num > gen_AST_ArrSpecs_Cap)
	{
		gen_log_failure("gen::gen_def_specifiers: num of speciifers to define gen_AST larger than gen_AST specicifier capacity - %d", num);
		return gen_InvalidCode;
	}
	gen_CodeSpecifiers result = (gen_CodeSpecifiers)gen_make_code();
	result->Type              = CT_Specifiers;

	gen_s32 idx               = 0;
	do
	{
		gen_specifiers_append(result, specs[idx]);
		idx++;
	} while (--num, num);

	return result;
}

gen_CodeBody gen_def_struct_body(gen_s32 num, ...)
{
	gen_def_body_start(gen_def_struct_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Struct_Body;

	va_list va;
	va_start(va, num);
	do
	{
		gen_Code_POD pod   = va_arg(va, gen_Code_POD);
		gen_Code     entry = gen_pcast(gen_Code, pod);
		if (! entry)
		{
			gen_log_failure(
			    "gen::"
			    "gen_def_struct_body"
			    ": Provided an null entry"
			);
			return gen_InvalidCode;
		}
		switch (entry->Type)
		{
		GEN_AST_BODY_STRUCT_UNALLOWED_TYPES_CASES:
			gen_log_failure(
			    "gen::"
			    "gen_def_struct_body"
			    ": Entry type is not allowed: %s",
			    gen_code_debug_str(entry)
			);
			return gen_InvalidCode;

			default:
				break;
		}
		gen_body_append(result, entry);
	} while (num--, num > 0);
	va_end(va);

	return result;
}

gen_CodeBody gen_def_struct_body_arr(gen_s32 num, gen_Code* codes)
{
	gen_def_body_code_array_start(gen_def_struct_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Struct_Body;
	do
	{
		gen_Code entry = *codes;
		codes++;
		if (! entry)
		{
			gen_log_failure(
			    "gen::"
			    "gen_def_struct_body"
			    ": Provided an null entry"
			);
			return gen_InvalidCode;
		}
		switch (entry->Type)
		{
		GEN_AST_BODY_STRUCT_UNALLOWED_TYPES_CASES:
			gen_log_failure(
			    "gen::"
			    "gen_def_struct_body"
			    ": Entry type is not allowed: %s",
			    gen_code_debug_str(entry)
			);
			return gen_InvalidCode;

			default:
				break;
		}
		gen_body_append(result, entry);
	} while (num--, num > 0);

	return result;
}

gen_CodeBody gen_def_union_body(gen_s32 num, ...)
{
	gen_def_body_start(gen_def_union_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Union_Body;

	va_list va;
	va_start(va, num);
	do
	{
		gen_Code_POD pod   = va_arg(va, gen_Code_POD);
		gen_Code     entry = gen_pcast(gen_Code, pod);
		if (! entry)
		{
			gen_log_failure("gen::gen_def_union_body: Provided a null entry");
			return gen_InvalidCode;
		}
		if (entry->Type != CT_Untyped && entry->Type != CT_Comment)
		{
			gen_log_failure("gen::gen_def_union_body: Entry type is not allowed - %s. Must be of untyped or comment type.", gen_code_debug_str(entry));
			return gen_InvalidCode;
		}
		gen_body_append(result, entry);
	} while (num--, num > 0);
	va_end(va);

	return result;
}

gen_CodeBody gen_def_union_body_arr(gen_s32 num, gen_Code* codes)
{
	gen_def_body_code_array_start(gen_def_union_body);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Union_Body;
	do
	{
		gen_Code entry = *codes;
		if (! entry)
		{
			gen_log_failure("gen::gen_def_union_body: Provided a null entry");
			return gen_InvalidCode;
		}
		if (entry->Type != CT_Untyped && entry->Type != CT_Comment)
		{
			gen_log_failure("gen::gen_def_union_body: Entry type is not allowed: %s", gen_code_debug_str(entry));
			return gen_InvalidCode;
		}
		gen_body_append(result, entry);
	} while (codes++, num--, num > 0);

	return (gen_CodeBody)result;
}

#undef name_check
#undef null_check
#undef gen_def_body_start
#undef gen_def_body_code_array_start

#pragma endregion Upfront

#pragma region Parsing


gen_StrBuilder gen_tok_to_strbuilder(gen_Token tok)
{
	gen_StrBuilder result   = gen_strbuilder_make_reserve(gen__ctx->Allocator_Temp, gen_kilobytes(4));
	gen_Str        type_str = gen_toktype_to_str(tok.Type);

	gen_strbuilder_append_fmt(
	    &result,
	    "Line: %d Column: %d, Type: %.*s Content: %.*s",
	    tok.Line,
	    tok.Column,
	    type_str.Len,
	    type_str.Ptr,
	    tok.Text.Len,
	    tok.Text.Ptr
	);
	return result;
}

bool gen_lex__eat(gen_TokArray* self, gen_TokType type);

gen_Token* gen_lex_current(gen_TokArray* self, bool skip_formatting)
{
	if (skip_formatting)
	{
		while (self->Arr[self->Idx].Type == Tok_NewLine || self->Arr[self->Idx].Type == Tok_Comment)
			self->Idx++;
	}
	return &self->Arr[self->Idx];
}

gen_Token* gen_lex_peek(gen_TokArray self, bool skip_formatting)
{
	gen_s32 idx = self.Idx;
	if (skip_formatting)
	{
		while (self.Arr[idx].Type == Tok_NewLine)
			idx++;

		return &self.Arr[idx];
	}
	return &self.Arr[idx];
}

gen_Token* gen_lex_previous(gen_TokArray self, bool skip_formatting)
{
	gen_s32 idx = self.Idx;
	if (skip_formatting)
	{
		while (self.Arr[idx].Type == Tok_NewLine)
			idx--;

		return &self.Arr[idx];
	}
	return &self.Arr[idx - 1];
}

gen_Token* gen_lex_next(gen_TokArray self, bool skip_formatting)
{
	gen_s32 idx = self.Idx;
	if (skip_formatting)
	{
		while (self.Arr[idx].Type == Tok_NewLine)
			idx++;

		return &self.Arr[idx + 1];
	}
	return &self.Arr[idx + 1];
}

enum
{
	Lex_Continue,
	Lex_ReturnNull,
};

gen_forceinline void lexer_move_forward(gen_LexContext* ctx)
{
	if (*ctx->scanner == '\n')
	{
		ctx->line   += 1;
		ctx->column  = 1;
	}
	else
	{
		++ctx->column;
	}
	--ctx->left;
	++ctx->scanner;
}

#define move_forward() lexer_move_forward(ctx)

gen_forceinline void lexer_skip_whitespace(gen_LexContext* ctx)
{
	while (ctx->left && gen_char_is_space(*ctx->scanner))
		move_forward();
}

#define skip_whitespace() lexer_skip_whitespace(ctx)

gen_forceinline void lexer_end_line(gen_LexContext* ctx)
{
	while (ctx->left && (*ctx->scanner) == ' ')
		move_forward();

	if (ctx->left && (*ctx->scanner) == '\r')
	{
		move_forward();
		move_forward();
	}
	else if (ctx->left && (*ctx->scanner) == '\n')
		move_forward();
}

#define gen_end_line() lexer_end_line(ctx)

// TODO(Ed): We need to to attempt to recover from a gen_lex failure?
gen_s32 gen_lex_preprocessor_define(gen_LexContext* ctx)
{
	gen_Token name = {
		{ ctx->scanner, 1 },
		Tok_Identifier,
		ctx->line,
		ctx->column,
		TF_Preprocess
	};
	move_forward();

	while (ctx->left && (gen_char_is_alphanumeric((*ctx->scanner)) || (*ctx->scanner) == '_'))
	{
		move_forward();
		name.Text.Len++;
	}

	gen_Specifier spec          = gen_str_to_specifier(name.Text);
	gen_TokType   attrib        = gen_str_to_toktype(name.Text);
	gen_b32       not_specifier = spec == Spec_Invalid;
	gen_b32       not_attribute = attrib <= Tok___Attributes_Start;

	gen_Macro  macro            = { name.Text, MT_Expression, (gen_MacroFlags)0 };
	gen_Macro* registered_macro = lookup_macro(name.Text);

	if (registered_macro == gen_nullptr && not_specifier && not_attribute)
	{
		gen_log_fmt(
		    "Warning: '%S' was not registered before the lexer processed its #define directive, it will be registered as a expression macro\n",
		    name.Text
		);
		// GEN_DEBUG_TRAP();
	}
	gen_array_append(gen__ctx->gen_Lexer_Tokens, name);

	if (ctx->left && (*ctx->scanner) == '(')
	{
		if (registered_macro && ! gen_macro_is_functional(*registered_macro))
		{
			gen_log_fmt(
			    "Warning: %S registered macro is not flagged as functional yet the definition detects opening parenthesis '(' for arguments\n",
			    name.Text
			);
			// GEN_DEBUG_TRAP();
		}
		else
		{
			macro.Flags |= MF_Functional;
		}

		gen_Token opening_paren = {
			{ ctx->scanner, 1 },
			Tok_Paren_Open,
			ctx->line,
			ctx->column,
			TF_Preprocess
		};
		gen_array_append(gen__ctx->gen_Lexer_Tokens, opening_paren);
		move_forward();

		gen_Token last_parameter = {};
		// We need to tokenize the define's arguments now:
		while (ctx->left && *ctx->scanner != ')')
		{
			skip_whitespace();

			gen_Str possible_varadic = { ctx->scanner, 3 };
			if (ctx->left > 3 && gen_str_are_equal(txt("..."), possible_varadic))
			{
				gen_Token parameter = {
					{ ctx->scanner, 3 },
					Tok_Preprocess_Define_Param,
					ctx->line,
					ctx->column,
					TF_Preprocess
				};
				move_forward();
				move_forward();
				move_forward();

				gen_array_append(gen__ctx->gen_Lexer_Tokens, parameter);
				skip_whitespace();
				last_parameter = parameter;

				while ((*ctx->scanner) == '\\')
				{
					move_forward();
					skip_whitespace();
				}
				if (*ctx->scanner != ')')
				{
					gen_log_failure(
					    "gen_lex_preprocessor_define(%d, %d): Expected a ')' after '...' (varaidc macro param) %S\n",
					    ctx->line,
					    ctx->column,
					    name.Text
					);
					return Lex_ReturnNull;
				}
				break;
			}
			else if ((*ctx->scanner) == '\\')
			{
				move_forward();
				skip_whitespace();
				continue;
			}
			else if (gen_char_is_alpha((*ctx->scanner)) || (*ctx->scanner) == '_')
			{
				gen_Token parameter = {
					{ ctx->scanner, 1 },
					Tok_Preprocess_Define_Param,
					ctx->line,
					ctx->column,
					TF_Preprocess
				};
				move_forward();

				while (ctx->left && (gen_char_is_alphanumeric((*ctx->scanner)) || (*ctx->scanner) == '_'))
				{
					move_forward();
					parameter.Text.Len++;
				}
				gen_array_append(gen__ctx->gen_Lexer_Tokens, parameter);
				skip_whitespace();
				last_parameter = parameter;
			}
			else
			{
				gen_log_failure(
				    "gen_lex_preprocessor_define(%d, %d): Expected a '_' or alpha character for a parameter name for %S\n",
				    ctx->line,
				    ctx->column,
				    name.Text
				);
				return Lex_ReturnNull;
			}

			if (*ctx->scanner == ')')
				break;

			// There should be a comma
			if (*ctx->scanner != ',')
			{
				gen_log_failure(
				    "gen_lex_preprocessor_define(%d, %d): Expected a comma after parameter %S for %S\n",
				    ctx->line,
				    ctx->column,
				    last_parameter.Text,
				    name.Text
				);
				return Lex_ReturnNull;
			}
			gen_Token comma = {
				{ ctx->scanner, 1 },
				Tok_Comma,
				ctx->line,
				ctx->column,
				TF_Preprocess
			};
			gen_array_append(gen__ctx->gen_Lexer_Tokens, comma);
			move_forward();
		}

		if (*ctx->scanner != ')')
		{
			gen_log_failure(
			    "gen_lex_preprocessor_define(%d, %d): Expected a ')' after last_parameter %S for %S (ran out of characters...)\n",
			    ctx->line,
			    ctx->column,
			    last_parameter.Text,
			    name.Text
			);
			return Lex_ReturnNull;
		}
		gen_Token closing_paren = {
			{ ctx->scanner, 1 },
			Tok_Paren_Close,
			ctx->line,
			ctx->column,
			TF_Preprocess
		};
		gen_array_append(gen__ctx->gen_Lexer_Tokens, closing_paren);
		move_forward();
	}
	else if (registered_macro && gen_macro_is_functional(*registered_macro))
	{
		if (registered_macro && ! gen_macro_is_functional(*registered_macro))
		{
			gen_log_fmt(
			    "Warning: %S registered macro is flagged as functional yet the definition detects no opening parenthesis '(' for arguments\n",
			    name.Text
			);
			GEN_DEBUG_TRAP();
		}
	}

	if (registered_macro == gen_nullptr)
	{
		gen_register_macro(macro);
	}

	// Define's content handled by gen_lex_preprocessor_directive (the original caller of this)
	return Lex_Continue;
}

// TODO(Ed): We need to to attempt to recover from a gen_lex failure?
gen_s32 gen_lex_preprocessor_directive(gen_LexContext* ctx)
{
	char const* gen_hash = ctx->scanner;
	gen_Token   hash_tok = {
        { gen_hash, 1 },
        Tok_Preprocess_Hash,
        ctx->line,
        ctx->column,
        TF_Preprocess
	};
	gen_array_append(gen__ctx->gen_Lexer_Tokens, hash_tok);

	move_forward();
	skip_whitespace();

	ctx->token.Text.Ptr = ctx->scanner;
	while (ctx->left && ! gen_char_is_space((*ctx->scanner)))
	{
		move_forward();
		ctx->token.Text.Len++;
	}

	ctx->token.Type      = gen_str_to_toktype(ctx->token.Text);

	bool is_preprocessor = ctx->token.Type >= Tok_Preprocess_Define && ctx->token.Type <= Tok_Preprocess_Pragma;
	if (! is_preprocessor)
	{
		ctx->token.Type = Tok_Preprocess_Unsupported;

		// Its an unsupported directive, skip it
		gen_s32 within_string = false;
		gen_s32 within_char   = false;
		while (ctx->left)
		{
			if (*ctx->scanner == '"' && ! within_char)
				within_string ^= true;

			if (*ctx->scanner == '\'' && ! within_string)
				within_char ^= true;

			if (*ctx->scanner == '\\' && ! within_string && ! within_char)
			{
				move_forward();
				ctx->token.Text.Len++;

				if ((*ctx->scanner) == '\r')
				{
					move_forward();
					ctx->token.Text.Len++;
				}

				if ((*ctx->scanner) == '\n')
				{
					move_forward();
					ctx->token.Text.Len++;
					continue;
				}
				else
				{
					gen_log_failure(
					    "gen::Parser::gen_lex: Invalid escape sequence '\\%c' (%d, %d)"
					    " in preprocessor directive (%d, %d)\n%.100s",
					    (*ctx->scanner),
					    ctx->line,
					    ctx->column,
					    ctx->token.Line,
					    ctx->token.Column,
					    ctx->token.Text
					);
					break;
				}
			}

			if ((*ctx->scanner) == '\r')
			{
				move_forward();
				ctx->token.Text.Len++;
			}

			if ((*ctx->scanner) == '\n')
			{
				move_forward();
				ctx->token.Text.Len++;
				break;
			}

			move_forward();
			ctx->token.Text.Len++;
		}

		ctx->token.Text.Len = ctx->token.Text.Len + ctx->token.Text.Ptr - gen_hash;
		ctx->token.Text.Ptr = gen_hash;
		gen_array_append(gen__ctx->gen_Lexer_Tokens, ctx->token);
		return Lex_Continue;    // Skip found token, its all handled here.
	}

	if (ctx->token.Type == Tok_Preprocess_Else || ctx->token.Type == Tok_Preprocess_EndIf)
	{
		ctx->token.Flags |= TF_Preprocess_Cond;
		gen_array_append(gen__ctx->gen_Lexer_Tokens, ctx->token);
		gen_end_line();
		return Lex_Continue;
	}
	else if (ctx->token.Type >= Tok_Preprocess_If && ctx->token.Type <= Tok_Preprocess_ElIf)
	{
		ctx->token.Flags |= TF_Preprocess_Cond;
	}

	gen_array_append(gen__ctx->gen_Lexer_Tokens, ctx->token);

	skip_whitespace();

	if (ctx->token.Type == Tok_Preprocess_Define)
	{
		gen_u32 result = gen_lex_preprocessor_define(ctx);    // handles: #define <name>( <params> ) - define's content handled later on within this scope.
		if (result != Lex_Continue)
			return Lex_ReturnNull;
	}

	gen_Token gen_preprocess_content = {
		{ ctx->scanner, 0 },
		Tok_Preprocess_Content,
		ctx->line,
		ctx->column,
		TF_Preprocess
	};

	if (ctx->token.Type == Tok_Preprocess_Include)
	{
		gen_preprocess_content.Type = Tok_String;

		if ((*ctx->scanner) != '"' && (*ctx->scanner) != '<')
		{
			gen_StrBuilder directive_str =
			    gen_strbuilder_fmt_buf(gen__ctx->Allocator_Temp, "%.*s", gen_min(80, ctx->left + gen_preprocess_content.Text.Len), ctx->token.Text.Ptr);

			gen_log_failure(
			    "gen::Parser::gen_lex: Expected '\"' or '<' after #include, not '%c' (%d, %d)\n%s",
			    (*ctx->scanner),
			    gen_preprocess_content.Line,
			    gen_preprocess_content.Column,
			    (char*)directive_str
			);
			return Lex_ReturnNull;
		}
		move_forward();
		gen_preprocess_content.Text.Len++;

		while (ctx->left && (*ctx->scanner) != '"' && (*ctx->scanner) != '>')
		{
			move_forward();
			gen_preprocess_content.Text.Len++;
		}

		move_forward();
		gen_preprocess_content.Text.Len++;

		if ((*ctx->scanner) == '\r' && ctx->scanner[1] == '\n')
		{
			move_forward();
			move_forward();
		}
		else if ((*ctx->scanner) == '\n')
		{
			move_forward();
		}

		gen_array_append(gen__ctx->gen_Lexer_Tokens, gen_preprocess_content);
		return Lex_Continue;    // Skip found token, its all handled here.
	}

	gen_s32 within_string = false;
	gen_s32 within_char   = false;

	// Consume preprocess content
	while (ctx->left)
	{
		if ((*ctx->scanner) == '"' && ! within_char)
			within_string ^= true;

		if ((*ctx->scanner) == '\'' && ! within_string)
			within_char ^= true;

		if ((*ctx->scanner) == '\\' && ! within_string && ! within_char)
		{
			move_forward();
			gen_preprocess_content.Text.Len++;

			if ((*ctx->scanner) == '\r')
			{
				move_forward();
				gen_preprocess_content.Text.Len++;
			}

			if ((*ctx->scanner) == '\n')
			{
				move_forward();
				gen_preprocess_content.Text.Len++;
				continue;
			}
			else
			{
				gen_StrBuilder directive_str = gen_strbuilder_make_length(gen__ctx->Allocator_Temp, ctx->token.Text.Ptr, ctx->token.Text.Len);
				gen_StrBuilder content_str   = gen_strbuilder_fmt_buf(
                    gen__ctx->Allocator_Temp,
                    "%.*s",
                    gen_min(400, ctx->left + gen_preprocess_content.Text.Len),
                    gen_preprocess_content.Text.Ptr
                );

				gen_log_failure(
				    "gen::Parser::gen_lex: Invalid escape sequence '\\%c' (%d, %d)"
				    " in preprocessor directive '%s' (%d, %d)\n%s",
				    (*ctx->scanner),
				    ctx->line,
				    ctx->column,
				    directive_str,
				    gen_preprocess_content.Line,
				    gen_preprocess_content.Column,
				    content_str
				);
				return Lex_ReturnNull;
				break;
			}
		}

		if ((*ctx->scanner) == '\r')
		{
			break;
			//move_forward();
		}

		if ((*ctx->scanner) == '\n')
		{
			//move_forward();
			break;
		}

		move_forward();
		gen_preprocess_content.Text.Len++;
	}

	gen_array_append(gen__ctx->gen_Lexer_Tokens, gen_preprocess_content);
	return Lex_Continue;    // Skip found token, its all handled here.
}

void gen_lex_found_token(gen_LexContext* ctx)
{
	if (ctx->token.Type != Tok_Invalid)
	{
		gen_array_append(gen__ctx->gen_Lexer_Tokens, ctx->token);
		return;
	}

	gen_TokType type = gen_str_to_toktype(ctx->token.Text);

	if (type == Tok_Preprocess_Define || type == Tok_Preprocess_Include)
	{
		ctx->token.Flags |= TF_Identifier;
	}

	if (type <= Tok_Access_Public && type >= Tok_Access_Private)
	{
		ctx->token.Flags |= TF_AccessSpecifier;
	}
	if (type > Tok___Attributes_Start)
	{
		ctx->token.Flags |= TF_Attribute;
	}
	if (type == Tok_Decl_Extern_Linkage)
	{
		skip_whitespace();

		if ((*ctx->scanner) != '"')
		{
			type              = Tok_Spec_Extern;
			ctx->token.Flags |= TF_Specifier;
		}

		ctx->token.Type = type;
		gen_array_append(gen__ctx->gen_Lexer_Tokens, ctx->token);
		return;
	}
	if ((type <= Tok_Star && type >= Tok_Spec_Alignas) || type == Tok_Ampersand || type == Tok_Ampersand_DBL)
	{
		ctx->token.Type   = type;
		ctx->token.Flags |= TF_Specifier;
		gen_array_append(gen__ctx->gen_Lexer_Tokens, ctx->token);
		return;
	}
	if (type != Tok_Invalid)
	{
		ctx->token.Type = type;
		gen_array_append(gen__ctx->gen_Lexer_Tokens, ctx->token);
		return;
	}

	gen_Macro* macro             = lookup_macro(ctx->token.Text);
	gen_b32    has_args          = ctx->left && (*ctx->scanner) == '(';
	gen_b32    resolved_to_macro = false;
	if (macro)
	{
		ctx->token.Type       = gen_macrotype__to_toktype(macro->Type);
		gen_b32 is_functional = gen_macro_is_functional(*macro);
		resolved_to_macro     = has_args ? is_functional : ! is_functional;
		if (! resolved_to_macro && GEN_BUILD_DEBUG)
		{
			gen_log_fmt(
			    "Info(%d, %d): %S identified as a macro but usage here does not resolve to one (interpreting as identifier)\n",
			    ctx->token.Line,
			    ctx->token.Line,
			    macro->Name
			);
		}
	}
	if (resolved_to_macro)
	{
		// TODO(Ed): When we introduce a macro gen_AST (and expression support), we'll properly gen_lex this section.
		// Want to ignore any arguments the define may have as they can be execution expressions.
		if (has_args)
		{
			ctx->token.Flags |= TF_Macro_Functional;
		}
		if (gen_bitfield_is_set(gen_MacroFlags, macro->Flags, MF_Allow_As_Attribute))
		{
			ctx->token.Flags |= TF_Attribute;
		}
		if (gen_bitfield_is_set(gen_MacroFlags, macro->Flags, MF_Allow_As_Specifier))
		{
			ctx->token.Flags |= TF_Specifier;
		}
	}
	else
	{
		ctx->token.Type = Tok_Identifier;
	}

	gen_array_append(gen__ctx->gen_Lexer_Tokens, ctx->token);
}

// TODO(Ed): We need to to attempt to recover from a gen_lex failure?
gen_neverinline gen_TokArray gen_lex(gen_Str content)
{
	gen_LexContext  c;
	gen_LexContext* ctx     = &c;
	c.content               = content;
	c.left                  = content.Len;
	c.scanner               = content.Ptr;

	char const* word        = c.scanner;
	gen_s32     word_length = 0;

	c.line                  = 1;
	c.column                = 1;

	skip_whitespace();
	if (c.left <= 0)
	{
		gen_log_failure("gen::gen_lex: no tokens found (only whitespace provided)");
		gen_TokArray null_array = {};
		return null_array;
	}

	gen_array_clear(gen__ctx->gen_Lexer_Tokens);

	gen_b32 gen_preprocess_args = true;

	while (c.left)
	{
#if 0
		if (Tokens.num())
		{
			gen_log_fmt("\nLastTok: %SB", Tokens.back().to_strbuilder());
		}
#endif

		{
			gen_Token thanks_c = {
				{ c.scanner, 0 },
				Tok_Invalid,
				c.line,
				c.column,
				TF_Null
			};
			c.token = thanks_c;
		}

		bool is_define = false;

		if (c.column == 1)
		{
			if ((*ctx->scanner) == '\r')
			{
				move_forward();
				c.token.Text.Len = 1;
			}

			if ((*ctx->scanner) == '\n')
			{
				move_forward();

				c.token.Type = Tok_NewLine;
				c.token.Text.Len++;

				gen_array_append(gen__ctx->gen_Lexer_Tokens, c.token);
				continue;
			}
		}

		c.token.Text.Len = 0;

		skip_whitespace();
		if (c.left <= 0)
			break;

		switch ((*ctx->scanner))
		{
			case '#':
			{
				gen_s32 result = gen_lex_preprocessor_directive(ctx);
				switch (result)
				{
					case Lex_Continue:
					{
						//gen_TokType last_type = Tokens[gen_array_get_header(Tokens)->Num - 2].Type;
						//if ( last_type == Tok_Preprocess_Pragma )
						{
							{
								gen_Token thanks_c = {
									{ c.scanner, 0 },
									Tok_Invalid,
									c.line,
									c.column,
									TF_Null
								};
								c.token = thanks_c;
							}
							if ((*ctx->scanner) == '\r')
							{
								move_forward();
								c.token.Text.Len = 1;
							}

							if ((*ctx->scanner) == '\n')
							{
								c.token.Type = Tok_NewLine;
								c.token.Text.Len++;
								move_forward();

								gen_array_append(gen__ctx->gen_Lexer_Tokens, c.token);
							}
						}
						continue;
					}

					case Lex_ReturnNull:
					{
						gen_TokArray gen_tok_array = {};
						return gen_tok_array;
					}
				}
			}
			case '.':
			{
				gen_Str text  = { c.scanner, 1 };
				c.token.Text  = text;
				c.token.Type  = Tok_Access_MemberSymbol;
				c.token.Flags = TF_AccessOperator;

				if (c.left)
				{
					move_forward();
				}

				if ((*ctx->scanner) == '.')
				{
					move_forward();
					if ((*ctx->scanner) == '.')
					{
						c.token.Text.Len = 3;
						c.token.Type     = Tok_Varadic_Argument;
						c.token.Flags    = TF_Null;
						move_forward();
					}
					else
					{
						gen_StrBuilder context_str = gen_strbuilder_fmt_buf(gen__ctx->Allocator_Temp, "%s", c.scanner, gen_min(100, c.left));

						gen_log_failure(
						    "gen::gen_lex: invalid varadic argument, expected '...' got '..%c' (%d, %d)\n%s",
						    (*ctx->scanner),
						    c.line,
						    c.column,
						    context_str
						);
					}
				}

				goto FoundToken;
			}
			case '&':
			{
				gen_Str text   = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_Ampersand;
				c.token.Flags |= TF_Operator;
				c.token.Flags |= TF_Specifier;

				if (c.left)
					move_forward();

				if ((*ctx->scanner) == '&')    // &&
				{
					c.token.Text.Len = 2;
					c.token.Type     = Tok_Ampersand_DBL;

					if (c.left)
						move_forward();
				}

				goto FoundToken;
			}
			case ':':
			{
				gen_Str text = { c.scanner, 1 };
				c.token.Text = text;
				c.token.Type = Tok_Assign_Classifer;
				// Can be either a classifier (ParentType, Bitfield width), or ternary else
				// token.Type   = Tok_Colon;

				if (c.left)
					move_forward();

				if ((*ctx->scanner) == ':')
				{
					move_forward();
					c.token.Type = Tok_Access_StaticSymbol;
					c.token.Text.Len++;
				}
				goto FoundToken;
			}
			case '{':
			{
				gen_Str text = { c.scanner, 1 };
				c.token.Text = text;
				c.token.Type = Tok_BraceCurly_Open;

				if (c.left)
					move_forward();
				goto FoundToken;
			}
			case '}':
			{
				gen_Str text  = { c.scanner, 1 };
				c.token.Text  = text;
				c.token.Type  = Tok_BraceCurly_Close;
				c.token.Flags = TF_EndDefinition;

				if (c.left)
					move_forward();

				gen_end_line();
				goto FoundToken;
			}
			case '[':
			{
				gen_Str text = { c.scanner, 1 };
				c.token.Text = text;
				c.token.Type = Tok_BraceSquare_Open;
				if (c.left)
				{
					move_forward();

					if ((*ctx->scanner) == ']')
					{
						c.token.Text.Len = 2;
						c.token.Type     = Tok_Operator;
						move_forward();
					}
				}
				goto FoundToken;
			}
			case ']':
			{
				gen_Str text = { c.scanner, 1 };
				c.token.Text = text;
				c.token.Type = Tok_BraceSquare_Close;

				if (c.left)
					move_forward();
				goto FoundToken;
			}
			case '(':
			{
				gen_Str text = { c.scanner, 1 };
				c.token.Text = text;
				c.token.Type = Tok_Paren_Open;

				if (c.left)
					move_forward();
				goto FoundToken;
			}
			case ')':
			{
				gen_Str text = { c.scanner, 1 };
				c.token.Text = text;
				c.token.Type = Tok_Paren_Close;

				if (c.left)
					move_forward();
				goto FoundToken;
			}
			case '\'':
			{
				gen_Str text  = { c.scanner, 1 };
				c.token.Text  = text;
				c.token.Type  = Tok_Char;
				c.token.Flags = TF_Literal;

				move_forward();

				if (c.left && (*ctx->scanner) == '\\')
				{
					move_forward();
					c.token.Text.Len++;

					if ((*ctx->scanner) == '\'')
					{
						move_forward();
						c.token.Text.Len++;
					}
				}

				while (c.left && (*ctx->scanner) != '\'')
				{
					move_forward();
					c.token.Text.Len++;
				}

				if (c.left)
				{
					move_forward();
					c.token.Text.Len++;
				}
				goto FoundToken;
			}
			case ',':
			{
				gen_Str text  = { c.scanner, 1 };
				c.token.Text  = text;
				c.token.Type  = Tok_Comma;
				c.token.Flags = TF_Operator;

				if (c.left)
					move_forward();
				goto FoundToken;
			}
			case '*':
			{
				gen_Str text   = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_Star;
				c.token.Flags |= TF_Specifier;
				c.token.Flags |= TF_Operator;

				if (c.left)
					move_forward();

				if ((*ctx->scanner) == '=')
				{
					c.token.Text.Len++;
					c.token.Flags |= TF_Assign;
					// c.token.Type = Tok_Assign_Multiply;

					if (c.left)
						move_forward();
				}

				goto FoundToken;
			}
			case ';':
			{
				gen_Str text  = { c.scanner, 1 };
				c.token.Text  = text;
				c.token.Type  = Tok_Statement_End;
				c.token.Flags = TF_EndDefinition;

				if (c.left)
					move_forward();

				gen_end_line();
				goto FoundToken;
			}
			case '"':
			{
				gen_Str text   = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_String;
				c.token.Flags |= TF_Literal;

				move_forward();
				while (c.left)
				{
					if ((*ctx->scanner) == '"')
					{
						move_forward();
						break;
					}

					if ((*ctx->scanner) == '\\')
					{
						move_forward();
						c.token.Text.Len++;

						if (c.left)
						{
							move_forward();
							c.token.Text.Len++;
						}
						continue;
					}

					move_forward();
					c.token.Text.Len++;
				}
				goto FoundToken;
			}
			case '?':
			{
				gen_Str text = { c.scanner, 1 };
				c.token.Text = text;
				c.token.Type = Tok_Operator;
				// c.token.Type     = Tok_Ternary;
				c.token.Flags = TF_Operator;

				if (c.left)
					move_forward();

				goto FoundToken;
			}
			case '=':
			{
				gen_Str text = { c.scanner, 1 };
				c.token.Text = text;
				c.token.Type = Tok_Operator;
				// c.token.Type     = Tok_Assign;
				c.token.Flags  = TF_Operator;
				c.token.Flags |= TF_Assign;

				if (c.left)
					move_forward();

				if ((*ctx->scanner) == '=')
				{
					c.token.Text.Len++;
					c.token.Flags = TF_Operator;

					if (c.left)
						move_forward();
				}

				goto FoundToken;
			}
			case '+':
			{
				// c.token.Type = Tok_Add
			}
			case '%':
			{
				// c.token.Type = Tok_Modulo;
			}
			case '^':
			{
				// c.token.Type = Tok_B_XOr;
			}
			case '~':
			{
				// c.token.Type = Tok_Unary_Not;
			}
			case '!':
			{
				// c.token.Type = Tok_L_Not;
			}
			case '<':
			{
				// c.token.Type = Tok_Lesser;
			}
			case '>':
			{
				// c.token.Type = Tok_Greater;
			}
			case '|':
			{
				gen_Str text  = { c.scanner, 1 };
				c.token.Text  = text;
				c.token.Type  = Tok_Operator;
				c.token.Flags = TF_Operator;
				// token.Type   = Tok_L_Or;

				if (c.left)
					move_forward();

				if ((*ctx->scanner) == '=')
				{
					c.token.Text.Len++;
					c.token.Flags |= TF_Assign;
					// token.Flags |= TokFlags::Assignment;
					// token.Type = Tok_Assign_L_Or;

					if (c.left)
						move_forward();
				}
				else
					while (c.left && (*ctx->scanner) == *(c.scanner - 1) && c.token.Text.Len < 3)
					{
						c.token.Text.Len++;

						if (c.left)
							move_forward();
					}
				goto FoundToken;
			}

			// Dash is unfortunately a gen_bit more complicated...
			case '-':
			{
				gen_Str text = { c.scanner, 1 };
				c.token.Text = text;
				c.token.Type = Tok_Operator;
				// token.Type = Tok_Subtract;
				c.token.Flags = TF_Operator;
				if (c.left)
				{
					move_forward();

					if ((*ctx->scanner) == '>')
					{
						c.token.Text.Len++;
						//						token.Type = Tok_Access_PointerToMemberSymbol;
						c.token.Flags |= TF_AccessOperator;
						move_forward();

						if ((*ctx->scanner) == '*')
						{
							//							token.Type = Tok_Access_PointerToMemberOfPointerSymbol;
							c.token.Text.Len++;
							move_forward();
						}
					}
					else if ((*ctx->scanner) == '=')
					{
						c.token.Text.Len++;
						// token.Type = Tok_Assign_Subtract;
						c.token.Flags |= TF_Assign;

						if (c.left)
							move_forward();
					}
					else
						while (c.left && (*ctx->scanner) == *(c.scanner - 1) && c.token.Text.Len < 3)
						{
							c.token.Text.Len++;

							if (c.left)
								move_forward();
						}
				}
				goto FoundToken;
			}
			case '/':
			{
				gen_Str text = { c.scanner, 1 };
				c.token.Text = text;
				c.token.Type = Tok_Operator;
				// token.Type   = Tok_Divide;
				c.token.Flags = TF_Operator;
				move_forward();

				if (c.left)
				{
					if ((*ctx->scanner) == '=')
					{
						// token.Type = TokeType::Assign_Divide;
						move_forward();
						c.token.Text.Len++;
						c.token.Flags = TF_Assign;
					}
					else if ((*ctx->scanner) == '/')
					{
						c.token.Type     = Tok_Comment;
						c.token.Text.Len = 2;
						c.token.Flags    = TF_Null;
						move_forward();

						while (c.left && (*ctx->scanner) != '\n' && (*ctx->scanner) != '\r')
						{
							move_forward();
							c.token.Text.Len++;
						}

						if ((*ctx->scanner) == '\r')
						{
							move_forward();
							c.token.Text.Len++;
						}
						if ((*ctx->scanner) == '\n')
						{
							move_forward();
							c.token.Text.Len++;
						}
						gen_array_append(gen__ctx->gen_Lexer_Tokens, c.token);
						continue;
					}
					else if ((*ctx->scanner) == '*')
					{
						c.token.Type     = Tok_Comment;
						c.token.Text.Len = 2;
						c.token.Flags    = TF_Null;
						move_forward();

						bool star   = (*ctx->scanner) == '*';
						bool slash  = c.scanner[1] == '/';
						bool at_end = star && slash;
						while (c.left && ! at_end)
						{
							move_forward();
							c.token.Text.Len++;

							star   = (*ctx->scanner) == '*';
							slash  = c.scanner[1] == '/';
							at_end = star && slash;
						}
						c.token.Text.Len += 2;
						move_forward();
						move_forward();

						if ((*ctx->scanner) == '\r')
						{
							move_forward();
							c.token.Text.Len++;
						}
						if ((*ctx->scanner) == '\n')
						{
							move_forward();
							c.token.Text.Len++;
						}
						gen_array_append(gen__ctx->gen_Lexer_Tokens, c.token);
						// gen_end_line();
						continue;
					}
				}
				goto FoundToken;
			}
		}

		if (gen_char_is_alpha((*ctx->scanner)) || (*ctx->scanner) == '_')
		{
			gen_Str text = { c.scanner, 1 };
			c.token.Text = text;
			move_forward();

			while (c.left && (gen_char_is_alphanumeric((*ctx->scanner)) || (*ctx->scanner) == '_'))
			{
				move_forward();
				c.token.Text.Len++;
			}

			goto FoundToken;
		}
		else if (gen_char_is_digit((*ctx->scanner)))
		{
			// This is a very brute force gen_lex, no checks are done for validity of literal.

			gen_Str text  = { c.scanner, 1 };
			c.token.Text  = text;
			c.token.Type  = Tok_Number;
			c.token.Flags = TF_Literal;
			move_forward();

			if (c.left
			    && ((*ctx->scanner) == 'x' || (*ctx->scanner) == 'X' || (*ctx->scanner) == 'b' || (*ctx->scanner) == 'B' || (*ctx->scanner) == 'o'
			        || (*ctx->scanner) == 'O'))
			{
				move_forward();
				c.token.Text.Len++;

				while (c.left && gen_char_is_hex_digit((*ctx->scanner)))
				{
					move_forward();
					c.token.Text.Len++;
				}

				goto FoundToken;
			}

			while (c.left && gen_char_is_digit((*ctx->scanner)))
			{
				move_forward();
				c.token.Text.Len++;
			}

			if (c.left && (*ctx->scanner) == '.')
			{
				move_forward();
				c.token.Text.Len++;

				while (c.left && gen_char_is_digit((*ctx->scanner)))
				{
					move_forward();
					c.token.Text.Len++;
				}

				// Handle number literal suffixes in a botched way
				if (c.left
				    && ((*ctx->scanner) == 'l' || (*ctx->scanner) == 'L' ||    // long/long long
				        (*ctx->scanner) == 'u' || (*ctx->scanner) == 'U' ||    // unsigned
				        (*ctx->scanner) == 'f' || (*ctx->scanner) == 'F' ||    // float
				        (*ctx->scanner) == 'i' || (*ctx->scanner) == 'I' ||    // imaginary
				        (*ctx->scanner) == 'z' || (*ctx->scanner) == 'Z'))     // complex
				{
					char prev = (*ctx->scanner);
					move_forward();
					c.token.Text.Len++;

					// Handle 'll'/'LL' as a special case when we just processed an 'l'/'L'
					if (c.left && (prev == 'l' || prev == 'L') && ((*ctx->scanner) == 'l' || (*ctx->scanner) == 'L'))
					{
						move_forward();
						c.token.Text.Len++;
					}
				}
			}

			goto FoundToken;
		}
		else
		{
			gen_s32 start = gen_max(0, gen_array_num(gen__ctx->gen_Lexer_Tokens) - 100);
			gen_log_fmt("\n%d\n", start);
			for (gen_s32 idx = start; idx < gen_array_num(gen__ctx->gen_Lexer_Tokens); idx++)
			{
				gen_log_fmt(
				    "gen_Token %d Type: %s : %.*s\n",
				    idx,
				    gen_toktype_to_str(gen__ctx->gen_Lexer_Tokens[idx].Type).Ptr,
				    gen__ctx->gen_Lexer_Tokens[idx].Text.Len,
				    gen__ctx->gen_Lexer_Tokens[idx].Text.Ptr
				);
			}

			gen_StrBuilder context_str = gen_strbuilder_fmt_buf(gen__ctx->Allocator_Temp, "%.*s", gen_min(100, c.left), c.scanner);
			gen_log_failure("Failed to gen_lex token '%c' (%d, %d)\n%s", (*ctx->scanner), c.line, c.column, context_str);

			// Skip to next whitespace since we can't know if anything else is valid until then.
			while (c.left && ! gen_char_is_space((*ctx->scanner)))
			{
				move_forward();
			}
		}

	FoundToken:
	{
		gen_lex_found_token(ctx);
		gen_TokType last_type = gen_array_back(gen__ctx->gen_Lexer_Tokens)->Type;
		if (last_type == Tok_Preprocess_Macro_Stmt || last_type == Tok_Preprocess_Macro_Expr)
		{
			gen_Token thanks_c = {
				{ c.scanner, 0 },
				Tok_Invalid,
				c.line,
				c.column,
				TF_Null
			};
			c.token = thanks_c;
			if ((*ctx->scanner) == '\r')
			{
				move_forward();
				c.token.Text.Len = 1;
			}
			if ((*ctx->scanner) == '\n')
			{
				c.token.Type = Tok_NewLine;
				c.token.Text.Len++;
				move_forward();

				gen_array_append(gen__ctx->gen_Lexer_Tokens, c.token);
				continue;
			}
		}
	}
	}

	if (gen_array_num(gen__ctx->gen_Lexer_Tokens) == 0)
	{
		gen_log_failure("Failed to gen_lex any tokens");
		gen_TokArray gen_tok_array = {};
		return gen_tok_array;
	}

	gen_TokArray result = { gen__ctx->gen_Lexer_Tokens, 0 };
	return result;
}

#undef move_forward
#undef skip_whitespace
#undef gen_end_line

#pragma region gen_Array_gen_CodeTypename

#define GEN_GENERIC_SLOT_10__array_init            gen_CodeTypename, gen_Array_gen_CodeTypename_init
#define GEN_GENERIC_SLOT_10__array_init_reserve    gen_CodeTypename, gen_Array_gen_CodeTypename_init_reserve
#define GEN_GENERIC_SLOT_10__array_append          gen_Array_gen_CodeTypename, gen_Array_gen_CodeTypename_append
#define GEN_GENERIC_SLOT_10__array_append_items    gen_Array_gen_CodeTypename, gen_Array_gen_CodeTypename_append_items
#define GEN_GENERIC_SLOT_10__array_append_at       gen_Array_gen_CodeTypename, gen_Array_gen_CodeTypename_append_at
#define GEN_GENERIC_SLOT_10__array_append_items_at gen_Array_gen_CodeTypename, gen_Array_gen_CodeTypename_append_items_at
#define GEN_GENERIC_SLOT_10__array_back            gen_Array_gen_CodeTypename, gen_Array_gen_CodeTypename_back
#define GEN_GENERIC_SLOT_10__array_clear           gen_Array_gen_CodeTypename, gen_Array_gen_CodeTypename_clear
#define GEN_GENERIC_SLOT_10__array_fill            gen_Array_gen_CodeTypename, gen_Array_gen_CodeTypename_fill
#define GEN_GENERIC_SLOT_10__array_free            gen_Array_gen_CodeTypename, gen_Array_gen_CodeTypename_free
#define GEN_GENERIC_SLOT_10__array_grow            gen_Array_gen_CodeTypename*, gen_Array_gen_CodeTypename_grow
#define GEN_GENERIC_SLOT_10__array_num             gen_Array_gen_CodeTypename, gen_Array_gen_CodeTypename_num
#define GEN_GENERIC_SLOT_10__array_pop             gen_Array_gen_CodeTypename, gen_Array_gen_CodeTypename_pop
#define GEN_GENERIC_SLOT_10__array_remove_at       gen_Array_gen_CodeTypename, gen_Array_gen_CodeTypename_remove_at
#define GEN_GENERIC_SLOT_10__array_reserve         gen_Array_gen_CodeTypename, gen_Array_gen_CodeTypename_reserve
#define GEN_GENERIC_SLOT_10__array_resize          gen_Array_gen_CodeTypename, gen_Array_gen_CodeTypename_resize
#define GEN_GENERIC_SLOT_10__array_set_capacity    gen_Array_gen_CodeTypename*, gen_Array_gen_CodeTypename_set_capacity

typedef gen_CodeTypename*  gen_Array_gen_CodeTypename;
gen_Array_gen_CodeTypename gen_Array_gen_CodeTypename_init(gen_AllocatorInfo allocator);
gen_Array_gen_CodeTypename gen_Array_gen_CodeTypename_init_reserve(gen_AllocatorInfo allocator, gen_usize capacity);
bool                       gen_Array_gen_CodeTypename_append_array(gen_Array_gen_CodeTypename* self, gen_Array_gen_CodeTypename other);
bool                       gen_Array_gen_CodeTypename_append(gen_Array_gen_CodeTypename* self, gen_CodeTypename value);
bool                       gen_Array_gen_CodeTypename_append_items(gen_Array_gen_CodeTypename* self, gen_CodeTypename* items, gen_usize item_num);
bool                       gen_Array_gen_CodeTypename_append_at(gen_Array_gen_CodeTypename* self, gen_CodeTypename item, gen_usize idx);
bool              gen_Array_gen_CodeTypename_append_items_at(gen_Array_gen_CodeTypename* self, gen_CodeTypename* items, gen_usize item_num, gen_usize idx);
gen_CodeTypename* gen_Array_gen_CodeTypename_back(gen_Array_gen_CodeTypename self);
void              gen_Array_gen_CodeTypename_clear(gen_Array_gen_CodeTypename self);
bool              gen_Array_gen_CodeTypename_fill(gen_Array_gen_CodeTypename self, gen_usize begin, gen_usize end, gen_CodeTypename value);
void              gen_Array_gen_CodeTypename_free(gen_Array_gen_CodeTypename* self);
bool              gen_Array_gen_CodeTypename_grow(gen_Array_gen_CodeTypename* self, gen_usize min_capacity);
gen_usize         gen_Array_gen_CodeTypename_num(gen_Array_gen_CodeTypename self);
gen_CodeTypename  gen_Array_gen_CodeTypename_pop(gen_Array_gen_CodeTypename self);
void              gen_Array_gen_CodeTypename_remove_at(gen_Array_gen_CodeTypename self, gen_usize idx);
bool              gen_Array_gen_CodeTypename_reserve(gen_Array_gen_CodeTypename* self, gen_usize new_capacity);
bool              gen_Array_gen_CodeTypename_resize(gen_Array_gen_CodeTypename* self, gen_usize num);
bool              gen_Array_gen_CodeTypename_set_capacity(gen_Array_gen_CodeTypename* self, gen_usize new_capacity);

gen_forceinline gen_Array_gen_CodeTypename gen_Array_gen_CodeTypename_init(gen_AllocatorInfo allocator)
{
	size_t initial_size = gen_array_grow_formula(0);
	return gen_array_init_reserve(gen_CodeTypename, allocator, initial_size);
}

inline gen_Array_gen_CodeTypename gen_Array_gen_CodeTypename_init_reserve(gen_AllocatorInfo allocator, gen_usize capacity)
{
	GEN_ASSERT(capacity > 0);
	gen_ArrayHeader* header = gen_rcast(gen_ArrayHeader*, gen_alloc(allocator, sizeof(gen_ArrayHeader) + sizeof(gen_CodeTypename) * capacity));
	if (header == gen_nullptr)
		return gen_nullptr;
	header->Allocator = allocator;
	header->Capacity  = capacity;
	header->Num       = 0;
	return gen_rcast(gen_CodeTypename*, header + 1);
}

gen_forceinline bool gen_Array_gen_CodeTypename_append_array(gen_Array_gen_CodeTypename* self, gen_Array_gen_CodeTypename other)
{
	return gen_array_append_items(*self, (gen_Array_gen_CodeTypename)other, gen_Array_gen_CodeTypename_num(other));
}

inline bool gen_Array_gen_CodeTypename_append(gen_Array_gen_CodeTypename* self, gen_CodeTypename value)
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

inline bool gen_Array_gen_CodeTypename_append_items(gen_Array_gen_CodeTypename* self, gen_CodeTypename* items, gen_usize item_num)
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
	gen_mem_copy((*self) + header->Num, items, sizeof(gen_CodeTypename) * item_num);
	header->Num += item_num;
	return true;
}

inline bool gen_Array_gen_CodeTypename_append_at(gen_Array_gen_CodeTypename* self, gen_CodeTypename item, gen_usize idx)
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
	gen_Array_gen_CodeTypename target = (*self) + idx;
	gen_mem_move(target + 1, target, (header->Num - idx) * sizeof(gen_CodeTypename));
	header->Num++;
	return true;
}

inline bool gen_Array_gen_CodeTypename_append_items_at(gen_Array_gen_CodeTypename* self, gen_CodeTypename* items, gen_usize item_num, gen_usize idx)
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
	gen_CodeTypename* target = (*self) + idx + item_num;
	gen_CodeTypename* src    = (*self) + idx;
	gen_mem_move(target, src, (header->Num - idx) * sizeof(gen_CodeTypename));
	gen_mem_copy(src, items, item_num * sizeof(gen_CodeTypename));
	header->Num += item_num;
	return true;
}

inline gen_CodeTypename* gen_Array_gen_CodeTypename_back(gen_Array_gen_CodeTypename self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	if (header->Num == 0)
		return 0;
	return self + header->Num - 1;
}

inline void gen_Array_gen_CodeTypename_clear(gen_Array_gen_CodeTypename self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	header->Num             = 0;
}

inline bool gen_Array_gen_CodeTypename_fill(gen_Array_gen_CodeTypename self, gen_usize begin, gen_usize end, gen_CodeTypename value)
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

inline void gen_Array_gen_CodeTypename_free(gen_Array_gen_CodeTypename* self)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	gen_allocator_free(header->Allocator, header);
	self = 0;
}

inline bool gen_Array_gen_CodeTypename_grow(gen_Array_gen_CodeTypename* self, gen_usize min_capacity)
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

gen_forceinline gen_usize gen_Array_gen_CodeTypename_num(gen_Array_gen_CodeTypename self)
{
	GEN_ASSERT(self != gen_nullptr);
	return gen_array_get_header(self)->Num;
}

inline gen_CodeTypename gen_Array_gen_CodeTypename_pop(gen_Array_gen_CodeTypename self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	GEN_ASSERT(header->Num > 0);
	gen_CodeTypename result = self[header->Num - 1];
	header->Num--;
	return result;
}

gen_forceinline void gen_Array_gen_CodeTypename_remove_at(gen_Array_gen_CodeTypename self, gen_usize idx)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	GEN_ASSERT(idx < header->Num);
	gen_mem_move(self + idx, self + idx + 1, sizeof(gen_CodeTypename) * (header->Num - idx - 1));
	header->Num--;
}

inline bool gen_Array_gen_CodeTypename_reserve(gen_Array_gen_CodeTypename* self, gen_usize new_capacity)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(new_capacity > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Capacity < new_capacity)
		return gen_array_set_capacity(self, new_capacity);
	return true;
}

inline bool gen_Array_gen_CodeTypename_resize(gen_Array_gen_CodeTypename* self, gen_usize num)
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

inline bool gen_Array_gen_CodeTypename_set_capacity(gen_Array_gen_CodeTypename* self, gen_usize new_capacity)
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
	gen_usize        size       = sizeof(gen_ArrayHeader) + sizeof(gen_CodeTypename) * new_capacity;
	gen_ArrayHeader* new_header = gen_cast(gen_ArrayHeader*, gen_alloc(header->Allocator, size));
	if (new_header == 0)
		return false;
	gen_mem_move(new_header, header, sizeof(gen_ArrayHeader) + sizeof(gen_CodeTypename) * header->Num);
	new_header->Capacity = new_capacity;
	gen_allocator_free(header->Allocator, &header);
	*self = gen_cast(gen_CodeTypename*, new_header + 1);
	return true;
}

#pragma endregion gen_Array_gen_CodeTypename


// TODO(Ed) : Rename ETok_Capture_Start, ETok_Capture_End to Open_Parenthesis adn Close_Parenthesis

#define gen_lex_dont_skip_formatting (bool)false
#define gen_lex_skip_formatting      (bool)true

void gen_parser_push(gen_ParseContext* ctx, gen_StackNode* node)
{
	node->Prev = ctx->Scope;
	ctx->Scope = node;

#if 0 && GEN_BUILD_DEBUG
	gen_log_fmt("\tEntering gen__ctx->parser: %.*s\n", Scope->ProcName.Len, Scope->ProcName.Ptr );
#endif
}

void gen_parser_pop(gen_ParseContext* ctx)
{
#if 0 && GEN_BUILD_DEBUG
	gen_log_fmt("\tPopping  gen__ctx->parser: %.*s\n", Scope->ProcName.Len, Scope->ProcName.Ptr );
#endif
	ctx->Scope = ctx->Scope->Prev;
}

gen_StrBuilder gen_parser_to_strbuilder(gen_ParseContext ctx)
{
	gen_StrBuilder result = gen_strbuilder_make_reserve(gen__ctx->Allocator_Temp, gen_kilobytes(4));

	gen_Token scope_start = *ctx.Scope->Start;
	gen_Token last_valid =
	    ctx.Tokens.Idx >= gen_array_num(ctx.Tokens.Arr) ? ctx.Tokens.Arr[gen_array_num(ctx.Tokens.Arr) - 1] : (*gen_lex_current(&ctx.Tokens, true));

	gen_sptr    length  = scope_start.Text.Len;
	char const* current = scope_start.Text.Ptr + length;
	while (current <= gen_array_back(ctx.Tokens.Arr)->Text.Ptr && (*current) != '\n' && length < 74)
	{
		current++;
		length++;
	}

	gen_Str        scope_str = { scope_start.Text.Ptr, length };
	gen_StrBuilder line      = gen_strbuilder_make_str(gen__ctx->Allocator_Temp, scope_str);
	gen_strbuilder_append_fmt(&result, "\tScope    : %s\n", line);
	gen_strbuilder_free(&line);

	gen_sptr dist                = (gen_sptr)last_valid.Text.Ptr - (gen_sptr)scope_start.Text.Ptr + 2;
	gen_sptr length_from_err     = dist;

	gen_Str        err_str       = { last_valid.Text.Ptr, length_from_err };
	gen_StrBuilder line_from_err = gen_strbuilder_make_str(gen__ctx->Allocator_Temp, err_str);

	if (length_from_err < 100)
		gen_strbuilder_append_fmt(&result, "\t(%d, %d):%*c\n", last_valid.Line, last_valid.Column, length_from_err, '^');
	else
		gen_strbuilder_append_fmt(&result, "\t(%d, %d)\n", last_valid.Line, last_valid.Column);

	gen_StackNode* curr_scope = ctx.Scope;
	gen_s32        level      = 0;
	do
	{
		if (curr_scope->Name.Ptr)
		{
			gen_strbuilder_append_fmt(&result, "\t%d: %s, gen_AST Name: %.*s\n", level, curr_scope->ProcName.Ptr, curr_scope->Name.Len, curr_scope->Name.Ptr);
		}
		else
		{
			gen_strbuilder_append_fmt(&result, "\t%d: %s\n", level, curr_scope->ProcName.Ptr);
		}

		curr_scope = curr_scope->Prev;
		level++;
	} while (curr_scope);
	return result;
}

bool gen_lex__eat(gen_TokArray* self, gen_TokType type)
{
	if (gen_array_num(self->Arr) - self->Idx <= 0)
	{
		gen_log_failure("No tokens left.\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
		return false;
	}

	gen_Token at_idx = self->Arr[self->Idx];

	if ((at_idx.Type == Tok_NewLine && type != Tok_NewLine) || (at_idx.Type == Tok_Comment && type != Tok_Comment))
	{
		self->Idx++;
	}

	gen_b32 not_accepted  = at_idx.Type != type;
	gen_b32 is_identifier = at_idx.Type == Tok_Identifier;
	if (not_accepted)
	{
		gen_Macro* macro                = lookup_macro(at_idx.Text);
		gen_b32    accept_as_identifier = macro && gen_bitfield_is_set(gen_MacroFlags, macro->Flags, MF_Allow_As_Identifier);
		not_accepted                    = type == Tok_Identifier && accept_as_identifier ? false : true;
	}
	if (not_accepted)
	{
		gen_Token tok = *gen_lex_current(self, gen_lex_skip_formatting);
		gen_log_failure(
		    "Parse Error, gen_TokArray::eat, Expected: ' %s ' not ' %.*s ' (%d, %d)`\n%s",
		    gen_toktype_to_str(type).Ptr,
		    at_idx.Text.Len,
		    at_idx.Text.Ptr,
		    tok.Line,
		    tok.Column,
		    gen_parser_to_strbuilder(gen__ctx->parser)
		);
		GEN_DEBUG_TRAP();
		return false;
	}

#if 0 && GEN_BUILD_DEBUG
	gen_log_fmt("Ate: %SB\n", self->Arr[Idx].to_strbuilder() );
#endif

	self->Idx++;
	return true;
}

gen_internal void gen_parser_init()
{
	gen__ctx->gen_Lexer_Tokens = gen_array_init_reserve(gen_Token, gen__ctx->Allocator_DyanmicContainers, gen__ctx->InitSize_LexerTokens);
}

gen_internal void gen_parser_deinit()
{
	gen_Array(gen_Token) null_array = { gen_nullptr };
	gen__ctx->gen_Lexer_Tokens      = null_array;
}

#pragma region Helper Macros


#define check_parse_args(def) _check_parse_args(def, gen_stringize(_func_))

bool _check_parse_args(gen_Str def, char const* func_name)
{
	if (def.Len <= 0)
	{
		gen_log_failure(gen_c_str_fmt_buf("gen::%s: length must greater than 0", func_name));
		gen_parser_pop(&gen__ctx->parser);
		return false;
	}
	if (def.Ptr == gen_nullptr)
	{
		gen_log_failure(gen_c_str_fmt_buf("gen::%s: def was null", func_name));
		gen_parser_pop(&gen__ctx->parser);
		return false;
	}
	return true;
}

#define currtok_noskip (*gen_lex_current(&gen__ctx->parser.Tokens, gen_lex_dont_skip_formatting))
#define currtok        (*gen_lex_current(&gen__ctx->parser.Tokens, gen_lex_skip_formatting))
#define peektok        (*gen_lex_peek(gen__ctx->parser.Tokens, gen_lex_skip_formatting))
#define prevtok        (*gen_lex_previous(gen__ctx->parser.Tokens, gen_lex_dont_skip_formatting))
#define nexttok        (*gen_lex_next(gen__ctx->parser.Tokens, gen_lex_skip_formatting))
#define nexttok_noskip (*gen_lex_next(gen__ctx->parser.Tokens, gen_lex_dont_skip_formatting))
#define eat(Type_)     gen_lex__eat(&gen__ctx->parser.Tokens, Type_)
#define left           (gen_array_num(gen__ctx->parser.Tokens.Arr) - gen__ctx->parser.Tokens.Idx)

#if GEN_COMPILER_CPP
#define gen_def_assign(...) \
	{                       \
		__VA_ARGS__         \
	}
#else
#define gen_def_assign(...) __VA_ARGS__
#endif


#ifdef check

#define CHECK_WAS_DEFINED

#pragma push_macro("check")

#undef check
#endif

#define check_noskip(Type_) (left && currtok_noskip.Type == Type_)
#define check(Type_)        (left && currtok.Type == Type_)

#define push_scope()                                                                                                                              \
	gen_Str       null_name = {};                                                                                                                 \
	gen_StackNode scope     = { gen_nullptr, gen_lex_current(&gen__ctx->parser.Tokens, gen_lex_dont_skip_formatting), null_name, txt(__func__) }; \
	gen_parser_push(&gen__ctx->parser, &scope)

#pragma endregion Helper Macros


// Procedure Forwards ( Entire parser gen_internal parser interface )

gen_internal gen_Code           gen_parse_array_decl();
gen_internal gen_CodeAttributes gen_parse_attributes();
gen_internal gen_CodeComment    gen_parse_comment();
gen_internal gen_Code           gen_parse_complicated_definition(gen_TokType which);
gen_internal gen_CodeBody       gen_parse_class_struct_body(gen_TokType which, gen_Token name);
gen_internal gen_Code           gen_parse_class_struct(gen_TokType which, bool inplace_def);
gen_internal gen_Code           gen_parse_expression();
gen_internal gen_Code           gen_parse_forward_or_definition(gen_TokType which, bool is_inplace);
gen_internal gen_CodeFn         gen_parse_function_after_name(
            gen_ModuleFlag     mflags,
            gen_CodeAttributes attributes,
            gen_CodeSpecifiers specifiers,
            gen_CodeTypename   ret_type,
            gen_Token          name
        );
gen_internal gen_Code        gen_parse_function_body();
gen_internal gen_CodeBody    gen_parse_global_nspace(gen_CodeType which);
gen_internal gen_Code        gen_parse_global_nspace_constructor_destructor(gen_CodeSpecifiers specifiers);
gen_internal gen_Token       gen_parse_identifier(bool* possible_member_function);
gen_internal gen_CodeInclude gen_parse_include();
gen_internal gen_Code        gen_parse_macro_as_definiton(gen_CodeAttributes attributes, gen_CodeSpecifiers specifiers);
gen_internal gen_CodeOperator
    gen_parse_operator_after_ret_type(gen_ModuleFlag mflags, gen_CodeAttributes attributes, gen_CodeSpecifiers specifiers, gen_CodeTypename ret_type);
gen_internal gen_Code       gen_parse_operator_function_or_variable(bool expects_function, gen_CodeAttributes attributes, gen_CodeSpecifiers specifiers);
gen_internal gen_CodePragma gen_parse_pragma();
gen_internal gen_CodeParams gen_parse_params(bool use_template_capture);
gen_internal gen_CodePreprocessCond gen_parse_preprocess_cond();
gen_internal gen_Code               gen_parse_simple_preprocess(gen_TokType which);
gen_internal gen_Code               gen_parse_static_assert();
gen_internal void                   gen_parse_template_args(gen_Token* token);
gen_internal gen_CodeVar
    gen_parse_variable_after_name(gen_ModuleFlag mflags, gen_CodeAttributes attributes, gen_CodeSpecifiers specifiers, gen_CodeTypename type, gen_Str name);
gen_internal gen_CodeVar gen_parse_variable_declaration_list();

gen_internal gen_CodeClass       gen_parser_parse_class(bool inplace_def);
gen_internal gen_CodeConstructor gen_parser_parse_constructor(gen_CodeSpecifiers specifiers);
gen_internal gen_CodeDefine      gen_parser_parse_define();
gen_internal gen_CodeDestructor  gen_parser_parse_destructor(gen_CodeSpecifiers specifiers);
gen_internal gen_CodeEnum        gen_parser_parse_enum(bool inplace_def);
gen_internal gen_CodeBody        gen_parser_parse_export_body();
gen_internal gen_CodeBody        gen_parser_parse_extern_link_body();
gen_internal gen_CodeExtern      gen_parser_parse_extern_link();
gen_internal gen_CodeFriend      gen_parser_parse_friend();
gen_internal gen_CodeFn          gen_parser_parse_function();
gen_internal gen_CodeNS          gen_parser_parse_namespace();
gen_internal gen_CodeOpCast      gen_parser_parse_operator_cast(gen_CodeSpecifiers specifiers);
gen_internal gen_CodeStruct      gen_parser_parse_struct(bool inplace_def);
gen_internal gen_CodeVar         gen_parser_parse_variable();
gen_internal gen_CodeTemplate    gen_parser_parse_template();
gen_internal gen_CodeTypename    gen_parser_parse_type(bool from_template, bool* is_function);
gen_internal gen_CodeTypedef     gen_parser_parse_typedef();
gen_internal gen_CodeUnion       gen_parser_parse_union(bool inplace_def);
gen_internal gen_CodeUsing       gen_parser_parse_using();

#define gen_parser_inplace_def         (bool)true
#define gen_parser_not_inplace_def     (bool)false
#define gen_parser_dont_consume_braces (bool)true
#define gen_parser_consume_braces      (bool)false
#define gen_parser_not_from_template   (bool)false

#define gen_parser_use_parenthesis     (bool)false

// Internal parsing functions

#define gen_parser_strip_formatting_dont_preserve_newlines (bool)false

/*
	This function was an attempt at stripping formatting from any c++ code.
	It has edge case failures that prevent it from being used in function bodies.
*/
gen_internal gen_StrBuilder gen_parser_strip_formatting(gen_Str raw_text, bool preserve_newlines)
{
	gen_StrBuilder content = gen_strbuilder_make_reserve(gen__ctx->Allocator_Temp, raw_text.Len);

	if (raw_text.Len == 0)
		return content;

#define cut_length (scanner - raw_text.Ptr - last_cut)
#define cut_ptr    (raw_text.Ptr + last_cut)
#define pos        (gen_rcast(gen_sptr, scanner) - gen_rcast(gen_sptr, raw_text.Ptr))
#define move_fwd() \
	do             \
	{              \
		scanner++; \
		tokleft--; \
	} while (0)

	gen_s32     tokleft  = raw_text.Len;
	gen_sptr    last_cut = 0;
	char const* scanner  = raw_text.Ptr;

	if (scanner[0] == ' ')
	{
		move_fwd();
		last_cut = 1;
	}

	bool within_string     = false;
	bool within_char       = false;
	bool must_keep_newline = false;
	while (tokleft)
	{
		// Skip over the content of string literals
		if (scanner[0] == '"')
		{
			move_fwd();

			while (tokleft && (scanner[0] != '"' || *(scanner - 1) == '\\'))
			{
				if (scanner[0] == '\\' && tokleft > 1)
				{
					scanner += 2;
					tokleft -= 2;
				}
				else
				{
					move_fwd();
				}
			}

			// Skip the closing "
			if (tokleft)
				move_fwd();

			gen_strbuilder_append_c_str_len(&content, cut_ptr, cut_length);
			last_cut = gen_rcast(gen_sptr, scanner) - gen_rcast(gen_sptr, raw_text.Ptr);
			continue;
		}

		// Skip over the content of character literals
		if (scanner[0] == '\'')
		{
			move_fwd();

			while (tokleft && (scanner[0] != '\'' || (*(scanner - 1) == '\\')))
			{
				move_fwd();
			}

			// Skip the closing '
			if (tokleft)
				move_fwd();

			gen_strbuilder_append_c_str_len(&content, cut_ptr, cut_length);
			last_cut = gen_rcast(gen_sptr, scanner) - gen_rcast(gen_sptr, raw_text.Ptr);
			continue;
		}

		// Block comments
		if (tokleft > 1 && scanner[0] == '/' && scanner[1] == '*')
		{
			while (tokleft > 1 && ! (scanner[0] == '*' && scanner[1] == '/'))
				move_fwd();

			scanner += 2;
			tokleft -= 2;

			gen_strbuilder_append_c_str_len(&content, cut_ptr, cut_length);
			last_cut = gen_rcast(gen_sptr, scanner) - gen_rcast(gen_sptr, raw_text.Ptr);
			continue;
		}

		// Line comments
		if (tokleft > 1 && scanner[0] == '/' && scanner[1] == '/')
		{
			must_keep_newline  = true;

			scanner           += 2;
			tokleft           -= 2;

			while (tokleft && scanner[0] != '\n')
				move_fwd();

			if (tokleft)
				move_fwd();

			gen_strbuilder_append_c_str_len(&content, cut_ptr, cut_length);
			last_cut = gen_rcast(gen_sptr, scanner) - gen_rcast(gen_sptr, raw_text.Ptr);
			continue;
		}

		// Tabs
		if (scanner[0] == '\t')
		{
			if (pos > last_cut)
				gen_strbuilder_append_c_str_len(&content, cut_ptr, cut_length);

			if (*gen_strbuilder_back(content) != ' ')
				gen_strbuilder_append_char(&content, ' ');

			move_fwd();
			last_cut = gen_rcast(gen_sptr, scanner) - gen_rcast(gen_sptr, raw_text.Ptr);
			continue;
		}

		if (tokleft > 1 && scanner[0] == '\r' && scanner[1] == '\n')
		{
			if (must_keep_newline || preserve_newlines)
			{
				must_keep_newline  = false;

				scanner           += 2;
				tokleft           -= 2;

				gen_strbuilder_append_c_str_len(&content, cut_ptr, cut_length);
				last_cut = gen_rcast(gen_sptr, scanner) - gen_rcast(gen_sptr, raw_text.Ptr);
				continue;
			}

			if (pos > last_cut)
				gen_strbuilder_append_c_str_len(&content, cut_ptr, cut_length);

			// Replace with a space
			if (*gen_strbuilder_back(content) != ' ')
				gen_strbuilder_append_char(&content, ' ');

			scanner  += 2;
			tokleft  -= 2;

			last_cut  = gen_rcast(gen_sptr, scanner) - gen_rcast(gen_sptr, raw_text.Ptr);
			continue;
		}

		if (scanner[0] == '\n')
		{
			if (must_keep_newline || preserve_newlines)
			{
				must_keep_newline = false;

				move_fwd();

				gen_strbuilder_append_c_str_len(&content, cut_ptr, cut_length);
				last_cut = gen_rcast(gen_sptr, scanner) - gen_rcast(gen_sptr, raw_text.Ptr);
				continue;
			}

			if (pos > last_cut)
				gen_strbuilder_append_c_str_len(&content, cut_ptr, cut_length);

			// Replace with a space
			if (*gen_strbuilder_back(content) != ' ')
				gen_strbuilder_append_char(&content, ' ');

			move_fwd();

			last_cut = gen_rcast(gen_sptr, scanner) - gen_rcast(gen_sptr, raw_text.Ptr);
			continue;
		}

		// Escaped newlines
		if (scanner[0] == '\\')
		{
			gen_strbuilder_append_c_str_len(&content, cut_ptr, cut_length);

			gen_s32 amount_to_skip = 1;
			if (tokleft > 1 && scanner[1] == '\n')
			{
				amount_to_skip = 2;
			}
			else if (tokleft > 2 && scanner[1] == '\r' && scanner[2] == '\n')
			{
				amount_to_skip = 3;
			}

			if (amount_to_skip > 1 && pos == last_cut)
			{
				scanner += amount_to_skip;
				tokleft -= amount_to_skip;
			}
			else
				move_fwd();

			last_cut = gen_rcast(gen_sptr, scanner) - gen_rcast(gen_sptr, raw_text.Ptr);
			continue;
		}

		// Consectuive spaces
		if (tokleft > 1 && gen_char_is_space(scanner[0]) && gen_char_is_space(scanner[1]))
		{
			gen_strbuilder_append_c_str_len(&content, cut_ptr, cut_length);
			do
			{
				move_fwd();
			} while (tokleft && gen_char_is_space(scanner[0]));

			last_cut = gen_rcast(gen_sptr, scanner) - gen_rcast(gen_sptr, raw_text.Ptr);

			// Preserve only 1 space of formattting
			char* last = gen_strbuilder_back(content);
			if (last == gen_nullptr || *last != ' ')
				gen_strbuilder_append_char(&content, ' ');

			continue;
		}

		move_fwd();
	}

	if (last_cut < raw_text.Len)
	{
		gen_strbuilder_append_c_str_len(&content, cut_ptr, raw_text.Len - last_cut);
	}

#undef cut_ptr
#undef cut_length
#undef pos
#undef move_fwd

	return content;
}

gen_internal gen_Code gen_parse_array_decl()
{
	push_scope();

	if (check(Tok_Operator) && currtok.Text.Ptr[0] == '[' && currtok.Text.Ptr[1] == ']')
	{
		gen_Code gen_array_expr = gen_untyped_str(txt(" "));
		eat(Tok_Operator);
		// []

		gen_parser_pop(&gen__ctx->parser);
		return gen_array_expr;
	}

	if (check(Tok_BraceSquare_Open))
	{
		eat(Tok_BraceSquare_Open);
		// [

		if (left == 0)
		{
			gen_log_failure("Error, unexpected end of array declaration ( '[]' scope started )\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}

		if (currtok.Type == Tok_BraceSquare_Close)
		{
			gen_log_failure("Error, empty array expression in definition\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}

		gen_Token gen_untyped_tok = currtok;

		while (left && currtok.Type != Tok_BraceSquare_Close)
		{
			eat(currtok.Type);
		}

		gen_untyped_tok.Text.Len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)gen_untyped_tok.Text.Ptr;

		gen_Code gen_array_expr  = gen_untyped_str(gen_untyped_tok.Text);
		// [ <Content>

		if (left == 0)
		{
			gen_log_failure("Error, unexpected end of array declaration, expected ]\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}

		if (currtok.Type != Tok_BraceSquare_Close)
		{
			gen_log_failure(
			    "%s: Error, expected ] in array declaration, not %s\n%s",
			    gen_toktype_to_str(currtok.Type),
			    gen_parser_to_strbuilder(gen__ctx->parser)
			);
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}

		eat(Tok_BraceSquare_Close);
		// [ <Content> ]

		// Its a multi-dimensional array
		if (check(Tok_BraceSquare_Open))
		{
			gen_Code adjacent_arr_expr = gen_parse_array_decl();
			// [ <Content> ][ <Content> ]...

			gen_array_expr->Next = adjacent_arr_expr;
		}

		gen_parser_pop(&gen__ctx->parser);
		return gen_array_expr;
	}

	gen_parser_pop(&gen__ctx->parser);
	return gen_NullCode;
}

gen_internal inline gen_CodeAttributes gen_parse_attributes()
{
	push_scope();

	gen_Token start = currtok;
	gen_s32   len   = 0;

	// There can be more than one attribute. If there is flatten them to a single string.
	// TODO(Ed): Support chaining attributes (Use parameter linkage pattern)
	while (left && gen_tok_is_attribute(currtok))
	{
		if (check(Tok_Attribute_Open))
		{
			eat(Tok_Attribute_Open);
			// [[

			while (left && currtok.Type != Tok_Attribute_Close)
			{
				eat(currtok.Type);
			}
			// [[ <Content>

			eat(Tok_Attribute_Close);
			// [[ <Content> ]]

			len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)start.Text.Ptr;
		}
		else if (check(Tok_Decl_GNU_Attribute))
		{
			eat(Tok_Decl_GNU_Attribute);
			eat(Tok_Paren_Open);
			eat(Tok_Paren_Open);
			// __attribute__((

			while (left && currtok.Type != Tok_Paren_Close)
			{
				eat(currtok.Type);
			}
			// __attribute__(( <Content>

			eat(Tok_Paren_Close);
			eat(Tok_Paren_Close);
			// __attribute__(( <Content> ))

			len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)start.Text.Ptr;
		}
		else if (check(Tok_Decl_MSVC_Attribute))
		{
			eat(Tok_Decl_MSVC_Attribute);
			eat(Tok_Paren_Open);
			// __declspec(

			while (left && currtok.Type != Tok_Paren_Close)
			{
				eat(currtok.Type);
			}
			// __declspec( <Content>

			eat(Tok_Paren_Close);
			// __declspec( <Content> )

			len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)start.Text.Ptr;
		}
		else if (gen_tok_is_attribute(currtok))
		{
			eat(currtok.Type);
			// <Attribute>

			// If its a macro based attribute, this could be a functional macro such as Unreal's UE_DEPRECATED(...)
			if (check(Tok_Paren_Open))
			{
				eat(Tok_Paren_Open);

				gen_s32 level = 0;
				while (left && currtok.Type != Tok_Paren_Close && level == 0)
				{
					if (currtok.Type == Tok_Paren_Open)
						++level;
					if (currtok.Type == Tok_Paren_Close)
						--level;
					eat(currtok.Type);
				}
				eat(Tok_Paren_Close);
			}

			len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)start.Text.Ptr;
			// <Attribute> ( ... )
		}
	}

	if (len > 0)
	{
		gen_Str attribute_txt = { start.Text.Ptr, len };
		gen_parser_pop(&gen__ctx->parser);

		gen_StrBuilder name_stripped = gen_parser_strip_formatting(attribute_txt, gen_parser_strip_formatting_dont_preserve_newlines);

		gen_Code result              = gen_make_code();
		result->Type                 = CT_PlatformAttributes;
		result->Name                 = gen_cache_str(gen_strbuilder_to_str(name_stripped));
		result->Content              = result->Name;
		// result->gen_Token   =

		return (gen_CodeAttributes)result;
	}

	gen_parser_pop(&gen__ctx->parser);
	return gen_NullCode;
}

gen_internal gen_Code gen_parse_class_struct(gen_TokType which, bool inplace_def)
{
	if (which != Tok_Decl_Class && which != Tok_Decl_Struct)
	{
		gen_log_failure("Error, expected class or struct, not %s\n%s", gen_toktype_to_str(which), gen_parser_to_strbuilder(gen__ctx->parser));
		return gen_InvalidCode;
	}

	gen_Token name                = gen_NullToken;

	gen_AccessSpec     access     = AccessSpec_Default;
	gen_CodeTypename   parent     = { gen_nullptr };
	gen_CodeBody       body       = { gen_nullptr };
	gen_CodeAttributes attributes = { gen_nullptr };
	gen_ModuleFlag     mflags     = ModuleFlag_None;

	gen_Code result               = gen_InvalidCode;

	if (check(Tok_Module_Export))
	{
		mflags = ModuleFlag_Export;
		eat(Tok_Module_Export);
	}
	// <ModuleFlags>

	eat(which);
	// <ModuleFlags> <class/struct>

	attributes = gen_parse_attributes();
	// <ModuleFlags> <class/struct> <Attributes>

	if (check(Tok_Identifier))
	{
		name                         = gen_parse_identifier(gen_nullptr);
		gen__ctx->parser.Scope->Name = name.Text;
	}
	// <ModuleFlags> <class/struct> <Attributes> <Name>

	gen_CodeSpecifiers specifiers = gen_NullCode;
	if (check(Tok_Spec_Final))
	{
		specifiers = gen_def_specifier(Spec_Final);
		eat(Tok_Spec_Final);
	}
	// <ModuleFlags> <class/struct> <Attributes> <Name> <final>

	gen_local_persist char interface_arr_mem[gen_kilobytes(4)] = { 0 };
	gen_Array(gen_CodeTypename) interfaces;
	{
		gen_Arena arena = gen_arena_init_from_memory(interface_arr_mem, gen_kilobytes(4));
		interfaces      = gen_array_init_reserve(gen_CodeTypename, gen_arena_allocator_info(&arena), 4);
	}

	// TODO(Ed) : Make an gen_AST_DerivedType, we'll store any arbitary derived type into there as a linear linked list of them.
	if (check(Tok_Assign_Classifer))
	{
		eat(Tok_Assign_Classifer);
		// <ModuleFlags> <class/struct> <Attributes> <Name> <final> :

		if (gen_tok_is_access_specifier(currtok))
		{
			access = gen_tok_to_access_specifier(currtok);
			// <ModuleFlags> <class/struct> <Attributes> <Name> <final> : <Access gen_Specifier>
			eat(currtok.Type);
		}

		gen_Token parent_tok = gen_parse_identifier(gen_nullptr);
		parent               = gen_def_type(parent_tok.Text);
		// <ModuleFlags> <class/struct> <Attributes> <Name> <final> : <Access gen_Specifier> <Parent/Interface Name>

		while (check(Tok_Comma))
		{
			eat(Tok_Comma);
			// <ModuleFlags> <class/struct> <Attributes> <Name> <final> : <Access gen_Specifier> <Name>,

			if (gen_tok_is_access_specifier(currtok))
			{
				eat(currtok.Type);
			}
			gen_Token interface_tok = gen_parse_identifier(gen_nullptr);

			gen_array_append(interfaces, gen_def_type(interface_tok.Text));
			// <ModuleFlags> <class/struct> <Attributes> <Name> <final> : <Access gen_Specifier> <Name>, ...
		}
	}

	if (check(Tok_BraceCurly_Open))
	{
		body = gen_parse_class_struct_body(which, name);
	}
	// <ModuleFlags> <class/struct> <Attributes> <Name> <final> : <Access gen_Specifier> <Name>, ... { <Body> }

	gen_CodeComment inline_cmt = gen_NullCode;
	if (! inplace_def)
	{
		gen_Token stmt_end = currtok;
		eat(Tok_Statement_End);
		// <ModuleFlags> <class/struct> <Attributes> <Name> <final> : <Access gen_Specifier> <Name>, ... { <Body> };

		if (currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line)
			inline_cmt = gen_parse_comment();
		// <ModuleFlags> <class/struct> <Attributes> <Name> <final> : <Access gen_Specifier> <Name>, ... { <Body> }; <InlineCmt>
	}

	if (which == Tok_Decl_Class)
		result = gen_cast(
		    gen_Code,
		    gen_def_class(
		        name.Text,
		        gen_def_assign(body, parent, access, attributes, interfaces, gen_scast(gen_s32, gen_array_num(interfaces)), specifiers, mflags)
		    )
		);

	else
		result = gen_cast(
		    gen_Code,
		    gen_def_struct(
		        name.Text,
		        gen_def_assign(
		            body,
		            (gen_CodeTypename)parent,
		            access,
		            attributes,
		            interfaces,
		            gen_scast(gen_s32, gen_array_num(interfaces)),
		            specifiers,
		            mflags
		        )
		    )
		);

	if (inline_cmt)
		result->InlineCmt = gen_cast(gen_Code, inline_cmt);

	gen_array_free(interfaces);
	return result;
}

gen_internal gen_neverinline gen_CodeBody gen_parse_class_struct_body(gen_TokType which, gen_Token name)
{
	push_scope();

	eat(Tok_BraceCurly_Open);
	// {

	gen_CodeBody result = (gen_CodeBody)gen_make_code();

	if (which == Tok_Decl_Class)
		result->Type = CT_Class_Body;

	else
		result->Type = CT_Struct_Body;

	while (left && currtok_noskip.Type != Tok_BraceCurly_Close)
	{
		gen_Code           member     = gen_Code_Invalid;
		gen_CodeAttributes attributes = { gen_nullptr };
		gen_CodeSpecifiers specifiers = { gen_nullptr };

		bool expects_function         = false;

		// gen__ctx->parser.Scope->Start = currtok_noskip;

		if (currtok_noskip.Type == Tok_Preprocess_Hash)
			eat(Tok_Preprocess_Hash);

		switch (currtok_noskip.Type)
		{
			case Tok_Statement_End:
			{
				// TODO(Ed): Convert this to a general warning procedure
				gen_log_fmt("Dangling end statement found %SB\n", gen_tok_to_strbuilder(currtok_noskip));
				eat(Tok_Statement_End);
				continue;
			}
			case Tok_NewLine:
			{
				member = gen_fmt_newline;
				eat(Tok_NewLine);
				break;
			}
			case Tok_Comment:
			{
				member = gen_cast(gen_Code, gen_parse_comment());
				break;
			}
			case Tok_Access_Public:
			{
				member = gen_access_public;
				eat(Tok_Access_Public);
				eat(Tok_Assign_Classifer);
				// public:
				break;
			}
			case Tok_Access_Protected:
			{
				member = gen_access_protected;
				eat(Tok_Access_Protected);
				eat(Tok_Assign_Classifer);
				// protected:
				break;
			}
			case Tok_Access_Private:
			{
				member = gen_access_private;
				eat(Tok_Access_Private);
				eat(Tok_Assign_Classifer);
				// private:
				break;
			}
			case Tok_Decl_Class:
			{
				member = gen_parse_complicated_definition(Tok_Decl_Class);
				// class
				break;
			}
			case Tok_Decl_Enum:
			{
				member = gen_parse_complicated_definition(Tok_Decl_Enum);
				// enum
				break;
			}
			case Tok_Decl_Friend:
			{
				member = gen_cast(gen_Code, gen_parser_parse_friend());
				// friend
				break;
			}
			case Tok_Decl_Operator:
			{
				member = gen_cast(gen_Code, gen_parser_parse_operator_cast(gen_NullCode));
				// operator <Type>()
				break;
			}
			case Tok_Decl_Struct:
			{
				member = gen_parse_complicated_definition(Tok_Decl_Struct);
				// struct
				break;
			}
			case Tok_Decl_Template:
			{
				member = gen_cast(gen_Code, gen_parser_parse_template());
				// template< ... >
				break;
			}
			case Tok_Decl_Typedef:
			{
				member = gen_cast(gen_Code, gen_parser_parse_typedef());
				// typedef
				break;
			}
			case Tok_Decl_Union:
			{
				member = gen_parse_complicated_definition(Tok_Decl_Union);
				// union
				break;
			}
			case Tok_Decl_Using:
			{
				member = gen_cast(gen_Code, gen_parser_parse_using());
				// using
				break;
			}
			case Tok_Operator:
			{
				//if ( currtok.Text[0] != '~' )
				//{
				//	gen_log_failure( "gen_Operator token found in gen_global body but not gen_destructor_ unary negation\n%s", to_strbuilder(gen__ctx->parser) );
				//	return gen_InvalidCode;
				//}

				member = gen_cast(gen_Code, gen_parser_parse_destructor(gen_NullCode));
				// ~<Name>()
				break;
			}
			case Tok_Preprocess_Define:
			{
				member = gen_cast(gen_Code, gen_parser_parse_define());
				// #define
				break;
			}
			case Tok_Preprocess_Include:
			{
				member = gen_cast(gen_Code, gen_parse_include());
				// #include
				break;
			}

			case Tok_Preprocess_If:
			case Tok_Preprocess_IfDef:
			case Tok_Preprocess_IfNotDef:
			case Tok_Preprocess_ElIf:
				member = gen_cast(gen_Code, gen_parse_preprocess_cond());
				// #<Condition>
				break;

			case Tok_Preprocess_Else:
			{
				member = gen_cast(gen_Code, gen_preprocess_else);
				eat(Tok_Preprocess_Else);
				// #else
				break;
			}
			case Tok_Preprocess_EndIf:
			{
				member = gen_cast(gen_Code, gen_preprocess_endif);
				eat(Tok_Preprocess_EndIf);
				// #endif
				break;
			}

			case Tok_Preprocess_Macro_Stmt:
			{
				member = gen_cast(gen_Code, gen_parse_simple_preprocess(Tok_Preprocess_Macro_Stmt));
				break;
			}

				// case Tok_Preprocess_Macro:
				// 	// <gen_Macro>
				// 	gen_macro_found = true;
				// 	goto Preprocess_Macro_Bare_In_Body;
				// break;

			case Tok_Preprocess_Pragma:
			{
				member = gen_cast(gen_Code, gen_parse_pragma());
				// #pragma
				break;
			}

			case Tok_Preprocess_Unsupported:
			{
				member = gen_cast(gen_Code, gen_parse_simple_preprocess(Tok_Preprocess_Unsupported));
				// #<UNKNOWN>
				break;
			}

			case Tok_StaticAssert:
			{
				member = gen_parse_static_assert();
				// gen_static_assert
				break;
			}

			case Tok_Preprocess_Macro_Expr:
			{
				if (! gen_tok_is_attribute(currtok))
				{
					gen_log_failure("Unbounded macro expression residing in class/struct body\n%S", gen_parser_to_strbuilder(gen__ctx->parser));
					return gen_InvalidCode;
				}
			}
			//! Fallthrough intended
			case Tok_Attribute_Open:
			case Tok_Decl_GNU_Attribute:
			case Tok_Decl_MSVC_Attribute:
#define Entry(attribute, str) case attribute:
				GEN_DEFINE_ATTRIBUTE_TOKENS
#undef Entry
				{
					attributes = gen_parse_attributes();
					// <Attributes>
				}
			//! Fallthrough intended
			GEN_PARSER_CLASS_STRUCT_BODY_ALLOWED_MEMBER_TOK_SPECIFIER_CASES:
			{
				gen_Specifier specs_found[16] = { Spec_NumSpecifiers };
				gen_s32       NumSpecifiers   = 0;

				while (left && gen_tok_is_specifier(currtok))
				{
					gen_Specifier spec  = gen_str_to_specifier(currtok.Text);

					gen_b32 ignore_spec = false;

					switch (spec)
					{
					GEN_PARSER_CLASS_STRUCT_BODY_ALLOWED_MEMBER_SPECIFIER_CASES:
						break;

						case Spec_Consteval:
							expects_function = true;
							break;

						case Spec_Const:
							ignore_spec = true;
							break;

						default:
							gen_log_failure(
							    "Invalid specifier %S for class/struct member\n%S",
							    gen_spec_to_str(spec),
							    gen_strbuilder_to_str(gen_parser_to_strbuilder(gen__ctx->parser))
							);
							gen_parser_pop(&gen__ctx->parser);
							return gen_InvalidCode;
					}

					// Every specifier after would be considered part of the type type signature
					if (ignore_spec)
						break;

					specs_found[NumSpecifiers] = spec;
					NumSpecifiers++;
					eat(currtok.Type);
				}

				if (NumSpecifiers)
				{
					specifiers = gen_def_specifiers_arr(NumSpecifiers, specs_found);
				}
				// <Attributes> <Specifiers>

				if (gen_tok_is_attribute(currtok))
				{
					// Unfortuantely Unreal has code where there is attirbutes before specifiers
					gen_CodeAttributes more_attributes = gen_parse_attributes();

					if (attributes)
					{
						gen_StrBuilder fused = gen_strbuilder_make_reserve(gen__ctx->Allocator_Temp, attributes->Content.Len + more_attributes->Content.Len);
						gen_strbuilder_append_fmt(&fused, "%SB %SB", attributes->Content, more_attributes->Content);

						gen_Str attrib_name = gen_strbuilder_to_str(fused);
						attributes->Name    = gen_cache_str(attrib_name);
						attributes->Content = attributes->Name;
						// <Attributes> <Specifiers> <Attributes>
					}

					attributes = more_attributes;
				}

				if (currtok.Type == Tok_Operator && currtok.Text.Ptr[0] == '~')
				{
					member = gen_cast(gen_Code, gen_parser_parse_destructor(specifiers));
					// <Attribute> <Specifiers> ~<Name>()
					break;
				}

				if (currtok.Type == Tok_Decl_Operator)
				{
					member = gen_cast(gen_Code, gen_parser_parse_operator_cast(specifiers));
					// <Attributes> <Specifiers> operator <Type>()
					break;
				}
			}
			//! Fallthrough intentional
			case Tok_Identifier:
			case Tok_Preprocess_Macro_Typename:
			case Tok_Spec_Const:
			case Tok_Type_Unsigned:
			case Tok_Type_Signed:
			case Tok_Type_Short:
			case Tok_Type_Long:
			case Tok_Type_bool:
			case Tok_Type_char:
			case Tok_Type_int:
			case Tok_Type_double:
			{
				if (nexttok.Type == Tok_Paren_Open && name.Text.Len && currtok.Type == Tok_Identifier)
				{
					if (gen_c_str_compare_len(name.Text.Ptr, currtok.Text.Ptr, name.Text.Len) == 0)
					{
						member = gen_cast(gen_Code, gen_parser_parse_constructor(specifiers));
						// <Attributes> <Specifiers> <Name>()
						break;
					}
				}

				member = gen_parse_operator_function_or_variable(expects_function, attributes, specifiers);
				// <Attributes> <Specifiers> operator <Op> ...
				// or
				// <Attributes> <Specifiers> <Name> ...
			}
			break;

			default:
				gen_Token gen_untyped_tok = currtok;
				while (left && currtok.Type != Tok_BraceCurly_Close)
				{
					gen_untyped_tok.Text.Len = ((gen_sptr)currtok.Text.Ptr + currtok.Text.Len) - (gen_sptr)gen_untyped_tok.Text.Ptr;
					eat(currtok.Type);
				}
				member = gen_untyped_str(gen_untyped_tok.Text);
				// Something unknown
				break;
		}

		if (member == gen_Code_Invalid)
		{
			gen_log_failure("Failed to parse member\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}
		gen_body_append(result, member);
	}

	eat(Tok_BraceCurly_Close);
	// { <Members> }
	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_CodeComment gen_parse_comment()
{
	push_scope();

	gen_CodeComment result = (gen_CodeComment)gen_make_code();
	result->Type           = CT_Comment;
	result->Content        = gen_cache_str(currtok_noskip.Text);
	// result->gen_Token   = currtok_noskip;
	eat(Tok_Comment);

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_Code gen_parse_complicated_definition(gen_TokType which)
{
	push_scope();

	gen_b32 is_inplace  = false;
	gen_b32 is_fn_def   = false;

	gen_TokArray tokens = gen__ctx->parser.Tokens;

	gen_s32 idx         = tokens.Idx;
	gen_s32 level       = 0;
	gen_b32 had_def     = false;
	gen_b32 had_paren   = false;
	for (; idx < gen_array_num(tokens.Arr); idx++)
	{
		if (tokens.Arr[idx].Type == Tok_BraceCurly_Open)
			level++;

		if (tokens.Arr[idx].Type == Tok_BraceCurly_Close)
		{
			level--;
			had_def = level == 0;
		}

		gen_b32 found_fn_def = had_def && had_paren;

		if (level == 0 && (tokens.Arr[idx].Type == Tok_Statement_End || found_fn_def))
			break;
	}

	is_fn_def = had_def && had_paren;
	if (is_fn_def)
	{
		// Function definition with <which> on return type
		gen_Code result = gen_parse_operator_function_or_variable(false, gen_NullCode, gen_NullCode);
		// <which> <typename>(...) ... { ... }
		gen_parser_pop(&gen__ctx->parser);
		return result;
	}

	if ((idx - 2) == tokens.Idx)
	{
		// It's a forward declaration only
		gen_Code result = gen_parse_forward_or_definition(which, is_inplace);
		// <class, enum, struct, or union> <Name>;
		gen_parser_pop(&gen__ctx->parser);
		return result;
	}

	gen_Token tok = tokens.Arr[idx - 1];
	if (gen_tok_is_specifier(tok) && gen_spec_is_trailing(gen_str_to_specifier(tok.Text)))
	{
		// <which> <type_identifier>(...) <specifier> ...;

		gen_s32   gen_spec_idx = idx - 1;
		gen_Token spec         = tokens.Arr[gen_spec_idx];
		while (gen_tok_is_specifier(spec) && gen_spec_is_trailing(gen_str_to_specifier(spec.Text)))
		{
			--gen_spec_idx;
			spec = tokens.Arr[gen_spec_idx];
		}

		if (tokens.Arr[gen_spec_idx].Type == Tok_Paren_Close)
		{
			// Forward declaration with trailing specifiers for a procedure
			tok             = tokens.Arr[gen_spec_idx];

			gen_Code result = gen_parse_operator_function_or_variable(false, gen_NullCode, gen_NullCode);
			// <Attributes> <Specifiers> <ReturnType/ValueType> <operator <Op>, or Name> ...
			gen_parser_pop(&gen__ctx->parser);
			return result;
		}

		gen_log_failure("Unsupported or bad member definition after %s declaration\n%s", gen_toktype_to_str(which), gen_parser_to_strbuilder(gen__ctx->parser));
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}
	if (tok.Type == Tok_Identifier)
	{
		tok                 = tokens.Arr[idx - 2];
		bool is_indirection = tok.Type == Tok_Ampersand || tok.Type == Tok_Star;
		bool ok_to_parse    = false;

		if (tok.Type == Tok_BraceCurly_Close)
		{
			// Its an inplace definition
			// <which> <type_identifier ?> { ... } <identifier>;
			ok_to_parse           = true;
			is_inplace            = true;

			gen_CodeTypename type = gen_cast(gen_CodeTypename, gen_parse_forward_or_definition(which, is_inplace));

			// Should be a name right after the type.
			gen_Token name               = gen_parse_identifier(gen_nullptr);
			gen__ctx->parser.Scope->Name = name.Text;

			gen_CodeVar result           = gen_parse_variable_after_name(ModuleFlag_None, gen_NullCode, gen_NullCode, type, name.Text);
			gen_parser_pop(&gen__ctx->parser);
			return (gen_Code)result;
		}
		else if (tok.Type == Tok_Identifier && tokens.Arr[idx - 3].Type == which)
		{
			// Its a variable with type ID using <which> namespace.
			// <which> <type_identifier> <identifier>;
			ok_to_parse = true;
		}
		else if (tok.Type == Tok_Assign_Classifer
		         && ((tokens.Arr[idx - 5].Type == which && tokens.Arr[idx - 4].Type == Tok_Decl_Class) || (tokens.Arr[idx - 4].Type == which)))
		{
			// Its a forward declaration of an enum
			// <enum>         <type_identifier> : <identifier>;
			// <enum> <class> <type_identifier> : <identifier>;
			ok_to_parse     = true;
			gen_Code result = gen_cast(gen_Code, gen_parser_parse_enum(! gen_parser_inplace_def));
			gen_parser_pop(&gen__ctx->parser);
			return result;
		}
		else if (is_indirection)
		{
			// Its a indirection type with type ID using struct namespace.
			// <which> <type_identifier>* <identifier>;
			ok_to_parse = true;
		}

		if (! ok_to_parse)
		{
			gen_log_failure(
			    "Unsupported or bad member definition after %s declaration\n%s",
			    gen_toktype_to_str(which),
			    gen_parser_to_strbuilder(gen__ctx->parser)
			);
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}

		gen_Code result = gen_parse_operator_function_or_variable(false, gen_NullCode, gen_NullCode);
		// <Attributes> <Specifiers> <ReturnType/ValueType> <operator <Op>, or Name> ...
		gen_parser_pop(&gen__ctx->parser);
		return result;
	}
	else if (tok.Type >= Tok_Type_Unsigned && tok.Type <= Tok_Type_MS_W64)
	{
		tok = tokens.Arr[idx - 2];

		if (tok.Type != Tok_Assign_Classifer
		    || ((tokens.Arr[idx - 5].Type != which && tokens.Arr[idx - 4].Type != Tok_Decl_Class) && (tokens.Arr[idx - 4].Type != which)))
		{
			gen_log_failure(
			    "Unsupported or bad member definition after %s declaration\n%s",
			    gen_toktype_to_str(which),
			    gen_parser_to_strbuilder(gen__ctx->parser)
			);
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}

		// Its a forward declaration of an enum class
		// <enum>         <type_identifier> : <identifier>;
		// <enum> <class> <type_identifier> : <identifier>;
		gen_Code result = gen_cast(gen_Code, gen_parser_parse_enum(! gen_parser_inplace_def));
		gen_parser_pop(&gen__ctx->parser);
		return result;
	}
	else if (tok.Type == Tok_BraceCurly_Close)
	{
		// Its a definition
		gen_Code result = gen_parse_forward_or_definition(which, is_inplace);
		// <which> { ... };
		gen_parser_pop(&gen__ctx->parser);
		return result;
	}
	else if (tok.Type == Tok_BraceSquare_Close)
	{
		// Its an array definition
		gen_Code result = gen_parse_operator_function_or_variable(false, gen_NullCode, gen_NullCode);
		// <which> <type_identifier> <identifier> [ ... ];
		gen_parser_pop(&gen__ctx->parser);
		return result;
	}
	else
	{
		gen_log_failure(
		    "Unsupported or bad member definition after %s declaration\n%SB",
		    gen_toktype_to_str(which).Ptr,
		    gen_parser_to_strbuilder(gen__ctx->parser)
		);
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}
}

gen_internal inline gen_Code gen_parse_assignment_expression()
{
	gen_Code expr = { gen_nullptr };

	eat(Tok_Operator);
	// <Attributes> <Specifiers> <ValueType> <Name> =

	gen_Token expr_tok = currtok;

	if (currtok.Type == Tok_Statement_End && currtok.Type != Tok_Comma)
	{
		gen_log_failure("Expected expression after assignment operator\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}

	gen_s32 level = 0;
	while (left && currtok.Type != Tok_Statement_End && (currtok.Type != Tok_Comma || level > 0))
	{
		if (currtok.Type == Tok_BraceCurly_Open)
			level++;
		if (currtok.Type == Tok_BraceCurly_Close)
			level--;
		if (currtok.Type == Tok_Paren_Open)
			level++;
		else if (currtok.Type == Tok_Paren_Close)
			level--;

		eat(currtok.Type);
	}

	expr_tok.Text.Len = ((gen_sptr)currtok.Text.Ptr + currtok.Text.Len) - (gen_sptr)expr_tok.Text.Ptr - 1;
	expr              = gen_untyped_str(expr_tok.Text);
	// = <Expression>
	return expr;
}

gen_internal inline gen_Code gen_parse_forward_or_definition(gen_TokType which, bool is_inplace)
{
	gen_Code result = gen_InvalidCode;

	switch (which)
	{
		case Tok_Decl_Class:
			result = gen_cast(gen_Code, gen_parser_parse_class(is_inplace));
			return result;

		case Tok_Decl_Enum:
			result = gen_cast(gen_Code, gen_parser_parse_enum(is_inplace));
			return result;

		case Tok_Decl_Struct:
			result = gen_cast(gen_Code, gen_parser_parse_struct(is_inplace));
			return result;

		case Tok_Decl_Union:
			result = gen_cast(gen_Code, gen_parser_parse_union(is_inplace));
			return result;

		default:
			gen_log_failure(
			    "Error, wrong token type given to gen_parse_complicated_definition "
			    "(only supports class, enum, struct, union) \n%s",
			    gen_parser_to_strbuilder(gen__ctx->parser)
			);

			return gen_InvalidCode;
	}
}

// Function parsing is handled in multiple places because its initial signature is shared with variable parsing
gen_internal inline gen_CodeFn gen_parse_function_after_name(
    gen_ModuleFlag     mflags,
    gen_CodeAttributes attributes,
    gen_CodeSpecifiers specifiers,
    gen_CodeTypename   ret_type,
    gen_Token          name
)
{
	push_scope();
	gen_CodeParams params = gen_parse_params(gen_parser_use_parenthesis);
	// <Attributes> <Specifiers> <ReturnType> <Name> ( <Parameters> )

	gen_Code suffix_specs = gen_NullCode;

	// TODO(Ed), Review old comment : These have to be kept separate from the return type's specifiers.
	while (left && gen_tok_is_specifier(currtok))
	{
		// For Unreal's PURE_VIRTUAL Support
		gen_Macro* macro = lookup_macro(currtok.Text);
		if (macro && gen_tok_is_specifier(currtok))
		{
			suffix_specs = gen_parse_simple_preprocess(Tok_Preprocess_Macro_Expr);
			continue;
		}
		if (specifiers == gen_nullptr)
		{
			specifiers = gen_def_specifier(gen_str_to_specifier(currtok.Text));
			eat(currtok.Type);
			continue;
		}

		gen_specifiers_append(specifiers, gen_str_to_specifier(currtok.Text));
		eat(currtok.Type);
	}
	// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers>

	gen_CodeBody    body       = gen_NullCode;
	gen_CodeComment inline_cmt = gen_NullCode;
	if (check(Tok_BraceCurly_Open))
	{
		body = gen_cast(gen_CodeBody, gen_parse_function_body());
		if (gen_cast(gen_Code, body) == gen_Code_Invalid)
		{
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}
		// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers> { <Body> }
	}
	else if (check(Tok_Operator) && currtok.Text.Ptr[0] == '=')
	{
		eat(Tok_Operator);
		if (specifiers == gen_nullptr)
		{
			specifiers       = (gen_CodeSpecifiers)gen_make_code();
			specifiers->Type = CT_Specifiers;
		}
		if (gen_str_are_equal(nexttok.Text, txt("delete")))
		{
			gen_specifiers_append(specifiers, Spec_Delete);
			eat(currtok.Type);
			// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers> = delete
		}
		else
		{
			gen_specifiers_append(specifiers, Spec_Pure);

			eat(Tok_Number);
			// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers> = 0
		}
		gen_Token stmt_end = currtok;
		eat(Tok_Statement_End);

		if (currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line)
			inline_cmt = gen_parse_comment();
		// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers>; <InlineCmt>
	}
	else
	{
		gen_Token stmt_end = currtok;
		eat(Tok_Statement_End);
		// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers>;

		if (currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line)
			inline_cmt = gen_parse_comment();
		// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers>; <InlineCmt>
	}

	gen_StrBuilder name_stripped = gen_strbuilder_make_str(gen__ctx->Allocator_Temp, name.Text);
	gen_strbuilder_strip_space(name_stripped);

	gen_CodeFn result   = (gen_CodeFn)gen_make_code();
	result->Name        = gen_cache_str(gen_strbuilder_to_str(name_stripped));
	result->ModuleFlags = mflags;

	if (body)
	{
		switch (body->Type)
		{
			case CT_Function_Body:
			case CT_Untyped:
				break;

			default:
			{
				gen_log_failure(
				    "Body must be either of Function_Body or Untyped type, %s\n%s",
				    gen_code_debug_str(body),
				    gen_parser_to_strbuilder(gen__ctx->parser)
				);
				gen_parser_pop(&gen__ctx->parser);
				return gen_InvalidCode;
			}
		}

		result->Type = CT_Function;
		result->Body = body;
	}
	else
	{
		result->Type = CT_Function_Fwd;
	}

	if (attributes)
		result->Attributes = attributes;

	if (specifiers)
		result->Specs = specifiers;

	if (suffix_specs)
		result->SuffixSpecs = suffix_specs;

	result->ReturnType = ret_type;

	if (params)
		result->Params = params;

	if (inline_cmt)
		result->InlineCmt = inline_cmt;

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_Code gen_parse_function_body()
{
	push_scope();

	eat(Tok_BraceCurly_Open);

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = CT_Function_Body;

	// TODO : Support actual parsing of function body
	gen_Token start = currtok_noskip;

	gen_s32 level   = 0;
	while (left && (currtok_noskip.Type != Tok_BraceCurly_Close || level > 0))
	{
		if (currtok_noskip.Type == Tok_BraceCurly_Open)
			level++;

		else if (currtok_noskip.Type == Tok_BraceCurly_Close && level > 0)
			level--;

		eat(currtok_noskip.Type);
	}

	gen_Token past = prevtok;

	gen_s32 len    = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)start.Text.Ptr;

	if (len > 0)
	{
		gen_Str str = { start.Text.Ptr, len };
		gen_body_append(result, gen_cast(gen_Code, gen_def_execution(str)));
	}

	eat(Tok_BraceCurly_Close);

	gen_parser_pop(&gen__ctx->parser);
	return gen_cast(gen_Code, result);
}

gen_internal gen_neverinline gen_CodeBody gen_parse_global_nspace(gen_CodeType which)
{
	push_scope();

	if (which != CT_Namespace_Body && which != CT_Global_Body && which != CT_Export_Body && which != CT_Extern_Linkage_Body)
		return gen_InvalidCode;

	if (which != CT_Global_Body)
		eat(Tok_BraceCurly_Open);
	// {

	gen_CodeBody result = (gen_CodeBody)gen_make_code();
	result->Type        = which;

	while (left && currtok_noskip.Type != Tok_BraceCurly_Close)
	{
		gen_Code           member     = gen_Code_Invalid;
		gen_CodeAttributes attributes = { gen_nullptr };
		gen_CodeSpecifiers specifiers = { gen_nullptr };

		bool expects_function         = false;

		// gen__ctx->parser.Scope->Start = currtok_noskip;

		if (currtok_noskip.Type == Tok_Preprocess_Hash)
			eat(Tok_Preprocess_Hash);

		gen_b32 gen_macro_found = false;

		switch (currtok_noskip.Type)
		{
			case Tok_Comma:
			{
				gen_log_failure("Dangling comma found: %SB\nContext:\n%SB", gen_tok_to_strbuilder(currtok), gen_parser_to_strbuilder(gen__ctx->parser));
				gen_parser_pop(&gen__ctx->parser);
				return gen_InvalidCode;
			}
			break;
			case Tok_Statement_End:
			{
				// TODO(Ed): Convert this to a general warning procedure
				gen_log_fmt("Dangling end statement found %SB\n", gen_tok_to_strbuilder(currtok_noskip));
				eat(Tok_Statement_End);
				continue;
			}
			case Tok_NewLine:
				// Empty lines are auto skipped by Tokens.current()
				member = gen_fmt_newline;
				eat(Tok_NewLine);
				break;

			case Tok_Comment:
				member = gen_cast(gen_Code, gen_parse_comment());
				break;

			case Tok_Decl_Class:
				member = gen_parse_complicated_definition(Tok_Decl_Class);
				// class
				break;

			case Tok_Decl_Enum:
				member = gen_parse_complicated_definition(Tok_Decl_Enum);
				// enum
				break;

			case Tok_Decl_Extern_Linkage:
				if (which == CT_Extern_Linkage_Body)
					gen_log_failure("Nested extern linkage\n%s", gen_parser_to_strbuilder(gen__ctx->parser));

				member = gen_cast(gen_Code, gen_parser_parse_extern_link());
				// extern "..." { ... }
				break;

			case Tok_Decl_Namespace:
				member = gen_cast(gen_Code, gen_parser_parse_namespace());
				// namespace <Name> { ... }
				break;

			case Tok_Decl_Struct:
				member = gen_parse_complicated_definition(Tok_Decl_Struct);
				// struct ...
				break;

			case Tok_Decl_Template:
				member = gen_cast(gen_Code, gen_parser_parse_template());
				// template<...> ...
				break;

			case Tok_Decl_Typedef:
				member = gen_cast(gen_Code, gen_parser_parse_typedef());
				// typedef ...
				break;

			case Tok_Decl_Union:
				member = gen_parse_complicated_definition(Tok_Decl_Union);
				// union ...
				break;

			case Tok_Decl_Using:
				member = gen_cast(gen_Code, gen_parser_parse_using());
				// using ...
				break;

			case Tok_Preprocess_Define:
				member = gen_cast(gen_Code, gen_parser_parse_define());
				// #define ...
				break;

			case Tok_Preprocess_Include:
				member = gen_cast(gen_Code, gen_parse_include());
				// #include ...
				break;

			case Tok_Preprocess_If:
			case Tok_Preprocess_IfDef:
			case Tok_Preprocess_IfNotDef:
			case Tok_Preprocess_ElIf:
				member = gen_cast(gen_Code, gen_parse_preprocess_cond());
				// #<Conditional> ...
				break;

			case Tok_Preprocess_Else:
				member = gen_cast(gen_Code, gen_preprocess_else);
				eat(Tok_Preprocess_Else);
				// #else
				break;

			case Tok_Preprocess_EndIf:
				member = gen_cast(gen_Code, gen_preprocess_endif);
				eat(Tok_Preprocess_EndIf);
				// #endif
				break;

			case Tok_Preprocess_Macro_Stmt:
			{
				member = gen_cast(gen_Code, gen_parse_simple_preprocess(Tok_Preprocess_Macro_Stmt));
				break;
			}

			case Tok_Preprocess_Pragma:
			{
				member = gen_cast(gen_Code, gen_parse_pragma());
				// #pragma ...
			}
			break;

			case Tok_Preprocess_Unsupported:
			{
				member = gen_cast(gen_Code, gen_parse_simple_preprocess(Tok_Preprocess_Unsupported));
				// #<UNSUPPORTED> ...
			}
			break;

			case Tok_StaticAssert:
			{
				member = gen_cast(gen_Code, gen_parse_static_assert());
				// gen_static_assert( <Conditional Expression>, ... );
			}
			break;

			case Tok_Module_Export:
			{
				if (which == CT_Export_Body)
					gen_log_failure("Nested export declaration\n%s", gen_parser_to_strbuilder(gen__ctx->parser));

				member = gen_cast(gen_Code, gen_parser_parse_export_body());
				// export { ... }
			}
			break;

			case Tok_Module_Import:
			{
				// import ...
				gen_log_failure("gen::%s: This function is not implemented");
				return gen_InvalidCode;
			}
			break;

			case Tok_Preprocess_Macro_Expr:
			{
				if (gen_tok_is_attribute(currtok))
				{
					gen_log_failure("Unbounded macro expression residing in class/struct body\n%S", gen_parser_to_strbuilder(gen__ctx->parser));
					return gen_InvalidCode;
				}
			}
			//! Fallthrough intentional
			case Tok_Attribute_Open:
			case Tok_Decl_GNU_Attribute:
			case Tok_Decl_MSVC_Attribute:
#define Entry(attribute, str) case attribute:
				GEN_DEFINE_ATTRIBUTE_TOKENS
#undef Entry
				{
					attributes = gen_parse_attributes();
					// <Attributes>
				}
			//! Fallthrough intentional
			GEN_PARSER_CLASS_GLOBAL_NSPACE_ALLOWED_MEMBER_TOK_SPECIFIER_CASES:
			{
				gen_Specifier specs_found[16] = { Spec_NumSpecifiers };
				gen_s32       NumSpecifiers   = 0;

				while (left && gen_tok_is_specifier(currtok))
				{
					gen_Specifier spec = gen_str_to_specifier(currtok.Text);

					bool ignore_spec   = false;

					switch (spec)
					{
					GEN_PARSER_CLASS_GLOBAL_NSPACE_ALLOWED_MEMBER_SPECIFIER_CASES:
						break;

						case Spec_Consteval:
							expects_function = true;
							break;

						case Spec_Const:
							ignore_spec = true;
							break;

						default:
							gen_Str gen_spec_str = gen_spec_to_str(spec);

							gen_log_failure(
							    "Invalid specifier %S for variable\n%S",
							    gen_spec_str,
							    gen_strbuilder_to_str(gen_parser_to_strbuilder(gen__ctx->parser))
							);
							gen_parser_pop(&gen__ctx->parser);
							return gen_InvalidCode;
					}

					if (ignore_spec)
						break;

					specs_found[NumSpecifiers] = spec;
					NumSpecifiers++;
					eat(currtok.Type);
				}

				if (NumSpecifiers)
				{
					specifiers = gen_def_specifiers_arr(NumSpecifiers, specs_found);
				}
				// <Attributes> <Specifiers>
			}
			//! Fallthrough intentional
			case Tok_Identifier:
			case Tok_Preprocess_Macro_Typename:
			case Tok_Spec_Const:
			case Tok_Type_Long:
			case Tok_Type_Short:
			case Tok_Type_Signed:
			case Tok_Type_Unsigned:
			case Tok_Type_bool:
			case Tok_Type_char:
			case Tok_Type_double:
			case Tok_Type_int:
			{
				// This s only in a scope so that Preprocess_Macro_Bare_In_Body works without microsoft extension warnings
				{
					gen_Code gen_constructor__destructor = gen_parse_global_nspace_constructor_destructor(specifiers);
					// Possible gen_constructor_ implemented at gen_global file scope.
					if (gen_constructor__destructor)
					{
						member = gen_constructor__destructor;
						break;
					}

					bool    found_operator_cast_outside_class_implmentation = false;
					gen_s32 idx                                             = gen__ctx->parser.Tokens.Idx;

					for (; idx < gen_array_num(gen__ctx->parser.Tokens.Arr); idx++)
					{
						gen_Token tok = gen__ctx->parser.Tokens.Arr[idx];

						if (tok.Type == Tok_Identifier)
						{
							idx++;
							tok = gen__ctx->parser.Tokens.Arr[idx];
							if (tok.Type == Tok_Access_StaticSymbol)
								continue;

							break;
						}

						if (tok.Type == Tok_Decl_Operator)
							found_operator_cast_outside_class_implmentation = true;

						break;
					}

					if (found_operator_cast_outside_class_implmentation)
					{
						member = gen_cast(gen_Code, gen_parser_parse_operator_cast(specifiers));
						// <Attributes> <Specifiers> <Name>::operator <Type>() { ... }
						break;
					}
				}

				member = gen_parse_operator_function_or_variable(expects_function, attributes, specifiers);
				// <Attributes> <Specifiers> ...
			}
		}

		if (member == gen_Code_Invalid)
		{
			gen_log_failure(
			    "Failed to parse member\nToken: %SB\nContext:\n%SB",
			    gen_tok_to_strbuilder(currtok_noskip),
			    gen_parser_to_strbuilder(gen__ctx->parser)
			);
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}

		// gen_log_fmt("Global Body Member: %s", member->debug_str());
		gen_body_append(result, member);
	}

	if (which != CT_Global_Body)
		eat(Tok_BraceCurly_Close);
	// { <Body> }

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal inline gen_Code gen_parse_global_nspace_constructor_destructor(gen_CodeSpecifiers specifiers)
{
	gen_Code result = { gen_nullptr };

	/*
		To check if a definition is for a gen_constructor_ we can go straight to the opening parenthesis for its parameters
		From There we work backwards to see if we come across two identifiers with the same name between an member access
		:: operator, there can be template parameters on the left of the :: so we ignore those.
		Whats important is that	its back to back.

		This has multiple possible faults. What we parse using this method may not filter out if something has a "return type"
		This is bad since technically you could have a namespace nested into another namespace with the same name.
		If this awful pattern is done the only way to distiguish with this coarse parse is to know there is no return type defined.

		TODO(Ed): We could fix this by attempting to parse a type, but we would have to have a way to have it soft fail and rollback.
	*/
	gen_TokArray tokens = gen__ctx->parser.Tokens;

	gen_s32   idx       = tokens.Idx;
	gen_Token nav       = tokens.Arr[idx];
	for (; idx < gen_array_num(tokens.Arr); idx++, nav = tokens.Arr[idx])
	{
		if (nav.Text.Ptr[0] == '<')
		{
			// Skip templated expressions as they mey have expressions with the () operators
			gen_s32 capture_level      = 0;
			gen_s32 gen_template_level = 0;
			for (; idx < gen_array_num(tokens.Arr); idx++, nav = tokens.Arr[idx])
			{
				if (nav.Text.Ptr[0] == '<')
					++gen_template_level;

				if (nav.Text.Ptr[0] == '>')
					--gen_template_level;
				if (nav.Type == Tok_Operator && nav.Text.Ptr[1] == '>')
					--gen_template_level;

				if (nav.Type == Tok_Paren_Open)
				{
					if (gen_template_level != 0)
						++capture_level;
					else
						break;
				}

				if (gen_template_level != 0 && nav.Type == Tok_Paren_Close)
					--capture_level;
			}
		}

		if (nav.Type == Tok_Paren_Open)
			break;
	}

	--idx;
	gen_Token gen_tok_right = tokens.Arr[idx];
	gen_Token gen_tok_left  = gen_NullToken;

	if (gen_tok_right.Type != Tok_Identifier)
	{
		// We're not dealing with a gen_constructor_ if there is no identifier right before the opening of a parameter's scope.
		return result;
	}

	--idx;
	gen_tok_left = tokens.Arr[idx];
	// <Attributes> <Specifiers> ... <Identifier>

	bool possible_destructor = false;
	if (gen_tok_left.Type == Tok_Operator && gen_tok_left.Text.Ptr[0] == '~')
	{
		possible_destructor = true;
		--idx;
		gen_tok_left = tokens.Arr[idx];
	}

	if (gen_tok_left.Type != Tok_Access_StaticSymbol)
		return result;

	--idx;
	gen_tok_left = tokens.Arr[idx];
	// <Attributes> <Specifiers> ... :: <Identifier>

	// We search toward the left until we find the next valid identifier
	gen_s32 capture_level      = 0;
	gen_s32 gen_template_level = 0;
	while (idx != tokens.Idx)
	{
		if (gen_tok_left.Text.Ptr[0] == '<')
			++gen_template_level;

		if (gen_tok_left.Text.Ptr[0] == '>')
			--gen_template_level;
		if (gen_tok_left.Type == Tok_Operator && gen_tok_left.Text.Ptr[1] == '>')
			--gen_template_level;

		if (gen_template_level != 0 && gen_tok_left.Type == Tok_Paren_Open)
			++capture_level;

		if (gen_template_level != 0 && gen_tok_left.Type == Tok_Paren_Close)
			--capture_level;

		if (capture_level == 0 && gen_template_level == 0 && gen_tok_left.Type == Tok_Identifier)
			break;

		--idx;
		gen_tok_left = tokens.Arr[idx];
	}

	bool is_same = gen_c_str_compare_len(gen_tok_right.Text.Ptr, gen_tok_left.Text.Ptr, gen_tok_right.Text.Len) == 0;
	if (gen_tok_left.Type == Tok_Identifier && is_same)
	{
		// We have found the pattern we desired
		if (possible_destructor)
		{
			// <Name> :: ~<Name> (
			result = gen_cast(gen_Code, gen_parser_parse_destructor(specifiers));
		}
		else
		{
			// <Name> :: <Name> (
			result = gen_cast(gen_Code, gen_parser_parse_constructor(specifiers));
		}
	}

	return result;
}

// TODO(Ed): I want to eventually change the identifier to its own gen_AST type.
// This would allow distinction of the qualifier for a symbol <qualifier>::<nested symboL>
// This would also allow
gen_internal gen_Token gen_parse_identifier(bool* possible_member_function)
{
	push_scope();

	gen_Token name                  = currtok;
	gen__ctx->parser.Scope->Name    = name.Text;

	gen_Macro* macro                = lookup_macro(currtok.Text);
	gen_b32    accept_as_identifier = macro && gen_bitfield_is_set(gen_MacroFlags, macro->Flags, MF_Allow_As_Identifier);

	// Typename can be: '::' <name>
	// If that is the case first  option will be Tok_Access_StaticSymbol below
	if (check(Tok_Identifier) || accept_as_identifier)
		eat(Tok_Identifier);
	// <Name>

	gen_parse_template_args(&name);
	// <Name><Template Args>

	while (check(Tok_Access_StaticSymbol))
	{
		eat(Tok_Access_StaticSymbol);
		// <Qualifier Name> <Template Args> ::

		gen_Token invalid = gen_NullToken;
		if (left == 0)
		{
			gen_log_failure("Error, unexpected end of static symbol identifier\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
			gen_parser_pop(&gen__ctx->parser);
			return invalid;
		}

		if (currtok.Type == Tok_Operator && currtok.Text.Ptr[0] == '~')
		{
			bool is_destructor = gen_str_are_equal(gen__ctx->parser.Scope->Prev->ProcName, txt("gen_parser_parse_destructor"));
			if (is_destructor)
			{
				name.Text.Len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)name.Text.Ptr;
				gen_parser_pop(&gen__ctx->parser);
				return name;
			}

			gen_log_failure(
			    "Error, had a ~ operator after %SB but not a gen_destructor_\n%s",
			    gen_toktype_to_str(prevtok.Type),
			    gen_parser_to_strbuilder(gen__ctx->parser)
			);
			gen_parser_pop(&gen__ctx->parser);
			return invalid;
		}

		if (currtok.Type == Tok_Operator && currtok.Text.Ptr[0] == '*' && currtok.Text.Len == 1)
		{
			if (possible_member_function)
				*possible_member_function = true;

			else
			{
				gen_log_failure(
				    "Found a member function pointer identifier but the parsing context did not expect it\n%s",
				    gen_parser_to_strbuilder(gen__ctx->parser)
				);
				gen_parser_pop(&gen__ctx->parser);
				return invalid;
			}
		}

		if (currtok.Type != Tok_Identifier)
		{
			gen_log_failure(
			    "Error, expected static symbol identifier, not %s\n%s",
			    gen_toktype_to_str(currtok.Type),
			    gen_parser_to_strbuilder(gen__ctx->parser)
			);
			gen_parser_pop(&gen__ctx->parser);
			return invalid;
		}

		name.Text.Len = ((gen_sptr)currtok.Text.Ptr + currtok.Text.Len) - (gen_sptr)name.Text.Ptr;
		eat(Tok_Identifier);
		// <Qualifier Name> <Template Args> :: <Name>

		gen_parse_template_args(&name);
		// <Qualifier Name> <Template Args> :: <Name> <Template Args>
	}
	// <Qualifier Name> <Template Args> :: <Name> <Template Args> ...

	gen_parser_pop(&gen__ctx->parser);
	return name;
}

gen_internal gen_CodeInclude gen_parse_include()
{
	push_scope();

	gen_CodeInclude include = (gen_CodeInclude)gen_make_code();
	include->Type           = CT_Preprocess_Include;
	eat(Tok_Preprocess_Include);
	// #include

	if (! check(Tok_String))
	{
		gen_log_failure("Error, expected include string after #include\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}

	gen__ctx->parser.Scope->Name = currtok.Text;
	include->Content             = gen_cache_str(currtok.Text);
	eat(Tok_String);
	// #include <Path> or "Path"

	gen_parser_pop(&gen__ctx->parser);
	return include;
}

gen_internal gen_CodeOperator
    gen_parse_operator_after_ret_type(gen_ModuleFlag mflags, gen_CodeAttributes attributes, gen_CodeSpecifiers specifiers, gen_CodeTypename ret_type)
{
	push_scope();

	gen_Token nspace = gen_NullToken;
	if (check(Tok_Identifier))
	{
		nspace = currtok;
		while (left && currtok.Type == Tok_Identifier)
		{
			eat(Tok_Identifier);

			if (currtok.Type == Tok_Access_StaticSymbol)
				eat(Tok_Access_StaticSymbol);
		}

		nspace.Text.Len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)nspace.Text.Ptr;
	}
	// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...>

	eat(Tok_Decl_Operator);
	// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator

	if (! left && currtok.Type != Tok_Operator && currtok.Type != Tok_Star && currtok.Type != Tok_Ampersand && currtok.Type != Tok_Ampersand_DBL)
	{
		gen_log_failure("Expected operator after 'operator' keyword\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}

	gen__ctx->parser.Scope->Name = currtok.Text;

	bool was_new_or_delete       = false;

	gen_Operator op              = Op_Invalid;
	switch (currtok.Text.Ptr[0])
	{
		case '+':
		{
			if (currtok.Text.Ptr[1] == '=')
				op = Op_Assign_Add;

			else if (currtok.Text.Ptr[1] == '+')
				op = Op_Increment;

			else
				op = Op_Add;
		}
		break;
		case '-':
		{
			if (currtok.Text.Ptr[1] == '>')
			{
				if (currtok.Text.Ptr[2] == '*')
					op = Op_MemberOfPointer;

				else
					op = Op_MemberOfPointer;

				break;
			}

			else if (currtok.Text.Ptr[1] == '=')
				op = Op_Assign_Subtract;

			else
				op = Op_Subtract;
		}
		break;
		case '*':
		{
			if (currtok.Text.Ptr[1] == '=')
				op = Op_Assign_Multiply;

			else
			{
				gen_Token finder = prevtok;
				while (finder.Type != Tok_Decl_Operator)
				{
					if (finder.Type == Tok_Identifier)
					{
						op = Op_Indirection;
						break;
					}
				}

				if (op == Op_Invalid)
					op = Op_Multiply;
			}
		}
		break;
		case '/':
		{
			if (currtok.Text.Ptr[1] == '=')
				op = Op_Assign_Divide;

			else
				op = Op_Divide;
		}
		break;
		case '%':
		{
			if (currtok.Text.Ptr[1] == '=')
				op = Op_Assign_Modulo;

			else
				op = Op_Modulo;
		}
		break;
		case '&':
		{
			if (currtok.Text.Ptr[1] == '=')
				op = Op_Assign_BAnd;

			else if (currtok.Text.Ptr[1] == '&')
				op = Op_LAnd;

			else
			{


				if (op == Op_Invalid)
					op = Op_BAnd;
			}
		}
		break;
		case '|':
		{
			if (currtok.Text.Ptr[1] == '=')
				op = Op_Assign_BOr;

			else if (currtok.Text.Ptr[1] == '|')
				op = Op_LOr;

			else
				op = Op_BOr;
		}
		break;
		case '^':
		{
			if (currtok.Text.Ptr[1] == '=')
				op = Op_Assign_BXOr;

			else
				op = Op_BXOr;
		}
		break;
		case '~':
		{
			op = Op_BNot;
		}
		break;
		case '!':
		{
			if (currtok.Text.Ptr[1] == '=')
				op = Op_LNot;

			else
				op = Op_UnaryNot;
		}
		break;
		case '=':
		{
			if (currtok.Text.Ptr[1] == '=')
				op = Op_LEqual;

			else
				op = Op_Assign;
		}
		break;
		case '<':
		{
			if (currtok.Text.Ptr[1] == '=')
				op = Op_LesserEqual;

			else if (currtok.Text.Ptr[1] == '<')
			{
				if (currtok.Text.Ptr[2] == '=')
					op = Op_Assign_LShift;

				else
					op = Op_LShift;
			}
			else
				op = Op_Lesser;
		}
		break;
		case '>':
		{
			if (currtok.Text.Ptr[1] == '=')
				op = Op_GreaterEqual;

			else if (currtok.Text.Ptr[1] == '>')
			{
				if (currtok.Text.Ptr[2] == '=')
					op = Op_Assign_RShift;

				else
					op = Op_RShift;
			}
			else
				op = Op_Greater;
		}
		break;
		case '(':
		{
			if (currtok.Text.Ptr[1] == ')')
				op = Op_FunctionCall;

			else
				op = Op_Invalid;
		}
		break;
		case '[':
		{
			if (currtok.Text.Ptr[1] == ']')
				op = Op_Subscript;

			else
				op = Op_Invalid;
		}
		break;
		default:
		{
			gen_Str gen_c_str_new    = gen_operator_to_str(Op_New);
			gen_Str gen_c_str_delete = gen_operator_to_str(Op_Delete);
			if (gen_c_str_compare_len(currtok.Text.Ptr, gen_c_str_new.Ptr, gen_max(gen_c_str_new.Len - 1, currtok.Text.Len)) == 0)
			{
				op = Op_New;
				eat(Tok_Identifier);
				was_new_or_delete = true;

				gen_s32 idx       = gen__ctx->parser.Tokens.Idx + 1;
				{
					while (gen__ctx->parser.Tokens.Arr[idx].Type == Tok_NewLine)
						idx++;
				}
				gen_Token next = gen__ctx->parser.Tokens.Arr[idx];
				if (currtok.Type == Tok_Operator && gen_c_str_compare_len(currtok.Text.Ptr, "[]", 2) == 0)
				{
					eat(Tok_Operator);
					op = Op_NewArray;
				}
				else if (currtok.Type == Tok_BraceSquare_Open && next.Type == Tok_BraceSquare_Close)
				{
					eat(Tok_BraceSquare_Open);
					eat(Tok_BraceSquare_Close);
					op = Op_NewArray;
				}
			}
			else if (gen_c_str_compare_len(currtok.Text.Ptr, gen_c_str_delete.Ptr, gen_max(gen_c_str_delete.Len - 1, currtok.Text.Len)) == 0)
			{
				op = Op_Delete;
				eat(Tok_Identifier);
				was_new_or_delete = true;

				gen_s32 idx       = gen__ctx->parser.Tokens.Idx + 1;
				{
					while (gen__ctx->parser.Tokens.Arr[idx].Type == Tok_NewLine)
						idx++;
				}
				gen_Token next = gen__ctx->parser.Tokens.Arr[idx];
				if (currtok.Type == Tok_Operator && gen_c_str_compare_len(currtok.Text.Ptr, "[]", 2) == 0)
				{
					eat(Tok_Operator);
					op = Op_DeleteArray;
				}
				else if (currtok.Type == Tok_BraceSquare_Open && next.Type == Tok_BraceSquare_Close)
				{
					eat(Tok_BraceSquare_Open);
					eat(Tok_BraceSquare_Close);
					op = Op_DeleteArray;
				}
			}
			else
			{
				if (op == Op_Invalid)
				{
					gen_log_failure("Invalid operator '%s'\n%s", prevtok.Text, gen_parser_to_strbuilder(gen__ctx->parser));
					gen_parser_pop(&gen__ctx->parser);
					return gen_InvalidCode;
				}
			}
		}
	}

	if (op == Op_Invalid)
	{
		gen_log_failure("Invalid operator '%s'\n%s", currtok.Text, gen_parser_to_strbuilder(gen__ctx->parser));
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}

	if (! was_new_or_delete)
		eat(currtok.Type);
	// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op>

	// Parse Params
	gen_CodeParams params = gen_parse_params(gen_parser_use_parenthesis);
	// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> )

	if (params == gen_nullptr && op == Op_Multiply)
		op = Op_MemberOfPointer;

	while (left && gen_tok_is_specifier(currtok))
	{
		if (specifiers == gen_nullptr)
		{
			specifiers = gen_def_specifier(gen_str_to_specifier(currtok.Text));
			eat(currtok.Type);
			continue;
		}

		gen_specifiers_append(specifiers, gen_str_to_specifier(currtok.Text));
		eat(currtok.Type);
	}
	// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> ) <Specifiers>

	// TODO(Ed): Add proper "delete" and "new" awareness
	// We're dealing with either a "= delete" or operator deletion
	if (check(Tok_Operator) && currtok.Text.Ptr[0] == '=')
	{
		eat(currtok.Type);
		if (! gen_str_are_equal(currtok.Text, txt("delete")))
		{
			gen_log_failure("Expected delete after = in operator forward instead found \"%S\"\n%SB", currtok.Text, gen_parser_to_strbuilder(gen__ctx->parser));
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}
		if (specifiers == gen_nullptr)
			specifiers = gen_def_specifier(Spec_Delete);
		else
			gen_specifiers_append(specifiers, Spec_Delete);
		eat(currtok.Type);
		// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> ) <Specifiers> = delete
	}

	// Parse Body
	gen_CodeBody    body       = { gen_nullptr };
	gen_CodeComment inline_cmt = gen_NullCode;
	if (check(Tok_BraceCurly_Open))
	{
		body = gen_cast(gen_CodeBody, gen_parse_function_body());
		if (gen_cast(gen_Code, body) == gen_Code_Invalid)
		{
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}
		// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> ) <Specifiers> { ... }
	}
	else
	{
		gen_Token stmt_end = currtok;
		eat(Tok_Statement_End);
		// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> ) <Specifiers>;

		if (currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line)
			inline_cmt = gen_parse_comment();
		// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> ) <Specifiers>; <InlineCmt>
	}

	// OpValidateResult check_result = gen_operator__validate( op, params, ret_type, specifiers );
	gen_CodeOperator result = gen_def_operator(op, nspace.Text, gen_def_assign(params, ret_type, body, specifiers, attributes, mflags));

	if (inline_cmt)
		result->InlineCmt = inline_cmt;

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_Code gen_parse_operator_function_or_variable(bool expects_function, gen_CodeAttributes attributes, gen_CodeSpecifiers specifiers)
{
	push_scope();

	gen_Code result         = gen_InvalidCode;

	gen_Code gen_macro_stmt = gen_parse_macro_as_definiton(attributes, specifiers);
	if (gen_macro_stmt)
	{
		gen_parser_pop(&gen__ctx->parser);
		return gen_macro_stmt;
	}

	gen_CodeTypename type = gen_parser_parse_type(gen_parser_not_from_template, gen_nullptr);
	// <Attributes> <Specifiers> <ReturnType/ValueType>

	// Thanks Unreal
	gen_CodeAttributes post_rt_attributes = gen_parse_attributes();
	if (post_rt_attributes)
	{
		if (attributes)
		{
			gen_StrBuilder merged = gen_strbuilder_fmt_buf(gen__ctx->Allocator_Temp, "%S %S", attributes->Content, post_rt_attributes->Content);
			attributes->Content   = gen_cache_str(gen_strbuilder_to_str(merged));
		}
		else
		{
			attributes = post_rt_attributes;
		}
		// <Attributes> <Specifiers> <ReturnType/ValueType> <Attributes>
		// CONVERTED TO:
		// <Attributes> <Specifiers> <ReturnType/ValueType>
	}

	if (type == gen_InvalidCode)
	{
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}

	bool    found_operator = false;
	gen_s32 idx            = gen__ctx->parser.Tokens.Idx;

	for (; idx < gen_array_num(gen__ctx->parser.Tokens.Arr); idx++)
	{
		gen_Token tok = gen__ctx->parser.Tokens.Arr[idx];

		if (tok.Type == Tok_Identifier)
		{
			idx++;
			tok = gen__ctx->parser.Tokens.Arr[idx];
			if (tok.Type == Tok_Access_StaticSymbol)
				continue;

			break;
		}

		if (tok.Type == Tok_Decl_Operator)
			found_operator = true;

		break;
	}

	if (found_operator)
	{
		// Dealing with an operator overload
		result = gen_cast(gen_Code, gen_parse_operator_after_ret_type(ModuleFlag_None, attributes, specifiers, type));
		// <Attributes> <Specifiers> <ReturnType> operator ...
	}
	else
	{
		gen_Token name               = gen_parse_identifier(gen_nullptr);
		gen__ctx->parser.Scope->Name = name.Text;

		bool detected_capture        = check(Tok_Paren_Open);

		// Check three tokens ahead to make sure that were not dealing with a gen_constructor_ initialization...
		//                  (         350.0f    ,         <---  Could be the scenario
		// Example : <Capture_Start> <Value> <Comma>
		//                 idx         +1      +2
		bool detected_comma                         = gen__ctx->parser.Tokens.Arr[gen__ctx->parser.Tokens.Idx + 2].Type == Tok_Comma;

		gen_b32 detected_non_varadic_unpaired_param = detected_comma && nexttok.Type != Tok_Varadic_Argument;
		if (! detected_non_varadic_unpaired_param && nexttok.Type == Tok_Preprocess_Macro_Expr)
			for (gen_s32 break_scope = 0; break_scope == 0; ++break_scope)
			{
				gen_Macro* macro = lookup_macro(nexttok.Text);
				if (macro == gen_nullptr || ! gen_macro_is_functional(*macro))
					break;

				// (   <Macro_Expr> (
				// Idx      +1     +2
				gen_s32 idx   = gen__ctx->parser.Tokens.Idx + 1;
				gen_s32 level = 0;

				// Find end of the token expression
				for (; idx < gen_array_num(gen__ctx->parser.Tokens.Arr); idx++)
				{
					gen_Token tok = gen__ctx->parser.Tokens.Arr[idx];

					if (tok.Type == Tok_Paren_Open)
						level++;
					else if (tok.Type == Tok_Paren_Close && level > 0)
						level--;
					if (level == 0 && tok.Type == Tok_Paren_Close)
						break;
				}
				++idx;    // Will incremnt to possible comma position

				if (gen__ctx->parser.Tokens.Arr[idx].Type != Tok_Comma)
					break;

				detected_non_varadic_unpaired_param = true;
			}

		if (detected_capture && ! detected_non_varadic_unpaired_param)
		{
			// Dealing with a function
			result = gen_cast(gen_Code, gen_parse_function_after_name(ModuleFlag_None, attributes, specifiers, type, name));
			// <Attributes> <Specifiers> <ReturnType> <Name> ( ...
		}
		else
		{
			if (expects_function)
			{
				gen_log_failure("Expected function declaration (consteval was used)\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
				gen_parser_pop(&gen__ctx->parser);
				return gen_InvalidCode;
			}
			// Dealing with a variable
			result = gen_cast(gen_Code, gen_parse_variable_after_name(ModuleFlag_None, attributes, specifiers, type, name.Text));
			// <Attributes> <Specifiers> <ValueType> <Name> ...
		}
	}

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_Code gen_parse_macro_as_definiton(gen_CodeAttributes attributes, gen_CodeSpecifiers specifiers)
{
	push_scope();

	if (currtok.Type != Tok_Preprocess_Macro_Stmt)
	{
		gen_parser_pop(&gen__ctx->parser);
		return gen_NullCode;
	}
	gen_Macro* macro                     = lookup_macro(currtok.Text);
	gen_b32    can_resolve_to_definition = macro && gen_bitfield_is_set(gen_MacroFlags, macro->Flags, MF_Allow_As_Definition);
	if (! can_resolve_to_definition)
	{
		gen_parser_pop(&gen__ctx->parser);
		return gen_NullCode;
	}

	// TODO(Ed): When gen_AST_Macro is made, have it support attributs and specifiers for when its behaving as a declaration/definition.
	gen_Code code = gen_parse_simple_preprocess(Tok_Preprocess_Macro_Stmt);

	// Attributes and sepcifiers will be collapsed into the macro's serialization.
	gen_StrBuilder resolved_definition = gen_strbuilder_fmt_buf(
	    gen__ctx->Allocator_Temp,
	    "%S %S %S",
	    attributes ? gen_strbuilder_to_str(gen_attributes_to_strbuilder(attributes)) : txt(""),
	    specifiers ? gen_strbuilder_to_str(gen_specifiers_to_strbuilder(specifiers)) : txt(""),
	    code->Content
	);
	gen_Code result = gen_untyped_str(gen_strbuilder_to_str(resolved_definition));
	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_CodePragma gen_parse_pragma()
{
	push_scope();

	gen_CodePragma pragma = (gen_CodePragma)gen_make_code();
	pragma->Type          = CT_Preprocess_Pragma;
	eat(Tok_Preprocess_Pragma);
	// #pragma

	if (! check(Tok_Preprocess_Content))
	{
		gen_log_failure("Error, expected content after #pragma\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}

	gen__ctx->parser.Scope->Name = currtok.Text;

	pragma->Content              = gen_cache_str(currtok.Text);
	eat(Tok_Preprocess_Content);
	// #pragma <Content>

	gen_parser_pop(&gen__ctx->parser);
	return pragma;
}

gen_internal inline gen_CodeParams gen_parse_params(bool use_template_capture)
{
	push_scope();

	if (! use_template_capture)
	{
		eat(Tok_Paren_Open);
		// (
	}
	else
	{
		if (check(Tok_Operator) && currtok.Text.Ptr[0] == '<')
			eat(Tok_Operator);
		// <
	}

	if (! use_template_capture && check(Tok_Paren_Close))
	{
		eat(Tok_Paren_Close);
		// )
		gen_parser_pop(&gen__ctx->parser);
		return gen_NullCode;
	}
	else if (check(Tok_Operator) && currtok.Text.Ptr[0] == '>')
	{
		eat(Tok_Operator);
		// >
		gen_parser_pop(&gen__ctx->parser);
		return gen_NullCode;
	}

	gen_Code         macro           = { gen_nullptr };
	gen_CodeTypename type            = { gen_nullptr };
	gen_Code         value           = { gen_nullptr };
	gen_Token        name            = gen_NullToken;
	gen_Code         post_name_macro = { gen_nullptr };

	if (check(Tok_Varadic_Argument))
	{
		eat(Tok_Varadic_Argument);
		// ( or <  ...

		gen_parser_pop(&gen__ctx->parser);
		return gen_param_varadic;
		// ( ... )
		// or < ... >
	}

#define CheckEndParams() (use_template_capture ? (currtok.Text.Ptr[0] != '>') : (currtok.Type != Tok_Paren_Close))

	// TODO(Ed): Use expression macros or this? macro as attribute?
	// Ex: Unreal has this type of macro:                 vvvvvvvvv
	// COREUOBJECT_API void CallFunction( FFrame& Stack, RESULT_DECL, UFunction* Function );
	// and:                 vvvv
	// AddComponentByClass(UPARAM(meta = (AllowAbstract = "false")) TSubclassOf<UActorComponent> Class, bool bManualAttachment, ...
	if (check(Tok_Preprocess_Macro_Expr))
	{
		macro = gen_parse_simple_preprocess(Tok_Preprocess_Macro_Expr);
		// ( <gen_Macro>
	}
	if (currtok.Type != Tok_Comma)
	{
		type = gen_parser_parse_type(use_template_capture, gen_nullptr);
		if (gen_cast(gen_Code, type) == gen_Code_Invalid)
		{
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}
		// ( <gen_Macro> <ValueType>

		if (check(Tok_Identifier) || gen_bitfield_is_set(gen_u32, currtok.Flags, TF_Identifier))
		{
			name = currtok;
			eat(currtok.Type);
			// ( <gen_Macro> <ValueType> <Name>
		}

		// TODO(Ed): Use expression macro for this?
		// Unreal has yet another type of macro:
		// template<class T UE_REQUIRES(TPointerIsConvertibleFromTo<T, UInterface>::Value)>
		// class T ... and then ^this^ UE_REQUIRES shows up
		// So we need to consume that.
		if (check(Tok_Preprocess_Macro_Expr))
		{
			post_name_macro = gen_parse_simple_preprocess(Tok_Preprocess_Macro_Expr);
			// ( <gen_Macro> <ValueType> <Name> <PostNameMacro>
		}

		// C++ allows typename = expression... so anything goes....
		if (gen_bitfield_is_set(gen_u32, currtok.Flags, TF_Assign))
		{
			eat(Tok_Operator);
			// ( <gen_Macro> <ValueType> <Name>  =

			gen_Token value_tok = currtok;

			if (currtok.Type == Tok_Comma)
			{
				gen_log_failure("Expected value after assignment operator\n%s.", gen_parser_to_strbuilder(gen__ctx->parser));
				gen_parser_pop(&gen__ctx->parser);
				return gen_InvalidCode;
			}

			gen_s32 capture_level      = 0;
			gen_s32 gen_template_level = 0;
			while ((left && (currtok.Type != Tok_Comma) && gen_template_level >= 0 && CheckEndParams()) || (capture_level > 0 || gen_template_level > 0))
			{
				if (currtok.Text.Ptr[0] == '<')
					++gen_template_level;

				if (currtok.Text.Ptr[0] == '>')
					--gen_template_level;
				if (currtok.Type == Tok_Operator && currtok.Text.Ptr[1] == '>')
					--gen_template_level;

				if (currtok.Type == Tok_Paren_Open)
					++capture_level;

				if (currtok.Type == Tok_Paren_Close)
					--capture_level;

				value_tok.Text.Len = ((gen_sptr)currtok.Text.Ptr + currtok.Text.Len) - (gen_sptr)value_tok.Text.Ptr;
				eat(currtok.Type);
			}

			value = gen_untyped_str(gen_strbuilder_to_str(gen_parser_strip_formatting(value_tok.Text, gen_parser_strip_formatting_dont_preserve_newlines)));
			// ( <gen_Macro> <ValueType> <Name> = <Expression>
		}
	}

	gen_CodeParams result = (gen_CodeParams)gen_make_code();
	result->Type          = CT_Parameters;

	result->gen_Macro     = macro;

	if (name.Text.Len > 0)
		result->Name = gen_cache_str(name.Text);

	result->ValueType = type;

	if (value)
		result->Value = value;

	result->NumEntries++;

	while (check(Tok_Comma))
	{
		eat(Tok_Comma);
		// ( <gen_Macro> <ValueType> <Name> = <Expression>,

		gen_Code type  = { gen_nullptr };
		gen_Code value = { gen_nullptr };

		if (check(Tok_Varadic_Argument))
		{
			eat(Tok_Varadic_Argument);
			gen_params_append(result, gen_param_varadic);
			continue;
			// ( <gen_Macro> <ValueType> <Name> = <Expression>, ...
		}

		// Ex: Unreal has this type of macro:                 vvvvvvvvv
		// COREUOBJECT_API void CallFunction( FFrame& Stack, RESULT_DECL, UFunction* Function );
		// and:                 vvvv
		// AddComponentByClass(UPARAM(meta = (AllowAbstract = "false")) TSubclassOf<UActorComponent> Class, bool bManualAttachment, ...
		if (check(Tok_Preprocess_Macro_Expr))
		{
			macro = gen_parse_simple_preprocess(Tok_Preprocess_Macro_Expr);
			// ( <gen_Macro> <ValueType> <Name> = <Expression>, <gen_Macro>
		}
		if (currtok.Type != Tok_Comma)
		{
			type = gen_cast(gen_Code, gen_parser_parse_type(use_template_capture, gen_nullptr));
			if (type == gen_Code_Invalid)
			{
				gen_parser_pop(&gen__ctx->parser);
				return gen_InvalidCode;
			}
			// ( <gen_Macro> <ValueType> <Name> = <Expression>, <gen_Macro> <ValueType>

			name = gen_NullToken;

			if (check(Tok_Identifier) || gen_bitfield_is_set(gen_u32, currtok.Flags, TF_Identifier))
			{
				name = currtok;
				eat(currtok.Type);
				// ( <gen_Macro> <ValueType> <Name> = <Expression>, <gen_Macro> <ValueType> <Name>
			}

			// Unreal has yet another type of macro:
			// template<class T UE_REQUIRES(TPointerIsConvertibleFromTo<T, UInterface>::Value)>
			// class T ... and then ^this^ UE_REQUIRES shows up
			// So we need to consume that.
			if (check(Tok_Preprocess_Macro_Expr))
			{
				post_name_macro = gen_parse_simple_preprocess(Tok_Preprocess_Macro_Expr);
				// ( <gen_Macro> <ValueType> <Name> = <Expression>, <gen_Macro> <ValueType> <PostNameMacro>
			}

			/// C++ allows typename = expression... so anything goes....
			if (gen_bitfield_is_set(gen_u32, currtok.Flags, TF_Assign))
			{
				eat(Tok_Operator);
				// ( <gen_Macro> <ValueType> <Name> = <Expression>, <gen_Macro> <ValueType> <Name> <PostNameMacro> =

				gen_Token value_tok = currtok;

				if (currtok.Type == Tok_Comma)
				{
					gen_log_failure("Expected value after assignment operator\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
					gen_parser_pop(&gen__ctx->parser);
					return gen_InvalidCode;
				}

				gen_s32 capture_level      = 0;
				gen_s32 gen_template_level = 0;
				while ((left && currtok.Type != Tok_Comma && gen_template_level >= 0 && CheckEndParams()) || (capture_level > 0 || gen_template_level > 0))
				{
					if (currtok.Text.Ptr[0] == '<')
						++gen_template_level;

					if (currtok.Text.Ptr[0] == '>')
						--gen_template_level;
					if (currtok.Type == Tok_Operator && currtok.Text.Ptr[1] == '>')
						--gen_template_level;

					if (currtok.Type == Tok_Paren_Open)
						++capture_level;

					if (currtok.Type == Tok_Paren_Close)
						--capture_level;

					value_tok.Text.Len = ((gen_sptr)currtok.Text.Ptr + currtok.Text.Len) - (gen_sptr)value_tok.Text.Ptr;
					eat(currtok.Type);
				}

				value = gen_untyped_str(gen_strbuilder_to_str(gen_parser_strip_formatting(value_tok.Text, gen_parser_strip_formatting_dont_preserve_newlines)));
				// ( <gen_Macro> <ValueType> <Name> = <Expression>, <gen_Macro> <ValueType> <Name> <PostNameMacro> = <Expression>
			}
			// ( <gen_Macro> <ValueType> <Name> = <Expression>, <gen_Macro> <ValueType> <Name> <PostNameMacro> = <Expression>, ..
		}

		gen_CodeParams param = (gen_CodeParams)gen_make_code();
		param->Type          = CT_Parameters;

		param->gen_Macro     = macro;

		if (name.Text.Len > 0)
			param->Name = gen_cache_str(name.Text);

		param->PostNameMacro = post_name_macro;
		param->ValueType     = gen_cast(gen_CodeTypename, type);

		if (value)
			param->Value = value;

		gen_params_append(result, param);
	}

	if (! use_template_capture)
	{
		eat(Tok_Paren_Close);
		// ( <gen_Macro> <ValueType> <Name> <PostNameMacro> = <Expression>, <gen_Macro> <ValueType> <Name> <PostNameMacro> = <Expression>, .. )
	}
	else
	{
		if (! check(Tok_Operator) || currtok.Text.Ptr[0] != '>')
		{
			gen_log_failure("Expected '<' after 'template' keyword\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}
		eat(Tok_Operator);
		// < <gen_Macro> <ValueType> <Name> <PostNameMacro> = <Expression>, <gen_Macro> <ValueType> <Name> <PostNameMacro> = <Expression>, .. >
	}
	gen_parser_pop(&gen__ctx->parser);
	return result;
#undef context
}

gen_internal gen_CodePreprocessCond gen_parse_preprocess_cond()
{
	push_scope();

	if (! gen_tok_is_preprocess_cond(currtok))
	{
		gen_log_failure("Error, expected preprocess conditional\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}

	gen_CodePreprocessCond cond = (gen_CodePreprocessCond)gen_make_code();
	cond->Type                  = gen_scast(gen_CodeType, currtok.Type - (Tok_Preprocess_If - CT_Preprocess_If));
	eat(currtok.Type);
	// #<Conditional>

	if (! check(Tok_Preprocess_Content))
	{
		gen_log_failure("Error, expected content after #define\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}

	gen__ctx->parser.Scope->Name = currtok.Text;
	cond->Content                = gen_cache_str(currtok.Text);
	eat(Tok_Preprocess_Content);
	// #<Conditiona> <Content>

	gen_parser_pop(&gen__ctx->parser);
	return cond;
}

gen_internal gen_Code gen_parse_simple_preprocess(gen_TokType which)
{
	// TODO(Ed): We can handle a macro a gen_bit better than this. It's gen_AST can be made more robust..
	// Make an gen_AST_Macro, it should have an Name be the macro itself, with the function body being an optional function body node.
	// If we want it to terminate or have an inline comment we can possbily use its parent typedef for that info...
	push_scope();

	gen_Token full_macro = currtok;
	eat(which);
	// <gen_Macro>

	gen_Macro* macro = lookup_macro(full_macro.Text);
	if (which != Tok_Preprocess_Unsupported && macro == gen_nullptr)
	{
		gen_log_failure("Expected the macro %S to be registered\n%S", full_macro, gen_parser_to_strbuilder(gen__ctx->parser));
		return gen_NullCode;
	}

	// TODO(Ed) : Parse this properly later (expression and statement support)
	if (macro && gen_macro_is_functional(*macro))
	{
		eat(Tok_Paren_Open);

		gen_s32 level = 0;
		while (left && (currtok.Type != Tok_Paren_Close || level > 0))
		{
			if (currtok.Type == Tok_Paren_Open)
				level++;

			else if (currtok.Type == Tok_Paren_Close && level > 0)
				level--;

			eat(currtok.Type);
		}
		eat(Tok_Paren_Close);
		// <gen_Macro> ( <params> )

		full_macro.Text.Len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)full_macro.Text.Ptr;
	}

	if (macro && gen_macro_expects_body(*macro) && peektok.Type == Tok_BraceCurly_Open)
	{
		// Eat the block scope right after the macro. Were assuming the macro defines a function definition's signature
		eat(Tok_BraceCurly_Open);
		// <gen_Macro> {

		// TODO(Ed) : Parse this properly later (expression and statement support)
		gen_s32 level = 0;
		while (left && (currtok.Type != Tok_BraceCurly_Close || level > 0))
		{
			if (currtok.Type == Tok_BraceCurly_Open)
				level++;

			else if (currtok.Type == Tok_BraceCurly_Close && level > 0)
				level--;

			eat(currtok.Type);
		}
		eat(Tok_BraceCurly_Close);
		// <gen_Macro> { <Body> }

		// TODO(Ed): Review this?
		gen_Str prev_proc = gen__ctx->parser.Scope->Prev->ProcName;
		if (macro->Type == MT_Typename && gen_c_str_compare_len(prev_proc.Ptr, "gen_parser_parse_typedef", prev_proc.Len) != 0)
		{
			if (check(Tok_Statement_End))
			{
				gen_Token stmt_end = currtok;
				eat(Tok_Statement_End);
				// <gen_Macro> { <Content> };

				if (currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line)
					eat(Tok_Comment);
				// <gen_Macro> { <Content> }; <InlineCmt>
			}
		}

		full_macro.Text.Len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)full_macro.Text.Ptr;
	}
	else
	{
		// If the macro is just a macro in the body of an gen_AST it may have a semi-colon for the user to close on purpsoe
		// (especially for functional macros)
		gen_Str calling_proc = gen__ctx->parser.Scope->Prev->ProcName;

		if (gen_str_contains(gen__ctx->parser.Scope->Prev->ProcName, txt("gen_parser_parse_enum")))
		{
			// Do nothing
			goto Leave_Scope_Early;
		}
		else if (macro && macro->Type == MT_Typename && gen_str_contains(gen__ctx->parser.Scope->Prev->ProcName, txt("gen_parser_parse_typedef")))
		{
			if (peektok.Type == Tok_Statement_End)
			{
				gen_Token stmt_end = currtok;
				eat(Tok_Statement_End);
				// <gen_Macro>;

				full_macro.Text.Len += prevtok.Text.Len;

				// TODO(Ed): Reveiw the context for this? (ESPECIALLY THIS)
				if (currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line)
				{
					eat(Tok_Comment);
					// <gen_Macro>; <InlineCmt>

					full_macro.Text.Len += prevtok.Text.Len;
				}
			}
		}
		else if (gen_str_contains(calling_proc, txt("gen_parse_global_nspace")) || gen_str_contains(calling_proc, txt("gen_parse_class_struct_body")))
		{
			if (left && peektok.Type == Tok_Statement_End)
			{
				gen_Token stmt_end = currtok;
				eat(Tok_Statement_End);
				// <gen_Macro>;
				full_macro.Text.Len += prevtok.Text.Len;
			}
		}
	}

Leave_Scope_Early:
	gen_Code result              = gen_untyped_str(full_macro.Text);
	gen__ctx->parser.Scope->Name = full_macro.Text;

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_Code gen_parse_static_assert()
{
	push_scope();

	gen_Code assert              = gen_make_code();
	assert->Type                 = CT_Untyped;

	gen_Token content            = currtok;

	gen__ctx->parser.Scope->Name = content.Text;

	eat(Tok_StaticAssert);
	eat(Tok_Paren_Open);
	// gen_static_assert(

	// TODO(Ed) : Parse this properly.
	gen_s32 level = 0;
	while (left && (currtok.Type != Tok_Paren_Close || level > 0))
	{
		if (currtok.Type == Tok_Paren_Open)
			level++;
		else if (currtok.Type == Tok_Paren_Close)
			level--;

		eat(currtok.Type);
	}
	eat(Tok_Paren_Close);
	eat(Tok_Statement_End);
	// gen_static_assert( <Content> );

	content.Text.Len        = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)content.Text.Ptr;

	char const* str         = gen_c_str_fmt_buf("%.*s\n", content.Text.Len, content.Text.Ptr);
	gen_Str     content_str = { str, content.Text.Len + 1 };
	assert->Content         = gen_cache_str(content_str);
	assert->Name            = assert->Content;

	gen_parser_pop(&gen__ctx->parser);
	return assert;
}

/*
	This a brute-froce make all the arguments part of the token provided.
	Can have in-place function signatures, regular identifiers, in-place typenames, compile-time expressions, parameter-pack expansion, etc.
	This means that validation can only go so far, and so if there is any different in formatting
	passed the basic stripping supported it report a soft failure.
*/
gen_internal inline void gen_parse_template_args(gen_Token* token)
{
	if (currtok.Type == Tok_Operator && currtok.Text.Ptr[0] == '<' && currtok.Text.Len == 1)
	{
		eat(Tok_Operator);
		// <

		gen_s32 level = 0;
		while (left && level >= 0 && (currtok.Text.Ptr[0] != '>' || level > 0))
		{
			if (currtok.Text.Ptr[0] == '<')
				level++;

			if (currtok.Text.Ptr[0] == '>')
				level--;
			if (currtok.Type == Tok_Operator && currtok.Text.Ptr[1] == '>')
				level--;

			eat(currtok.Type);
		}
		// < <Content>

		// Due to the >> token, this could have been eaten early...
		if (level == 0)
			eat(Tok_Operator);
		// < <Content> >

		// Extend length of name to last token
		token->Text.Len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)token->Text.Ptr;
	}
}

// Variable parsing is handled in multiple places because its initial signature is shared with function parsing
gen_internal gen_CodeVar
    gen_parse_variable_after_name(gen_ModuleFlag mflags, gen_CodeAttributes attributes, gen_CodeSpecifiers specifiers, gen_CodeTypename type, gen_Str name)
{
	push_scope();

	gen_Code gen_array_expr                   = gen_parse_array_decl();
	gen_Code expr                             = gen_NullCode;
	gen_Code bitfield_expr                    = gen_NullCode;

	gen_b32 gen_using_constructor_initializer = false;

	if (gen_bitfield_is_set(gen_u32, currtok.Flags, TF_Assign))
	{
		// <Attributes> <Specifiers> <ValueType> <Name> = <Expression>
		expr = gen_parse_assignment_expression();
	}

	if (currtok.Type == Tok_BraceCurly_Open)
	{
		gen_Token expr_tok = currtok;

		eat(Tok_BraceCurly_Open);
		// <Attributes> <Specifiers> <ValueType> <Name> {

		gen_s32 level = 0;
		while (left && (currtok.Type != Tok_BraceCurly_Close || level > 0))
		{
			if (currtok.Type == Tok_BraceCurly_Open)
				level++;

			else if (currtok.Type == Tok_BraceCurly_Close && level > 0)
				level--;

			eat(currtok.Type);
		}
		eat(Tok_BraceCurly_Close);

		expr_tok.Text.Len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)expr_tok.Text.Ptr;
		expr              = gen_untyped_str(expr_tok.Text);
		// <Attributes> <Specifiers> <ValueType> <Name> = { <Expression> }
	}

	if (currtok.Type == Tok_Paren_Open)
	{
		eat(Tok_Paren_Open);
		// <Attributes> <Specifiers> <ValueType> <Name> (

		gen_Token expr_token              = currtok;

		gen_using_constructor_initializer = true;

		gen_s32 level                     = 0;
		while (left && (currtok.Type != Tok_Paren_Close || level > 0))
		{
			if (currtok.Type == Tok_Paren_Open)
				level++;

			else if (currtok.Type == Tok_Paren_Close && level > 0)
				level--;

			eat(currtok.Type);
		}

		expr_token.Text.Len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)expr_token.Text.Ptr;
		expr                = gen_untyped_str(expr_token.Text);
		eat(Tok_Paren_Close);
		// <Attributes> <Specifiers> <ValueType> <Name> ( <Expression> )
	}

	if (currtok.Type == Tok_Assign_Classifer)
	{
		eat(Tok_Assign_Classifer);
		// <Attributes> <Specifiers> <ValueType> <Name> :

		gen_Token expr_tok = currtok;

		if (currtok.Type == Tok_Statement_End)
		{
			gen_log_failure("Expected expression after bitfield \n%SB", gen_parser_to_strbuilder(gen__ctx->parser));
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}

		while (left && currtok.Type != Tok_Statement_End)
		{
			eat(currtok.Type);
		}

		expr_tok.Text.Len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)expr_tok.Text.Ptr;
		bitfield_expr     = gen_untyped_str(expr_tok.Text);
		// <Attributes> <Specifiers> <ValueType> <Name> : <Expression>
	}

	gen_CodeVar     gen_next_var = gen_NullCode;
	gen_Token       stmt_end     = gen_NullToken;
	gen_CodeComment inline_cmt   = gen_NullCode;
	if (type)
	{
		if (currtok.Type == Tok_Comma)
		{
			// Were dealing with a statement with more than one declaration
			// This is only handled this way if its the first declaration
			// Otherwise its looped through in gen_parse_variable_declaration_list
			gen_next_var = gen_parse_variable_declaration_list();
			// <Attributes> <Specifiers> <ValueType> <Name> : <Expression>, ...
			// <Attributes> <Specifiers> <ValueType> <Name> = <Expression>, ...
			// <Attributes> <Specifiers> <ValueType> <Name> { <Expression> }, ...
		}

		// If we're dealing with a "comma-procedding then we cannot expect a statement end or inline comment
		// Any comma procedding variable will not have a type provided so it can act as a indicator to skip this
		gen_Token stmt_end = currtok;
		eat(Tok_Statement_End);
		// <Attributes> <Specifiers> <ValueType> <Name> : <Expression>, ...;
		// <Attributes> <Specifiers> <ValueType> <Name> = <Expression>, ...;
		// <Attributes> <Specifiers> <ValueType> <Name> { <Expression> }, ...;

		// Check for inline comment : <type> <identifier> = <expression>; // <inline comment>
		if (left && (currtok_noskip.Type == Tok_Comment) && currtok_noskip.Line == stmt_end.Line)
		{
			inline_cmt = gen_parse_comment();
			// <Attributes> <Specifiers> <ValueType> <Name> : <Expression>, ...; <InlineCmt>
			// <Attributes> <Specifiers> <ValueType> <Name> = <Expression>, ...; <InlineCmt>
			// <Attributes> <Specifiers> <ValueType> <Name> { <Expression> }, ...; <InlineCmt>
		}
	}

	gen_CodeVar result   = (gen_CodeVar)gen_make_code();
	result->Type         = CT_Variable;
	result->Name         = gen_cache_str(name);
	result->ModuleFlags  = mflags;
	result->ValueType    = type;
	result->BitfieldSize = bitfield_expr;
	result->Attributes   = attributes;
	result->Specs        = specifiers;
	result->Value        = expr;
	result->InlineCmt    = inline_cmt;

	if (gen_array_expr)
		type->ArrExpr = gen_array_expr;

	if (gen_next_var)
	{
		result->NextVar         = gen_next_var;
		result->NextVar->Parent = gen_cast(gen_Code, result);
	}
	result->VarParenthesizedInit = gen_using_constructor_initializer;

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

/*
	Note(Ed): This does not support the following:
	* Function Pointers
*/
gen_internal gen_CodeVar gen_parse_variable_declaration_list()
{
	push_scope();

	gen_CodeVar result   = gen_NullCode;
	gen_CodeVar last_var = gen_NullCode;
	while (check(Tok_Comma))
	{
		eat(Tok_Comma);
		// ,

		gen_CodeSpecifiers specifiers = gen_NullCode;

		while (left && gen_tok_is_specifier(currtok))
		{
			gen_Specifier spec = gen_str_to_specifier(currtok.Text);

			switch (spec)
			{
				case Spec_Const:
					if (specifiers->NumEntries && specifiers->ArrSpecs[specifiers->NumEntries - 1] != Spec_Ptr)
					{
						gen_log_failure(
						    "Error, const specifier must come after pointer specifier for variable declaration proceeding comma\n"
						    "(Parser will add and continue to specifiers, but will most likely fail to compile)\n%SB",
						    gen_parser_to_strbuilder(gen__ctx->parser)
						);

						gen_specifiers_append(specifiers, spec);
					}
					break;

				case Spec_Ptr:
				case Spec_Ref:
				case Spec_RValue:
					break;

				default:
				{
					gen_log_failure(
					    "Error, invalid specifier '%S' proceeding comma\n"
					    "(Parser will add and continue to specifiers, but will most likely fail to compile)\n%S",
					    currtok.Text,
					    gen_strbuilder_to_str(gen_parser_to_strbuilder(gen__ctx->parser))
					);
					continue;
				}
				break;
			}

			if (specifiers)
				gen_specifiers_append(specifiers, spec);
			else
				specifiers = gen_def_specifier(spec);

			eat(currtok.Type);
		}
		// , <Specifiers>

		gen_Str name = currtok.Text;
		eat(Tok_Identifier);
		// , <Specifiers> <Name>

		gen_CodeVar var = gen_parse_variable_after_name(ModuleFlag_None, gen_NullCode, specifiers, gen_NullCode, name);
		// , <Specifiers> <Name> ...

		if (! result)
		{
			result   = var;
			last_var = var;
		}
		else
		{
			last_var->NextVar         = var;
			last_var->NextVar->Parent = gen_cast(gen_Code, var);
			last_var                  = var;
		}
	}

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_CodeClass gen_parser_parse_class(bool inplace_def)
{
	push_scope();
	gen_CodeClass result = (gen_CodeClass)gen_parse_class_struct(Tok_Decl_Class, inplace_def);
	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_CodeConstructor gen_parser_parse_constructor(gen_CodeSpecifiers specifiers)
{
	push_scope();

	gen_Token      identifier = gen_parse_identifier(gen_nullptr);
	gen_CodeParams params     = gen_parse_params(gen_parser_not_from_template);
	// <Name> ( <Parameters> )

	gen_Code        initializer_list = gen_NullCode;
	gen_CodeBody    body             = gen_NullCode;
	gen_CodeComment inline_cmt       = gen_NullCode;

	// TODO(Ed) : Need to support postfix specifiers

	if (check(Tok_Assign_Classifer))
	{
		eat(Tok_Assign_Classifer);
		// <Name> ( <Parameters> ) :

		gen_Token initializer_list_tok = currtok;

		gen_s32 level                  = 0;
		while (left && (currtok.Type != Tok_BraceCurly_Open || level > 0))
		{
			if (currtok.Type == Tok_Paren_Open)
				level++;
			else if (currtok.Type == Tok_Paren_Close)
				level--;

			eat(currtok.Type);
		}

		initializer_list_tok.Text.Len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)initializer_list_tok.Text.Ptr;
		// <Name> ( <Parameters> ) : <InitializerList>

		initializer_list = gen_untyped_str(initializer_list_tok.Text);

		// TODO(Ed): Constructors can have post-fix specifiers

		body = gen_cast(gen_CodeBody, gen_parse_function_body());
		// <Name> ( <Parameters> ) : <InitializerList> { <Body> }
	}
	else if (check(Tok_BraceCurly_Open))
	{
		body = gen_cast(gen_CodeBody, gen_parse_function_body());
		// <Name> ( <Parameters> ) { <Body> }
	}
	// TODO(Ed): Add support for detecting gen_constructor_ deletion
	else if (check(Tok_Operator) && currtok.Text.Ptr[0] == '=')
	{
		body = gen_cast(gen_CodeBody, gen_parse_assignment_expression());
	}
	else
	{
		gen_Token stmt_end = currtok;
		eat(Tok_Statement_End);
		// <Name> ( <Parameters> );

		if (currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line)
			inline_cmt = gen_parse_comment();
		// <Name> ( <Parameters> ); <InlineCmt>
	}

	gen_CodeConstructor result = (gen_CodeConstructor)gen_make_code();

	result->Name               = gen_cache_str(identifier.Text);

	result->Specs              = specifiers;

	if (params)
		result->Params = params;

	if (initializer_list)
		result->InitializerList = initializer_list;

	if (body && body->Type == CT_Function_Body)
	{
		result->Body = gen_cast(gen_Code, body);
		result->Type = CT_Constructor;
	}
	else
		result->Type = CT_Constructor_Fwd;

	if (inline_cmt)
		result->InlineCmt = inline_cmt;

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal inline gen_CodeDefine gen_parser_parse_define()
{
	push_scope();
	if (check(Tok_Preprocess_Hash))
	{
		// If gen_parse_define is called by the user the gen_hash reach here.
		eat(Tok_Preprocess_Hash);
	}

	eat(Tok_Preprocess_Define);
	// #define

	gen_CodeDefine define = (gen_CodeDefine)gen_make_code();
	define->Type          = CT_Preprocess_Define;
	if (! check(Tok_Identifier))
	{
		gen_log_failure("Error, expected identifier after #define\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}
	gen__ctx->parser.Scope->Name = currtok.Text;
	define->Name                 = gen_cache_str(currtok.Text);
	eat(Tok_Identifier);
	// #define <Name>

	gen_Macro* macro = lookup_macro(define->Name);
	if (gen_macro_is_functional(*macro))
	{
		eat(Tok_Paren_Open);
		// #define <Name> (

		// We provide the define params even if empty to make sure '()' are serialized.
		gen_CodeDefineParams params = (gen_CodeDefineParams)gen_make_code();
		params->Type                = CT_Parameters_Define;

		if (left && currtok.Type != Tok_Paren_Close)
		{
			params->Name = currtok.Text;
			params->NumEntries++;

			eat(Tok_Preprocess_Define_Param);
			// #define <Name> ( <param>
		}

		while (left && currtok.Type != Tok_Paren_Close)
		{
			eat(Tok_Comma);
			// #define <Name> ( <param>,

			gen_CodeDefineParams gen_next_param = (gen_CodeDefineParams)gen_make_code();
			gen_next_param->Type                = CT_Parameters_Define;
			gen_next_param->Name                = currtok.Text;
			gen_define_params_append(params, gen_next_param);

			// #define  <Name> (  <param>, <gen_next_param> ...
			eat(Tok_Preprocess_Define_Param);
		}

		eat(Tok_Paren_Close);
		// #define <Name> ( <params> )

		define->Params = params;
	}

	if (! check(Tok_Preprocess_Content))
	{
		gen_log_failure("Error, expected content after #define %s\n%s", define->Name, gen_parser_to_strbuilder(gen__ctx->parser));
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}

	if (currtok.Text.Len == 0)
	{
		define->Body = gen_untyped_str(txt("\n"));
		eat(Tok_Preprocess_Content);
		// #define <Name> ( <params> ) <Content>

		gen_parser_pop(&gen__ctx->parser);
		return define;
	}

	define->Body = gen_untyped_str(gen_strbuilder_to_str(gen_parser_strip_formatting(currtok.Text, gen_parser_strip_formatting_dont_preserve_newlines)));
	eat(Tok_Preprocess_Content);
	// #define <Name> ( <params> ) <Content>

	gen_parser_pop(&gen__ctx->parser);
	return define;
}

gen_internal gen_CodeDestructor gen_parser_parse_destructor(gen_CodeSpecifiers specifiers)
{
	push_scope();

	bool has_context         = gen__ctx->parser.Scope && gen__ctx->parser.Scope->Prev;
	bool is_in_global_nspace = has_context && gen_str_are_equal(gen__ctx->parser.Scope->Prev->ProcName, txt("gen_parse_global_nspace"));

	if (check(Tok_Spec_Virtual))
	{
		if (specifiers)
			gen_specifiers_append(specifiers, Spec_Virtual);
		else
			specifiers = gen_def_specifier(Spec_Virtual);
		eat(Tok_Spec_Virtual);
	}
	// <Virtual gen_Specifier>

	gen_Token prefix_identifier = gen_NullToken;
	if (is_in_global_nspace)
		prefix_identifier = gen_parse_identifier(gen_nullptr);

	if (left && currtok.Text.Ptr[0] == '~')
		eat(Tok_Operator);
	else
	{
		gen_log_failure("Expected gen_destructor_ '~' token\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}
	// <Virtual gen_Specifier> ~

	gen_Token       identifier = gen_parse_identifier(gen_nullptr);
	gen_CodeBody    body       = { gen_nullptr };
	gen_CodeComment inline_cmt = gen_NullCode;
	// <Virtual gen_Specifier> ~<Name>

	eat(Tok_Paren_Open);
	eat(Tok_Paren_Close);
	// <Virtual gen_Specifier> ~<Name>()

	bool pure_virtual = false;

	if (check(Tok_Operator) && currtok.Text.Ptr[0] == '=')
	{
		// <Virtual gen_Specifier> ~<Name>() =

		bool      skip_formatting = true;
		gen_Token upcoming        = nexttok;
		if (left && upcoming.Text.Ptr[0] == '0')
		{
			eat(Tok_Operator);
			eat(Tok_Number);
			// <Virtual gen_Specifier> ~<Name>() = 0

			gen_specifiers_append(specifiers, Spec_Pure);
		}
		else if (left && gen_c_str_compare_len(upcoming.Text.Ptr, "default", sizeof("default") - 1) == 0)
		{
			body = gen_cast(gen_CodeBody, gen_parse_assignment_expression());
			// <Virtual gen_Specifier> ~<
		}
		else
		{
			gen_log_failure("Pure or default specifier expected due to '=' token\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}

		pure_virtual = true;
	}

	if (! pure_virtual && check(Tok_BraceCurly_Open))
	{
		body = gen_cast(gen_CodeBody, gen_parse_function_body());
		// <Virtual gen_Specifier> ~<Name>() { ... }
	}
	else
	{
		gen_Token stmt_end = currtok;
		eat(Tok_Statement_End);
		// <Virtual gen_Specifier> ~<Name>() <Pure gen_Specifier>;

		if (currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line)
			inline_cmt = gen_parse_comment();
		// <Virtual gen_Specifier> ~<Name>() <Pure gen_Specifier>; <InlineCmt>
	}

	gen_CodeDestructor result = (gen_CodeDestructor)gen_make_code();

	if (gen_tok_is_valid(prefix_identifier))
	{
		prefix_identifier.Text.Len += 1 + identifier.Text.Len;
		result->Name                = gen_cache_str(prefix_identifier.Text);
	}

	if (specifiers)
		result->Specs = specifiers;

	if (body && body->Type == CT_Function_Body)
	{
		result->Body = gen_cast(gen_Code, body);
		result->Type = CT_Destructor;
	}
	else
		result->Type = CT_Destructor_Fwd;

	if (inline_cmt)
		result->InlineCmt = inline_cmt;

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_CodeEnum gen_parser_parse_enum(bool inplace_def)
{
	push_scope();

	gen_Specifier specs_found[16]   = { Spec_NumSpecifiers };
	gen_s32       NumSpecifiers     = 0;

	gen_CodeAttributes attributes   = { gen_nullptr };

	gen_Token        name           = gen_NullToken;
	gen_Code         gen_array_expr = { gen_nullptr };
	gen_CodeTypename type           = { gen_nullptr };

	bool is_enum_class              = false;

	eat(Tok_Decl_Enum);
	// enum

	if (currtok.Type == Tok_Decl_Class)
	{
		eat(Tok_Decl_Class);
		is_enum_class = true;
		// enum class
	}

	attributes = gen_parse_attributes();
	// enum <class> <Attributes>

	if (check(Tok_Identifier))
	{
		name                         = currtok;
		gen__ctx->parser.Scope->Name = currtok.Text;
		eat(Tok_Identifier);
	}
	// enum <class> <Attributes> <Name>

	gen_b32  use_macro_underlying = false;
	gen_Code underlying_macro     = { gen_nullptr };
	if (currtok.Type == Tok_Assign_Classifer)
	{
		eat(Tok_Assign_Classifer);
		// enum <class> <Attributes> <Name> :

		type = gen_parser_parse_type(gen_parser_not_from_template, gen_nullptr);
		if (gen_cast(gen_Code, type) == gen_Code_Invalid)
		{
			gen_log_failure("Failed to parse enum classifier\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}
		// enum <class> <Attributes> <Name> : <UnderlyingType>
	}
	else if (currtok.Type == Tok_Preprocess_Macro_Expr)
	{
		// We'll support the gen_enum_underlying macro
		if (gen_str_contains(currtok.Text, gen_enum_underlying_macro.Name))
		{
			use_macro_underlying = true;
			underlying_macro     = gen_parse_simple_preprocess(Tok_Preprocess_Macro_Expr);
		}
	}

	gen_CodeBody body = { gen_nullptr };

	if (currtok.Type == Tok_BraceCurly_Open)
	{
		body       = (gen_CodeBody)gen_make_code();
		body->Type = CT_Enum_Body;

		eat(Tok_BraceCurly_Open);
		// enum <class> <Attributes> <Name> : <UnderlyingType> {

		gen_Code member    = gen_InvalidCode;

		bool expects_entry = true;
		while (left && currtok_noskip.Type != Tok_BraceCurly_Close)
		{
			if (! expects_entry)
			{
				gen_log_failure("Did not expect an entry after last member of enum body.\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
				gen_parser_pop(&gen__ctx->parser);
				break;
			}

			if (currtok_noskip.Type == Tok_Preprocess_Hash)
				eat(Tok_Preprocess_Hash);

			switch (currtok_noskip.Type)
			{
				case Tok_NewLine:
					member = gen_untyped_str(currtok_noskip.Text);
					eat(Tok_NewLine);
					break;

				case Tok_Comment:
					member = gen_cast(gen_Code, gen_parse_comment());
					break;

				case Tok_Preprocess_Define:
					member = gen_cast(gen_Code, gen_parser_parse_define());
					// #define
					break;

				case Tok_Preprocess_If:
				case Tok_Preprocess_IfDef:
				case Tok_Preprocess_IfNotDef:
				case Tok_Preprocess_ElIf:
					member = gen_cast(gen_Code, gen_parse_preprocess_cond());
					// #<if, ifdef, ifndef, elif> ...
					break;

				case Tok_Preprocess_Else:
					member = gen_cast(gen_Code, gen_preprocess_else);
					eat(Tok_Preprocess_Else);
					break;

				case Tok_Preprocess_EndIf:
					member = gen_cast(gen_Code, gen_preprocess_endif);
					eat(Tok_Preprocess_EndIf);
					break;

				case Tok_Preprocess_Macro_Stmt:
				{
					member = gen_cast(gen_Code, gen_parse_simple_preprocess(Tok_Preprocess_Macro_Stmt));
					// <gen_Macro>
					break;
				}

				case Tok_Preprocess_Pragma:
					member = gen_cast(gen_Code, gen_parse_pragma());
					// #pragma
					break;

				case Tok_Preprocess_Unsupported:
					member = gen_cast(gen_Code, gen_parse_simple_preprocess(Tok_Preprocess_Unsupported));
					// #<UNSUPPORTED>
					break;

				default:
				{
					gen_Token entry = currtok;

					eat(Tok_Identifier);
					// <Name>

					if (currtok.Type == Tok_Operator && currtok.Text.Ptr[0] == '=')
					{
						eat(Tok_Operator);
						// <Name> =

						while (currtok.Type != Tok_Comma && currtok.Type != Tok_BraceCurly_Close)
						{
							eat(currtok.Type);
						}
					}
					// <Name> = <Expression>

					// Unreal UMETA macro support
					if (currtok.Type == Tok_Preprocess_Macro_Expr)
					{
						gen_Code macro = gen_parse_simple_preprocess(Tok_Preprocess_Macro_Expr);
						// <Name> = <Expression> <gen_Macro>

						// We're intentially ignoring this code as its going to be serialized as an untyped string with the rest of the enum "entry".
						// TODO(Ed): We need a CodeEnumEntry, gen_AST_EnumEntry types
					}

					if (currtok.Type == Tok_Comma)
					{
						//gen_Token prev = * previous(gen__ctx->parser.Tokens, dont_skip_formatting);
						//entry.Length = ( (gen_sptr)prev.Text + prev.Length ) - (gen_sptr)entry.Text;

						eat(Tok_Comma);
						// <Name> = <Expression> <gen_Macro>,
					}

					// Consume inline comments
					// if ( currtok.Type == Tok_Comment && prevtok.Line == currtok.Line )
					// {
					// eat( Tok_Comment );
					// <Name> = <Expression> <gen_Macro>, // <Inline Comment>
					// }

					gen_Token prev = *gen_lex_previous(gen__ctx->parser.Tokens, gen_lex_dont_skip_formatting);
					entry.Text.Len = ((gen_sptr)prev.Text.Ptr + prev.Text.Len) - (gen_sptr)entry.Text.Ptr;

					member         = gen_untyped_str(entry.Text);
				}
				break;
			}

			if (member == gen_Code_Invalid)
			{
				gen_log_failure("Failed to parse member\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
				gen_parser_pop(&gen__ctx->parser);
				return gen_InvalidCode;
			}

			gen_body_append(body, member);
		}

		eat(Tok_BraceCurly_Close);
		// enum <class> <Attributes> <Name> : <UnderlyingType> { <Body> }
	}

	gen_CodeComment inline_cmt = gen_NullCode;

	if (! inplace_def)
	{
		gen_Token stmt_end = currtok;
		eat(Tok_Statement_End);
		// enum <class> <Attributes> <Name> : <UnderlyingType> { <Body> };

		if (currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line)
			inline_cmt = gen_parse_comment();
		// enum <class> <Attributes> <Name> : <UnderlyingType> { <Body> }; <InlineCmt>
	}

	gen_CodeEnum result = (gen_CodeEnum)gen_make_code();

	if (body)
	{
		result->Type = is_enum_class ? CT_Enum_Class : CT_Enum;
		result->Body = body;
	}
	else
	{
		result->Type = is_enum_class ? CT_Enum_Class_Fwd : CT_Enum_Fwd;
	}

	result->Name = gen_cache_str(name.Text);

	if (attributes)
		result->Attributes = attributes;

	result->UnderlyingTypeMacro = underlying_macro;
	result->UnderlyingType      = type;

	if (inline_cmt)
		result->InlineCmt = inline_cmt;


	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal inline gen_CodeBody gen_parser_parse_export_body()
{
	push_scope();
	gen_CodeBody result = gen_parse_global_nspace(CT_Export_Body);
	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal inline gen_CodeBody gen_parser_parse_extern_link_body()
{
	push_scope();
	gen_CodeBody result = gen_parse_global_nspace(CT_Extern_Linkage_Body);
	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_CodeExtern gen_parser_parse_extern_link()
{
	push_scope();

	eat(Tok_Decl_Extern_Linkage);
	// extern

	gen_Token name = currtok;
	eat(Tok_String);
	// extern "<Name>"

	name.Text.Ptr         += 1;
	name.Text.Len         -= 1;

	gen_CodeExtern result  = (gen_CodeExtern)gen_make_code();
	result->Type           = CT_Extern_Linkage;
	result->Name           = gen_cache_str(name.Text);

	gen_CodeBody entry     = gen_parser_parse_extern_link_body();
	if (gen_cast(gen_Code, entry) == gen_Code_Invalid)
	{
		gen_log_failure("Failed to parse body\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
		gen_parser_pop(&gen__ctx->parser);
		return result;
	}
	// extern "<Name>" { <Body> }

	result->Body = entry;

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_CodeFriend gen_parser_parse_friend()
{
	push_scope();

	eat(Tok_Decl_Friend);
	// friend

	gen_CodeFn         function   = { gen_nullptr };
	gen_CodeOperator   op         = { gen_nullptr };
	gen_CodeSpecifiers specifiers = { gen_nullptr };

	// Specifiers Parsing
	{
		gen_Specifier specs_found[16] = { Spec_NumSpecifiers };
		gen_s32       NumSpecifiers   = 0;

		while (left && gen_tok_is_specifier(currtok))
		{
			gen_Specifier spec = gen_str_to_specifier(currtok.Text);

			switch (spec)
			{
			GEN_PARSER_FRIEND_ALLOWED_SPECIFIER_CASES:
				break;

				default:
					gen_log_failure(
					    "Invalid specifier %S for friend definition\n%S",
					    gen_spec_to_str(spec),
					    gen_strbuilder_to_str(gen_parser_to_strbuilder(gen__ctx->parser))
					);
					gen_parser_pop(&gen__ctx->parser);
					return gen_InvalidCode;
			}

			// Ignore const it will be handled by the type
			if (spec == Spec_Const)
				break;

			specs_found[NumSpecifiers] = spec;
			NumSpecifiers++;
			eat(currtok.Type);
		}

		if (NumSpecifiers)
		{
			specifiers = gen_def_specifiers_arr(NumSpecifiers, specs_found);
		}
		// <friend> <specifiers>
	}

	// Type declaration or return type
	gen_CodeTypename type = gen_parser_parse_type(gen_parser_not_from_template, gen_nullptr);
	if (gen_cast(gen_Code, type) == gen_Code_Invalid)
	{
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}
	// friend <Type>

	// Funciton declaration
	if (currtok.Type == Tok_Identifier)
	{
		// Name
		gen_Token name               = gen_parse_identifier(gen_nullptr);
		gen__ctx->parser.Scope->Name = name.Text;
		// friend <ReturnType> <Name>

		function = gen_parse_function_after_name(ModuleFlag_None, gen_NullCode, specifiers, type, name);

		// Parameter list
		// gen_CodeParams params = gen_parse_params();
		// friend <ReturnType> <Name> ( <Parameters> )

		// function             = gen_make_code();
		// function->Type       = Function_Fwd;
		// function->Name       = gen_cache_str( name );
		// function->ReturnType = type;

		// if ( params )
		// function->Params = params;
	}

	// gen_Operator declaration or definition
	if (currtok.Type == Tok_Decl_Operator)
	{
		op = gen_parse_operator_after_ret_type(ModuleFlag_None, gen_NullCode, specifiers, type);
	}

	gen_CodeComment inline_cmt = gen_NullCode;
	if (function && function->Type == CT_Function_Fwd)
	{
		gen_Token stmt_end = currtok;
		eat(Tok_Statement_End);
		// friend <Type>;
		// friend <ReturnType> <Name> ( <Parameters> );

		if (currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line)
			inline_cmt = gen_parse_comment();
		// friend <Type>; <InlineCmt>
		// friend <ReturnType> <Name> ( <Parameters> ); <InlineCmt>
	}

	gen_CodeFriend result = (gen_CodeFriend)gen_make_code();
	result->Type          = CT_Friend;

	if (function)
		result->Declaration = gen_cast(gen_Code, function);
	else if (op)
		result->Declaration = gen_cast(gen_Code, op);
	else
		result->Declaration = gen_cast(gen_Code, type);

	if (inline_cmt)
		result->InlineCmt = inline_cmt;

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_CodeFn gen_parser_parse_function()
{
	push_scope();

	gen_Specifier specs_found[16] = { Spec_NumSpecifiers };
	gen_s32       NumSpecifiers   = 0;

	gen_CodeAttributes attributes = { gen_nullptr };
	gen_CodeSpecifiers specifiers = { gen_nullptr };
	gen_ModuleFlag     mflags     = ModuleFlag_None;

	if (check(Tok_Module_Export))
	{
		mflags = ModuleFlag_Export;
		eat(Tok_Module_Export);
	}
	// <export>

	attributes = gen_parse_attributes();
	// <export> <Attributes>

	while (left && gen_tok_is_specifier(currtok))
	{
		gen_Specifier spec = gen_str_to_specifier(currtok.Text);

		switch (spec)
		{
		GEN_PARSER_FUNCTION_ALLOWED_SPECIFIER_CASES:
			break;

			default:
				gen_log_failure("Invalid specifier %S for functon\n%SB", gen_spec_to_str(spec), gen_parser_to_strbuilder(gen__ctx->parser));
				gen_parser_pop(&gen__ctx->parser);
				return gen_InvalidCode;
		}

		if (spec == Spec_Const)
			continue;

		specs_found[NumSpecifiers] = spec;
		NumSpecifiers++;
		eat(currtok.Type);
	}

	if (NumSpecifiers)
	{
		specifiers = gen_def_specifiers_arr(NumSpecifiers, specs_found);
	}
	// <export> <Attributes> <Specifiers>

	gen_CodeTypename ret_type = gen_parser_parse_type(gen_parser_not_from_template, gen_nullptr);
	if (gen_cast(gen_Code, ret_type) == gen_Code_Invalid)
	{
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}
	// <export> <Attributes> <Specifiers> <ReturnType>

	gen_Token name               = gen_parse_identifier(gen_nullptr);
	gen__ctx->parser.Scope->Name = name.Text;
	if (! gen_tok_is_valid(name))
	{
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}
	// <export> <Attributes> <Specifiers> <ReturnType> <Name>

	gen_CodeFn result = gen_parse_function_after_name(mflags, attributes, specifiers, ret_type, name);
	// <export> <Attributes> <Specifiers> <ReturnType> <Name> ...

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_CodeNS gen_parser_parse_namespace()
{
	push_scope();

	eat(Tok_Decl_Namespace);
	// namespace

	gen_Token name               = gen_parse_identifier(gen_nullptr);
	gen__ctx->parser.Scope->Name = name.Text;
	// namespace <Name>

	gen_CodeBody body = gen_parse_global_nspace(CT_Namespace_Body);
	if (gen_cast(gen_Code, body) == gen_Code_Invalid)
	{
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}
	// namespace <Name> { <Body> }

	gen_CodeNS result = (gen_CodeNS)gen_make_code();
	result->Type      = CT_Namespace;
	result->Name      = gen_cache_str(name.Text);

	result->Body      = body;

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_CodeOperator gen_parser_parse_operator()
{
	push_scope();

	gen_CodeAttributes attributes = { gen_nullptr };
	gen_CodeSpecifiers specifiers = { gen_nullptr };
	gen_ModuleFlag     mflags     = ModuleFlag_None;

	gen_Specifier specs_found[16] = { Spec_NumSpecifiers };
	gen_s32       NumSpecifiers   = 0;

	if (check(Tok_Module_Export))
	{
		mflags = ModuleFlag_Export;
		eat(Tok_Module_Export);
	}
	// <export>

	attributes = gen_parse_attributes();
	// <export> <Attributes>

	while (left && gen_tok_is_specifier(currtok))
	{
		gen_Specifier spec = gen_str_to_specifier(currtok.Text);

		switch (spec)
		{
		GEN_PARSER_OPERATOR_ALLOWED_SPECIFIER_CASES:
			break;

			default:
				gen_log_failure(
				    "Invalid specifier "
				    "%S"
				    " for operator\n%SB",
				    gen_spec_to_str(spec),
				    gen_parser_to_strbuilder(gen__ctx->parser)
				);
				gen_parser_pop(&gen__ctx->parser);
				return gen_InvalidCode;
		}

		if (spec == Spec_Const)
			continue;

		specs_found[NumSpecifiers] = spec;
		NumSpecifiers++;
		eat(currtok.Type);
	}

	if (NumSpecifiers)
	{
		specifiers = gen_def_specifiers_arr(NumSpecifiers, specs_found);
	}
	// <export> <Attributes> <Specifiers>

	// Parse Return Type
	gen_CodeTypename ret_type = gen_parser_parse_type(gen_parser_not_from_template, gen_nullptr);
	// <export> <Attributes> <Specifiers> <ReturnType>

	gen_CodeOperator result = gen_parse_operator_after_ret_type(mflags, attributes, specifiers, ret_type);
	// <export> <Attributes> <Specifiers> <ReturnType> ...

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_CodeOpCast gen_parser_parse_operator_cast(gen_CodeSpecifiers specifiers)
{
	push_scope();

	// gen_Operator's namespace if not within same class.
	gen_Token name = gen_NullToken;
	if (check(Tok_Identifier))
	{
		name = currtok;
		while (left && currtok.Type == Tok_Identifier)
		{
			eat(Tok_Identifier);
			// <Specifiers> <Qualifier>

			if (currtok.Type == Tok_Access_StaticSymbol)
				eat(Tok_Access_StaticSymbol);
			// <Specifiers> <Qualifier> ::
		}
		// <Specifiers> <Qualifier> :: ...

		name.Text.Len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)name.Text.Ptr;
	}

	eat(Tok_Decl_Operator);
	// <Specifiers> <Qualifier> :: ... operator

	gen_CodeTypename type = gen_parser_parse_type(gen_parser_not_from_template, gen_nullptr);
	// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>

	gen_Str   scope_name         = { type->Name.Ptr, type->Name.Len };
	gen_Token scope_name_tok     = { scope_name, Tok_Identifier, 0, 0, TF_Null };
	gen__ctx->parser.Scope->Name = scope_name_tok.Text;

	eat(Tok_Paren_Open);
	eat(Tok_Paren_Close);
	// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>()

	// TODO(Ed) : operator gen_cast can have const, volatile, l-value, r-value noexecept qualifying specifiers.
	if (check(Tok_Spec_Const))
	{
		if (specifiers == gen_nullptr)
			specifiers = gen_def_specifier(Spec_Const);

		else
			gen_specifiers_append(specifiers, Spec_Const);

		eat(Tok_Spec_Const);
	}
	// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>() <const>

	gen_Code        body       = gen_NullCode;
	gen_CodeComment inline_cmt = gen_NullCode;

	if (check(Tok_BraceCurly_Open))
	{
		eat(Tok_BraceCurly_Open);
		// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>() <const> {

		gen_Token gen_body_str = currtok;

		gen_s32 level          = 0;
		while (left && (currtok.Type != Tok_BraceCurly_Close || level > 0))
		{
			if (currtok.Type == Tok_BraceCurly_Open)
				level++;

			else if (currtok.Type == Tok_BraceCurly_Close)
				level--;

			eat(currtok.Type);
		}
		gen_body_str.Text.Len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)gen_body_str.Text.Ptr;

		eat(Tok_BraceCurly_Close);
		// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>() <const> { <Body> }

		body = gen_untyped_str(gen_body_str.Text);
	}
	else
	{
		gen_Token stmt_end = currtok;
		eat(Tok_Statement_End);
		// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>() <const>;

		if (currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line)
			inline_cmt = gen_parse_comment();
		// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>() <const>; <InlineCmt>
	}

	gen_CodeOpCast result = (gen_CodeOpCast)gen_make_code();

	if (gen_tok_is_valid(name))
		result->Name = gen_cache_str(name.Text);

	if (body)
	{
		result->Type = CT_Operator_Cast;
		result->Body = gen_cast(gen_CodeBody, body);
	}
	else
	{
		result->Type = CT_Operator_Cast_Fwd;
	}

	if (specifiers)
		result->Specs = specifiers;

	result->ValueType = gen_cast(gen_CodeTypename, type);

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal inline gen_CodeStruct gen_parser_parse_struct(bool inplace_def)
{
	push_scope();
	gen_CodeStruct result = (gen_CodeStruct)gen_parse_class_struct(Tok_Decl_Struct, inplace_def);
	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_CodeTemplate gen_parser_parse_template()
{
#define UseTemplateCapture true

	push_scope();

	gen_ModuleFlag mflags = ModuleFlag_None;

	if (check(Tok_Module_Export))
	{
		mflags = ModuleFlag_Export;
		eat(Tok_Module_Export);
	}
	// <export> template

	eat(Tok_Decl_Template);
	// <export> template

	gen_CodeParams params = gen_parse_params(UseTemplateCapture);
	if (gen_cast(gen_Code, params) == gen_Code_Invalid)
	{
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}
	// <export> template< <Parameters> >

	gen_Code definition = { gen_nullptr };

	while (left)
	{
		if (check(Tok_Decl_Class))
		{
			definition = gen_cast(gen_Code, gen_parser_parse_class(gen_parser_not_inplace_def));
			// <export> template< <Parameters> > class ...
			break;
		}

		if (check(Tok_Decl_Struct))
		{
			definition = gen_cast(gen_Code, gen_parser_parse_struct(gen_parser_not_inplace_def));
			// <export> template< <Parameters> > struct ...
			break;
		}

		if (check(Tok_Decl_Union))
		{
			definition = gen_cast(gen_Code, gen_parser_parse_union(gen_parser_not_inplace_def));
			// <export> template< <Parameters> > union ...
			break;
		}

		if (check(Tok_Decl_Using))
		{
			definition = gen_cast(gen_Code, gen_parser_parse_using());
			// <export> template< <Parameters> > using ...
			break;
		}

		// Its either a function or a variable
		gen_Token name                = gen_NullToken;

		gen_CodeAttributes attributes = { gen_nullptr };
		gen_CodeSpecifiers specifiers = { gen_nullptr };

		bool expects_function         = false;

		gen_Specifier specs_found[16] = { Spec_NumSpecifiers };
		gen_s32       NumSpecifiers   = 0;

		attributes                    = gen_parse_attributes();
		// <export> template< <Parameters> > <Attributes>

		// Specifiers Parsing
		{
			while (left && gen_tok_is_specifier(currtok))
			{
				gen_Specifier spec = gen_str_to_specifier(currtok.Text);

				switch (spec)
				{
				GEN_PARSER_TEMPLATE_ALLOWED_SPECIFIER_CASES:
					break;

					case Spec_Consteval:
						expects_function = true;
						break;

					default:
						gen_log_failure(
						    "Invalid specifier %S for variable or function\n%SB",
						    gen_spec_to_str(spec),
						    gen_parser_to_strbuilder(gen__ctx->parser)
						);
						gen_parser_pop(&gen__ctx->parser);
						return gen_InvalidCode;
				}

				// Ignore const it will be handled by the type
				if (spec == Spec_Const)
					break;

				specs_found[NumSpecifiers] = spec;
				NumSpecifiers++;
				eat(currtok.Type);
			}

			if (NumSpecifiers)
			{
				specifiers = gen_def_specifiers_arr(NumSpecifiers, specs_found);
			}
			// <export> template< <Parameters> > <Attributes> <Specifiers>
		}


		bool has_context         = gen__ctx->parser.Scope && gen__ctx->parser.Scope->Prev;
		bool is_in_global_nspace = has_context && gen_str_are_equal(gen__ctx->parser.Scope->Prev->ProcName, txt("gen_parse_global_nspace"));
		// Possible gen_constructor_ implemented at gen_global file scope.
		if (is_in_global_nspace)
		{
			gen_Code gen_constructor__destructor = gen_parse_global_nspace_constructor_destructor(specifiers);
			if (gen_constructor__destructor)
			{
				definition = gen_constructor__destructor;
				// <Attributes> <Specifiers> <Name> :: <Name> <Type> () { ... }
				break;
			}
		}

		// Possible user Defined operator casts
		if (is_in_global_nspace)
		{
			bool    found_operator_cast_outside_class_implmentation = false;
			gen_s32 idx                                             = gen__ctx->parser.Tokens.Idx;

			for (; idx < gen_array_num(gen__ctx->parser.Tokens.Arr); idx++)
			{
				gen_Token tok = gen__ctx->parser.Tokens.Arr[idx];

				if (tok.Type == Tok_Identifier)
				{
					idx++;
					tok = gen__ctx->parser.Tokens.Arr[idx];
					if (tok.Type == Tok_Access_StaticSymbol)
						continue;

					break;
				}

				if (tok.Type == Tok_Decl_Operator)
					found_operator_cast_outside_class_implmentation = true;

				break;
			}

			if (found_operator_cast_outside_class_implmentation)
			{
				definition = gen_cast(gen_Code, gen_parser_parse_operator_cast(specifiers));
				// <Attributes> <Specifiers> <Name> :: operator <Type> () { ... }
				break;
			}
		}

		definition = gen_parse_operator_function_or_variable(expects_function, attributes, specifiers);
		// <export> template< <Parameters> > <Attributes> <Specifiers> ...
		break;
	}

	gen_CodeTemplate result = (gen_CodeTemplate)gen_make_code();
	result->Type            = CT_Template;
	result->Params          = params;
	result->Declaration     = definition;
	result->ModuleFlags     = mflags;
	// result->Name        = definition->Name;

	gen_parser_pop(&gen__ctx->parser);
	return result;
#undef UseTemplateCapture
}

/*
	This is a mess, but it works
	Parsing typename is arguably one of the worst aspects of C/C++.
	This is an effort to parse it without a full blown or half-blown compliant parser.

	Recursive function typenames are not supported, if they are used expect it to serailize just fine, but validation with gen_AST::is_equal
	will not be possible if two ASTs share the same definiton but the formatting is slightly different:
	gen_AST_1->Name: (* A    ( int   (*)    (short a,unsigned b,long c) ) )
	gen_AST_2->Name: (* A       ( int(*)(short a, unsigned b, long c) ) )

	The excess whitespace cannot be stripped however, because there is no semantic awareness within the first capture group.
*/
gen_internal gen_CodeTypename gen_parser_parse_type(bool from_template, bool* gen_typedef_is_function)
{
	push_scope();

	gen_Token context_tok         = prevtok;

	gen_Specifier specs_found[16] = { Spec_NumSpecifiers };
	gen_s32       NumSpecifiers   = 0;

	gen_Token name                = gen_NullToken;

	gen_ETypenameTag tag          = Tag_None;

	// Attributes are assumed to be before the type signature
	gen_CodeAttributes attributes = gen_parse_attributes();
	// <Attributes>

	// Prefix specifiers
	while (left && gen_tok_is_specifier(currtok))
	{
		gen_Specifier spec = gen_str_to_specifier(currtok.Text);

		if (spec != Spec_Const)
		{
			gen_log_failure("Error, invalid specifier used in type definition: %S\n%SB", currtok.Text, gen_parser_to_strbuilder(gen__ctx->parser));
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}

		specs_found[NumSpecifiers] = spec;
		NumSpecifiers++;
		eat(currtok.Type);
	}
	// <Attributes> <Specifiers>

	if (left == 0)
	{
		gen_log_failure("Error, unexpected end of type definition\n%SB", gen_parser_to_strbuilder(gen__ctx->parser));
		gen_parser_pop(&gen__ctx->parser);
		return gen_InvalidCode;
	}

	if (from_template && currtok.Type == Tok_Decl_Class)
	{
		// If a value's type is being parsed from a template, class can be used instead of typename.
		name = currtok;
		eat(Tok_Decl_Class);
		// <class>
	}

	// All kinds of nonsense can makeup a type signature, first we check for a in-place definition of a class, enum, struct, or union
	else if (currtok.Type == Tok_Decl_Class || currtok.Type == Tok_Decl_Enum || currtok.Type == Tok_Decl_Struct || currtok.Type == Tok_Decl_Union)
	{
		switch (currtok.Type)
		{
			case Tok_Decl_Class:
				tag = Tag_Class;
				break;
			case Tok_Decl_Enum:
				tag = Tag_Enum;
				break;
			case Tok_Decl_Struct:
				tag = Tag_Struct;
				break;
			case Tok_Decl_Union:
				tag = Tag_Union;
				break;
			default:
				break;
		}
		eat(currtok.Type);
		// <Attributes> <Specifiers> <class, enum, struct, union>

		name = gen_parse_identifier(gen_nullptr);

		// name.Length = ( ( gen_sptr )currtok.Text + currtok.Length ) - ( gen_sptr )name.Text;
		// eat( Tok_Identifier );
		gen__ctx->parser.Scope->Name = name.Text;
		// <Attributes> <Specifiers> <class, enum, struct, union> <Name>
	}

// Decltype draft implementation
#if 0
else if ( currtok.Type == Tok_DeclType )
{
	// Will have a capture and its own parsing rules, were going to just shove everything in a string (for now).
	name = currtok;
	eat( Tok_DeclType );
	// <Attributes> <Specifiers> decltype

	eat( Tok_Paren_Open );
	while ( left && currtok.Type != Tok_Paren_Close )
	{
		if ( currtok.Type == Tok_Paren_Open )
			level++;

		if ( currtok.Type == Tok_Paren_Close )
			level--;

		eat( currtok.Type );
	}
	eat( Tok_Paren_Close );

	name.Length = ( (gen_sptr)currtok.Text + currtok.Length ) - (gen_sptr)name.Text;
	gen__ctx->parser.Scope->Name = name;
	// <Attributes> <Specifiers> decltype( <Expression > )
}
#endif

	// Check if native type keywords are used, eat them for the signature.
	// <attributes> <specifiers> <native types ...> ...
	else if (currtok.Type >= Tok_Type_Unsigned && currtok.Type <= Tok_Type_MS_W64)
	{
		// TODO(Ed) : Review this... Its necessary for parsing however the algo's path to this is lost...
		name = currtok;
		eat(currtok.Type);

		while (left && currtok.Type >= Tok_Type_Unsigned && currtok.Type <= Tok_Type_MS_W64)
		{
			eat(currtok.Type);
		}

		name.Text.Len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)name.Text.Ptr;
		// <Attributes> <Specifiers> <Compound type expression>
	}
	else if (currtok.Type == Tok_Type_Typename)
	{
		name = currtok;
		eat(Tok_Type_Typename);
		// <typename>

		if (! from_template)
		{
			name                         = gen_parse_identifier(gen_nullptr);
			gen__ctx->parser.Scope->Name = name.Text;
			if (! gen_tok_is_valid(name))
			{
				gen_log_failure("Error, failed to type signature\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
				gen_parser_pop(&gen__ctx->parser);
				return gen_InvalidCode;
			}
		}
	}
	else if (currtok.Type == Tok_Preprocess_Macro_Typename)
	{
		// Typename is a macro
		// name = currtok;
		// eat(Tok_Preprocess_Macro_Typename);
		gen_Code macro = gen_parse_simple_preprocess(Tok_Preprocess_Macro_Typename);
		name.Text      = macro->Content;
	}

	// The usual Identifier type signature that may have namespace qualifiers
	else
	{
		name                         = gen_parse_identifier(gen_nullptr);
		gen__ctx->parser.Scope->Name = name.Text;
		if (! gen_tok_is_valid(name))
		{
			gen_log_failure("Error, failed to type signature\n%s", gen_parser_to_strbuilder(gen__ctx->parser));
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}
		// <Attributes> <Specifiers> <Qualifier ::> <Identifier>
		// <Attributes> <Specifiers> <Identifier>
	}

	// Suffix specifiers for typename.
	while (left && gen_tok_is_specifier(currtok))
	{
		gen_Specifier spec = gen_str_to_specifier(currtok.Text);

		switch (spec)
		{
		GEN_PARSER_TYPENAME_ALLOWED_SUFFIX_SPECIFIER_CASES:
			break;

			default:
			{
				gen_log_failure("Error, invalid specifier used in type definition: %S\n%SB", currtok.Text, gen_parser_to_strbuilder(gen__ctx->parser));
				gen_parser_pop(&gen__ctx->parser);
				return gen_InvalidCode;
			}
		}
		specs_found[NumSpecifiers] = spec;
		NumSpecifiers++;
		eat(currtok.Type);
	}

#ifdef GEN_USE_NEW_TYPENAME_PARSING
	if (NumSpecifiers)
	{
		specifiers    = gen_def_specifiers_arr(NumSpecifiers, specs_found);
		NumSpecifiers = 0;
	}
#endif
	// <Attributes> <Specifiers> <Identifier> <Specifiers>

	// For function type signatures
	gen_CodeTypename return_type = gen_NullCode;
	gen_CodeParams   params      = gen_NullCode;

#ifdef GEN_USE_NEW_TYPENAME_PARSING
	gen_CodeParams gen_params_nested = gen_NullCode;
#endif

	bool       is_function_typename = false;
	gen_Token* last_capture         = gen_nullptr;
	{
		gen_Token* scanner = gen__ctx->parser.Tokens.Arr + gen__ctx->parser.Tokens.Idx;

		// An identifier being within a typename's signature only occurs if were parsing a typename for a typedef.
		if (gen_typedef_is_function && scanner->Type == Tok_Identifier)
		{
			is_function_typename = true;
			++scanner;
		}
		is_function_typename     = scanner->Type == Tok_Paren_Open;

		gen_Token* first_capture = scanner;
		if (is_function_typename)
		{
			// Go to the end of the signature
			while (scanner->Type != Tok_Statement_End && scanner->Type != Tok_BraceCurly_Open)
				++scanner;

			// Go back to the first capture start found
			while (scanner->Type != Tok_Paren_Open)
				--scanner;

			last_capture = scanner;
		}

		bool has_context   = gen__ctx->parser.Scope && gen__ctx->parser.Scope->Prev;
		bool is_for_opcast = has_context && gen_str_are_equal(gen__ctx->parser.Scope->Prev->ProcName, txt("gen_parser_parse_operator_cast"));
		if (is_for_opcast && is_function_typename && last_capture)
		{
			// If we're parsing for an operator gen_cast, having one capture start is not enough
			// we need to make sure that the capture is not for the gen_cast definition.
			is_function_typename = false;

			if (last_capture == first_capture)
			{
				// The capture start in question is the first capture start, this is not a function typename.
				is_function_typename = false;
			}
		}
	}

	if (is_function_typename)
	{
		// We're dealing with a function typename.
		// By this point, decltype should have been taken care of for return type, along with any all its specifiers

		// The previous information with exception to attributes will be considered the return type.
		return_type       = (gen_CodeTypename)gen_make_code();
		return_type->Type = CT_Typename;

		// gen_StrBuilder
		// name_stripped = gen_StrBuilder::make( FallbackAllocator, name );
		// name_stripped.strip_space();
		return_type->Name = gen_cache_str(name.Text);

#ifdef GEN_USE_NEW_TYPENAME_PARSING
		if (specifiers)
		{
			return_type->Specs = specifiers;
			specifiers         = gen_nullptr;
		}

#else
		if (NumSpecifiers)
			return_type->Specs = gen_def_specifiers_arr(NumSpecifiers, (gen_Specifier*)specs_found);

		// Reset specifiers, the function itself will have its own suffix specifiers possibly.
		NumSpecifiers = 0;
#endif
		// <Attributes> <ReturnType>
		name = gen_NullToken;

		// The next token can either be a capture for the identifier or it could be the identifier exposed.
		if (! check(Tok_Paren_Open))
		{
			// Started with an identifier immeidately, which means its of the format: <ReturnType> <identifier> <capture>;
			name = gen_parse_identifier(gen_nullptr);
		}
		// <Attributes> <ReturnType> <Identifier>

		// If the next token is a capture start and is not the last capture, then we're dealing with function typename whoose identifier is within the
		// capture.
		else if ((gen__ctx->parser.Tokens.Arr + gen__ctx->parser.Tokens.Idx) != last_capture)
		{
			// WIP : Possible alternative without much pain...
			// If this were to be parsed properly...
			// Eat Capture Start
			// Deal with possible binding specifiers (*, &, &&) and modifiers on those bindings (const, volatile)
			// Parse specifiers for the typename with an optional identifier,
			// we can shove these specific specifiers into a specs, and then leave the suffix ones for a separate member of the gen_AST.
			// Parse immeidate capture which would be with gen_parse_params()
			// Eat Capture End
#ifdef GEN_USE_NEW_TYPENAME_PARSING
			eat(Tok_Paren_Open);
			// <Attributes> <ReturnType> (

			// Binding specifiers
			while (left && currtok.is_specifier())
			{
				gen_Specifier spec = to_type(currtok);

				if (spec != Spec_Ptr && spec != Spec_Ref && spec != Spec_RValue)
				{
					gen_log_failure("Error, invalid specifier used in type definition: %S\n%SB", gen_toktype_to_str(currtok), to_strbuilder(gen__ctx->parser));
					pop(&gen__ctx->parser);
					return gen_InvalidCode;
				}

				specs_found[NumSpecifiers] = spec;
				NumSpecifiers++;
				eat(currtok.Type);
			}

			if (NumSpecifiers)
			{
				specifiers = gen_def_specifiers_arr(NumSpecifiers, specs_found);
			}
			NumSpecifiers = 0;
			// <Attributes> <ReturnType> ( <Specifiers>

			if (check(Tok_Identifier))
				name = gen_parse_identifier();
			// <Attributes> <ReturnType> ( <Specifiers> <Identifier>

			// Immeidate parameters

			if (check(Tok_Paren_Open))
				gen_params_nested = gen_parse_params();
			// <Attributes> <ReturnType> ( <Specifiers> <Identifier> ( <Parameters> )

			eat(Tok_Paren_Close);
			// <Attributes> <ReturnType> ( <Specifiers> <Identifier> ( <Parameters> ) )

#else
			// Starting immediatley with a capture, most likely declaring a typename for a member function pointer.
			// Everything within this capture will just be shoved into the name field including the capture tokens themselves.
			name = currtok;

			eat(Tok_Paren_Open);
			// <Attributes> <ReturnType> (

			gen_s32 level = 0;
			while (left && (currtok.Type != Tok_Paren_Close || level > 0))
			{
				if (currtok.Type == Tok_Paren_Open)
					level++;

				if (currtok.Type == Tok_Paren_Close)
					level--;

				eat(currtok.Type);
			}
			eat(Tok_Paren_Close);
			// <Attributes> <ReturnType> ( <Expression> )

			name.Text.Len = ((gen_sptr)prevtok.Text.Ptr + prevtok.Text.Len) - (gen_sptr)name.Text.Ptr;
#endif
		}

		// Were now dealing with the parameters of the function
		params = gen_parse_params(gen_parser_use_parenthesis);
		// <Attributes> <ReturnType> <All Kinds of nonsense> ( <Parameters> )

		// Look for suffix specifiers for the function
		while (left && gen_tok_is_specifier(currtok))
		{
			gen_Specifier spec = gen_str_to_specifier(currtok.Text);

			if (spec != Spec_Const
			    // TODO : Add support for NoExcept, l-value, volatile, l-value, etc
			    // && spec != Spec_NoExcept
			    && spec != Spec_RValue)
			{
				gen_log_failure(
				    "Error, invalid specifier used in type definition: %S\n%S",
				    currtok.Text,
				    gen_strbuilder_to_str(gen_parser_to_strbuilder(gen__ctx->parser))
				);
				gen_parser_pop(&gen__ctx->parser);
				return gen_InvalidCode;
			}

			specs_found[NumSpecifiers] = spec;
			NumSpecifiers++;
			eat(currtok.Type);
		}

#ifdef GEN_USE_NEW_TYPENAME_PARSING
		if (NumSpecifiers)
		{
			func_suffix_specs = gen_def_specifiers_arr(NumSpecifiers, specs_found);
			NumSpecifiers     = 0;
		}
#endif
		// <Attributes> <ReturnType> <All Kinds of nonsense> ( <Parameters> ) <Specifiers>
	}
	// <Attributes> <All Kinds of nonsense>

	bool is_param_pack = false;
	if (check(Tok_Varadic_Argument))
	{
		is_param_pack = true;
		eat(Tok_Varadic_Argument);
		// <Attributes> <All kinds of nonsense> ...
	}

	gen_CodeTypename result = (gen_CodeTypename)gen_make_code();
	result->Type            = CT_Typename;
	// result->gen_Token = gen__ctx->parser.Scope->Start;

	// Need to wait until were using the new parsing method to do this.
	gen_StrBuilder name_stripped = gen_parser_strip_formatting(name.Text, gen_parser_strip_formatting_dont_preserve_newlines);

	// name_stripped.strip_space();

#ifdef GEN_USE_NEW_TYPENAME_PARSING
	if (gen_params_nested)
	{
		name_stripped.append(gen_params_nested->to_strbuilder());
	}
#endif

	result->Name = gen_cache_str(gen_strbuilder_to_str(name_stripped));

	if (attributes)
		result->Attributes = attributes;

#ifdef GEN_USE_NEW_TYPENAME_PARSING
	if (specifiers)
	{
		result->Specs = specifiers;
	}

	if (func_suffix_specs)
	{
		result->FuncSuffixSpecs = func_suffix_specs;
	}
#else
	if (NumSpecifiers)
	{
		gen_CodeSpecifiers specifiers = gen_def_specifiers_arr(NumSpecifiers, (gen_Specifier*)specs_found);
		result->Specs                 = specifiers;
	}
#endif

	if (is_param_pack)
		result->IsParamPack = true;

	// These following are only populated if its a function typename
	if (return_type)
	{
		result->ReturnType = return_type;

		if (gen_typedef_is_function)
			*gen_typedef_is_function = true;
	}

	if (params)
		result->Params = params;

	result->TypeTag = tag;

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_CodeTypedef gen_parser_parse_typedef()
{
	push_scope();

	bool      is_function    = false;
	gen_Token name           = gen_NullToken;
	gen_Code  gen_array_expr = { gen_nullptr };
	gen_Code  type           = { gen_nullptr };

	gen_ModuleFlag mflags    = ModuleFlag_None;

	if (check(Tok_Module_Export))
	{
		mflags = ModuleFlag_Export;
		eat(Tok_Module_Export);
	}
	// <ModuleFlags>

	eat(Tok_Decl_Typedef);
	// <ModuleFlags> typedef

	const bool from_typedef = true;

	// TODO(Ed): UPDATE MACRO USAGE HERE
#if GEN_PARSER_DISABLE_MACRO_TYPEDEF
	if (false)
#else
	gen_b32 valid_macro  = false;
	valid_macro         |= left && currtok.Type == Tok_Preprocess_Macro_Typename;
	valid_macro         |= left && currtok.Type == Tok_Preprocess_Macro_Stmt;
	// if (currtok.Type == Tok_Preprocess_Macro_Stmt)
	// {
	// PreprocessMacro* macro = lookup_macro(currtok.Text);
	// valid_macro |= macro && gen_macro_expects_body(* macro));
	// }

	if (valid_macro)
#endif
	{
		type                         = gen_cast(gen_Code, gen_t_empty);
		name                         = currtok;
		gen_Code macro               = gen_parse_simple_preprocess(currtok.Type);
		name.Text.Len                = macro->Content.Len;
		gen__ctx->parser.Scope->Name = name.Text;
		// <ModuleFalgs> typedef <Preprocessed_Macro>

		if (currtok.Type == Tok_Identifier)
		{
			type = macro;
			name = currtok;
			eat(Tok_Identifier);
			// <ModuleFalgs> typedef <Preprocessed_Macro> <Identifier>
		}
	}
	else
	{
		bool is_complicated =
		    currtok.Type == Tok_Decl_Enum || currtok.Type == Tok_Decl_Class || currtok.Type == Tok_Decl_Struct || currtok.Type == Tok_Decl_Union;


		// This code is highly correlated with gen_parse_complicated_definition
		if (is_complicated)
		{
			gen_TokArray tokens = gen__ctx->parser.Tokens;
			gen_TokType  which  = currtok.Type;

			gen_s32 idx         = tokens.Idx;
			gen_s32 level       = 0;
			for (; idx < gen_array_num(tokens.Arr); idx++)
			{
				if (tokens.Arr[idx].Type == Tok_BraceCurly_Open)
					level++;

				if (tokens.Arr[idx].Type == Tok_BraceCurly_Close)
					level--;

				if (level == 0 && tokens.Arr[idx].Type == Tok_Statement_End)
					break;
			}

			gen_Token pre_foward_tok = currtok;
			if ((idx - 3) == tokens.Idx)
			{
				// Its a forward declaration only
				type = gen_parse_forward_or_definition(which, from_typedef);
				// <ModuleFalgs> typedef <UnderlyingType: Forward Decl>
			}
			else
			{
				gen_Token tok = tokens.Arr[idx - 1];
				if (tok.Type == Tok_Identifier)
				{
					gen_log_fmt("Found id\n");
					tok                 = tokens.Arr[idx - 2];

					bool is_indirection = tok.Type == Tok_Ampersand || tok.Type == Tok_Star;

					bool ok_to_parse    = false;

					gen_Token temp_3    = tokens.Arr[idx - 3];

					if (tok.Type == Tok_BraceCurly_Close)
					{
						// Its an inplace definition
						// typedef <which> <type_identifier> { ... } <identifier>;
						ok_to_parse = true;
					}
					else if (tok.Type == Tok_Identifier && tokens.Arr[idx - 3].Type == which)
					{
						// Its a variable with type ID using which namespace.
						// typedef <which> <type_identifier> <identifier>;
						ok_to_parse = true;
					}
					else if (is_indirection)
					{
						// Its a indirection type with type ID using struct namespace.
						// typedef <which> <type_identifier>* <identifier>;
						ok_to_parse = true;
					}

					if (! ok_to_parse)
					{
						gen_log_failure("Unsupported or bad member definition after struct declaration\n%SB", gen_parser_to_strbuilder(gen__ctx->parser));
						gen_parser_pop(&gen__ctx->parser);
						return gen_InvalidCode;
					}

					// TODO(Ed) : I'm not sure if I have to use gen_parser_parse_type here, I'd rather not as that would complicate gen_parser_parse_type.
					// type = gen_parser_parse_type();
					type = gen_parse_forward_or_definition(which, from_typedef);
					// <ModuleFalgs> typedef <UnderlyingType>
				}
				else if (tok.Type == Tok_BraceCurly_Close)
				{
					// Its a definition
					// <which> { ... };
					type = gen_parse_forward_or_definition(currtok.Type, from_typedef);
					// <ModuleFalgs> typedef <UnderlyingType>
				}
				else if (tok.Type == Tok_BraceSquare_Close)
				{
					// Its an array definition
					// <which> <type_identifier> <identifier> [ ... ];
					type = gen_cast(gen_Code, gen_parser_parse_type(gen_parser_not_from_template, gen_nullptr));
					// <ModuleFalgs> typedef <UnderlyingType>
				}
				else
				{
					gen_log_failure("Unsupported or bad member definition after struct declaration\n%SB", gen_parser_to_strbuilder(gen__ctx->parser));
					gen_parser_pop(&gen__ctx->parser);
					return gen_InvalidCode;
				}
			}
		}
		else
		{
			bool from_template = false;
			type               = gen_cast(gen_Code, gen_parser_parse_type(from_template, &is_function));
			// <ModuleFalgs> typedef <UnderlyingType>
		}

		if (check(Tok_Identifier))
		{
			name = currtok;
			eat(Tok_Identifier);
			// <ModuleFalgs> typedef <UnderlyingType> <Name>
		}
		else if (! is_function)
		{
			gen_log_failure("Error, expected identifier for typedef\n%SB", gen_parser_to_strbuilder(gen__ctx->parser));
			gen_parser_pop(&gen__ctx->parser);
			return gen_InvalidCode;
		}

		gen_array_expr = gen_parse_array_decl();
		// <UnderlyingType> + <ArrayExpr>
	}

	gen_Token stmt_end = currtok;
	eat(Tok_Statement_End);
	// <ModuleFalgs> typedef <UnderlyingType> <Name>;

	gen_CodeComment inline_cmt = gen_NullCode;
	if (currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line)
		inline_cmt = gen_parse_comment();
	// <ModuleFalgs> typedef <UnderlyingType> <Name> <ArrayExpr>; <InlineCmt>

	gen_CodeTypedef result = (gen_CodeTypedef)gen_make_code();
	result->Type           = CT_Typedef;
	result->ModuleFlags    = mflags;

	if (is_function)
	{
		result->Name       = type->Name;
		result->IsFunction = true;
	}
	else
	{
		result->Name       = gen_cache_str(name.Text);
		result->IsFunction = false;
	}

	if (type)
	{
		result->UnderlyingType         = type;
		result->UnderlyingType->Parent = gen_cast(gen_Code, result);
	}
	// Type needs to be aware of its parent so that it can be serialized properly.

	if (type->Type == CT_Typename && gen_array_expr && gen_array_expr->Type != CT_Invalid)
		gen_cast(gen_CodeTypename, type)->ArrExpr = gen_array_expr;

	if (inline_cmt)
		result->InlineCmt = inline_cmt;

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_neverinline gen_CodeUnion gen_parser_parse_union(bool inplace_def)
{
	push_scope();

	gen_ModuleFlag mflags = ModuleFlag_None;

	if (check(Tok_Module_Export))
	{
		mflags = ModuleFlag_Export;
		eat(Tok_Module_Export);
	}
	// <ModuleFlags>

	eat(Tok_Decl_Union);
	// <ModuleFlags> union

	gen_CodeAttributes attributes = gen_parse_attributes();
	// <ModuleFlags> union <Attributes>

	gen_Str name = { gen_nullptr, 0 };
	if (check(Tok_Identifier))
	{
		name                         = currtok.Text;
		gen__ctx->parser.Scope->Name = currtok.Text;
		eat(Tok_Identifier);
	}
	// <ModuleFlags> union <Attributes> <Name>

	gen_CodeBody body = { gen_nullptr };

	if (! inplace_def || ! check(Tok_Identifier))
	{
		eat(Tok_BraceCurly_Open);
		// <ModuleFlags> union <Attributes> <Name> {

		body       = gen_cast(gen_CodeBody, gen_make_code());
		body->Type = CT_Union_Body;

		while (! check_noskip(Tok_BraceCurly_Close))
		{
			if (currtok_noskip.Type == Tok_Preprocess_Hash)
				eat(Tok_Preprocess_Hash);

			gen_Code member = { gen_nullptr };
			switch (currtok_noskip.Type)
			{
				case Tok_NewLine:
					member = gen_fmt_newline;
					eat(Tok_NewLine);
					break;

				case Tok_Comment:
					member = gen_cast(gen_Code, gen_parse_comment());
					break;

					// TODO(Ed) : Unions can have gen_constructor_s and gen_destructor_s

				case Tok_Decl_Class:
					member = gen_parse_complicated_definition(Tok_Decl_Class);
					break;

				case Tok_Decl_Enum:
					member = gen_parse_complicated_definition(Tok_Decl_Enum);
					break;

				case Tok_Decl_Struct:
					member = gen_parse_complicated_definition(Tok_Decl_Struct);
					break;

				case Tok_Decl_Union:
					member = gen_parse_complicated_definition(Tok_Decl_Union);
					break;

				case Tok_Preprocess_Define:
					member = gen_cast(gen_Code, gen_parser_parse_define());
					break;

				case Tok_Preprocess_If:
				case Tok_Preprocess_IfDef:
				case Tok_Preprocess_IfNotDef:
				case Tok_Preprocess_ElIf:
					member = gen_cast(gen_Code, gen_parse_preprocess_cond());
					break;

				case Tok_Preprocess_Else:
					member = gen_cast(gen_Code, gen_preprocess_else);
					eat(Tok_Preprocess_Else);
					break;

				case Tok_Preprocess_EndIf:
					member = gen_cast(gen_Code, gen_preprocess_endif);
					eat(Tok_Preprocess_EndIf);
					break;

				case Tok_Preprocess_Macro_Typename:
					// Its a variable with a macro typename
					member = gen_cast(gen_Code, gen_parser_parse_variable());
					break;

				case Tok_Preprocess_Macro_Stmt:
					member = gen_parse_simple_preprocess(Tok_Preprocess_Macro_Stmt);
					break;

				case Tok_Preprocess_Pragma:
					member = gen_cast(gen_Code, gen_parse_pragma());
					break;

				case Tok_Preprocess_Unsupported:
					member = gen_parse_simple_preprocess(Tok_Preprocess_Unsupported);
					break;

				default:
					member = gen_cast(gen_Code, gen_parser_parse_variable());
					break;
			}

			if (member)
				gen_body_append(body, member);
		}
		// <ModuleFlags> union <Attributes> <Name> { <Body>

		eat(Tok_BraceCurly_Close);
		// <ModuleFlags> union <Attributes> <Name> { <Body> }
	}

	if (! inplace_def)
		eat(Tok_Statement_End);
	// <ModuleFlags> union <Attributes> <Name> { <Body> };

	gen_CodeUnion result = (gen_CodeUnion)gen_make_code();
	result->Type         = body ? CT_Union : CT_Union_Fwd;
	result->ModuleFlags  = mflags;

	if (name.Len)
		result->Name = gen_cache_str(name);

	result->Body       = body;
	result->Attributes = attributes;

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_CodeUsing gen_parser_parse_using()
{
	push_scope();

	gen_Specifier specs_found[16]   = { Spec_Invalid };
	gen_s32       NumSpecifiers     = 0;

	gen_Token        name           = gen_NullToken;
	gen_Code         gen_array_expr = { gen_nullptr };
	gen_CodeTypename type           = { gen_nullptr };

	bool is_namespace               = false;

	gen_ModuleFlag     mflags       = ModuleFlag_None;
	gen_CodeAttributes attributes   = { gen_nullptr };

	if (check(Tok_Module_Export))
	{
		mflags = ModuleFlag_Export;
		eat(Tok_Module_Export);
	}
	// <ModuleFlags>

	eat(Tok_Decl_Using);
	// <ModuleFlags> using

	if (currtok.Type == Tok_Decl_Namespace)
	{
		is_namespace = true;
		eat(Tok_Decl_Namespace);
		// <ModuleFlags> using namespace
	}

	name                         = currtok;
	gen__ctx->parser.Scope->Name = name.Text;
	eat(Tok_Identifier);
	// <ModuleFlags> using <namespace> <Name>

	if (! is_namespace)
	{
		attributes = gen_parse_attributes();
		// <ModuleFlags> using <Name> <Attributes>

		if (gen_bitfield_is_set(gen_u32, currtok.Flags, TF_Assign))
		{
			attributes = gen_parse_attributes();
			// <ModuleFlags> using <Name> <Attributes>

			eat(Tok_Operator);
			// <ModuleFlags> using <Name> <Attributes> =

			type = gen_parser_parse_type(gen_parser_not_from_template, gen_nullptr);
			// <ModuleFlags> using <Name> <Attributes> = <UnderlyingType>

			gen_array_expr = gen_parse_array_decl();
			// <UnderlyingType> + <ArrExpr>
		}
	}

	gen_Token stmt_end = currtok;
	eat(Tok_Statement_End);
	// <ModuleFlags> using <namespace> <Attributes> <Name> = <UnderlyingType>;

	gen_CodeComment inline_cmt = gen_NullCode;
	if (currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line)
	{
		inline_cmt = gen_parse_comment();
	}
	// <ModuleFlags> using <namespace> <Attributes> <Name> = <UnderlyingType>; <InlineCmt>

	gen_CodeUsing result = (gen_CodeUsing)gen_make_code();
	result->Name         = gen_cache_str(name.Text);
	result->ModuleFlags  = mflags;

	if (is_namespace)
	{
		result->Type = CT_Using_Namespace;
	}
	else
	{
		result->Type = CT_Using;

		if (type)
			result->UnderlyingType = type;

		if (gen_array_expr)
			type->ArrExpr = gen_array_expr;

		if (attributes)
			result->Attributes = attributes;

		if (inline_cmt)
			result->InlineCmt = inline_cmt;
	}

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_CodeVar gen_parser_parse_variable()
{
	push_scope();

	gen_Specifier specs_found[16] = { Spec_NumSpecifiers };
	gen_s32       NumSpecifiers   = 0;

	gen_ModuleFlag     mflags     = ModuleFlag_None;
	gen_CodeAttributes attributes = { gen_nullptr };
	gen_CodeSpecifiers specifiers = { gen_nullptr };

	if (check(Tok_Module_Export))
	{
		mflags = ModuleFlag_Export;
		eat(Tok_Module_Export);
	}
	// <ModuleFlags>

	attributes = gen_parse_attributes();
	// <ModuleFlags> <Attributes>

	while (left && gen_tok_is_specifier(currtok))
	{
		gen_Specifier spec = gen_str_to_specifier(currtok.Text);
		switch (spec)
		{
		GEN_PARSER_VARIABLE_ALLOWED_SPECIFIER_CASES:
			break;

			default:
				gen_log_failure(
				    "Invalid specifier %S for variable\n%S",
				    gen_spec_to_str(spec),
				    gen_strbuilder_to_str(gen_parser_to_strbuilder(gen__ctx->parser))
				);
				gen_parser_pop(&gen__ctx->parser);
				return gen_InvalidCode;
		}

		// Ignore const specifiers, they're handled by the type
		if (spec == Spec_Const)
			break;

		specs_found[NumSpecifiers] = spec;
		NumSpecifiers++;
		eat(currtok.Type);
	}

	if (NumSpecifiers)
	{
		specifiers = gen_def_specifiers_arr(NumSpecifiers, specs_found);
	}
	// <ModuleFlags> <Attributes> <Specifiers>

	gen_CodeTypename type = gen_parser_parse_type(gen_parser_not_from_template, gen_nullptr);
	// <ModuleFlags> <Attributes> <Specifiers> <ValueType>

	if (gen_cast(gen_Code, type) == gen_Code_Invalid)
		return gen_InvalidCode;

	gen__ctx->parser.Scope->Name = gen_parse_identifier(gen_nullptr).Text;
	// <ModuleFlags> <Attributes> <Specifiers> <ValueType> <Name>

	gen_CodeVar result = gen_parse_variable_after_name(mflags, attributes, specifiers, type, gen__ctx->parser.Scope->Name);
	// Regular  : <ModuleFlags> <Attributes> <Specifiers> <ValueType> <Name>                  = <Value>; <InlineCmt>
	// Bitfield : <ModuleFlags> <Attributes> <Specifiers> <ValueType> <Name> : <BitfieldSize> = <Value>; <InlineCmt>

	gen_parser_pop(&gen__ctx->parser);
	return result;
}

gen_internal gen_CodeTypename gen_parser_parse_type_alt(bool from_template, bool* gen_typedef_is_functon)
{
	return gen_InvalidCode;
}

#ifdef CHECK_WAS_DEFINED

#pragma pop_macro("check")

#endif

// Publically Exposed Interface

gen_CodeClass gen_parse_class( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	push_scope();
	gen_CodeClass result = (gen_CodeClass) gen_parse_class_struct( Tok_Decl_Class, gen_parser_not_inplace_def );
	gen_parser_pop(& gen__ctx->parser);
	return result;
}

gen_CodeConstructor gen_parse_constructor( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	// TODO(Ed): Constructors can have prefix attributes

	gen_CodeSpecifiers specifiers = gen_NullCode;
	gen_Specifier      specs_found[ 16 ] = { Spec_NumSpecifiers };
	gen_s32            NumSpecifiers = 0;

	while ( left && gen_tok_is_specifier(currtok) )
	{
		gen_Specifier spec = gen_str_to_specifier( currtok.Text );

		gen_b32 ignore_spec = false;

		switch ( spec )
		{
			case Spec_Constexpr :
			case Spec_Explicit:
			case Spec_Inline :
			case Spec_ForceInline :
			case Spec_NeverInline :
				break;

			case Spec_Const :
				ignore_spec = true;
				break;

			default :
				gen_log_failure( "Invalid specifier %s for variable\n%S", gen_spec_to_str( spec ), gen_parser_to_strbuilder(gen__ctx->parser) );
				gen_parser_pop(& gen__ctx->parser);
				return gen_InvalidCode;
		}

		// Every specifier after would be considered part of the type type signature
		if (ignore_spec)
			break;

		specs_found[ NumSpecifiers ] = spec;
		NumSpecifiers++;
		eat( currtok.Type );
	}

	if ( NumSpecifiers )
	{
		specifiers = gen_def_specifiers_arr( NumSpecifiers, specs_found );
		// <specifiers> ...
	}

	gen__ctx->parser.Tokens         = toks;
	gen_CodeConstructor result = gen_parser_parse_constructor( specifiers );
	return result;
}

gen_CodeDefine gen_parse_define( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	push_scope();
	gen_CodeDefine result = gen_parser_parse_define();
	gen_parser_pop(& gen__ctx->parser);
	return result;
}

gen_CodeDestructor gen_parse_destructor( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	// TODO(Ed): Destructors can have prefix attributes
	// TODO(Ed): Destructors can have virtual

	gen__ctx->parser.Tokens        = toks;
	gen_CodeDestructor result = gen_parser_parse_destructor(gen_NullCode);
	return result;
}

gen_CodeEnum gen_parse_enum( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
	{
		gen_parser_pop(& gen__ctx->parser);
		return gen_InvalidCode;
	}

	gen__ctx->parser.Tokens = toks;
	return gen_parser_parse_enum( gen_parser_not_inplace_def);
}

gen_CodeBody gen_parse_export_body( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	return gen_parser_parse_export_body();
}

gen_CodeExtern gen_parse_extern_link( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	return gen_parser_parse_extern_link();
}

gen_CodeFriend gen_parse_friend( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	return gen_parser_parse_friend();
}

gen_CodeFn gen_parse_function( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	return (gen_CodeFn) gen_parser_parse_function();
}

gen_CodeBody gen_parse_global_body( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	push_scope();
	gen_CodeBody result = gen_parse_global_nspace( CT_Global_Body );
	gen_parser_pop(& gen__ctx->parser);
	return result;
}

gen_CodeNS gen_parse_namespace( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	return gen_parser_parse_namespace();
}

gen_CodeOperator gen_parse_operator( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	return (gen_CodeOperator) gen_parser_parse_operator();
}

gen_CodeOpCast gen_parse_operator_cast( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	return gen_parser_parse_operator_cast(gen_NullCode);
}

gen_CodeStruct gen_parse_struct( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	push_scope();
	gen_CodeStruct result = (gen_CodeStruct) gen_parse_class_struct( Tok_Decl_Struct, gen_parser_not_inplace_def );
	gen_parser_pop(& gen__ctx->parser);
	return result;
}

gen_CodeTemplate gen_parse_template( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	return gen_parser_parse_template();
}

gen_CodeTypename gen_parse_type( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	return gen_parser_parse_type( gen_parser_not_from_template, gen_nullptr);
}

gen_CodeTypedef gen_parse_typedef( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	return gen_parser_parse_typedef();
}

gen_CodeUnion gen_parse_union( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	return gen_parser_parse_union( gen_parser_not_inplace_def);
}

gen_CodeUsing gen_parse_using( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	return gen_parser_parse_using();
}

gen_CodeVar gen_parse_variable( gen_Str def )
{
	check_parse_args( def );

	gen_TokArray toks = gen_lex( def );
	if ( toks.Arr == gen_nullptr )
		return gen_InvalidCode;

	gen__ctx->parser.Tokens = toks;
	return gen_parser_parse_variable();
}

// Undef helper macros
#undef check_parse_args
#undef currtok_noskip
#undef currtok
#undef peektok
#undef prevtok
#undef nexttok
#undef nexttok_noskip
#undef eat
#undef left
#undef check
#undef push_scope
#undef gen_def_assign

// Here for C Variant
#undef gen_lex_dont_skip_formatting
#undef gen_lex_skip_formatting

#undef gen_parser_inplace_def
#undef gen_parser_not_inplace_def
#undef gen_parser_dont_consume_braces
#undef gen_parser_consume_braces
#undef gen_parser_not_from_template
#undef gen_parser_use_parenthesis
#undef gen_parser_strip_formatting_dont_preserve_newlines

#pragma endregion Parsing

gen_ssize gen_token_fmt_va( char* buf, gen_usize buf_size, gen_s32 num_tokens, va_list va )
{
	char const* buf_begin = buf;
	gen_ssize       remaining = buf_size;

	if (gen__ctx->gen_token_fmt_map.Hashes == gen_nullptr) {
		gen__ctx->gen_token_fmt_map = gen_hashtable_init(gen_Str, gen__ctx->Allocator_DyanmicContainers );
	}
	// Populate token pairs
	{
		gen_s32 left = num_tokens - 1;

		while ( left-- )
		{
			char const* token = va_arg( va, char const* );
			gen_Str         value = va_arg( va, gen_Str );

			gen_u32 key = gen_crc32( token, gen_c_str_len(token) );
			gen_hashtable_set( gen__ctx->gen_token_fmt_map, key, value );
		}
	}

	char const* fmt     = va_arg( va, char const* );
	char        current = *fmt;

	while ( current )
	{
		gen_ssize len = 0;

		while ( current && current != '<' && remaining )
		{
			* buf = * fmt;
			buf++;
			fmt++;
			remaining--;

			current = * fmt;
		}

		if ( current == '<' )
		{
			char const* scanner = fmt + 1;

			gen_s32 gen_tok_len = 0;

			while ( *scanner != '>' )
			{
				gen_tok_len++;
				scanner++;
			}

			char const* token = fmt + 1;

			gen_u32      key   = gen_crc32( token, gen_tok_len );
			gen_Str*     value = gen_hashtable_get(gen__ctx->gen_token_fmt_map, key );

			if ( value )
			{
				gen_ssize          left = value->Len;
				char const* str  = value->Ptr;

				while ( left-- )
				{
					* buf = * str;
					buf++;
					str++;
					remaining--;
				}

				scanner++;
				fmt     = scanner;
				current = * fmt;
				continue;
			}

			* buf = * fmt;
			buf++;
			fmt++;
			remaining--;

			current = * fmt;
		}
	}
	gen_hashtable_clear(gen__ctx->gen_token_fmt_map);
	gen_ssize result = buf_size - remaining;
	return result;
}

gen_Code gen_untyped_str( gen_Str content )
{
	if ( content.Len == 0 )
	{
		gen_log_failure( "gen_untyped_str: empty string" );
		return gen_InvalidCode;
	}

	gen_Code
	result          = gen_make_code();
	result->Name    = gen_cache_str( content );
	result->Type    = CT_Untyped;
	result->Content = result->Name;

	if ( result->Name.Len == 0 )
	{
		gen_log_failure( "gen_untyped_str: could not cache string" );
		return gen_InvalidCode;
	}

	return result;
}

gen_Code gen_untyped_fmt( char const* fmt, ...)
{
	if ( fmt == gen_nullptr )
	{
		gen_log_failure( "gen_untyped_fmt: null format string" );
		return gen_InvalidCode;
	}

	gen_local_persist gen_thread_local
	char buf[GEN_PRINTF_MAXLEN] = { 0 };

	va_list va;
	va_start(va, fmt);
	gen_ssize length = gen_c_str_fmt_va(buf, GEN_PRINTF_MAXLEN, fmt, va);
	va_end(va);
    gen_Str content = { buf, length };

	gen_Code
	result          = gen_make_code();
	result->Type    = CT_Untyped;
	result->Content = gen_cache_str( content );

	if ( result->Name.Len == 0 )
	{
		gen_log_failure( "gen_untyped_fmt: could not cache string" );
		return gen_InvalidCode;
	}

	return result;
}

gen_Code gen_untyped_token_fmt( gen_s32 num_tokens, char const* fmt, ... )
{
	if ( num_tokens == 0 )
	{
		gen_log_failure( "gen_untyped_token_fmt: zero tokens" );
		return gen_InvalidCode;
	}

	gen_local_persist gen_thread_local
	char buf[GEN_PRINTF_MAXLEN] = { 0 };

	va_list va;
	va_start(va, fmt);
	gen_ssize length = gen_token_fmt_va(buf, GEN_PRINTF_MAXLEN, num_tokens, va);
	va_end(va);

	gen_Str buf_str = { buf, length };

	gen_Code
	result          = gen_make_code();
	result->Type    = CT_Untyped;
	result->Content = gen_cache_str( buf_str );

	if ( result->Name.Len == 0 )
	{
		gen_log_failure( "gen_untyped_fmt: could not cache string" );
		return gen_InvalidCode;
	}

	return result;
}

#pragma endregion Interface

#pragma region gen_Builder

gen_Builder gen_builder_open(char const* path)
{
	gen_Builder result;

	gen_FileError error = gen_file_open_mode(&result.File, EFileMode_WRITE, path);
	if (error != EFileError_NONE)
	{
		gen_log_failure("gen::File::open - Could not open file: %s", path);
		return result;
	}

	gen_Context* ctx = get_context();
	GEN_ASSERT_NOT_NULL(ctx);
	result.Buffer = gen_strbuilder_make_reserve(ctx->Allocator_Temp, ctx->InitSize_BuilderBuffer);

	// gen_log_fmt("$gen_Builder - Opened file: %s\n", result.File.filename );
	return result;
}

void gen_builder_pad_lines(gen_Builder* builder, gen_s32 num)
{
	gen_strbuilder_append_str(&builder->Buffer, txt("\n"));
}

void gen_builder__print(gen_Builder* builder, gen_Code code)
{
	gen_StrBuilder str = gen_code_to_strbuilder(code);
	// const gen_ssize len = str.length();
	// gen_log_fmt( "%s - print: %.*s\n", File.filename, len > 80 ? 80 : len, str.Data );
	gen_strbuilder_append_string(&builder->Buffer, str);
}

void gen_builder_print_fmt_va(gen_Builder* builder, char const* fmt, va_list va)
{
	gen_ssize res;
	char      buf[GEN_PRINTF_MAXLEN] = { 0 };

	res                              = gen_c_str_fmt_va(buf, gen_count_of(buf) - 1, fmt, va) - 1;

	gen_strbuilder_append_c_str_len((gen_StrBuilder*)&(builder->Buffer), (char const*)buf, res);
}

void gen_builder_write(gen_Builder* builder)
{
	gen_b32 result = gen_file_write(&builder->File, builder->Buffer, gen_strbuilder_length(builder->Buffer));

	if (result == false)
		gen_log_failure("gen::File::write - Failed to write to file: %s\n", gen_file_name(&builder->File));

	gen_log_fmt("Generated: %s\n", builder->File.filename);
	gen_file_close(&builder->File);
	gen_strbuilder_free(&builder->Buffer);
}

#pragma endregion gen_Builder

#pragma region Scanner

gen_Code gen_scan_file(char const* path)
{
	gen_FileInfo file;

	gen_FileError error = gen_file_open_mode(&file, EFileMode_READ, path);
	if (error != EFileError_NONE)
	{
		GEN_FATAL("gen_scan_file: Could not open: %s", path);
	}

	gen_ssize fsize = gen_file_size(&file);
	if (fsize <= 0)
	{
		GEN_FATAL("gen_scan_file: %s is empty", path);
	}

	gen_StrBuilder str = gen_strbuilder_make_reserve(get_context()->Allocator_Temp, fsize);
	gen_file_read(&file, str, fsize);
	gen_strbuilder_get_header(str)->Length = fsize;

	// Skip GEN_INTELLISENSE_DIRECTIVES preprocessor blocks
	// Its designed so that the directive should be the first thing in the file.
	// Anything that comes before it will also be omitted.
	{
#define current (*scanner)
#define matched 0
#define move_fwd() \
	do             \
	{              \
		++scanner; \
		--left;    \
	} while (0)
		const gen_Str directive_start      = txt("ifdef");
		const gen_Str directive_end        = txt("endif");
		const gen_Str gen_def_intellisense = txt("GEN_INTELLISENSE_DIRECTIVES");

		bool        found_directive        = false;
		char const* scanner                = (char const*)str;
		gen_s32     left                   = fsize;
		while (left)
		{
			// Processing directive.
			if (current == '#')
			{
				move_fwd();
				while (left && gen_char_is_space(current))
					move_fwd();

				if (! found_directive)
				{
					if (left && gen_c_str_compare_len(scanner, directive_start.Ptr, directive_start.Len) == matched)
					{
						scanner += directive_start.Len;
						left    -= directive_start.Len;

						while (left && gen_char_is_space(current))
							move_fwd();

						if (left && gen_c_str_compare_len(scanner, gen_def_intellisense.Ptr, gen_def_intellisense.Len) == matched)
						{
							scanner         += gen_def_intellisense.Len;
							left            -= gen_def_intellisense.Len;

							found_directive  = true;
						}
					}

					// Skip to end of line
					while (left && current != '\r' && current != '\n')
						move_fwd();
					move_fwd();

					if (left && current == '\n')
						move_fwd();

					continue;
				}

				if (left && gen_c_str_compare_len(scanner, directive_end.Ptr, directive_end.Len) == matched)
				{
					scanner += directive_end.Len;
					left    -= directive_end.Len;

					// Skip to end of line
					while (left && current != '\r' && current != '\n')
						move_fwd();
					move_fwd();

					if (left && current == '\n')
						move_fwd();

					// gen_sptr skip_size = fsize - left;
					if ((scanner + 2) >= ((char const*)str + fsize))
					{
						gen_mem_move(str, scanner, left);
						gen_strbuilder_get_header(str)->Length = left;
						break;
					}

					gen_mem_move(str, scanner, left);
					gen_strbuilder_get_header(str)->Length = left;

					break;
				}
			}

			move_fwd();
		}
#undef move_fwd
#undef matched
#undef current
	}

	gen_file_close(&file);
	return gen_untyped_str(gen_strbuilder_to_str(str));
}

gen_CodeBody gen_parse_file(const char* path)
{
	FileContents file    = gen_file_read_contents(get_context()->Allocator_Temp, true, path);
	gen_Str      content = { (char const*)file.data, file.size };
	gen_CodeBody code    = gen_parse_global_body(content);
	gen_log_fmt("\nParsed: %s\n", path);
	return code;
}

gen_CSV_Column gen_parse_csv_one_column(gen_AllocatorInfo allocator, char const* path)
{
	FileContents content       = gen_file_read_contents(allocator, gen_file_zero_terminate, path);
	gen_Arena    gen_csv_arena = gen_arena_init_from_memory(content.data, content.size);

	gen_CSV_Column result;
	gen_csv_parse(&result.ADT, gen_rcast(char*, content.data), allocator, false);
	result.Content = result.ADT.nodes[0].nodes;
	return result;
}

gen_CSV_Columns2 gen_parse_csv_two_columns(gen_AllocatorInfo allocator, char const* path)
{
	FileContents content       = gen_file_read_contents(allocator, gen_file_zero_terminate, path);
	gen_Arena    gen_csv_arena = gen_arena_init_from_memory(content.data, content.size);

	gen_CSV_Columns2 result;
	gen_csv_parse(&result.ADT, gen_rcast(char*, content.data), allocator, false);
	result.Col_1 = result.ADT.nodes[0].nodes;
	result.Col_2 = result.ADT.nodes[1].nodes;
	return result;
}

#pragma endregion Scanner

GEN_NS_END
