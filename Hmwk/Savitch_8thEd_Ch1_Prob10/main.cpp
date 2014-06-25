/* Chapter 1 Problem 10
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 24, 2014, 5:06 PM
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
    unsigned short time, divcons = 2; //time in seconds, division constant
    float accel = 9.82, dist; //Acceleration due to gravity in m/s^2, distance fallen
    
    //User Inputs
    //User Input for entering a character
    cout << "Press any character then press return:\n";
    cin >> time;

    //Output the results
    //Message of the letter "C" using X's
    cout << "  X X X" << endl;
    cout << " X    X" << endl;
    cout << "X      " << endl;
    cout << "X      " << endl;
    cout << "X      " << endl;
    cout << "X      " << endl;
    cout << "X      " << endl;
    cout << " X    X" << endl;
    cout << "  X X X" << endl;
    
    //Exit Stage Right!
    return 0;
}