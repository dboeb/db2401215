/* Assignment 4 Savitch 8th Ed Chapter 4
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on July 9, 2014, 9:59 AM
 */

//System Library
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Defined Libraries

//Global Constants
const float GLPERLT=2.64179e-1;//Number of gallons per liter for conversion
const float GRACONS=6.673e-8;  //Universal Gravitational Constant in cm^3/(g*sec^2)

//Function Prototypes
float miles_per_gallon(float miles, float gallons){
    return(miles/gallons);
}
float stock_value(unsigned short wholeD, unsigned short frDnum, unsigned short frDden){
    float value;
    value=wholeD+static_cast<float>(frDnum)/frDden;
    return(value);
}
float rate_of_inflation(float priceO, float priceN){
    float infRate;
    infRate=(priceN-priceO)/priceO*100;
    return(infRate);
}
float future_cost(float priceO, float infRate){
    float costF;
    costF=priceO*(1+infRate/100);
    return(costF);
}
float credit_card_interest_due(float intrate, float account, unsigned short months){
    float intdue;
    float baldue=account;
    int n=0;
    do{
        intdue=baldue*intrate/100;
        baldue+=intdue;
        n++;
    }while(n<months);
    return(intdue);
}
float gravitational_attractive_force(float mass1, float mass2, float dist){
    float atForce;
    atForce=GRACONS*mass1*mass2/(dist*dist);
    return(atForce);
}

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //General Menu Format
    bool loop=true;
    do{
        //Display the selection
        cout<<"Type 1 to solve problem 1"<<endl;
        cout<<"Type 2 to solve problem 2"<<endl;
        cout<<"Type 3 to solve problem 3"<<endl;
        cout<<"Type 4 to solve problem 4"<<endl;
        cout<<"Type 5 to solve problem 5"<<endl;
        cout<<"Type 6 to solve problem 6"<<endl;
        cout<<"Type 7 to solve problem 7"<<endl;
        cout<<"Type 8 to solve problem 8"<<endl;
        cout<<"Type 9 to solve problem 9"<<endl;
        cout<<"Type 0 to solve problem 10"<<endl;
        cout<<"Type anything else to quit with no solutions."<<endl;
        //Read the choice
        char choice;
        cin>>choice;
        //Solve a problem that has been chosen.
        switch(choice){
                case '1':{//Problem 1 Miles per Gallon
                    bool loop1=true;
                    do{
                        //Declare Variables
                        //Inputs
                        float liter;  //Liters of gasoline consumed by user's car
                        float miles;  //Number of miles traveled by the car
                        //Outputs
                        float gallon;//Gallons of gasoline consumed by user's car
                        float mpg;    //Miles per gallon the car delivered
                    
                        //Input Values
                        cout<<"Enter the liters of gasoline consumed by the car"<<endl;
                        cin>>liter;
                        cout<<"Enter the miles traveled by the car"<<endl;
                        cin>>miles;
                        
                        //Calculations
                        //Calculate gallons
                        gallon=liter*GLPERLT;
                        //Calculate Miles per gallon
                        mpg=miles_per_gallon(miles,gallon);
                        
                        //Output Results
                        cout<<fixed<<showpoint<<setprecision(1);
                        cout<<"Miles per Gallon = "<<mpg<<" mpg"<<endl;
                        
                        //Ask to repeat Problem
                        cout<<"Repeat Problem? Y/N"<<endl;
                        char repeat;
                        cin>>repeat;
                        switch(repeat){
                            case 'Y':
                            case 'y':{
                                break;
                            }default:{
                                loop1=false;
                                break;
                            }    
                        }
                    }while(loop1);
                    //Exit Stage Right!
                    break;
                }
                case '2':{//Problem 2 Miles per Gallon for Two Cars
                    bool loop1=true;
                    do{
                        //Declare Variables
                        //Inputs
                        float liter1;  //Liters of gasoline consumed by user's car 1
                        float miles1;  //Number of miles traveled by the car 1
                        float liter2;  //Liters of gasoline consumed by user's car 2
                        float miles2;  //Number of miles traveled by the car 2
                        //Outputs
                        float gallon1;//Gallons of gasoline consumed by user's car 1
                        float mpg1;    //Miles per gallon car 1 delivered
                        float gallon2;//Gallons of gasoline consumed by user's car 2
                        float mpg2;    //Miles per gallon car 2 delivered
                    
                        //Input Values
                        cout<<"Enter the liters of gasoline consumed by the first car"<<endl;
                        cin>>liter1;
                        cout<<"Enter the miles traveled by the first car"<<endl;
                        cin>>miles1;
                        cout<<"Enter the liters of gasoline consumed by the second car"<<endl;
                        cin>>liter2;
                        cout<<"Enter the miles traveled by the second car"<<endl;
                        cin>>miles2;
                        
                        //Calculations
                        //Calculate gallons
                        gallon1=liter1*GLPERLT;
                        gallon2=liter2*GLPERLT;
                        //Calculate Miles per gallon
                        mpg1=miles_per_gallon(miles1,gallon1);
                        mpg2=miles_per_gallon(miles2,gallon2);
                        
                        //Output Results
                        cout<<fixed<<showpoint<<setprecision(1)<<endl;
                        cout<<"Miles per Gallon for the first car = "<<mpg1<<" mpg"<<endl;
                        cout<<"Miles per Gallon for the second car = "<<mpg2<<" mpg"<<endl;
                        if (mpg1>mpg2){
                            cout<<"The first car has the best fuel efficiency"<<endl;
                        }else if (mpg1<mpg2){
                            cout<<"The second car has the best fuel efficiency"<<endl;
                        }else{
                            cout<<"Both cars have the same fuel efficiency"<<endl;
                        }
                        
                        //Ask to repeat Problem
                        cout<<"Repeat Problem? Y/N"<<endl;
                        char repeat;
                        cin>>repeat;
                        switch(repeat){
                            case 'Y':
                            case 'y':{
                                break;
                            }default:{
                                loop1=false;
                                break;
                            }    
                        }
                    }while(loop1);
                    //Exit Stage Right!
                    break;
                }
                case '3':{//Problem 3 Stock Value
                    bool loop1=true;
                    do{
                        //Declare Variables
                        //Inputs
                        unsigned short shares;//Number of shares of stock owned
                        unsigned short wholeD;//Whole-dollar portion of the price
                        unsigned short frDnum;//Fraction-dollar numerator portion of the price
                        unsigned short frDden;//Fraction-dollar denominator portion of the price
                        //Outputs
                        float totval;         //Value of the user's holdings in dollars
                    
                        //Input Values
                        cout<<"Enter the number of shares of stock owned"<<endl;
                        cin>>shares;
                        cout<<"Enter the whole-dollar portion of the price"<<endl;
                        cin>>wholeD;
                        cout<<"Enter the fraction-dollar numerator portion of the price"<<endl;
                        cin>>frDnum;
                        cout<<"Enter the fraction-dollar denominator portion of the price"<<endl;
                        cin>>frDden;
                        
                        //Calculations
                        //Calculate sum of all shares
                        totval=shares*stock_value(wholeD,frDnum,frDden);
                        
                        //Output Results
                        cout<<fixed<<showpoint<<setprecision(2);
                        cout<<"Total value of holdings = $"<<totval<<endl;
                        
                        //Ask to repeat Problem
                        cout<<"Repeat Problem? Y/N"<<endl;
                        char repeat;
                        cin>>repeat;
                        switch(repeat){
                            case 'Y':
                            case 'y':{
                                break;
                            }default:{
                                loop1=false;
                                break;
                            }    
                        }
                    }while(loop1);
                    //Exit Stage Right!
                    break;
                }
                case '4':{//Problem 4 Rate of Inflation
                    bool loop1=true;
                    do{
                        //Declare Variables
                        //Inputs
                        float priceO;//Price of an item in dollars one year ago
                        float priceN;//Price of an item in dollars today
                        //Outputs
                        float inflat;//Inflation rate for the year in percent
                    
                        //Input Values
                        cout<<"Enter the value of an item one year ago in dollars"<<endl;
                        cin>>priceO;
                        cout<<"Enter the value of that item today in dollars"<<endl;
                        cin>>priceN;
                        
                        //Calculations
                        //Calculate the inflation rate
                        inflat=rate_of_inflation(priceO,priceN);
                        
                        //Output Results
                        cout<<fixed<<showpoint<<setprecision(1);
                        cout<<"Inflation Rate for this year = "<<inflat<<"%"<<endl;
                        
                        //Ask to repeat Problem
                        cout<<"Repeat Problem? Y/N"<<endl;
                        char repeat;
                        cin>>repeat;
                        switch(repeat){
                            case 'Y':
                            case 'y':{
                                break;
                            }default:{
                                loop1=false;
                                break;
                            }    
                        }
                    }while(loop1);
                    //Exit Stage Right!
                    break;
                }
                case '5':{//Problem 5 Future Price
                    bool loop1=true;
                    do{
                        //Declare Variables
                        //Inputs
                        float priceO; //Price of an item in dollars one year ago
                        float priceN; //Price of an item in dollars today
                        //Outputs
                        float inflat; //Inflation rate for the year in percent
                        float priceF1;//Future price of an item in dollars one year from now
                        float priceF2;//Future price of an item in dollars two years from now
                        
                        //Input Values
                        cout<<"Enter the value of an item one year ago in dollars"<<endl;
                        cin>>priceO;
                        cout<<"Enter the value of that item today in dollars"<<endl;
                        cin>>priceN;
                        
                        //Calculations
                        //Calculate the inflation rate
                        inflat=rate_of_inflation(priceO,priceN);
                        priceF1=future_cost(priceN,inflat);
                        priceF2=future_cost(priceF1,inflat);
                        
                        //Output Results
                        cout<<fixed<<showpoint<<setprecision(1);
                        cout<<"Inflation Rate for this year = "<<inflat<<"%"<<endl;
                        cout<<setprecision(2);
                        cout<<"Cost of item one year from now =  $"<<priceF1<<endl;
                        cout<<"Cost of item two years from now = $"<<priceF2<<endl;
                        
                        //Ask to repeat Problem
                        cout<<"Repeat Problem? Y/N"<<endl;
                        char repeat;
                        cin>>repeat;
                        switch(repeat){
                            case 'Y':
                            case 'y':{
                                break;
                            }default:{
                                loop1=false;
                                break;
                            }    
                        }
                    }while(loop1);
                    //Exit Stage Right!
                    break;
                }
                case '6':{//Problem 6 Credit Card Interest
                    bool loop1=true;
                    do{
                        //Declare Variables
                        //Inputs
                        float intrate;        //Monthly interest rate in percent
                        float account;        //Initial account balance in dollars
                        unsigned short months;//Number of months for which interest must be paid
                        //Outputs
                        float inter;          //Interest due in dollars
                    
                        //Input Values
                        cout<<"Enter the monthly interest rate of the credit card in percent"<<endl;
                        cin>>intrate;
                        cout<<"Enter the initial account balance in dollars"<<endl;
                        cin>>account;
                        cout<<"Enter the number of months for which the interest must be paid"<<endl;
                        cin>>months;
                        
                        //Calculations
                        //Calculate the interest due
                        inter=credit_card_interest_due(intrate,account,months);
                        
                        //Output Results
                        cout<<fixed<<showpoint<<setprecision(2);
                        cout<<"Interest Due = $"<<inter<<endl;
                        
                        //Ask to repeat Problem
                        cout<<"Repeat Problem? Y/N"<<endl;
                        char repeat;
                        cin>>repeat;
                        switch(repeat){
                            case 'Y':
                            case 'y':{
                                break;
                            }default:{
                                loop1=false;
                                break;
                            }    
                        }
                    }while(loop1);
                    //Exit Stage Right!
                    break;
                }
                case '7':{//Problem 7 Gravitational Force
                    bool loop1=true;
                    do{
                        //Declare Variables
                        //Inputs
                        float mass1;//mass one in grams
                        float mass2;//mass two in grams
                        float dist; //distance between masses in centimeters
                        //Outputs
                        float force;//force in dynes [g*cm/sec^2]
                    
                        //Input Values
                        cout<<"Enter the mass of body one in grams"<<endl;
                        cin>>mass1;
                        cout<<"Enter the mass of body two in grams"<<endl;
                        cin>>mass2;
                        cout<<"Enter the distance between the bodies in centimeters"<<endl;
                        cin>>dist;
                        
                        //Calculations
                        //Calculate the gravitational force
                        force=gravitational_attractive_force(mass1,mass2,dist);
                        
                        //Output Results
                        cout<<"Gravitational Force = "<<force<<" dynes [g*cm/sec^2]"<<endl;
                        
                        //Ask to repeat Problem
                        cout<<"Repeat Problem? Y/N"<<endl;
                        char repeat;
                        cin>>repeat;
                        switch(repeat){
                            case 'Y':
                            case 'y':{
                                break;
                            }default:{
                                loop1=false;
                                break;
                            }    
                        }
                    }while(loop1);
                    //Exit Stage Right!
                    break;
                }
                case '8':{//Problem 8 Cost of House
                    bool loop1=true;
                    do{
                        //Declare Variables
                        //Inputs
                        float cost;   //Cost of House in dollars
                        float downPay;//Down payment in dollars
                        //Outputs
                        float princip;//Principle in dollars
                        float inter;  //Interest in dollars
                        float aftTaxC;//Annual after-tax cost of a new house in dollars
                    
                        //Input Values
                        cout<<"Enter the cost of the house in dollars"<<endl;
                        cin>>cost;
                        cout<<"Enter the down payment in dollars"<<endl;
                        cin>>downPay;
                        
                        //Calculations
                        //Calculate the principle
                        princip=3e-2*(cost-downPay);
                        //Calculate the interest
                        inter=6e-2*(cost-downPay);
                        //Calculate annual after-tax cost
                        aftTaxC=princip+inter*(1-3.5e-1);
                        
                        //Output Results
                        cout<<"Annual after-tax cost of a new"<<endl;
                        cout<<"house for first year of ownership"<<endl;
                        cout<<" = $"<<aftTaxC<<endl;
                        
                        //Ask to repeat Problem
                        cout<<"Repeat Problem? Y/N"<<endl;
                        char repeat;
                        cin>>repeat;
                        switch(repeat){
                            case 'Y':
                            case 'y':{
                                break;
                            }default:{
                                loop1=false;
                                break;
                            }    
                        }
                    }while(loop1);
                    //Exit Stage Right!
                    break;
                }
                case '9':{//Problem 9 Clothing Size
                    bool loop1=true;
                    do{
                        //Declare Variables
                        //Inputs
                        int height;//Height in inches
                        int weight;//Weight in pounds
                        int age;   //Age in Years
                        //Outputs
                        int hat;   //Hat size
                        int jacket;//Jacket size, chest size in inches
                        int waist; //Waist size in inches
                    
                        //Input Values
                        cout<<"Enter your height in inches"<<endl;
                        cin>>height;
                        cout<<"Enter your weight in pounds"<<endl;
                        cin>>weight;
                        cout<<"Enter your age in years"<<endl;
                        cin>>age;
                        
                        //Calculations
                        //Calculate the hat size
                        hat=(static_cast<float>(weight)/height)*2.9e0;
                        //Calculate the jacket size
                        jacket=height*weight/2.88e2f;
                        if (age>30){
                            jacket+=1e0f/8*((age-30)/10);
                        }
                        //Calculate the waist size
                        waist=weight/5.7e0f;
                        if (age>28){
                            waist+=1e0f/10*((age-28)/2);
                        }
                        
                        //Output Results
                        cout<<"Hat size = "<<hat<<endl;
                        cout<<"Jacket Size = "<<jacket<<" in"<<endl;
                        cout<<"Waist Size = "<<waist<<" in"<<endl;
                        
                        //Ask to repeat Problem
                        cout<<"Repeat Problem? Y/N"<<endl;
                        char repeat;
                        cin>>repeat;
                        switch(repeat){
                            case 'Y':
                            case 'y':{
                                break;
                            }default:{
                                loop1=false;
                                break;
                            }    
                        }
                    }while(loop1);
                    //Exit Stage Right!
                    break;
                }
                case '0':{//Problem 10 Clothing Size After 10 Years
                    bool loop1=true;
                    do{
                        //Declare Variables
                        //Inputs
                        int height;   //Height in inches
                        int weight;   //Weight in pounds
                        int age;      //Age in Years
                        //Outputs
                        int ageold;   //Age after 10 years 
                        float hat;    //Hat size
                        float jacket; //Jacket size, chest size in inches
                        float waist;  //Waist size in inches
                        float jacketO;//Jacket size after 10 years
                        float waistO; //Waist size after 10 years
                    
                        //Input Values
                        cout<<"Enter your height in inches"<<endl;
                        cin>>height;
                        cout<<"Enter your weight in pounds"<<endl;
                        cin>>weight;
                        cout<<"Enter your age in years"<<endl;
                        cin>>age;
                        
                        //Calculations
                        //Calculate the hat size
                        hat=(static_cast<float>(weight)/height)*2.9e0;
                        //Calculate the jacket size
                        jacket=height*weight/2.88e2f;
                        if (age>30){
                            jacket+=1e0f/8*((age-30)/10);
                        }
                        //Calculate the waist size
                        waist=weight/5.7e0f;
                        if (age>28){
                            waist+=1e0f/10*((age-28)/2);
                        }
                        //Calculate age after 10 years
                        ageold=age+1.0e1;
                        //Calculate the jacket size after 10 years
                        jacketO=height*weight/2.88e2f;
                        if (ageold>30){
                            jacketO+=1e0f/8*((ageold-30)/10);
                        } 
                        //Calculate the waist size after 10 years
                        waistO=weight/5.7e0f;
                        if (ageold>28){
                            waistO+=1e0f/10*((ageold-28)/2);
                        }
                        
                        //Output Results
                        cout<<fixed<<setprecision(0);//Rounds to nearest integer
                        cout<<"Hat size = "<<hat<<endl;
                        cout<<"Jacket Size = "<<jacket<<" in"<<endl;
                        cout<<"Waist Size = "<<waist<<" in"<<endl;
                        cout<<"In 10 years your sizes will be:"<<endl;
                        cout<<"Hat size = "<<hat<<endl;
                        cout<<"Jacket Size = "<<jacketO<<" in"<<endl;
                        cout<<"Waist Size = "<<waistO<<" in"<<endl;
                        
                        //Ask to repeat Problem
                        cout<<"Repeat Problem? Y/N"<<endl;
                        char repeat;
                        cin>>repeat;
                        switch(repeat){
                            case 'Y':
                            case 'y':{
                                break;
                            }default:{
                                loop1=false;
                                break;
                            }    
                        }
                    }while(loop1);
                    //Exit Stage Right!
                    break;
                }
                default:{
                        cout<<"Exit?"<<endl;
                        loop=false;
                        break;
                }
        };
    }while(loop);//Upper do-while
    //Exit Stage Right!
    return 0;
}

