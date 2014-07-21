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
void ave_and_stDev(int,int,int,int,float&,float&);
float average(int,int,int,int);
float sta_dev(int,int,int,int,float);
void compute_coins(int,int&,int&);


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
    char m;    //AM/PM information for 12 hour notation
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
    cout<<endl<<endl;
}

//Solution to problem 2
void problem2(){
    //Declare Variables
    //Inputs
    int hourT;  //Time in hours
    int minuteT;//Time in minutes
    int hourW;  //Hours to wait
    int minuteW;//Minutes to wait
    //Outputs
    int hourN;  //Time in hours after waiting
    int minuteN;//Time in minutes after waiting
    
    //Input Values
    cout<<"Enter the Time in 24-Hour Notation:"<<endl;
    cout<<"Enter the hours"<<endl;
    cin>>hourT;
    cout<<"Enter the minutes"<<endl;
    cin>>minuteT;
    cout<<"Enter the Wait Period:"<<endl;
    cout<<"Enter the hours"<<endl;
    cin>>hourW;
    cout<<"Enter the minutes"<<endl;
    cin>>minuteW;
    
    //Calculations
    //Calculate the Time After Waiting
    minuteN=minuteT+minuteW;
    hourN=hourT+hourW;
    if (minuteN>=60){
        minuteN-=60;
        hourN++;
    }
    if (hourN>=24){
        hourN-=24;
    }
    
    //Output Results
    cout<<showpoint<<fixed<<setprecision(0);
    cout<<"The time after waiting "<<hourW<<" hours and "<<minuteW<<" minutes"<<endl;
    cout<<"is "<<hourN<<":"<<setw(2)<<minuteN<<endl;
    
    //Exit Stage Right!
    cout<<endl<<endl;
}

//Solution to problem 3
void problem3(){
    //Declare Variables
    //Inputs
    int hourT;  //Time in hours
    int minuteT;//Time in minutes
    int hourW;  //Hours to wait
    int minuteW;//Minutes to wait
    char m;     //AM/PM information for the 12-hour notation
    //Outputs
    int hourN;  //Time in hours after waiting
    int minuteN;//Time in minutes after waiting
    
    //Input Values
    cout<<"Enter the Time in 24-Hour Notation:"<<endl;
    cout<<"Enter the hours"<<endl;
    cin>>hourT;
    cout<<"Enter the minutes"<<endl;
    cin>>minuteT;
    cout<<"Enter the Wait Period:"<<endl;
    cout<<"Enter the hours"<<endl;
    cin>>hourW;
    cout<<"Enter the minutes"<<endl;
    cin>>minuteW;
    
    //Calculations
    //Calculate the Time After Waiting
    minuteN=minuteT+minuteW;
    hourN=hourT+hourW;
    if (minuteN>=60){
        minuteN-=60;
        hourN++;
    }
    if (hourN>=24){
        hourN-=24;
    }
    //Calculate the Time in 12-hour Notation
    time_conv(hourN,minuteN,m);
    
    //Output Results
    cout<<showpoint<<fixed<<setprecision(0);
    cout<<"The time after waiting "<<hourW<<" hours and "<<minuteW<<" minutes"<<endl;
    cout<<"is "<<time_conv(hourN,minuteN,m)<<":"<<setw(2)<<minuteN<<" "<<m<<"M"<<endl;
    
    //Exit Stage Right!
    cout<<endl<<endl;
}

//Solution to problem 4
void problem4(){
    //Declare Variables
    //Inputs
    int s1;  //Score 1
    int s2;  //Score 2
    int s3;  //Score 3
    int s4;  //Score 4
    //Outputs
    float a; //Average of the four scores
    float sd;//Standard Deviation of the four scores
    
    //Input Values
    cout<<"Enter Score 1"<<endl;
    cin>>s1;
    cout<<"Enter Score 2"<<endl;
    cin>>s2;
    cout<<"Enter Score 3"<<endl;
    cin>>s3;
    cout<<"Enter Score 4"<<endl;
    cin>>s4;
    
    //Calculations
    //Calculate the Average and Standard Deviation
    ave_and_stDev(s1,s2,s3,s4,a,sd);
    
    //Output Results
    cout<<showpoint<<fixed<<setprecision(1);
    cout<<"Average of Scores = "<<a<<endl;
    cout<<"Standard Deviation = "<<sd<<endl;
    
    //Exit Stage Right!
    cout<<endl<<endl;
}

//Solution to problem 5
void problem5(){
    //Declare Variables
    //Inputs
    int cents;           //Number of cents
    const int quarVal=25;//Value of a quarter in cents
    const int dimeVal=10;//Value of a dime in cents
    const int pennVal=1; //Value of a penny in cents
    //Outputs
    int quarter;         //Number of quarters
    int dime;            //Number of dimes
    int penny;           //Number of pennies
    
    //Input Values
    do {
        cout<<"Enter the amount of change in cents"<<endl;
        cin>>cents;
        if (cents<1||cents>99){
            cout<<"The value must be between 1 and 99"<<endl;
        }
    }
    while(cents<1||cents>99);
    
    //Calculations
    //Calculate the number of quarters
    compute_coins(quarVal,quarter,cents);
    //Calculate the number of dimes
    compute_coins(dimeVal,dime,cents);
    //Calculate the number of pennies
    penny=cents;
    
    //Output Results
    cout<<"Number of Quarters = "<<setw(2)<<quarter<<endl;
    cout<<"Number of Dimes    = "<<setw(2)<<dime<<endl;
    cout<<"Number of Pennies  = "<<setw(2)<<penny<<endl;
    
    //Exit Stage Right!
    cout<<endl<<endl;
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

//Calculation for Standard Deviation
//Inputs
//    coin_value    ->value of the coin in cents
//    num           ->number of that coin
//    amount_left   ->amount of change left in cents
//Outputs
//    NONE
void compute_coins(int coin_value,int& num,int& amount_left){
    num=amount_left/coin_value;
    amount_left-=num*coin_value;
}

//Calculation for Standard Deviation
//Inputs
//    s1    ->score 1
//    s2    ->score 2
//    s3    ->score 3
//    s4    ->score 4
//    a     ->average of the scores
//Outputs
//    sd    ->Standard deviation of the scores
float sta_dev(int s1,int s2,int s3,int s4,float a){
    return sqrt(((s1-a)*(s1-a)+(s2-a)*(s2-a)+(s3-a)*(s3-a)+(s4-a)*(s4-a))/static_cast<float>(4));
}

//Calculation for Average
//Inputs
//    s1    ->score 1
//    s2    ->score 2
//    s3    ->score 3
//    s4    ->score 4
//Outputs
//    a     ->average of the scores
float average(int s1,int s2,int s3,int s4){
    return (s1+s2+s3+s4)/static_cast<float>(4);
}

//Calculations for average and standard deviation
//Inputs
//    s1    ->score 1
//    s2    ->score 2
//    s3    ->score 3
//    s4    ->score 4
//    a     ->average of the scores
//    sd    ->standard deviation of the scores
//Outputs
//    NONE
void ave_and_stDev(int s1,int s2,int s3,int s4,float& a,float& sd){
    a=average(s1,s2,s3,s4);
    sd=sta_dev(s1,s2,s3,s4,a);
}

//Function for Problem 1 Outputs
//Inputs
//    hour    ->hours for time in 24-hour notation
//    minutes ->for time in 24-hour notation
//    m       ->AM/PM information for 12-hour notation
//Outputs
//    NONE
void prob1Ou(int hour,int minutes,char m){
    cout<<showpoint<<fixed<<setprecision(0);
    cout<<"The time is "<<time_conv(hour,minutes,m)<<":"<<setw(2)<<minutes<<" "<<m<<"M"<<endl;
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
    }else{
        m='A';
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