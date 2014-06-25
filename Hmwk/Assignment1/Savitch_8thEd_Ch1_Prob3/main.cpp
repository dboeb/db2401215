/* Chapter 1 Problem 3
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 24, 2014, 3:15 PM
 */

//System Library
#include <iostream>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    unsigned short numOPod, peperpo, totPeas; //Number of Pods, Peas Per Pod, Total Peas
    
    //User Inputs
    //User Input for entering number of pods
    cout << "Hello" << endl;
    cout << "Press return after entering a number." << endl;
    cout << "Enter the number of pods:" << endl;
    cin >> numOPod;
    //User Input for entering number of peas in a pod
    cout << "Enter the number of peas in a pod:" << endl;
    cin >> peperpo;
    
    //Calculate the total number of peas
    totPeas = numOPod / peperpo; //* was changed to /
    
    //Output the results
    cout << "If you have ";
    cout << numOPod;
    cout << " pea pods" << endl;
    cout << "and ";
    cout << peperpo;
    cout << " peas in each pod, then" << endl;
    cout << "you have ";
    cout << totPeas;
    cout << " peas in all the pods." << endl;
    cout << "Good-bye" << endl;
    //Exit Stage Right!
    return 0;
}


