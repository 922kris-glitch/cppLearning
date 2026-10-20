/*
Decay demonstration. Print sizeof of a C-style array in main and inside a function that takes it as a parameter (int arr[]). Add std::size inside the function and read the compile error. Then pass it by reference and by template and watch the length survive.

The old sizeof idiom. Write the sizeof(arr)/sizeof(arr[0]) length calculation in both places and show it silently gives the wrong answer in the function.

Pointer arithmetic by hand. Print the addresses of arr, arr+1, arr+2 for an int[], then for a char[] and a double[]. Confirm the step equals sizeof of the element type. Show that arr[i], *(arr+i), and i[arr] all give the same value. Then show relative indexing: point at element 3 and print p[-1], p[0], p[1].

Reimplement range-based for. Write a begin/end pointer loop over an array, then pull it into a function taking (const int* begin, const int* end) so it works on any sub-range. Use it to implement reverse, sum, and “find first”.

One-past-the-end. Make end = arr + n, loop up to it, and confirm you never dereference end. Then deliberately dereference it under the sanitizer.

std::array and compile-time checks. Write a function template over std::array<T, N> that uses static_assert(N > 3) and one that uses std::get<3>. Pass in arrays of length 2 and 5, and read the compile errors. Then try making N an int instead of size_t and see the template fail to match.

Enum-indexed table. Build an enum with a count enumerator and a constexpr std::array of names indexed by it. Add a static_assert on the size, then add an enumerator without updating the array and watch it fail to compile.

Brace initialization trap. Make a struct and a std::array<struct, 3> initialized with single braces and without naming the type per element (it fails), with double braces (it works), and with the type named at each element. Read the error you get from the first one.

C-string hazards. Write your own strlen with pointer arithmetic, and a function that prints a C-string backwards. Then deliberately overwrite the terminator (or build an unterminated char array) and print it under the sanitizer. Try cin >> buf vs cin.getline(buf, size) with a too-long input. Print a char* vs static_cast<const void*> of the same pointer.

2D arrays and memory order. Fill a large 2D array (e.g. 5000x5000) and sum it row-major, then column-major, and time both. The difference demonstrates row-major layout and why access order matters. Then flatten it into a 1D vector with row * cols + col indexing and confirm it matches.
*/