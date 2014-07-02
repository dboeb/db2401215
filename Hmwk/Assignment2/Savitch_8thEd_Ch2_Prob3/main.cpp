/* Chapter 2 Problem 3
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 26, 2014, 2:52 PM
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
    //Inputs and Constants
    const float PAYINC=7.6e-2f;//Percentage retroactive pay increase
    const float MONRET=6;      //months of retroactive pay
    float osalary;             //old annual salary in dollars
    //Outputs
    float nsalary;             //new annual salary after increase in dollars
    float rpay;                //retroactive pay due to employee in dollars
    float omonsal;             //old monthly salary in dollars
    float nmonsal;             //new monthly salary in dollars
    float mondif;              //monthly salary difference between old and new monthly salaries
    
    //Input Values
    cout<<"Enter previous employee annual salary in dollars then press return:"<<endl;
    cin>>osalary;
    
    //Calculations
    //Calculate the new annual salary
    nsalary=osalary*(1+PAYINC);
    //Calculate monthly salaries
    omonsal=osalary/12;
    nmonsal=nsalary/12;
    //Calculate difference in monthly salaries
    mondif=nmonsal-omonsal;
    //Calculate Retroactive pay due
    rpay=mondif*MONRET;
      

    //Output the results
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Retroactive Pay =    $"<<setw(10)<<rpay<<endl;
    cout<<"New Annual Salary =  $"<<setw(10)<<nsalary<<endl;
    cout<<"New Monthly Salary = $"<<setw(10)<<nmonsal<<endl;

    //Exit Stage Right!
    return 0;
}