# gencpp-odin

gencpp bindings for the odin programming language

An attempt at simple staged metaprogramming for C/C++. Reflect and generate code for your codebase at runtime!

TODO: Add splash

The library API is a composition of code element constructors, and a non-standards-compliant single-pass C/C++ parser.  
These build up a code AST to then serialize with a file builder, or can be traversed for staged-reflection of C/C++ code.

## Notes

This project is still in development (very much an alpha state), so expect bugs and missing features.  
See [issues](https://github.com/Ed94/gencpp/issues) for a list of known bugs or todos.

The library can already be used to generate code just fine, but the parser is where the most work is needed. If your C++ isn't "down to earth" expect issues.

