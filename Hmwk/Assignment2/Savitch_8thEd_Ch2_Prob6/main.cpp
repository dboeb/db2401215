/* Chapter 2 Problem 1
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 30, 2014, 11:32 AM
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
    //Inputs and Constants
    int maxcap;//maximum room capacity
    int people;//number of people currently in room 
    //Outputs
    int addpe; //how many additional people may legally attend if capacity not reached
    int expe;  //how many people must leave to make room capacity legal
 
    //Input Variables
    cout<<"What is the maximum room capacity?"<<endl;
    cin>>maxcap;
    cout<<"How many people are attending the meeting?"<<endl;
    cin>>people;
    
    //Output the results
    if (people<=maxcap){
        addpe=maxcap-people;
        cout<<"It is legal to hold a meeting."<<endl;
        cout<<addpe<<" more people can attend the meeting.";
    }
    else {
        expe=people-maxcap;
        cout<<"A meeting cannot be held as planned"<<endl<<"due to fire regulations."<<endl;
        cout<<expe<<" people need to be excluded"<<endl<<"in order to meet the fire regulations."; 
    }
    
    //Exit stage right
    return 0;
}
