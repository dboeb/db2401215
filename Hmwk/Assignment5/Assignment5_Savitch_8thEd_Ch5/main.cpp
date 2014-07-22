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
const float IN2CENT=2.54;//Conversion from inches to centimeters
const float OU2GRAM=28.3495;//Conversion from ounces to grams

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
void prob6In(int&,int&);
void ft_to_mtrs(int,int,int&,int&);
void prob6Ou(int,int);
void prob7In(int&,int&);
void mtrs_to_ft(int,int,int&,int&);
void prob7Ou(int,int);
void prob9In(int&,int&);
void lb_to_kg(int,int,int&,int&);
void prob9Ou(int,int);
void prob10In(int&,int&);
void kg_to_lb(int,int,int&,int&);
void prob10Ou(int,int);

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
    //Declare Variables
    //Inputs
    int feet;  //Number of feet
    int inches;//Number of inches
    //Outputs
    int meters;//Number of meters
    int centi; //Number of centimeters
    
    //Input Values
    prob6In(feet,inches);
    
    //Calculations
    //Calculate length in Metric Units
    ft_to_mtrs(feet,inches,meters,centi);
    
    //Output Results
    prob6Ou(meters,centi);
    
    //Exit Stage Right!
    cout<<endl<<endl;
}

//Solution to problem 7
void problem7(){
    //Declare Variables
    //Inputs
    int meters;//Number of meters
    int centi; //Number of centimeters
    //Outputs
    int feet;  //Number of feet
    int inches;//Number of inches
    
    //Input Values
    prob7In(meters,centi);
    
    //Calculations
    //Calculate length in Metric Units
    mtrs_to_ft(meters,centi,feet,inches);
    
    //Output Results
    prob7Ou(feet,inches);
    
    //Exit Stage Right!
    cout<<endl<<endl;
}

//Solution to problem 8
void problem8(){
    //Declare Variables
    //Inputs or Outputs (Depending on User Decision)
    char choice;//Choice for conversion
    int meters; //Number of meters
    int centi;  //Number of centimeters
    //Outputs or Inputs (Depending on User Decision)
    int feet;   //Number of feet
    int inches; //Number of inches
    
    //Input Values
    cout<<"Enter 'M' to convert English Units to Metric Units"<<endl;
    cout<<"Or Enter 'E' to convert Metric Units to English Units"<<endl;
    cin>>choice;
    switch(choice){
            case 'M':
            case 'm':{
                prob6In(feet,inches);
                break;
            }
            case 'E':
            case 'e':{
                prob7In(meters,centi);
                break;
            }
            default:{
                //Defaulted to convert Metric Units to English Units because America Uses English Units
                cout<<"Invalid input, defaulted to convert Metric Units to English Units"<<endl;
                prob7In(meters,centi);
                choice='E';
                break;
            }
    }
    
    //Calculations
    //Calculate length conversion
    if (choice=='M'||choice=='m'){
        ft_to_mtrs(feet,inches,meters,centi);
    }else{
        mtrs_to_ft(meters,centi,feet,inches);
    }
    
    //Output Results
    if (choice=='M'||choice=='m'){
        prob6Ou(meters,centi);
    }else{
        prob7Ou(feet,inches);
    }
    
    //Exit Stage Right!
    cout<<endl<<endl;
}

//Solution to problem 9
void problem9(){
    //Declare Variables
    //Inputs
    int pounds;//Number of pounds
    int ounces;//Number of ounces
    //Outputs
    int kilos; //Number of kilograms
    int grams; //Number of grams
    
    //Input Values
    prob9In(pounds,ounces);
    
    //Calculations
    //Calculate weight in Metric Units
    lb_to_kg(pounds,ounces,kilos,grams);
    
    //Output Results
    prob9Ou(kilos,grams);
    
    //Exit Stage Right!
    cout<<endl<<endl;
}

//Solution to problem 10
void problem10(){
    //Declare Variables
    //Inputs
    int kilos; //Number of kilograms
    int grams; //Number of grams
    //Outputs
    int pounds;//Number of pounds
    int ounces;//Number of ounces
    
    //Input Values
    prob10In(kilos,grams);
    
    //Calculations
    //Calculate weight in English Units
    kg_to_lb(kilos,grams,pounds,ounces);
    
    //Output Results
    prob10Ou(pounds,ounces);
    
    //Exit Stage Right!
    cout<<endl<<endl;
}

//Exit Comment
void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

//Function for Problem 10 Outputs
//Inputs
//    pounds  ->Number of pounds
//    ounces  ->Number of ounces
//Outputs
//    NONE
void prob10Ou(int pounds,int ounces){
    cout<<"The weight in English Units is"<<endl;
    cout<<pounds<<" pounds and "<<ounces<<" ounces"<<endl;
}

//Weight Conversion from Metric to English Units
//Inputs
//    kilos  ->number of kilograms
//    grams  ->number of grams
//    pounds ->number of pounds
//    ounces ->number of ounces
//Outputs
//    NONE
void kg_to_lb(int kilos,int grams,int& pounds,int& ounces){
    grams=kilos*1000+grams;
    ounces=grams/OU2GRAM;
    pounds=ounces/16;
    ounces=ounces-pounds*16;
}

//Function for Problem 10 Inputs
//Inputs
//    kilos  ->number of kilograms for weight
//    grams  ->number of grams for weight
//Outputs
//    NONE
void prob10In(int& kilos,int& grams){
    //Input Values
    cout<<"Enter the weight in kilograms and grams:"<<endl;
    cout<<"First enter the kilograms"<<endl;
    cin>>kilos;
    cout<<"Now enter the grams"<<endl;
    cin>>grams;
}

//Function for Problem 9 Outputs
//Inputs
//    kilos  ->Number of kilograms
//    grams  ->Number of grams
//Outputs
//    NONE
void prob9Ou(int kilos,int grams){
    cout<<"The weight in Metric Units is"<<endl;
    cout<<kilos<<" kilograms and "<<grams<<" grams"<<endl;
}

//Weight Conversion from English to Metric Units
//Inputs
//    pounds ->number of pounds
//    ounces ->number of ounces
//    kilos  ->number of kilograms
//    grams  ->number of grams
//Outputs
//    NONE
void lb_to_kg(int pounds,int ounces,int& kilos,int& grams){
    ounces=ounces+pounds*16;
    grams=ounces*OU2GRAM;
    kilos=grams/1000;
    grams=grams-kilos*1000;
}

//Function for Problem 9 Inputs
//Inputs
//    pounds  ->number of pounds for weight
//    ounces  ->number of ounces for weight
//Outputs
//    NONE
void prob9In(int& pounds,int& ounces){
    //Input Values
    cout<<"Enter the weight in pounds and ounces:"<<endl;
    cout<<"First enter the pounds"<<endl;
    cin>>pounds;
    cout<<"Now enter the ounces"<<endl;
    cin>>ounces;
}

//Function for Problem 7 Outputs
//Inputs
//    feet    ->Number of feet
//    inches  ->Number of inches
//Outputs
//    NONE
void prob7Ou(int feet,int inches){
    cout<<"The length in English Units is"<<endl;
    cout<<feet<<" feet and "<<inches<<" inches"<<endl;
}

//Length Conversion from Metric to English Units
//Inputs
//    feet   ->number of feet
//    inches ->number of inches
//    meters ->number of meters
//    centi  ->number of centimeters
//Outputs
//    NONE
void mtrs_to_ft(int meters,int centi,int& feet,int& inches){
    centi=meters*100+centi;
    inches=centi/IN2CENT;
    feet=inches/12;
    inches=inches-feet*12;
}

//Function for Problem 7 Inputs
//Inputs
//    meters ->number of meters for length
//    centi  ->number of centimeters for length
//Outputs
//    NONE
void prob7In(int& meters,int& centi){
    //Input Values
    cout<<"Enter the length in meters and centimeters:"<<endl;
    cout<<"First enter the meters"<<endl;
    cin>>meters;
    cout<<"Now enter the centimeters"<<endl;
    cin>>centi;
}

//Function for Problem 6 Outputs
//Inputs
//    meters ->Number of meters
//    centi  ->Number of centimeters
//Outputs
//    NONE
void prob6Ou(int meters,int centi){
    cout<<"The length in Metric Units is"<<endl;
    cout<<meters<<" meters and "<<centi<<" centimeters"<<endl;
}

//Length Conversion from English to Metric Units
//Inputs
//    feet   ->number of feet
//    inches ->number of inches
//    meters ->number of meters
//    centi  ->number of centimeters
//Outputs
//    NONE
void ft_to_mtrs(int feet,int inches,int& meters,int& centi){
    inches=inches+feet*12;
    centi=inches*IN2CENT;
    meters=centi/100;
    centi=centi-meters*100;
}

//Function for Problem 6 Inputs
//Inputs
//    feet    ->number of feet for length
//    inches  ->number of inches for length
//Outputs
//    NONE
void prob6In(int& feet,int& inches){
    //Input Values
    cout<<"Enter the length in feet and inches:"<<endl;
    cout<<"First enter the feet"<<endl;
    cin>>feet;
    cout<<"Now enter the inches"<<endl;
    cin>>inches;
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