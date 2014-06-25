/* Chapter 1 Problem 8
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 24, 2014, 4:29 PM
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
    int qrtrs, dimes, nickels, //Number of Quarters, Number of Dimes, Number of Nickels
        qrtval = 25, dimval = 10, nicval = 5, //Value of a Quarter, Value of a Dime, Value of a Nickel
        qrtcnts, dimcnts, niccnts, cents; // Total Cents in Quarters, Total Cents in Dimes, Total Cents in Nickels, Total Cents
    
    //User Inputs
    //User Input for entering the number of quarters
    cout << "Press return after entering a number.\n";
    cout << "Enter the number of quarters:\n";
    cin >> qrtrs;
    //User Input for entering the number of dimes
    cout << "Enter the number of dimes:\n";
    cin >> dimes;
    //User Input for entering the number of nickels
    cout << "Enter the number of nickels:\n";
    cin >> nickels;
    
    //Program Calculations
    //Calculate the total value of quarters
    qrtcnts = qrtrs * qrtval;
    //Calculate the total value of dimes
    dimcnts = dimes * dimval;
    //Calculate the total value of nickels
    niccnts = nickels * nicval;
    //Calculate total monetary value of the coins in cents
    cents = qrtcnts + dimcnts + niccnts;
    
    //Output the results
    cout << "Total Amount of Money:" << endl;
    cout << cents;
    cout << " cents" << endl;
    
    //Exit Stage Right!
    return 0;
}