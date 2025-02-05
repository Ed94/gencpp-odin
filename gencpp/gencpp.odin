/*
	gencpp: An attempt at "simple" staged metaprogramming for c/c++.

	See Readme.md for more information from the project repository.

	Public Address:
	https://github.com/Ed94/gencpp-odin ----------------------------------------------------------------.
	|   _____                               _____ _                       _      ___       _            |
	|  / ____)                             / ____} |                     | |   / ,_, \    | |{_}        |
	| | / ___  ___ _ __   ___ _ __  _ __  | {___ | l_ __ _  __ _, ___  __| |  | |   | | __| | _ _ __    |
	| | |{_  \/ __\ '_ \ / __} '_ l| '_ l  \___ \| __/ _` |/ _` |/ __\/ _` |  | |   | |/ _` || | '_ \   |    
	| | l__j | ___/ | | | {__; ;_l } ;_l } ____} | l| (_} | {_| | ___/ {_; |  | \___/ | {_; || | | | |  |     
	|  \_____|\___}_l |_|\___} .__/| .__/ {_____/ \__\__/_l\__. |\___/\__,_l   \_____/ \__,_l|_|_l |_|  |
	|                        | |   | |                      __} |                                       |
	|                        l_l   l_l                     {___/                                        |
	! ---------------------------------------------------------------------------- VERSION: v0.25-Alpha |
	! ==================================================================================================|
	! WARNING: THIS IS AN ALPHA VERSION OF THE LIBRARY, USE AT YOUR OWN DISCRETION                      |
	! NEVER DO CODE GENERATION WITHOUT AT LEAST HAVING CONTENT IN A CODEBASE UNDER VERSION CONTROL      |
*/

package gencpp

import    "base:runtime"
import c  "core:c"
import    "core:c/libc"
import    "core:fmt"
import    "core:mem"
import    "core:reflect"
import os "core:os/os2"
import    "core:strings"

when ODIN_OS == .Windows {
	foreign import gencpp_c11 "./lib/win64/gencpp_c11.lib"
}
else when ODIN_OS == .Linux {
	// TODO(Ed): Get linux working
}
else when ODIN_OS == .Darwin {
	// TODO(Ed): Get Mac working
}

// Eventually gencpp will support execution statements and expressions
// For now it does not.
EXECUTION_SUPPORT :: false

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
//#region("Enums N Types")

Access_Spec :: enum(u32) {
	Default,
	Private,
	Protected,
	Public,

	Num_AccessSpec,
	Invalid,
}

access_spec_to_str :: proc "contextless" (type : Access_Spec) -> string {
	#partial switch type {
		case .Default:   return ""
		case .Private:   return "private"
		case .Protected: return "protected"
		case .Public:    return "public"
	}
	return "INVALID"
}

Code_Flag :: enum(u32) {
	None,
	FunctionType,
	ParamPack,
	Module_Export,
	Module_Import,
}
CodeFlags :: bit_set[Code_Flag; u32]

Enum_Decl :: enum(u32) {
	Regular,
	Class,
}

Module_Flag :: enum(u32) {
	None,
	Export,
	Import,

	Num_ModuleFlags,
	Invalid,
}
Module_Flags :: bit_set[Module_Flag; u32]

module_flag_to_str :: proc "contextless" (flag : Module_Flag) -> string {
	#partial switch flag {
		case .None:   return "__none__"
		case .Export: return "export"
		case .Import: return "import"
	}
	return "INVALID"
}

Preprocess_Cond :: enum(u32)
{
	If,
	IfDef,
	IfNotDef,
	ElIf,
}

Typename_Tag :: enum(u16)
{
	None,
	Class,
	Enum,
	Struct,
	Union,
}

Code_Type :: enum(u32) {
	Invalid,
	Untyped,
	NewLine,
	Comment,
	Access_Private,
	Access_Protected,
	Access_Public,
	Platform_Attributes,
	Class,
	Class_Fwd,
	Class_Body,
	Constructor,
	Constructor_Fwd,
	Destructor,
	Destructor_Fwd,
	Enum,
	Enum_Fwd,
	Enum_Body,
	Enum_Class,
	Enum_Class_Fwd,
	Execution,
	Export_Body,
	Extern_Linkege,
	Extern_Linkage_Body,
	Friend,
	Function,
	Function_Fwd,
	Function_Body,
	Global_Body,
	Module,
	Namespace,
	Namespace_Body,
	Operator,
	Operator_Fwd,
	Operator_Member,
	Operator_Member_Fwd,
	Operator_Cast,
	Operator_Cast_Fwd,
	Parameters,
	Parameters_Define,
	Preprocess_Define,
	Preprocess_Include,
	Preprocess_If,
	Preprocess_IfDef,
	Preprocess_IfNotDef,
	Preprocess_ElIf,
	Preprocess_Else,
	Preprocess_EndIf,
	Preprocess_Pragma,
	Specifiers,
	Struct,
	Struct_Fwd,
	Struct_Body,
	Template,
	Typedef,
	Typename,
	Union,
	Union_Fwd,
	Union_Body,
	Using,
	Using_Namespace,
	Variable,
}

codetype_to_keyword_str :: proc "contextless" (type : Code_Type) -> string
{
	switch type {
		case .Invalid, .Untyped, .NewLine:          return "__NA__"
		case .Comment:                              return "//"
		case .Access_Private:                       return "private"
		case .Access_Protected:                     return "protected"
		case .Access_Public:                        return "public"
		case .Platform_Attributes:                  return "__NA__"
		case .Class, .Class_Fwd:                    return "class"
		case .Class_Body,                 \
			.Constructor, .Constructor_Fwd, \
			.Destructor,  .Destructor_Fwd:            return "__NA__"
		case .Enum, .Enum_Fwd:                      return "enum"
		case .Enum_Body:                            return "__NA__"
		case .Enum_Class, .Enum_Class_Fwd:          return "enum class"
		case .Execution, .Export_Body:              return "__NA__"
		case .Extern_Linkege, .Extern_Linkage_Body: return "extern"
		case .Friend:                               return "friend"
		case .Function, .Function_Fwd, \
			.Function_Body, .Global_Body:             return "__NA__"
		case .Module:                               return "module"
		case .Namespace:                            return "namespace"
		case .Namespace_Body:                       return "__NA__"
		case .Operator, .Operator_Fwd,            \
			.Operator_Member, .Operator_Member_Fwd, \
			.Operator_Cast, .Operator_Cast_Fwd:       return "operator"
		case .Parameters, .Parameters_Define:       return "__NA__"
		case .Preprocess_Define:                    return "define"
		case .Preprocess_Include:                   return "include"
		case .Preprocess_If:                        return "if"
		case .Preprocess_IfDef:                     return "ifdef"
		case .Preprocess_IfNotDef:                  return "ifndef"
		case .Preprocess_ElIf:                      return "elif"
		case .Preprocess_Else:                      return "else"
		case .Preprocess_EndIf:                     return "endif"
		case .Preprocess_Pragma:                    return "pragma"
		case .Specifiers:                           return "__NA__"
		case .Struct, .Struct_Fwd:                  return "struct"
		case .Struct_Body:                          return "__NA__"
		case .Template:                             return "template"
		case .Typedef:                              return "typedef"
		case .Typename:                             return "__NA__"
		case .Union, .Union_Fwd:                    return "union"
		case .Union_Body:                           return "__NA__"
		case .Using:                                return "using"
		case .Using_Namespace:                      return "using namespace"
		case .Variable:                             return "__NA__"
	}
	return ""
}

Operator :: enum(u32)
{
	Invalid,
	Assign,
	Assign_Add,
	Assign_Subtract,
	Assign_Multiply,
	Assign_Divide,
	Assign_Modulo,
	Assign_BAnd,
	Assign_BOr,
	Assign_BXOr,
	Assign_LShift,
	Assign_RShift,
	Increment,
	Decrement,
	Unary_Plus,
	Unary_Minus,
	UnaryNot,
	Add,
	Subtract,
	Multiply,
	Divide,
	Modulo,
	BNot,
	BAnd,
	BOr,
	BXOr,
	LShift,
	RShift,
	LAnd,
	LOr,
	LEqual,
	LNot,
	Lesser,
	Greater,
	LesserEqual,
	GreaterEqual,
	Subscript,
	Indirection,
	AddressOf,
	MemberOfPointer,
	PtrToMemOfPtr,
	FunctionCall,
	Comma,
	New,
	NewArray,
	Delete,
	DeleteArray,
};

operator_to_str :: proc "contextless" (op : Operator) -> string
{
	switch op {
		case .Invalid:         return "INVALID"
		case .Assign:          return "="
		case .Assign_Add:      return "+="
		case .Assign_Subtract: return "-="
		case .Assign_Multiply: return "*="
		case .Assign_Divide:   return "/="
		case .Assign_Modulo:   return "%="
		case .Assign_BAnd:     return "&="
		case .Assign_BOr:      return "|="
		case .Assign_BXOr:     return "^="
		case .Assign_LShift:   return "<<="
		case .Assign_RShift:   return ">>="
		case .Increment:       return "++"
		case .Decrement:       return "--"
		case .Unary_Plus:      return "+"
		case .Unary_Minus:     return "-"
		case .UnaryNot:        return "!"
		case .Add:             return "+"
		case .Subtract:        return "-"
		case .Multiply:        return "*"
		case .Divide:          return "/"
		case .Modulo:          return "%"
		case .BNot:            return "~"
		case .BAnd:            return "&"
		case .BOr:             return "|"
		case .BXOr:            return "^"
		case .LShift:          return "<<"
		case .RShift:          return ">>"
		case .LAnd:            return "&&"
		case .LOr:             return "||"
		case .LEqual:          return "=="
		case .LNot:            return "!="
		case .Lesser:          return "<"
		case .Greater:         return ">"
		case .LesserEqual:     return "<="
		case .GreaterEqual:    return ">="
		case .Subscript:       return "[]"
		case .Indirection:     return "*"
		case .AddressOf:       return "&"
		case .MemberOfPointer: return "->"
		case .PtrToMemOfPtr:   return "->*"
		case .FunctionCall:    return "()"
		case .Comma:           return ","
		case .New:             return "new"
		case .NewArray:        return "new[]"
		case .Delete:          return "delete"
		case .DeleteArray:     return "delete[]"
	}
	return ""
}

Specifier :: enum(u32)
{
	Invalid,
	Consteval,
	Constexpr,
	Constinit,
	Explicit,
	External_Linkage,
	ForceInline,
	Global,
	Inline,
	Internal_Linkage,
	Local_Persist,
	Mutable,
	NeverInline,
	Ptr,
	Ref,
	Register,
	Restrict,
	RValue,
	Static,
	Thread_Local,
	Virtual,
	Const,
	Final,
	NoExceptions,
	Override,
	Pure,
	Delete,
	Volatile,
}

spec_to_str :: proc "contextless" (spec : Specifier) -> string
{
	switch(spec) {
		case .Invalid:          return "INVALID"
		case .Consteval:        return "consteval"
		case .Constexpr:        return "constexpr"
		case .Constinit:        return "constinit"
		case .Explicit:         return "explicit"
		case .External_Linkage: return "external"
		case .ForceInline:      return "forceinline"
		case .Global:           return "global"
		case .Inline:           return "inline"
		case .Internal_Linkage: return "internal"
		case .Local_Persist:    return "local_persist"
		case .Mutable:          return "mutable"
		case .NeverInline:      return "neverinline"
		case .Ptr:              return "*"
		case .Ref:              return "&"
		case .Register:         return "register"
		case .Restrict:         return "restrict"
		case .RValue:           return "&&"
		case .Static:           return "static"
		case .Thread_Local:     return "thread_local"
		case .Virtual:          return "virtual"
		case .Const:            return "const"
		case .Final:            return "final"
		case .NoExceptions:     return "noexcept"
		case .Override:         return "override"
		case .Pure:             return "= 0"
		case .Delete:           return "= delete"
		case .Volatile:         return "volatile"
	}
	return ""
}

spec_is_trailing :: proc "contextless" (spec : Specifier) -> bool
{
	#partial switch spec {
		case .Const, .Final, .NoExceptions, .Override, .Pure, .Delete, .Volatile: return true
	}
	return false;
}

Token_Type :: enum(u32)
{
	Invalid,
	Access_Private,
	Access_Protected,
	Access_Public,
	Access_MemberSymbol,
	Access_StaticSymbol,
	Ampersand,
	Ampersand_DBL,
	Assign_Classifer,
	Attribute_Open,
	Attribute_Close,
	BraceCurly_Open,
	BraceCurly_Close,
	BraceSquare_Open,
	BraceSquare_Close,
	Paren_Open,
	Paren_Close,
	Comment,
	Comment_End,
	Comment_Start,
	Char,
	Comma,
	Decl_Class,
	Decl_GNU_Attribute,
	Decl_MSVC_Attribute,
	Decl_Enum,
	Decl_Extern_Linkage,
	Decl_Friend,
	Decl_Module,
	Decl_Namespace,
	Decl_Operator,
	Decl_Struct,
	Decl_Template,
	Decl_Typedef,
	Decl_Using,
	Decl_Union,
	Identifier,
	Module_Import,
	Module_Export,
	NewLine,
	Number,
	Operator,
	Preprocess_Hash,
	Preprocess_Define,
	Preprocess_Define_Param,
	Preprocess_If,
	Preprocess_IfDef,
	Preprocess_IfNotDef,
	Preprocess_ElIf,
	Preprocess_Else,
	Preprocess_EndIf,
	Preprocess_Include,
	Preprocess_Pragma,
	Preprocess_Content,
	Preprocess_Macro_Expr,
	Preprocess_Macro_Stmt,
	Preprocess_Macro_Typename,
	Preprocess_Unsupported,
	Spec_Alignas,
	Spec_Const,
	Spec_Consteval,
	Spec_Constexpr,
	Spec_Constinit,
	Spec_Explicit,
	Spec_Extern,
	Spec_Final,
	Spec_ForceInline,
	Spec_Global,
	Spec_Inline,
	Spec_Internal_Linkage,
	Spec_LocalPersist,
	Spec_Mutable,
	Spec_NeverInline,
	Spec_Override,
	Spec_Restrict,
	Spec_Static,
	Spec_ThreadLocal,
	Spec_Volatile,
	Spec_Virtual,
	Star,
	Statement_End,
	Static_Assert,
	String,
	Type_Typename,
	Type_Unsigned,
	Type_Signed,
	Type_Short,
	Type_Long,
	Type_bool,
	Type_char,
	Type_int,
	Type_double,
	Type_MS_int8,
	Type_MS_int16,
	Type_MS_int32,
	Type_MS_int64,
	Type_MS_W64,
	Varadic_Argument,
	Tok___Attributes_Start,
}

toktype_to_str :: proc "contextless" (type : Token_Type) -> string
{
	switch type {
		case .Invalid:                   return "INVALID"
		case .Access_Private:            return "private"
		case .Access_Protected:          return "protected"
		case .Access_Public:             return "public"
		case .Access_MemberSymbol:       return "."
		case .Access_StaticSymbol:       return "::"
		case .Ampersand:                 return "&"
		case .Ampersand_DBL:             return "&&"
		case .Assign_Classifer:          return ":"
		case .Attribute_Open:            return "[["
		case .Attribute_Close:           return "]]"
		case .BraceCurly_Open:           return "{"
		case .BraceCurly_Close:          return "}"
		case .BraceSquare_Open:          return "["
		case .BraceSquare_Close:         return "]"
		case .Paren_Open:                return "("
		case .Paren_Close:               return ")"
		case .Comment:                   return "__comment__"
		case .Comment_End:               return "__comment_end__"
		case .Comment_Start:             return "__comment_start__"
		case .Char:                      return "__character__"
		case .Comma:                     return ","
		case .Decl_Class:                return "class"
		case .Decl_GNU_Attribute:        return "__atribute__"
		case .Decl_MSVC_Attribute:       return "__declspec"
		case .Decl_Enum:                 return "enum"
		case .Decl_Extern_Linkage:       return "extern"
		case .Decl_Friend:               return "friend"
		case .Decl_Module:               return "module"
		case .Decl_Namespace:            return "namespace"
		case .Decl_Operator:             return "operator"
		case .Decl_Struct:               return "struct"
		case .Decl_Template:             return "template"
		case .Decl_Typedef:              return "typedef"
		case .Decl_Using:                return "using"
		case .Decl_Union:                return "union"
		case .Identifier:                return "__identifier__"
		case .Module_Import:             return "import"
		case .Module_Export:             return "export"
		case .NewLine:                   return "__new_line__"
		case .Number:                    return "__number__"
		case .Operator:                  return "operator"
		case .Preprocess_Hash:           return "#"
		case .Preprocess_Define:         return "define"
		case .Preprocess_Define_Param:   return "__define_param__"
		case .Preprocess_If:             return "if"
		case .Preprocess_IfDef:          return "ifdef"
		case .Preprocess_IfNotDef:       return "ifndef"
		case .Preprocess_ElIf:           return "elif"
		case .Preprocess_Else:           return "else"
		case .Preprocess_EndIf:          return "endif"
		case .Preprocess_Include:        return "include"
		case .Preprocess_Pragma:         return "pragma"
		case .Preprocess_Content:        return "__macro_content__"
		case .Preprocess_Macro_Expr:     return "__macro_expansion__"
		case .Preprocess_Macro_Stmt:     return "__macro_statement__"
		case .Preprocess_Macro_Typename: return "__macro_typename__"
		case .Preprocess_Unsupported:    return "__unsupported__"
		case .Spec_Alignas:              return "alignas"
		case .Spec_Const:                return "const"
		case .Spec_Consteval:            return "consteval"
		case .Spec_Constexpr:            return "constexpr"
		case .Spec_Constinit:            return "constinit"
		case .Spec_Explicit:             return "explicti"
		case .Spec_Extern:               return "extern"
		case .Spec_Final:                return "final"
		case .Spec_ForceInline:          return "forceinline"
		case .Spec_Global:               return "global"
		case .Spec_Inline:               return "inline"
		case .Spec_Internal_Linkage:     return "internal"
		case .Spec_LocalPersist:         return "local_persist"
		case .Spec_Mutable:              return "mutable"
		case .Spec_NeverInline:          return "neverinline"
		case .Spec_Override:             return "override"
		case .Spec_Restrict:             return "restrict"
		case .Spec_Static:               return "static"
		case .Spec_ThreadLocal:          return "thread_local"
		case .Spec_Volatile:             return "volatile"
		case .Spec_Virtual:              return "virtual"
		case .Star:                      return "*"
		case .Statement_End:             return ";"
		case .Static_Assert:             return "static_assert"
		case .String:                    return "__string_"
		case .Type_Typename:             return "typename"
		case .Type_Unsigned:             return "unsigned"
		case .Type_Signed:               return "signed"
		case .Type_Short:                return "short"
		case .Type_Long:                 return "long"
		case .Type_bool:                 return "bool"
		case .Type_char:                 return "char"
		case .Type_int:                  return "int"
		case .Type_double:               return "double"
		case .Type_MS_int8:              return "__int8"
		case .Type_MS_int16:             return "__int16"
		case .Type_MS_int32:             return "__int32"
		case .Type_MS_int64:             return "__int64"
		case .Type_MS_W64:               return "_W64"
		case .Varadic_Argument:          return "..."
		case .Tok___Attributes_Start:    return "__attrib_start__"
	}
	return ""
}

Token_Flag :: enum(u32) {
	Operator,
	Assign,
	Preprocess,
	Preprocess_Cond,
	Attribute,
	Access_Operator,
	Access_Specifier,
	Specifier,
	End_Definition,
	Formatting,
	Literal,
	Macro_Functional,
	Macro_Expects_Body, 
	Null = 0
};
Token_Flags :: bit_set[Token_Flag; u32]

Token :: struct {
	text   : string,
	type   : Token_Type,
	line   : i32,
	column : i32,
	flags  : Token_Flags,
}

tok_to_access_specifier :: #force_inline proc "contextless" (tok : Token) -> Access_Spec { return cast(Access_Spec) tok.type }
tok_is_valid            :: #force_inline proc "contextless" (tok : Token) -> bool        { return tok.text != "" && len(tok.text) > 0 && tok.type != .Invalid }
tok_is_access_specifier :: #force_inline proc "contextless" (tok : Token) -> bool        { return .Access_Operator in tok.flags }
tok_is_attribute        :: #force_inline proc "contextless" (tok : Token) -> bool        { return .Attribute       in tok.flags }
tok_is_operator         :: #force_inline proc "contextless" (tok : Token) -> bool        { return .Operator        in tok.flags }
tok_is_proprocessor     :: #force_inline proc "contextless" (tok : Token) -> bool        { return .Preprocess      in tok.flags }
tok_is_preprocess_cond  :: #force_inline proc "contextless" (tok : Token) -> bool        { return .Preprocess_Cond in tok.flags }
tok_is_specifier        :: #force_inline proc "contextless" (tok : Token) -> bool        { return .Specifier       in tok.flags }
tok_is_end_definition   :: #force_inline proc "contextless" (tok : Token) -> bool        { return .End_Definition  in tok.flags }

Token_Array :: struct {
	arr : Array(Token),
	idx : i32,
}

Lex_Context :: struct {
	content : string,
	left    : i32,
	scanner : ^c.char,
	line    : i32,
	column  : i32,
	token   : Token,
}

Stack_Node :: struct {
	prev      : ^Stack_Node,
	start     : ^Token,
	name      : string,
	proc_name : string,
}

Parse_Context :: struct {
	tokens : Token_Array,
	scope  : ^Stack_Node,
}

Macro_Type :: enum(u16)
{
	Expression,     // A macro is assumed to be a expression if not resolved.
	Statement,      
	Typename,
	Block_Start,    // Not Supported yet
	Block_End,      // Not Supported yet
	Case_Statement, // Not Supported yet
};

Macro_Flag :: enum(u16)
{
	Functional,   // Macro has parameters (args expected to be passed)
	Expects_Body, // Expects to assign a braced scope to its body.

	Allow_As_Identifier, // lex__eat wil treat this macro as an identifier if the parser attempts to consume it as one.

	Allow_As_Attribute, // lex__eat wil treat this macro as an attribute if the parser attempts to consume it as one.
	//  ^^^ This a kludge because unreal has a macro that behaves as both a 'statement' and an attribute (UE_DEPRECATED, PRAGMA_ENABLE_DEPRECATION_WARNINGS, etc)
	// TODO(Ed): We can keep the MF_Allow_As_Attribute flag for macros, however, we need to add the ability of AST_Attributes to chain themselves.
	// Its thats already a thing in the standard language anyway
	// & it would allow UE_DEPRECATED, (UE_PROPERTY / UE_FUNCTION) to chain themselves as attributes of a resolved member function/variable definition

	// When a macro is encountered after attributes and specifiers while parsing a function, or variable:
	// It will consume the macro and treat it as resolving the definition. (Yes this is for Unreal Engine)
	// (MUST BE OF MT_Statement TYPE)
	Allow_As_Definition,

	Allow_As_Specifier, // Created for Unreal's PURE_VIRTUAL

	None = 0,
};
Macro_Flags :: bit_set[Macro_Flag; u16]

Macro :: struct {
	name  : string_cached,
	type  : Macro_Type,
	flags : Macro_Flags
}

macro_is_functional :: #force_inline proc "contextless"(macro : Macro) -> bool { return .Functional   in macro.flags }
macro_expects_body  :: #force_inline proc "contextless"(macro : Macro) -> bool { return .Expects_Body in macro.flags }
//#endregion("Enums N Types")

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
//#region("AST N Code")

Code                 :: distinct ^AST
Code_Body            :: distinct ^AST_Body
Code_Attributes      :: distinct ^AST_Attributes
Code_Comment         :: distinct ^AST_Comment
Code_Class           :: distinct ^AST_Class
Code_Constructor     :: distinct ^AST_Constructor
Code_Define          :: distinct ^AST_Define
Code_DefineParams    :: distinct ^AST_Define_Params
Code_Destructor      :: distinct ^AST_Destructor
Code_Enum            :: distinct ^AST_Enum
Code_Exec            :: distinct ^AST_Exec
Code_Extern          :: distinct ^AST_Extern
Code_Include         :: distinct ^AST_Include
Code_Friend          :: distinct ^AST_Friend
Code_Fn              :: distinct ^AST_Fn
Code_Module          :: distinct ^AST_Module
Code_NS              :: distinct ^AST_NS
Code_Operator        :: distinct ^AST_Operator
Code_OpCast          :: distinct ^AST_Op_Cast
Code_Params          :: distinct ^AST_Params
Code_Preprocess_Cond :: distinct ^AST_Preprocess_Cond
Code_Pragma          :: distinct ^AST_Pragma
Code_Specifiers      :: distinct ^AST_Specifiers
Code_Struct          :: distinct ^AST_Struct
Code_Template        :: distinct ^AST_Template
Code_Typename        :: distinct ^AST_Typename
Code_Typedef         :: distinct ^AST_Typedef
Code_Union           :: distinct ^AST_Union
Code_Using           :: distinct ^AST_Using
Code_Var             :: distinct ^AST_Var

when EXECUTION_SUPPORT {
	Code_Expr                :: distinct ^AST_Expr
	Code_Expr_Assign         :: distinct ^AST_Expr_Assign
	Code_Expr_Alignof        :: distinct ^AST_Expr_Alignof
	Code_Expr_Binary         :: distinct ^AST_Expr_Binary
	Code_Expr_CSytleCast     :: distinct ^AST_Expr_CSytleCast
	Code_Expr_FunctionalCast :: distinct ^AST_Expr_FunctionalCast
	Code_Expr_CppCast        :: distinct ^AST_Expr_CppCast
	Code_Expr_Element        :: distinct ^AST_Expr_Element
	Code_Expr_FnCall         :: distinct ^AST_Expr_FnCall
	Code_Expr_Decltype       :: distinct ^AST_Expr_Decltype
	Code_Expr_Comma          :: distinct ^AST_Expr_Comma
	Code_Expr_AMS            :: distinct ^AST_Expr_AMS
	Code_Expr_sizeof         :: distinct ^AST_Expr_sizeof
	Code_Expr_Subscript      :: distinct ^AST_Expr_Subscript
	Code_Expr_Ternary        :: distinct ^AST_Expr_Ternary
	Code_Expr_UnraryPrefix   :: distinct ^AST_Expr_UnraryPrefix
	Code_Expr_UnraryPostfix  :: distinct ^AST_Expr_UnraryPostfix

	Code_Stmt          :: distinct ^AST_Stmt
	Code_Stmt_Break    :: distinct ^AST_Stmt_Break
	Code_Stmt_Case     :: distinct ^AST_Stmt_Case
	Code_Stmt_Continue :: distinct ^AST_Stmt_Continue
	Code_Stmt_Decl     :: distinct ^AST_Stmt_Decl
	Code_Stmt_Do       :: distinct ^AST_Stmt_Do
	Code_Stmt_Expr     :: distinct ^AST_Stmt_Expr
	Code_Stmt_Else     :: distinct ^AST_Stmt_Else
	Code_Stmt_If       :: distinct ^AST_Stmt_If
	Code_Stmt_Goto     :: distinct ^AST_Stmt_Goto
	Code_Stmt_Label    :: distinct ^AST_Stmt_Label
	Code_Stmt_Lambda   :: distinct ^AST_Stmt_Lambda
	Code_Stmt_Switch   :: distinct ^AST_Stmt_Switch
	Code_Stmt_While    :: distinct ^AST_Stmt_While
}

@(default_calling_convention="c", link_prefix="gen_")
foreign gencpp_c11 {
	Code_Global  : Code
	Code_Invalid : Code

	enum_underlying_macro : Code

	access_public    : Code
	access_protected : Code
	access_private   : Code

	module_global_fragment  : Code
	module_private_fragment : Code

	fmt_newline : Code

	pragma_once : Code_Pragma

	param_varadic : Code_Params

	preprocess_else  : Code_Preprocess_Cond
	preprocess_endif : Code_Preprocess_Cond

	spec_const            : Code_Specifiers
	spec_conteval         : Code_Specifiers
	spec_constexpr        : Code_Specifiers
	spec_constinit        : Code_Specifiers
	spec_extern_linkage   : Code_Specifiers
	spec_final            : Code_Specifiers
	spec_forceinline      : Code_Specifiers
	spec_global           : Code_Specifiers
	spec_inline           : Code_Specifiers
	spec_Internal_Linkage : Code_Specifiers
	spec_local_persist    : Code_Specifiers
	spec_mutable          : Code_Specifiers
	spec_neverinline      : Code_Specifiers
	spec_noexcept         : Code_Specifiers
	spec_override         : Code_Specifiers
	spec_ptr              : Code_Specifiers
	spec_pure             : Code_Specifiers
	spec_ref              : Code_Specifiers
	spec_register         : Code_Specifiers
	spec_rvalue           : Code_Specifiers
	spec_static_member    : Code_Specifiers
	spec_thread_local     : Code_Specifiers
	spec_virtual          : Code_Specifiers
	spec_volatile         : Code_Specifiers

	t_empty    : Code_Typename
	t_auto     : Code_Typename
	t_void     : Code_Typename
	t_int      : Code_Typename
	t_bool     : Code_Typename
	t_char     : Code_Typename
	t_wchar_t  : Code_Typename
	t_class    : Code_Typename
	t_typename : Code_Typename

	t_b32 : Code_Typename

	t_s8  : Code_Typename
	t_s16 : Code_Typename
	t_s32 : Code_Typename
	t_s64 : Code_Typename

	t_u8  : Code_Typename
	t_u16 : Code_Typename
	t_u32 : Code_Typename
	t_u64 : Code_Typename

	t_ssize : Code_Typename
	t_usize : Code_Typename

	t_f32 : Code_Typename
	t_f64 : Code_Typename
}

AST_POD_SIZE        :: 128
AST_ARRAY_SPECS_CAP :: 14

AST :: struct
{
	using _ : struct #raw_union
	{
		using _ : struct
		{
			inline_cmt  : Code,  // Class, Constructor, Destructor, Enum, Friend, Functon, Operator, OpCast, Struct, Typedef, Using, Variable
			attributes  : Code,  // Class, Enum, Function, Struct, Typedef, Union, Using, Variable
			specs       : Code,  // Class, Destructor, Function, Operator, Struct, Typename, Variable
			using _ : struct #raw_union {
				initializer_list : Code,  // Constructor
				parent_type      : Code,  // Class, Struct, ParentType->Next has a possible list of interfaces.
				return_type      : Code,  // Function, Operator, Typename
				underlying_type  : Code,  // Enum, Typedef
				value_type       : Code,   // Parameter, Variable
			},
			using _ : struct #raw_union {
				macro                 : Code,  // Parameter
				bitfield_size         : Code,  // Variable (Class/Struct Data Member)
				params                : Code,  // Constructor, Define, Function, Operator, Template, Typename
				underlying_type_macro : Code,  // Enum
			},
			using _ : struct #raw_union {
				arr_expr      : Code,  // Typename
				body          : Code,  // Class, Constructor, Define, Destructor, Enum, Friend, Function, Namespace, Struct, Union
				delcaration   : Code,  // Friend, Template
				value         : Code,  // Parameter, Variable
			},
			using _ : struct #raw_union {
				next_var        : Code, // Variable
				suffix_specs    : Code, // Typename, Function (Thanks Unreal)
				post_name_macro : Code, // Only used with parameters for specifically UE_REQUIRES (Thanks Unreal)
			},
		},
		content : string_cached,
		using _ : struct {
			arr_specs  : [AST_ARRAY_SPECS_CAP]Specifier,
			next_specs : Code,
		},
	},
	Name : string_cached,
	using _ : struct #raw_union {
		prev  : Code,
		front : Code,
		last  : Code,
	},
	using _ : struct #raw_union {
		next : Code,
		back : Code,
	},
	token        : ^Token,
	parent       : Code,
	type         : Code_Type,
	module_flags : Module_Flags,
	using _ : struct #raw_union
	{
		is_function : b32,
		using _ : struct #raw_union {
			is_param_pack : b16,
			type_tag      : Typename_Tag,
		},
		op : Operator,
		num_entries             : i32,
		var_parenthesiszed_init : i32,
	}
}
//#endregion("AST N Code")

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
//#region("Code Interface")

append :: proc {
	code_append,
	body_append,
	define_params_append,
	params_append,
	specifiers_append,
}

body_append :: #force_inline proc(body : Code_Body, other : Code) { code_append(transmute(Code) body, other) }

begin :: proc {
	begin_body,
	begin_define_params,
	begin_params,
	begin_specifiers,
}

debug_str :: proc {
	code_debug_str,
	attributes_debug_str,
	body_debug_str,
	comment_debug_str,
	constructor_debug_str,
	class_debug_str,
	define_debug_str,
	define_params_debug_str,
	enum_debug_str,
	exec_debug_str,
	extern_debug_str,
	include_debug_str,
	friend_debug_str,
	fn_debug_str,
	module_debug_str,
	namespace_debug_str,
	operator_debug_str,
	opcast_debug_str,
	params_debug_str,
	specifiers_debug_str,
	struct_debug_str,
	template_debug_str,
	typename_debug_str,
	typedef_debug_str,
	union_debug_str,
	var_debug_str,
}

attributes_debug_str    :: #force_inline proc(code : Code_Attributes)   { code__debug_str(transmute(Code) code) }
body_debug_str          :: #force_inline proc(code : Code_Body)         { code__debug_str(transmute(Code) code) }
comment_debug_str       :: #force_inline proc(code : Code_Comment)      { code__debug_str(transmute(Code) code) }
constructor_debug_str   :: #force_inline proc(code : Code_Constructor)  { code__debug_str(transmute(Code) code) }
class_debug_str         :: #force_inline proc(code : Code_Class)        { code__debug_str(transmute(Code) code) }
define_debug_str        :: #force_inline proc(code : Code_Define)       { code__debug_str(transmute(Code) code) }
define_params_debug_str :: #force_inline proc(code : Code_DefineParams) { code__debug_str(transmute(Code) code) }
enum_debug_str          :: #force_inline proc(code : Code_Enum)         { code__debug_str(transmute(Code) code) }
exec_debug_str          :: #force_inline proc(code : Code_Exec)         { code__debug_str(transmute(Code) code) }
extern_debug_str        :: #force_inline proc(code : Code_Extern)       { code__debug_str(transmute(Code) code) }
include_debug_str       :: #force_inline proc(code : Code_Include)      { code__debug_str(transmute(Code) code) }
friend_debug_str        :: #force_inline proc(code : Code_Friend)       { code__debug_str(transmute(Code) code) }
fn_debug_str            :: #force_inline proc(code : Code_Fn)           { code__debug_str(transmute(Code) code) }
module_debug_str        :: #force_inline proc(code : Code_Module)       { code__debug_str(transmute(Code) code) }
namespace_debug_str     :: #force_inline proc(code : Code_NS)           { code__debug_str(transmute(Code) code) }
operator_debug_str      :: #force_inline proc(code : Code_Operator)     { code__debug_str(transmute(Code) code) }
opcast_debug_str        :: #force_inline proc(code : Code_OpCast)       { code__debug_str(transmute(Code) code) }
params_debug_str        :: #force_inline proc(code : Code_Params)       { code__debug_str(transmute(Code) code) }
specifiers_debug_str    :: #force_inline proc(code : Code_Specifiers)   { code__debug_str(transmute(Code) code) }
struct_debug_str        :: #force_inline proc(code : Code_Struct)       { code__debug_str(transmute(Code) code) }
template_debug_str      :: #force_inline proc(code : Code_Template)     { code__debug_str(transmute(Code) code) }
typename_debug_str      :: #force_inline proc(code : Code_Typename)     { code__debug_str(transmute(Code) code) }
typedef_debug_str       :: #force_inline proc(code : Code_Typedef)      { code__debug_str(transmute(Code) code) }
union_debug_str         :: #force_inline proc(code : Code_Union)        { code__debug_str(transmute(Code) code) }
var_debug_str           :: #force_inline proc(code : Code_Var)          { code__debug_str(transmute(Code) code) }

duplicate :: proc {
	code__duplicate,
	attributes_duplicate,
	body_duplicate,
	comment_duplicate,
	constructor_duplicate,
	class_duplicate,
	define_duplicate,
	define_params_duplicate,
	enum_duplicate,
	exec_duplicate,
	extern_duplicate,
	include_duplicate,
	friend_duplicate,
	fn_duplicate,
	module_duplicate,
	namespace_duplicate,
	operator_duplicate,
	opcast_duplicate,
	params_duplicate,
	specifiers_duplicate,
	struct_duplicate,
	template_duplicate,
	typename_duplicate,
	typedef_duplicate,
	union_duplicate,
	var_duplicate,
}

attributes_duplicate    :: #force_inline proc(code: Code_Attributes)   -> Code { return code__duplicate(transmute(Code) code) }
body_duplicate          :: #force_inline proc(code: Code_Body)         -> Code { return code__duplicate(transmute(Code) code) }
comment_duplicate       :: #force_inline proc(code: Code_Comment)      -> Code { return code__duplicate(transmute(Code) code) }
constructor_duplicate   :: #force_inline proc(code: Code_Constructor)  -> Code { return code__duplicate(transmute(Code) code) }
class_duplicate         :: #force_inline proc(code: Code_Class)        -> Code { return code__duplicate(transmute(Code) code) }
define_duplicate        :: #force_inline proc(code: Code_Define)       -> Code { return code__duplicate(transmute(Code) code) }
define_params_duplicate :: #force_inline proc(code: Code_DefineParams) -> Code { return code__duplicate(transmute(Code) code) }
enum_duplicate          :: #force_inline proc(code: Code_Enum)         -> Code { return code__duplicate(transmute(Code) code) }
exec_duplicate          :: #force_inline proc(code: Code_Exec)         -> Code { return code__duplicate(transmute(Code) code) }
extern_duplicate        :: #force_inline proc(code: Code_Extern)       -> Code { return code__duplicate(transmute(Code) code) }
include_duplicate       :: #force_inline proc(code: Code_Include)      -> Code { return code__duplicate(transmute(Code) code) }
friend_duplicate        :: #force_inline proc(code: Code_Friend)       -> Code { return code__duplicate(transmute(Code) code) }
fn_duplicate            :: #force_inline proc(code: Code_Fn)           -> Code { return code__duplicate(transmute(Code) code) }
module_duplicate        :: #force_inline proc(code: Code_Module)       -> Code { return code__duplicate(transmute(Code) code) }
namespace_duplicate     :: #force_inline proc(code: Code_NS)           -> Code { return code__duplicate(transmute(Code) code) }
operator_duplicate      :: #force_inline proc(code: Code_Operator)     -> Code { return code__duplicate(transmute(Code) code) }
opcast_duplicate        :: #force_inline proc(code: Code_OpCast)       -> Code { return code__duplicate(transmute(Code) code) }
params_duplicate        :: #force_inline proc(code: Code_Params)       -> Code { return code__duplicate(transmute(Code) code) }
specifiers_duplicate    :: #force_inline proc(code: Code_Specifiers)   -> Code { return code__duplicate(transmute(Code) code) }
struct_duplicate        :: #force_inline proc(code: Code_Struct)       -> Code { return code__duplicate(transmute(Code) code) }
template_duplicate      :: #force_inline proc(code: Code_Template)     -> Code { return code__duplicate(transmute(Code) code) }
typename_duplicate      :: #force_inline proc(code: Code_Typename)     -> Code { return code__duplicate(transmute(Code) code) }
typedef_duplicate       :: #force_inline proc(code: Code_Typedef)      -> Code { return code__duplicate(transmute(Code) code) }
union_duplicate         :: #force_inline proc(code: Code_Union)        -> Code { return code__duplicate(transmute(Code) code) }
var_duplicate           :: #force_inline proc(code: Code_Var)          -> Code { return code__duplicate(transmute(Code) code) }

end :: proc {
	end_body,
	end_define_params,
	end_params,
	end_specifiers,
}

entry :: proc {
	code_entry,
	body_entry,
	define_params_entry,
	params_entry,
	specifiers_entry,
}

body_entry          :: #force_inline proc(self: Code_Body,         idx: u32) -> ^Code { return code_entry(transmute(Code) self, idx) }
define_params_entry :: #force_inline proc(self: Code_DefineParams, idx: u32) -> ^Code { return code_entry(transmute(Code) self, idx) }
params_entry        :: #force_inline proc(self: Code_Params,       idx: u32) -> ^Code { return code_entry(transmute(Code) self, idx) }
specifiers_entry    :: #force_inline proc(self: Code_Specifiers,   idx: u32) -> ^Code { return code_entry(transmute(Code) self, idx) }

has_entries :: proc {
	code_has_entries,
	body_has_entries,
	define_params_has_entires,
	params_has_entries,
	specifiers_has_entries,
}

body_has_entries          :: #force_inline proc(self: Code_Body)         -> bool { return code_has_entries(transmute(Code) self) }
define_params_has_entries :: #force_inline proc(self: Code_DefineParams) -> bool { return code_has_entries(transmute(Code) self) }
params_has_entries        :: #force_inline proc(self: Code_Params)       -> bool { return code_has_entries(transmute(Code) self) }
specifiers_has_entries    :: #force_inline proc(self: Code_Specifiers)   -> bool { return code_has_entries(transmute(Code) self) }

is_body :: proc {
	code_is_body,
}

is_equal :: proc {
	code__is_equal,
	attributes_is_equal,
	body_is_equal,
	comment_is_equal,
	constructor_is_equal,
	class_is_equal,
	define_is_equal,
	define_params_is_equal,
	destructor_is_equal,
	enum_is_equal,
	exec_is_equal,
	extern_is_equal,
	include_is_equal,
	friend_is_equal,
	fn_is_equal,
	module_is_equal,
	namespace_is_equal,
	operator_is_equal,
	opcast_is_equal,
	params_is_equal,
	specifiers_is_equal,
	struct_is_equal,
	template_is_equal,
	typename_is_equal,
	typedef_is_equal,
	union_is_equal,
	var_is_equal,
}

attributes_is_equal    :: #force_inline proc(code: Code_Attributes)   -> bool { return code__is_equal(transmute(Code) code) }
body_is_equal          :: #force_inline proc(code: Code_Body)         -> bool { return code__is_equal(transmute(Code) code) }
comment_is_equal       :: #force_inline proc(code: Code_Comment)      -> bool { return code__is_equal(transmute(Code) code) }
constructor_is_equal   :: #force_inline proc(code: Code_Constructor)  -> bool { return code__is_equal(transmute(Code) code) }
class_is_equal         :: #force_inline proc(code: Code_Class)        -> bool { return code__is_equal(transmute(Code) code) }
define_is_equal        :: #force_inline proc(code: Code_Define)       -> bool { return code__is_equal(transmute(Code) code) }
define_params_is_equal :: #force_inline proc(code: Code_DefineParams) -> bool { return code__is_equal(transmute(Code) code) }
destructor_is_equal    :: #force_inline proc(code: Code_Destructor)   -> bool { return code__is_equal(transmute(Code) code) }
enum_is_equal          :: #force_inline proc(code: Code_Enum)         -> bool { return code__is_equal(transmute(Code) code) }
exec_is_equal          :: #force_inline proc(code: Code_Exec)         -> bool { return code__is_equal(transmute(Code) code) }
extern_is_equal        :: #force_inline proc(code: Code_Extern)       -> bool { return code__is_equal(transmute(Code) code) }
include_is_equal       :: #force_inline proc(code: Code_Include)      -> bool { return code__is_equal(transmute(Code) code) }
friend_is_equal        :: #force_inline proc(code: Code_Friend)       -> bool { return code__is_equal(transmute(Code) code) }
fn_is_equal            :: #force_inline proc(code: Code_Fn)           -> bool { return code__is_equal(transmute(Code) code) }
module_is_equal        :: #force_inline proc(code: Code_Module)       -> bool { return code__is_equal(transmute(Code) code) }
namespace_is_equal     :: #force_inline proc(code: Code_NS)           -> bool { return code__is_equal(transmute(Code) code) }
operator_is_equal      :: #force_inline proc(code: Code_Operator)     -> bool { return code__is_equal(transmute(Code) code) }
opcast_is_equal        :: #force_inline proc(code: Code_OpCast)       -> bool { return code__is_equal(transmute(Code) code) }
params_is_equal        :: #force_inline proc(code: Code_Params)       -> bool { return code__is_equal(transmute(Code) code) }
specifiers_is_equal    :: #force_inline proc(code: Code_Specifiers)   -> bool { return code__is_equal(transmute(Code) code) }
struct_is_equal        :: #force_inline proc(code: Code_Struct)       -> bool { return code__is_equal(transmute(Code) code) }
template_is_equal      :: #force_inline proc(code: Code_Template)     -> bool { return code__is_equal(transmute(Code) code) }
typename_is_equal      :: #force_inline proc(code: Code_Typename)     -> bool { return code__is_equal(transmute(Code) code) }
typedef_is_equal       :: #force_inline proc(code: Code_Typedef)      -> bool { return code__is_equal(transmute(Code) code) }
union_is_equal         :: #force_inline proc(code: Code_Union)        -> bool { return code__is_equal(transmute(Code) code) }
var_is_equal           :: #force_inline proc(code: Code_Var)          -> bool { return code__is_equal(transmute(Code) code) }

is_valid :: proc {
	code_is_valid,
	attributes_is_valid,
	body_is_valid,
	comment_is_valid,
	constructor_is_valid,
	class_is_valid,
	define_is_valid,
	define_params_is_valid,
	destructor_is_valid,
	enum_is_valid,
	exec_is_valid,
	extern_is_valid,
	include_is_valid,
	friend_is_valid,
	fn_is_valid,
	module_is_valid,
	namespace_is_valid,
	operator_is_valid,
	opcast_is_valid,
	params_is_valid,
	specifiers_is_valid,
	struct_is_valid,
	template_is_valid,
	typename_is_valid,
	typedef_is_valid,
	union_is_valid,
	var_is_valid,
}

attributes_is_valid    :: #force_inline proc(self: Code_Attributes)   -> bool { return code_is_valid(transmute(Code) self) }
body_is_valid          :: #force_inline proc(self: Code_Body)         -> bool { return code_is_valid(transmute(Code) self) }
comment_is_valid       :: #force_inline proc(self: Code_Comment)      -> bool { return code_is_valid(transmute(Code) self) }
constructor_is_valid   :: #force_inline proc(self: Code_Constructor)  -> bool { return code_is_valid(transmute(Code) self) }
class_is_valid         :: #force_inline proc(self: Code_Class)        -> bool { return code_is_valid(transmute(Code) self) }
define_is_valid        :: #force_inline proc(self: Code_Define)       -> bool { return code_is_valid(transmute(Code) self) }
define_params_is_valid :: #force_inline proc(self: Code_DefineParams) -> bool { return code_is_valid(transmute(Code) self) }
destructor_is_valid    :: #force_inline proc(self: Code_Destructor)   -> bool { return code_is_valid(transmute(Code) self) }
enum_is_valid          :: #force_inline proc(self: Code_Enum)         -> bool { return code_is_valid(transmute(Code) self) }
exec_is_valid          :: #force_inline proc(self: Code_Exec)         -> bool { return code_is_valid(transmute(Code) self) }
extern_is_valid        :: #force_inline proc(self: Code_Extern)       -> bool { return code_is_valid(transmute(Code) self) }
include_is_valid       :: #force_inline proc(self: Code_Include)      -> bool { return code_is_valid(transmute(Code) self) }
friend_is_valid        :: #force_inline proc(self: Code_Friend)       -> bool { return code_is_valid(transmute(Code) self) }
fn_is_valid            :: #force_inline proc(self: Code_Fn)           -> bool { return code_is_valid(transmute(Code) self) }
module_is_valid        :: #force_inline proc(self: Code_Module)       -> bool { return code_is_valid(transmute(Code) self) }
namespace_is_valid     :: #force_inline proc(self: Code_NS)           -> bool { return code_is_valid(transmute(Code) self) }
operator_is_valid      :: #force_inline proc(self: Code_Operator)     -> bool { return code_is_valid(transmute(Code) self) }
opcast_is_valid        :: #force_inline proc(self: Code_OpCast)       -> bool { return code_is_valid(transmute(Code) self) }
params_is_valid        :: #force_inline proc(self: Code_Params)       -> bool { return code_is_valid(transmute(Code) self) }
specifiers_is_valid    :: #force_inline proc(self: Code_Specifiers)   -> bool { return code_is_valid(transmute(Code) self) }
struct_is_valid        :: #force_inline proc(self: Code_Struct)       -> bool { return code_is_valid(transmute(Code) self) }
template_is_valid      :: #force_inline proc(self: Code_Template)     -> bool { return code_is_valid(transmute(Code) self) }
typename_is_valid      :: #force_inline proc(self: Code_Typename)     -> bool { return code_is_valid(transmute(Code) self) }
typedef_is_valid       :: #force_inline proc(self: Code_Typedef)      -> bool { return code_is_valid(transmute(Code) self) }
union_is_valid         :: #force_inline proc(self: Code_Union)        -> bool { return code_is_valid(transmute(Code) self) }
var_is_valid           :: #force_inline proc(self: Code_Var)          -> bool { return code_is_valid(transmute(Code) self) }

next :: proc {
	next_body,
	next_define_params,
	next_params,
	next_specifiers,
}

set_global :: proc {
	code_set_global,
	attributes_set_global,
	body_set_global,
	comment_set_global,
	constructor_set_global,
	class_set_global,
	define_set_global,
	define_params_set_global,
	destructor_set_global,
	enum_set_global,
	exec_set_global,
	extern_set_global,
	include_set_global,
	friend_set_global,
	fn_set_global,
	module_set_global,
	namespace_set_global,
	operator_set_global,
	opcast_set_global,
	params_set_global,
	specifiers_set_global,
	struct_set_global,
	template_set_global,
	typename_set_global,
	typedef_set_global,
	union_set_global,
	var_set_global,
}

attributes_set_global    :: #force_inline proc(self: Code_Attributes)   { code_set_global(transmute(Code) self) }
body_set_global          :: #force_inline proc(self: Code_Body)         { code_set_global(transmute(Code) self) }
comment_set_global       :: #force_inline proc(self: Code_Comment)      { code_set_global(transmute(Code) self) }
constructor_set_global   :: #force_inline proc(self: Code_Constructor)  { code_set_global(transmute(Code) self) }
class_set_global         :: #force_inline proc(self: Code_Class)        { code_set_global(transmute(Code) self) }
define_set_global        :: #force_inline proc(self: Code_Define)       { code_set_global(transmute(Code) self) }
define_params_set_global :: #force_inline proc(self: Code_DefineParams) { code_set_global(transmute(Code) self) }
destructor_set_global    :: #force_inline proc(self: Code_Destructor)   { code_set_global(transmute(Code) self) }
enum_set_global          :: #force_inline proc(self: Code_Enum)         { code_set_global(transmute(Code) self) }
exec_set_global          :: #force_inline proc(self: Code_Exec)         { code_set_global(transmute(Code) self) }
extern_set_global        :: #force_inline proc(self: Code_Extern)       { code_set_global(transmute(Code) self) }
include_set_global       :: #force_inline proc(self: Code_Include)      { code_set_global(transmute(Code) self) }
friend_set_global        :: #force_inline proc(self: Code_Friend)       { code_set_global(transmute(Code) self) }
fn_set_global            :: #force_inline proc(self: Code_Fn)           { code_set_global(transmute(Code) self) }
module_set_global        :: #force_inline proc(self: Code_Module)       { code_set_global(transmute(Code) self) }
namespace_set_global     :: #force_inline proc(self: Code_NS)           { code_set_global(transmute(Code) self) }
operator_set_global      :: #force_inline proc(self: Code_Operator)     { code_set_global(transmute(Code) self) }
opcast_set_global        :: #force_inline proc(self: Code_OpCast)       { code_set_global(transmute(Code) self) }
params_set_global        :: #force_inline proc(self: Code_Params)       { code_set_global(transmute(Code) self) }
specifiers_set_global    :: #force_inline proc(self: Code_Specifiers)   { code_set_global(transmute(Code) self) }
struct_set_global        :: #force_inline proc(self: Code_Struct)       { code_set_global(transmute(Code) self) }
template_set_global      :: #force_inline proc(self: Code_Template)     { code_set_global(transmute(Code) self) }
typename_set_global      :: #force_inline proc(self: Code_Typename)     { code_set_global(transmute(Code) self) }
typedef_set_global       :: #force_inline proc(self: Code_Typedef)      { code_set_global(transmute(Code) self) }
union_set_global         :: #force_inline proc(self: Code_Union)        { code_set_global(transmute(Code) self) }
var_set_global           :: #force_inline proc(self: Code_Var)          { code_set_global(transmute(Code) self) }

to_strbuilder :: proc {
	attributes_to_strbuilder,
	body_to_strbuilder,
	comment_to_strbuilder,
	constructor_to_strbuilder,
	class_to_strbuilder,
	define_to_strbuilder,
	define_params_to_strbuilder,
	destructor_to_strbuilder,
	enum_to_strbuilder,
	exec_to_strbuilder,
	extern_to_strbuilder,
	include_to_strbuilder,
	friend_to_strbuilder,
	fn_to_strbuilder,
	module_to_strbuilder,
	namespace_to_strbuilder,
	operator_to_strbuilder,
	opcast_to_strbuilder,
	params_to_strbuilder,
	specifiers_to_strbuilder,
	struct_to_strbuilder,
	template_to_strbuilder,
	typename_to_strbuilder,
	typedef_to_strbuilder,
	union_to_strbuilder,
	var_to_strbuilder,
}

attributes_to_strbuilder :: #force_inline proc(attributes : Code_Attributes) -> Str_Builder {
	assert(attributes != nil)
	dupe := strbuilder_make_string(_ctx.allocator_temp, attributes.content)
	return dupe
}

attributes_to_strbuilder_ref :: #force_inline proc(attributes : Code_Attributes, builder : ^Str_Builder) {
	assert(attributes != nil)
	assert(builder != nil)
	strbuilder_append_string(builder, attributes.content)
}

body_to_stringbuilder_ref :: proc(body : Code_Body, result : ^Str_Builder) {
	assert(body != nil)
	assert(result != nil)
	curr := body.front
	left := body.num_entries
	for left > -1 {
		code_to_strbuilder_ref(curr, result)
		left -= 1
		curr = curr.next
	}
}

comment_to_strbuilder :: #force_inline proc(comment : Code_Comment) -> Str_Builder {
	assert(comment != nil)
	dupe := strbuilder_make_string(_ctx.allocator_temp, comment.content)
	return dupe
}

comment_to_strbuilder_ref :: #force_inline proc(comment : Code_Comment, builder : ^Str_Builder) {
	assert(comment != nil)
	assert(builder != nil)
	strbuilder_append_string(builder, comment.content)
}

define_to_strbuilder :: #force_inline proc(define : Code_Define) -> Str_Builder {
	assert(define != nil)
	result := strbuilder_make_reserve(_ctx.allocator_temp, 512)
	define_to_strbuilder_ref(define, & result)
	return result
}

define_params_to_strbuilder :: proc(params : Code_DefineParams) -> Str_Builder {
	assert(params != nil)
	result := strbuilder_make_reserve(_ctx.allocator_temp, 512)
	define_params_to_strbuilder_ref(params, & result)
	return result
}

exec_to_strbuilder :: proc(code : Code_Exec) -> Str_Builder {
	assert(code != nil )
	result := strbuilder_make_reserve(_ctx.allocator_temp, 512)
	exec_to_strbuilder_ref(code, & result)
	return result
}

exec_to_strbuilder_ref :: proc(code : Code_Exec, result : ^Str_Builder) {
	assert(code != nil)
	assert(result != nil)
	strbuilder_append_string(result, code.content)
}

extern_to_strbuilder :: proc(extern : Code_Extern) -> Str_Builder {
	result := strbuilder_make_reserve(_ctx.allocator_temp, 512)
	extern_to_strbuilder_ref(extern, & result)
	return result
}

extern_to_strbuilder_ref :: proc(extern : Code_Extern, result : ^Str_Builder) {
	assert(extern != nil)
	assert(result != nil)
	if extern.body != nil {
		strbuilder_append_fmt_buf(result, "extern \"%s\"\n{\n%s\n}\n", extern.name, strbuilder_to_string(body_to_strbuilder(extern.body)))
	}
	else {
		strbuilder_append_fmt_buf(result, "extern \"%s\"\n{}\n", extern.name)
	}
}

friend_to_strbuilder :: proc(friend : Code_Friend) -> Str_Builder {
	assert(friend != nil)
	result := strbuilder_make_reserve(_ctx.allocator_temp, 256)
	friend_to_strbuilder_ref(friend, & result)
	return result
}

friend_to_strbuilder_ref :: proc(friend : Code_Friend, result : ^Str_Builder) {
	assert(friend != nil)
	assert(result != nil)
	strbuilder_append_fmt_buf( result, "friend %s", code_to_string(friend.declaration) );

	result_str := strbuilder_to_string(result ^)
	if ( friend.declaration.type != .Function && friend.declaration.type != .Operator && result_str[len(result_str) - 1] != ';' ) {
		strbuilder_append_string( result, ";" );
	}

	if ( friend.inline_cmt != nil ) {
		strbuilder_append_fmt_buf( result, "  %s", friend.inline_cmt.content );
	}
	else {
		strbuilder_append_string( result, "\n");
	}
}

include_to_strbuilder :: proc(include : Code_Include) -> Str_Builder {
	assert(include != nil)
	return strbuilder_fmt_buf(_ctx.allocator_temp, "#include %s\n", include.content)
}

include_to_strbuilder_ref :: proc(include : Code_Include, result : ^Str_Builder) {
	assert(include != nil)
	assert(result != nil)
	strbuilder_append_fmt_buf(result, "#include %s\n", include.content)
}

module_to_strbuilder :: proc(code : Code_Module) -> Str_Builder {
	assert(code != nil)
	result := strbuilder_make_reserve(_ctx.allocator_temp, 64)
	module_to_strbuilder_ref(code, & result)
	return result
}

namespace_to_strbuilder :: proc(code : Code_NS) -> Str_Builder {
	assert(code != nil)
	result := strbuilder_make_reserve(_ctx.allocator_temp, 512)
	namespace_to_strbuilder_ref(code, & result)
	return result
}

namespace_to_strbuilder_ref :: proc(code : Code_NS, result : ^Str_Builder) {
	assert(code != nil)
	assert(result != nil)
	result := strbuilder_make_reserve(_ctx.allocator_temp, 512 )
	namespace_to_strbuilder_ref(code, & result)
}

params_to_strbuilder :: proc(params : Code_Params) -> Str_Builder {
	assert(params != nil)
	result := strbuilder_make_reserve(_ctx.allocator_temp, 128)
	params_to_strbuilder_ref(params, & result)
	return result
}

pragma_to_strbuilder :: proc(pragma : Code_Pragma) -> Str_Builder {
	assert(pragma != nil)
	result := strbuilder_make_reserve(_ctx.allocator_temp, 512)
	pragma_to_strbuilder_ref(pragma, & result)
	return result
}

pragam_to_strbuilder_ref :: proc(pragma : Code_Pragma, result : ^Str_Builder) {
	assert(pragma != nil)
	assert(result != nil)
	strbuilder_append_fmt_buf(result, "#pragma %s\n", pragma.content)
}

preprocess_to_strbuilder_if :: proc(cond : Code_Preprocess_Cond, result : ^Str_Builder) {
	assert(cond != nil)
	assert(result != nil)
	strbuilder_append_fmt_buf(result, "#if %s", cond.content)
}

preprocess_to_strbuilder_ifdef :: proc(cond : Code_Preprocess_Cond, result : ^Str_Builder) {
	assert(cond != nil)
	assert(result != nil)
	strbuilder_append_fmt_buf(result, "#ifdef %s\n", cond.content)
}

preprocess_to_strbuilder_ifndef :: proc(cond : Code_Preprocess_Cond, result : ^Str_Builder) {
	assert(cond != nil)
	assert(result != nil)
	strbuilder_append_fmt_buf(result, "#ifndef %s", cond.content)
}

preprocess_to_strbuilder_elif :: proc(cond : Code_Preprocess_Cond, result : ^Str_Builder) {
	assert(cond != nil)
	assert(result != nil)
	strbuilder_append_fmt_buf(result, "#elif %s\n", cond.content)
}

preprocess_to_strbuilder_else :: proc(cond : Code_Preprocess_Cond, result : ^Str_Builder) {
	assert(cond != nil)
	assert(result != nil)
	strbuilder_append_fmt_buf(result, "#else\n")
}

preprocess_to_strbuilder_endif :: proc(cond : Code_Preprocess_Cond, result : ^Str_Builder) {
	assert(cond != nil)
	assert(result != nil)
	strbuilder_append_fmt_buf(result, "#endif\n")
}

specifiers_to_strbuilder :: proc(specifiers : Code_Specifiers) -> Str_Builder {
	assert(specifiers != nil)
	result := strbuilder_make_reserve(_ctx.allocator_temp, 64)
	specifiers_to_strbuilder_ref(specifiers, & result)
	return result
}

template_to_strbuilder :: proc(template : Code_Template) -> Str_Builder {
	assert(template != nil)
	result := strbuilder_make_reserve(_ctx.allocator_temp, 1024)
	template_to_strbuilder_ref(template, & result)
	return result
}

typedef_to_strbuilder :: proc(typedef : Code_Typedef) -> Str_Builder {
	assert(typedef != nil)
	result := strbuilder_make_reserve(_ctx.allocator_temp, 128)
	typedef_to_strbuilder_ref(typedef, & result)
	return result
}

typename_to_strbuilder :: proc(typename : Code_Typename) -> Str_Builder {
	assert(typename != nil)
	result := strbuilder_make_reserve(_ctx.allocator_temp, 128)
	typename_to_strbuilder_ref(typename, & result)
	return result
}

using_to_strbuilder :: proc(code : Code_Using) -> Str_Builder {
	assert(code != nil)
	result := strbuilder_make_reserve(_ctx.allocator_temp, 128)
	#partial switch code.type {
		case .Using:
			using_to_strbuilder_ref(code, & result)
		case .Using_Namespace:
			using_to_strbuilder_ns(code, & result)
	}
	return result
}

using_to_strbuilder_ns :: proc(self : Code_Using, builder : ^Str_Builder) {
	assert(self != nil)
	assert(builder != nil)
	if self.inline_cmt != nil {
		strbuilder_append_fmt_buf(builder, "using namespace %s; %s", self.name, self.inline_cmt)
	}
	else {
		strbuilder_append_fmt_buf(builder, "using namespace %s;\n", self.name)
	}
}

var_to_strbuilder :: proc(var : Code_Var) -> Str_Builder {
	assert(var != nil)
	result := strbuilder_make_reserve(_ctx.allocator_temp, 256)
	var_to_strbuilder_ref(var, & result)
	return result
}

to_string :: proc {
	code_to_string,
	attributes_to_string,
	body_to_string,
	class_to_string,
	comment_to_string,
	constructor_to_string,
	define_to_string,
	define_params_to_string,
	destructor_to_string,
	enum_to_string,
	exec_to_string,
	extern_to_string,
	include_to_string,
	friend_to_string,
	fn_to_string,
	module_to_string,
	namespace_to_string,
	operator_to_string,
	opcast_to_string,
	params_to_string,
	preprocess_to_string,
	pragma_to_string,
	specifiers_to_string,
	struct_to_string,
	template_to_string,
	typename_to_string,
	typedef_to_string,
	union_to_string,
	var_to_string,
	strbuilder_to_string,
}

code_to_string          :: #force_inline proc(code        : Code)                 -> string { return strbuilder_to_string( code_to_strbuilder(code)) }
attributes_to_string    :: #force_inline proc(attributes  : Code_Attributes)      -> string { return strbuilder_to_string( attributes_to_strbuilder(attributes)) }
body_to_string          :: #force_inline proc(body        : Code_Body)            -> string { return strbuilder_to_string( body_to_strbuilder(body)) }
comment_to_string       :: #force_inline proc(comment     : Code_Comment)         -> string { return strbuilder_to_string( comment_to_strbuilder(comment)) }
constructor_to_string   :: #force_inline proc(constructor : Code_Constructor)     -> string { return strbuilder_to_string( constructor_to_strbuilder(constructor)) }
class_to_string         :: #force_inline proc(class       : Code_Class)           -> string { return strbuilder_to_string( class_to_strbuilder(class)) }
define_to_string        :: #force_inline proc(define      : Code_Define)          -> string { return strbuilder_to_string( define_to_strbuilder(define)) }
define_params_to_string :: #force_inline proc(params      : Code_DefineParams)    -> string { return strbuilder_to_string( define_params_to_strbuilder(params)) }
destructor_to_string    :: #force_inline proc(destructor  : Code_Destructor)      -> string { return strbuilder_to_string( destructor_to_strbuilder(destructor)) }
enum_to_string          :: #force_inline proc(code        : Code_Enum)            -> string { return strbuilder_to_string( enum_to_strbuilder(code)) }
exec_to_string          :: #force_inline proc(exec        : Code_Exec)            -> string { return strbuilder_to_string( exec_to_strbuilder(exec)) }
extern_to_string        :: #force_inline proc(extern      : Code_Extern)          -> string { return strbuilder_to_string( extern_to_strbuilder(extern)) }
include_to_string       :: #force_inline proc(include     : Code_Include)         -> string { return strbuilder_to_string( include_to_strbuilder(include)) }
friend_to_string        :: #force_inline proc(friend      : Code_Friend)          -> string { return strbuilder_to_string( friend_to_strbuilder(friend)) }
fn_to_string            :: #force_inline proc(fn          : Code_Fn)              -> string { return strbuilder_to_string( fn_to_strbuilder(fn)) }
module_to_string        :: #force_inline proc(module      : Code_Module)          -> string { return strbuilder_to_string( module_to_strbuilder(module)) }
namespace_to_string     :: #force_inline proc(namespace   : Code_NS)              -> string { return strbuilder_to_string( namespace_to_strbuilder(namespace)) }
operator_to_string      :: #force_inline proc(operator    : Code_Operator)        -> string { return strbuilder_to_string( operator_to_strbuilder(operator)) }
opcast_to_string        :: #force_inline proc(opcast      : Code_OpCast)          -> string { return strbuilder_to_string( opcast_to_strbuilder(opcast)) }
params_to_string        :: #force_inline proc(params      : Code_Params)          -> string { return strbuilder_to_string( params_to_strbuilder(params)) }
preprocess_to_string    :: #force_inline proc(cond        : Code_Preprocess_Cond) -> string { return strbuilder_to_string( preprocess_to_strbuilder(cond)) }
pragma_to_string        :: #force_inline proc(pragma      : Code_Pragma)          -> string { return strbuilder_to_string( pragma_to_strbuilder(pragma)) }
specifiers_to_string    :: #force_inline proc(specifiers  : Code_Specifiers)      -> string { return strbuilder_to_string( specifiers_to_strbuilder(specifiers)) }
struct_to_string        :: #force_inline proc(code        : Code_Struct)          -> string { return strbuilder_to_string( struct_to_strbuilder(code)) }
template_to_string      :: #force_inline proc(template    : Code_Template)        -> string { return strbuilder_to_string( template_to_strbuilder(template)) }
typename_to_string      :: #force_inline proc(typename    : Code_Typename)        -> string { return strbuilder_to_string( typename_to_strbuilder(typename)) }
typedef_to_string       :: #force_inline proc(typedef     : Code_Typedef)         -> string { return strbuilder_to_string( typedef_to_strbuilder(typedef)) }
union_to_string         :: #force_inline proc(code        : Code_Union)           -> string { return strbuilder_to_string( union_to_strbuilder(code)) }
var_to_string           :: #force_inline proc(var         : Code_Var)             -> string { return strbuilder_to_string( var_to_strbuilder(var)) }

type_str :: proc {
	code_type_str,
	attributes_type_str,
	body_type_str,
	class_type_str,
	comment_type_str,
	define_type_str,
	define_params_type_str,
	destructor_type_str,
	enum_type_str,
	exec_type_str,
	extern_type_str,
	include_type_str,
	friend_type_str,
	fn_type_str,
	module_type_str,
	namespace_type_str,
	operator_type_str,
	opcast_type_str,
	params_type_str,
	preprocess_type_str,
	pragma_type_str,
	specifiers_type_str,
	struct_type_str,
	template_type_str,
	typename_type_str,
	typedef_type_str,
	union_type_str,
	var_type_str,
}

attributes_type_str    :: #force_inline proc(self: Code_Attributes)      -> string { return code_type_str(transmute(Code) self) }
body_type_str          :: #force_inline proc(self: Code_Body)            -> string { return code_type_str(transmute(Code) self) }
class_type_str         :: #force_inline proc(self: Code_Class)           -> string { return code_type_str(transmute(Code) self) }
comment_type_str       :: #force_inline proc(self: Code_Comment)         -> string { return code_type_str(transmute(Code) self) }
define_type_str        :: #force_inline proc(self: Code_Define)          -> string { return code_type_str(transmute(Code) self) }
define_params_type_str :: #force_inline proc(self: Code_DefineParams)    -> string { return code_type_str(transmute(Code) self) }
destructor_type_str    :: #force_inline proc(self: Code_Destructor)      -> string { return code_type_str(transmute(Code) self) }
enum_type_str          :: #force_inline proc(self: Code_Enum)            -> string { return code_type_str(transmute(Code) self) }
exec_type_str          :: #force_inline proc(self: Code_Exec)            -> string { return code_type_str(transmute(Code) self) }
extern_type_str        :: #force_inline proc(self: Code_Extern)          -> string { return code_type_str(transmute(Code) self) }
include_type_str       :: #force_inline proc(self: Code_Include)         -> string { return code_type_str(transmute(Code) self) }
friend_type_str        :: #force_inline proc(self: Code_Friend)          -> string { return code_type_str(transmute(Code) self) }
fn_type_str            :: #force_inline proc(self: Code_Fn)              -> string { return code_type_str(transmute(Code) self) }
module_type_str        :: #force_inline proc(self: Code_Module)          -> string { return code_type_str(transmute(Code) self) }
namespace_type_str     :: #force_inline proc(self: Code_NS)              -> string { return code_type_str(transmute(Code) self) }
operator_type_str      :: #force_inline proc(self: Code_Operator)        -> string { return code_type_str(transmute(Code) self) }
opcast_type_str        :: #force_inline proc(self: Code_OpCast)          -> string { return code_type_str(transmute(Code) self) }
params_type_str        :: #force_inline proc(self: Code_Params)          -> string { return code_type_str(transmute(Code) self) }
preprocess_type_str    :: #force_inline proc(self: Code_Preprocess_Cond) -> string { return code_type_str(transmute(Code) self) }
pragma_type_str        :: #force_inline proc(self: Code_Pragma)          -> string { return code_type_str(transmute(Code) self) }
specifiers_type_str    :: #force_inline proc(self: Code_Specifiers)      -> string { return code_type_str(transmute(Code) self) }
struct_type_str        :: #force_inline proc(self: Code_Struct)          -> string { return code_type_str(transmute(Code) self) }
template_type_str      :: #force_inline proc(self: Code_Template)        -> string { return code_type_str(transmute(Code) self) }
typename_type_str      :: #force_inline proc(self: Code_Typename)        -> string { return code_type_str(transmute(Code) self) }
typedef_type_str       :: #force_inline proc(self: Code_Typedef)         -> string { return code_type_str(transmute(Code) self) }
union_type_str         :: #force_inline proc(self: Code_Union)           -> string { return code_type_str(transmute(Code) self) }
var_type_str           :: #force_inline proc(self: Code_Var)             -> string { return code_type_str(transmute(Code) self) }

validate_body :: proc {
	code__validate_body,
	body_validate_body,
}

body_validate_body :: #force_inline proc(body : Code_Body) -> bool { return code__validate_body(transmute(Code) body) }

code_append :: proc(self, other : Code) {
	assert(self != nil)
	assert(other != nil)
	assert(self != other)

	other := other
	if (other.parent != nil) {
		other = code_duplicate(other)
	}

	other.parent = self

	if (self.front == nil)
	{
		self.front = other
		self.back  = other
		self.num_entries += 1
		return
	}

	current     := self.back
	current.next = other
	other.prev   = current
	self.back    = other
	self.num_entries += 1
}

code_is_body :: proc(code : Code) -> bool {
	assert(code != nil)
	#partial switch(code.type) {
		case \
			.Enum_Body, 
			.Class_Body, 
			.Union_Body, 
			.Export_Body, 
			.Global_Body, 
			.Struct_Body, 
			.Function_Body, 
			.Namespace_Body, 
			.Extern_Linkage_Body: \
		return true
	}
	return false;
}

code_entry :: proc(self : Code, idx : u32) -> ^Code {
	assert(self != nil)
	idx     := idx
	current := & self.front
	for idx >= 0 && current != nil {
		if idx == 0 do return current

		(current^) = (current^).next
		idx -= 1
	}
	return current
}

code_is_valid :: #force_inline proc(self : Code) -> bool {
	assert(self != nil)
	return self != nil && self.type != .Invalid
}

code_has_entries :: #force_inline proc(self : Code) -> bool {
	assert(self != nil)
	return self.num_entries > 0
}

code_set_global :: #force_inline proc(self : Code) {
	assert(self != nil)
	self.parent = Code_Global
}

code_to_strbuilder :: #force_inline proc(self : Code) -> Str_Builder {
	result := strbuilder_make_reserve(_ctx.allocator_temp, mem.Kilobyte)
	code_to_strbuilder_ref(self, & result)
	return result
}

code_type_str :: #force_inline proc(self : Code) -> string {
	assert(self != nil)
	result, ok := reflect.enum_name_from_value(self.type)
	return result
}

body_append_code :: proc(body : Code_Body, other : Code) {
	assert(body != nil)
	assert(other != nil)
	if code_is_body(other) {
		body_append_body(body, transmute(Code_Body) other)
		return
	}
	code_append(cast(Code) body, other)
}

body_append_body :: proc(body, other : Code_Body) {
	assert(body != nil)
	assert(other != nil)
	assert(body != other)
	for entry := begin_body(body); entry != end_body(body); entry = next_body(body, entry) {
		body_append_code(body, entry)
	}
}

begin_body :: proc(body : Code_Body) -> Code { assert(body != nil)
	assert(body != nil)
	return body.front
}

end_body :: proc(body : Code_Body) -> Code {
	assert(body != nil)
	return body.back.next
}

next_body :: proc(body : Code_Body, code : Code) -> Code {
	assert(body != nil)
	assert(code != nil)
	assert(code.parent != (transmute(Code) body))
	return code.next
}

class_add_interface :: proc(class : Code_Class, type : Code_Typename) {
	assert(class != nil)
	assert(type != nil)

	possible_slot := class.parent_type
	if possible_slot != nil {
		class.parent_access = .Public
	}

	for possible_slot.next != nil {
		possible_slot = transmute(Code_Typename) possible_slot.next
	}

	possible_slot.next = transmute(Code) type;
}

params_append :: proc(appendee, other : Code_Params) {
	assert(appendee != nil)
	assert(other != nil)
	assert(appendee != other)
	self  := transmute(Code) appendee
	entry := transmute(Code) other

	if entry.parent != nil {
		entry = code__duplicate(entry);
	}

	if self.last == nil {
		self.last = entry
		self.next = entry
		self.num_entries += 1
	}

	self.last.next = entry
	self.last      = entry
	self.num_entries += 1
}

params_get :: proc(params : Code_Params, idx : i32) -> Code_Params {
	assert(params != nil)
	param := params
	idx   := idx
	for
	{
		if ( param.next != nil ) {
			return nil
		}

		param = param.next

		idx -= 1
		if idx <= 0 do break
	}
	return param
}

begin_params :: #force_inline proc(params : Code_Params) -> Code_Params {
	assert(params != nil)
	return params
}

end_params :: #force_inline proc(params : Code_Params) -> Code_Params {
	assert(params != nil)
	return nil
}

next_params :: #force_inline proc(params, params_iter : Code_Params) -> Code_Params {
	assert(params != nil)
	assert(params_iter != nil)
	return params_iter.next
}

// define_params_append      -> params_append
// define_params_get         -> params_get
// define_params_has_entries -> params_has_entries

define_params_append      :: #force_inline proc(appendee, other : Code_DefineParams)                        { params_append(transmute(Code_Params) appendee, transmute(Code_Params) other) }
define_params_get         :: #force_inline proc(params : Code_DefineParams, idx : i32) -> Code_DefineParams { return transmute(Code_DefineParams) params_get( transmute(Code_Params) params, idx) }
define_params_has_entires :: #force_inline proc(params : Code_DefineParams) -> bool                         { return params_has_entries(transmute(Code_Params) params) }

begin_define_params :: #force_inline proc(params : Code_DefineParams) -> Code_DefineParams {
	assert(params != nil)
	return params
}

end_define_params :: #force_inline proc(params : Code_DefineParams) -> Code_DefineParams {
	assert(params != nil)
	return nil
}

next_define_params :: #force_inline proc(params, params_iter : Code_DefineParams) -> Code_DefineParams {
	assert(params != nil)
	assert(params_iter != nil)
	return params_iter.next
}

specifiers_append :: proc(self : Code_Specifiers, spec : Specifier) -> bool {
	assert(self != nil)
	assert(self.num_entries < AST_ARRAY_SPECS_CAP)

	self.arr_specs[self.num_entries] = spec
	self.num_entries += 1
	return true
}

specifiers_has :: proc(self : Code_Specifiers, spec : Specifier) -> bool {
	assert(self != nil)
	for idx : i32 = 0; idx < self.num_entries; idx += 1 {
		if self.arr_specs[idx] == spec {
			return true
		}
	}
	return false
}

specifiers_index_of :: proc(self : Code_Specifiers, spec : Specifier) -> i32 {
	assert(self != nil)
	for idx : i32 = 0; idx < self.num_entries; idx += 1 {
		if self.arr_specs[idx] == spec {
			return idx
		}
	}
	return -1
}

specifiers_remove :: proc(self : Code_Specifiers, to_remove : Specifier) -> i32 {
	assert(self != nil)
	assert(self.num_entries < AST_ARRAY_SPECS_CAP)

	result : i32 = -1

	curr : i32 = 0
	next : i32 = 0
	for next < self.num_entries
	{
		spec := self.arr_specs[next]
		if spec == to_remove {
			result = next

			next += 1
			if next >= self.num_entries do break

			spec = self.arr_specs[next]
		}

		self.arr_specs[curr] = spec

		curr += 1
		next += 1
	}

	if result > -1 {
		self.num_entries -= 1
	}
	return result
}

begin_specifiers :: #force_inline proc(self : Code_Specifiers) -> Specifier {
	assert(self != nil)
	return self.arr_specs[0]
}

end_specifiers :: #force_inline proc(self : Code_Specifiers) -> Specifier {
	return .Invalid
}

next_specifiers :: #force_inline proc(self : Code_Specifiers, spec : ^Specifier) -> ^Specifier {
	return mem.ptr_offset(spec, 1)
}

struct_add_interface :: #force_inline proc(self : Code_Struct, type : Code_Typename) { class_add_interface(transmute(Code_Class) self, type) }

code_debug_str         :: code__debug_str
code_duplicate         :: code__duplicate
code_is_equal          :: code__is_equal
code_to_strbuilder_ref :: code__to_strbuilder_ref
code_validate_body     :: code__validate_body

operator_to_strbuilder     :: code_op_to_strbuilder
operator_to_strbuilder_def :: code_op_to_strbuilder_def
operator_to_strbuilder_fwd :: code_op_to_strbuilder_fwd

@(default_calling_convention="c", link_prefix="gen_")
foreign gencpp_c11
{
	code__debug_str         :: proc(code : Code)                         -> string ---
	code__duplicate         :: proc(code : Code)                         -> Code ---
	code__is_equal          :: proc(code : Code)                         -> bool ---
	code__to_strbuilder_ref :: proc(code : Code, buiider : ^Str_Builder) -> Str_Builder ---
	code__validate_body     :: proc(code : Code)                         -> bool ---

	body_to_strbuilder        :: proc(body : Code_Body) -> Str_Builder ---
	body_to_strbuilder_ref    :: proc(body : Code_Body, builder : ^Str_Builder) ---
	body_to_strbuilder_export :: proc(body : Code_Body, builder : ^Str_Builder) ---

	class_to_strbuilder     :: proc(class : Code_Class) -> Str_Builder ---
	class_to_strbuilder_fwd :: proc(class : Code_Class, builder : ^Str_Builder) ---
	class_to_strbuilder_def :: proc(class : Code_Class, builder : ^Str_Builder) ---

	define_to_strbuilder_ref :: proc(define : Code_Define, builder : ^Str_Builder) ---

	define_params_to_strbuilder_ref :: proc(params : Code_DefineParams, builder : ^Str_Builder) ---

	params_to_strbuilder_ref :: proc(params : Code_Params, builder : ^Str_Builder) ---

	specifiers_to_strbuilder_ref :: proc(specifiers : Code_Specifiers, builder : ^Str_Builder) ---

	struct_to_strbuilder     :: proc(code : Code_Struct) -> Str_Builder ---
	struct_to_strbuilder_fwd :: proc(code : Code_Struct, result : ^Str_Builder) ---
	struct_to_strbuilder_def :: proc(code : Code_Struct, result : ^Str_Builder) ---

	constructor_to_strbuilder     :: proc(code : Code_Constructor) -> Str_Builder ---
	constructor_to_strbuilder_def :: proc(code : Code_Constructor, result : ^Str_Builder) ---
	constructor_to_strbuilder_fwd :: proc(code : Code_Constructor, result : ^Str_Builder) ---

	destructor_to_strbuilder     :: proc(code : Code_Destructor) -> Str_Builder ---
	destructor_to_strbuilder_fwd :: proc(code : Code_Destructor, result : ^Str_Builder) ---
	destructor_to_strbuilder_def :: proc(code : Code_Destructor, result : ^Str_Builder) ---

	enum_to_strbuilder           :: proc(code : Code_Enum) -> Str_Builder ---
	enum_to_strbuilder_fwd       :: proc(code : Code_Enum, result : ^Str_Builder) ---
	enum_to_strbuilder_def       :: proc(code : Code_Enum, result : ^Str_Builder) ---
	enum_to_strbuilder_class_fwd :: proc(code : Code_Enum, result : ^Str_Builder) ---
	enum_to_strbuilder_class_def :: proc(code : Code_Enum, result : ^Str_Builder) ---

	fn_to_strbuilder     :: proc(code : Code_Fn) -> Str_Builder ---
	fn_to_strbuilder_def :: proc(code : Code_Fn, result : ^Str_Builder) ---
	fn_to_strbuilder_fwd :: proc(code : Code_Fn, result : ^Str_Builder) ---

	module_to_strbuilder_ref :: proc(code : Code_Module, result : ^Str_Builder) ---

	code_op_to_strbuilder     :: proc(operator : Code_Operator) -> Str_Builder ---
	code_op_to_strbuilder_def :: proc(operator : Code_Operator, result : ^Str_Builder) ---
	code_op_to_strbuilder_fwd :: proc(operator : Code_Operator, result : ^Str_Builder) ---

	opcast_to_strbuilder     :: proc(opcast : Code_OpCast) -> Str_Builder ---
	opcast_to_strbuilder_def :: proc(opcast : Code_OpCast, result : ^Str_Builder) ---
	opcast_to_strbuilder_fwd :: proc(opcast : Code_OpCast, result : ^Str_Builder) ---

	pragma_to_strbuilder_ref :: proc(pragma : Code_Pragma, result : ^Str_Builder) ---

	preprocess_to_strbuilder :: proc(cond : Code_Preprocess_Cond) -> Str_Builder ---

	template_to_strbuilder_ref :: proc(template : Code_Template, result : ^Str_Builder) ---

	typename_to_strbuilder_ref :: proc(type : Code_Typename, result : ^Str_Builder) ---

	typedef_to_strbuilder_ref :: proc(typedef : Code_Typedef, result : ^Str_Builder) ---

	union_to_strbuilder     :: proc(code : Code_Union) -> Str_Builder ---
	union_to_strbuilder_def :: proc(code : Code_Union, result : ^Str_Builder) ---
	union_to_strbuilder_fwd :: proc(code : Code_Union, result : ^Str_Builder) ---

	using_to_strbuilder_ref :: proc(code : Code_Using, result : ^Str_Builder) ---

	var_to_strbuilder_ref :: proc(self : Code_Var, builder : ^Str_Builder) ---
}
//#endregion("Code Interface")

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
//#region("AST Types")

AST_Body :: struct {
	using _ : struct {
		_PAD_ : [64]byte,
	},
	name         : string_cached,
	front        : Code,
	back         : Code,
	token        : ^Token,
	parent       : Code,
	type         : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flag)]byte,
	num_entries  : i32,
}

AST_Attributes :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		content : string_cached,
	},
	name   : string_cached,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flag) + size_of(u32)]byte
}

AST_Comment :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		content : string_cached,
	},
	name   : string_cached,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flag) + size_of(u32)]byte
}

AST_Class :: struct {
	using _ : struct #raw_union {
		_PAD_ : [64]byte,
		using _ : struct {
			inline_cmt    : Code_Comment,
			attributes    : Code_Attributes,
			specs         : Code_Specifiers,
			parent_type   : Code_Typename,
			_PAD_PARARMS_ : [ size_of(Code) ]byte,
			body          : Code_Body,
			_PAD_PROPERTIES_2_ : [size_of(Code) ]byte,
		}
	},
	name          : string_cached,
	prev          : Code,
	next          : Code,
	token         : ^Token,
	parent        : Code,
	type          : Code_Type,
	moule_flags   : Module_Flags,
	parent_access : Access_Spec,
}

AST_Constructor :: struct {
	using _ : struct #raw_union {
		_PAD_ : [64]byte,
		using _ : struct {
			inline_cmt       : Code_Comment,
			_PAD_PROPERTIES_ : [size_of(Code)]byte,
			specs            : Code_Specifiers,
			initializer_list : Code,
			params           : Code_Params,
			body             : Code,
			_PAD_PROPERTIES_2_ : [size_of(Code) * 2]byte,
		}
	},
	name   : string_cached,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flag) + size_of(u32)]byte
}

AST_Define :: struct {
	using _ : struct #raw_union {
		_PAD_ : [64]byte,
		using _ : struct {
			_PAD_PROPERTIES_ : [size_of(Code) * 4]byte,
			params : Code_DefineParams,
			body   : Code,
			_PAD_PROPERTIES_2_ : [size_of(Code)]byte,
		},
	},
	name   : string_cached,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flag) + size_of(u32)]byte,
}

AST_Define_Params :: struct {
	using _ : struct #raw_union {
		_PAD_ : [64]byte,
	},
	name        : string_cached,
	prev        : Code_DefineParams,
	next        : Code_DefineParams,
	token       : ^Token,
	parent      : Code,
	type        : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flag)]byte,
	num_entries : i32,
}

AST_Destructor :: struct {
	using _ : struct #raw_union {
		_PAD_ : [64]byte,
		using _ : struct {
			inline_cmt         : Code_Comment,
			_PAD_PROPERTIES    : [size_of(Code)]byte,
			specs              : Code_Specifiers,
			_PAD_PROPERTIES_2_ : [size_of(Code) * 2]byte,
			body               : Code,
			_PAD_PROPERTIES_3_ : [size_of(Code)]byte,
		},
	},
	name   : string_cached,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flag) + size_of(u32)]byte,
}

AST_Enum :: struct {
	using _ : struct #raw_union {
		_PAD_ : [64]byte,
		using _ : struct {
			inline_cmt            : Code_Comment,
			attributes            : Code_Attributes,
			_PAD_SPEC_            : [size_of(Code)]byte,
			underlying_type       : Code_Typename,
			underlying_type_macro : Code,
			body                  : Code_Body,
			_PAD_PROPERTIES_2_    : [size_of(Code)]byte,
		},
	},
	name        : string_cached,
	prev        : Code,
	next        : Code,
	token       : ^Token,
	parent      : Code,
	type        : Code_Type,
	module_flag : Module_Flags,
	_PAD_UNUSED_ : [size_of(u32)]byte,
}

AST_Exec :: struct {
	using _ : struct #raw_union {
		_PAD_ : [64]byte,
		content : string_cached
	},
	name   : string_cached,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flag) + size_of(u32)]byte,
}

AST_Extern :: struct {
	using _ : struct #raw_union {
		_PAD_ : [64]byte,
		using _ : struct {
			_PAD_PROPERTIES_   : [size_of(Code) * 5]byte,
			body               : Code_Body,
			_PAD_PROPERTIES_2_ : [size_of(Code)]byte,
		},
	},
	name   : string_cached,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flag) + size_of(u32)]byte,
}

AST_Include :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		content : string_cached,
	},
	name   : string_cached,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flags) + size_of(u32)]byte,
}

AST_Friend :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			inline_cmt : Code_Comment,
			_PAD_PROPRTIES_ : [size_of(Code)]byte,
			declaration : Code,
			_PAD_PROPERTIES_ : [size_of(Code)]byte,
		},
	},
	name   : string_cached,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flags) + size_of(u32)]byte,
}

AST_Fn :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
	},
	name         : string_cached,
	prev         : Code,
	next         : Code,
	token        : ^Token,
	parent       : Code,
	type         : Code_Type,
	module_flags : Module_Flags,
	_PAD_UNUSED_ : [size_of(u32)]byte,
}

AST_Module :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
	},
	name         : string_cached,
	prev         : Code,
	next         : Code,
	token        : ^Token,
	parent       : Code,
	type         : Code_Type,
	module_flags : Module_Flags,
	_PAD_UNUSED_ : [size_of(u32)]byte,
}

AST_NS :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			_PAD_PROPRTIES_ : [size_of(Code) * 5]byte,
			body : Code_Body,
			_PAD_PROPERTIES_ : [size_of(Code)]byte,
		},
	},
	name         : string_cached,
	prev         : Code,
	next         : Code,
	token        : ^Token,
	parent       : Code,
	type         : Code_Type,
	module_flags : Module_Flags,
	_PAD_UNUSED_ : [size_of(u32)]byte,
}

AST_Operator :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			inline_cmt  : Code_Comment,
			attributes  : Code_Attributes,
			specs       : Code_Specifiers,
			return_type : Code_Typename,
			params      : Code_Params,
			body        : Code_Body,
			_PAD_PROPERTIES_ : [size_of(Code)]byte,
		},
	},
	name        : string_cached,
	prev        : Code,
	next        : Code,
	token       : ^Token,
	parent      : Code,
	type        : Code_Type,
	module_flag : Module_Flags,
	operator    : Operator,
}

AST_Op_Cast :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			inline_cmt         : Code_Comment,
			_PAD_PROPERTIES_   : [size_of(Code)]byte,
			specs              : Code_Specifiers,
			value_type         : Code_Typename,
			_PAD_PROPERTIES_2_ : [size_of(Code)]byte,
			body               : Code_Body,
			_PAD_PROPERTIES_3_ : [size_of(Code)]byte,
		},
	},
	name   : string_cached,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flags) + size_of(u32)]byte,
}

AST_Params :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			_PAD_PROPERTIES_2_ : [size_of(Code) * 3]byte,
			value_type         : Code_Typename,
			macro              : Code,
			value              : Code,
			post_name_macro    : Code,
		},
	},
	name        : string_cached,
	prev        : Code_Params,
	next        : Code_Params,
	token       : ^Token,
	parent      : Code,
	type        : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flags)]byte,
	num_entries : i32,
}

AST_Pragma :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		content : string_cached,
	},
	name        : string_cached,
	prev        : Code,
	next        : Code,
	token       : ^Token,
	parent      : Code,
	type        : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flags) + size_of(u32)]byte,
}

AST_Preprocess_Cond :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		content : string_cached,
	},
	name        : string_cached,
	prev        : Code,
	next        : Code,
	token       : ^Token,
	parent      : Code,
	type        : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flags) + size_of(u32)]byte,
}

AST_Specifiers :: struct {
	arr_specs   : [AST_ARRAY_SPECS_CAP]Specifier,
	next_specs  : Code,
	name        : string_cached,
	prev        : Code,
	next        : Code,
	token       : ^Token,
	parent      : Code,
	type        : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flags)]byte,
	num_entries : i32,
}

AST_Struct :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			inline_cmt   : Code_Comment,
			attributes   : Code_Attributes,
			specs        : Code_Specifiers,
			parent_type  : Code_Typename,
			_PAD_PARAMS_ : [size_of(Code)]byte,
			body         : Code_Body,
			_PAD_PROPERTIES_2_ : [size_of(Code)]byte,
		},
	},
	name         : string_cached,
	prev         : Code_Typename,
	next         : Code_Typename,
	token        : ^Token,
	parent       : Code,
	type         : Code_Type,
	module_flags : Module_Flags,
	num_entries  : i32,
}

AST_Template :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			_PAD_PROPERTIES_ : [size_of(Code)* 4]byte,
			params      : Code_Params,
			declaration : Code,
			_PAD_PROPERTIES_2_ : [size_of(Code)]byte,
		},
	},
	name         : string_cached,
	prev         : Code_Typename,
	next         : Code_Typename,
	token        : ^Token,
	parent       : Code,
	type         : Code_Type,
	module_flags : Module_Flags,
	_PAD_UNUSED_ : [size_of(u32)]byte,
}

AST_Typename :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			_PAD_INLINE_CMT_  : [size_of(Code)]byte,
			attributes        : Code_Attributes,
			specs             : Code_Specifiers,
			return_type       : Code_Typename,
			params            : Code_Params,
			arr_expr          : Code,
			specs_func_suffix : Code_Specifiers,
		},
	},
	name   : string_cached,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [size_of(Module_Flags)]byte,
	using _ : struct {
		is_param_pack : b16,
		type_tag      : Typename_Tag,
	}
}

AST_Typedef :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			inline_cmt         : Code_Comment,
			_PAD_PROPERTIES_   : [size_of(Code) * 2]byte,
			underlying_type    : Code,
			_PAD_PROPERTIES_2_ : [size_of(Code) * 3]byte,
		},
	},
	name         : string_cached,
	prev         : Code,
	next         : Code,
	token        : ^Token,
	parent       : Code,
	type         : Code_Type,
	module_flags : Module_Flags,
	is_function  : b32,
}

AST_Union :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			_PAD_INLINE_CMT_   : [size_of(Code)]byte,
			attributes         : Code_Attributes,
			_PAD_PROPERTIES_   : [size_of(Code) * 3]byte,
			body               : Code_Body,
			_PAD_PROPERTIES_2_ : [size_of(Code)]byte,
		},
	},
	name         : string_cached,
	prev         : Code,
	next         : Code,
	token        : ^Token,
	parent       : Code,
	type         : Code_Type,
	module_flags : Module_Flags,
	_PAD_UNUSED_ : [size_of(u32)]byte,
}

AST_Using :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			inline_cmt       : Code_Comment,
			attributes       : Code_Attributes,
			_PAD_SPECS_      : [size_of(Code)]byte,
			underlying_type  : Code_Typename,
			_PAD_PROPERTIES_ : [size_of(Code)]byte,
		},
	},
	name         : string_cached,
	prev         : Code,
	next         : Code,
	token        : ^Token,
	parent       : Code,
	type         : Code_Type,
	module_flags : Module_Flags,
	_PAD_UNUSED_ : [size_of(u32)]byte,
}

AST_Var :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			inline_cmt    : Code_Comment,
			attributes    : Code_Attributes,
			specs         : Code_Specifiers,
			value_type    : Code_Typename,
			bitfield_size : Code,
			value         : Code,
			next_var      : Code_Var,
		},
	},
	name                    : string_cached,
	prev                    : Code,
	next                    : Code,
	token                   : ^Token,
	parent                  : Code,
	type                    : Code_Type,
	module_flags            : Module_Flags,
	var_parenthesiszed_init : i32,
}

when EXECUTION_SUPPORT {
	// Eventually this will be fleshed out...
}
//#endregion("AST Types")

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
//#region("Gen Interface")

Context :: struct {
	// Data Allocation

	allocator_dynamic_containers : Allocator_Info,
	allocator_pool               : Allocator_Info,
	allocator_str_cache          : Allocator_Info,
	allocator_temp               : Allocator_Info,

	// Initialization Config

	max_comment_line_length : u32,
	max_str_cache_length    : u32,

	init_size_builder_buffer      : u32,
	init_size_code_pools_array    : u32,
	init_size_string_arenas_array : u32,

	code_pool_num_blocks : u32,

	init_size_lexer_tokens : u32,
	size_per_string_arena  : u32,

	// Parser

	macros : Macro_Table,

	// Backend

	init_size_fallback_allocator_bucket_size : u32,
	fallback_allocator_buckets               : Array(Arena),

	token_fmt_map : String_Table,

	code_pools : Array(Pool),
	code_arena : Array(Arena),

	str_cache : String_Table,

	lexer_tokens : Array(Token),

	parser : Parse_Context,

	temp_serialized_indent : i32,
}

get_context :: #force_inline proc() -> ^Context {
	return _ctx
}

set_context :: #force_inline proc(ctx : ^Context) {
	_ctx = ctx
}

def_body :: proc(type : Code_Type) -> Code_Body {
	valid_def : b32 
	valid_def |= type == .Class_Body
	valid_def |= type == .Enum_Body
	valid_def |= type == .Export_Body
	valid_def |= type == .Extern_Linkege
	valid_def |= type == .Function_Body
	valid_def |= type == .Global_Body
	valid_def |= type == .Namespace_Body
	valid_def |= type == .Struct_Body
	valid_def |= type == .Union_Body
	assert(valid_def != false)

	result     := transmute(Code_Body) make_code()
	result.type = type
	return result
}

token_fmt :: proc() -> string {
	return ""
}

Opts_Def_Struct :: struct {
	body           : Code_Body,
	parent         : Code_Typename,
	parent_access  : Access_Spec,
	attributes     : Code_Attributes,
	interfaces     : [^]Code_Typename,
	num_interfaces : i32,
	specifiers     : Code_Specifiers,
	mflags         : Module_Flags,
}

def_class :: #force_inline proc(name : string, 
	body           : Code_Body       = nil,
	parent         : Code_Typename   = nil,
	parent_access  : Access_Spec     = .Default,
	attributes     : Code_Attributes = nil,
	interfaces     : []Code_Typename = nil,
	specifiers     : Code_Specifiers = nil,
	mflags         : Module_Flags    = {},
) -> Code_Class
{
	opts := Opts_Def_Struct {
		body,
		parent,
		parent_access,
		attributes,
		raw_data(interfaces),
		cast(i32) len(interfaces),
		specifiers,
		mflags
	}
	return def__class(name, opts)
}

def_struct :: #force_inline proc(name : string, 
	body           : Code_Body       = nil,
	parent         : Code_Typename   = nil,
	parent_access  : Access_Spec     = .Default,
	attributes     : Code_Attributes = nil,
	interfaces     : []Code_Typename = nil,
	specifiers     : Code_Specifiers = nil,
	mflags         : Module_Flags    = {},
) -> Code_Struct
{
	opts := Opts_Def_Struct {
		body,
		parent,
		parent_access,
		attributes,
		raw_data(interfaces),
		cast(i32) len(interfaces),
		specifiers,
		mflags
	}
	return def__struct(name, opts)
}

Opts_Def_Constructor :: struct {
	params           : Code_Params,
	initializer_list : Code,
	body             : Code_Body,
}

def_constructor :: #force_inline proc(
	params           : Code_Params = nil, 
	initializer_list : Code        = nil, 
	body             : Code_Body   = nil
) -> Code_Constructor 
{
	opts := Opts_Def_Constructor {
		params, initializer_list, body
	}
	return def__constructor(opts)
} 

Opts_Def_Define :: struct {
	params  : Code_DefineParams,
	content : string,
	flags   : Macro_Flags,
	dont_register_to_preprocess_macros : b32,
}

def_define :: #force_inline proc(name : string, type : Macro_Type,
	params  : Code_DefineParams = nil,
	content : string            = "",
	flags   : Macro_Flags       = {},
	dont_register_to_preprocess_macros : b32 = false
) -> Code_Define
{
	opts := Opts_Def_Define {
		params, 
		content, 
		flags, 
		dont_register_to_preprocess_macros
	}
	return def__define(name, type, opts)
}

Opts_Def_Destructor :: struct {
	body       : Code,
	specifiers : Code_Specifiers,
}

def_destructor :: #force_inline proc(body : Code = nil, specifiers : Code_Specifiers = nil) -> Code_Destructor {
	opts := Opts_Def_Destructor {
		body,
		specifiers
	}
	return def__destructor(opts)
}

Opts_Def_Enum :: struct {
	body       : Code_Body,
	type       : Code_Typename,
	specifier  : Enum_Decl,
	attributes : Code_Attributes,
	mflags     : Module_Flags,
	type_macro : Code,
}

def_enum :: #force_inline proc(
	name       : string,
	body       : Code_Body       = nil,
	type       : Code_Typename   = nil,
	specifier  : Enum_Decl       = .Regular,
	attributes : Code_Attributes = nil,
	mflags     : Module_Flags    = {},
	type_macro : Code            = nil,
) -> Code_Enum
{
	opts := Opts_Def_Enum {
		body,
		type,
		specifier,
		attributes,
		mflags,
		type_macro,
	}
	return def__enum(name, opts)
}

Opts_Def_Function :: struct {
	params     : Code_Params,
	ret_type   : Code_Typename,
	body       : Code_Body,
	specs      : Code_Specifiers,
	attributes : Code_Attributes,
	mflags     : Module_Flags,
}

def_function :: #force_inline proc(
	name       : string,
	params     : Code_Params     = nil,
	ret_type   : Code_Typename   = nil,
	body       : Code_Body       = nil,
	specs      : Code_Specifiers = nil,
	attributes : Code_Attributes = nil,
	mflags     : Module_Flags    = {},
) -> Code_Fn
{
	opts := Opts_Def_Function {
		params,
		ret_type,
		body,
		specs,
		attributes,
		mflags,
	}
	return def__function(name, opts)
}

Opts_Def_Include   :: struct { is_foreign : b32 } 
Opts_Def_Module    :: struct { mflags     : Module_Flags }
Opts_Def_Namespace :: struct { mflags     : Module_Flags }

def_include :: #force_inline proc(
	content    : string,
	is_foreign : b32 = false,
) -> Code_Include
{
	opts := Opts_Def_Include {
		is_foreign,
	}
	return def__include(content, opts)
}

def_module :: #force_inline proc(
	name   : string,
	mflags : Module_Flags = {},
) -> Code_Module
{
	opts := Opts_Def_Module {
		mflags,
	}
	return def__module(name, opts)
}

def_namespace :: #force_inline proc(
	name   : string,
	body   : Code_Body,
	mflags : Module_Flags = {},
) -> Code_NS
{
	opts := Opts_Def_Namespace {
		mflags,
	}
	return def__namespace(name, body, opts)
}

Opts_Def_Operator :: struct {
	params     : Code_Params,
	ret_type   : Code_Typename,
	body       : Code_Body,
	specifiers : Code_Specifiers,
	attributes : Code_Attributes,
	mflags     : Module_Flags,
}

def_operator :: #force_inline proc(
	op         : Operator,
	nspace     : string,
	params     : Code_Params     = nil,
	ret_type   : Code_Typename   = nil,
	body       : Code_Body       = nil,
	specifiers : Code_Specifiers = nil,
	attributes : Code_Attributes = nil,
	mflags     : Module_Flags    = {},
) -> Code_Operator
{
	opts := Opts_Def_Operator {
		params,
		ret_type,
		body,
		specifiers,
		attributes,
		mflags,
	}
	return def__operator(op, nspace, opts)
}

Opts_Def_OpCast :: struct {
	body  : Code_Body,
	specs : Code_Specifiers,
}

def_opcast :: #force_inline proc(
	type  : Code_Typename,
	body  : Code_Body       = nil,
	specs : Code_Specifiers = nil,
) -> Code_OpCast
{
	opts := Opts_Def_OpCast {
		body,
		specs,
	}
	return def__operator_cast(type, opts)
}

Opts_Def_Param    :: struct { value  : Code }
Opts_Def_Template :: struct { mflags : Module_Flags }

def_param :: #force_inline proc(
	type : Code_Typename,
	name : string,
	value: Code = nil,
) -> Code_Params
{
	opts := Opts_Def_Param {
		value,
	}
	return def__param(type, name, opts)
}

def_template :: #force_inline proc(
	params     : Code_Params,
	definition : Code,
	mflags     : Module_Flags = {},
) -> Code_Template
{
	opts := Opts_Def_Template {
		mflags,
	}
	return def__template(params, definition, opts)
}

Opts_Def_Type :: struct {
	type_tag   : Typename_Tag,
	array_expr : Code,
	specifiers : Code_Specifiers,
	attributes : Code_Attributes,
}

def_type :: #force_inline proc(
	name       : string,
	type_tag   : Typename_Tag   = .None,
	array_expr : Code           = nil,
	specifiers : Code_Specifiers = nil,
	attributes : Code_Attributes = nil,
) -> Code_Typename
{
	opts := Opts_Def_Type {
		type_tag,
		array_expr,
		specifiers,
		attributes,
	}
	return def__type(name, opts)
}

Opts_Def_Typedef :: struct {
	attributes : Code_Attributes,
	mflags     : Module_Flags,
}

def_typedef :: #force_inline proc(
	name       : string,
	type       : Code,
	attributes : Code_Attributes = nil,
	mflags     : Module_Flags    = {},
) -> Code_Typedef
{
	opts := Opts_Def_Typedef {
		attributes,
		mflags,
	}
	return def__typedef(name, type, opts)
}

Opts_Def_Union :: struct {
	attributes : Code_Attributes,
	mflags     : Module_Flags,
}

def_union :: #force_inline proc(
	name       : string,
	body       : Code_Body,
	attributes : Code_Attributes = nil,
	mflags     : Module_Flags    = {},
) -> Code_Union
{
	opts := Opts_Def_Union {
		attributes,
		mflags,
	}
	return def__union(name, body, opts)
}

Opts_Def_Using :: struct {
	attributes : Code_Attributes,
	mflags     : Module_Flags,
}

def_using :: #force_inline proc(
	name       : string,
	type       : Code_Typename,
	attributes : Code_Attributes = nil,
	mflags     : Module_Flags    = {},
) -> Code_Using
{
	opts := Opts_Def_Using {
		attributes,
		mflags,
	}
	return def__using(name, type, opts)
}

Opts_Def_Variable :: struct {
	value      : Code,
	specifiers : Code_Specifiers,
	attributes : Code_Attributes,
	mflags     : Module_Flags,
}

def_variable :: #force_inline proc(
	type       : Code_Typename,
	name       : string,
	value      : Code            = nil,
	specifiers : Code_Specifiers = nil,
	attributes : Code_Attributes = nil,
	mflags     : Module_Flags    = {},
) -> Code_Var
{
	opts := Opts_Def_Variable {
		value,
		specifiers,
		attributes,
		mflags,
	}
	return def__variable(type, name, opts)
}

def_class_body       :: #force_inline proc(codes  : []Code)              -> Code_Body         { return def_class_body_arr      (cast(i32) len(codes),  raw_data(codes)) }
def_define_params    :: #force_inline proc(params : []Code_DefineParams) -> Code_DefineParams { return def_define_params_arr   (cast(i32) len(params), raw_data(params)) }
def_enum_body        :: #force_inline proc(codes  : []Code)              -> Code_Body         { return def_enum_body_arr       (cast(i32) len(codes),  raw_data(codes)) }
def_export_body      :: #force_inline proc(codes  : []Code)              -> Code_Body         { return def_export_body_arr     (cast(i32) len(codes),  raw_data(codes)) }
def_extern_link_body :: #force_inline proc(codes  : []Code)              -> Code_Body         { return def_extern_link_body_arr(cast(i32) len(codes),  raw_data(codes)) }
def_function_body    :: #force_inline proc(codes  : []Code)              -> Code_Body         { return def_function_body_arr   (cast(i32) len(codes),  raw_data(codes)) }
def_global_body      :: #force_inline proc(codes  : []Code)              -> Code_Body         { return def_global_body_arr     (cast(i32) len(codes),  raw_data(codes)) }
def_namespace_body   :: #force_inline proc(codes  : []Code)              -> Code_Body         { return def_namespace_body_arr  (cast(i32) len(codes),  raw_data(codes)) }
def_params           :: #force_inline proc(params : []Code_Params)       -> Code_Params       { return def_params_arr          (cast(i32) len(params), raw_data(params)) }
def_specifiers       :: #force_inline proc(specs  : []Specifier)         -> Code_Specifiers   { return def_specifiers_arr      (cast(i32) len(specs),  raw_data(specs)) }
def_struct_body      :: #force_inline proc(codes  : []Code)              -> Code_Body         { return def_struct_body_arr     (cast(i32) len(codes),  raw_data(codes)) }
def_union_body       :: #force_inline proc(codes  : []Code)              -> Code_Body         { return def_union_body_arr      (cast(i32) len(codes),  raw_data(codes)) }

@(default_calling_convention="c", link_prefix="gen_")
foreign gencpp_c11
{
	init   :: proc(ctx : ^Context) ---
	deinit :: proc(ctx : ^Context) ---

	reset :: proc(ctx : ^Context) ---

	lookup_macro :: proc(name : string) -> ^Macro ---

	register_macro      :: proc(macro : Macro) ---
	register_macros_arr :: proc(num : i32, macros : [^]Macro) ---

	cache_str :: proc(str : string) -> string_cached ---

	make_code :: proc() -> Code ---

	def_attributes      :: proc(content : string) -> Code_Attributes ---
	def_comment         :: proc(content : string) -> Code_Comment ---
	def_execution       :: proc(content : string) -> Code_Exec ---
	def_extern_link     :: proc(name : string, body : Code_Body) -> Code_Extern ---
	def_friend          :: proc(signature : Code) -> Code_Friend ---
	def_pragma          :: proc() ---
	def_preprocess_cond :: proc() ---
	def_specifier       :: proc() ---
	def_using_namespace :: proc(name : string) -> Code_Using ---

	def__class         :: proc(name : string,                           opts : Opts_Def_Struct)      -> Code_Class ---
	def__constructor   :: proc(                                         opts : Opts_Def_Constructor) -> Code_Constructor ---
	def__define        :: proc(name : string, type : Macro_Type,        opts : Opts_Def_Define)      -> Code_Define ---
	def__destructor    :: proc(                                         opts : Opts_Def_Destructor)  -> Code_Destructor ---
	def__enum          :: proc(name : string,                           opts : Opts_Def_Enum)        -> Code_Enum ---
	def__function      :: proc(name : string,                           opts : Opts_Def_Function)    -> Code_Fn ---
	def__include       :: proc(content : string,                        opts : Opts_Def_Include)     -> Code_Include ---
	def__module        :: proc(name : string,                           opts : Opts_Def_Module)      -> Code_Module ---
	def__namespace     :: proc(name : string, body : Code_Body,         opts : Opts_Def_Namespace)   -> Code_NS ---
	def__operator      :: proc(op : Operator, nspace : string,          opts : Opts_Def_Operator)    -> Code_Operator ---
	def__operator_cast :: proc(type : Code_Typename,                    opts : Opts_Def_OpCast)      -> Code_OpCast ---
	def__param         :: proc(type : Code_Typename, name : string,     opts : Opts_Def_Param)       -> Code_Params ---
	def__struct        :: proc(name : string,                           opts : Opts_Def_Struct)      -> Code_Struct ---
	def__template      :: proc(params : Code_Params, definition : Code, opts : Opts_Def_Template)    -> Code_Template ---
	def__type          :: proc(name : string,                           opts : Opts_Def_Type)        -> Code_Typename ---
	def__typedef       :: proc(name : string, type : Code,              opts : Opts_Def_Typedef)     -> Code_Typedef ---
	def__using         :: proc(name : string, type : Code_Typename,     opts : Opts_Def_Using)       -> Code_Using ---
	def__union         :: proc(name : string, body : Code_Body,         opts : Opts_Def_Union)       -> Code_Union ---
	def__variable      :: proc(type : Code_Typename, name : string,     opts : Opts_Def_Variable)    -> Code_Var ---

	def_class_body_arr       :: proc(num : i32, codes : [^]Code)              -> Code_Body ---
	def_define_params_arr    :: proc(num : i32, codes : [^]Code_DefineParams) -> Code_DefineParams ---
	def_enum_body_arr        :: proc(num : i32, codes : [^]Code)              -> Code_Body ---
	def_export_body_arr      :: proc(num : i32, codes : [^]Code)              -> Code_Body ---
	def_extern_link_body_arr :: proc(num : i32, codes : [^]Code)              -> Code_Body ---
	def_function_body_arr    :: proc(num : i32, codes : [^]Code)              -> Code_Body ---
	def_global_body_arr      :: proc(num : i32, codes : [^]Code)              -> Code_Body ---
	def_namespace_body_arr   :: proc(num : i32, codes : [^]Code)              -> Code_Body ---
	def_params_arr           :: proc(num : i32, codes : [^]Code_Params)       -> Code_Params ---
	def_specifiers_arr       :: proc(num : i32, codes : [^]Specifier)         -> Code_Specifiers ---
	def_struct_body_arr      :: proc(num : i32, codes : [^]Code)              -> Code_Body ---
	def_union_body_arr       :: proc(num : i32, codes : [^]Code)              -> Code_Body ---

	parse_class         :: proc(class_def       : string) -> Code_Class ---
	parse_constructor   :: proc(constructor_def : string) -> Code_Constructor ---
	parse_define        :: proc(define_def      : string) -> Code_Define ---
	parse_destructor    :: proc(destructor_def  : string) -> Code_Destructor ---
	parse_enum          :: proc(enum_def        : string) -> Code_Enum ---
	parse_export_body   :: proc(export_def      : string) -> Code_Body ---
	parse_extern_link   :: proc(exter_link_def  : string) -> Code_Extern ---
	parse_friend        :: proc(friend_def      : string) -> Code_Friend ---
	parse_function      :: proc(function_def    : string) -> Code_Fn ---
	parse_global_body   :: proc(body_def        : string) -> Code_Body ---
	parse_namespace     :: proc(namespace_def   : string) -> Code_NS ---
	parse_operator      :: proc(operator_def    : string) -> Code_Operator ---
	parse_operator_cast :: proc(operator_def    : string) -> Code_OpCast ---
	parse_struct        :: proc(struct_def      : string) -> Code_Struct ---
	parse_template      :: proc(template_def    : string) -> Code_Template ---
	parse_type          :: proc(type_def        : string) -> Code_Typename ---
	parse_typedef       :: proc(typedef_def     : string) -> Code_Typedef ---
	parse_union         :: proc(union_def       : string) -> Code_Union ---
	parse_using         :: proc(using_def       : string) -> Code_Using ---
	parse_variable      :: proc(var_def         : string) -> Code_Var ---

	untyped_str :: proc(content : string) -> Code ---
}
//#endregion("General Interface")

/*
  ______                    __ __ __                            
 /      \                  |  \  \  \                           
|  ▓▓▓▓▓▓\__    __ __    __ \▓▓ ▓▓\▓▓ ______   ______  __    __ 
| ▓▓__| ▓▓  \  |  \  \  /  \  \ ▓▓  \|      \ /      \|  \  |  \
| ▓▓    ▓▓ ▓▓  | ▓▓\▓▓\/  ▓▓ ▓▓ ▓▓ ▓▓ \▓▓▓▓▓▓\  ▓▓▓▓▓▓\ ▓▓  | ▓▓
| ▓▓▓▓▓▓▓▓ ▓▓  | ▓▓ >▓▓  ▓▓| ▓▓ ▓▓ ▓▓/      ▓▓ ▓▓   \▓▓ ▓▓  | ▓▓
| ▓▓  | ▓▓ ▓▓__/ ▓▓/  ▓▓▓▓\| ▓▓ ▓▓ ▓▓  ▓▓▓▓▓▓▓ ▓▓     | ▓▓__/ ▓▓
| ▓▓  | ▓▓\▓▓    ▓▓  ▓▓ \▓▓\ ▓▓ ▓▓ ▓▓\▓▓    ▓▓ ▓▓      \▓▓    ▓▓
 \▓▓   \▓▓ \▓▓▓▓▓▓ \▓▓   \▓▓\▓▓\▓▓\▓▓ \▓▓▓▓▓▓▓\▓▓      _\▓▓▓▓▓▓▓
                                                      |  \__| ▓▓
                                                       \▓▓    ▓▓
                                                        \▓▓▓▓▓▓ 
*/
//#region("Auxiliary")

Builder :: struct {
	file   : ^os.File,
	buffer : Str_Builder,
}

builder_open :: proc(path : string) -> (Builder, os.Error) {
	file, error := os.open(path, flags = {.Write, .Create})
	if error != nil {
		return {}, error
	}

	buffer := strbuilder_make_reserve(_ctx.allocator_temp, cast(int) _ctx.init_size_builder_buffer)
	result := Builder {
		file,
		buffer
	}
	return result, error
}

builder_pad_lines :: proc(builder : ^Builder, num : i32) {
	for _ in 0 ..< num {
		strbuilder_append_string(& builder.buffer, "\n")
	}
}

builder_print :: proc {
	builder_print_fmt,
	builder_print_code,
	builder_print_attributes,
	builder_print_body,
	builder_print_comment,
	builder_print_constructor,
	builder_print_class,
	builder_print_define,
	builder_print_define_params,
	builder_print_enum,
	builder_print_exec,
	builder_print_extern,
	builder_print_include,
	builder_print_friend,
	builder_print_fn,
	builder_print_module,
	builder_print_namespace,
	builder_print_operator,
	builder_print_opcast,
	builder_print_params,
	builder_print_specifiers,
	builder_print_struct,
	builder_print_template,
	builder_print_typename,
	builder_print_typedef,
	builder_print_union,
	builder_print_var,
}

builder_print_fmt           :: #force_inline proc(builder : ^Builder, fmt  : string, args : ..any ) { strbuilder_append_fmt_buf(& builder.buffer, fmt, ..args ) }
builder_print_code          :: #force_inline proc(builder : ^Builder, code : Code)                  { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_attributes    :: #force_inline proc(builder : ^Builder, code : Code_Attributes)       { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_body          :: #force_inline proc(builder : ^Builder, code : Code_Body)             { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_comment       :: #force_inline proc(builder : ^Builder, code : Code_Comment)          { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_constructor   :: #force_inline proc(builder : ^Builder, code : Code_Constructor)      { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_class         :: #force_inline proc(builder : ^Builder, code : Code_Class)            { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_define        :: #force_inline proc(builder : ^Builder, code : Code_Define)           { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_define_params :: #force_inline proc(builder : ^Builder, code : Code_DefineParams)     { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_enum          :: #force_inline proc(builder : ^Builder, code : Code_Enum)             { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_exec          :: #force_inline proc(builder : ^Builder, code : Code_Exec)             { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_extern        :: #force_inline proc(builder : ^Builder, code : Code_Extern)           { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_include       :: #force_inline proc(builder : ^Builder, code : Code_Include)          { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_friend        :: #force_inline proc(builder : ^Builder, code : Code_Friend)           { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_fn            :: #force_inline proc(builder : ^Builder, code : Code_Fn)               { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_module        :: #force_inline proc(builder : ^Builder, code : Code_Module)           { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_namespace     :: #force_inline proc(builder : ^Builder, code : Code_NS)               { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_operator      :: #force_inline proc(builder : ^Builder, code : Code_Operator)         { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_opcast        :: #force_inline proc(builder : ^Builder, code : Code_OpCast)           { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_params        :: #force_inline proc(builder : ^Builder, code : Code_Params)           { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_specifiers    :: #force_inline proc(builder : ^Builder, code : Code_Specifiers)       { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_struct        :: #force_inline proc(builder : ^Builder, code : Code_Struct)           { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_template      :: #force_inline proc(builder : ^Builder, code : Code_Template)         { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_typename      :: #force_inline proc(builder : ^Builder, code : Code_Typename)         { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_typedef       :: #force_inline proc(builder : ^Builder, code : Code_Typedef)          { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_union         :: #force_inline proc(builder : ^Builder, code : Code_Union)            { strbuilder_append_string(& builder.buffer, to_string(code)) }
builder_print_var           :: #force_inline proc(builder : ^Builder, code : Code_Var)              { strbuilder_append_string(& builder.buffer, to_string(code)) }

builder_write :: proc(builder : ^Builder) -> os.Error {
	num, error := os.write(builder.file, transmute([]byte) strbuilder_to_string(builder.buffer))
	return error
}

parse_file :: proc(path : string) -> (Code_Body, os.Error) {
	content, error := os.read_entire_file_from_path(path, allocator = allocator_info_to_odin_allocator(& _ctx.allocator_temp))
	if error != nil do return nil, error
	body := parse_global_body(transmute(string) content)
	return body, error
}

untyped_file :: #force_inline proc(path : string) -> string {
	return scan_file(transmute([^]c.char) strings.clone_to_cstring(path, allocator = allocator_info_to_odin_allocator(& _ctx.allocator_temp)))
}

@(default_calling_convention="c", link_prefix="gen_")
foreign gencpp_c11
{
	scan_file :: proc(path : [^]c.char) -> string ---
}

//#endregion("Auxiliary")

/*
$$$$$$$\                      $$\                                 $$\ 
$$  __$$\                     $$ |                                $$ |
$$ |  $$ | $$$$$$\   $$$$$$$\ $$ |  $$\  $$$$$$\  $$$$$$$\   $$$$$$$ |
$$$$$$$\ | \____$$\ $$  _____|$$ | $$  |$$  __$$\ $$  __$$\ $$  __$$ |
$$  __$$\  $$$$$$$ |$$ /      $$$$$$  / $$$$$$$$ |$$ |  $$ |$$ /  $$ |
$$ |  $$ |$$  __$$ |$$ |      $$  _$$<  $$   ____|$$ |  $$ |$$ |  $$ |
$$$$$$$  |\$$$$$$$ |\$$$$$$$\ $$ | \$$\ \$$$$$$$\ $$ |  $$ |\$$$$$$$ |
\_______/  \_______| \_______|\__|  \__| \_______|\__|  \__| \_______|
*/
//#region("Backend")

@(link_prefix="gen_")
foreign gencpp_c11
{
	_ctx : ^Context
}

// Data structures from the library will be redefined here for the sake of transparently exposing them to the package
// Their interface however was only redefined as necessary.

Allocation_Type :: enum(i32) {
	Alloc,
	Free,
	Free_All,
	Resize,
}

Allocator_Proc :: #type proc(
	allocator_data : rawptr, 
	type           : Allocation_Type, 
	size           : c.ssize_t, 
	alignment      : c.ssize_t, 
	old_memory     : rawptr,
	old_size       : c.ssize_t,
	flags: u64
) -> rawptr

Allocator_Info :: struct {
	procedure : Allocator_Proc,
	data      : rawptr,
}

allocation_type_to_allocator_mode :: proc(type : Allocation_Type) -> mem.Allocator_Mode {
	switch type {
		case .Alloc:    return .Alloc
		case .Free:     return .Free
		case .Free_All: return .Free_All
		case .Resize:   return .Resize
	}
	assert(false)
	return .Query_Features
}

allocator_mode_to_allocation_type :: proc(mode : mem.Allocator_Mode) -> Allocation_Type {
	#partial switch mode {
		case .Alloc, .Alloc_Non_Zeroed:   return .Alloc
		case .Free:                       return .Free
		case .Free_All:                   return .Free_All
		case .Resize, .Resize_Non_Zeroed: return .Resize
	}
	assert(false)
	return .Alloc
}

odin_allocator_wrapper_proc :: proc(
	allocator_data : rawptr, 
	type           : Allocation_Type, 
	size           : c.ssize_t, 
	alignment      : c.ssize_t, 
	old_memory     : rawptr,
	old_size       : c.ssize_t,
	flags: u64) -> rawptr
{
	info := transmute(^mem.Allocator) allocator_data
	memory, error := info.procedure(info.data, allocation_type_to_allocator_mode(type), size, alignment, old_memory, old_size)
	assert(error == .None)
	return raw_data(memory)
}

allocator_info_wrapper_proc :: proc(allocator_data: rawptr, mode: mem.Allocator_Mode,
	size, alignment: int,
	old_memory: rawptr, old_size: int,
	location: runtime.Source_Code_Location = #caller_location) -> ([]byte, mem.Allocator_Error)
{
	info       := transmute(^Allocator_Info) allocator_data
	result_raw := info.procedure(info.data, allocator_mode_to_allocation_type(mode), size, alignment, old_memory, old_size, 0 )
	result     := (cast([^]byte) result_raw)[ : size]
	return result, (result_raw != nil ? .None : .Out_Of_Memory)
}

allocator_from_odin_allocator :: #force_inline proc(allocator : ^mem.Allocator) -> Allocator_Info {
	result := Allocator_Info { 
		odin_allocator_wrapper_proc,
		transmute(rawptr) allocator
	}
	return result
}

allocator_info_to_odin_allocator :: #force_inline proc(allocator : ^Allocator_Info) -> mem.Allocator {
	result := mem.Allocator { 
		allocator_info_wrapper_proc,
		transmute(rawptr) allocator,
	}
	return result
}

Arena :: struct {
	backing    : Allocator_Info,
	mem_start  : rawptr,
	total_size : int,
	total_used : int,
	temp_count : int,
}

Pool :: struct {
	backing     : Allocator_Info,
	mem_start   : rawptr,
	free_list   : rawptr,
	block_size  : int,
	block_align : int,
	total_size  : int,
	num_blocks  : int,
}

Array_Header :: struct {
	allocator : Allocator_Info,
	capacity  : uint,
	num       : uint,
}

USE_TEMP_ALLOCATOR :: Allocator_Info{}

Array :: struct($Type : typeid) { data : [^]Type }

array_header :: #force_inline proc(array : Array($Type)) -> Array_Header { return mem.ptr_offset(cast(^ArrayHeader)(array.data),  -1) }
array_slice  :: #force_inline proc(array : Array($Type)) -> []Type       { return array.data[ : array_header(array).num] }

Hash_Table_Entry :: struct($Type : typeid) {
	key   : u64,
	next  : int,
	value : Type,
}

Hash_Table :: struct($Type : typeid) { 
	hashes  : Array(Type),
	entries : Array(Hash_Table_Entry(Type)),
}

Macro_Table  :: Hash_Table(Macro)
String_Table :: Hash_Table(string)

string_cached :: string

Str_Builder_Header :: struct {
	allocator : Allocator_Info,
	capacity  : int,
	length    : int,
}

Str_Builder :: struct {
	data : [^]u8
}

strbuilder_header    :: #force_inline proc(builder : Str_Builder) -> ^Str_Builder_Header { return mem.ptr_offset(transmute(^Str_Builder_Header)(builder.data), -1) }
strbuilder_to_string :: #force_inline proc(builder : Str_Builder) -> string             { return transmute(string) builder.data[:strbuilder_header(builder).length] }

strbuilder_make_string :: proc(allocator := USE_TEMP_ALLOCATOR, str : string) -> Str_Builder {
	allocator := allocator
	if allocator.procedure == nil do allocator = _ctx.allocator_temp
	return strbuilder_make_length(allocator, transmute([^]c.char) raw_data(str), len(str) )
}

// NOTE: The original implementation fo the _fmt related procedures utilized gencpp's c_str_fmt_va 
// which had custom verbs for string and string builder: %S for string and %SB for Str_Builder
// This rewrite uses fmt.aprintf instead so those are have changed to just %s for odin's string (equivalent),
// but for Str_Builder there is no equivalnet and the user must use strbuider_to_string before feeding to the fmt procedure
strbuilder_fmt :: proc(allocator := USE_TEMP_ALLOCATOR, size : int, format : string, args: ..any ) -> Str_Builder {
	allocator := allocator
	if allocator.procedure == nil do allocator = _ctx.allocator_temp
	res := fmt.aprintf(format, ..args, allocator = allocator_info_to_odin_allocator(& allocator))
	return strbuilder_make_length(allocator, transmute([^]c.char) raw_data(res), len(res))
}

// NOTE: The original implementation fo the _fmt related procedures utilized gencpp's c_str_fmt_va 
// which had custom verbs for string and string builder: %S for string and %SB for Str_Builder
// This rewrite uses fmt.bprintf instead so those are have changed to just %s for odin's string (equivalent),
// but for Str_Builder there is no equivalnet and the user must use strbuider_to_string before feeding to the fmt procedure
strbuilder_fmt_buf :: proc(allocator := USE_TEMP_ALLOCATOR, format : string, args : ..any ) -> Str_Builder {
	allocator := allocator
	if allocator.procedure == nil do allocator = _ctx.allocator_temp
	@thread_local
	buf : [mem.Kilobyte * 128]byte
	res := fmt.bprintf(buf[:], format, ..args)
	return strbuilder_make_length(allocator, transmute([^]c.char) raw_data(res), len(res))
}

strbuilder_append_char :: proc(builder : ^Str_Builder, char : c.char) -> bool {
	assert(builder != nil)
	char := char
	return strbuilder_append_c_str_len(builder, & char, 1)
}

strbuilder_append_string :: proc(builder : ^Str_Builder, str : string) -> bool {
	assert(builder != nil)
	return strbuilder_append_c_str_len(builder, transmute([^]c.char) raw_data(str), len(str))
}

// NOTE: The original implementation fo the _fmt related procedures utilized gencpp's c_str_fmt_va 
// which had custom verbs for string and string builder: %S for string and %SB for Str_Builder
// This rewrite uses fmt.aprintf instead so those are have changed to just %s for odin's string (equivalent),
// but for Str_Builder there is no equivalnet and the user must use strbuider_to_string before feeding to the fmt procedure
strbuilder_append_fmt :: proc(builder : ^Str_Builder, format : string, args : ..any ) -> bool {
	assert(builder != nil)
	header := strbuilder_header(builder ^)
	res := fmt.aprintf(format, ..args, allocator = allocator_info_to_odin_allocator(& header.allocator))
	return strbuilder_append_c_str_len(builder, transmute([^]c.char) raw_data(res), len(res))
}

// NOTE: The original implementation fo the _fmt related procedures utilized gencpp's c_str_fmt_va 
// which had custom verbs for string and string builder: %S for string and %SB for Str_Builder
// This rewrite uses fmt.bprintf instead so those are have changed to just %s for odin's string (equivalent),
// but for Str_Builder there is no equivalnet and the user must use strbuider_to_string before feeding to the fmt procedure
strbuilder_append_fmt_buf :: proc(builder : ^Str_Builder, format : string, args : ..any ) -> bool {
	assert(builder != nil)
	header := strbuilder_header(builder ^)
	@thread_local
	buf : [mem.Kilobyte * 128]byte
	res := fmt.bprintf(buf[:], format, ..args)
	return strbuilder_append_c_str_len(builder, transmute([^]c.char) raw_data(res), len(res))
}

strbuilder_avail_space :: proc(builder : Str_Builder ) -> int {
	header := strbuilder_header(builder)
	return header.capacity - header.length
}

strbuilder_capacity :: proc(builder : Str_Builder) -> int {
	header := strbuilder_header(builder)
	return header.capacity
}

strbuilder_clear :: proc(builder : Str_Builder) {
	strbuilder_header(builder).length = 0
}

strbiulder_duplicate :: proc(builder : Str_Builder, allocator := USE_TEMP_ALLOCATOR) -> Str_Builder {
	allocator := allocator
	if allocator.procedure == nil do allocator = _ctx.allocator_temp
	return strbuilder_make_string(allocator, strbuilder_to_string(builder))
}

@(default_calling_convention="c", link_prefix="gen_")
foreign gencpp_c11
{
	strbuilder_make_reserve   :: proc(allocator : Allocator_Info, capacity  : int) -> Str_Builder ---
	strbuilder_make_length    :: proc(allocator : Allocator_Info, str       : [^]c.char, length : int) -> Str_Builder ---

	strbuilder_make_space_for       :: proc(builder : ^Str_Builder, to_append : [^]c.char, length : int) -> bool ---
	strbuilder_append_c_str_len     :: proc(builder : ^Str_Builder, to_append : [^]c.char, length : int) -> bool ---
	strbuilder_trim                 :: proc(builder : Str_Builder,  cut_set   : [^]c.char) ---
	strbuilder_visualize_whitespace :: proc(builder : Str_Builder) ---
}
//#endregion("Backend")
