/* Chapter 1 Problem 5
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 24, 2014, 3:32 PM
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