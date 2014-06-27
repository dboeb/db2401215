/* Chapter 2 Problem 2
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 26, 2014, 4:32 PM
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
    const float ARTSWE = 0.01; //(known/constant)percent of artificial sweetener in soda
    float deadmou; //(known/input)Amount of artificial sweetener needed to kill a mouse in pounds
    float mouswe; //(known/input)weight of the mouse in pounds
    float dietwe; //(known/input)weight of the dieter after the diet in pounds
    float swerat; //(unknown)ratio of sweetener weight to body weight
    float deaddie; //(unknown)amount of artificial sweetener needed to kill the dieter in pounds
    float sodawe; //(unknown)weight of soda required to kill dieter in pounds
    
    //User Inputs
    cout << "Enter the amount of artificial sweetener needed to kill a mouse in pounds:" << endl;
    cin >> deadmou;
    cout << "Enter the weight of the mouse in pounds:" << endl;
    cin >> mouswe;
    cout << "Enter the weight of the dieter after the diet in pounds" << endl;
    cin >> dietwe;
    
    //Calculations
    //Calculate the weight ratio of the sweetener and mouse
    swerat = deadmou / mouswe;
    //Calculate weight of sweetener required to kill dieter
    deaddie = dietwe * swerat;
    //Calculate the weight of soda required to kill dieter
    sodawe = deaddie / ARTSWE;
    
    //Output the results
    cout << "weight of soda safe for consumption = less than " << sodawe << " pounds of soda" << endl;

    //Exit Stage Right!
    return 0;
}