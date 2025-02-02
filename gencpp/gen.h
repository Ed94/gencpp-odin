// This file was generated automatially by gencpp's c_library.cpp  (See: https://github.com/Ed94/gencpp)

#pragma once

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
/*
	gencpp: An attempt at "simple" staged metaprogramming for c/c++.

	See Readme.md for more information from the project repository.

	Public Address:
	https://github.com/Ed94/gencpp  ---------------------------------------------------------------.
	|   _____                               _____ _                       _      ___   __     __    |
	|  / ____)                             / ____} |                     | |   / ,__} /  |   /  |   |
	| | / ___  ___ _ __   ___ _ __  _ __  | {___ | l_ __ _  __ _, ___  __| |  | |    '-l |  '-l |   |
	| | |{_  \/ __\ '_ \ / __} '_ l| '_ l  \___ \| __/ _` |/ _` |/ __\/ _` |  | |      | |    | |   |
	| | l__j | ___/ | | | {__; ;_l } ;_l } ____} | l| (_} | {_| | ___j {_; |  | l___  _J l_  _J l_  |
	|  \_____|\___}_l |_|\___} .__/| .__/ {_____/ \__\__/_l\__. |\___/\__,_l   \____}{_____}{_____} |
	|                        | |   | |                      __} |                                   |
	|                        l_l   l_l                     {___/                                    |
	! ----------------------------------------------------------------------- VERSION: v0.24-Alpha  |
	! ============================================================================================= |
	! WARNING: THIS IS AN ALPHA VERSION OF THE LIBRARY, USE AT YOUR OWN DISCRETION                  |
	! NEVER DO CODE GENERATION WITHOUT AT LEAST HAVING CONTENT IN A CODEBASE UNDER VERSION CONTROL  |
	! ============================================================================================= /
*/
#if ! defined(GEN_DONT_ENFORCE_GEN_TIME_GUARD) && ! defined(GEN_TIME)
#	error Gen.hpp : GEN_TIME not defined
#endif
#if ! defined(GEN_DONT_ENFORCE_GEN_TIME_GUARD) && ! defined(GEN_TIME)
#	error Gen.h : GEN_TIME not defined
#endif

//! If its desired to roll your own dependencies, define GEN_ROLL_OWN_DEPENDENCIES before including this file.
// Dependencies are derived from the c-zpl library: https://github.com/zpl-c/zpl
#ifndef GEN_ROLL_OWN_DEPENDENCIES
#	include "gen.dep.h"
#endif

GEN_NS_BEGIN
GEN_API_C_BEGIN

#pragma region Types

/*
 ________                                              __    __      ________
|        \                                            |  \  |  \    |        \
| ▓▓▓▓▓▓▓▓_______  __    __ ______ ____   _______     | ▓▓\ | ▓▓     \▓▓▓▓▓▓▓▓__    __  ______   ______   _______
| ▓▓__   |       \|  \  |  \      \    \ /       \    | ▓▓▓\| ▓▓       | ▓▓  |  \  |  \/      \ /      \ /       \
| ▓▓  \  | ▓▓▓▓▓▓▓\ ▓▓  | ▓▓ ▓▓▓▓▓▓\▓▓▓▓\  ▓▓▓▓▓▓▓    | ▓▓▓▓\ ▓▓       | ▓▓  | ▓▓  | ▓▓  ▓▓▓▓▓▓\  ▓▓▓▓▓▓\  ▓▓▓▓▓▓▓
| ▓▓▓▓▓  | ▓▓  | ▓▓ ▓▓  | ▓▓ ▓▓ | ▓▓ | ▓▓\▓▓    \     | ▓▓\▓▓ ▓▓       | ▓▓  | ▓▓  | ▓▓ ▓▓  | ▓▓ ▓▓    ▓▓\▓▓    \
| ▓▓_____| ▓▓  | ▓▓ ▓▓__/ ▓▓ ▓▓ | ▓▓ | ▓▓_\▓▓▓▓▓▓\    | ▓▓ \▓▓▓▓       | ▓▓  | ▓▓__/ ▓▓ ▓▓__/ ▓▓ ▓▓▓▓▓▓▓▓_\▓▓▓▓▓▓\
| ▓▓     \ ▓▓  | ▓▓\▓▓    ▓▓ ▓▓ | ▓▓ | ▓▓       ▓▓    | ▓▓  \▓▓▓       | ▓▓   \▓▓    ▓▓ ▓▓    ▓▓\▓▓     \       ▓▓
 \▓▓▓▓▓▓▓▓\▓▓   \▓▓ \▓▓▓▓▓▓ \▓▓  \▓▓  \▓▓\▓▓▓▓▓▓▓      \▓▓   \▓▓        \▓▓   _\▓▓▓▓▓▓▓ ▓▓▓▓▓▓▓  \▓▓▓▓▓▓▓\▓▓▓▓▓▓▓
                                                                             |  \__| ▓▓ ▓▓
                                                                              \▓▓    ▓▓ ▓▓
                                                                               \▓▓▓▓▓▓ \▓▓

*/

typedef gen_ssize (*LogFailType)(char const*, ...);

// By default this library will either crash or exit if an error is detected while generating codes.
// Even if set to not use GEN_FATAL, GEN_FATAL will still be used for memory failures as the library is unusable when they occur.
#ifdef GEN_DONT_USE_FATAL

#define gen_log_failure gen_log_fmt
#else
#define gen_log_failure GEN_FATAL
#endif

enum gen_AccessSpec gen_enum_underlying(gen_u32)
{
	AccessSpec_Default,
	AccessSpec_Private,
	AccessSpec_Protected,
	AccessSpec_Public,
	AccessSpec_Num_AccessSpec,
	AccessSpec_Invalid,
	AccessSpec_SizeDef = GEN_U32_MAX,
};

typedef gen_u32 gen_AccessSpec;
gen_static_assert(gen_size_of(gen_AccessSpec) == gen_size_of(gen_u32), "gen_AccessSpec not gen_u32 size");

inline gen_Str gen_access_spec_to_str(gen_AccessSpec type)
{
	gen_local_persist gen_Str lookup[(gen_u32)AccessSpec_Num_AccessSpec] = {
		{ "",        sizeof("") - 1          },
		{ "private", sizeof("prviate") - 1   },
		{ "private", sizeof("protected") - 1 },
		{ "public",  sizeof("public") - 1    },
	};

	gen_Str invalid = { "Invalid", sizeof("Invalid") - 1 };
	if (type > AccessSpec_Public)
		return invalid;

	return lookup[(gen_u32)type];
}

enum gen_CodeFlag gen_enum_underlying(gen_u32)
{
	CodeFlag_None          = 0,
	CodeFlag_FunctionType  = gen_bit(0),
	CodeFlag_ParamPack     = gen_bit(1),
	CodeFlag_Module_Export = gen_bit(2),
	CodeFlag_Module_Import = gen_bit(3),
	CodeFlag_SizeDef       = GEN_U32_MAX,
};

typedef gen_u32 gen_CodeFlag;
gen_static_assert(gen_size_of(gen_CodeFlag) == gen_size_of(gen_u32), "gen_CodeFlag not gen_u32 size");

// Used to indicate if enum definitoin is an enum class or regular enum.
enum gen_EnumDecl gen_enum_underlying(gen_u8)
{
	EnumDecl_Regular,
	EnumDecl_Class,
	EnumT_SizeDef = GEN_U8_MAX,
};

typedef gen_u8 gen_EnumDecl;
typedef gen_u8 EnumT;

enum gen_ModuleFlag gen_enum_underlying(gen_u32)
{
	ModuleFlag_None   = 0,
	ModuleFlag_Export = gen_bit(0),
	ModuleFlag_Import = gen_bit(1),
	Num_ModuleFlags,
	ModuleFlag_Invalid,
	ModuleFlag_SizeDef = GEN_U32_MAX,
};

typedef gen_u32 gen_ModuleFlag;
gen_static_assert(gen_size_of(gen_ModuleFlag) == gen_size_of(gen_u32), "gen_ModuleFlag not gen_u32 size");

inline gen_Str gen_module_flag_to_str(gen_ModuleFlag flag)
{
	gen_local_persist gen_Str lookup[(gen_u32)Num_ModuleFlags] = {
		{ "__none__", sizeof("__none__") - 1 },
		{ "export",   sizeof("export") - 1   },
		{ "import",   sizeof("import") - 1   },
	};

	gen_local_persist gen_Str invalid_flag = { "invalid", sizeof("invalid") };
	if (flag > ModuleFlag_Import)
		return invalid_flag;

	return lookup[(gen_u32)flag];
}

enum gen_EPreprocessCOnd gen_enum_underlying(gen_u32)
{
	PreprocessCond_If,
	PreprocessCond_IfDef,
	PreprocessCond_IfNotDef,
	PreprocessCond_ElIf,
	EPreprocessCond_SizeDef = GEN_U32_MAX,
};

typedef gen_u32 gen_EPreprocessCOnd;
gen_static_assert(gen_size_of(gen_EPreprocessCOnd) == gen_size_of(gen_u32), "gen_EPreprocessCOnd not gen_u32 size");

enum gen_ETypenameTag gen_enum_underlying(gen_u16)
{
	Tag_None,
	Tag_Class,
	Tag_Enum,
	Tag_Struct,
	Tag_Union,
	Tag_UnderlyingType = GEN_U16_MAX,
};

typedef gen_u16 gen_ETypenameTag;
gen_static_assert(gen_size_of(gen_ETypenameTag) == gen_size_of(gen_u16), "gen_ETypenameTag is not gen_u16 size");

enum gen_CodeType gen_enum_underlying(gen_u32)
{
	CT_Invalid,
	CT_Untyped,
	CT_NewLine,
	CT_Comment,
	CT_Access_Private,
	CT_Access_Protected,
	CT_Access_Public,
	CT_PlatformAttributes,
	CT_Class,
	CT_Class_Fwd,
	CT_Class_Body,
	CT_Constructor,
	CT_Constructor_Fwd,
	CT_Destructor,
	CT_Destructor_Fwd,
	CT_Enum,
	CT_Enum_Fwd,
	CT_Enum_Body,
	CT_Enum_Class,
	CT_Enum_Class_Fwd,
	CT_Execution,
	CT_Export_Body,
	CT_Extern_Linkage,
	CT_Extern_Linkage_Body,
	CT_Friend,
	CT_Function,
	CT_Function_Fwd,
	CT_Function_Body,
	CT_Global_Body,
	CT_Module,
	CT_Namespace,
	CT_Namespace_Body,
	CT_Operator,
	CT_Operator_Fwd,
	CT_Operator_Member,
	CT_Operator_Member_Fwd,
	CT_Operator_Cast,
	CT_Operator_Cast_Fwd,
	CT_Parameters,
	CT_Parameters_Define,
	CT_Preprocess_Define,
	CT_Preprocess_Include,
	CT_Preprocess_If,
	CT_Preprocess_IfDef,
	CT_Preprocess_IfNotDef,
	CT_Preprocess_ElIf,
	CT_Preprocess_Else,
	CT_Preprocess_EndIf,
	CT_Preprocess_Pragma,
	CT_Specifiers,
	CT_Struct,
	CT_Struct_Fwd,
	CT_Struct_Body,
	CT_Template,
	CT_Typedef,
	CT_Typename,
	CT_Union,
	CT_Union_Fwd,
	CT_Union_Body,
	CT_Using,
	CT_Using_Namespace,
	CT_Variable,
	CT_NumTypes,
	CT_UnderlyingType = GEN_U32_MAX
};
typedef enum gen_CodeType gen_CodeType;

inline gen_Str gen_codetype_to_str(gen_CodeType type)
{
	gen_local_persist gen_Str lookup[] = {
		{ "Invalid",             sizeof("Invalid") - 1             },
		{ "Untyped",             sizeof("Untyped") - 1             },
		{ "NewLine",             sizeof("NewLine") - 1             },
		{ "Comment",             sizeof("Comment") - 1             },
		{ "Access_Private",      sizeof("Access_Private") - 1      },
		{ "Access_Protected",    sizeof("Access_Protected") - 1    },
		{ "Access_Public",       sizeof("Access_Public") - 1       },
		{ "PlatformAttributes",  sizeof("PlatformAttributes") - 1  },
		{ "Class",               sizeof("Class") - 1               },
		{ "Class_Fwd",           sizeof("Class_Fwd") - 1           },
		{ "Class_Body",          sizeof("Class_Body") - 1          },
		{ "Constructor",         sizeof("Constructor") - 1         },
		{ "Constructor_Fwd",     sizeof("Constructor_Fwd") - 1     },
		{ "Destructor",          sizeof("Destructor") - 1          },
		{ "Destructor_Fwd",      sizeof("Destructor_Fwd") - 1      },
		{ "Enum",                sizeof("Enum") - 1                },
		{ "Enum_Fwd",            sizeof("Enum_Fwd") - 1            },
		{ "Enum_Body",           sizeof("Enum_Body") - 1           },
		{ "Enum_Class",          sizeof("Enum_Class") - 1          },
		{ "Enum_Class_Fwd",      sizeof("Enum_Class_Fwd") - 1      },
		{ "Execution",           sizeof("Execution") - 1           },
		{ "Export_Body",         sizeof("Export_Body") - 1         },
		{ "Extern_Linkage",      sizeof("Extern_Linkage") - 1      },
		{ "Extern_Linkage_Body", sizeof("Extern_Linkage_Body") - 1 },
		{ "Friend",              sizeof("Friend") - 1              },
		{ "Function",            sizeof("Function") - 1            },
		{ "Function_Fwd",        sizeof("Function_Fwd") - 1        },
		{ "Function_Body",       sizeof("Function_Body") - 1       },
		{ "Global_Body",         sizeof("Global_Body") - 1         },
		{ "Module",              sizeof("Module") - 1              },
		{ "Namespace",           sizeof("Namespace") - 1           },
		{ "Namespace_Body",      sizeof("Namespace_Body") - 1      },
		{ "gen_Operator",        sizeof("gen_Operator") - 1        },
		{ "Operator_Fwd",        sizeof("Operator_Fwd") - 1        },
		{ "Operator_Member",     sizeof("Operator_Member") - 1     },
		{ "Operator_Member_Fwd", sizeof("Operator_Member_Fwd") - 1 },
		{ "Operator_Cast",       sizeof("Operator_Cast") - 1       },
		{ "Operator_Cast_Fwd",   sizeof("Operator_Cast_Fwd") - 1   },
		{ "Parameters",          sizeof("Parameters") - 1          },
		{ "Parameters_Define",   sizeof("Parameters_Define") - 1   },
		{ "Preprocess_Define",   sizeof("Preprocess_Define") - 1   },
		{ "Preprocess_Include",  sizeof("Preprocess_Include") - 1  },
		{ "Preprocess_If",       sizeof("Preprocess_If") - 1       },
		{ "Preprocess_IfDef",    sizeof("Preprocess_IfDef") - 1    },
		{ "Preprocess_IfNotDef", sizeof("Preprocess_IfNotDef") - 1 },
		{ "Preprocess_ElIf",     sizeof("Preprocess_ElIf") - 1     },
		{ "Preprocess_Else",     sizeof("Preprocess_Else") - 1     },
		{ "Preprocess_EndIf",    sizeof("Preprocess_EndIf") - 1    },
		{ "Preprocess_Pragma",   sizeof("Preprocess_Pragma") - 1   },
		{ "Specifiers",          sizeof("Specifiers") - 1          },
		{ "Struct",              sizeof("Struct") - 1              },
		{ "Struct_Fwd",          sizeof("Struct_Fwd") - 1          },
		{ "Struct_Body",         sizeof("Struct_Body") - 1         },
		{ "Template",            sizeof("Template") - 1            },
		{ "Typedef",             sizeof("Typedef") - 1             },
		{ "Typename",            sizeof("Typename") - 1            },
		{ "Union",               sizeof("Union") - 1               },
		{ "Union_Fwd",           sizeof("Union_Fwd") - 1           },
		{ "Union_Body",          sizeof("Union_Body") - 1          },
		{ "Using",               sizeof("Using") - 1               },
		{ "Using_Namespace",     sizeof("Using_Namespace") - 1     },
		{ "Variable",            sizeof("Variable") - 1            },
	};
	return lookup[type];
}

inline gen_Str gen_codetype_to_keyword_str(gen_CodeType type)
{
	gen_local_persist gen_Str lookup[] = {
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "//",              sizeof("//") - 1              },
		{ "private",         sizeof("private") - 1         },
		{ "protected",       sizeof("protected") - 1       },
		{ "public",          sizeof("public") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "class",           sizeof("class") - 1           },
		{ "clsss",           sizeof("clsss") - 1           },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "enum",            sizeof("enum") - 1            },
		{ "enum",            sizeof("enum") - 1            },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "enum class",      sizeof("enum class") - 1      },
		{ "enum class",      sizeof("enum class") - 1      },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "extern",          sizeof("extern") - 1          },
		{ "extern",          sizeof("extern") - 1          },
		{ "friend",          sizeof("friend") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "module",          sizeof("module") - 1          },
		{ "namespace",       sizeof("namespace") - 1       },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "operator",        sizeof("operator") - 1        },
		{ "operator",        sizeof("operator") - 1        },
		{ "operator",        sizeof("operator") - 1        },
		{ "operator",        sizeof("operator") - 1        },
		{ "operator",        sizeof("operator") - 1        },
		{ "operator",        sizeof("operator") - 1        },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "define",          sizeof("define") - 1          },
		{ "include",         sizeof("include") - 1         },
		{ "if",              sizeof("if") - 1              },
		{ "ifdef",           sizeof("ifdef") - 1           },
		{ "ifndef",          sizeof("ifndef") - 1          },
		{ "elif",            sizeof("elif") - 1            },
		{ "else",            sizeof("else") - 1            },
		{ "endif",           sizeof("endif") - 1           },
		{ "pragma",          sizeof("pragma") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "struct",          sizeof("struct") - 1          },
		{ "struct",          sizeof("struct") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "template",        sizeof("template") - 1        },
		{ "typedef",         sizeof("typedef") - 1         },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "union",           sizeof("union") - 1           },
		{ "union",           sizeof("union") - 1           },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "using",           sizeof("using") - 1           },
		{ "using namespace", sizeof("using namespace") - 1 },
		{ "__NA__",          sizeof("__NA__") - 1          },
	};
	return lookup[type];
}

enum gen_Operator gen_enum_underlying(gen_u32)
{
	Op_Invalid,
	Op_Assign,
	Op_Assign_Add,
	Op_Assign_Subtract,
	Op_Assign_Multiply,
	Op_Assign_Divide,
	Op_Assign_Modulo,
	Op_Assign_BAnd,
	Op_Assign_BOr,
	Op_Assign_BXOr,
	Op_Assign_LShift,
	Op_Assign_RShift,
	Op_Increment,
	Op_Decrement,
	Op_Unary_Plus,
	Op_Unary_Minus,
	Op_UnaryNot,
	Op_Add,
	Op_Subtract,
	Op_Multiply,
	Op_Divide,
	Op_Modulo,
	Op_BNot,
	Op_BAnd,
	Op_BOr,
	Op_BXOr,
	Op_LShift,
	Op_RShift,
	Op_LAnd,
	Op_LOr,
	Op_LEqual,
	Op_LNot,
	Op_Lesser,
	Op_Greater,
	Op_LesserEqual,
	Op_GreaterEqual,
	Op_Subscript,
	Op_Indirection,
	Op_AddressOf,
	Op_MemberOfPointer,
	Op_PtrToMemOfPtr,
	Op_FunctionCall,
	Op_Comma,
	Op_New,
	Op_NewArray,
	Op_Delete,
	Op_DeleteArray,
	Op_NumOps,
	Op_UnderlyingType = 0xffffffffu
};
typedef enum gen_Operator gen_Operator;

inline gen_Str gen_operator_to_str(gen_Operator op)
{
	gen_local_persist gen_Str lookup[] = {
		{ "INVALID",  sizeof("INVALID") - 1  },
		{ "=",        sizeof("=") - 1        },
		{ "+=",       sizeof("+=") - 1       },
		{ "-=",       sizeof("-=") - 1       },
		{ "*=",       sizeof("*=") - 1       },
		{ "/=",       sizeof("/=") - 1       },
		{ "%=",       sizeof("%=") - 1       },
		{ "&=",       sizeof("&=") - 1       },
		{ "|=",       sizeof("|=") - 1       },
		{ "^=",       sizeof("^=") - 1       },
		{ "<<=",      sizeof("<<=") - 1      },
		{ ">>=",      sizeof(">>=") - 1      },
		{ "++",       sizeof("++") - 1       },
		{ "--",       sizeof("--") - 1       },
		{ "+",        sizeof("+") - 1        },
		{ "-",        sizeof("-") - 1        },
		{ "!",        sizeof("!") - 1        },
		{ "+",        sizeof("+") - 1        },
		{ "-",        sizeof("-") - 1        },
		{ "*",        sizeof("*") - 1        },
		{ "/",        sizeof("/") - 1        },
		{ "%",        sizeof("%") - 1        },
		{ "~",        sizeof("~") - 1        },
		{ "&",        sizeof("&") - 1        },
		{ "|",        sizeof("|") - 1        },
		{ "^",        sizeof("^") - 1        },
		{ "<<",       sizeof("<<") - 1       },
		{ ">>",       sizeof(">>") - 1       },
		{ "&&",       sizeof("&&") - 1       },
		{ "||",       sizeof("||") - 1       },
		{ "==",       sizeof("==") - 1       },
		{ "!=",       sizeof("!=") - 1       },
		{ "<",        sizeof("<") - 1        },
		{ ">",        sizeof(">") - 1        },
		{ "<=",       sizeof("<=") - 1       },
		{ ">=",       sizeof(">=") - 1       },
		{ "[]",       sizeof("[]") - 1       },
		{ "*",        sizeof("*") - 1        },
		{ "&",        sizeof("&") - 1        },
		{ "->",       sizeof("->") - 1       },
		{ "->*",      sizeof("->*") - 1      },
		{ "()",       sizeof("()") - 1       },
		{ ",",        sizeof(",") - 1        },
		{ "new",      sizeof("new") - 1      },
		{ "new[]",    sizeof("new[]") - 1    },
		{ "delete",   sizeof("delete") - 1   },
		{ "delete[]", sizeof("delete[]") - 1 },
	};
	return lookup[op];
}

enum gen_Specifier gen_enum_underlying(gen_u32)
{
	Spec_Invalid,
	Spec_Consteval,
	Spec_Constexpr,
	Spec_Constinit,
	Spec_Explicit,
	Spec_External_Linkage,
	Spec_ForceInline,
	Spec_Global,
	Spec_Inline,
	Spec_Internal_Linkage,
	Spec_Local_Persist,
	Spec_Mutable,
	Spec_NeverInline,
	Spec_Ptr,
	Spec_Ref,
	Spec_Register,
	Spec_Restrict,
	Spec_RValue,
	Spec_Static,
	Spec_Thread_Local,
	Spec_Virtual,
	Spec_Const,
	Spec_Final,
	Spec_NoExceptions,
	Spec_Override,
	Spec_Pure,
	Spec_Delete,
	Spec_Volatile,
	Spec_NumSpecifiers,
	Spec_UnderlyingType = 0xffffffffu
};
typedef enum gen_Specifier gen_Specifier;

inline gen_Str gen_spec_to_str(gen_Specifier type)
{
	gen_local_persist gen_Str lookup[] = {
		{ "INVALID",           sizeof("INVALID") - 1           },
		{ "consteval",         sizeof("consteval") - 1         },
		{ "constexpr",         sizeof("constexpr") - 1         },
		{ "constinit",         sizeof("constinit") - 1         },
		{ "explicit",          sizeof("explicit") - 1          },
		{ "extern",            sizeof("extern") - 1            },
		{ "gen_forceinline",   sizeof("gen_forceinline") - 1   },
		{ "gen_global",        sizeof("gen_global") - 1        },
		{ "inline",            sizeof("inline") - 1            },
		{ "gen_internal",      sizeof("gen_internal") - 1      },
		{ "gen_local_persist", sizeof("gen_local_persist") - 1 },
		{ "mutable",           sizeof("mutable") - 1           },
		{ "gen_neverinline",   sizeof("gen_neverinline") - 1   },
		{ "*",		         sizeof("*") - 1                 },
		{ "&",		         sizeof("&") - 1                 },
		{ "register",          sizeof("register") - 1          },
		{ "restrict",          sizeof("restrict") - 1          },
		{ "&&",		        sizeof("&&") - 1                },
		{ "static",            sizeof("static") - 1            },
		{ "gen_thread_local",  sizeof("gen_thread_local") - 1  },
		{ "virtual",           sizeof("virtual") - 1           },
		{ "const",             sizeof("const") - 1             },
		{ "final",             sizeof("final") - 1             },
		{ "noexcept",          sizeof("noexcept") - 1          },
		{ "override",          sizeof("override") - 1          },
		{ "= 0",               sizeof("= 0") - 1               },
		{ "= delete",          sizeof("= delete") - 1          },
		{ "volatile",          sizeof("volatile") - 1          },
	};
	return lookup[type];
}

inline bool gen_spec_is_trailing(gen_Specifier specifier)
{
	switch (specifier)
	{
		case Spec_Const:
		case Spec_Final:
		case Spec_NoExceptions:
		case Spec_Override:
		case Spec_Pure:
		case Spec_Delete:
		case Spec_Volatile:
			return true;
		default:
			return false;
	}
}

inline gen_Specifier gen_str_to_specifier(gen_Str str)
{
	gen_local_persist gen_u32 keymap[Spec_NumSpecifiers];
	gen_do_once_start for (gen_u32 index = 0; index < Spec_NumSpecifiers; index++)
	{
		gen_Str gen_enum_str = gen_spec_to_str((gen_Specifier)index);
		keymap[index]        = gen_crc32(gen_enum_str.Ptr, gen_enum_str.Len);
	}
	gen_do_once_end gen_u32 gen_hash = gen_crc32(str.Ptr, str.Len);
	for (gen_u32 index = 0; index < Spec_NumSpecifiers; index++)
	{
		if (keymap[index] == gen_hash)
			return (gen_Specifier)index;
	}
	return Spec_Invalid;
}
#define GEN_DEFINE_ATTRIBUTE_TOKENS Entry(Tok_Attribute_GEN_API, "GEN_API")

enum gen_TokType
{
	Tok_Invalid,
	Tok_Access_Private,
	Tok_Access_Protected,
	Tok_Access_Public,
	Tok_Access_MemberSymbol,
	Tok_Access_StaticSymbol,
	Tok_Ampersand,
	Tok_Ampersand_DBL,
	Tok_Assign_Classifer,
	Tok_Attribute_Open,
	Tok_Attribute_Close,
	Tok_BraceCurly_Open,
	Tok_BraceCurly_Close,
	Tok_BraceSquare_Open,
	Tok_BraceSquare_Close,
	Tok_Paren_Open,
	Tok_Paren_Close,
	Tok_Comment,
	Tok_Comment_End,
	Tok_Comment_Start,
	Tok_Char,
	Tok_Comma,
	Tok_Decl_Class,
	Tok_Decl_GNU_Attribute,
	Tok_Decl_MSVC_Attribute,
	Tok_Decl_Enum,
	Tok_Decl_Extern_Linkage,
	Tok_Decl_Friend,
	Tok_Decl_Module,
	Tok_Decl_Namespace,
	Tok_Decl_Operator,
	Tok_Decl_Struct,
	Tok_Decl_Template,
	Tok_Decl_Typedef,
	Tok_Decl_Using,
	Tok_Decl_Union,
	Tok_Identifier,
	Tok_Module_Import,
	Tok_Module_Export,
	Tok_NewLine,
	Tok_Number,
	Tok_Operator,
	Tok_Preprocess_Hash,
	Tok_Preprocess_Define,
	Tok_Preprocess_Define_Param,
	Tok_Preprocess_If,
	Tok_Preprocess_IfDef,
	Tok_Preprocess_IfNotDef,
	Tok_Preprocess_ElIf,
	Tok_Preprocess_Else,
	Tok_Preprocess_EndIf,
	Tok_Preprocess_Include,
	Tok_Preprocess_Pragma,
	Tok_Preprocess_Content,
	Tok_Preprocess_Macro_Expr,
	Tok_Preprocess_Macro_Stmt,
	Tok_Preprocess_Macro_Typename,
	Tok_Preprocess_Unsupported,
	Tok_Spec_Alignas,
	Tok_Spec_Const,
	Tok_Spec_Consteval,
	Tok_Spec_Constexpr,
	Tok_Spec_Constinit,
	Tok_Spec_Explicit,
	Tok_Spec_Extern,
	Tok_Spec_Final,
	Tok_Spec_ForceInline,
	Tok_Spec_Global,
	Tok_Spec_Inline,
	Tok_Spec_Internal_Linkage,
	Tok_Spec_LocalPersist,
	Tok_Spec_Mutable,
	Tok_Spec_NeverInline,
	Tok_Spec_Override,
	Tok_Spec_Restrict,
	Tok_Spec_Static,
	Tok_Spec_ThreadLocal,
	Tok_Spec_Volatile,
	Tok_Spec_Virtual,
	Tok_Star,
	Tok_Statement_End,
	Tok_StaticAssert,
	Tok_String,
	Tok_Type_Typename,
	Tok_Type_Unsigned,
	Tok_Type_Signed,
	Tok_Type_Short,
	Tok_Type_Long,
	Tok_Type_bool,
	Tok_Type_char,
	Tok_Type_int,
	Tok_Type_double,
	Tok_Type_MS_int8,
	Tok_Type_MS_int16,
	Tok_Type_MS_int32,
	Tok_Type_MS_int64,
	Tok_Type_MS_W64,
	Tok_Varadic_Argument,
	Tok___Attributes_Start,
	Tok_Attribute_GEN_API,
	Tok_NumTokens,
	Tok_UnderlyingType = 0xffffffffu
};
typedef enum gen_TokType gen_TokType;

inline gen_Str gen_toktype_to_str(gen_TokType type)
{
	gen_local_persist gen_Str lookup[] = {
		{ "__invalid__",          sizeof("__invalid__") - 1          },
		{ "private",              sizeof("private") - 1              },
		{ "protected",            sizeof("protected") - 1            },
		{ "public",               sizeof("public") - 1               },
		{ ".",		            sizeof(".") - 1                    },
		{ "::",		           sizeof("::") - 1                   },
		{ "&",		            sizeof("&") - 1                    },
		{ "&&",		           sizeof("&&") - 1                   },
		{ ":",		            sizeof(":") - 1                    },
		{ "[[",		           sizeof("[[") - 1                   },
		{ "]]",		           sizeof("]]") - 1                   },
		{ "{",		            sizeof("{") - 1                    },
		{ "}",		            sizeof("}") - 1                    },
		{ "[",		            sizeof("[") - 1                    },
		{ "]",		            sizeof("]") - 1                    },
		{ "(",		            sizeof("(") - 1                    },
		{ ")",		            sizeof(")") - 1                    },
		{ "__comment__",          sizeof("__comment__") - 1          },
		{ "__comment_end__",      sizeof("__comment_end__") - 1      },
		{ "__comment_start__",    sizeof("__comment_start__") - 1    },
		{ "__character__",        sizeof("__character__") - 1        },
		{ ",",		            sizeof(",") - 1                    },
		{ "class",                sizeof("class") - 1                },
		{ "__attribute__",        sizeof("__attribute__") - 1        },
		{ "__declspec",           sizeof("__declspec") - 1           },
		{ "enum",                 sizeof("enum") - 1                 },
		{ "extern",               sizeof("extern") - 1               },
		{ "friend",               sizeof("friend") - 1               },
		{ "module",               sizeof("module") - 1               },
		{ "namespace",            sizeof("namespace") - 1            },
		{ "operator",             sizeof("operator") - 1             },
		{ "struct",               sizeof("struct") - 1               },
		{ "template",             sizeof("template") - 1             },
		{ "typedef",              sizeof("typedef") - 1              },
		{ "using",                sizeof("using") - 1                },
		{ "union",                sizeof("union") - 1                },
		{ "__identifier__",       sizeof("__identifier__") - 1       },
		{ "import",               sizeof("import") - 1               },
		{ "export",               sizeof("export") - 1               },
		{ "__new_line__",         sizeof("__new_line__") - 1         },
		{ "__number__",           sizeof("__number__") - 1           },
		{ "__operator__",         sizeof("__operator__") - 1         },
		{ "#",		            sizeof("#") - 1                    },
		{ "define",               sizeof("define") - 1               },
		{ "__define_param__",     sizeof("__define_param__") - 1     },
		{ "if",		           sizeof("if") - 1                   },
		{ "ifdef",                sizeof("ifdef") - 1                },
		{ "ifndef",               sizeof("ifndef") - 1               },
		{ "elif",                 sizeof("elif") - 1                 },
		{ "else",                 sizeof("else") - 1                 },
		{ "endif",                sizeof("endif") - 1                },
		{ "include",              sizeof("include") - 1              },
		{ "pragma",               sizeof("pragma") - 1               },
		{ "__macro_content__",    sizeof("__macro_content__") - 1    },
		{ "__macro_expression__", sizeof("__macro_expression__") - 1 },
		{ "__macro_statment__",   sizeof("__macro_statment__") - 1   },
		{ "__macro_typename__",   sizeof("__macro_typename__") - 1   },
		{ "__unsupported__",      sizeof("__unsupported__") - 1      },
		{ "alignas",              sizeof("alignas") - 1              },
		{ "const",                sizeof("const") - 1                },
		{ "consteval",            sizeof("consteval") - 1            },
		{ "constexpr",            sizeof("constexpr") - 1            },
		{ "constinit",            sizeof("constinit") - 1            },
		{ "explicit",             sizeof("explicit") - 1             },
		{ "extern",               sizeof("extern") - 1               },
		{ "final",                sizeof("final") - 1                },
		{ "gen_forceinline",      sizeof("gen_forceinline") - 1      },
		{ "gen_global",           sizeof("gen_global") - 1           },
		{ "inline",               sizeof("inline") - 1               },
		{ "gen_internal",         sizeof("gen_internal") - 1         },
		{ "gen_local_persist",    sizeof("gen_local_persist") - 1    },
		{ "mutable",              sizeof("mutable") - 1              },
		{ "gen_neverinline",      sizeof("gen_neverinline") - 1      },
		{ "override",             sizeof("override") - 1             },
		{ "restrict",             sizeof("restrict") - 1             },
		{ "static",               sizeof("static") - 1               },
		{ "gen_thread_local",     sizeof("gen_thread_local") - 1     },
		{ "volatile",             sizeof("volatile") - 1             },
		{ "virtual",              sizeof("virtual") - 1              },
		{ "*",		            sizeof("*") - 1                    },
		{ ";",		            sizeof(";") - 1                    },
		{ "gen_static_assert",    sizeof("gen_static_assert") - 1    },
		{ "__string__",           sizeof("__string__") - 1           },
		{ "typename",             sizeof("typename") - 1             },
		{ "unsigned",             sizeof("unsigned") - 1             },
		{ "signed",               sizeof("signed") - 1               },
		{ "short",                sizeof("short") - 1                },
		{ "long",                 sizeof("long") - 1                 },
		{ "bool",                 sizeof("bool") - 1                 },
		{ "char",                 sizeof("char") - 1                 },
		{ "int",		          sizeof("int") - 1                  },
		{ "double",               sizeof("double") - 1               },
		{ "__int8",               sizeof("__int8") - 1               },
		{ "__int16",              sizeof("__int16") - 1              },
		{ "__int32",              sizeof("__int32") - 1              },
		{ "__int64",              sizeof("__int64") - 1              },
		{ "_W64",                 sizeof("_W64") - 1                 },
		{ "...",		          sizeof("...") - 1                  },
		{ "__attrib_start__",     sizeof("__attrib_start__") - 1     },
		{ "GEN_API",              sizeof("GEN_API") - 1              },
	};
	return lookup[type];
}

inline gen_TokType gen_str_to_toktype(gen_Str str)
{
	gen_local_persist gen_u32 keymap[Tok_NumTokens];
	gen_do_once_start for (gen_u32 index = 0; index < Tok_NumTokens; index++)
	{
		gen_Str gen_enum_str = gen_toktype_to_str((gen_TokType)index);
		keymap[index]        = gen_crc32(gen_enum_str.Ptr, gen_enum_str.Len);
	}
	gen_do_once_end gen_u32 gen_hash = gen_crc32(str.Ptr, str.Len);
	for (gen_u32 index = 0; index < Tok_NumTokens; index++)
	{
		if (keymap[index] == gen_hash)
			return (gen_TokType)index;
	}
	return Tok_Invalid;
}

enum TokFlags gen_enum_underlying(gen_u32)
{
	TF_Operator           = gen_bit(0),
	TF_Assign             = gen_bit(1),
	TF_Preprocess         = gen_bit(2),
	TF_Preprocess_Cond    = gen_bit(3),
	TF_Attribute          = gen_bit(6),
	TF_AccessOperator     = gen_bit(7),
	TF_AccessSpecifier    = gen_bit(8),
	TF_Specifier          = gen_bit(9),
	TF_EndDefinition      = gen_bit(10),    // Either ; or }
	TF_Formatting         = gen_bit(11),
	TF_Literal            = gen_bit(12),
	TF_Macro_Functional   = gen_bit(13),
	TF_Macro_Expects_Body = gen_bit(14),
	TF_Null               = 0,
	TF_UnderlyingType     = GEN_U32_MAX,
};

typedef gen_u32 TokFlags;

struct gen_Token;
typedef struct gen_Token gen_Token;
typedef gen_Token*       gen_Array_gen_Token;

struct gen_Token
{
	gen_Str     Text;
	gen_TokType Type;
	gen_s32     Line;
	gen_s32     Column;
	gen_u32     Flags;
};

#pragma region gen_Array_gen_Token

#define GEN_GENERIC_SLOT_6__array_init            gen_Token, gen_Array_gen_Token_init
#define GEN_GENERIC_SLOT_6__array_init_reserve    gen_Token, gen_Array_gen_Token_init_reserve
#define GEN_GENERIC_SLOT_6__array_append          gen_Array_gen_Token, gen_Array_gen_Token_append
#define GEN_GENERIC_SLOT_6__array_append_items    gen_Array_gen_Token, gen_Array_gen_Token_append_items
#define GEN_GENERIC_SLOT_6__array_append_at       gen_Array_gen_Token, gen_Array_gen_Token_append_at
#define GEN_GENERIC_SLOT_6__array_append_items_at gen_Array_gen_Token, gen_Array_gen_Token_append_items_at
#define GEN_GENERIC_SLOT_6__array_back            gen_Array_gen_Token, gen_Array_gen_Token_back
#define GEN_GENERIC_SLOT_6__array_clear           gen_Array_gen_Token, gen_Array_gen_Token_clear
#define GEN_GENERIC_SLOT_6__array_fill            gen_Array_gen_Token, gen_Array_gen_Token_fill
#define GEN_GENERIC_SLOT_6__array_free            gen_Array_gen_Token, gen_Array_gen_Token_free
#define GEN_GENERIC_SLOT_6__array_grow            gen_Array_gen_Token*, gen_Array_gen_Token_grow
#define GEN_GENERIC_SLOT_6__array_num             gen_Array_gen_Token, gen_Array_gen_Token_num
#define GEN_GENERIC_SLOT_6__array_pop             gen_Array_gen_Token, gen_Array_gen_Token_pop
#define GEN_GENERIC_SLOT_6__array_remove_at       gen_Array_gen_Token, gen_Array_gen_Token_remove_at
#define GEN_GENERIC_SLOT_6__array_reserve         gen_Array_gen_Token, gen_Array_gen_Token_reserve
#define GEN_GENERIC_SLOT_6__array_resize          gen_Array_gen_Token, gen_Array_gen_Token_resize
#define GEN_GENERIC_SLOT_6__array_set_capacity    gen_Array_gen_Token*, gen_Array_gen_Token_set_capacity

gen_Array_gen_Token gen_Array_gen_Token_init(gen_AllocatorInfo allocator);
gen_Array_gen_Token gen_Array_gen_Token_init_reserve(gen_AllocatorInfo allocator, gen_usize capacity);
bool                gen_Array_gen_Token_append_array(gen_Array_gen_Token* self, gen_Array_gen_Token other);
bool                gen_Array_gen_Token_append(gen_Array_gen_Token* self, gen_Token value);
bool                gen_Array_gen_Token_append_items(gen_Array_gen_Token* self, gen_Token* items, gen_usize item_num);
bool                gen_Array_gen_Token_append_at(gen_Array_gen_Token* self, gen_Token item, gen_usize idx);
bool                gen_Array_gen_Token_append_items_at(gen_Array_gen_Token* self, gen_Token* items, gen_usize item_num, gen_usize idx);
gen_Token*          gen_Array_gen_Token_back(gen_Array_gen_Token self);
void                gen_Array_gen_Token_clear(gen_Array_gen_Token self);
bool                gen_Array_gen_Token_fill(gen_Array_gen_Token self, gen_usize begin, gen_usize end, gen_Token value);
void                gen_Array_gen_Token_free(gen_Array_gen_Token* self);
bool                gen_Array_gen_Token_grow(gen_Array_gen_Token* self, gen_usize min_capacity);
gen_usize           gen_Array_gen_Token_num(gen_Array_gen_Token self);
gen_Token           gen_Array_gen_Token_pop(gen_Array_gen_Token self);
void                gen_Array_gen_Token_remove_at(gen_Array_gen_Token self, gen_usize idx);
bool                gen_Array_gen_Token_reserve(gen_Array_gen_Token* self, gen_usize new_capacity);
bool                gen_Array_gen_Token_resize(gen_Array_gen_Token* self, gen_usize num);
bool                gen_Array_gen_Token_set_capacity(gen_Array_gen_Token* self, gen_usize new_capacity);

gen_forceinline gen_Array_gen_Token gen_Array_gen_Token_init(gen_AllocatorInfo allocator)
{
	size_t initial_size = gen_array_grow_formula(0);
	return gen_array_init_reserve(gen_Token, allocator, initial_size);
}

inline gen_Array_gen_Token gen_Array_gen_Token_init_reserve(gen_AllocatorInfo allocator, gen_usize capacity)
{
	GEN_ASSERT(capacity > 0);
	gen_ArrayHeader* header = gen_rcast(gen_ArrayHeader*, gen_alloc(allocator, sizeof(gen_ArrayHeader) + sizeof(gen_Token) * capacity));
	if (header == gen_nullptr)
		return gen_nullptr;
	header->Allocator = allocator;
	header->Capacity  = capacity;
	header->Num       = 0;
	return gen_rcast(gen_Token*, header + 1);
}

gen_forceinline bool gen_Array_gen_Token_append_array(gen_Array_gen_Token* self, gen_Array_gen_Token other)
{
	return gen_array_append_items(*self, (gen_Array_gen_Token)other, gen_Array_gen_Token_num(other));
}

inline bool gen_Array_gen_Token_append(gen_Array_gen_Token* self, gen_Token value)
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

inline bool gen_Array_gen_Token_append_items(gen_Array_gen_Token* self, gen_Token* items, gen_usize item_num)
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
	gen_mem_copy((*self) + header->Num, items, sizeof(gen_Token) * item_num);
	header->Num += item_num;
	return true;
}

inline bool gen_Array_gen_Token_append_at(gen_Array_gen_Token* self, gen_Token item, gen_usize idx)
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
	gen_Array_gen_Token target = (*self) + idx;
	gen_mem_move(target + 1, target, (header->Num - idx) * sizeof(gen_Token));
	header->Num++;
	return true;
}

inline bool gen_Array_gen_Token_append_items_at(gen_Array_gen_Token* self, gen_Token* items, gen_usize item_num, gen_usize idx)
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
	gen_Token* target = (*self) + idx + item_num;
	gen_Token* src    = (*self) + idx;
	gen_mem_move(target, src, (header->Num - idx) * sizeof(gen_Token));
	gen_mem_copy(src, items, item_num * sizeof(gen_Token));
	header->Num += item_num;
	return true;
}

inline gen_Token* gen_Array_gen_Token_back(gen_Array_gen_Token self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	if (header->Num == 0)
		return 0;
	return self + header->Num - 1;
}

inline void gen_Array_gen_Token_clear(gen_Array_gen_Token self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	header->Num             = 0;
}

inline bool gen_Array_gen_Token_fill(gen_Array_gen_Token self, gen_usize begin, gen_usize end, gen_Token value)
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

inline void gen_Array_gen_Token_free(gen_Array_gen_Token* self)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	gen_allocator_free(header->Allocator, header);
	self = 0;
}

inline bool gen_Array_gen_Token_grow(gen_Array_gen_Token* self, gen_usize min_capacity)
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

gen_forceinline gen_usize gen_Array_gen_Token_num(gen_Array_gen_Token self)
{
	GEN_ASSERT(self != gen_nullptr);
	return gen_array_get_header(self)->Num;
}

inline gen_Token gen_Array_gen_Token_pop(gen_Array_gen_Token self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	GEN_ASSERT(header->Num > 0);
	gen_Token result = self[header->Num - 1];
	header->Num--;
	return result;
}

gen_forceinline void gen_Array_gen_Token_remove_at(gen_Array_gen_Token self, gen_usize idx)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	GEN_ASSERT(idx < header->Num);
	gen_mem_move(self + idx, self + idx + 1, sizeof(gen_Token) * (header->Num - idx - 1));
	header->Num--;
}

inline bool gen_Array_gen_Token_reserve(gen_Array_gen_Token* self, gen_usize new_capacity)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(new_capacity > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Capacity < new_capacity)
		return gen_array_set_capacity(self, new_capacity);
	return true;
}

inline bool gen_Array_gen_Token_resize(gen_Array_gen_Token* self, gen_usize num)
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

inline bool gen_Array_gen_Token_set_capacity(gen_Array_gen_Token* self, gen_usize new_capacity)
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
	gen_usize        size       = sizeof(gen_ArrayHeader) + sizeof(gen_Token) * new_capacity;
	gen_ArrayHeader* new_header = gen_cast(gen_ArrayHeader*, gen_alloc(header->Allocator, size));
	if (new_header == 0)
		return false;
	gen_mem_move(new_header, header, sizeof(gen_ArrayHeader) + sizeof(gen_Token) * header->Num);
	new_header->Capacity = new_capacity;
	gen_allocator_free(header->Allocator, &header);
	*self = gen_cast(gen_Token*, new_header + 1);
	return true;
}

#pragma endregion gen_Array_gen_Token


#define gen_NullToken                  \
	(gen_Token)                        \
	{                                  \
		{}, Tok_Invalid, 0, 0, TF_Null \
	}

gen_forceinline gen_AccessSpec gen_tok_to_access_specifier(gen_Token tok)
{
	return gen_scast(gen_AccessSpec, tok.Type);
}

gen_forceinline bool gen_tok_is_valid(gen_Token tok)
{
	return tok.Text.Ptr && tok.Text.Len && tok.Type != Tok_Invalid;
}

gen_forceinline bool gen_tok_is_access_operator(gen_Token tok)
{
	return gen_bitfield_is_set(gen_u32, tok.Flags, TF_AccessOperator);
}

gen_forceinline bool gen_tok_is_access_specifier(gen_Token tok)
{
	return gen_bitfield_is_set(gen_u32, tok.Flags, TF_AccessSpecifier);
}

gen_forceinline bool gen_tok_is_attribute(gen_Token tok)
{
	return gen_bitfield_is_set(gen_u32, tok.Flags, TF_Attribute);
}

gen_forceinline bool gen_tok_is_operator(gen_Token tok)
{
	return gen_bitfield_is_set(gen_u32, tok.Flags, TF_Operator);
}

gen_forceinline bool gen_tok_is_preprocessor(gen_Token tok)
{
	return gen_bitfield_is_set(gen_u32, tok.Flags, TF_Preprocess);
}

gen_forceinline bool gen_tok_is_preprocess_cond(gen_Token tok)
{
	return gen_bitfield_is_set(gen_u32, tok.Flags, TF_Preprocess_Cond);
}

gen_forceinline bool gen_tok_is_specifier(gen_Token tok)
{
	return gen_bitfield_is_set(gen_u32, tok.Flags, TF_Specifier);
}

gen_forceinline bool gen_tok_is_end_definition(gen_Token tok)
{
	return gen_bitfield_is_set(gen_u32, tok.Flags, TF_EndDefinition);
}

gen_StrBuilder gen_tok_to_strbuilder(gen_Token tok);

typedef struct gen_TokArray gen_TokArray;

struct gen_TokArray
{
	gen_Array(gen_Token) Arr;
	gen_s32 Idx;
};

typedef struct gen_LexContext gen_LexContext;

struct gen_LexContext
{
	gen_Str     content;
	gen_s32     left;
	char const* scanner;
	gen_s32     line;
	gen_s32     column;
	// gen_StringTable     defines;
	gen_Token token;
};

typedef struct gen_StackNode gen_StackNode;

struct gen_StackNode
{
	gen_StackNode* Prev;

	gen_Token* Start;
	gen_Str    Name;        // The name of the gen_AST node (if parsed)
	gen_Str    ProcName;    // The name of the procedure
};

typedef struct gen_ParseContext gen_ParseContext;

struct gen_ParseContext
{
	gen_TokArray   Tokens;
	gen_StackNode* Scope;
};

enum gen_MacroType gen_enum_underlying(gen_u16)
{
	MT_Expression,    // A macro is assumed to be a expression if not resolved.
	MT_Statement,
	MT_Typename,
	MT_Block_Start,       // Not Supported yet
	MT_Block_End,         // Not Supported yet
	MT_Case_Statement,    // Not Supported yet

	MT_UnderlyingType = GEN_U16_MAX,
};

typedef gen_u16 gen_MacroType;

gen_forceinline gen_TokType gen_macrotype__to_toktype(gen_MacroType type)
{
	switch (type)
	{
		case MT_Statement:
			return Tok_Preprocess_Macro_Stmt;
		case MT_Expression:
			return Tok_Preprocess_Macro_Expr;
		case MT_Typename:
			return Tok_Preprocess_Macro_Typename;
	}
	// All others unsupported for now.
	return Tok_Invalid;
}

inline gen_Str gen_macrotype__to_str(gen_MacroType type)
{
	gen_local_persist gen_Str lookup[] = {
		{ "Statement",      sizeof("Statement") - 1      },
        { "Expression",     sizeof("Expression") - 1     },
        { "Typename",       sizeof("Typename") - 1       },
		{ "Block_Start",    sizeof("Block_Start") - 1    },
        { "Block_End",      sizeof("Block_End") - 1      },
        { "Case_Statement", sizeof("Case_Statement") - 1 },
	};
	gen_local_persist gen_Str invalid = { "Invalid", sizeof("Invalid") };
	if (type > MT_Case_Statement)
		return invalid;

	return lookup[type];
}

enum gen_EMacroFlags gen_enum_underlying(gen_u16)
{
	MF_Functional   = gen_bit(0),    // gen_Macro has parameters (args expected to be passed)
	MF_Expects_Body = gen_bit(1),    // Expects to assign a braced scope to its body.

	// gen_lex__eat wil treat this macro as an identifier if the parser attempts to consume it as one.
	//  ^^^ This is a kludge because we don't support push/pop macro pragmas rn.
	MF_Allow_As_Identifier = gen_bit(2),    // gen_lex__eat wil treat this macro as an attribute if the parser attempts to consume it as one.
	//  ^^^ This a kludge because unreal has a macro that behaves as both a 'statement' and an attribute (UE_DEPRECATED, PRAGMA_ENABLE_DEPRECATION_WARNINGS, etc)
	// TODO(Ed): We can keep the MF_Allow_As_Attribute flag for macros, however, we need to add the ability of gen_AST_Attributes to chain themselves.
	// Its thats already a thing in the standard language anyway
	// & it would allow UE_DEPRECATED, (UE_PROPERTY / UE_FUNCTION) to chain themselves as attributes of a resolved member function/variable definition
	MF_Allow_As_Attribute = gen_bit(3),    // When a macro is encountered after attributes and specifiers while parsing a function, or variable:
	// It will consume the macro and treat it as resolving the definition. (Yes this is for Unreal Engine)
	// (MUST BE OF MT_Statement TYPE)
	MF_Allow_As_Definition = gen_bit(4),
	MF_Allow_As_Specifier  = gen_bit(5),    // Created for Unreal's PURE_VIRTUAL

	MF_Null                = 0,
	MF_UnderlyingType      = GEN_U16_MAX,
};

typedef gen_u16 gen_EMacroFlags;
typedef gen_u16 gen_MacroFlags;

typedef struct gen_Macro gen_Macro;

struct gen_Macro
{
	gen_StrCached  Name;
	gen_MacroType  Type;
	gen_MacroFlags Flags;
};

gen_forceinline gen_b32 gen_macro_is_functional(gen_Macro macro)
{
	return gen_bitfield_is_set(gen_b16, macro.Flags, MF_Functional);
}

gen_forceinline gen_b32 gen_macro_expects_body(gen_Macro macro)
{
	return gen_bitfield_is_set(gen_b16, macro.Flags, MF_Expects_Body);
}

#if GEN_COMPILER_CPP && ! GEN_C_LIKE_CPP
gen_forceinline gen_b32 is_functional(gen_Macro macro)
{
	return gen_bitfield_is_set(gen_b16, macro.Flags, MF_Functional);
}

gen_forceinline gen_b32 expects_body(gen_Macro macro)
{
	return gen_bitfield_is_set(gen_b16, macro.Flags, MF_Expects_Body);
}
#endif

typedef gen_HashTable(gen_Macro) MacroTable;
#pragma endregion Types

#pragma region AST

/*
  ______   ______  ________      __    __       ______                 __
 /      \ /      \|        \    |  \  |  \     /      \               |  \
|  ▓▓▓▓▓▓\  ▓▓▓▓▓▓\\▓▓▓▓▓▓▓▓    | ▓▓\ | ▓▓    |  ▓▓▓▓▓▓\ ______   ____| ▓▓ ______
| ▓▓__| ▓▓ ▓▓___\▓▓  | ▓▓       | ▓▓▓\| ▓▓    | ▓▓   \▓▓/      \ /      ▓▓/      \
| ▓▓    ▓▓\▓▓    \   | ▓▓       | ▓▓▓▓\ ▓▓    | ▓▓     |  ▓▓▓▓▓▓\  ▓▓▓▓▓▓▓  ▓▓▓▓▓▓\
| ▓▓▓▓▓▓▓▓_\▓▓▓▓▓▓\  | ▓▓       | ▓▓\▓▓ ▓▓    | ▓▓   __| ▓▓  | ▓▓ ▓▓  | ▓▓ ▓▓    ▓▓
| ▓▓  | ▓▓  \__| ▓▓  | ▓▓       | ▓▓ \▓▓▓▓    | ▓▓__/  \ ▓▓__/ ▓▓ ▓▓__| ▓▓ ▓▓▓▓▓▓▓▓
| ▓▓  | ▓▓\▓▓    ▓▓  | ▓▓       | ▓▓  \▓▓▓     \▓▓    ▓▓\▓▓    ▓▓\▓▓    ▓▓\▓▓     \
 \▓▓   \▓▓ \▓▓▓▓▓▓    \▓▓        \▓▓   \▓▓      \▓▓▓▓▓▓  \▓▓▓▓▓▓  \▓▓▓▓▓▓▓ \▓▓▓▓▓▓▓
*/

struct gen_AST;
typedef struct gen_AST gen_AST;
struct gen_AST_Body;
typedef struct gen_AST_Body gen_AST_Body;
struct gen_AST_Attributes;
typedef struct gen_AST_Attributes gen_AST_Attributes;
struct gen_AST_Comment;
typedef struct gen_AST_Comment gen_AST_Comment;
struct gen_AST_Constructor;
typedef struct gen_AST_Constructor gen_AST_Constructor;
// struct gen_AST_BaseClass;
struct gen_AST_Class;
typedef struct gen_AST_Class gen_AST_Class;
struct gen_AST_Define;
typedef struct gen_AST_Define gen_AST_Define;
struct gen_AST_DefineParams;
typedef struct gen_AST_DefineParams gen_AST_DefineParams;
struct gen_AST_Destructor;
typedef struct gen_AST_Destructor gen_AST_Destructor;
struct gen_AST_Enum;
typedef struct gen_AST_Enum gen_AST_Enum;
struct gen_AST_Exec;
typedef struct gen_AST_Exec gen_AST_Exec;
struct gen_AST_Extern;
typedef struct gen_AST_Extern gen_AST_Extern;
struct gen_AST_Include;
typedef struct gen_AST_Include gen_AST_Include;
struct gen_AST_Friend;
typedef struct gen_AST_Friend gen_AST_Friend;
struct gen_AST_Fn;
typedef struct gen_AST_Fn gen_AST_Fn;
struct gen_AST_Module;
typedef struct gen_AST_Module gen_AST_Module;
struct gen_AST_NS;
typedef struct gen_AST_NS gen_AST_NS;
struct gen_AST_Operator;
typedef struct gen_AST_Operator gen_AST_Operator;
struct gen_AST_OpCast;
typedef struct gen_AST_OpCast gen_AST_OpCast;
struct gen_AST_Params;
typedef struct gen_AST_Params gen_AST_Params;
struct gen_AST_Pragma;
typedef struct gen_AST_Pragma gen_AST_Pragma;
struct gen_AST_PreprocessCond;
typedef struct gen_AST_PreprocessCond gen_AST_PreprocessCond;
struct gen_AST_Specifiers;
typedef struct gen_AST_Specifiers gen_AST_Specifiers;


struct gen_AST_Struct;
typedef struct gen_AST_Struct gen_AST_Struct;
struct gen_AST_Template;
typedef struct gen_AST_Template gen_AST_Template;
struct gen_AST_Typename;
typedef struct gen_AST_Typename gen_AST_Typename;
struct gen_AST_Typedef;
typedef struct gen_AST_Typedef gen_AST_Typedef;
struct gen_AST_Union;
typedef struct gen_AST_Union gen_AST_Union;
struct gen_AST_Using;
typedef struct gen_AST_Using gen_AST_Using;
struct gen_AST_Var;
typedef struct gen_AST_Var gen_AST_Var;


typedef gen_AST* gen_Code;

typedef gen_AST_Body*           gen_CodeBody;
typedef gen_AST_Attributes*     gen_CodeAttributes;
typedef gen_AST_Comment*        gen_CodeComment;
typedef gen_AST_Class*          gen_CodeClass;
typedef gen_AST_Constructor*    gen_CodeConstructor;
typedef gen_AST_Define*         gen_CodeDefine;
typedef gen_AST_DefineParams*   gen_CodeDefineParams;
typedef gen_AST_Destructor*     gen_CodeDestructor;
typedef gen_AST_Enum*           gen_CodeEnum;
typedef gen_AST_Exec*           gen_CodeExec;
typedef gen_AST_Extern*         gen_CodeExtern;
typedef gen_AST_Include*        gen_CodeInclude;
typedef gen_AST_Friend*         gen_CodeFriend;
typedef gen_AST_Fn*             gen_CodeFn;
typedef gen_AST_Module*         gen_CodeModule;
typedef gen_AST_NS*             gen_CodeNS;
typedef gen_AST_Operator*       gen_CodeOperator;
typedef gen_AST_OpCast*         gen_CodeOpCast;
typedef gen_AST_Params*         gen_CodeParams;
typedef gen_AST_PreprocessCond* gen_CodePreprocessCond;
typedef gen_AST_Pragma*         gen_CodePragma;
typedef gen_AST_Specifiers*     gen_CodeSpecifiers;


typedef gen_AST_Struct*   gen_CodeStruct;
typedef gen_AST_Template* gen_CodeTemplate;
typedef gen_AST_Typename* gen_CodeTypename;
typedef gen_AST_Typedef*  gen_CodeTypedef;
typedef gen_AST_Union*    gen_CodeUnion;
typedef gen_AST_Using*    gen_CodeUsing;
typedef gen_AST_Var*      gen_CodeVar;

#pragma region gen_Code C-Interface


GEN_API void           gen_code__append(gen_Code code, gen_Code other);
GEN_API gen_Str        gen_code__debug_str(gen_Code code);
GEN_API gen_Code       gen_code__duplicate(gen_Code code);
GEN_API gen_Code*      gen_code__entry(gen_Code code, gen_u32 idx);
GEN_API bool           gen_code__has_entries(gen_Code code);
GEN_API bool           gen_code__is_body(gen_Code code);
GEN_API bool           gen_code__is_equal(gen_Code code, gen_Code other);
GEN_API bool           gen_code__is_valid(gen_Code code);
GEN_API void           gen_code__set_global(gen_Code code);
GEN_API gen_StrBuilder gen_code__to_strbuilder(gen_Code self);
GEN_API void           gen_code__to_strbuilder_ptr(gen_Code self, gen_StrBuilder* result);
GEN_API gen_Str        gen_code__type_str(gen_Code self);
GEN_API bool           gen_code__validate_body(gen_Code self);

#pragma endregion gen_Code C - Interface



// Used to identify ASTs that should always be duplicated. (Global constant ASTs)
GEN_API extern gen_Code gen_Code_Global;

// Used to identify invalid generated code.
GEN_API extern gen_Code gen_Code_Invalid;

struct gen_Code_POD
{
	gen_AST* ast;
};
typedef struct gen_Code_POD gen_Code_POD;
gen_static_assert(sizeof(gen_Code) == sizeof(gen_Code_POD), "ERROR: gen_Code is not POD");

// Desired width of the gen_AST data structure.
#define gen_AST_POD_Size 128

#define gen_AST_ArrSpecs_Cap                                                                                                                           \
	(gen_AST_POD_Size - sizeof(gen_Code) - sizeof(gen_StrCached) - sizeof(gen_Code) * 2 - sizeof(gen_Token*) - sizeof(gen_Code) - sizeof(gen_CodeType) \
	 - sizeof(gen_ModuleFlag) - sizeof(gen_u32))                                                                                                       \
	        / sizeof(gen_Specifier)                                                                                                                    \
	    - 1

/*
	Simple gen_AST POD with functionality to seralize into C++ syntax.
	TODO(Ed): Eventually haven't a transparent gen_AST like this will longer be viable once statements & expressions are in (most likely....)
*/
struct gen_AST
{
	union
	{
		struct
		{
			gen_Code InlineCmt;     // Class, Constructor, Destructor, Enum, Friend, Functon, gen_Operator, OpCast, Struct, Typedef, Using, Variable
			gen_Code Attributes;    // Class, Enum, Function, Struct, Typedef, Union, Using, Variable // TODO(Ed): Parameters can have attributes
			gen_Code Specs;         // Class, Destructor, Function, gen_Operator, Struct, Typename, Variable

			union
			{
				gen_Code InitializerList;    // Constructor
				gen_Code ParentType;         // Class, Struct, ParentType->Next has a possible list of interfaces.
				gen_Code ReturnType;         // Function, gen_Operator, Typename
				gen_Code UnderlyingType;     // Enum, Typedef
				gen_Code ValueType;          // Parameter, Variable
			};

			union
			{
				gen_Code gen_Macro;              // Parameter
				gen_Code BitfieldSize;           // Variable (Class/Struct Data Member)
				gen_Code Params;                 // Constructor, Define, Function, gen_Operator, Template, Typename
				gen_Code UnderlyingTypeMacro;    // Enum
			};

			union
			{
				gen_Code ArrExpr;        // Typename
				gen_Code Body;           // Class, Constructor, Define, Destructor, Enum, Friend, Function, Namespace, Struct, Union
				gen_Code Declaration;    // Friend, Template
				gen_Code Value;          // Parameter, Variable
			};

			union
			{
				gen_Code
				    NextVar;    // Variable; Possible way to handle comma separated variables declarations. ( , NextVar->Specs NextVar->Name NextVar->ArrExpr = NextVar->Value )
				gen_Code SuffixSpecs;      // Typename, Function (Thanks Unreal)
				gen_Code PostNameMacro;    // Only used with parameters for specifically UE_REQUIRES (Thanks Unreal)
			};
		};

		gen_StrCached Content;    // Attributes, Comment, Execution, Include

		struct
		{
			gen_Specifier ArrSpecs[gen_AST_ArrSpecs_Cap];    // Specifiers
			gen_Code      NextSpecs;                         // Specifiers; If ArrSpecs is full, then NextSpecs is used.
		};
	};

	gen_StrCached Name;

	union
	{
		gen_Code Prev;
		gen_Code Front;
		gen_Code Last;
	};

	union
	{
		gen_Code Next;
		gen_Code Back;
	};

	gen_Token*   gen_Token;    // Reference to starting token, only available if it was derived from parsing.
	gen_Code     Parent;
	gen_CodeType Type;
	//	gen_CodeFlag          CodeFlags;
	gen_ModuleFlag ModuleFlags;

	union
	{
		gen_b32 IsFunction;    // Used by typedef to not serialize the name field.

		struct
		{
			gen_b16          IsParamPack;    // Used by typename to know if type should be considered a parameter pack.
			gen_ETypenameTag TypeTag;        // Used by typename to keep track of explicitly declared tags for the identifier (enum, struct, union)
		};

		gen_Operator   Op;
		gen_AccessSpec ParentAccess;
		gen_s32        NumEntries;
		gen_s32
		    VarParenthesizedInit;    // Used by variables to know that initialization is using a gen_constructor_ expression instead of an assignment expression.
	};
};

gen_static_assert(sizeof(gen_AST) == gen_AST_POD_Size, "ERROR: gen_AST is not size of gen_AST_POD_Size");

#define gen_InvalidCode         \
	(void*)                     \
	{                           \
		(void*)gen_Code_Invalid \
	}

#define gen_NullCode gen_nullptr

/*
  ______                 __               ______            __                        ______
 /      \               |  \             |      \          |  \                      /      \
|  ▓▓▓▓▓▓\ ______   ____| ▓▓ ______       \▓▓▓▓▓▓_______  _| ▓▓_    ______   ______ |  ▓▓▓▓▓▓\ ______   _______  ______
| ▓▓   \▓▓/      \ /      ▓▓/      \       | ▓▓ |       \|   ▓▓ \  /      \ /      \| ▓▓_  \▓▓|      \ /       \/      \
| ▓▓     |  ▓▓▓▓▓▓\  ▓▓▓▓▓▓▓  ▓▓▓▓▓▓\      | ▓▓ | ▓▓▓▓▓▓▓\\▓▓▓▓▓▓ |  ▓▓▓▓▓▓\  ▓▓▓▓▓▓\ ▓▓ \     \▓▓▓▓▓▓\  ▓▓▓▓▓▓▓  ▓▓▓▓▓▓\
| ▓▓   __| ▓▓  | ▓▓ ▓▓  | ▓▓ ▓▓    ▓▓      | ▓▓ | ▓▓  | ▓▓ | ▓▓ __| ▓▓    ▓▓ ▓▓   \▓▓ ▓▓▓▓    /      ▓▓ ▓▓     | ▓▓    ▓▓
| ▓▓__/  \ ▓▓__/ ▓▓ ▓▓__| ▓▓ ▓▓▓▓▓▓▓▓     _| ▓▓_| ▓▓  | ▓▓ | ▓▓|  \ ▓▓▓▓▓▓▓▓ ▓▓     | ▓▓     |  ▓▓▓▓▓▓▓ ▓▓_____| ▓▓▓▓▓▓▓▓
 \▓▓    ▓▓\▓▓    ▓▓\▓▓    ▓▓\▓▓     \    |   ▓▓ \ ▓▓  | ▓▓  \▓▓  ▓▓\▓▓     \ ▓▓     | ▓▓      \▓▓    ▓▓\▓▓     \\▓▓     \
  \▓▓▓▓▓▓  \▓▓▓▓▓▓  \▓▓▓▓▓▓▓ \▓▓▓▓▓▓▓     \▓▓▓▓▓▓\▓▓   \▓▓   \▓▓▓▓  \▓▓▓▓▓▓▓\▓▓      \▓▓       \▓▓▓▓▓▓▓ \▓▓▓▓▓▓▓ \▓▓▓▓▓▓▓
*/

#pragma region gen_Code Type C-Interface

#define gen_code_append(code, other)              \
	_Generic(                                     \
	    (code),                                   \
	    gen_Code: gen_code__append,               \
	    gen_CodeBody: gen_code__append,           \
	    gen_CodeAttributes: gen_code__append,     \
	    gen_CodeComment: gen_code__append,        \
	    gen_CodeClass: gen_code__append,          \
	    gen_CodeConstructor: gen_code__append,    \
	    gen_CodeDefine: gen_code__append,         \
	    gen_CodeDefineParams: gen_code__append,   \
	    gen_CodeDestructor: gen_code__append,     \
	    gen_CodeEnum: gen_code__append,           \
	    gen_CodeExec: gen_code__append,           \
	    gen_CodeExtern: gen_code__append,         \
	    gen_CodeInclude: gen_code__append,        \
	    gen_CodeFriend: gen_code__append,         \
	    gen_CodeFn: gen_code__append,             \
	    gen_CodeModule: gen_code__append,         \
	    gen_CodeNS: gen_code__append,             \
	    gen_CodeOperator: gen_code__append,       \
	    gen_CodeOpCast: gen_code__append,         \
	    gen_CodePragma: gen_code__append,         \
	    gen_CodeParams: gen_code__append,         \
	    gen_CodePreprocessCond: gen_code__append, \
	    gen_CodeSpecifiers: gen_code__append,     \
	    gen_CodeStruct: gen_code__append,         \
	    gen_CodeTemplate: gen_code__append,       \
	    gen_CodeTypename: gen_code__append,       \
	    gen_CodeTypedef: gen_code__append,        \
	    gen_CodeUnion: gen_code__append,          \
	    gen_CodeUsing: gen_code__append,          \
	    gen_CodeVar: gen_code__append,            \
	    default: gen_generic_selection_fail       \
	) GEN_RESOLVED_FUNCTION_CALL((gen_Code)code, other)

#define gen_code_debug_str(code)                     \
	_Generic(                                        \
	    (code),                                      \
	    gen_Code: gen_code__debug_str,               \
	    gen_CodeBody: gen_code__debug_str,           \
	    gen_CodeAttributes: gen_code__debug_str,     \
	    gen_CodeComment: gen_code__debug_str,        \
	    gen_CodeClass: gen_code__debug_str,          \
	    gen_CodeConstructor: gen_code__debug_str,    \
	    gen_CodeDefine: gen_code__debug_str,         \
	    gen_CodeDefineParams: gen_code__debug_str,   \
	    gen_CodeDestructor: gen_code__debug_str,     \
	    gen_CodeEnum: gen_code__debug_str,           \
	    gen_CodeExec: gen_code__debug_str,           \
	    gen_CodeExtern: gen_code__debug_str,         \
	    gen_CodeInclude: gen_code__debug_str,        \
	    gen_CodeFriend: gen_code__debug_str,         \
	    gen_CodeFn: gen_code__debug_str,             \
	    gen_CodeModule: gen_code__debug_str,         \
	    gen_CodeNS: gen_code__debug_str,             \
	    gen_CodeOperator: gen_code__debug_str,       \
	    gen_CodeOpCast: gen_code__debug_str,         \
	    gen_CodePragma: gen_code__debug_str,         \
	    gen_CodeParams: gen_code__debug_str,         \
	    gen_CodePreprocessCond: gen_code__debug_str, \
	    gen_CodeSpecifiers: gen_code__debug_str,     \
	    gen_CodeStruct: gen_code__debug_str,         \
	    gen_CodeTemplate: gen_code__debug_str,       \
	    gen_CodeTypename: gen_code__debug_str,       \
	    gen_CodeTypedef: gen_code__debug_str,        \
	    gen_CodeUnion: gen_code__debug_str,          \
	    gen_CodeUsing: gen_code__debug_str,          \
	    gen_CodeVar: gen_code__debug_str,            \
	    default: gen_generic_selection_fail          \
	) GEN_RESOLVED_FUNCTION_CALL((gen_Code)code)

#define gen_code_duplicate(code)                     \
	_Generic(                                        \
	    (code),                                      \
	    gen_Code: gen_code__duplicate,               \
	    gen_CodeBody: gen_code__duplicate,           \
	    gen_CodeAttributes: gen_code__duplicate,     \
	    gen_CodeComment: gen_code__duplicate,        \
	    gen_CodeClass: gen_code__duplicate,          \
	    gen_CodeConstructor: gen_code__duplicate,    \
	    gen_CodeDefine: gen_code__duplicate,         \
	    gen_CodeDefineParams: gen_code__duplicate,   \
	    gen_CodeDestructor: gen_code__duplicate,     \
	    gen_CodeEnum: gen_code__duplicate,           \
	    gen_CodeExec: gen_code__duplicate,           \
	    gen_CodeExtern: gen_code__duplicate,         \
	    gen_CodeInclude: gen_code__duplicate,        \
	    gen_CodeFriend: gen_code__duplicate,         \
	    gen_CodeFn: gen_code__duplicate,             \
	    gen_CodeModule: gen_code__duplicate,         \
	    gen_CodeNS: gen_code__duplicate,             \
	    gen_CodeOperator: gen_code__duplicate,       \
	    gen_CodeOpCast: gen_code__duplicate,         \
	    gen_CodePragma: gen_code__duplicate,         \
	    gen_CodeParams: gen_code__duplicate,         \
	    gen_CodePreprocessCond: gen_code__duplicate, \
	    gen_CodeSpecifiers: gen_code__duplicate,     \
	    gen_CodeStruct: gen_code__duplicate,         \
	    gen_CodeTemplate: gen_code__duplicate,       \
	    gen_CodeTypename: gen_code__duplicate,       \
	    gen_CodeTypedef: gen_code__duplicate,        \
	    gen_CodeUnion: gen_code__duplicate,          \
	    gen_CodeUsing: gen_code__duplicate,          \
	    gen_CodeVar: gen_code__duplicate,            \
	    default: gen_generic_selection_fail          \
	) GEN_RESOLVED_FUNCTION_CALL((gen_Code)code)

#define gen_code_entry(code, idx)                \
	_Generic(                                    \
	    (code),                                  \
	    gen_Code: gen_code__entry,               \
	    gen_CodeBody: gen_code__entry,           \
	    gen_CodeAttributes: gen_code__entry,     \
	    gen_CodeComment: gen_code__entry,        \
	    gen_CodeClass: gen_code__entry,          \
	    gen_CodeConstructor: gen_code__entry,    \
	    gen_CodeDefine: gen_code__entry,         \
	    gen_CodeDefineParams: gen_code__entry,   \
	    gen_CodeDestructor: gen_code__entry,     \
	    gen_CodeEnum: gen_code__entry,           \
	    gen_CodeExec: gen_code__entry,           \
	    gen_CodeExtern: gen_code__entry,         \
	    gen_CodeInclude: gen_code__entry,        \
	    gen_CodeFriend: gen_code__entry,         \
	    gen_CodeFn: gen_code__entry,             \
	    gen_CodeModule: gen_code__entry,         \
	    gen_CodeNS: gen_code__entry,             \
	    gen_CodeOperator: gen_code__entry,       \
	    gen_CodeOpCast: gen_code__entry,         \
	    gen_CodePragma: gen_code__entry,         \
	    gen_CodeParams: gen_code__entry,         \
	    gen_CodePreprocessCond: gen_code__entry, \
	    gen_CodeSpecifiers: gen_code__entry,     \
	    gen_CodeStruct: gen_code__entry,         \
	    gen_CodeTemplate: gen_code__entry,       \
	    gen_CodeTypename: gen_code__entry,       \
	    gen_CodeTypedef: gen_code__entry,        \
	    gen_CodeUnion: gen_code__entry,          \
	    gen_CodeUsing: gen_code__entry,          \
	    gen_CodeVar: gen_code__entry,            \
	    default: gen_generic_selection_fail      \
	) GEN_RESOLVED_FUNCTION_CALL((gen_Code)code, idx)

#define gen_code_has_entries(code)                     \
	_Generic(                                          \
	    (code),                                        \
	    gen_Code: gen_code__has_entries,               \
	    gen_CodeBody: gen_code__has_entries,           \
	    gen_CodeAttributes: gen_code__has_entries,     \
	    gen_CodeComment: gen_code__has_entries,        \
	    gen_CodeClass: gen_code__has_entries,          \
	    gen_CodeConstructor: gen_code__has_entries,    \
	    gen_CodeDefine: gen_code__has_entries,         \
	    gen_CodeDefineParams: gen_code__has_entries,   \
	    gen_CodeDestructor: gen_code__has_entries,     \
	    gen_CodeEnum: gen_code__has_entries,           \
	    gen_CodeExec: gen_code__has_entries,           \
	    gen_CodeExtern: gen_code__has_entries,         \
	    gen_CodeInclude: gen_code__has_entries,        \
	    gen_CodeFriend: gen_code__has_entries,         \
	    gen_CodeFn: gen_code__has_entries,             \
	    gen_CodeModule: gen_code__has_entries,         \
	    gen_CodeNS: gen_code__has_entries,             \
	    gen_CodeOperator: gen_code__has_entries,       \
	    gen_CodeOpCast: gen_code__has_entries,         \
	    gen_CodePragma: gen_code__has_entries,         \
	    gen_CodeParams: gen_code__has_entries,         \
	    gen_CodePreprocessCond: gen_code__has_entries, \
	    gen_CodeSpecifiers: gen_code__has_entries,     \
	    gen_CodeStruct: gen_code__has_entries,         \
	    gen_CodeTemplate: gen_code__has_entries,       \
	    gen_CodeTypename: gen_code__has_entries,       \
	    gen_CodeTypedef: gen_code__has_entries,        \
	    gen_CodeUnion: gen_code__has_entries,          \
	    gen_CodeUsing: gen_code__has_entries,          \
	    gen_CodeVar: gen_code__has_entries,            \
	    default: gen_generic_selection_fail            \
	) GEN_RESOLVED_FUNCTION_CALL((gen_Code)code)

#define gen_code_is_body(code)                     \
	_Generic(                                      \
	    (code),                                    \
	    gen_Code: gen_code__is_body,               \
	    gen_CodeBody: gen_code__is_body,           \
	    gen_CodeAttributes: gen_code__is_body,     \
	    gen_CodeComment: gen_code__is_body,        \
	    gen_CodeClass: gen_code__is_body,          \
	    gen_CodeConstructor: gen_code__is_body,    \
	    gen_CodeDefine: gen_code__is_body,         \
	    gen_CodeDefineParams: gen_code__is_body,   \
	    gen_CodeDestructor: gen_code__is_body,     \
	    gen_CodeEnum: gen_code__is_body,           \
	    gen_CodeExec: gen_code__is_body,           \
	    gen_CodeExtern: gen_code__is_body,         \
	    gen_CodeInclude: gen_code__is_body,        \
	    gen_CodeFriend: gen_code__is_body,         \
	    gen_CodeFn: gen_code__is_body,             \
	    gen_CodeModule: gen_code__is_body,         \
	    gen_CodeNS: gen_code__is_body,             \
	    gen_CodeOperator: gen_code__is_body,       \
	    gen_CodeOpCast: gen_code__is_body,         \
	    gen_CodePragma: gen_code__is_body,         \
	    gen_CodeParams: gen_code__is_body,         \
	    gen_CodePreprocessCond: gen_code__is_body, \
	    gen_CodeSpecifiers: gen_code__is_body,     \
	    gen_CodeStruct: gen_code__is_body,         \
	    gen_CodeTemplate: gen_code__is_body,       \
	    gen_CodeTypename: gen_code__is_body,       \
	    gen_CodeTypedef: gen_code__is_body,        \
	    gen_CodeUnion: gen_code__is_body,          \
	    gen_CodeUsing: gen_code__is_body,          \
	    gen_CodeVar: gen_code__is_body,            \
	    default: gen_generic_selection_fail        \
	) GEN_RESOLVED_FUNCTION_CALL((gen_Code)code)

#define gen_code_is_equal(code, other)              \
	_Generic(                                       \
	    (code),                                     \
	    gen_Code: gen_code__is_equal,               \
	    gen_CodeBody: gen_code__is_equal,           \
	    gen_CodeAttributes: gen_code__is_equal,     \
	    gen_CodeComment: gen_code__is_equal,        \
	    gen_CodeClass: gen_code__is_equal,          \
	    gen_CodeConstructor: gen_code__is_equal,    \
	    gen_CodeDefine: gen_code__is_equal,         \
	    gen_CodeDefineParams: gen_code__is_equal,   \
	    gen_CodeDestructor: gen_code__is_equal,     \
	    gen_CodeEnum: gen_code__is_equal,           \
	    gen_CodeExec: gen_code__is_equal,           \
	    gen_CodeExtern: gen_code__is_equal,         \
	    gen_CodeInclude: gen_code__is_equal,        \
	    gen_CodeFriend: gen_code__is_equal,         \
	    gen_CodeFn: gen_code__is_equal,             \
	    gen_CodeModule: gen_code__is_equal,         \
	    gen_CodeNS: gen_code__is_equal,             \
	    gen_CodeOperator: gen_code__is_equal,       \
	    gen_CodeOpCast: gen_code__is_equal,         \
	    gen_CodePragma: gen_code__is_equal,         \
	    gen_CodeParams: gen_code__is_equal,         \
	    gen_CodePreprocessCond: gen_code__is_equal, \
	    gen_CodeSpecifiers: gen_code__is_equal,     \
	    gen_CodeStruct: gen_code__is_equal,         \
	    gen_CodeTemplate: gen_code__is_equal,       \
	    gen_CodeTypename: gen_code__is_equal,       \
	    gen_CodeTypedef: gen_code__is_equal,        \
	    gen_CodeUnion: gen_code__is_equal,          \
	    gen_CodeUsing: gen_code__is_equal,          \
	    gen_CodeVar: gen_code__is_equal,            \
	    default: gen_generic_selection_fail         \
	) GEN_RESOLVED_FUNCTION_CALL((gen_Code)code, other)

#define gen_code_is_valid(code)                     \
	_Generic(                                       \
	    (code),                                     \
	    gen_Code: gen_code__is_valid,               \
	    gen_CodeBody: gen_code__is_valid,           \
	    gen_CodeAttributes: gen_code__is_valid,     \
	    gen_CodeComment: gen_code__is_valid,        \
	    gen_CodeClass: gen_code__is_valid,          \
	    gen_CodeConstructor: gen_code__is_valid,    \
	    gen_CodeDefine: gen_code__is_valid,         \
	    gen_CodeDefineParams: gen_code__is_valid,   \
	    gen_CodeDestructor: gen_code__is_valid,     \
	    gen_CodeEnum: gen_code__is_valid,           \
	    gen_CodeExec: gen_code__is_valid,           \
	    gen_CodeExtern: gen_code__is_valid,         \
	    gen_CodeInclude: gen_code__is_valid,        \
	    gen_CodeFriend: gen_code__is_valid,         \
	    gen_CodeFn: gen_code__is_valid,             \
	    gen_CodeModule: gen_code__is_valid,         \
	    gen_CodeNS: gen_code__is_valid,             \
	    gen_CodeOperator: gen_code__is_valid,       \
	    gen_CodeOpCast: gen_code__is_valid,         \
	    gen_CodePragma: gen_code__is_valid,         \
	    gen_CodeParams: gen_code__is_valid,         \
	    gen_CodePreprocessCond: gen_code__is_valid, \
	    gen_CodeSpecifiers: gen_code__is_valid,     \
	    gen_CodeStruct: gen_code__is_valid,         \
	    gen_CodeTemplate: gen_code__is_valid,       \
	    gen_CodeTypename: gen_code__is_valid,       \
	    gen_CodeTypedef: gen_code__is_valid,        \
	    gen_CodeUnion: gen_code__is_valid,          \
	    gen_CodeUsing: gen_code__is_valid,          \
	    gen_CodeVar: gen_code__is_valid,            \
	    default: gen_generic_selection_fail         \
	) GEN_RESOLVED_FUNCTION_CALL((gen_Code)code)

#define gen_code_set_global(code)                     \
	_Generic(                                         \
	    (code),                                       \
	    gen_Code: gen_code__set_global,               \
	    gen_CodeBody: gen_code__set_global,           \
	    gen_CodeAttributes: gen_code__set_global,     \
	    gen_CodeComment: gen_code__set_global,        \
	    gen_CodeClass: gen_code__set_global,          \
	    gen_CodeConstructor: gen_code__set_global,    \
	    gen_CodeDefine: gen_code__set_global,         \
	    gen_CodeDefineParams: gen_code__set_global,   \
	    gen_CodeDestructor: gen_code__set_global,     \
	    gen_CodeEnum: gen_code__set_global,           \
	    gen_CodeExec: gen_code__set_global,           \
	    gen_CodeExtern: gen_code__set_global,         \
	    gen_CodeInclude: gen_code__set_global,        \
	    gen_CodeFriend: gen_code__set_global,         \
	    gen_CodeFn: gen_code__set_global,             \
	    gen_CodeModule: gen_code__set_global,         \
	    gen_CodeNS: gen_code__set_global,             \
	    gen_CodeOperator: gen_code__set_global,       \
	    gen_CodeOpCast: gen_code__set_global,         \
	    gen_CodePragma: gen_code__set_global,         \
	    gen_CodeParams: gen_code__set_global,         \
	    gen_CodePreprocessCond: gen_code__set_global, \
	    gen_CodeSpecifiers: gen_code__set_global,     \
	    gen_CodeStruct: gen_code__set_global,         \
	    gen_CodeTemplate: gen_code__set_global,       \
	    gen_CodeTypename: gen_code__set_global,       \
	    gen_CodeTypedef: gen_code__set_global,        \
	    gen_CodeUnion: gen_code__set_global,          \
	    gen_CodeUsing: gen_code__set_global,          \
	    gen_CodeVar: gen_code__set_global,            \
	    default: gen_generic_selection_fail           \
	) GEN_RESOLVED_FUNCTION_CALL((gen_Code)code)

#define gen_code_to_strbuilder(code)                     \
	_Generic(                                            \
	    (code),                                          \
	    gen_Code: gen_code__to_strbuilder,               \
	    gen_CodeBody: gen_code__to_strbuilder,           \
	    gen_CodeAttributes: gen_code__to_strbuilder,     \
	    gen_CodeComment: gen_code__to_strbuilder,        \
	    gen_CodeClass: gen_code__to_strbuilder,          \
	    gen_CodeConstructor: gen_code__to_strbuilder,    \
	    gen_CodeDefine: gen_code__to_strbuilder,         \
	    gen_CodeDefineParams: gen_code__to_strbuilder,   \
	    gen_CodeDestructor: gen_code__to_strbuilder,     \
	    gen_CodeEnum: gen_code__to_strbuilder,           \
	    gen_CodeExec: gen_code__to_strbuilder,           \
	    gen_CodeExtern: gen_code__to_strbuilder,         \
	    gen_CodeInclude: gen_code__to_strbuilder,        \
	    gen_CodeFriend: gen_code__to_strbuilder,         \
	    gen_CodeFn: gen_code__to_strbuilder,             \
	    gen_CodeModule: gen_code__to_strbuilder,         \
	    gen_CodeNS: gen_code__to_strbuilder,             \
	    gen_CodeOperator: gen_code__to_strbuilder,       \
	    gen_CodeOpCast: gen_code__to_strbuilder,         \
	    gen_CodePragma: gen_code__to_strbuilder,         \
	    gen_CodeParams: gen_code__to_strbuilder,         \
	    gen_CodePreprocessCond: gen_code__to_strbuilder, \
	    gen_CodeSpecifiers: gen_code__to_strbuilder,     \
	    gen_CodeStruct: gen_code__to_strbuilder,         \
	    gen_CodeTemplate: gen_code__to_strbuilder,       \
	    gen_CodeTypename: gen_code__to_strbuilder,       \
	    gen_CodeTypedef: gen_code__to_strbuilder,        \
	    gen_CodeUnion: gen_code__to_strbuilder,          \
	    gen_CodeUsing: gen_code__to_strbuilder,          \
	    gen_CodeVar: gen_code__to_strbuilder,            \
	    default: gen_generic_selection_fail              \
	) GEN_RESOLVED_FUNCTION_CALL((gen_Code)code)

#define gen_code_to_strbuilder_ptr(code, result)             \
	_Generic(                                                \
	    (code),                                              \
	    gen_Code: gen_code__to_strbuilder_ptr,               \
	    gen_CodeBody: gen_code__to_strbuilder_ptr,           \
	    gen_CodeAttributes: gen_code__to_strbuilder_ptr,     \
	    gen_CodeComment: gen_code__to_strbuilder_ptr,        \
	    gen_CodeClass: gen_code__to_strbuilder_ptr,          \
	    gen_CodeConstructor: gen_code__to_strbuilder_ptr,    \
	    gen_CodeDefine: gen_code__to_strbuilder_ptr,         \
	    gen_CodeDefineParams: gen_code__to_strbuilder_ptr,   \
	    gen_CodeDestructor: gen_code__to_strbuilder_ptr,     \
	    gen_CodeEnum: gen_code__to_strbuilder_ptr,           \
	    gen_CodeExec: gen_code__to_strbuilder_ptr,           \
	    gen_CodeExtern: gen_code__to_strbuilder_ptr,         \
	    gen_CodeInclude: gen_code__to_strbuilder_ptr,        \
	    gen_CodeFriend: gen_code__to_strbuilder_ptr,         \
	    gen_CodeFn: gen_code__to_strbuilder_ptr,             \
	    gen_CodeModule: gen_code__to_strbuilder_ptr,         \
	    gen_CodeNS: gen_code__to_strbuilder_ptr,             \
	    gen_CodeOperator: gen_code__to_strbuilder_ptr,       \
	    gen_CodeOpCast: gen_code__to_strbuilder_ptr,         \
	    gen_CodePragma: gen_code__to_strbuilder_ptr,         \
	    gen_CodeParams: gen_code__to_strbuilder_ptr,         \
	    gen_CodePreprocessCond: gen_code__to_strbuilder_ptr, \
	    gen_CodeSpecifiers: gen_code__to_strbuilder_ptr,     \
	    gen_CodeStruct: gen_code__to_strbuilder_ptr,         \
	    gen_CodeTemplate: gen_code__to_strbuilder_ptr,       \
	    gen_CodeTypename: gen_code__to_strbuilder_ptr,       \
	    gen_CodeTypedef: gen_code__to_strbuilder_ptr,        \
	    gen_CodeUnion: gen_code__to_strbuilder_ptr,          \
	    gen_CodeUsing: gen_code__to_strbuilder_ptr,          \
	    gen_CodeVar: gen_code__to_strbuilder_ptr,            \
	    default: gen_generic_selection_fail                  \
	) GEN_RESOLVED_FUNCTION_CALL((gen_Code)code, result)

#define gen_code_type_str(code)                     \
	_Generic(                                       \
	    (code),                                     \
	    gen_Code: gen_code__type_str,               \
	    gen_CodeBody: gen_code__type_str,           \
	    gen_CodeAttributes: gen_code__type_str,     \
	    gen_CodeComment: gen_code__type_str,        \
	    gen_CodeClass: gen_code__type_str,          \
	    gen_CodeConstructor: gen_code__type_str,    \
	    gen_CodeDefine: gen_code__type_str,         \
	    gen_CodeDefineParams: gen_code__type_str,   \
	    gen_CodeDestructor: gen_code__type_str,     \
	    gen_CodeEnum: gen_code__type_str,           \
	    gen_CodeExec: gen_code__type_str,           \
	    gen_CodeExtern: gen_code__type_str,         \
	    gen_CodeInclude: gen_code__type_str,        \
	    gen_CodeFriend: gen_code__type_str,         \
	    gen_CodeFn: gen_code__type_str,             \
	    gen_CodeModule: gen_code__type_str,         \
	    gen_CodeNS: gen_code__type_str,             \
	    gen_CodeOperator: gen_code__type_str,       \
	    gen_CodeOpCast: gen_code__type_str,         \
	    gen_CodePragma: gen_code__type_str,         \
	    gen_CodeParams: gen_code__type_str,         \
	    gen_CodePreprocessCond: gen_code__type_str, \
	    gen_CodeSpecifiers: gen_code__type_str,     \
	    gen_CodeStruct: gen_code__type_str,         \
	    gen_CodeTemplate: gen_code__type_str,       \
	    gen_CodeTypename: gen_code__type_str,       \
	    gen_CodeTypedef: gen_code__type_str,        \
	    gen_CodeUnion: gen_code__type_str,          \
	    gen_CodeUsing: gen_code__type_str,          \
	    gen_CodeVar: gen_code__type_str,            \
	    default: gen_generic_selection_fail         \
	) GEN_RESOLVED_FUNCTION_CALL((gen_Code)code)

#define gen_code_validate_body(code)                     \
	_Generic(                                            \
	    (code),                                          \
	    gen_Code: gen_code__validate_body,               \
	    gen_CodeBody: gen_code__validate_body,           \
	    gen_CodeAttributes: gen_code__validate_body,     \
	    gen_CodeComment: gen_code__validate_body,        \
	    gen_CodeClass: gen_code__validate_body,          \
	    gen_CodeConstructor: gen_code__validate_body,    \
	    gen_CodeDefine: gen_code__validate_body,         \
	    gen_CodeDefineParams: gen_code__validate_body,   \
	    gen_CodeDestructor: gen_code__validate_body,     \
	    gen_CodeEnum: gen_code__validate_body,           \
	    gen_CodeExec: gen_code__validate_body,           \
	    gen_CodeExtern: gen_code__validate_body,         \
	    gen_CodeInclude: gen_code__validate_body,        \
	    gen_CodeFriend: gen_code__validate_body,         \
	    gen_CodeFn: gen_code__validate_body,             \
	    gen_CodeModule: gen_code__validate_body,         \
	    gen_CodeNS: gen_code__validate_body,             \
	    gen_CodeOperator: gen_code__validate_body,       \
	    gen_CodeOpCast: gen_code__validate_body,         \
	    gen_CodePragma: gen_code__validate_body,         \
	    gen_CodeParams: gen_code__validate_body,         \
	    gen_CodePreprocessCond: gen_code__validate_body, \
	    gen_CodeSpecifiers: gen_code__validate_body,     \
	    gen_CodeStruct: gen_code__validate_body,         \
	    gen_CodeTemplate: gen_code__validate_body,       \
	    gen_CodeTypename: gen_code__validate_body,       \
	    gen_CodeTypedef: gen_code__validate_body,        \
	    gen_CodeUnion: gen_code__validate_body,          \
	    gen_CodeUsing: gen_code__validate_body,          \
	    gen_CodeVar: gen_code__validate_body,            \
	    default: gen_generic_selection_fail              \
	) GEN_RESOLVED_FUNCTION_CALL((gen_Code)code)



GEN_API void           gen_body_append(gen_CodeBody body, gen_Code other);
GEN_API void           gen_body_append_body(gen_CodeBody body, gen_CodeBody other);
GEN_API gen_StrBuilder gen_body_to_strbuilder(gen_CodeBody body);
GEN_API void           gen_body_to_strbuilder_ref(gen_CodeBody body, gen_StrBuilder* result);
GEN_API void           gen_body_to_strbuilder_export(gen_CodeBody body, gen_StrBuilder* result);

GEN_API gen_Code gen_begin_CodeBody(gen_CodeBody body);
GEN_API gen_Code gen_end_CodeBody(gen_CodeBody body);
GEN_API gen_Code gen_next_CodeBody(gen_CodeBody body, gen_Code entry_iter);

GEN_API void           gen_class_add_interface(gen_CodeClass self, gen_CodeTypename interface);
GEN_API gen_StrBuilder gen_class_to_strbuilder(gen_CodeClass self);
GEN_API void           gen_class_to_strbuilder_def(gen_CodeClass self, gen_StrBuilder* result);
GEN_API void           gen_class_to_strbuilder_fwd(gen_CodeClass self, gen_StrBuilder* result);

GEN_API void                 gen_define_params_append(gen_CodeDefineParams appendee, gen_CodeDefineParams other);
GEN_API gen_CodeDefineParams gen_define_params_get(gen_CodeDefineParams params, gen_s32 idx);
GEN_API bool                 gen_define_params_has_entries(gen_CodeDefineParams params);
GEN_API gen_StrBuilder       gen_define_params_to_strbuilder(gen_CodeDefineParams params);
GEN_API void                 gen_define_params_to_strbuilder_ref(gen_CodeDefineParams params, gen_StrBuilder* result);

GEN_API gen_CodeDefineParams gen_begin_CodeDefineParams(gen_CodeDefineParams params);
GEN_API gen_CodeDefineParams gen_end_CodeDefineParams(gen_CodeDefineParams params);
GEN_API gen_CodeDefineParams gen_next_CodeDefineParams(gen_CodeDefineParams params, gen_CodeDefineParams entry_iter);

GEN_API void           gen_params_append(gen_CodeParams appendee, gen_CodeParams other);
GEN_API gen_CodeParams gen_params_get(gen_CodeParams params, gen_s32 idx);
GEN_API bool           gen_params_has_entries(gen_CodeParams params);
GEN_API gen_StrBuilder gen_params_to_strbuilder(gen_CodeParams params);
GEN_API void           gen_params_to_strbuilder_ref(gen_CodeParams params, gen_StrBuilder* result);

GEN_API gen_CodeParams gen_begin_CodeParams(gen_CodeParams params);
GEN_API gen_CodeParams gen_end_CodeParams(gen_CodeParams params);
GEN_API gen_CodeParams gen_next_CodeParams(gen_CodeParams params, gen_CodeParams entry_iter);

GEN_API bool           gen_specifiers_append(gen_CodeSpecifiers specifiers, gen_Specifier spec);
GEN_API gen_s32        gen_specifiers_has(gen_CodeSpecifiers specifiers, gen_Specifier spec);
GEN_API gen_s32        gen_specifiers_remove(gen_CodeSpecifiers specifiers, gen_Specifier to_remove);
GEN_API gen_StrBuilder gen_specifiers_to_strbuilder(gen_CodeSpecifiers specifiers);
GEN_API void           gen_specifiers_to_strbuilder_ref(gen_CodeSpecifiers specifiers, gen_StrBuilder* result);

GEN_API gen_Specifier* gen_begin_CodeSpecifiers(gen_CodeSpecifiers specifiers);
GEN_API gen_Specifier* gen_end_CodeSpecifiers(gen_CodeSpecifiers specifiers);
GEN_API gen_Specifier* gen_next_CodeSpecifiers(gen_CodeSpecifiers specifiers, gen_Specifier* gen_spec_iter);

GEN_API void           gen_struct_add_interface(gen_CodeStruct self, gen_CodeTypename interface);
GEN_API gen_StrBuilder gen_struct_to_strbuilder(gen_CodeStruct self);
GEN_API void           gen_struct_to_strbuilder_fwd(gen_CodeStruct self, gen_StrBuilder* result);
GEN_API void           gen_struct_to_strbuilder_def(gen_CodeStruct self, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_attributes_to_strbuilder(gen_CodeAttributes attributes);
GEN_API void           gen_attributes_to_strbuilder_ref(gen_CodeAttributes attributes, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_comment_to_strbuilder(gen_CodeComment comment);
GEN_API void           gen_comment_to_strbuilder_ref(gen_CodeComment comment, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_constructor__to_strbuilder(gen_CodeConstructor gen_constructor_);
GEN_API void           gen_constructor__to_strbuilder_def(gen_CodeConstructor gen_constructor_, gen_StrBuilder* result);
GEN_API void           gen_constructor__to_strbuilder_fwd(gen_CodeConstructor gen_constructor_, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_define_to_strbuilder(gen_CodeDefine self);
GEN_API void           gen_define_to_strbuilder_ref(gen_CodeDefine self, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_destructor__to_strbuilder(gen_CodeDestructor gen_destructor_);
GEN_API void           gen_destructor__to_strbuilder_fwd(gen_CodeDestructor gen_destructor_, gen_StrBuilder* result);
GEN_API void           gen_destructor__to_strbuilder_def(gen_CodeDestructor gen_destructor_, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_enum_to_strbuilder(gen_CodeEnum self);
GEN_API void           gen_enum_to_strbuilder_def(gen_CodeEnum self, gen_StrBuilder* result);
GEN_API void           gen_enum_to_strbuilder_fwd(gen_CodeEnum self, gen_StrBuilder* result);
GEN_API void           gen_enum_to_strbuilder_class_def(gen_CodeEnum self, gen_StrBuilder* result);
GEN_API void           gen_enum_to_strbuilder_class_fwd(gen_CodeEnum self, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_exec_to_strbuilder(gen_CodeExec exec);
GEN_API void           gen_exec_to_strbuilder_ref(gen_CodeExec exec, gen_StrBuilder* result);

GEN_API void gen_extern_to_strbuilder(gen_CodeExtern self, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_include_to_strbuilder(gen_CodeInclude self);
GEN_API void           gen_include_to_strbuilder_ref(gen_CodeInclude self, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_friend_to_strbuilder(gen_CodeFriend self);
GEN_API void           gen_friend_to_strbuilder_ref(gen_CodeFriend self, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_fn_to_strbuilder(gen_CodeFn self);
GEN_API void           gen_fn_to_strbuilder_def(gen_CodeFn self, gen_StrBuilder* result);
GEN_API void           gen_fn_to_strbuilder_fwd(gen_CodeFn self, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_module_to_strbuilder(gen_CodeModule self);
GEN_API void           gen_module_to_strbuilder_ref(gen_CodeModule self, gen_StrBuilder* result);

GEN_API gen_StrBuilder namespace_to_strbuilder(gen_CodeNS self);
GEN_API void           namespace_to_strbuilder_ref(gen_CodeNS self, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_code_op_to_strbuilder(gen_CodeOperator self);
GEN_API void           gen_code_op_to_strbuilder_fwd(gen_CodeOperator self, gen_StrBuilder* result);
GEN_API void           gen_code_op_to_strbuilder_def(gen_CodeOperator self, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_opcast_to_strbuilder(gen_CodeOpCast op_cast);
GEN_API void           gen_opcast_to_strbuilder_def(gen_CodeOpCast op_cast, gen_StrBuilder* result);
GEN_API void           gen_opcast_to_strbuilder_fwd(gen_CodeOpCast op_cast, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_pragma_to_strbuilder(gen_CodePragma self);
GEN_API void           gen_pragma_to_strbuilder_ref(gen_CodePragma self, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_preprocess_to_strbuilder(gen_CodePreprocessCond cond);
GEN_API void           gen_preprocess_to_strbuilder_if(gen_CodePreprocessCond cond, gen_StrBuilder* result);
GEN_API void           gen_preprocess_to_strbuilder_ifdef(gen_CodePreprocessCond cond, gen_StrBuilder* result);
GEN_API void           gen_preprocess_to_strbuilder_ifndef(gen_CodePreprocessCond cond, gen_StrBuilder* result);
GEN_API void           gen_preprocess_to_strbuilder_elif(gen_CodePreprocessCond cond, gen_StrBuilder* result);
GEN_API void           gen_preprocess_to_strbuilder_else(gen_CodePreprocessCond cond, gen_StrBuilder* result);
GEN_API void           gen_preprocess_to_strbuilder_endif(gen_CodePreprocessCond cond, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_template_to_strbuilder(gen_CodeTemplate self);
GEN_API void           gen_template_to_strbuilder_ref(gen_CodeTemplate self, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_typename_to_strbuilder(gen_CodeTypename self);
GEN_API void           gen_typename_to_strbuilder_ref(gen_CodeTypename self, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_typedef_to_strbuilder(gen_CodeTypedef self);
GEN_API void           gen_typedef_to_strbuilder_ref(gen_CodeTypedef self, gen_StrBuilder* result);

GEN_API gen_StrBuilder union_to_strbuilder(gen_CodeUnion self);
GEN_API void           union_to_strbuilder_def(gen_CodeUnion self, gen_StrBuilder* result);
GEN_API void           union_to_strbuilder_fwd(gen_CodeUnion self, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_using_to_strbuilder(gen_CodeUsing op_cast);
GEN_API void           gen_using_to_strbuilder_ref(gen_CodeUsing op_cast, gen_StrBuilder* result);
GEN_API void           gen_using_to_strbuilder_ns(gen_CodeUsing op_cast, gen_StrBuilder* result);

GEN_API gen_StrBuilder gen_var_to_strbuilder(gen_CodeVar self);
GEN_API void           gen_var_to_strbuilder_ref(gen_CodeVar self, gen_StrBuilder* result);

#pragma endregion gen_Code Type C - Interface

#pragma region gen_AST Types

/*
  ______   ______  ________      ________
 /      \ /      \|        \    |        \
|  ▓▓▓▓▓▓\  ▓▓▓▓▓▓\\▓▓▓▓▓▓▓▓     \▓▓▓▓▓▓▓▓__    __  ______   ______   _______
| ▓▓__| ▓▓ ▓▓___\▓▓  | ▓▓          | ▓▓  |  \  |  \/      \ /      \ /       \
| ▓▓    ▓▓\▓▓    \   | ▓▓          | ▓▓  | ▓▓  | ▓▓  ▓▓▓▓▓▓\  ▓▓▓▓▓▓\  ▓▓▓▓▓▓▓
| ▓▓▓▓▓▓▓▓_\▓▓▓▓▓▓\  | ▓▓          | ▓▓  | ▓▓  | ▓▓ ▓▓  | ▓▓ ▓▓    ▓▓\▓▓    \
| ▓▓  | ▓▓  \__| ▓▓  | ▓▓          | ▓▓  | ▓▓__/ ▓▓ ▓▓__/ ▓▓ ▓▓▓▓▓▓▓▓_\▓▓▓▓▓▓\
| ▓▓  | ▓▓\▓▓    ▓▓  | ▓▓          | ▓▓   \▓▓    ▓▓ ▓▓    ▓▓\▓▓     \       ▓▓
 \▓▓   \▓▓ \▓▓▓▓▓▓    \▓▓           \▓▓   _\▓▓▓▓▓▓▓ ▓▓▓▓▓▓▓  \▓▓▓▓▓▓▓\▓▓▓▓▓▓▓
                                         |  \__| ▓▓ ▓▓
                                          \▓▓    ▓▓ ▓▓
                                           \▓▓▓▓▓▓ \▓▓
*/

/*
	Show only relevant members of the gen_AST for its type.
	gen_AST* fields are replaced with gen_Code types.
		- Guards assignemnts to gen_AST* fields to ensure the gen_AST is duplicated if assigned to another parent.
*/

struct gen_AST_Body
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C
	};

	gen_StrCached Name;
	gen_Code      Front;
	gen_Code      Back;
	gen_Token*    Tok;
	gen_Code      Parent;
	gen_CodeType  Type;
	char          _PAD_UNUSED_[sizeof(gen_ModuleFlag)];
	gen_s32       NumEntries;
};
typedef struct gen_AST_Body gen_AST_Body;
gen_static_assert(sizeof(gen_AST_Body) == sizeof(gen_AST), "ERROR: gen_AST_Body is not the same size as gen_AST");

// TODO(Ed): Support chaining attributes (Use parameter linkage pattern)
struct gen_AST_Attributes
{
	union
	{
		char          _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C
		gen_StrCached Content;
	};

	gen_StrCached Name;
	gen_Code      Prev;
	gen_Code      Next;
	gen_Token*    Tok;
	gen_Code      Parent;
	gen_CodeType  Type;
	char          _PAD_UNUSED_[sizeof(gen_ModuleFlag) + sizeof(gen_u32)];
};
typedef struct gen_AST_Attributes gen_AST_Attributes;
gen_static_assert(sizeof(gen_AST_Attributes) == sizeof(gen_AST), "ERROR: gen_AST_Attributes is not the same size as gen_AST");

#if 0
struct gen_AST_BaseClass
{
union 
{
char _PAD_[ 64 ];  // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

};
gen_StrCached Name;
gen_Code Prev;
gen_Code Next;
gen_Token *  Tok;
gen_Code Parent;
gen_CodeType Type;
char _PAD_UNUSED_[ sizeof(gen_ModuleFlag) + sizeof(gen_u32) ];

};
typedef struct gen_AST_BaseClass gen_AST_BaseClass;
gen_static_assert( sizeof(gen_AST_BaseClass) == sizeof(gen_AST), "ERROR: gen_AST_BaseClass is not the same size as gen_AST");
#endif

struct gen_AST_Comment
{
	union
	{
		char          _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C
		gen_StrCached Content;
	};

	gen_StrCached Name;
	gen_Code      Prev;
	gen_Code      Next;
	gen_Token*    Tok;
	gen_Code      Parent;
	gen_CodeType  Type;
	char          _PAD_UNUSED_[sizeof(gen_ModuleFlag) + sizeof(gen_u32)];
};
typedef struct gen_AST_Comment gen_AST_Comment;
gen_static_assert(sizeof(gen_AST_Comment) == sizeof(gen_AST), "ERROR: gen_AST_Comment is not the same size as gen_AST");

struct gen_AST_Class
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			gen_CodeComment    InlineCmt;    // Only supported by forward declarations
			gen_CodeAttributes Attributes;
			gen_CodeSpecifiers Specs;    // Support for final
			gen_CodeTypename   ParentType;
			char               _PAD_PARAMS_[sizeof(gen_AST*)];
			gen_CodeBody       Body;
			char               _PAD_PROPERTIES_2_[sizeof(gen_AST*)];
		};
	};

	gen_StrCached    Name;
	gen_CodeTypename Prev;
	gen_CodeTypename Next;
	gen_Token*       Tok;
	gen_Code         Parent;
	gen_CodeType     Type;
	gen_ModuleFlag   ModuleFlags;
	gen_AccessSpec   ParentAccess;
};
typedef struct gen_AST_Class gen_AST_Class;
gen_static_assert(sizeof(gen_AST_Class) == sizeof(gen_AST), "ERROR: gen_AST_Class is not the same size as gen_AST");

struct gen_AST_Constructor
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			gen_CodeComment    InlineCmt;    // Only supported by forward declarations
			char               _PAD_PROPERTIES_[sizeof(gen_AST*) * 1];
			gen_CodeSpecifiers Specs;
			gen_Code           InitializerList;
			gen_CodeParams     Params;
			gen_Code           Body;
			char               _PAD_PROPERTIES_2_[sizeof(gen_AST*) * 2];
		};
	};

	gen_StrCached Name;
	gen_Code      Prev;
	gen_Code      Next;
	gen_Token*    Tok;
	gen_Code      Parent;
	gen_CodeType  Type;
	char          _PAD_UNUSED_[sizeof(gen_ModuleFlag) + sizeof(gen_u32)];
};
typedef struct gen_AST_Constructor gen_AST_Constructor;
gen_static_assert(sizeof(gen_AST_Constructor) == sizeof(gen_AST), "ERROR: gen_AST_Constructor is not the same size as gen_AST");

struct gen_AST_Define
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			char                 _PAD_PROPERTIES_[sizeof(gen_AST*) * 4];
			gen_CodeDefineParams Params;
			gen_Code             Body;    // Should be completely serialized for now to a: gen_StrCached Content.
			char                 _PAD_PROPERTIES_2_[sizeof(gen_AST*) * 1];
		};
	};

	gen_StrCached Name;
	gen_Code      Prev;
	gen_Code      Next;
	gen_Token*    Tok;
	gen_Code      Parent;
	gen_CodeType  Type;
	char          _PAD_UNUSED_[sizeof(gen_ModuleFlag) + sizeof(gen_u32)];
};
typedef struct gen_AST_Define gen_AST_Define;
gen_static_assert(sizeof(gen_AST_Define) == sizeof(gen_AST), "ERROR: gen_AST_Define is not the same size as gen_AST");

struct gen_AST_DefineParams
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C
	};

	gen_StrCached        Name;
	gen_CodeDefineParams Last;
	gen_CodeDefineParams Next;
	gen_Token*           Tok;
	gen_Code             Parent;
	gen_CodeType         Type;
	char                 _PAD_UNUSED_[sizeof(gen_ModuleFlag)];
	gen_s32              NumEntries;
};
typedef struct gen_AST_DefineParams gen_AST_DefineParams;
gen_static_assert(sizeof(gen_AST_DefineParams) == sizeof(gen_AST), "ERROR: gen_AST_DefineParams is not the same size as gen_AST");

struct gen_AST_Destructor
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			gen_CodeComment    InlineCmt;
			char               _PAD_PROPERTIES_[sizeof(gen_AST*) * 1];
			gen_CodeSpecifiers Specs;
			char               _PAD_PROPERTIES_2_[sizeof(gen_AST*) * 2];
			gen_Code           Body;
			char               _PAD_PROPERTIES_3_[sizeof(gen_AST*)];
		};
	};

	gen_StrCached Name;
	gen_Code      Prev;
	gen_Code      Next;
	gen_Token*    Tok;
	gen_Code      Parent;
	gen_CodeType  Type;
	char          _PAD_UNUSED_[sizeof(gen_ModuleFlag) + sizeof(gen_u32)];
};
typedef struct gen_AST_Destructor gen_AST_Destructor;
gen_static_assert(sizeof(gen_AST_Destructor) == sizeof(gen_AST), "ERROR: gen_AST_Destructor is not the same size as gen_AST");

struct gen_AST_Enum
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			gen_CodeComment    InlineCmt;
			gen_CodeAttributes Attributes;
			char               _PAD_SPEC_[sizeof(gen_AST*)];
			gen_CodeTypename   UnderlyingType;
			gen_Code           UnderlyingTypeMacro;
			gen_CodeBody       Body;
			char               _PAD_PROPERTIES_2_[sizeof(gen_AST*)];
		};
	};

	gen_StrCached  Name;
	gen_Code       Prev;
	gen_Code       Next;
	gen_Token*     Tok;
	gen_Code       Parent;
	gen_CodeType   Type;
	gen_ModuleFlag ModuleFlags;
	char           _PAD_UNUSED_[sizeof(gen_ModuleFlag) + sizeof(gen_u32)];
};
typedef struct gen_AST_Enum gen_AST_Enum;
gen_static_assert(sizeof(gen_AST_Enum) == sizeof(gen_AST), "ERROR: gen_AST_Enum is not the same size as gen_AST");

struct gen_AST_Exec
{
	union
	{
		char          _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C
		gen_StrCached Content;
	};

	gen_StrCached Name;
	gen_Code      Prev;
	gen_Code      Next;
	gen_Token*    Tok;
	gen_Code      Parent;
	gen_CodeType  Type;
	char          _PAD_UNUSED_[sizeof(gen_ModuleFlag) + sizeof(gen_u32)];
};
typedef struct gen_AST_Exec gen_AST_Exec;
gen_static_assert(sizeof(gen_AST_Exec) == sizeof(gen_AST), "ERROR: gen_AST_Exec is not the same size as gen_AST");

struct gen_AST_Extern
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			char         _PAD_PROPERTIES_[sizeof(gen_AST*) * 5];
			gen_CodeBody Body;
			char         _PAD_PROPERTIES_2_[sizeof(gen_AST*)];
		};
	};

	gen_StrCached Name;
	gen_Code      Prev;
	gen_Code      Next;
	gen_Token*    Tok;
	gen_Code      Parent;
	gen_CodeType  Type;
	char          _PAD_UNUSED_[sizeof(gen_ModuleFlag) + sizeof(gen_u32)];
};
typedef struct gen_AST_Extern gen_AST_Extern;
gen_static_assert(sizeof(gen_AST_Extern) == sizeof(gen_AST), "ERROR: gen_AST_Extern is not the same size as gen_AST");

struct gen_AST_Include
{
	union
	{
		char          _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C
		gen_StrCached Content;
	};

	gen_StrCached Name;
	gen_Code      Prev;
	gen_Code      Next;
	gen_Token*    Tok;
	gen_Code      Parent;
	gen_CodeType  Type;
	char          _PAD_UNUSED_[sizeof(gen_ModuleFlag) + sizeof(gen_u32)];
};
typedef struct gen_AST_Include gen_AST_Include;
gen_static_assert(sizeof(gen_AST_Include) == sizeof(gen_AST), "ERROR: gen_AST_Include is not the same size as gen_AST");

struct gen_AST_Friend
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			gen_CodeComment InlineCmt;
			char            _PAD_PROPERTIES_[sizeof(gen_AST*) * 4];
			gen_Code        Declaration;
			char            _PAD_PROPERTIES_2_[sizeof(gen_AST*)];
		};
	};

	gen_StrCached Name;
	gen_Code      Prev;
	gen_Code      Next;
	gen_Token*    Tok;
	gen_Code      Parent;
	gen_CodeType  Type;
	char          _PAD_UNUSED_[sizeof(gen_ModuleFlag) + sizeof(gen_u32)];
};
typedef struct gen_AST_Friend gen_AST_Friend;
gen_static_assert(sizeof(gen_AST_Friend) == sizeof(gen_AST), "ERROR: gen_AST_Friend is not the same size as gen_AST");

struct gen_AST_Fn
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			gen_CodeComment    InlineCmt;
			gen_CodeAttributes Attributes;
			gen_CodeSpecifiers Specs;
			gen_CodeTypename   ReturnType;
			gen_CodeParams     Params;
			gen_CodeBody       Body;
			gen_Code           SuffixSpecs;    // Thanks Unreal
		};
	};

	gen_StrCached  Name;
	gen_Code       Prev;
	gen_Code       Next;
	gen_Token*     Tok;
	gen_Code       Parent;
	gen_CodeType   Type;
	gen_ModuleFlag ModuleFlags;
	char           _PAD_UNUSED_[sizeof(gen_u32)];
};
typedef struct gen_AST_Fn gen_AST_Fn;
gen_static_assert(sizeof(gen_AST_Fn) == sizeof(gen_AST), "ERROR: gen_AST_Fn is not the same size as gen_AST");

struct gen_AST_Module
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C
	};

	gen_StrCached  Name;
	gen_Code       Prev;
	gen_Code       Next;
	gen_Token*     Tok;
	gen_Code       Parent;
	gen_CodeType   Type;
	gen_ModuleFlag ModuleFlags;
	char           _PAD_UNUSED_[sizeof(gen_u32)];
};
typedef struct gen_AST_Module gen_AST_Module;
gen_static_assert(sizeof(gen_AST_Module) == sizeof(gen_AST), "ERROR: gen_AST_Module is not the same size as gen_AST");

struct gen_AST_NS
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			char         _PAD_PROPERTIES_[sizeof(gen_AST*) * 5];
			gen_CodeBody Body;
			char         _PAD_PROPERTIES_2_[sizeof(gen_AST*)];
		};
	};

	gen_StrCached  Name;
	gen_Code       Prev;
	gen_Code       Next;
	gen_Token*     Tok;
	gen_Code       Parent;
	gen_CodeType   Type;
	gen_ModuleFlag ModuleFlags;
	char           _PAD_UNUSED_[sizeof(gen_u32)];
};
typedef struct gen_AST_NS gen_AST_NS;
gen_static_assert(sizeof(gen_AST_NS) == sizeof(gen_AST), "ERROR: gen_AST_NS is not the same size as gen_AST");

struct gen_AST_Operator
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			gen_CodeComment    InlineCmt;
			gen_CodeAttributes Attributes;
			gen_CodeSpecifiers Specs;
			gen_CodeTypename   ReturnType;
			gen_CodeParams     Params;
			gen_CodeBody       Body;
			char               _PAD_PROPERTIES_[sizeof(gen_AST*)];
		};
	};

	gen_StrCached  Name;
	gen_Code       Prev;
	gen_Code       Next;
	gen_Token*     Tok;
	gen_Code       Parent;
	gen_CodeType   Type;
	gen_ModuleFlag ModuleFlags;
	gen_Operator   Op;
};
typedef struct gen_AST_Operator gen_AST_Operator;
gen_static_assert(sizeof(gen_AST_Operator) == sizeof(gen_AST), "ERROR: gen_AST_Operator is not the same size as gen_AST");

struct gen_AST_OpCast
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			gen_CodeComment    InlineCmt;
			char               _PAD_PROPERTIES_[sizeof(gen_AST*)];
			gen_CodeSpecifiers Specs;
			gen_CodeTypename   ValueType;
			char               _PAD_PROPERTIES_2_[sizeof(gen_AST*)];
			gen_CodeBody       Body;
			char               _PAD_PROPERTIES_3_[sizeof(gen_AST*)];
		};
	};

	gen_StrCached Name;
	gen_Code      Prev;
	gen_Code      Next;
	gen_Token*    Tok;
	gen_Code      Parent;
	gen_CodeType  Type;
	char          _PAD_UNUSED_[sizeof(gen_ModuleFlag) + sizeof(gen_u32)];
};
typedef struct gen_AST_OpCast gen_AST_OpCast;
gen_static_assert(sizeof(gen_AST_OpCast) == sizeof(gen_AST), "ERROR: gen_AST_OpCast is not the same size as gen_AST");

struct gen_AST_Params
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			// TODO(Ed): Support attributes for parameters (Some prefix macros can be converted to that...)
			char             _PAD_PROPERTIES_2_[sizeof(gen_AST*) * 3];
			gen_CodeTypename ValueType;
			gen_Code         gen_Macro;
			gen_Code         Value;
			gen_Code         PostNameMacro;    // Thanks Unreal
			// char     _PAD_PROPERTIES_3_[sizeof( gen_AST* )];
		};
	};

	gen_StrCached  Name;
	gen_CodeParams Last;
	gen_CodeParams Next;
	gen_Token*     Tok;
	gen_Code       Parent;
	gen_CodeType   Type;
	char           _PAD_UNUSED_[sizeof(gen_ModuleFlag)];
	gen_s32        NumEntries;
};
typedef struct gen_AST_Params gen_AST_Params;
gen_static_assert(sizeof(gen_AST_Params) == sizeof(gen_AST), "ERROR: gen_AST_Params is not the same size as gen_AST");

struct gen_AST_Pragma
{
	union
	{
		char          _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C
		gen_StrCached Content;
	};

	gen_StrCached Name;
	gen_Code      Prev;
	gen_Code      Next;
	gen_Token*    Tok;
	gen_Code      Parent;
	gen_CodeType  Type;
	char          _PAD_UNUSED_[sizeof(gen_ModuleFlag) + sizeof(gen_u32)];
};
typedef struct gen_AST_Pragma gen_AST_Pragma;
gen_static_assert(sizeof(gen_AST_Pragma) == sizeof(gen_AST), "ERROR: gen_AST_Pragma is not the same size as gen_AST");

struct gen_AST_PreprocessCond
{
	union
	{
		char          _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C
		gen_StrCached Content;
	};

	gen_StrCached Name;
	gen_Code      Prev;
	gen_Code      Next;
	gen_Token*    Tok;
	gen_Code      Parent;
	gen_CodeType  Type;
	char          _PAD_UNUSED_[sizeof(gen_ModuleFlag) + sizeof(gen_u32)];
};
typedef struct gen_AST_PreprocessCond gen_AST_PreprocessCond;
gen_static_assert(sizeof(gen_AST_PreprocessCond) == sizeof(gen_AST), "ERROR: gen_AST_PreprocessCond is not the same size as gen_AST");

struct gen_AST_Specifiers
{
	gen_Specifier      ArrSpecs[gen_AST_ArrSpecs_Cap];
	gen_StrCached      Name;
	gen_CodeSpecifiers NextSpecs;
	gen_Code           Prev;
	gen_Code           Next;
	gen_Token*         Tok;
	gen_Code           Parent;
	gen_CodeType       Type;
	char               _PAD_UNUSED_[sizeof(gen_ModuleFlag)];
	gen_s32            NumEntries;
};
typedef struct gen_AST_Specifiers gen_AST_Specifiers;
gen_static_assert(sizeof(gen_AST_Specifiers) == sizeof(gen_AST), "ERROR: gen_AST_Specifier is not the same size as gen_AST");

struct gen_AST_Struct
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			gen_CodeComment    InlineCmt;
			gen_CodeAttributes Attributes;
			gen_CodeSpecifiers Specs;    // Support for final
			gen_CodeTypename   ParentType;
			char               _PAD_PARAMS_[sizeof(gen_AST*)];
			gen_CodeBody       Body;
			char               _PAD_PROPERTIES_2_[sizeof(gen_AST*)];
		};
	};

	gen_StrCached    Name;
	gen_CodeTypename Prev;
	gen_CodeTypename Next;
	gen_Token*       Tok;
	gen_Code         Parent;
	gen_CodeType     Type;
	gen_ModuleFlag   ModuleFlags;
	gen_AccessSpec   ParentAccess;
};
typedef struct gen_AST_Struct gen_AST_Struct;
gen_static_assert(sizeof(gen_AST_Struct) == sizeof(gen_AST), "ERROR: gen_AST_Struct is not the same size as gen_AST");

struct gen_AST_Template
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			char           _PAD_PROPERTIES_[sizeof(gen_AST*) * 4];
			gen_CodeParams Params;
			gen_Code       Declaration;
			char           _PAD_PROPERTIES_2_[sizeof(gen_AST*)];
		};
	};

	gen_StrCached  Name;
	gen_Code       Prev;
	gen_Code       Next;
	gen_Token*     Tok;
	gen_Code       Parent;
	gen_CodeType   Type;
	gen_ModuleFlag ModuleFlags;
	char           _PAD_UNUSED_[sizeof(gen_u32)];
};
typedef struct gen_AST_Template gen_AST_Template;
gen_static_assert(sizeof(gen_AST_Template) == sizeof(gen_AST), "ERROR: gen_AST_Template is not the same size as gen_AST");

#if 0
// WIP... The type ast is going to become more advanced and lead to a major change to gen_AST design.
struct gen_AST_Type
{
union 
{
char _PAD_[ 64 ];  // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C
struct 
{
char _PAD_INLINE_CMT_[ sizeof(gen_AST*) ];
gen_CodeAttributes Attributes;
gen_CodeSpecifiers Specs;
gen_Code QualifierID;
// gen_CodeTypename ReturnType;      // Only used for function signatures
// gen_CodeParams    Params;          // Only used for function signatures
gen_Code ArrExpr;
// gen_CodeSpecifiers SpecsFuncSuffix; // Only used for function signatures

};

};
gen_StrCached Name;
gen_Code Prev;
gen_Code Next;
gen_Token *  Tok;
gen_Code Parent;
gen_CodeType Type;
char _PAD_UNUSED_[ sizeof(gen_ModuleFlag) ];
gen_b32 IsParamPack;

};
typedef struct gen_AST_Type gen_AST_Type;
gen_static_assert( sizeof(gen_AST_Type) == sizeof(gen_AST), "ERROR: gen_AST_Type is not the same size as gen_AST");
#endif

struct gen_AST_Typename
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			char               _PAD_INLINE_CMT_[sizeof(gen_AST*)];
			gen_CodeAttributes Attributes;
			gen_CodeSpecifiers Specs;
			gen_CodeTypename   ReturnType;    // Only used for function signatures
			gen_CodeParams     Params;        // Only used for function signatures
			gen_Code           ArrExpr;
			gen_CodeSpecifiers SpecsFuncSuffix;    // Only used for function signatures
		};
	};

	gen_StrCached Name;
	gen_Code      Prev;
	gen_Code      Next;
	gen_Token*    Tok;
	gen_Code      Parent;
	gen_CodeType  Type;
	char          _PAD_UNUSED_[sizeof(gen_ModuleFlag)];

	struct
	{
		gen_b16          IsParamPack;    // Used by typename to know if type should be considered a parameter pack.
		gen_ETypenameTag TypeTag;        // Used by typename to keep track of explicitly declared tags for the identifier (enum, struct, union)
	};
};
typedef struct gen_AST_Typename gen_AST_Typename;
gen_static_assert(sizeof(gen_AST_Typename) == sizeof(gen_AST), "ERROR: gen_AST_Type is not the same size as gen_AST");

struct gen_AST_Typedef
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			gen_CodeComment InlineCmt;
			char            _PAD_PROPERTIES_[sizeof(gen_AST*) * 2];
			gen_Code        UnderlyingType;
			char            _PAD_PROPERTIES_2_[sizeof(gen_AST*) * 3];
		};
	};

	gen_StrCached  Name;
	gen_Code       Prev;
	gen_Code       Next;
	gen_Token*     Tok;
	gen_Code       Parent;
	gen_CodeType   Type;
	gen_ModuleFlag ModuleFlags;
	gen_b32        IsFunction;
};
typedef struct gen_AST_Typedef gen_AST_Typedef;
gen_static_assert(sizeof(gen_AST_Typedef) == sizeof(gen_AST), "ERROR: gen_AST_Typedef is not the same size as gen_AST");

struct gen_AST_Union
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			char               _PAD_INLINE_CMT_[sizeof(gen_AST*)];
			gen_CodeAttributes Attributes;
			char               _PAD_PROPERTIES_[sizeof(gen_AST*) * 3];
			gen_CodeBody       Body;
			char               _PAD_PROPERTIES_2_[sizeof(gen_AST*)];
		};
	};

	gen_StrCached  Name;
	gen_Code       Prev;
	gen_Code       Next;
	gen_Token*     Tok;
	gen_Code       Parent;
	gen_CodeType   Type;
	gen_ModuleFlag ModuleFlags;
	char           _PAD_UNUSED_[sizeof(gen_u32)];
};
typedef struct gen_AST_Union gen_AST_Union;
gen_static_assert(sizeof(gen_AST_Union) == sizeof(gen_AST), "ERROR: gen_AST_Union is not the same size as gen_AST");

struct gen_AST_Using
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			gen_CodeComment    InlineCmt;
			gen_CodeAttributes Attributes;
			char               _PAD_SPECS_[sizeof(gen_AST*)];
			gen_CodeTypename   UnderlyingType;
			char               _PAD_PROPERTIES_[sizeof(gen_AST*) * 3];
		};
	};

	gen_StrCached  Name;
	gen_Code       Prev;
	gen_Code       Next;
	gen_Token*     Tok;
	gen_Code       Parent;
	gen_CodeType   Type;
	gen_ModuleFlag ModuleFlags;
	char           _PAD_UNUSED_[sizeof(gen_u32)];
};
typedef struct gen_AST_Using gen_AST_Using;
gen_static_assert(sizeof(gen_AST_Using) == sizeof(gen_AST), "ERROR: gen_AST_Using is not the same size as gen_AST");

struct gen_AST_Var
{
	union
	{
		char _PAD_[64];    // Had to hardcode _PAD_ because (sizeof(gen_Specifier) * gen_AST_ArrSpecs_Cap + sizeof(gen_AST*)) was 67 bytes in C

		struct
		{
			gen_CodeComment    InlineCmt;
			gen_CodeAttributes Attributes;
			gen_CodeSpecifiers Specs;
			gen_CodeTypename   ValueType;
			gen_Code           BitfieldSize;
			gen_Code           Value;
			gen_CodeVar        NextVar;
		};
	};

	gen_StrCached  Name;
	gen_Code       Prev;
	gen_Code       Next;
	gen_Token*     Tok;
	gen_Code       Parent;
	gen_CodeType   Type;
	gen_ModuleFlag ModuleFlags;
	gen_s32        VarParenthesizedInit;
};
typedef struct gen_AST_Var gen_AST_Var;
gen_static_assert(sizeof(gen_AST_Var) == sizeof(gen_AST), "ERROR: gen_AST_Var is not the same size as gen_AST");

#pragma endregion gen_AST Types

#pragma endregion AST

#pragma region Gen Interface

/*
 /      \                       |      \          |  \                      /      \
|  ▓▓▓▓▓▓\ ______  _______       \▓▓▓▓▓▓_______  _| ▓▓_    ______   ______ |  ▓▓▓▓▓▓\ ______   _______  ______
| ▓▓ __\▓▓/      \|       \       | ▓▓ |       \|   ▓▓ \  /      \ /      \| ▓▓_  \▓▓|      \ /       \/      \
| ▓▓|    \  ▓▓▓▓▓▓\ ▓▓▓▓▓▓▓\      | ▓▓ | ▓▓▓▓▓▓▓\\▓▓▓▓▓▓ |  ▓▓▓▓▓▓\  ▓▓▓▓▓▓\ ▓▓ \     \▓▓▓▓▓▓\  ▓▓▓▓▓▓▓  ▓▓▓▓▓▓\
| ▓▓ \▓▓▓▓ ▓▓    ▓▓ ▓▓  | ▓▓      | ▓▓ | ▓▓  | ▓▓ | ▓▓ __| ▓▓    ▓▓ ▓▓   \▓▓ ▓▓▓▓    /      ▓▓ ▓▓     | ▓▓    ▓▓
| ▓▓__| ▓▓ ▓▓▓▓▓▓▓▓ ▓▓  | ▓▓     _| ▓▓_| ▓▓  | ▓▓ | ▓▓|  \ ▓▓▓▓▓▓▓▓ ▓▓     | ▓▓     |  ▓▓▓▓▓▓▓ ▓▓_____| ▓▓▓▓▓▓▓▓
 \▓▓    ▓▓\▓▓     \ ▓▓  | ▓▓    |   ▓▓ \ ▓▓  | ▓▓  \▓▓  ▓▓\▓▓     \ ▓▓     | ▓▓      \▓▓    ▓▓\▓▓     \\▓▓     \
  \▓▓▓▓▓▓  \▓▓▓▓▓▓▓\▓▓   \▓▓     \▓▓▓▓▓▓\▓▓   \▓▓   \▓▓▓▓  \▓▓▓▓▓▓▓\▓▓      \▓▓       \▓▓▓▓▓▓▓ \▓▓▓▓▓▓▓ \▓▓▓▓▓▓▓
*/


// Note(Ed): This is subject to heavily change
// with upcoming changes to the library's fallback (default) allocations strategy;
// and major changes to lexer/parser context usage.
struct gen_Context
{
	// User Configuration

	// Persistent Data Allocation
	gen_AllocatorInfo Allocator_DyanmicContainers;    // By default will use a genral slab allocator (TODO(Ed): Currently does not)
	gen_AllocatorInfo Allocator_Pool;                 // By default will use the growing vmem reserve (TODO(Ed): Currently does not)
	gen_AllocatorInfo Allocator_StrCache;             // By default will use a dedicated slab allocator (TODO(Ed): Currently does not)

	// Temporary Allocation
	gen_AllocatorInfo Allocator_Temp;

	// LoggerCallaback* log_callback; // TODO(Ed): Impl user logger callback as an option.

	// Initalization config
	gen_u32 Max_CommentLineLength;    // Used by gen_def_comment
	gen_u32 Max_StrCacheLength;       // Any cached string longer than this is always allocated again.

	gen_u32 InitSize_BuilderBuffer;
	gen_u32 InitSize_CodePoolsArray;
	gen_u32 InitSize_StringArenasArray;

	gen_u32 CodePool_NumBlocks;

	// TODO(Ed): Review these... (No longer needed if using the proper allocation strategy)
	gen_u32 InitSize_LexerTokens;
	gen_u32 SizePer_StringArena;

	// TODO(Ed): Symbol Table
	// Keep track of all resolved symbols (naemspaced identifiers)

	// Parser

	// Used by the lexer to persistently treat all these identifiers as preprocessor defines.
	// Populate with strings via gen::gen_cache_str.
	// Functional defines must have format: id( ;at minimum to indicate that the define is only valid with arguments.
	MacroTable Macros;

	// Backend

	// The fallback allocator is utilized if any fo the three above allocators is not specified by the user.
	gen_u32 InitSize_Fallback_Allocator_Bucket_Size;
	gen_Array(gen_Arena) Fallback_AllocatorBuckets;

	gen_StringTable gen_token_fmt_map;

	// gen_Array(gen_Token) LexerTokens;

	gen_Array(gen_Pool) CodePools;
	gen_Array(gen_Arena) StringArenas;

	gen_StringTable StrCache;

	// TODO(Ed): This needs to be just handled by a parser context
	gen_Array(gen_Token) gen_Lexer_Tokens;

	// TODO(Ed): Active parse context vs a parse result need to be separated conceptually
	gen_ParseContext parser;

	// TODO(Ed): Formatting - This will eventually be in a separate struct when in the process of serialization of the builder.
	gen_s32 temp_serialize_indent;
};
typedef struct gen_Context gen_Context;


// Initialize the library. There first ctx initialized must exist for lifetime of other contextes that come after as its the one that
GEN_API void gen_init(gen_Context* ctx);

// Currently manually free's the arenas, code for checking for leaks.
// However on Windows at least, it doesn't need to occur as the OS will clean up after the process.
GEN_API void gen_deinit(gen_Context* ctx);

// Retrieves the active context (not usually needed, but here in case...)
GEN_API gen_Context* get_context();

// Clears the allocations, but doesn't free the memoery, then calls gen_init() again.
// Ease of use.
GEN_API void gen_reset(gen_Context* ctx);

GEN_API void set_context(gen_Context* ctx);

// Mostly intended for the parser
GEN_API gen_Macro* lookup_macro(gen_Str Name);

// Alternative way to add a preprocess define entry for the lexer & parser to utilize
// if the user doesn't want to use gen_def_define
// Macros are tracked by name so if the name already exists the entry will be overwritten.
GEN_API void gen_register_macro(gen_Macro macro);

// Ease of use batch registration
GEN_API void gen_register_macros(gen_s32 num, ...);
GEN_API void gen_register_macros_arr(gen_s32 num, gen_Macro* macros);


// Used internally to retrive or make string allocations.
// Strings are stored in a series of string arenas of fixed size (SizePer_StringArena)
GEN_API gen_StrCached gen_cache_str(gen_Str str);

/*
	This provides a fresh gen_Code gen_AST.
	The gen interface use this as their method from getting a new gen_AST object from the CodePool.
	Use this if you want to make your own API for formatting the supported gen_Code Types.
*/
GEN_API gen_Code gen_make_code();

// Set these before calling gen's gen_init() procedure.

#pragma region Upfront


GEN_API gen_CodeAttributes gen_def_attributes(gen_Str content);
GEN_API gen_CodeComment    gen_def_comment(gen_Str content);

struct gen_Opts_def_struct
{
	gen_CodeBody       body;
	gen_CodeTypename   parent;
	gen_AccessSpec     parent_access;
	gen_CodeAttributes attributes;
	gen_CodeTypename*  interfaces;
	gen_s32            num_interfaces;
	gen_CodeSpecifiers specifiers;    // Only used for final specifier for now.
	gen_ModuleFlag     mflags;
};
typedef struct gen_Opts_def_struct gen_Opts_def_struct;

GEN_API gen_CodeClass gen_def__class(gen_Str name, gen_Opts_def_struct opts GEN_PARAM_DEFAULT);
#define gen_def_class(name, ...) gen_def__class(name, (gen_Opts_def_struct) { __VA_ARGS__ })

struct gen_Opts_def_constructor
{
	gen_CodeParams params;
	gen_Code       initializer_list;
	gen_Code       body;
};
typedef struct gen_Opts_def_constructor gen_Opts_def_constructor;

GEN_API gen_CodeConstructor gen_def__constructor(gen_Opts_def_constructor opts);
#define gen_def_constructor(...) gen_def__constructor((gen_Opts_def_constructor) { __VA_ARGS__ })

struct gen_Opts_def_define
{
	gen_CodeDefineParams params;
	gen_Str              content;
	gen_MacroFlags       flags;
	gen_b32              dont_register_to_preprocess_macros;
};
typedef struct gen_Opts_def_define gen_Opts_def_define;

GEN_API gen_CodeDefine gen_def__define(gen_Str name, gen_MacroType type, gen_Opts_def_define opts GEN_PARAM_DEFAULT);
#define gen_def_define(name, type, ...) gen_def__define(name, type, (gen_Opts_def_define) { __VA_ARGS__ })

struct gen_Opts_def_destructor
{
	gen_Code           body;
	gen_CodeSpecifiers specifiers;
};
typedef struct gen_Opts_def_destructor gen_Opts_def_destructor;

GEN_API gen_CodeDestructor gen_def__destructor(gen_Opts_def_destructor opts);
#define gen_def_destructor(...) gen_def__destructor((gen_Opts_def_destructor) { __VA_ARGS__ })

struct gen_Opts_def_enum
{
	gen_CodeBody       body;
	gen_CodeTypename   type;
	EnumT              specifier;
	gen_CodeAttributes attributes;
	gen_ModuleFlag     mflags;
	gen_Code           type_macro;
};
typedef struct gen_Opts_def_enum gen_Opts_def_enum;

GEN_API gen_CodeEnum gen_def__enum(gen_Str name, gen_Opts_def_enum opts GEN_PARAM_DEFAULT);
#define gen_def_enum(name, ...) gen_def__enum(name, (gen_Opts_def_enum) { __VA_ARGS__ })

GEN_API gen_CodeExec   gen_def_execution(gen_Str content);
GEN_API gen_CodeExtern gen_def_extern_link(gen_Str name, gen_CodeBody body);
GEN_API gen_CodeFriend gen_def_friend(gen_Code symbol);

struct gen_Opts_def_function
{
	gen_CodeParams     params;
	gen_CodeTypename   ret_type;
	gen_CodeBody       body;
	gen_CodeSpecifiers specs;
	gen_CodeAttributes attrs;
	gen_ModuleFlag     mflags;
};
typedef struct gen_Opts_def_function gen_Opts_def_function;

GEN_API gen_CodeFn gen_def__function(gen_Str name, gen_Opts_def_function opts GEN_PARAM_DEFAULT);
#define gen_def_function(name, ...) gen_def__function(name, (gen_Opts_def_function) { __VA_ARGS__ })

struct gen_Opts_def_include
{
	gen_b32 foreign;
};
typedef struct gen_Opts_def_include gen_Opts_def_include;

struct gen_Opts_def_module
{
	gen_ModuleFlag mflags;
};
typedef struct gen_Opts_def_module gen_Opts_def_module;

struct gen_Opts_def_namespace
{
	gen_ModuleFlag mflags;
};
typedef struct gen_Opts_def_namespace gen_Opts_def_namespace;

GEN_API gen_CodeInclude gen_def__include(gen_Str content, gen_Opts_def_include opts GEN_PARAM_DEFAULT);
#define gen_def_include(content, ...) gen_def__include(content, (gen_Opts_def_include) { __VA_ARGS__ })

GEN_API gen_CodeModule gen_def__module(gen_Str name, gen_Opts_def_module opts GEN_PARAM_DEFAULT);
#define gen_def_module(name, ...) gen_def__module(name, (gen_Opts_def_module) { __VA_ARGS__ })

GEN_API gen_CodeNS gen_def__namespace(gen_Str name, gen_CodeBody body, gen_Opts_def_namespace opts GEN_PARAM_DEFAULT);
#define gen_def_namespace(name, body, ...) gen_def__namespace(name, body, (gen_Opts_def_namespace) { __VA_ARGS__ })

struct gen_Opts_def_operator
{
	gen_CodeParams     params;
	gen_CodeTypename   ret_type;
	gen_CodeBody       body;
	gen_CodeSpecifiers specifiers;
	gen_CodeAttributes attributes;
	gen_ModuleFlag     mflags;
};
typedef struct gen_Opts_def_operator gen_Opts_def_operator;

GEN_API gen_CodeOperator gen_def__operator(gen_Operator op, gen_Str nspace, gen_Opts_def_operator opts GEN_PARAM_DEFAULT);
#define gen_def_operator(op, nspace, ...) gen_def__operator(op, nspace, (gen_Opts_def_operator) { __VA_ARGS__ })

struct gen_Opts_def_operator_cast
{
	gen_CodeBody       body;
	gen_CodeSpecifiers specs;
};
typedef struct gen_Opts_def_operator_cast gen_Opts_def_operator_cast;

GEN_API gen_CodeOpCast gen_def__operator_cast(gen_CodeTypename type, gen_Opts_def_operator_cast opts GEN_PARAM_DEFAULT);
#define gen_def_operator_cast(type, ...) gen_def__operator_cast(type, (gen_Opts_def_operator_cast) { __VA_ARGS__ })

struct gen_Opts_def_param
{
	gen_Code value;
};
typedef struct gen_Opts_def_param gen_Opts_def_param;

GEN_API gen_CodeParams gen_def__param(gen_CodeTypename type, gen_Str name, gen_Opts_def_param opts GEN_PARAM_DEFAULT);
#define gen_def_param(type, name, ...) gen_def__param(type, name, (gen_Opts_def_param) { __VA_ARGS__ })

GEN_API gen_CodePragma gen_def_pragma(gen_Str directive);

GEN_API gen_CodePreprocessCond gen_def_preprocess_cond(gen_EPreprocessCOnd type, gen_Str content);

GEN_API gen_CodeSpecifiers gen_def_specifier(gen_Specifier specifier);

GEN_API gen_CodeStruct gen_def__struct(gen_Str name, gen_Opts_def_struct opts GEN_PARAM_DEFAULT);
#define gen_def_struct(name, ...) gen_def__struct(name, (gen_Opts_def_struct) { __VA_ARGS__ })

struct gen_Opts_def_template
{
	gen_ModuleFlag mflags;
};
typedef struct gen_Opts_def_template gen_Opts_def_template;

GEN_API gen_CodeTemplate gen_def__template(gen_CodeParams params, gen_Code definition, gen_Opts_def_template opts GEN_PARAM_DEFAULT);
#define gen_def_template(params, definition, ...) gen_def__template(params, definition, (gen_Opts_def_template) { __VA_ARGS__ })

struct gen_Opts_def_type
{
	gen_ETypenameTag   type_tag;
	gen_Code           arrayexpr;
	gen_CodeSpecifiers specifiers;
	gen_CodeAttributes attributes;
};
typedef struct gen_Opts_def_type gen_Opts_def_type;

GEN_API gen_CodeTypename gen_def__type(gen_Str name, gen_Opts_def_type opts GEN_PARAM_DEFAULT);
#define gen_def_type(name, ...) gen_def__type(name, (gen_Opts_def_type) { __VA_ARGS__ })

struct gen_Opts_def_typedef
{
	gen_CodeAttributes attributes;
	gen_ModuleFlag     mflags;
};
typedef struct gen_Opts_def_typedef gen_Opts_def_typedef;

GEN_API gen_CodeTypedef gen_def__typedef(gen_Str name, gen_Code type, gen_Opts_def_typedef opts GEN_PARAM_DEFAULT);
#define gen_def_typedef(name, type, ...) gen_def__typedef(name, type, (gen_Opts_def_typedef) { __VA_ARGS__ })

struct gen_Opts_def_union
{
	gen_CodeAttributes attributes;
	gen_ModuleFlag     mflags;
};
typedef struct gen_Opts_def_union gen_Opts_def_union;

GEN_API gen_CodeUnion gen_def__union(gen_Str name, gen_CodeBody body, gen_Opts_def_union opts GEN_PARAM_DEFAULT);
#define gen_def_union(name, body, ...) gen_def__union(name, body, (gen_Opts_def_union) { __VA_ARGS__ })

struct gen_Opts_def_using
{
	gen_CodeAttributes attributes;
	gen_ModuleFlag     mflags;
};
typedef struct gen_Opts_def_using gen_Opts_def_using;

GEN_API gen_CodeUsing gen_def__using(gen_Str name, gen_CodeTypename type, gen_Opts_def_using opts GEN_PARAM_DEFAULT);
#define gen_def_using(name, type, ...) gen_def__using(name, type, (gen_Opts_def_using) { __VA_ARGS__ })

GEN_API gen_CodeUsing gen_def_using_namespace(gen_Str name);

struct gen_Opts_def_variable
{
	gen_Code           value;
	gen_CodeSpecifiers specifiers;
	gen_CodeAttributes attributes;
	gen_ModuleFlag     mflags;
};
typedef struct gen_Opts_def_variable gen_Opts_def_variable;

GEN_API gen_CodeVar gen_def__variable(gen_CodeTypename type, gen_Str name, gen_Opts_def_variable opts GEN_PARAM_DEFAULT);
#define gen_def_variable(type, name, ...) gen_def__variable(type, name, (gen_Opts_def_variable) { __VA_ARGS__ })

// Constructs an empty body. Use gen_AST::validate_body() to check if the body is was has valid entries.
GEN_API gen_CodeBody gen_def_body(gen_CodeType type);

// There are two options for defining a struct body, either varadically provided with the args macro to auto-deduce the arg num,
/// or provide as an array of gen_Code objects.

GEN_API gen_CodeBody         gen_def_class_body(gen_s32 num, ...);
GEN_API gen_CodeBody         gen_def_class_body_arr(gen_s32 num, gen_Code* codes);
GEN_API gen_CodeDefineParams gen_def_define_params(gen_s32 num, ...);
GEN_API gen_CodeDefineParams gen_def_define_params_arr(gen_s32 num, gen_CodeDefineParams* codes);
GEN_API gen_CodeBody         gen_def_enum_body(gen_s32 num, ...);
GEN_API gen_CodeBody         gen_def_enum_body_arr(gen_s32 num, gen_Code* codes);
GEN_API gen_CodeBody         gen_def_export_body(gen_s32 num, ...);
GEN_API gen_CodeBody         gen_def_export_body_arr(gen_s32 num, gen_Code* codes);
GEN_API gen_CodeBody         gen_def_extern_link_body(gen_s32 num, ...);
GEN_API gen_CodeBody         gen_def_extern_link_body_arr(gen_s32 num, gen_Code* codes);
GEN_API gen_CodeBody         gen_def_function_body(gen_s32 num, ...);
GEN_API gen_CodeBody         gen_def_function_body_arr(gen_s32 num, gen_Code* codes);
GEN_API gen_CodeBody         gen_def_global_body(gen_s32 num, ...);
GEN_API gen_CodeBody         gen_def_global_body_arr(gen_s32 num, gen_Code* codes);
GEN_API gen_CodeBody         gen_def_namespace_body(gen_s32 num, ...);
GEN_API gen_CodeBody         gen_def_namespace_body_arr(gen_s32 num, gen_Code* codes);
GEN_API gen_CodeParams       gen_def_params(gen_s32 num, ...);
GEN_API gen_CodeParams       gen_def_params_arr(gen_s32 num, gen_CodeParams* params);
GEN_API gen_CodeSpecifiers   gen_def_specifiers(gen_s32 num, ...);
GEN_API gen_CodeSpecifiers   gen_def_specifiers_arr(gen_s32 num, gen_Specifier* specs);
GEN_API gen_CodeBody         gen_def_struct_body(gen_s32 num, ...);
GEN_API gen_CodeBody         gen_def_struct_body_arr(gen_s32 num, gen_Code* codes);
GEN_API gen_CodeBody         gen_def_union_body(gen_s32 num, ...);
GEN_API gen_CodeBody         gen_def_union_body_arr(gen_s32 num, gen_Code* codes);


#pragma endregion Upfront


#pragma region Parsing



GEN_API gen_CodeClass       gen_parse_class(gen_Str gen_class_def);
GEN_API gen_CodeConstructor gen_parse_constructor(gen_Str gen_constructor__def);
GEN_API gen_CodeDefine      gen_parse_define(gen_Str gen_define_def);
GEN_API gen_CodeDestructor  gen_parse_destructor(gen_Str gen_destructor__def);
GEN_API gen_CodeEnum        gen_parse_enum(gen_Str gen_enum_def);
GEN_API gen_CodeBody        gen_parse_export_body(gen_Str export_def);
GEN_API gen_CodeExtern      gen_parse_extern_link(gen_Str exten_link_def);
GEN_API gen_CodeFriend      gen_parse_friend(gen_Str gen_friend_def);
GEN_API gen_CodeFn          gen_parse_function(gen_Str gen_fn_def);
GEN_API gen_CodeBody        gen_parse_global_body(gen_Str gen_body_def);
GEN_API gen_CodeNS          gen_parse_namespace(gen_Str namespace_def);
GEN_API gen_CodeOperator    gen_parse_operator(gen_Str operator_def);
GEN_API gen_CodeOpCast      gen_parse_operator_cast(gen_Str operator_def);
GEN_API gen_CodeStruct      gen_parse_struct(gen_Str gen_struct_def);
GEN_API gen_CodeTemplate    gen_parse_template(gen_Str gen_template_def);
GEN_API gen_CodeTypename    gen_parse_type(gen_Str type_def);
GEN_API gen_CodeTypedef     gen_parse_typedef(gen_Str gen_typedef_def);
GEN_API gen_CodeUnion       gen_parse_union(gen_Str union_def);
GEN_API gen_CodeUsing       gen_parse_using(gen_Str gen_using_def);
GEN_API gen_CodeVar         gen_parse_variable(gen_Str gen_var_def);

#pragma endregion Parsing


#pragma region Untyped text


GEN_API gen_ssize gen_token_fmt_va(char* buf, gen_usize buf_size, gen_s32 num_tokens, va_list va);
//! Do not use directly. Use the gen_token_fmt macro instead.
GEN_API gen_Str gen_token_fmt_impl(gen_ssize, ...);

GEN_API gen_Code gen_untyped_str(gen_Str content);
GEN_API gen_Code gen_untyped_fmt(char const* fmt, ...);
GEN_API gen_Code gen_untyped_token_fmt(gen_s32 num_tokens, char const* fmt, ...);

#pragma endregion Untyped text


#pragma region Macros


#ifndef gen_main
#define gen_main main
#endif

#ifndef name
//	Convienence for defining any name used with the gen api.
//  Lets you provide the length and string literal to the functions without the need for the DSL.
#if GEN_COMPILER_C
#define name(Id_)                                          \
	(gen_Str)                                              \
	{                                                      \
		gen_stringize(Id_), sizeof(gen_stringize(Id_)) - 1 \
	}
#else
#define name(Id_)                                          \
	gen_Str                                                \
	{                                                      \
		gen_stringize(Id_), sizeof(gen_stringize(Id_)) - 1 \
	}
#endif
#endif

#ifndef code
//  Same as name just used to indicate intention of literal for code instead of names.
#if GEN_COMPILER_C
#define code(...)                                                          \
	(gen_Str)                                                              \
	{                                                                      \
		gen_stringize(__VA_ARGS__), sizeof(gen_stringize(__VA_ARGS__)) - 1 \
	}
#else
#define code(...)                                                          \
	gen_Str                                                                \
	{                                                                      \
		gen_stringize(__VA_ARGS__), sizeof(gen_stringize(__VA_ARGS__)) - 1 \
	}
#endif
#endif

#ifndef args
// Provides the number of arguments while passing args inplace.
#define args(...) gen_num_args(__VA_ARGS__), __VA_ARGS__
#endif

#ifndef gen_code_str
// Just wrappers over common untyped code definition constructions.
#define gen_code_str(...) GEN_NS gen_untyped_str(code(__VA_ARGS__))
#endif

#ifndef gen_code_fmt
#define gen_code_fmt(...) GEN_NS gen_untyped_str(gen_token_fmt(__VA_ARGS__))
#endif

#ifndef gen_parse_fmt
#define gen_parse_fmt(type, ...) GEN_NS gen_parse_##type(gen_token_fmt(__VA_ARGS__))
#endif

#ifndef gen_token_fmt
/*
Takes a format string (char const*) and a list of tokens (gen_Str) and returns a gen_Str of the formatted string.
Tokens are provided in '<'identifier'>' format where '<' '>' are just angle brackets (you can change it in gen_token_fmt_va)
---------------------------------------------------------
	Example - A string with:
		typedef <type> <name> <name>;
	Will have a gen_token_fmt arguments populated with:
		"type", gen_str_for_type,
		"name", gen_str_for_name,
	and:
		gen_stringize( typedef <type> <name> <name>; )
-----------------------------------------------------------
So the full call for this example would be:
	gen_token_fmt(
		"type", gen_str_for_type
	,	"name", gen_str_for_name
	,	gen_stringize(
		typedef <type> <name> <name>
	));
!----------------------------------------------------------
! Note: gen_token_fmt_va is whitespace sensitive for the tokens.
! This can be alleviated by skipping whitespace between brackets but it was choosen to not have that implementation by default.
*/
#define gen_token_fmt(...) GEN_NS gen_token_fmt_impl((gen_num_args(__VA_ARGS__) + 1) / 2, __VA_ARGS__)
#endif

#pragma endregion Macros


#pragma endregion Gen Interface

#pragma region Inlines

#pragma region gen_Code

inline void gen_code__append(gen_Code self, gen_Code other)
{
	GEN_ASSERT(self);
	GEN_ASSERT(other);
	GEN_ASSERT_MSG(self != other, "Attempted to recursively append gen_Code gen_AST to itself.");

	if (other->Parent != gen_nullptr)
		other = gen_code_duplicate(other);

	other->Parent = self;

	if (self->Front == gen_nullptr)
	{
		self->Front = other;
		self->Back  = other;

		self->NumEntries++;
		return;
	}

	gen_Code Current = self->Back;
	Current->Next    = other;
	other->Prev      = Current;
	self->Back       = other;
	self->NumEntries++;
}

inline bool gen_code__is_body(gen_Code self)
{
	GEN_ASSERT(self);
	switch (self->Type)
	{
		case CT_Enum_Body:
		case CT_Class_Body:
		case CT_Union_Body:
		case CT_Export_Body:
		case CT_Global_Body:
		case CT_Struct_Body:
		case CT_Function_Body:
		case CT_Namespace_Body:
		case CT_Extern_Linkage_Body:
			return true;
	}
	return false;
}

inline gen_Code* gen_code__entry(gen_Code self, gen_u32 idx)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_Code* current = &self->Front;
	while (idx >= 0 && current != gen_nullptr)
	{
		if (idx == 0)
			return gen_rcast(gen_Code*, current);

		current = &(*current)->Next;
		idx--;
	}

	return gen_rcast(gen_Code*, current);
}

gen_forceinline bool gen_code__is_valid(gen_Code self)
{
	GEN_ASSERT(self);
	return self != gen_nullptr && self->Type != CT_Invalid;
}

gen_forceinline bool gen_code__has_entries(gen_AST* self)
{
	GEN_ASSERT(self);
	return self->NumEntries > 0;
}

gen_forceinline void gen_code__set_global(gen_Code self)
{
	if (self == gen_nullptr)
	{
		gen_log_failure("gen_Code::set_global: Cannot set code as gen_global, gen_AST is null!");
		return;
	}

	self->Parent = gen_Code_Global;
}

gen_forceinline gen_Str gen_code__type_str(gen_Code self)
{
	GEN_ASSERT(self != gen_nullptr);
	return gen_codetype_to_str(self->Type);
}

#pragma endregion gen_Code


#pragma region gen_CodeBody

inline void gen_body_append(gen_CodeBody self, gen_Code other)
{
	GEN_ASSERT(self);
	GEN_ASSERT(other);

	if (gen_code_is_body(other))
	{
		gen_body_append_body(self, gen_cast(gen_CodeBody, other));
		return;
	}

	gen_code_append(gen_cast(gen_Code, self), other);
}

inline void gen_body_append_body(gen_CodeBody self, gen_CodeBody body)
{
	GEN_ASSERT(self);
	GEN_ASSERT(body);
	GEN_ASSERT_MSG(self != body, "Attempted to append body to itself.");

	for (gen_Code entry = gen_begin_CodeBody(body); entry != gen_end_CodeBody(body); entry = gen_next_CodeBody(body, entry))
	{
		gen_body_append(self, entry);
	}
}

inline gen_Code gen_begin_CodeBody(gen_CodeBody body)
{
	GEN_ASSERT(body);
	if (body != gen_nullptr)
		return body->Front;

	return gen_NullCode;
}

gen_forceinline gen_Code gen_end_CodeBody(gen_CodeBody body)
{
	GEN_ASSERT(body);
	return body->Back->Next;
}

inline gen_Code gen_next_CodeBody(gen_CodeBody body, gen_Code entry)
{
	GEN_ASSERT(body);
	GEN_ASSERT(entry);
	return entry->Next;
}

#pragma endregion gen_CodeBody


#pragma region gen_CodeClass

inline void gen_class_add_interface(gen_CodeClass self, gen_CodeTypename type)
{
	GEN_ASSERT(self);
	GEN_ASSERT(type);
	gen_CodeTypename possible_slot = self->ParentType;
	if (possible_slot != gen_nullptr)
	{
		// Were adding an interface to parent type, so we need to make sure the parent type is public.
		self->ParentAccess = AccessSpec_Public;
		// If your planning on adding a proper parent,
		// then you'll need to move this over to ParentType->next and update ParentAccess accordingly.
	}

	while (possible_slot != gen_nullptr)
	{
		possible_slot = gen_cast(gen_CodeTypename, possible_slot->Next);
	}

	possible_slot = type;
}

#pragma endregion gen_CodeClass


#pragma region gen_CodeParams

inline void gen_params_append(gen_CodeParams appendee, gen_CodeParams other)
{
	GEN_ASSERT(appendee);
	GEN_ASSERT(other);
	GEN_ASSERT_MSG(appendee != other, "Attempted to append parameter to itself.");
	gen_Code self  = gen_cast(gen_Code, appendee);
	gen_Code entry = gen_cast(gen_Code, other);

	if (entry->Parent != gen_nullptr)
		entry = gen_code_duplicate(entry);

	entry->Parent = self;

	if (self->Last == gen_nullptr)
	{
		self->Last = entry;
		self->Next = entry;
		self->NumEntries++;
		return;
	}

	self->Last->Next = entry;
	self->Last       = entry;
	self->NumEntries++;
}

inline gen_CodeParams gen_params_get(gen_CodeParams self, gen_s32 idx)
{
	GEN_ASSERT(self);
	gen_CodeParams param = self;
	do
	{
		if (++param != gen_nullptr)
			return gen_NullCode;

		param = gen_cast(gen_CodeParams, gen_cast(gen_Code, param)->Next);
	} while (--idx);

	return param;
}

gen_forceinline bool gen_params_has_entries(gen_CodeParams self)
{
	GEN_ASSERT(self);
	return self->NumEntries > 0;
}

gen_forceinline gen_CodeParams gen_begin_CodeParams(gen_CodeParams params)
{
	if (params != gen_nullptr)
		return params;

	return gen_NullCode;
}

gen_forceinline gen_CodeParams gen_end_CodeParams(gen_CodeParams params)
{
	// return { (gen_AST_Params*) gen_rcast( gen_AST*, ast)->Last };
	return gen_NullCode;
}

gen_forceinline gen_CodeParams gen_next_CodeParams(gen_CodeParams params, gen_CodeParams param_iter)
{
	GEN_ASSERT(param_iter);
	return param_iter->Next;
}

#pragma endregion gen_CodeParams


#pragma region gen_CodeDefineParams

gen_forceinline void gen_define_params_append(gen_CodeDefineParams appendee, gen_CodeDefineParams other)
{
	gen_params_append(gen_cast(gen_CodeParams, appendee), gen_cast(gen_CodeParams, other));
}

gen_forceinline gen_CodeDefineParams gen_define_params_get(gen_CodeDefineParams self, gen_s32 idx)
{
	return (gen_CodeDefineParams)(gen_Code)gen_params_get(gen_cast(gen_CodeParams, self), idx);
}

gen_forceinline bool gen_define_params_has_entries(gen_CodeDefineParams self)
{
	return gen_params_has_entries(gen_cast(gen_CodeParams, self));
}

gen_forceinline gen_CodeDefineParams gen_begin_CodeDefineParams(gen_CodeDefineParams params)
{
	return (gen_CodeDefineParams)(gen_Code)gen_begin_CodeParams(gen_cast(gen_CodeParams, (gen_Code)params));
}

gen_forceinline gen_CodeDefineParams gen_end_CodeDefineParams(gen_CodeDefineParams params)
{
	return (gen_CodeDefineParams)(gen_Code)gen_end_CodeParams(gen_cast(gen_CodeParams, (gen_Code)params));
}

gen_forceinline gen_CodeDefineParams gen_next_CodeDefineParams(gen_CodeDefineParams params, gen_CodeDefineParams entry_iter)
{
	return (gen_CodeDefineParams)(gen_Code)gen_next_CodeParams(gen_cast(gen_CodeParams, (gen_Code)params), gen_cast(gen_CodeParams, (gen_Code)entry_iter));
}

#pragma endregion gen_CodeDefineParams


#pragma region gen_CodeSpecifiers

inline bool gen_specifiers_append(gen_CodeSpecifiers self, gen_Specifier spec)
{
	if (self == gen_nullptr)
	{
		gen_log_failure("gen_CodeSpecifiers: Attempted to append to a null specifiers gen_AST!");
		return false;
	}
	if (self->NumEntries == gen_AST_ArrSpecs_Cap)
	{
		gen_log_failure("gen_CodeSpecifiers: Attempted to append over %d specifiers to a specifiers gen_AST!", gen_AST_ArrSpecs_Cap);
		return false;
	}

	self->ArrSpecs[self->NumEntries] = spec;
	self->NumEntries++;
	return true;
}

inline gen_s32 gen_specifiers_has(gen_CodeSpecifiers self, gen_Specifier spec)
{
	GEN_ASSERT(self != gen_nullptr);
	for (gen_s32 idx = 0; idx < self->NumEntries; idx++)
	{
		if (self->ArrSpecs[idx] == spec)
			return idx;
	}
	return -1;
}

inline gen_s32 gen_specifiers_remove(gen_CodeSpecifiers self, gen_Specifier to_remove)
{
	if (self == gen_nullptr)
	{
		gen_log_failure("gen_CodeSpecifiers: Attempted to append to a null specifiers gen_AST!");
		return -1;
	}
	if (self->NumEntries == gen_AST_ArrSpecs_Cap)
	{
		gen_log_failure("gen_CodeSpecifiers: Attempted to append over %d specifiers to a specifiers gen_AST!", gen_AST_ArrSpecs_Cap);
		return -1;
	}

	gen_s32 result = -1;

	gen_s32 curr   = 0;
	gen_s32 next   = 0;
	for (; next < self->NumEntries; ++curr, ++next)
	{
		gen_Specifier spec = self->ArrSpecs[next];
		if (spec == to_remove)
		{
			result = next;

			next++;
			if (next >= self->NumEntries)
				break;

			spec = self->ArrSpecs[next];
		}

		self->ArrSpecs[curr] = spec;
	}

	if (result > -1)
	{
		self->NumEntries--;
	}
	return result;
}

gen_forceinline gen_Specifier* gen_begin_CodeSpecifiers(gen_CodeSpecifiers self)
{
	if (self != gen_nullptr)
		return &self->ArrSpecs[0];

	return gen_nullptr;
}

gen_forceinline gen_Specifier* gen_end_CodeSpecifiers(gen_CodeSpecifiers self)
{
	return self->ArrSpecs + self->NumEntries;
}

gen_forceinline gen_Specifier* gen_next_CodeSpecifiers(gen_CodeSpecifiers self, gen_Specifier* gen_spec_iter)
{
	return gen_spec_iter + 1;
}

#pragma endregion gen_CodeSpecifiers


#pragma region gen_CodeStruct

inline void gen_struct_add_interface(gen_CodeStruct self, gen_CodeTypename type)
{
	gen_CodeTypename possible_slot = self->ParentType;
	if (possible_slot != gen_nullptr)
	{
		// Were adding an interface to parent type, so we need to make sure the parent type is public.
		self->ParentAccess = AccessSpec_Public;
		// If your planning on adding a proper parent,
		// then you'll need to move this over to ParentType->next and update ParentAccess accordingly.
	}

	while (possible_slot != gen_nullptr)
	{
		possible_slot = gen_cast(gen_CodeTypename, possible_slot->Next);
	}

	possible_slot = type;
}

#pragma endregion gen_Code


#pragma region Interface

inline gen_CodeBody gen_def_body(gen_CodeType type)
{
	switch (type)
	{
		case CT_Class_Body:
		case CT_Enum_Body:
		case CT_Export_Body:
		case CT_Extern_Linkage:
		case CT_Function_Body:
		case CT_Global_Body:
		case CT_Namespace_Body:
		case CT_Struct_Body:
		case CT_Union_Body:
			break;

		default:
			gen_log_failure("gen_def_body: Invalid type %s", gen_codetype_to_str(type).Ptr);
			return (gen_CodeBody)gen_Code_Invalid;
	}

	gen_Code result = gen_make_code();
	result->Type    = type;
	return (gen_CodeBody)result;
}

inline gen_Str gen_token_fmt_impl(gen_ssize num, ...)
{
	gen_local_persist gen_thread_local char buf[GEN_PRINTF_MAXLEN] = { 0 };
	gen_mem_set(buf, 0, GEN_PRINTF_MAXLEN);

	va_list va;
	va_start(va, num);
	gen_ssize result = gen_token_fmt_va(buf, GEN_PRINTF_MAXLEN, num, va);
	va_end(va);

	gen_Str str = { buf, result };
	return str;
}

#pragma endregion Interface
#pragma endregion Inlines

#pragma region gen_Array_gen_StrCached

#define GEN_GENERIC_SLOT_2__array_init            gen_StrCached, gen_Array_gen_StrCached_init
#define GEN_GENERIC_SLOT_2__array_init_reserve    gen_StrCached, gen_Array_gen_StrCached_init_reserve
#define GEN_GENERIC_SLOT_2__array_append          gen_Array_gen_StrCached, gen_Array_gen_StrCached_append
#define GEN_GENERIC_SLOT_2__array_append_items    gen_Array_gen_StrCached, gen_Array_gen_StrCached_append_items
#define GEN_GENERIC_SLOT_2__array_append_at       gen_Array_gen_StrCached, gen_Array_gen_StrCached_append_at
#define GEN_GENERIC_SLOT_2__array_append_items_at gen_Array_gen_StrCached, gen_Array_gen_StrCached_append_items_at
#define GEN_GENERIC_SLOT_2__array_back            gen_Array_gen_StrCached, gen_Array_gen_StrCached_back
#define GEN_GENERIC_SLOT_2__array_clear           gen_Array_gen_StrCached, gen_Array_gen_StrCached_clear
#define GEN_GENERIC_SLOT_2__array_fill            gen_Array_gen_StrCached, gen_Array_gen_StrCached_fill
#define GEN_GENERIC_SLOT_2__array_free            gen_Array_gen_StrCached, gen_Array_gen_StrCached_free
#define GEN_GENERIC_SLOT_2__array_grow            gen_Array_gen_StrCached*, gen_Array_gen_StrCached_grow
#define GEN_GENERIC_SLOT_2__array_num             gen_Array_gen_StrCached, gen_Array_gen_StrCached_num
#define GEN_GENERIC_SLOT_2__array_pop             gen_Array_gen_StrCached, gen_Array_gen_StrCached_pop
#define GEN_GENERIC_SLOT_2__array_remove_at       gen_Array_gen_StrCached, gen_Array_gen_StrCached_remove_at
#define GEN_GENERIC_SLOT_2__array_reserve         gen_Array_gen_StrCached, gen_Array_gen_StrCached_reserve
#define GEN_GENERIC_SLOT_2__array_resize          gen_Array_gen_StrCached, gen_Array_gen_StrCached_resize
#define GEN_GENERIC_SLOT_2__array_set_capacity    gen_Array_gen_StrCached*, gen_Array_gen_StrCached_set_capacity

typedef gen_StrCached*  gen_Array_gen_StrCached;
gen_Array_gen_StrCached gen_Array_gen_StrCached_init(gen_AllocatorInfo allocator);
gen_Array_gen_StrCached gen_Array_gen_StrCached_init_reserve(gen_AllocatorInfo allocator, gen_usize capacity);
bool                    gen_Array_gen_StrCached_append_array(gen_Array_gen_StrCached* self, gen_Array_gen_StrCached other);
bool                    gen_Array_gen_StrCached_append(gen_Array_gen_StrCached* self, gen_StrCached value);
bool                    gen_Array_gen_StrCached_append_items(gen_Array_gen_StrCached* self, gen_StrCached* items, gen_usize item_num);
bool                    gen_Array_gen_StrCached_append_at(gen_Array_gen_StrCached* self, gen_StrCached item, gen_usize idx);
bool                    gen_Array_gen_StrCached_append_items_at(gen_Array_gen_StrCached* self, gen_StrCached* items, gen_usize item_num, gen_usize idx);
gen_StrCached*          gen_Array_gen_StrCached_back(gen_Array_gen_StrCached self);
void                    gen_Array_gen_StrCached_clear(gen_Array_gen_StrCached self);
bool                    gen_Array_gen_StrCached_fill(gen_Array_gen_StrCached self, gen_usize begin, gen_usize end, gen_StrCached value);
void                    gen_Array_gen_StrCached_free(gen_Array_gen_StrCached* self);
bool                    gen_Array_gen_StrCached_grow(gen_Array_gen_StrCached* self, gen_usize min_capacity);
gen_usize               gen_Array_gen_StrCached_num(gen_Array_gen_StrCached self);
gen_StrCached           gen_Array_gen_StrCached_pop(gen_Array_gen_StrCached self);
void                    gen_Array_gen_StrCached_remove_at(gen_Array_gen_StrCached self, gen_usize idx);
bool                    gen_Array_gen_StrCached_reserve(gen_Array_gen_StrCached* self, gen_usize new_capacity);
bool                    gen_Array_gen_StrCached_resize(gen_Array_gen_StrCached* self, gen_usize num);
bool                    gen_Array_gen_StrCached_set_capacity(gen_Array_gen_StrCached* self, gen_usize new_capacity);

gen_forceinline gen_Array_gen_StrCached gen_Array_gen_StrCached_init(gen_AllocatorInfo allocator)
{
	size_t initial_size = gen_array_grow_formula(0);
	return gen_array_init_reserve(gen_StrCached, allocator, initial_size);
}

inline gen_Array_gen_StrCached gen_Array_gen_StrCached_init_reserve(gen_AllocatorInfo allocator, gen_usize capacity)
{
	GEN_ASSERT(capacity > 0);
	gen_ArrayHeader* header = gen_rcast(gen_ArrayHeader*, gen_alloc(allocator, sizeof(gen_ArrayHeader) + sizeof(gen_StrCached) * capacity));
	if (header == gen_nullptr)
		return gen_nullptr;
	header->Allocator = allocator;
	header->Capacity  = capacity;
	header->Num       = 0;
	return gen_rcast(gen_StrCached*, header + 1);
}

gen_forceinline bool gen_Array_gen_StrCached_append_array(gen_Array_gen_StrCached* self, gen_Array_gen_StrCached other)
{
	return gen_array_append_items(*self, (gen_Array_gen_StrCached)other, gen_Array_gen_StrCached_num(other));
}

inline bool gen_Array_gen_StrCached_append(gen_Array_gen_StrCached* self, gen_StrCached value)
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

inline bool gen_Array_gen_StrCached_append_items(gen_Array_gen_StrCached* self, gen_StrCached* items, gen_usize item_num)
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
	gen_mem_copy((*self) + header->Num, items, sizeof(gen_StrCached) * item_num);
	header->Num += item_num;
	return true;
}

inline bool gen_Array_gen_StrCached_append_at(gen_Array_gen_StrCached* self, gen_StrCached item, gen_usize idx)
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
	gen_Array_gen_StrCached target = (*self) + idx;
	gen_mem_move(target + 1, target, (header->Num - idx) * sizeof(gen_StrCached));
	header->Num++;
	return true;
}

inline bool gen_Array_gen_StrCached_append_items_at(gen_Array_gen_StrCached* self, gen_StrCached* items, gen_usize item_num, gen_usize idx)
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
	gen_StrCached* target = (*self) + idx + item_num;
	gen_StrCached* src    = (*self) + idx;
	gen_mem_move(target, src, (header->Num - idx) * sizeof(gen_StrCached));
	gen_mem_copy(src, items, item_num * sizeof(gen_StrCached));
	header->Num += item_num;
	return true;
}

inline gen_StrCached* gen_Array_gen_StrCached_back(gen_Array_gen_StrCached self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	if (header->Num == 0)
		return 0;
	return self + header->Num - 1;
}

inline void gen_Array_gen_StrCached_clear(gen_Array_gen_StrCached self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	header->Num             = 0;
}

inline bool gen_Array_gen_StrCached_fill(gen_Array_gen_StrCached self, gen_usize begin, gen_usize end, gen_StrCached value)
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

inline void gen_Array_gen_StrCached_free(gen_Array_gen_StrCached* self)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	gen_allocator_free(header->Allocator, header);
	self = 0;
}

inline bool gen_Array_gen_StrCached_grow(gen_Array_gen_StrCached* self, gen_usize min_capacity)
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

gen_forceinline gen_usize gen_Array_gen_StrCached_num(gen_Array_gen_StrCached self)
{
	GEN_ASSERT(self != gen_nullptr);
	return gen_array_get_header(self)->Num;
}

inline gen_StrCached gen_Array_gen_StrCached_pop(gen_Array_gen_StrCached self)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	GEN_ASSERT(header->Num > 0);
	gen_StrCached result = self[header->Num - 1];
	header->Num--;
	return result;
}

gen_forceinline void gen_Array_gen_StrCached_remove_at(gen_Array_gen_StrCached self, gen_usize idx)
{
	GEN_ASSERT(self != gen_nullptr);
	gen_ArrayHeader* header = gen_array_get_header(self);
	GEN_ASSERT(idx < header->Num);
	gen_mem_move(self + idx, self + idx + 1, sizeof(gen_StrCached) * (header->Num - idx - 1));
	header->Num--;
}

inline bool gen_Array_gen_StrCached_reserve(gen_Array_gen_StrCached* self, gen_usize new_capacity)
{
	GEN_ASSERT(self != gen_nullptr);
	GEN_ASSERT(*self != gen_nullptr);
	GEN_ASSERT(new_capacity > 0);
	gen_ArrayHeader* header = gen_array_get_header(*self);
	if (header->Capacity < new_capacity)
		return gen_array_set_capacity(self, new_capacity);
	return true;
}

inline bool gen_Array_gen_StrCached_resize(gen_Array_gen_StrCached* self, gen_usize num)
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

inline bool gen_Array_gen_StrCached_set_capacity(gen_Array_gen_StrCached* self, gen_usize new_capacity)
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
	gen_usize        size       = sizeof(gen_ArrayHeader) + sizeof(gen_StrCached) * new_capacity;
	gen_ArrayHeader* new_header = gen_cast(gen_ArrayHeader*, gen_alloc(header->Allocator, size));
	if (new_header == 0)
		return false;
	gen_mem_move(new_header, header, sizeof(gen_ArrayHeader) + sizeof(gen_StrCached) * header->Num);
	new_header->Capacity = new_capacity;
	gen_allocator_free(header->Allocator, &header);
	*self = gen_cast(gen_StrCached*, new_header + 1);
	return true;
}

#pragma endregion gen_Array_gen_StrCached

#pragma region Constants


GEN_API extern gen_Macro gen_enum_underlying_macro;

GEN_API extern gen_Code gen_access_public;
GEN_API extern gen_Code gen_access_protected;
GEN_API extern gen_Code gen_access_private;

GEN_API extern gen_CodeAttributes gen_attrib_api_export;
GEN_API extern gen_CodeAttributes gen_attrib_api_import;

GEN_API extern gen_Code gen_module_global_fragment;
GEN_API extern gen_Code gen_module_private_fragment;

GEN_API extern gen_Code gen_fmt_newline;

GEN_API extern gen_CodePragma gen_pragma_once;

GEN_API extern gen_CodeParams gen_param_varadic;

GEN_API extern gen_CodePreprocessCond gen_preprocess_else;
GEN_API extern gen_CodePreprocessCond gen_preprocess_endif;

GEN_API extern gen_CodeSpecifiers gen_spec_const;
GEN_API extern gen_CodeSpecifiers gen_spec_consteval;
GEN_API extern gen_CodeSpecifiers gen_spec_constexpr;
GEN_API extern gen_CodeSpecifiers gen_spec_constinit;
GEN_API extern gen_CodeSpecifiers gen_spec_extern_linkage;
GEN_API extern gen_CodeSpecifiers gen_spec_final;
GEN_API extern gen_CodeSpecifiers gen_spec_forceinline;
GEN_API extern gen_CodeSpecifiers gen_spec_global;
GEN_API extern gen_CodeSpecifiers gen_spec_inline;
GEN_API extern gen_CodeSpecifiers gen_spec_internal_linkage;
GEN_API extern gen_CodeSpecifiers gen_spec_local_persist;
GEN_API extern gen_CodeSpecifiers gen_spec_mutable;
GEN_API extern gen_CodeSpecifiers gen_spec_neverinline;
GEN_API extern gen_CodeSpecifiers gen_spec_noexcept;
GEN_API extern gen_CodeSpecifiers gen_spec_override;
GEN_API extern gen_CodeSpecifiers gen_spec_ptr;
GEN_API extern gen_CodeSpecifiers gen_spec_pure;
GEN_API extern gen_CodeSpecifiers gen_spec_ref;
GEN_API extern gen_CodeSpecifiers gen_spec_register;
GEN_API extern gen_CodeSpecifiers gen_spec_rvalue;
GEN_API extern gen_CodeSpecifiers gen_spec_static_member;
GEN_API extern gen_CodeSpecifiers gen_spec_thread_local;
GEN_API extern gen_CodeSpecifiers gen_spec_virtual;
GEN_API extern gen_CodeSpecifiers gen_spec_volatile;

GEN_API extern gen_CodeTypename gen_t_empty;    // Used with varaidc parameters. (Exposing just in case its useful for another circumstance)
GEN_API extern gen_CodeTypename gen_t_auto;
GEN_API extern gen_CodeTypename gen_t_void;
GEN_API extern gen_CodeTypename gen_t_int;
GEN_API extern gen_CodeTypename gen_t_bool;
GEN_API extern gen_CodeTypename gen_t_char;
GEN_API extern gen_CodeTypename gen_t_wchar_t;
GEN_API extern gen_CodeTypename gen_t_class;
GEN_API extern gen_CodeTypename gen_t_typename;

#ifdef GEN_DEFINE_LIBRARY_CODE_CONSTANTS

// Predefined typename codes. Are set to readonly and are setup during gen::gen_init()
GEN_API extern gen_Context* gen__ctx;

GEN_API extern gen_CodeTypename gen_t_b32;

GEN_API extern gen_CodeTypename gen_t_s8;
GEN_API extern gen_CodeTypename gen_t_s16;
GEN_API extern gen_CodeTypename gen_t_s32;
GEN_API extern gen_CodeTypename gen_t_s64;

GEN_API extern gen_CodeTypename gen_t_u8;
GEN_API extern gen_CodeTypename gen_t_u16;
GEN_API extern gen_CodeTypename gen_t_u32;
GEN_API extern gen_CodeTypename gen_t_u64;

GEN_API extern gen_CodeTypename gen_t_ssize;
GEN_API extern gen_CodeTypename gen_t_usize;

GEN_API extern gen_CodeTypename gen_t_f32;
GEN_API extern gen_CodeTypename gen_t_f64;
#endif

#pragma endregion Constants

#pragma region gen_Builder


struct gen_Builder;
typedef struct gen_Builder gen_Builder;

GEN_API gen_Builder gen_builder_open(char const* path);
GEN_API void        gen_builder_pad_lines(gen_Builder* builder, gen_s32 num);
GEN_API void        gen_builder__print(gen_Builder* builder, gen_Code code);
GEN_API void        gen_builder_print_fmt_va(gen_Builder* builder, char const* fmt, va_list va);
GEN_API void        gen_builder_write(gen_Builder* builder);

gen_forceinline void gen_builder_print_fmt(gen_Builder* builder, char const* fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	gen_builder_print_fmt_va(builder, fmt, va);
	va_end(va);
}

#define gen_builder_print(builder, code)            \
	_Generic(                                       \
	    (code),                                     \
	    gen_Code: gen_builder__print,               \
	    gen_CodeBody: gen_builder__print,           \
	    gen_CodeAttributes: gen_builder__print,     \
	    gen_CodeComment: gen_builder__print,        \
	    gen_CodeClass: gen_builder__print,          \
	    gen_CodeConstructor: gen_builder__print,    \
	    gen_CodeDefine: gen_builder__print,         \
	    gen_CodeDefineParams: gen_builder__print,   \
	    gen_CodeDestructor: gen_builder__print,     \
	    gen_CodeEnum: gen_builder__print,           \
	    gen_CodeExec: gen_builder__print,           \
	    gen_CodeExtern: gen_builder__print,         \
	    gen_CodeInclude: gen_builder__print,        \
	    gen_CodeFriend: gen_builder__print,         \
	    gen_CodeFn: gen_builder__print,             \
	    gen_CodeModule: gen_builder__print,         \
	    gen_CodeNS: gen_builder__print,             \
	    gen_CodeOperator: gen_builder__print,       \
	    gen_CodeOpCast: gen_builder__print,         \
	    gen_CodePragma: gen_builder__print,         \
	    gen_CodeParams: gen_builder__print,         \
	    gen_CodePreprocessCond: gen_builder__print, \
	    gen_CodeSpecifiers: gen_builder__print,     \
	    gen_CodeStruct: gen_builder__print,         \
	    gen_CodeTemplate: gen_builder__print,       \
	    gen_CodeTypename: gen_builder__print,       \
	    gen_CodeTypedef: gen_builder__print,        \
	    gen_CodeUnion: gen_builder__print,          \
	    gen_CodeUsing: gen_builder__print,          \
	    gen_CodeVar: gen_builder__print,            \
	    default: gen_generic_selection_fail         \
	) GEN_RESOLVED_FUNCTION_CALL(builder, (gen_Code)code)

struct gen_Builder
{
	gen_FileInfo   File;
	gen_StrBuilder Buffer;
};

#pragma endregion gen_Builder

#pragma region Scanner

// This is a simple file reader that reads the entire file into memory.
// It has an extra option to skip the first few lines for undesired includes.
// This is done so that includes can be kept in dependency and component files so that intellisense works.
GEN_API gen_Code gen_scan_file(char const* path);

GEN_API gen_CodeBody gen_parse_file(const char* path);

// The follow is basic support for light csv parsing (use it as an example)
// Make something robust if its more serious.

typedef struct gen_CSV_Column gen_CSV_Column;

struct gen_CSV_Column
{
	gen_CSV_Object ADT;
	gen_Array(gen_ADT_Node) Content;
};

typedef struct gen_CSV_Columns2 gen_CSV_Columns2;

struct gen_CSV_Columns2
{
	gen_CSV_Object ADT;
	gen_Array(gen_ADT_Node) Col_1;
	gen_Array(gen_ADT_Node) Col_2;
};

GEN_API gen_CSV_Column   gen_parse_csv_one_column(gen_AllocatorInfo allocator, char const* path);
GEN_API gen_CSV_Columns2 gen_parse_csv_two_columns(gen_AllocatorInfo allocator, char const* path);

#pragma endregion Scanner

GEN_API_C_END
GEN_NS_END

#ifdef __clang__
#	pragma clang diagnostic pop
#endif

#ifdef __GNUC__
#	pragma GCC diagnostic pop
#endif
