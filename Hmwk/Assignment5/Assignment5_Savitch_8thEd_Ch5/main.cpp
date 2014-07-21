/* Assignment 5 Savitch 8th Edition Chapter 5
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on July 21, 2014, 12:09 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();
void prob1In(int&,int&);
int time_conv(int,int,char&);
void prob1Ou(int,int,char);

//Execution begins here
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1: problem1();break;
        case 2: problem2();break;
        case 3: problem3();break;
        case 4: problem4();break;
        case 5: problem5();break;
        case 6: problem6();break;
        case 7: problem7();break;
        case 8: problem8();break;
        case 9: problem9();break;
        case 10: problem10();break;
            default:;
        };
    }while(inN<11);
    return 0;
}

//Menu Function
void Menu(){
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type 7 for problem 7"<<endl;
    cout<<"Type 8 for problem 8"<<endl;
    cout<<"Type 9 for problem 9"<<endl;
    cout<<"Type 10 for problem 10"<<endl;
    cout<<"Type 11 to exit \n"<<endl;
}

//Choose problem number function
int getN(){
    int inN;
    cin>>inN;
    return inN;
}

//Solution to problem 1
void problem1(){
    //Declare Variables
    //Inputs
    int hour24;//Hours in 24 hour notation
    int minute;//minutes in 24 hour notation
    char m='A';//AM/PM information for 12 hour notation
    //Outputs
    int hour12;//Hours in 12 hour notation
    
    //Input Values
    prob1In(hour24,minute);
    
    //Calculations
    //Calculate 12 hour notation
    time_conv(hour24,minute,m);
    
    //Output Results
    prob1Ou(hour24,minute,m);
    
    //Exit Stage Right!
}

//Solution to problem 2
void problem2(){
    cout<<"Random Integration to find PI again"<<endl<<endl;
    //Display exact values of PI
    cout<<"Pi = "<<fixed<<setprecision(15)<<atan(1)*4<<endl<<endl;
    //Declare variables
    int nDarts,inCircle=0,maxRandom=pow(2,31);
    float approxPI=0;
    //Ask question as to number of darts
    cout<<"During the dart game, How many darts do you want to throw"<<endl;
    cin>>nDarts;
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Start playing the game
    for(int throwDart=1;throwDart<=nDarts;throwDart++){
        float x=1.0f*rand()/maxRandom;
        float y=1.0f*rand()/maxRandom;
        if((x*x+y*y)<=1)inCircle++;
    }
    //Calculate the approx value of PI
    approxPI=4.0f*inCircle/nDarts;
    //Output the result
    cout<<"The Approximate value of PI = "<<approxPI<<endl<<endl;
}

//Solution to problem 3
void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
}

//Solution to problem 4
void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
}

//Solution to problem 5
void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
}

//Solution to problem 6
void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
}

//Solution to problem 7
void problem7(){
    cout<<"In problem # 7"<<endl<<endl;
}

//Solution to problem 8
void problem8(){
    cout<<"In problem # 8"<<endl<<endl;
}

//Solution to problem 9
void problem9(){
    cout<<"In problem # 9"<<endl<<endl;
}

//Solution to problem 10
void problem10(){
    cout<<"In problem # 10"<<endl<<endl;
}

//Exit Comment
void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

//Function for Problem 1 Outputs
//Inputs
//    hour    ->hours for time in 24-hour notation
//    minutes ->for time in 24-hour notation
//    m       ->AM/PM information for 12-hour notation
//Outputs
//    hour12  ->hours for time in 12-hour notation
void prob1Ou(int hour,int minutes,char m){
    cout<<"The time is "<<time_conv(hour,minutes,m)<<":"<<minutes<<" "<<m<<"M"<<endl;
}

//Time Conversion from 24 to 12 hour notation
//Inputs
//    hour    ->hours for time in 24-hour notation
//    minutes ->for time in 24-hour notation
//    m       ->AM/PM information for 12-hour notation
//Outputs
//    hour12  ->hours for time in 12-hour notation
int time_conv(int hour24,const int minute, char& m){
    int hour12;
    if (hour24>12){
        hour12=hour24-12;
    }else{
        hour12=hour24;
    }
    if (hour24>=12){
        m='P';
    }
    return hour12;
}

//Function for Problem 1 Inputs
//Inputs
//    hour    ->hours for time in 24-hour notation
//    minutes ->for time in 24-hour notation
//Outputs
//    NONE
void prob1In(int& hour, int& minutes){
    //Input Values
    cout<<"Enter the time in 24-hour notation"<<endl;
    cout<<"First enter the hours"<<endl;
    cin>>hour;
    cout<<"Now enter the minutes"<<endl;
    cin>>minutes;
}