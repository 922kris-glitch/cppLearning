/*
Chapter 1: variables, initialization, undefined behavior
★ Initialization zoo. Define one variable each with int a;, int b = 5;, int c(5);, int d{5};, int e{};, and print them.
Prove: a is garbage (read it only once, to see it). e is 0. int f{5.7}; is a compile error, while int g = 5.7; compiles and gives 5. That error is why brace init is preferred.
★ Uninitialized read. Read an uninitialized int and print it. Run it at -O0 and at -O2.
Prove: the output differs between builds and nothing warns you at runtime. That is undefined behavior: the language promises nothing about what happens.
★ Assignment vs initialization. Write int x{3}; x = 7; and explain which line creates the variable and which changes it. Then write int x{3}; int x{4}; and read the error.
Input handling. Read two ints with cin.
Prove: type abc and see what the variables become. Type 5 6 7 and see where the leftover 7 goes.
Expressions vs statements. Write x = 5 inside an if condition on purpose, and print its value.
Prove: an assignment is itself an expression with a value. This is the classic = vs == bug.
Keywords and identifiers. Try naming a variable int, _Foo, my-var, and 2fast.
Prove: which are rejected, and why.
*/

#include <iostream>

void localVar()
{
    int a=9;
    std::cout<<a<<'\n';
    return;

}

int main(){


/*
Initialization zoo. Define one variable each with int a;, int b = 5;, int c(5);, int d{5};, int e{};, and print them.
Prove: a is garbage (read it only once, to see it). e is 0. int f{5.7}; is a compile error, while int g = 5.7; compiles and gives 5. That error is why brace init is preferred.
*/

int a; // default initialization
int b=5; //copy initialization
int c (5); // dirrect initialization
int d{5}; // list initialization
int e{}; // empty list initialization


//shaddowing a
localVar();

std::cout<< a<<b<<c<<d<<e<<'\n';


}