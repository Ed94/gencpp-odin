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

AST_POD_SIZE        :: 128
AST_ARRAY_SPECS_CAP :: 14

Code                 :: ^AST
Code_Body            :: ^AST_Body
Code_Attributes      :: ^AST_Attributes
Code_Comment         :: ^AST_Comment
Code_Class           :: ^AST_Class
Code_Constructor     :: ^AST_Constructor
Code_Define          :: ^AST_Define
Code_Define_Params   :: ^AST_Define_Params
Code_Destructor      :: ^AST_Destructor
Code_Enum            :: ^AST_Enum
// Code_Exec            :: ^AST_Exec
Code_Extern          :: ^AST_Extern
Code_Include         :: ^AST_Include
Code_Friend          :: ^AST_Friend
Code_Fn              :: ^AST_Fn
Code_Module          :: ^AST_Module
Code_NS              :: ^AST_NS
Code_Operator        :: ^AST_Operator
Code_Op_Cast         :: ^AST_Op_Cast
Code_Params          :: ^AST_Define_Params
Code_Preprocess_Cond :: ^AST_Preprocess_Cond
Code_Pragma          :: ^AST_Pragma
Code_Specifiers      :: ^AST_Sepcifiers
Code_Struct          :: ^AST_Struct
Code_Template        :: ^AST_Template
Code_Typename        :: ^AST_Typename
Code_Typedef         :: ^AST_Typedef
Code_Union           :: ^AST_Union
Code_Using           :: ^AST_Using
Code_Var             :: ^AST_Var

@(default_calling_convention="c", link_prefix="gen_")
foreign gen {
	Code_Invalid : Code
}

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
	append_code,
	append_body,
	append_attributes,
	append_comment,
	append_class,
	append_constructor,
	append_define,
	append_define_params,
	append_destructor,
	append_enum,
	// append_exec,
	append_include,
	append_friend,
	append_fn,
	append_module,
	append_ns,
	append_operator,
	append_op_cast,
	append_pragma,
	append_params,
	append_preprocess_cond,
	append_specifiers,
	append_struct,
	append_template,
	append_typename,
	append_typename,
	append_typedef,
	append_union,
	append_using,
	append_var
}

debug_str :: proc {
	debug_str_code,
	debug_str_body,
	debug_str_attributes,
	debug_str_comment,
	debug_str_class,
	debug_str_constructor,
	debug_str_define,
	debug_str_define_params,
	debug_str_destructor,
	debug_str_enum,
	// debug_str_exec,
	debug_str
}

duplicate :: proc {

}

entry :: proc {

}

has_entries :: proc {

}

is_body :: proc {

}

is_equal :: proc {

}

is_valid :: proc {

}

set_global :: proc {

}

to_strbuilder :: proc {

}

to_strbuilder_ptr :: proc {

}

type_str :: proc {

}

validate_body :: proc {

}

@(default_calling_convention="c", link_prefix="gen_")
foreign gen
{
	code__debug_str     :: proc(code        : Code) -> string     ---
	code__duplicate     :: proc(code        : Code) -> Code       ---
	code__is_equal      :: proc(code        : Code) -> bool       ---
	code__to_strbuilder :: proc(code        : Code) -> strbuilder ---

	
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
	name        : string_cache,
	prev        : Code,
	next        : Code,
	token       : ^Token,
	parent      : Code,
	type        : Code_Type,
	moule_flags : Module_Flags,
	access_spec : Access_Spec,
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

Array_Header :: struct {
	allocator : Allocator_Info,
	capacity  : uint,
	num       : uint,
}

USE_TEMP_ALLOCATOR :: Allocator_Info{}

Array :: struct($Type : typeid) { data : ^Type }

array_header :: #force_inline proc(array : Array($Type)) -> Array_Header { return mem.ptr_offset(cast(^ArrayHeader)(array),  -1) }
array_slice  :: #force_inline proc(array : Array($Type)) -> []Type       { return array.data[:array_header(array).num] }

string_cached :: distinct string

Str_Builder_Header :: struct {
	allocator : Allocator_Info,
	capacity  : int,
	length    : int,
}

Str_Builder :: struct {
	data : ^c.char
}

strbuilder_header :: #force_inline proc(builder : Str_Builder) -> Str_Builder_Header { return mem.ptr_offset(cast(^Str_Builder_Header)(builder), -1) }
strbuilder_to_str :: #force_inline proc(builder : Str_Builder) -> string             { return transmute(string) builder.data[:strbuilder_header(builder).length] }

// strbuilder is fully-inline in the header. So we're just re-implementing here.

strbuiilder_make_str :: proc(allocator := USE_TEMP_ALLOCATOR, str : string) -> Str_Builder {
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