/*
	gencpp: An attempt at "simple" staged metaprogramming for c/c++.

	See Readme.md for more information from the project repository.

	Public Address:
	https://github.com/Ed94/gencpp-odin ----------------------------------------------------------------.
	|   _____                               _____ _                       _      ___       _            |
	|  / ____)                             / ____} |                     | |   / ,_, \    | |{_}        |
	| | / ___  ___ _ __   ___ _ __  _ __  | {___ | l_ __ _  __ _, ___  __| |  | |   | | __| | _ _ __    |
	| | |{_  \/ __\ '_ \ / __} '_ l| '_ l  \___ \| __/ _` |/ _` |/ __\/ _` |  | |   | |/ _` || | '_ \   |    
	| | l__j | ___/ | | | {__; ;_l } ;_l } ____} | l| (_} | {_| | ___j {_; |  | \___/ | {_; || | | | |  |     
	|  \_____|\___}_l |_|\___} .__/| .__/ {_____/ \__\__/_l\__. |\___/\__,_l   \_____/ \__,_l|_|_l |_|  |
	|                        | |   | |                      __} |                                       |
	|                        l_l   l_l                     {___/                                        |
	! ---------------------------------------------------------------------------- VERSION: v0.24-Alpha |
	! ==================================================================================================|
	! WARNING: THIS IS AN ALPHA VERSION OF THE LIBRARY, USE AT YOUR OWN DISCRETION                      |
	! NEVER DO CODE GENERATION WITHOUT AT LEAST HAVING CONTENT IN A CODEBASE UNDER VERSION CONTROL      |
*/

package gencpp

import c "core:c"
import   "core:mem"
import   "core:reflect"
import   "core:runtime"

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

Access_Spec :: enum(u32) {
	Default,
	Private,
	Protected,
	Public,

	Num_AccessSpec,
	Invalid,
}

access_spec_to_str :: proc(type : Access_Spec) -> string {
	switch type {
		case Default:   return ""
		case Priate:    return "private"
		case Protected: return "protected"
		case Public:    return "public"
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

module_flag_to_str :: proc(flag : Module_Flag) -> string {
	switch flag {
		case None:   return "__none__"
		case Export: return "export"
		case Import: return "import"
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
	Operator_Member_Fwd,
	Operator_Cast,
	Operator_Cast_Fwd,
	Parameters,
	Parameters_Define,
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

codetype_to_keyword_str :: proc(type : Code_Type) -> string
{
	switch type {
		case Invalid, Untyped, NewLine:           return "__NA__"
		case Comment:                             return "//"
		case Access_Private:                      return "private"
		case Access_Protected:                    return "protected"
		case Access_Public:                       return "public"
		case Platform_Attributes:                 return "__NA__"
		case Class, Class_Fwd:                    return "class"
		case Class_Body,                  \
			Constructor, Constructor_Fwd, \
			Destructor,  Destructor_Fwd:          return "__NA__"
		case Enum, Enum_Fwd:                      return "enum"
		case Enum_Body:                           return "__NA__"
		case Enum_Class, Enum_Class_Fwd:          return "enum class"
		case Execution, Export_Body:              return "__NA__"
		case Extern_Linkege, Extern_Linkage_Body: return "extern"
		case Friend:                              return "friend"
		case Function, Function_Fwd, \
			Function_Body, Global_Body:           return "__NA__"
		case Module:                              return "module"
		case Namespace:                           return "namespace"
		case Namespace_Body:                      return "__NA__"
		case Operator, Operator_Fwd, \
			Operator_Member_Fwd,     \
			Operator_Cast, Operator_Cast_Fwd:     return "operator"
		case Parameters, Parameters_Define:       return "__NA__"
		case Preprocess_Define:                   return "define"
		case Preprocess_Include:                  return "include"
		case Preprocess_If:                       return "if"
		case Preprocess_IfDef:                    return "ifdef"
		case Preprocess_ifndef:                   return "ifndef"
		case Preprocess_elif:                     return "elif"
		case Preprocess_else:                     return "else"
		case Preprocess_endif:                    return "endif"
		case Preprocess_Pragma:                   return "pragma"
		case Specifiers:                          return "__NA__"
		case Struct, Struct_Fwd:                  return "struct"
		case Struct_Body:                         return "__NA__"
		case Template:                            return "template"
		case Typedef:                             return "typedef"
		case Typename:                            return "__NA__"
		case Union, Union_Fwd:                    return Union
		case Union_Body:                          return "__NA__"
		case Using:                               return "using"
		case Using_Namespace:                     return "using namespace"
		case Variable:                            return "__NA__"
	}
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

operator_to_str :: proc(op : Operator) -> string
{
	switch op {
		case Invalid:         return "INVALID"
		case Assign:          return "="
		case Assign_Add:      return "+="
		case Assign_Subtract: return "-="
		case Assign_Multiply: return "*="
		case Assign_Divide:   return "/="
		case Assign_Modulo:   return "%="
		case Assign_BAnd:     return "&="
		case Assign_BOr:      return "|="
		case Assign_BXOr:     return "^="
		case Assign_LShift:   return "<<="
		case Assign_RShift:   return ">>="
		case Increment:       return "++"
		case Decrement:       return "--"
		case Unary_Plus:      return "+"
		case Unary_Minus:     return "-"
		case UnaryNot:        return "!"
		case Add:             return "+"
		case Subtract:        return "-"
		case Multiply:        return "*"
		case Divide:          return "/"
		case Modulo:          return "%"
		case BNot:            return "~"
		case BAnd:            return "&"
		case BOr:             return "|"
		case BXOr:            return "^"
		case LShift:          return "<<"
		case RShift:          return ">>"
		case LAnd:            return "&&"
		case LOr:             return "||"
		case LEqual:          return "=="
		case LNot:            return "!="
		case Lesser:          return "<"
		case Greater:         return ">"
		case LesserEqual:     return "<="
		case GreaterEqual:    return ">="
		case Subscript:       return "[]"
		case Indirection:     return "*"
		case AddressOf:       return "&"
		case MemberOfPointer: return "->"
		case PtrToMemOfPtr:   return "->*"
		case FunctionCall:    return "()"
		case Comma:           return ","
		case New:             return "new"
		case NewArray:        return "new[]"
		case Delete:          return "delete"
		case DeleteArray:     return "delete[]"
	}
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

spec_to_str :: proc(spec : Specifier) -> string
{
	switch(spec) {
		case Invalid:          return "INVALID"
		case Consteval:        return "consteval"
		case Constexpr:        return "constexpr"
		case Constinit:        return "constinit"
		case Explicit:         return "explicit"
		case External_Linkage: return "external"
		case ForceInline:      return "forceinline"
		case Global:           return "global"
		case Inline:           return "inline"
		case Internal_Linkage: return "internal"
		case Local_Persist:    return "local_persist"
		case Mutable:          return "mutable"
		case NeverInline:      return "neverinline"
		case Ptr:              return "*"
		case Ref:              return "&"
		case Register:         return "register"
		case Restrict:         return "restrict"
		case RValue:           return "&&"
		case Static:           return "static"
		case Thread_Local:     return "thread_local"
		case Virtual:          return "virtual"
		case Const:            return "const"
		case Final:            return "final"
		case NoExceptions:     return "noexcept"
		case Override:         return "override"
		case Pure:             return "= 0"
		case Delete:           return "= delete"
		case Volatile:         return "volatile"
	}
}

spec_is_trailing :: proc(spec : Specifier) -> bool
{
	switch spec {
		case Const, Final, NoExceptions, Override, Pure, Delete, Volatile: return true
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
	StaticAssert,
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

toktype_to_str :: proc(type : Token_Type) -> string
{
	switch type {
		case Invalid:                   return "INVALID"
		case Access_Private:            return "private"
		case Access_Protected:          return "protected"
		case Access_Public:             return "public"
		case Access_MemberSymbol:       return "."
		case Access_StaticSymbol:       return "::"
		case Ampersand:                 return "&"
		case Ampersand_DBL:             return "&&"
		case Assign_Classifer:          return ":"
		case Attribute_Open:            return "[["
		case Attribute_Close:           return "]]"
		case BraceCurly_Open:           return "{"
		case BraceCurly_Close:          return "}"
		case BraceSquare_Open:          return "["
		case BraceSquare_Close:         return "]"
		case Paren_Open:                return "("
		case Paren_Close:               return ")"
		case Comment:                   return "__comment__"
		case Comment_End:               return "__comment_end__"
		case Comment_Start:             return "__comment_start__"
		case Char:                      return "__character__"
		case Comma:                     return ","
		case Decl_Class:                return "class"
		case Decl_GNU_Attribute:        return "__atribute__"
		case Decl_MSVC_Attribute:       return "__declspec"
		case Decl_Enum:                 return "enum"
		case Decl_Extern_Linkage:       return "extern"
		case Decl_Friend:               return "friend"
		case Decl_Module:               return "module"
		case Decl_Namespace:            return "namespace"
		case Decl_Operator:             return "operator"
		case Decl_Struct:               return "struct"
		case Decl_Template:             return "template"
		case Decl_Typedef:              return "typedef"
		case Decl_Using:                return "using"
		case Decl_Union:                return "union"
		case Identifier:                return "__identifier__"
		case Module_Import:             return "import"
		case Module_Export:             return "export"
		case NewLine:                   return "__new_line__"
		case Number:                    return "__number__"
		case Operator:                  return "operator"
		case Preprocess_Hash:           return "#"
		case Preprocess_Define:         return "define"
		case Preprocess_Define_Param:   return "__define_param__"
		case Preprocess_If:             return "if"
		case Preprocess_IfDef:          return "ifdef"
		case Preprocess_IfNotDef:       return "ifndef"
		case Preprocess_ElIf:           return "elif"
		case Preprocess_Else:           return "else"
		case Preprocess_EndIf:          return "endif"
		case Preprocess_Include:        return "include"
		case Preprocess_Pragma:         return "pragma"
		case Preprocess_Content:        return "__macro_content__"
		case Preprocess_Macro_Expr:     return "__macro_expansion__"
		case Preprocess_Macro_Stmt:     return "__macro_statement__"
		case Preprocess_Macro_Typename: return "__macro_typename__"
		case Preprocess_Unsupported:    return "__unsupported__"
		case Spec_Alignas:              return "alignas"
		case Spec_Const:                return "const"
		case Spec_Consteval:            return "consteval"
		case Spec_Constexpr:            return "constexpr"
		case Spec_Constinit:            return "constinit"
		case Spec_Explicit:             return "explicti"
		case Spec_Extern:               return "extern"
		case Spec_Final:                return "final"
		case Spec_ForceInline:          return "forceinline"
		case Spec_Global:               return "global"
		case Spec_Inline:               return "inline"
		case Spec_Internal_Linkage:     return "internal"
		case Spec_LocalPersist:         return "local_persist"
		case Spec_Mutable:              return "mutable"
		case Spec_NeverInline:          return "neverinline"
		case Spec_Override:             return "override"
		case Spec_Restrict:             return "restrict"
		case Spec_Static:               return "static"
		case Spec_ThreadLocal:          return "thread_local"
		case Spec_Volatile:             return "volatile"
		case Spec_Virtual:              return "virtual"
		case Star:                      return "*"
		case Statement_End:             return ";"
		case Static_Assert:             return "static_assert"
		case String:                    return "__string_"
		case Type_Typename:             return "typename"
		case Type_Unsigned:             return "unsigned"
		case Type_Signed:               return "signed"
		case Type_Short:                return "short"
		case Type_Long:                 return "long"
		case Type_bool:                 return "bool"
		case Type_char:                 return "char"
		case Type_int:                  return "int"
		case Type_double:               return "double"
		case Type_MS_int8:              return "__int8"
		case Type_MS_int16:             return "__int16"
		case Type_MS_int32:             return "__int32"
		case Type_MS_int64:             return "__int64"
		case Type_MS_W64:               return "_W64"
		case Varadic_Argument:          return "..."
		case Tok___Attributes_Start:    return "__attrib_start__"
	}
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
TokFlags :: bit_set[Token_Flag; u32]

Token :: struct {
	text   : string,
	type   : Token_Type,
	line   : i32,
	column : i32,
	flags  : TokFlag,
}

tok_to_access_specifier :: #force_inline proc(tok : Token) -> AccessSpec { return cast(AccessSpec) tok.Type }
tok_is_valid            :: #force_inline proc(tok : Token) -> bool       { return tok.text != "" && len(tok.text) > 0 && tok.Type != .Invalid }
tok_is_access_specifier :: #force_inline proc(tok : Token) -> bool       { return .Access_Operator in tok.flags }
tok_is_attribute        :: #force_inline proc(tok : Token) -> bool       { return .Attribute       in tok.flags }
tok_is_operator         :: #force_inline proc(tok : Token) -> bool       { return .Operator        in tok.flags }
tok_is_proprocessor     :: #force_inline proc(tok : Token) -> bool       { return .Preprocess      in tok.flags }
tok_is_preprocess_cond  :: #force_inline proc(tok : Token) -> bool       { return .Preprocess_Cond in tok.flags }
tok_is_specifier        :: #force_inline proc(tok : Token) -> bool       { return .Specifier       in tok.flags }
tok_is_end_definition   :: #force_inline proc(tok : Token) -> bool       { return .End_Definition  in tok.flags }

Token_Array :: struct {
	arr : Array(Token),
	idx : s32,
}

Lex_Context :: struct {
	content : string,
	left    : s32,
	scanner : ^c.char,
	line    : s32,
	column  : s32,
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

	// lex__eat wil treat this macro as an identifier if the parser attempts to consume it as one.
	//  ^^^ This is a kludge because we don't support push/pop macro pragmas rn.
	Allow_As_Identifier,

	// lex__eat wil treat this macro as an attribute if the parser attempts to consume it as one.
	//  ^^^ This a kludge because unreal has a macro that behaves as both a 'statement' and an attribute (UE_DEPRECATED, PRAGMA_ENABLE_DEPRECATION_WARNINGS, etc)
	// TODO(Ed): We can keep the MF_Allow_As_Attribute flag for macros, however, we need to add the ability of AST_Attributes to chain themselves.
	// Its thats already a thing in the standard language anyway
	// & it would allow UE_DEPRECATED, (UE_PROPERTY / UE_FUNCTION) to chain themselves as attributes of a resolved member function/variable definition
	Allow_As_Attribute,

	// When a macro is encountered after attributes and specifiers while parsing a function, or variable:
	// It will consume the macro and treat it as resolving the definition. (Yes this is for Unreal Engine)
	// (MUST BE OF MT_Statement TYPE)
	Allow_As_Definition,

	Allow_As_Specifier, // Created for Unreal's PURE_VIRTUAL

	Null = 0,
};
Macro_Flags :: bit_set[Macro_Flag; u16]

Macro :: struct {
	name  : string_cached,
	type  : Macro_Type,
	flags : Macro_Flags
}

macro_is_functional :: #force_inline proc(macro : Macro) -> bool { return .Functional   in macro.flags }
macro_expects_body  :: #force_inline proc(macro : Macro) -> bool { return .Expects_Body in macro.flags }

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

Code                 :: distinct ^AST
Code_Body            :: distinct ^AST_Body
Code_Attributes      :: distinct ^AST_Attributes
Code_Comment         :: distinct ^AST_Comment
Code_Class           :: distinct ^AST_Class
Code_Constructor     :: distinct ^AST_Constructor
Code_Define          :: distinct ^AST_Define
Code_Define_Params   :: distinct ^AST_Define_Params
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
Code_Op_Cast         :: distinct ^AST_Op_Cast
Code_Params          :: distinct ^AST_Define_Params
Code_Preprocess_Cond :: distinct ^AST_Preprocess_Cond
Code_Pragma          :: distinct ^AST_Pragma
Code_Specifiers      :: distinct ^AST_Sepcifiers
Code_Struct          :: distinct ^AST_Struct
Code_Template        :: distinct ^AST_Template
Code_Typename        :: distinct ^AST_Typename
Code_Typedef         :: distinct ^AST_Typedef
Code_Union           :: distinct ^AST_Union
Code_Using           :: distinct ^AST_Using
Code_Var             :: distinct ^AST_Var

@(default_calling_convention="c", link_prefix="gen_")
foreign gen {
	Code_Global  : Code
	Code_Invalid : Code
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
			}
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

append :: proc {
	code_append,
	code_debug_str,
	// append_body,
	// append_attributes,
	// append_comment,
	// append_class,
	// append_constructor,
	// append_define,
	// append_define_params,
	// append_destructor,
	// append_enum,
	// append_exec,
	// append_include,
	// append_friend,
	// append_fn,
	// append_module,
	// append_ns,
	// append_operator,
	// append_op_cast,
	// append_pragma,
	// append_params,
	// append_preprocess_cond,
	// append_specifiers,
	// append_struct,
	// append_template,
	// append_typename,
	// append_typename,
	// append_typedef,
	// append_union,
	// append_using,
	// append_var
}

begin :: proc {
	begin_body,
	begin_define_params,
	begin_define_params,
	begin_specifiers,
}

debug_str :: proc {
	// debug_str_code,
	// debug_str_body,
	// debug_str_attributes,
	// debug_str_comment,
	// debug_str_class,
	// debug_str_constructor,
	// debug_str_define,
	// debug_str_define_params,
	// debug_str_destructor,
	// debug_str_enum,
	// debug_str_exec,
	// debug_str
}

duplicate :: proc {

}

end :: proc {
	end_body,
	end_define_params,
	end_params,
	end_specifiers,
}

entry :: proc {

}

has_entries :: proc {

}

is_body :: proc {
	code_is_body,
}

is_equal :: proc {

}

is_valid :: proc {

}

next :: proc {
	next_body,
	next_define_params,
	next_params,
	next_specifiers,
}

set_global :: proc {

}

to_strbuilder :: proc {
	attributes_to_strbuilder,
	comment_to_strbuilder,
}

to_strbuilder_ref :: proc {
	attributes_to_strbuilder_ref,
	comment_to_strbuilder_ref,
}

type_str :: proc {

}

validate_body :: proc {

}

attributes_to_strbuilder :: #force_inlin proc(attributes : Code_Attributes) -> Str_Builder {
	assert(attributes != nil)
	dupe := strbuilder_make_str(get_context().temp_allocator, attributes.content)
	return dupe
}

attributes_to_strbuilder_ref :: #force_inline proc(attributes : Code_Attributes, builder : ^Str_Builder) {
	assert(attributes != nil)
	assert(builder != nil)
	strbuilder_append_string(result, attributes.content)
}

comment_to_strbuilder :: #force_inlin proc(comment : Code_Attributes) -> Str_Builder {
	assert(attributes != nil)
	dupe := strbuilder_make_str(get_context().temp_allocator, comment.content)
	return dupe
}

comment_to_strbuilder_ref :: proc(comment : Code_Comment, builder : ^Str_Builder) {
	assert(comment != nil)
	assert(builder != nil)
	strbuilder_append_string(result, comment.content)
}

using_to_strbuilder_ns :: proc(self : Code_Using, builder : ^Str_Builder) {
	assert(self != nil)
	assert(builder != nil)
	if self.inline_cmt {
		strbuilder_append_fmt(result, "using namespace %S; %S", self.name, self.inline_cmt)
	}
	else {
		strbuilder_append_fmt(result, "using namespace %S;\n", self.name)
	}
}

code_append :: proc(self, other : Code) {
	assert(self != nil)
	assert(other != nil)
	assert(self != other)
	if (other.parent != nil)
		other = gen.code__duplicate(other)

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

code_is_body :: proc(code : Code) {
	assert(code != nil)
	switch(code.type) {
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
	current := & self.front
	for idx >= 0 && current != nil {
		if idx == 0 do return currrent

		current & current.next
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

code_type_str :: #force_inline proc(self : Code) {
	assert(self != nil)
	return reflect.enum_name_from_value(self.type)
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
	for entry := begin_body(body); entry != end_body(body); entry = next_body(body) {
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
	assert(code.parent == body)
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
		possible_slot.next = transmute(Code_Typename) possible_slot.Next
	}

	possible_slot.next = type;
}

params_append :: proc(appendee, other : Code_Params) {
	assert(appendee != nil)
	assert(other != nil)
	assert(appendee != other)
	self  = transmute(Code) appendee
	entry = transmute(Code) other

	if entry.parent != nil {
		entry = code__duplicate(entry);
	}

	if self.last == nil {
		self.last = map_entry
		self.next = map_entry
		self.num_entries += 1
	}

	self.last.next = entry
	self.last      = entry
	self.num_entries += 1
}

params_get :: proc(params : Code_Params, idx : i32) -> Code_Params {
	assert(params != nil)
	params := param
	for
	{
		if ( param.next != nil ) {
			return nil
		}

		param = param.next

		idx -= 1
		if idx <= 0 do break
	}
}

params_has_entries :: #force_inline proc(params : Code_Params) -> bool {
	assert(params != nil)
	return params.num_entries > 0
}

begin_params :: #force_inline proc(params : Code_Params) {
	assert(params != nil)
	return params
}

end_params :: #force_inline proc(params : Code_Params) {
	assert(params != nil)
	return nil
}

next_params :: #force_inline proc(params, params_iter : Code_Params) {
	assert(params != nil)
	assert(params_iter != nil)
	return params_iter.next
}

// define_params_append      -> params_append
// define_params_get         -> params_get
// define_params_has_entries -> params_has_entries

define_params_append      :: #force_inline proc(appendee, other : Code_Define_Params)   { params_append(transmute(Code_Params) appendee, transmute(Code_Params) other) }
define_params_get         :: #force_inline proc(params : Code_Define_Params, idx : s32) { return transmute(Code_Define_Params) params_get( transmute(Code_Params) params, idx) }
define_params_has_entires :: #force_inline proc(params : Code_Define_Params)            { return params_has_entries(transmute(Code_Params) params) }

begin_define_params :: #force_inline proc(params : CoCode_Define_Paramse_Params) {
	assert(params != nil)
	return params
}

end_define_params :: #force_inline proc(params : Code_Define_Params) {
	assert(params != nil)
	return nil
}

next_define_params :: #force_inline proc(params, params_iter : Code_Define_Params) {
	assert(params != nil)
	assert(params_iter != nil)
	return params_iter.next
}

specifiers_append :: proc(self, spec : Code_Specifiers) -> bool {
	assert(self != nil)
	assert(self.num_entries < AST_ARRAY_SPECS_CAP)

	self.arr_specs[self.num_entries] = spec
	self.num_entries += 1
	return true
}

specifiers_has :: proc(self, spec) -> bool {
	assert(self != nil)
	for idx : i32 = 0; idx < self.num_entries; idx += 1 {
		if self.arr_specs[idx] == spec {
			return true
		}
	}
	return false
}

specifiers_index_of :: proc(self, spec) -> i32 {
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
	assert(sef.num_entries < AST_ARRAY_SPECS_CAP)

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

end_specifiers :: #force_inline proc(self : CodeSpecifiers) -> Specifier {
	return .Invalid
}

next_specifiers :: #force_inline proc(self : Code_Specifiers, spec : ^Specifier) -> Specifier {
	return mem.ptr_offset(self, 1)
}

struct_add_interface :: #force_inline proc(self : Code_Struct, type : Code_Typename) { class_add_interface(transmute(Code_Class) self, type) }

code_debug_str     :: gen.code__debug_str
code_duplicate     :: gen.code__duplicate
code_is_equal      :: gen.code__is_equal
code_to_strbuilder :: gen.code__to_strbuilder

@(default_calling_convention="c", link_prefix="gen_")
foreign gen
{
	code__debug_str     :: proc(code        : Code) -> string ---
	code__duplicate     :: proc(code        : Code) -> Code ---
	code__is_equal      :: proc(code        : Code) -> bool ---
	code__to_strbuilder :: proc(code        : Code) -> strbuilder ---

	body_to_strbuilder        :: proc(body : Code_Body) -> StrBuilder ---
	body_to_strbuilder_ref    :: proc(body : Code_Body, builder : ^Str_Builder) ---
	body_to_strbuilder_export :: proc(body : Code_Body, builder : ^Str_Builder) ---

	class_to_strbuilder     :: proc(class : Code_Class) ---
	class_to_strbuilder_def :: proc(class : Code_Class, builder : ^Str_Builder) ---
	class_to_strbuilder_fwd :: proc(class : Code_Class, builder : ^Str_Builder) ---

	define_params_to_strbuilder :: proc(params : Code_Define_Params) ---
	define_params_to_strbuilder :: proc(params : Code_Define_Params, builder : ^Str_Builder) ---

	params_to_strbuilder     :: proc(params : Code_Params) ---
	params_to_strbuilder_ref :: proc(params : Code_Params, builder : ^Str_Builder) ---

	specifiers_to_strbuilder     :: proc(specifiers : Code_Specifiers) ---
	specifiers_to_strbuilder_ref :: proc(specifiers : Code_Specifiers, builder : ^Str_Builder) ---



	var_to_strbuilder_ref :: proc(self : Code_Var, builder : ^Str_Builder) ---
}

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

AST_Body :: struct {
	using _ : struct {
		_PAD_ : [64]byte,
	},
	name         : string_cache,
	front        : Code,
	back         : Code,
	token        : ^Token,
	parent       : Code,
	type         : Code_Type,
	_PAD_UNUSED_ : [sizeof(ModuleFlag)]byte,
	num_entries  : s32,
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
	_PAD_UNUSED_ : [sizeof(Module_Flag) + sizeof(u32)]byte
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
	_PAD_UNUSED_ : [sizeof(Module_Flag) + sizeof(u32)]byte
}

AST_Class :: struct {
	using _ : struct #raw_union {
		_PAD_ : [64]byte,
		using _ : struct {
			inline_cmt    : Code_Comment,
			attributes    : Code_Attributes,
			specs         : Code_Specifiers,
			parent_type   : Code_Typename,
			_PAD_PARARMS_ : [ sizeof(Code) ]byte,
			body          : Code_Body,
			_PAD_PROPERTIES_2_ : [sizeof(Code) ]byte,
		}
	},
	name          : string_cache,
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
			_PAD_PROPERTIES_ : [sizeof(Code)]byte,
			specs            : Code_Specifiers,
			initializer_list : Code,
			params           : Code_Params,
			body             : Code,
			_PAD_PROPERTIES_2_ : [sizeof(Code) * 2]byte,
		}
	},
	name   : string_cache,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [sizeof(Module_Flag) + sizeof(u32)]byte
}

AST_Define :: struct {
	using _ : struct #raw_union {
		_PAD_ : [64]byte,
		using _ : struct {
			_PAD_PROPERTIES_ : [sizeof(Code) * 4]byte,
			params : Code_Define_Params,
			body : Code,
			_PAD_PROPERTIES_2_ : [sizeof(Code)]byte,
		},
	},
	name   : string_cached,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [sizeof(Module_Flag) + sizeof(u32)]byte,
}

AST_Define_Params :: struct {
	using _ : struct #raw_union {
		_PAD_ : [64]byte,
	},
	name        : string_cached,
	prev        : Code,
	next        : Code,
	token       : ^Token,
	parent      : Code,
	type        : Code_Type,
	_PAD_UNUSED_ : [sizeof(Module_Flag)]byte,
	num_entries : i32,
}

AST_Destructor :: struct {
	using _ : struct #raw_union {
		_PAD_ : [64]byte,
		using _ : struct {
			inline_cmt         : Code_Comment,
			_PAD_PROPERTIES    : [sizeof(Code)]byte,
			specs              : Code_Specifiers,
			_PAD_PROPERTIES_2_ : [sizeof(Code) * 2]byte,
			body               : Code,
			_PAD_PROPERTIES_3_ : [sizeof(Code)]byte,
		},
	},
	name   : string_cached,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [sizeof(Module_Flag) + sizeof(u32)]byte,
}

AST_Enum :: struct {
	using _ : struct #raw_union {
		_PAD_ : [64]byte,
		using _ : struct {
			inline_cmt            : Code_Comment,
			attributes            : Code_Attributes,
			_PAD_SPEC_            : [sizeof(Code)]byte,
			underlying_type       : Code_Typename,
			underlying_type_macro : Code,
			body                  : Code_Body,
			_PAD_PROPERTIES_2_    : [sizeof(Code)]byte,
		},
	},
	name        : string_cached,
	prev        : Code,
	next        : Code,
	token       : ^Token,
	parent      : Code,
	type        : Code_Type,
	module_flag : Module_Flags,
	_PAD_UNUSED_ : [sizeof(u32)]byte,
}

// AST_Exec

AST_Extern :: struct {
	using _ : struct #raw_union {
		_PAD_ : [64]byte,
		using _ : struct {
			_PAD_PROPERTIES_   : [sizeof(Code) * 5]byte,
			body               : Code_Body,
			_PAD_PROPERTIES_2_ : [sizeof(Code)]byte,
		},
	},
	name   : string_cached,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [sizeof(Module_Flag) + sizeof(u32)]byte,
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
	_PAD_UNUSED_ : [sizeof(Module_Flags) + sizeof(u32)]byte,
}

AST_Friend :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			inline_cmt : Code_Comment,
			_PAD_PROPRTIES_ : [sizeof(Code)]byte,
			declaration : Code,
			_PAD_PROPERTIES_ : [sizeof(Code)]byte,
		},
	},
	name   : string_cached,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [sizeof(Module_Flags) + sizeof(u32)]byte,
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
	_PAD_UNUSED_ : [sizeof(u32)]byte,
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
	_PAD_UNUSED_ : [sizeof(u32)]byte,
}

AST_NS :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			_PAD_PROPRTIES_ : [sizeof(Code) * 5]byte,
			body : Code_Body,
			_PAD_PROPERTIES_ : [sizeof(Code)]byte,
		},
	},
	name         : string_cached,
	prev         : Code,
	next         : Code,
	token        : ^Token,
	parent       : Code,
	type         : Code_Type,
	module_flags : Module_Flags,
	_PAD_UNUSED_ : [sizeof(u32)]byte,
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
			_PAD_PROPERTIES_ : [sizeof(Code)]byte,
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
			_PAD_PROPERTIES_   : [sizeof(Code)]byte,
			specs              : Code_Specifiers,
			value_type         : Code_Typename,
			_PAD_PROPERTIES_2_ : [sizeof(Code)]byte,
			body               : Code_Body,
			_PAD_PROPERTIES_3_ : [sizeof(Code)]byte,
		},
	},
	name   : string_cached,
	prev   : Code,
	next   : Code,
	token  : ^Token,
	parent : Code,
	type   : Code_Type,
	_PAD_UNUSED_ : [sizeof(Module_Flags) + sizeof(u32)]byte,
}

AST_Params :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			_PAD_PROPERTIES_2_ : [sizeof(Code) * 3]byte,
			value_type         : Code_Typename,
			macro              : Code,
			value              : Code,
			post_name_macro    : Code,
		},
	},
	name        : string_cached,
	prev        : Code,
	next        : Code,
	token       : ^Token,
	parent      : Code,
	type        : Code_Type,
	_PAD_UNUSED_ : [sizeof(Module_Flags)]byte,
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
	_PAD_UNUSED_ : [sizeof(Module_Flags) + sizeof(u32)]byte,
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
	_PAD_UNUSED_ : [sizeof(Module_Flags) + sizeof(u32)]byte,
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
	_PAD_UNUSED_ : [sizeof(Module_Flags)]byte,
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
			_PAD_PARAMS_ : [sizeof(Code)]byte,
			body         : Code_Body,
			_PAD_PROPERTIES_2_ : [sizeof(Code)]byte,
		},
	},
	name         : string_cached,
	prev         : Code_Typename,
	next         : Code_Typeanme,
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
			_PAD_PROPERTIES_ : [sizeof(Code)* 4]byte,
			params      : Code_Params,
			declaration : Code,
			_PAD_PROPERTIES_2_ : [sizeof(Code)]byte,
		},
	},
	name         : string_cached,
	prev         : Code_Typename,
	next         : Code_Typeanme,
	token        : ^Token,
	parent       : Code,
	type         : Code_Type,
	module_flags : Module_Flags,
	_PAD_UNUSED_ : [sizeof(u32)]byte,
}

AST_Typename :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			_PAD_INLINE_CMT_  : [sizeof(Code)]byte,
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
	_PAD_UNUSED_ : [sizeof(Module_Flags)]byte,
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
			_PAD_PROPERTIES_   : [sizeof(Code) * 2]byte,
			underlying_type    : Code,
			_PAD_PROPERTIES_2_ : [sizeof(Code) * 3]byte,
		},
	},
	name         : string_cached,
	prev         : Code,
	next         : Code,
	token        : ^Token,
	parent       : Code,
	type         : Code_Type,
	module_flags : Module_Flags,
	is_function  : b3,
}

AST_Union :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			_PAD_INLINE_CMT_   : [sizeof(Code)]byte,
			attributes         : Code_Attributes,
			_PAD_PROPERTIES_   : [sizeof(Code) * 3]byte,
			body               : Code_Body,
			_PAD_PROPERTIES_2_ : [sizeof(Code)]byte,
		},
	},
	name         : string_cached,
	prev         : Code,
	next         : Code,
	token        : ^Token,
	parent       : Code,
	type         : Code_Type,
	module_flags : Module_Flags,
	_PAD_UNUSED_ : [sizeof(u32)]byte,
}

AST_Using :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			inline_cmt       : Code_Comment,
			attributes       : Code_Attributes,
			_PAD_SPECS_      : [sizeof(Code)]byte,
			underlying_type  : Code_Typename,
			_PAD_PROPERTIES_ : [sizeof(Code)]byte,
		},
	},
	name         : string_cached,
	prev         : Code,
	next         : Code,
	token        : ^Token,
	parent       : Code,
	code_type    : Code_Type,
	module_flags : Module_Flags,
	_PAD_UNUSED_ : [sizeof(u32)]byte,
}

AST_Var :: struct {
	using _ : struct #raw_union {
		_PAD_   : [64]byte,
		using _ : struct {
			inline_cmt : Code_Comment,
			attributes : Code_Attributes,
			specs      : Code_Specifiers,
			value_type : Code_Typename,
		},
	},
	name                    : string_cached,
	prev                    : Code,
	next                    : Code,
	token                   : ^Token,
	parent                  : Code,
	type                    : Code_Type,
	module_flags            : Module_Flags,
	var_parenthesiszed_init : s32,
}

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

	macros : Marco_Table,

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
	vaid_def  |= type == .Class_Body
	vaid_def  |= type == .Enum_Body
	valid_def |= type == .Export_Body
	valid_def |= type == .Extern_Linkege
	valid_def |= type == .Function_Body
	valid_def |= type == .Global_Body
	valid_def |= type == .Namespace_Body
	valid_def |= type == .Struct_Body
	valid_def |= type == .Union_Body
	assert(valid_def)

	result     := make_code()
	result.type = type
	return transmute(CodeBody) result
}

token_fmt :: proc() -> string {
	return ""
}

Opts_Def_Struct :: struct {
	body           : Code_Body,
	parent         : Code_Typename,
	parent_access  : Access_Spec,
	attributes     : Attributes,
	interfaces     : Code_Typename,
	num_interfaces : i32,
	specifiers     : Code_Specifiers,
	mflags         : Module_Flags,
}

Opts_Def_Constructor :: struct {
	params           : Code_Params,
	initializer_list : Code,
	body             : body,
}

Opts_Def_Define :: struct {
	params  : Code_Define_Params,
	content : string,
	flags   : Macro_Flags,
	dont_register_to_preprocess_macros : b32,
}

Opts_Def_Destructor :: struct {
	body       : Code,
	specifiers : Code_Specifiers,
}

Opts_Def_Enum :: struct {
	body       : Code_Body,
	type       : Code_Typename,
	specifier  : Enum_Decl,
	attributes : Code_Attributes,
	mflags     : Module_Flags,
	type_macro : Code,
}

Opts_Def_Function :: struct {
	params     : Code_Params,
	ret_type   : Code_Typename,
	body       : Code_Body,
	specs      : Code_Specifiers,
	attributes : Code_Attributes,
	mflags     : Module_Flags,
}

Opts_Def_Include   :: struct { is_foreign : b32 } 
Opts_Def_Module    :: struct { mflags     : Module_Flags }
Opts_Def_Namespace :: struct { mflags     : Module_Flags }

Opts_Def_Operator :: struct {
	params     : Code_Params,
	ret_type   : Code_Typename,
	body       : Code_Body,
	specifiers : Code_Specifiers,
	attributes : Code_Attributes,
	mflags     : Module_Flags,
}

Opts_Def_Operator_Cast :: struct {
	body  : Code_Body,
	specs : Code_Specifiers,
}

Opts_Def_Param    :: struct { value  : Code }
Opts_Def_Template :: struct { mflags : Module_Flags }

Opts_Def_Type :: struct {
	type_tag   : Typename_Tag,
	array_expr : Code,
	specifiers : Code_Specifiers,
	attributes : Code_Attributes,
}

Opts_Def_Typedef :: struct {
	attributes : Code_Attributes,
	mflags     : Module_Flags,
}

Opts_Def_Union :: struct {
	attributes : Code_Attributes,
	mflags     : Module_Flags,
}

Opts_Def_Using :: struct {
	attributes : Code_Attributes,
	mflags     : Module_Flags,
}

Opts_Def_Variable :: struct {
	value      : Code,
	specifiers : Code_Specifiers,
	attributes : Code_Attributes,
	mflags     : Module_Flags,
}

@(default_calling_convention="c", link_prefix="gen_")
foreign gen
{
	init   :: proc(ctx : ^Context) ---
	deinit :: proc(ctx : ^Context) ---

	reset :: proc(ctx : ^Context) ---

	lookup_macro :: proc(name : string) -> ^Macro ---

	register_macro      :: proc(macro : Macro) ---
	register_macros_arr :: proc(num : i32, macros : ^Macros) ---

	cache_str :: proc(str : string) -> string_cached ---

	make_code :: proc() ---

	def_attributes      :: proc(content : string) -> Code_Attributes ---
	def_comment         :: proc(content : string) -> Code_Comment ---
	def_execution       :: proc(content : string) -> Code_Exec ---
	def_extern_link     :: proc(name : string, body : Code_Body) -> Code_Extern ---
	def_friend          :: proc(signature : Code) -> Code_Friend ---
	def_pragma          :: proc() ---
	def_preprocess_cond :: proc() ---
	def_specifier       :: proc() ---
	def_using_namespace :: proc(name : string) -> Code_Using ---

	def__class          :: proc(name : string,                           opts : Opts_Def_Struct)        -> Code_Class ---
	def__constructor    :: proc(                                         opts : Opts_Def_Constructor)   -> Code_Constructor ---
	def__define         :: proc(name : string, type : Macro_Type,        opts : Opts_Def_Define)        -> Code_Define ---
	def__destructor     :: proc(                                         opts : Opts_Def_Destructor)    -> Code_Destructor ---
	def__enum           :: proc(name : string,                           opts : Opts_Def_Enum)          -> Code_Enum ---
	def__function       :: proc(name : string,                           opts : Opts_Def_Function)      -> Code_Fn ---
	def__include        :: proc(content : string,                        opts : Opts_Def_Include)       -> Code_Include ---
	def__module         :: proc(name : string,                           opts : Opts_Def_Module)        -> Code_Module ---
	def__namespace      :: proc(name : string, body : CodeBody,          opts : Opts_Def_Namespace)     -> Code_NS ---
	def__operator       :: proc(op : Operator, nspace : string,          opts : Opts_Def_Operator)      -> Code_Operator ---
	def__operator_cast  :: proc(type : Code_Typename,                    opts : Opts_Def_Operator_Cast) -> Code_Op_Cast ---
	def__param          :: proc(type : Code_Typename, name : string,     opts : Opts_Def_Param)         -> Code_Params ---
	def__struct         :: proc(name : string,                           opts : Opts_Def_Struct)        -> Code_Struct ---
	def__template       :: proc(params : Code_Params, definition : Code, opts : Opts_Def_Template)      -> Code_Template ---
	def__type           :: proc(name : string,                           opts : Opts_Def_Type)          -> Code_Typename ---
	def__typedef        :: proc(name : string, type : Code,              opts : Opts_Def_Typedef)       -> Code_Typedef ---
	def__using          :: proc(name : string, type : Code_Typename,     opts : Opts_Def_Using)         -> Code_Using ---
	def__union          :: proc(name : string, body : Code_Body,         opts : Opts_Def_Union)         -> Code_Union ---
	def__variable       :: proc(type : Code_Typename, name : string,     opts : Opts_Def_Variable)      -> Code_Var ---

	def_class_body_arr       :: proc(num : i32, codes : ^Code) -> Code_Body ---
	def_define_params_arr    :: proc(num : i32, codes : ^Code) -> Code_Body ---
	def_enum_body_arr        :: proc(num : i32, codes : ^Code) -> Code_Body ---
	def_export_body_arr      :: proc(num : i32, codes : ^Code) -> Code_Body ---
	def_extern_link_body_arr :: proc(num : i32, codes : ^Code) -> Code_Body ---
	def_function_body_arr    :: proc(num : i32, codes : ^Code) -> Code_Body ---
	def_global_body_arr      :: proc(num : i32, codes : ^Code) -> Code_Body ---
	def_namespace_body_arr   :: proc(num : i32, codes : ^Code) -> Code_Body ---
	def_params_arr           :: proc(num : i32, codes : ^Code) -> Code_Params ---
	def_specifiers_arr       :: proc(num : i32, codes : ^Code) -> Code_Specifiers ---
	def_struct_body_arr      :: proc(num : i32, codes : ^Code) -> Code_Body ---
	def_union_body_arr       :: proc(num : i32, codes : ^Code) -> Code_Body ---

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
	parse_operator_cast :: proc(operator_def    : string) -> Code_Op_Cast ---
	parse_struct        :: proc(struct_def      : string) -> Code_Struct ---
	parse_template      :: proc(template_def    : string) -> Code_Template ---
	parse_type          :: proc(type_def        : string) -> Code_Typename ---
	parse_typedef       :: proc(typedef_def     : string) -> Code_Typedef ---
	parse_union         :: proc(union_def       : string) -> Code_Union ---
	parse_using         :: proc(using_def       : string) -> Code_Using ---
	parse_variable      :: proc(var_def         : string) -> Code_Var ---

	untyped_str :: proc(content : string) -> Code ---
}

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

@(default_calling_convention="c", link_prefix="gen_")
foreign gen
{
	_ctx : ^Context
}

// Data structures from the library will be redefined here for the sake of transparently exposing them to the package
// Their interface however was only redefined as necessary.

Allocation_Type :: enum(i32) {
	Alloc,
	Free,
	FreeAll,
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

odin_allocator_proc_wrapper :: proc(
	allocator_data : rawptr, 
	type           : Allocation_Type, 
	size           : c.ssize_t, 
	alignment      : c.ssize_t, 
	old_memory     : rawptr,
	old_size       : c.ssize_t,
	flags: u64) -> rawptr
{
	info := transmute(mem.Allocator) allocator_data
	memory, error := info.procedure(info.data, type, size, alignment, old_memory, old_size)
	return raw_data(memory)
}

allocator_from_odin_allocator :: #force_inline proc(allocator : ^mem.Allocator) -> Allocator_Info {
	result := Allocator_Info { 
		odin_allocator_proc_wrapper,
		raw_data(allocator)
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

Pool : struct {
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

Array :: struct($Type : typeid) { data : ^Type }

array_header :: #force_inline proc(array : Array($Type)) -> Array_Header { return mem.ptr_offset(cast(^ArrayHeader)(array),  -1) }
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

string_cached :: distinct string

Str_Builder_Header :: struct {
	allocator : Allocator_Info,
	capacity  : int,
	length    : int,
}

Str_Builder :: struct {
	data : ^c.char
}

strbuilder_header    :: #force_inline proc(builder : Str_Builder) -> Str_Builder_Header { return mem.ptr_offset(cast(^Str_Builder_Header)(builder), -1) }
strbuilder_to_string :: #force_inline proc(builder : Str_Builder) -> string             { return transmute(string) builder.data[:strbuilder_header(builder).length] }

// strbuilder is fully-inline in the header. So we're just re-implementing here.

strbuilder_make_str :: proc(allocator := USE_TEMP_ALLOCATOR, str : string) -> Str_Builder {
	return {}
}

strbuilder_fmt :: proc(allocator := USE_TEMP_ALLOCATOR, buf : c.char[] ) -> Str_Builder {
	return {}
}

strbuilder_fmt_buf :: proc(allocator := USE_TEMP_ALLOCATOR ) -> Str_Builder {
	return {}
}

strbuilder_join :: proc(allocator := USE_TEMP_ALLOCATOR, ) -> Str_Builder {
	return {}
}

strbuilder_make_space_for :: proc(builder : ^Str_Builder, amount : u32) -> bool {
	return false
}

strbuilder_append_char :: proc(builder : ^Str_Builder, char : c.char) -> bool {
	return false
}

strbuilder_append_string :: proc(builder : ^Str_builder, str : string) -> bool {
	return false
}

strbuilder_append_fmt :: proc(builder : ^Str_Builder ) -> bool {
	 return false
}

strbuilder_avail_space :: proc(builder : ^Str_Builder ) -> int {
	return 0
}

strbuilder_back :: proc(builder : ^Str_Builder) -> ^c.char {
	return nil
}

strbuilder_capacity :: proc(builder : ^Str_Builder) -> int {
	return 0
}

strbuilder_clear :: proc(builder : ^Str_Builder) {

}

strbiulder_duplicate :: proc(builder : ^Str_Builder, allocator := USE_TEMP_ALLOCATOR) -> StrBuilder {
	return {}
}
