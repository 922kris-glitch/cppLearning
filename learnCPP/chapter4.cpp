#include <iostream>
#include <cstdint>
#include <climits>
#include <iomanip>
#include <cmath>
#include <vector>

int main() {
    // ==========================================
    // 1. sizeof table
    // ==========================================
    // 1. ★ sizeof table. Print sizeof for char, short, int, long, long long, float, double, bool.
    //   - Prove: sizes are minimums set by the platform, not fixed. Then do the same with int8_t, int32_t, uint64_t to see what “fixed-width” gives you.
    std::cout << "=== 1. sizeof Table ===" << std::endl;
    std::cout << "char: " << sizeof(char) << " bytes\n";
    std::cout << "short: " << sizeof(short) << " bytes\n";
    std::cout << "int: " << sizeof(int) << " bytes\n";
    std::cout << "long: " << sizeof(long) << " bytes\n";
    std::cout << "long long: " << sizeof(long long) << " bytes\n";
    std::cout << "float: " << sizeof(float) << " bytes\n";
    std::cout << "double: " << sizeof(double) << " bytes\n";
    std::cout << "bool: " << sizeof(bool) << " bytes\n";

    std::cout << "\nFixed-width types (<cstdint>):\n";
    std::cout << "int8_t: " << sizeof(int8_t) << " byte\n";
    std::cout << "int32_t: " << sizeof(int32_t) << " bytes\n";
    std::cout << "uint64_t: " << sizeof(uint64_t) << " bytes\n\n";
// C++ dose not guarente int and long have the same size across machines, only int#_t have same length across all machines

    // ==========================================
    // 2. Unsigned wraparound
    // ==========================================
    // 2. ★ Unsigned wraparound. Set unsigned int u{0}; --u; and print it. Add 1 to the max of unsigned char.
    //   - Prove: unsigned wrap is well-defined and lands on the max value or 0.
    std::cout << "=== 2. Unsigned Wraparound ===" << std::endl;
    unsigned int u{0};
    --u;
    std::cout << "unsigned int u{0}; --u -> " << u << " (UINT_MAX)\n";

    unsigned char max_uc = UCHAR_MAX;
    unsigned char wrapped_uc = max_uc + 1;
    std::cout << "unsigned char max (" << static_cast<int>(max_uc) << ") + 1 -> " 
              << static_cast<int>(wrapped_uc) << " (wraps to 0)\n\n";
// unsigned arithmatic is well defined and understood behavior

    // ==========================================
    // 3. Signed overflow
    // ==========================================
    // 3. ★ Signed overflow. Set int to INT_MAX and add 1, using the UB sanitizer.
    //   - Prove: the sanitizer flags it. Signed overflow is undefined, unlike unsigned.
    std::cout << "=== 3. Signed Overflow ===" << std::endl;
    // Compile with -fsanitize=undefined to catch this: g++ -fsanitize=undefined file.cpp
    int max_int = INT_MAX;
    std::cout << "INT_MAX: " << max_int << std::endl;
    // int overflowed = max_int + 1; // Undefined Behavior!
    std::cout << "(Signed overflow is Undefined Behavior and not guaranteed to wrap predictably)\n\n";
//signed overflow is UB

    // ==========================================
    // 4. Signed/unsigned comparison trap
    // ==========================================
    // 4. ★ Signed/unsigned comparison trap. Compare -1 < 1u, and loop for (unsigned i{5}; i >= 0; --i).
    //   - Prove: the first comparison is false. The loop never ends. Use std::size_t and .size() to see why this bites with containers.
    std::cout << "=== 4. Signed/Unsigned Comparison Trap ===" << std::endl;
    std::cout << "-1 < 1u is: " << (-1 < 1u ? "true" : "false") 
              << " (-1 converts to a massive unsigned value)\n";

    // Infinite loop demonstration (shown safely via comment/alternative):
    // for (unsigned i{5}; i >= 0; --i) { /* Infinite loop because i is always >= 0 */ }
    std::cout << "Loop 'for (unsigned i{5}; i >= 0; --i)' never ends because unsigned is never < 0.\n\n";
//, In a condition w/ signed and unsigned, it will convert signed to unsigned to preven UB

    // ==========================================
    // 5. Float precision
    // ==========================================
    // 5. ★ Float precision. Print 0.1 + 0.2 == 0.3, then print 0.1 with setprecision(20). Add 0.1f ten times and compare to 1.0f.
    //   - Prove: floats are binary approximations. Write an epsilon-based almostEqual function and test it on the cases that failed.
    std::cout << "=== 5. Float Precision ===" << std::endl;
    std::cout << std::boolalpha;
    std::cout << "0.1 + 0.2 == 0.3: " << (0.1 + 0.2 == 0.3) << std::endl;
    
    std::cout << std::fixed << std::setprecision(20);
    std::cout << "0.1 with setprecision(20): " << 0.1 << std::endl;

    float sum_f{0.0f};
    for(int i = 0; i < 10; ++i) {
        sum_f += 0.1f;
    }
    std::cout << "Sum of 0.1f ten times == 1.0f: " << (sum_f == 1.0f) << std::endl;

    auto almostEqual = [](double a, double b, double eps = 1e-9) {
        return std::fabs(a - b) < eps;
    };
    std::cout << "almostEqual(0.1 + 0.2, 0.3): " << almostEqual(0.1 + 0.2, 0.3) << std::endl;
    std::cout << std::defaultfloat << std::setprecision(6);
    std::cout << std::endl;
//float and double are floating point numbers and they are not exact double result = 0.1 + 0.2;
// result is actually 0.30000000000000004, NOT 0.3!
//so you cant do regular comparison, you must do:
/*
bool nearlyEqual(float a, float b, float epsilon = 0.00001f) {
    return std::abs(a - b) < epsilon;
}
*/

    // ==========================================
    // 6. Float special values
    // ==========================================
    // 6. Float special values. Divide 1.0/0.0, -1.0/0.0, and 0.0/0.0. Check std::isnan and std::isinf.
    //   - Prove: float division by zero doesn’t crash, but integer 1/0 is undefined.
    std::cout << "=== 6. Float Special Values ===" << std::endl;
    double pos_inf = 1.0 / 0.0;
    double neg_inf = -1.0 / 0.0;
    double nan_val = 0.0 / 0.0;

    std::cout << "1.0 / 0.0 isinf? " << std::isinf(pos_inf) << " (" << pos_inf << ")\n";
    std::cout << "-1.0 / 0.0 isinf? " << std::isinf(neg_inf) << " (" << neg_inf << ")\n";
    std::cout << "0.0 / 0.0 isnan? " << std::isnan(nan_val) << " (" << nan_val << ")\n";
    std::cout << "(Integer division 1/0 would trigger hardware traps/undefined behavior).\n\n";
// float quirks you get infinite, -infinite, and not a number

    // ==========================================
    // 7. Integer division
    // ==========================================
    // 7. ★ Integer division. Compare 7/2, -7/2, 7.0/2, 7/2.0, and static_cast<double>(7)/2.
    //   - Prove: truncation happens before assignment to a double, so double d{7/2} gives 3.
    std::cout << "=== 7. Integer Division ===" << std::endl;
    std::cout << "7 / 2 = " << 7 / 2 << std::endl;
    std::cout << "-7 / 2 = " << -7 / 2 << std::endl;
    std::cout << "7.0 / 2 = " << 7.0 / 2 << std::endl;
    std::cout << "7 / 2.0 = " << 7 / 2.0 << std::endl;
    std::cout << "static_cast<double>(7)/2 = " << static_cast<double>(7) / 2 << std::endl;

    double d{7 / 2}; // truncates to 3 first, then converts to double (3.0)
    std::cout << "double d{7/2} results in: " << d << std::endl << std::endl;
// int devision gets truncated into an int and the decimal getss dropped, for double and int operations, the int gets converted to a double

    // ==========================================
    // 8. char as number
    // ==========================================
    // 8. char as number. Print char c{'A'}, c + 1, static_cast<int>(c), and int8_t values.
    //   - Prove: cout prints the type, not the bits. int8_t often prints as a character.
    std::cout << "=== 8. char as number ===" << std::endl;
    char c{'A'};
    std::cout << "c: " << c << std::endl;
    std::cout << "c + 1 (promoted to int): " << c + 1 << std::endl;
    std::cout << "static_cast<int>(c): " << static_cast<int>(c) << std::endl;

    int8_t small_int{65};
    std::cout << "int8_t value 65 prints as char due to overload: " << small_int 
              << ", cast to int: " << static_cast<int>(small_int) << std::endl << std::endl;
// CHar in c++ is just intigers following ASCII so when you do addition it converts to an int

    // ==========================================
    // 9. static_cast and narrowing
    // ==========================================
    // 9. ★ static_cast and narrowing. Brace-initialize an int from a double and from a runtime long. Then fix both with static_cast.
    //   - Prove: narrowing in braces is an error, while explicit casts are your “I meant it” marker.
    std::cout << "=== 9. static_cast and Narrowing ===" << std::endl;
    double pi{3.14159};
    long runtime_val{100};

    // Error in strict list initialization:
    // int bad1{pi};           // Error: narrowing conversion from double to int
    // int bad2{runtime_val};  // Error: narrowing conversion (long is wider/runtime)

    // Fixed with static_cast:
    int good1{static_cast<int>(pi)};
    int good2{static_cast<int>(runtime_val)};
    std::cout << "Fixed with static_cast -> good1: " << good1 << ", good2: " << good2 << std::endl << std::endl;
// static_cast forces conversion and tels compiler i wat to do this narrowing

    // ==========================================
    // 10. bool
    // ==========================================
    // 10. bool. Print a bool with and without boolalpha, and test if (5), if (-1), if (0.0).
    //   - Prove: any nonzero value is true.
    std::cout << "=== 10. bool ===" << std::endl;
    bool flag{true};
    std::cout << "Without boolalpha: " << flag << std::endl;
    std::cout << "With boolalpha: " << std::boolalpha << flag << std::endl;

    if (5) { std::cout << "if (5) is true\n"; }
    if (-1) { std::cout << "if (-1) is true\n"; }
    if (0.0) { /* won't execute */ } else { std::cout << "if (0.0) evaluates to false\n"; }

    return 0;
    // 0,0.0 is false, andthing else is true
}