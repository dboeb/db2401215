/* Chapter 1 Problem 6
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 24, 2014, 3:52 PM
 */

//System Library
#include <iostream> // If an extra space is added after the <, the error recieved is "main.cpp:8:21: fatal error:  iostream: No such file or directory"
                    // If one of the < or > are missing, the error recieved is "main.cpp:8:151: error: missing terminating > character"
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
//Program from problem 5
int main (int argc, char** argv) { // If the int is missing, the program lets out an incorrect value "
                                   // If the word main is misspelled or missing, the error recieved is a "BUILD FAILED"
                                   // If one of the ( or ) is missing, the error recieved is "main.cpp:20:13: error: expected initializer before 'argc'"
    //Declare and initialize variables
    int frstint, scndint, intsum, intprod; //First Integer, Second Integer, Sum of Integers, Product of Integers
           
    //User Inputs
    //User Input for entering the first integer
    cout << "Press return after entering a number.\n";
    cout << "Enter the first integer:\n";
    cin >> frstint;
    //User Input for entering the second integer
    cout << "Enter the second integer:\n";
    cin >> scndint;
    
    //Program Calculations
    //Calculate the sum of the two integers
    intsum = frstint + scndint;
    //Calculate the product of the two integers
    intprod = frstint * scndint;
    
    //Output the results
    cout << "If you add ";
    cout << frstint;
    cout << " and ";
    cout << scndint << endl;
    cout << "you will get ";
    cout << intsum << endl;
    cout << "If you multiply ";
    cout << frstint;
    cout << " and ";
    cout << scndint << endl;
    cout << "you will get ";
    cout << intprod;
  
    //Exit Stage Right!
    return 0;
}