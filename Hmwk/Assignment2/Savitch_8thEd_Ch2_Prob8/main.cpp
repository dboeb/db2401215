/* Chapter 2 Problem 8
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 30, 2014, 4:35 PM
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
    float cost,//(known/input)cost of the item(s) in dollars
          years,//(known/input)number of years from now that the item will be purchased
          inflate,//(known/input)the rate of inflation in percent per year
          newcost;//(unknown)estimated price after inflation in dollars
    //Input current cost, years to purchase, and rate of inflation
    cout<<"Enter the cost of the item(s) in dollars:"<<endl;
    cin>>cost;
    cout<<"Enter the number of years from now"<<endl<<"that the item will be purchased:"<<endl;
    cin>>years;
    cout<<"Enter the rate of inflation in percent per year:"<<endl;
    cin>>inflate;
    //Calculate the estimated price after inflation
    newcost=cost+cost*years*(inflate/100);
    //Output the estimated price of item(s)
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Estimated cost of item(s)"<<endl<<"due to inflation = $"<<newcost;
    //Exit stage right
    return 0;
}