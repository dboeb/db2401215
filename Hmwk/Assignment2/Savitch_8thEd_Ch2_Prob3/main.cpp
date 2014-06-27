/* Chapter 2 Problem 3
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 26, 2014, 2:52 PM
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
    const float PAYINC = 7.6e-2f; //(known/constant)Percentage retroactive pay increase
    const float MONRET = 6; //(known/constant)months of retroactive pay
    float osalary; //(known/input)old annual salary in dollars
    float nsalary; //(unknown)new annual salary after increase in dollars
    float rpay; //(unknown)retroactive pay due to employee in dollars
    float omonsal; //(unknown)old monthly salary in dollars
    float nmonsal; //(unknown)new monthly salary in dollars
    float mondif; //(unknown)monthly salary difference between old and new monthly salaries
    //User Inputs
    cout << "Enter previous employee annual salary in dollars then press return:" << endl;
    cin >> osalary;
    
    //Calculations
    //Calculate the new annual salary
    nsalary = osalary * (1 + PAYINC);
    //Calculate monthly salaries
    omonsal = osalary / 12;
    nmonsal = nsalary / 12;
    //Calculate difference in monthly salaries
    mondif = nmonsal - omonsal;
    //Calculate Retroactive pay due
    rpay = mondif * MONRET;
      

    //Output the results
    cout << "Retroactive pay due to employee = $" << rpay << endl;
    cout << "New annual salary = $" << nsalary << endl;
    cout << "New monthly salary = $" << nmonsal << endl;

    //Exit Stage Right!
    return 0;
}