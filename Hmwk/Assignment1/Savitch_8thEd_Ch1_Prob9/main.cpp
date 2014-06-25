/* Chapter 1 Problem 9
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 24, 2014, 4:51 PM
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
    unsigned short time; //time in seconds
    float ACCEL = 9.82, dist; //Acceleration due to gravity in m/s^2, distance fallen in meters
    
    //User Inputs
    //User Input for entering the number of quarters
    cout << "Press return after entering a number." << endl;
    cout << "Enter the time falling in seconds:" << endl;
    cin >> time;
    
    //Program Calculations
    //Calculate the total distance traveled
    dist = ACCEL * time * time / 2;

    //Output the results
    cout << "Total Distance traveled: ";
    cout << dist;
    cout << " meters" << endl;
    
    //Exit Stage Right!
    return 0;
}