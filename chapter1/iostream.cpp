#include <iostream>
using namespace std;
/*
Purpouse:

to create a program that accepts input and outputs in this format:

Enter three numbers: 4 5 6
You entered 4, 5, and 6.

*/
int main(){

int x {};
int y {};
int z {};

cout << "Enter three numbers: ";
cin>>x;
cout<< " " ; 
cin>>y; 
cout << " ";
cin>>z;

cout << "You entered " << x << ", " << y << ", and " << z;


}