/* Chapter 2 Problem 5
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 26, 2014, 3:58 PM
 */

//System Library
#include <iostream>
#include <iomanip>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    //Inputs
    float need;  //Amount of money the costumer needs to receive in dollars
    float inter; //Interest rate in percent
    float durat; //The duration of the loan in months
    //Outputs
    float face;  //The actual face value of the loan in dollars
    float monpay;//Monthly payment in dollars
    
    //Input Values
    cout<<"Enter the amount of money you need to receive in dollars:"<<endl;
    cin>>need;
    cout<<"Enter the interest rate of the loan in percent:"<<endl;
    cin>>inter;
    cout<<"Enter the duration of the loan in months"<<endl;
    cin>>durat;
    
    //Calculations
    //Calculate the face value of the loan
    face=need/(1-(inter/100)*(durat/12));
    //Calculate monthly payment
    monpay=face/durat;

    //Output the results
    cout<<setprecision(2)<< fixed<<showpoint;
    cout<<"Face value of loan required = $"<<setw(9)<<face<<endl;
    cout<<"Required monthly payment =    $"<<setw(9)<<monpay<<endl;

    //Exit Stage Right!
    return 0;
}