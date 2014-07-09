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
const float GLPERLT=0.264179;//Number of gallons per liter for conversion

//Function Prototypes
float miles_per_gallon(float miles, float gallons)
{
    return(miles/gallons);
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
                    bool loop2=true;
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
                                loop2=false;
                                break;
                            }    
                        }
                    }while(loop2);
                    //Exit Stage Right!
                    break;
                }
                case '3':{//Problem 3 Stock Value
                    bool loop3=true;
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
                                loop3=false;
                                break;
                            }    
                        }
                    }while(loop3);
                    //Exit Stage Right!
                    break;
                }
                case '4':{
                    int sum=0,num=1;
                    do{
                        sum+=num++;
                    }while(num<=10);
                    cout<<endl;
                    cout<<"Solution to 3 Do-While-loop, sum(1->10)="<<sum<<endl;
                    cout<<endl;
                    break;
                }
                case '5':{
                    int sum=0,num=1;
                    do{
                        sum+=num++;
                    }while(num<=10);
                    cout<<endl;
                    cout<<"Solution to 3 Do-While-loop, sum(1->10)="<<sum<<endl;
                    cout<<endl;
                    break;
                }
                case '6':{
                    int sum=0,num=1;
                    do{
                        sum+=num++;
                    }while(num<=10);
                    cout<<endl;
                    cout<<"Solution to 3 Do-While-loop, sum(1->10)="<<sum<<endl;
                    cout<<endl;
                    break;
                }
                case '7':{
                    int sum=0,num=1;
                    do{
                        sum+=num++;
                    }while(num<=10);
                    cout<<endl;
                    cout<<"Solution to 3 Do-While-loop, sum(1->10)="<<sum<<endl;
                    cout<<endl;
                    break;
                }
                case '8':{
                    int sum=0,num=1;
                    do{
                        sum+=num++;
                    }while(num<=10);
                    cout<<endl;
                    cout<<"Solution to 3 Do-While-loop, sum(1->10)="<<sum<<endl;
                    cout<<endl;
                    break;
                }
                case '9':{
                    int sum=0,num=1;
                    do{
                        sum+=num++;
                    }while(num<=10);
                    cout<<endl;
                    cout<<"Solution to 3 Do-While-loop, sum(1->10)="<<sum<<endl;
                    cout<<endl;
                    break;
                }
                case '0':{
                    int sum=0,num=1;
                    do{
                        sum+=num++;
                    }while(num<=10);
                    cout<<endl;
                    cout<<"Solution to 3 Do-While-loop, sum(1->10)="<<sum<<endl;
                    cout<<endl;
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

