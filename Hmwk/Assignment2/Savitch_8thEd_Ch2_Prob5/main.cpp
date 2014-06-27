/* Chapter 2 Problem 5
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 26, 2014, 3:58 PM
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
    float need; //(known/input)Amount of money the costumer needs to receive in dollars
    float inter; //(known/input)Interest rate in percent
    float durat; //(known/input)The duration of the loan in months
    float face; //(unknown)The actual face value of the loan in dollars
    float monpay; //(unknown)Monthly payment in dollars
    
    //User Inputs
    cout << "Enter the amount of money you need to receive in dollars:" << endl;
    cin >> need;
    cout << "Enter the interest rate of the loan in percent:" << endl;
    cin >> inter;
    cout << "Enter the duration of the loan in months" << endl;
    cin >> durat;
    
    //Calculations
    //Calculate the face value of the loan
    face = need / (1-(inter / 100 )* (durat / 12));
    //Calculate monthly payment
    monpay = face / durat;

    //Output the results
    cout << "Face value of loan required = $" << face << endl;
    cout << "Required monthly payment = $" << monpay << endl;

    //Exit Stage Right!
    return 0;
}