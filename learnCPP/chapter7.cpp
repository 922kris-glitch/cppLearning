/*
★ Scope and lifetime. Nest blocks, define a variable in the inner block, and try to use it after the closing brace.
Prove: it’s a compile error, and the variable is destroyed at }.
★ Shadowing. Define x in an outer block and again in an inner one. Print it before, inside, and after.
Prove: -Wshadow warns, and the inner x hides the outer one without changing it.
★ Static local. Write int counter() with static int n{0}; return ++n;. Call it 3 times.
Prove: it’s initialized once and persists. Compare with the same function without static.
★ Global vs local in two files. Define int g{5}; in a.cpp and extern int g; in b.cpp, then use it.
Prove: extern declares without defining. Then remove the definition to get a linker error (undefined reference), and define it in both files to get a duplicate definition error.
★ Internal vs external linkage. Mark a global static in a.cpp and try extern-ing it from b.cpp. Then try a non-static const int.
Prove: static globals are private to the file, and const globals default to internal linkage, so they can’t be reached from another file without extern.
★ Header and ODR. Put a function definition in util.h and include it from two .cpp files, then add inline.
Prove: without inline you get a duplicate-symbol link error. With it, the build succeeds. Also check that header guards or #pragma once stop a double include inside a single file.
★ inline constexpr constants. Put inline constexpr double pi{3.14159}; in a header used by two files.
Prove: the address &pi is identical in both files, which proves there’s one object.
Namespaces and using. Define the same function name in two namespaces. Call each by qualified name, then add using namespace for both.
Prove: the call becomes ambiguous, which is why using namespace std; in a header is a bad idea.
Unnamed namespace. Replace static globals with an unnamed namespace.
Prove: the symbol is still file-private.
Why globals are bad. Write three functions that secretly modify a non-const global, then try to unit-test one in isolation.
Prove: tests depend on call order, so you can’t reason about any function alone.
*/