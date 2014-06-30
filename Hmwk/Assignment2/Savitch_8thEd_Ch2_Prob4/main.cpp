/* Chapter 2 Problem 4
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 26, 2014, 3:38 PM
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
    //Declare and initialize variables
    const float PAYINC = 7.6e-2f; //(known/constant)Percentage retroactive pay increase
    float monret; //(known/input)months of retroactive pay
    float osalary; //(known/input)old annual salary in dollars
    float nsalary; //(unknown)new annual salary after increase in dollars
    float rpay; //(unknown)retroactive pay due to employee in dollars
    float omonsal; //(unknown)old monthly salary in dollars
    float nmonsal; //(unknown)new monthly salary in dollars
    float mondif; //(unknown)monthly salary difference between old and new monthly salaries
    //User Inputs
    cout << "Enter previous employee annual salary in dollars then press return:" << endl;
    cin >> osalary;
    cout << "Enter months of retroactive pay:" << endl;
    cin >> monret;
    
    //Calculations
    //Calculate the new annual salary
    nsalary = osalary * (1 + PAYINC);
    //Calculate monthly salaries
    omonsal = osalary / 12;
    nmonsal = nsalary / 12;
    //Calculate difference in monthly salaries
    mondif = nmonsal - omonsal;
    //Calculate Retroactive pay due
    rpay = mondif * monret;
      

    //Output the results
    cout << setprecision(2) << fixed << showpoint;
    cout << "Retroactive Pay =    $" << setw(10) << rpay << endl;
    cout << "New Annual Salary =  $" << setw(10) << nsalary << endl;
    cout << "New Monthly Salary = $" << setw(10) << nmonsal << endl;

    //Exit Stage Right!
    return 0;
}