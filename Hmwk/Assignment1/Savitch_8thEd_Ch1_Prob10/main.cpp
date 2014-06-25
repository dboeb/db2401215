/* Chapter 1 Problem 10
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 24, 2014, 5:06 PM
 */

//System Library
#include <iostream>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare and initialize variables
    char inpt; // Character Input
    
    //User Inputs
    //User Input for entering a character
    cout << "Press any character then press return: ";
    cin >> inpt;

    //Output the results
    //Message of the letter "C" using imputed character
    cout << endl;
    cout << "  " << inpt << " " << inpt << " " << inpt << endl;
    cout << " " << inpt << "    " << inpt << endl;
    cout << inpt << endl;
    cout << inpt << endl;
    cout << inpt << endl;
    cout << inpt << endl;
    cout << inpt << endl;
    cout << " " << inpt << "    " << inpt << endl;
    cout << "  " << inpt << " " << inpt << " " << inpt << endl;
    
    //Exit Stage Right!
    return 0;
}