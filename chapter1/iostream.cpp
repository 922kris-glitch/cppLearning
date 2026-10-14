#include <iostream>
using namespace std;
/*
Purpouse:

to create a program that accepts input and outputs in this format:

Enter three numbers: 4 5 6
You entered 4, 5, and 6.

*/

/*
//my wrong code
int main(){

int x = 0;
int y =0;
int z =0;

cout << "Enter three numbers: ";
cin>>x;
cout<< " " ; 
cin>>y; 
cout << " ";
cin>>z;

cout << "You entered " << x << ", " << y << ", and " << z << '\n';


}

*/

//awnser
#include <iostream>

// Asks the user to enter three values and then print those values as a sentence.
int main()
{
    std::cout << "Enter three numbers: ";

int x = 0;
int y =0;
int z =0;
    std::cin >> x >> y >> z;

    std::cout << "You entered " << x << ", " << y << ", and " << z << ".\n";

    return 0;
}