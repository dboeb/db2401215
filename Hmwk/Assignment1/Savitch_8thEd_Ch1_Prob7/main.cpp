/* Chapter 1 Problem 7
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on June 24, 2014, 4:09 PM
 */

//System Library
#include <iostream>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Screen Output for the Program
    //Top Border
    cout << "****************************************" << endl;
    //Blank  Row
    cout << endl;
    //Rows of C's, S's, and !'s for the first message
    cout << "          CCC         SSSS       !!     " << endl;
    cout << "        C     C     S      S     !!     " << endl;
    cout << "       C           S             !!     " << endl;
    cout << "      C             S            !!     " << endl;
    cout << "      C              SSSS        !!     " << endl;
    cout << "      C                    S     !!     " << endl;
    cout << "       C                    S    !!     " << endl;
    cout << "        C     C     S      S            " << endl;
    cout << "          CCC         SSSS       00     " << endl;
    //Blank  Row
    cout << endl;
    //Bottom Border
    cout << "****************************************" << endl;
    //Final Message
    cout << "   Computer Science is Cool Stuff!!!    ";
  
    //Exit Stage Right!
    return 0;
}