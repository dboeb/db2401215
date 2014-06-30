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
    float hours;//(known/input)number of hours worked
    int depend;//(known.input)number of dependants
    const float WAGE=16.78,//(known,constant)pay rate in dollars per hour
                HEALTH=35,//(known/constant)extra health insurance cost for dependants in dollars
                UNDUE=10,//(known/constant)Union dues in dollars
                SS=0.06,//(known/constant)Social security tax percent
                FED=0.14,//(known/constant)Federal income tax percent
                STATE=0.05;//(known/constant)State income tax percent
    float grosspay,//(unknown)Workers gross pay in dollars
          sstax,//(unknown)social security tax withholding amount in dollars
          fedinc,//(unknown)federal income tax withholding amount in dollars
          statinc,//(unknown)state income tax withholding amount in dollars
          netpay;//(unknown)net take-home pay for the week in dollars
    //Input hours worked and number of dependants
    cout<<"Enter the number of hours worked in a week:"<<endl;
    cin>>hours;
    cout<<"Enter the number of dependants"<<endl;
    cin>>depend;
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
    //Output gross pay, each withholding amount, and the net take-home pay
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