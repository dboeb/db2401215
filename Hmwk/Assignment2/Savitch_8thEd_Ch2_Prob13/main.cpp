/* Chapter 2 Problem 13
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on July 1, 2014, 3:19 PM
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Starts Here!
int main(int argc, char** argv) {
    //Declare variables
    //Inputs
    float mph;   //Speed in miles per hour
    //Outputs
    int min;     //minutes per mile
    float sec;   //seconds per mile
    float secrem;//Seconds per mile remaining from minutes per mile
    
    //Input Values      
    cout<<"Enter speed in miles per hour"<<endl;
    cin>>mph;
    
    //Calculations
    //Calculate the seconds per mile
    sec=1/(mph/(60*60));
    //Calculate minutes per mile
    min=sec/60;
    //Calculate seconds remainder from minutes
    secrem=static_cast<int>(sec)%60;
    
    //Output the results4
    cout<<mph<<" mph is equivalent to "<<min<<" minutes and ";
    cout<<secrem<<" seconds per mile"<<endl;
 
    //Exit stage right
    return 0;
}