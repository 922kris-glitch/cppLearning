/*★ const vs constexpr. Make const int a{userInput}; and constexpr int b{userInput};.
Prove: b fails to compile, while a is fine but can’t be used as an array size. Then make const int c{5}; and use it as an array size, which works. Explain the difference in one sentence.
★ Constant expression test. Write about 8 variable definitions (const/constexpr, literal/runtime initializer, const double, const int from a function call). Predict which are usable in constexpr int x{...}; and compile to check.
★ constexpr function. Write constexpr int square(int). Call it once with a literal inside a constexpr variable and once with runtime input.
Prove: the same function works in both contexts. Add static_assert(square(4) == 16); to confirm the compile-time call.
★ Literal suffixes and types. Print sizeof and the type name for 5, 5L, 5u, 5.0, 5.0f, '5', "5".
Prove: literals have types, and "5" is a char array, not a std::string.
Numeral systems. Print 0b1010, 012, 0x1F, and 1'000'000. Print a value through std::bitset<8>.
Prove: a leading zero means octal. That bug is real.
★ Magic numbers. Write a function with a hard-coded 0.0825 tax, then refactor it to a named constexpr. Put it in a namespace.
★ string vs string_view. Pass a long std::string to a function by value and by std::string_view.
Prove: with a debugger or allocation counter, the by-value call copies and the view doesn’t.
★ string_view dangling. Create a string_view from a std::string, then modify or destroy the string and print the view. Also return a string_view from a function that built a local std::string.
Prove: it reads garbage or crashes under the sanitizer. A view doesn’t own its characters.
Input pitfalls. Mix cin >> name with getline.
Prove: the leftover newline makes getline return an empty string. Fix it with cin.ignore.
String basics. Check .length() against strlen, concatenate with +, compare with ==, and index past the end with [] vs .at().

*/