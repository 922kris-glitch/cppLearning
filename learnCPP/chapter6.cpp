/*
★ Precedence and associativity. Predict and then print 2 + 3 * 4, 10 - 4 - 3, 2 * 3 % 4, !a && b, and a || b && c.
Prove: what binds tighter, and which direction chains evaluate. Add parentheses to the ones that surprised you.
★ Remainder with negatives. Print -7 % 3, 7 % -3, -7 / 3.
Prove: the remainder takes the sign of the left operand. Check that (a/b)*b + a%b == a holds.
★ Prefix vs postfix. Run int x{5}; int y{x++}; and int y{++x};, and print both.
Prove: postfix returns the old value.
★ Order of evaluation. Call f(i, i++) and i = i++ + ++i, comparing GCC and Clang if you can.
Prove: argument evaluation order is unspecified, and some forms are UB. The rule is never modify and read the same variable in one expression.
Comma operator. Write int x{(1, 2)}; and for (int i{0}, j{10}; i < j; ++i, --j).
Prove: the first returns the last value, and the second is its one legitimate use.
★ Ternary. Write max(a, b) with ?:, then try one branch returning int and the other double, and nest two ternaries.
Prove: the result type gets promoted, and nesting is unreadable. Also check that cout << a > b ? a : b misbehaves from precedence.
★ Float comparison. Do relational tests on values that should be equal after arithmetic, using your Chapter 4 almostEqual.
Prove: exact == fails for computed values, and the epsilon version passes.
★ Short-circuit. Write bool f() that prints when called, and test false && f() and true || f().
Prove: f never runs. Then guard a null-pointer-style check with &&.
De Morgan. Write truth tables in code proving !(a && b) == (!a || !b) for all four combinations.
*/