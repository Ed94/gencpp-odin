# gencpp-odin

**NOTE: BINDINGS ARE NOT FINISHED. WILL NOT WORK YET.**

[gencpp](https://github.com/Ed94/gencpp) bindings for the odin programming language

An attempt at simple staged metaprogramming for C/C++. Reflect and generate code for your codebase at runtime!

TODO: Add splash

The library API is a composition of code element constructors, and a non-standards-compliant single-pass C/C++ parser. These build up a code AST to then serialize with a file builder, or can be traversed for staged-reflection of C/C++ code.

## Notes

This project is still in development (very much an alpha state), so expect bugs and missing features.  
See [gencpp/issues](https://github.com/Ed94/gencpp/issues) for a list of known bugs or todos.

The library can already be used to generate code just fine, but the parser is where the most work is needed. If your C++ isn't "down to earth" expect issues.

## Bindings Info

***Note: These bindings have not been well tested. Any reported issues are appreciated.***

The c11 variant of the library is used. Any inlines are re-implemented. Because the library dependencies are derived from zpl they are very compatible with odin's memory allocation model. Thus all data structures are trasparently defined with the bindings.

For convience some of the bindings have to_string and slices wrappers. The provided serialization interface utilize's gencpp's `StrBuilder` (in the bindings package its `Str_Builder`), which doesn't interop with odin's fmt or strings.builder. Eventually I'll get around to just porting serialization to utilize odin's core packages instead.

For documentation see [gencpp/docs](https://github.com/Ed94/gencpp/blob/main/Readme.md)
