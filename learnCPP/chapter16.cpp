/*
Constructor traps. Print size() for each of vector<int> v(10), v{10}, v = {10}, v{}, and vector<int> v(10, 5). Predict first, then check.

Length vs capacity. Push 100,000 elements one at a time and print size() and capacity() whenever capacity changes. Work out your compiler’s growth factor. Repeat with reserve(100000) first and count reallocations (zero). Then try resize(n) followed by push_back and see that the new elements land after n zeros.

Reallocation invalidates references. Take a reference (and an iterator) to v[0], then push_back until capacity grows, then read through the stale reference under AddressSanitizer. This is the single most important vector intricacy to see fail.

Bounds behavior. Compare out-of-bounds v[i] (silent or sanitizer error), v.at(i) (catch the exception), and back() / pop_back() on an empty vector. Catch std::out_of_range and print the message.

Copy vs move vs reference.
Write a small class that prints from its copy constructor, move constructor, and destructor.
Put several in a vector and pass the vector by value, by const&, and return it from a function. Count the copies and moves for each.
Try push_back(obj), push_back(Obj{...}), and emplace_back(...), and compare the output.

Range-for variants. Loop over a vector<std::string> with auto, auto&, and const auto&. Use your printing class to show which ones copy, and which ones let you modify the original.

Index loops and the unsigned problem. Write a reverse loop three ways: broken size_t, a signed index with a cast, and a range-based reverse (or rbegin/rend). Compile with -Wconversion and read the warnings. Run all three on an empty vector.

vector<bool> surprise. Write a template T& first = v[0] helper and try it on vector<int> and vector<bool>. Read the compiler error. Compare sizeof and behavior with vector<char>.

Stack practice (interview staple). Implement a balanced-parentheses checker and a “min stack” using only push_back, pop_back, back, and empty. Test empty input, a lone closing bracket, and very deep nesting.

*/