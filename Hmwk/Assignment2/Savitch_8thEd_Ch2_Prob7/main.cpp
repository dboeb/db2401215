/* Chapter 2 Problem 7
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 30, 2014, 2:53 PM
 */
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Starts Here!
int main(int argc, char** argv) {
    //Declare variables
    //Inputs and Constants
    float hours;           //number of hours worked
    int depend;            //number of dependants
    const float WAGE=16.78;//pay rate in dollars per hour
    const float HEALTH=35; //extra health insurance cost for dependants in dollars
    const float UNDUE=10;  //Union dues in dollars
    const float SS=0.06;   //Social security tax percent
    const float FED=0.14;  //Federal income tax percent
    const float STATE=0.05;//State income tax percent
    //Outputs
    float grosspay;        //Workers gross pay in dollars
    float sstax;           //social security tax withholding amount in dollars
    float fedinc;          //federal income tax withholding amount in dollars
    float statinc;         //state income tax withholding amount in dollars
    float netpay;          //net take-home pay for the week in dollars
    
    //Input Values
    cout<<"Enter the number of hours worked in a week:"<<endl;
    cin>>hours;
    cout<<"Enter the number of dependants"<<endl;
    cin>>depend;
    
    //Calculations
    //Calculate gross pay, each withholding amount, and the net take-home pay
    if (hours<=40){
        if (depend<3){
            grosspay=hours*WAGE;
            sstax=grosspay*SS;
            fedinc=grosspay*FED;
            statinc=grosspay*STATE;
            netpay=grosspay-sstax-fedinc-statinc-UNDUE;
        }
        else {
            grosspay=hours*WAGE;
            sstax=grosspay*SS;
            fedinc=grosspay*FED;
            statinc=grosspay*STATE;
            netpay=grosspay-sstax-fedinc-statinc-HEALTH-UNDUE;
        }
    }
    else {
        if (depend<3){
            grosspay=40*WAGE + WAGE*1.5*(hours-40);
            sstax=grosspay*SS;
            fedinc=grosspay*FED;
            statinc=grosspay*STATE;
            netpay=grosspay-sstax-fedinc-statinc-UNDUE;
        }
        else {
            grosspay=40*WAGE + WAGE*1.5*(hours-40);
            sstax=grosspay*SS;
            fedinc=grosspay*FED;
            statinc=grosspay*STATE;
            netpay=grosspay-sstax-fedinc-statinc-HEALTH-UNDUE;
        }
    }
    
    //Output the results
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Gross Pay =                   $"<<setw(7)<<grosspay<<endl;
    cout<<"Social Security Tax =         $"<<setw(7)<<sstax<<endl;
    cout<<"Federal Income Tax =          $"<<setw(7)<<fedinc<<endl;
    cout<<"State Income Tax =            $"<<setw(7)<<statinc<<endl;
    cout<<"Union Dues =                  $"<<setw(7)<<UNDUE<<endl;
    if (depend>=3)cout<<"Health Insurance Additional = $"<<setw(7)<<HEALTH<<endl;
    else cout<<"Health Insurance Additional = $   n/a"<<endl;
    cout<<"Net Take-Home Pay =           $"<<setw(7)<<netpay<<endl;
    
    //Exit stage right
    return 0;
}