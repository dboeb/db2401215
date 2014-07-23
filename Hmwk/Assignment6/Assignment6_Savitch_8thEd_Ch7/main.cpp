/* Assignment 6 Savitch 8th Edition Chapter 7
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on July 22, 2014, 1:38 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

//User Defined Libraries

//Global Constants
const int COLS1=4;//Set Columns to 3 for Problem 1

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
int hex_to_10(char,int);

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
    const int ROWS=12;       //Set Number of Rows to 12 for each month
    int raArray[ROWS][COLS1];//2-d array for rainfall each month
    char choice;             //User's choice for graph or table
    //Outputs
    int month;               //Current Month Number
    int diff;                //Difference 
    
    //Input Values
    for(int row=0;row<ROWS;row++){
        for(int col=0;col<COLS1;col++){
            month=row+1;
            if (col==0){
                //Input the Month
                raArray[row][col]=month;
            }else if (col==1){
                cout<<"Enter Average Rainfall in inches for month "<<month<<endl;
                cin>>raArray[row][col];
            }else if (col==2){
                cout<<"Enter Actual Rainfall in inches for month "<<month<<endl;
                cin>>raArray[row][col];
            }else{
                //Calculate Difference in Average and Actual Rainfall
                diff=raArray[row][col-1]-raArray[row][col-2];
                raArray[row][col]=diff;
            }
        }
    }
    cout<<"Enter 'G' to view the bar graph or 'T' to view the table"<<endl;
    cin>>choice;
    
    //Output Results
    //Output Bar Graph
    if (choice=='G'||choice=='g'){
        cout<<endl;
        for(int row=0;row<ROWS;row++){
            month=row+1;
            cout<<"For Month "<<month<<endl;
            for(int col=1;col<COLS1-1;col++){
                if (col==1){
                    cout<<"    Average Rainfall ";
                }else{
                    cout<<"    Actual Rainfall  ";
                }
                int n;
                n=raArray[row][col];
                for(int count=1;count<=n;count++){
                    cout<<"*";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    //Output Table
    }else{
        cout<<endl;
        cout<<"     Month     Average    Actual    Difference"<<endl;
        cout<<"               Rainfall   Rainfall"<<endl;
        for(int row=0;row<ROWS;row++){
            for(int col=0;col<COLS1;col++){
                cout<<setw(8)<<raArray[row][col]<<"   ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    
    //Exit Stage Right
    cout<<endl<<endl;
}

//Solution to problem 2
void problem2(){
    //Declare Variables
    //Inputs
    const int ROWS=11;    //Set Number if rows to 10 for 10 digits
    char h1Array[ROWS]={};//1-d array for the first hexadecimal numerals
    char h2Array[ROWS]={};//1-d array for the second hexadecimal numerals
    //Outputs
    int h1val;            //Value of first hexadecimal numerals in base 10
    int h2val;            //Value of second hexadecimal numerals in base 10
    int sum;              //Sum of both hexadecimal numerals in base 10
    
    //Input Values
    cout<<"Enter two hexadecimal numbers to add them together"<<endl;
    cout<<"Each number must not exceed 10 numerals"<<endl;
    cout<<"Enter the first hexadecimal number"<<endl;
    cout<<"Put a '.' at the end of the number"<<endl;
    for(int row=0;row<ROWS&&h1Array[row-1]!='.';row++){
        cin>>h1Array[row];
        if (row==10&&h1Array[row]!='.'){
            cout<<"Addition Overflow"<<endl;
            cout<<"Only first 10 numerals recorded"<<endl;
            h1Array[row]='.';
        }
    }
    cout<<"Enter the second hexadecimal number"<<endl;
    cout<<"Put a '.' at the end of the number"<<endl;
    for(int row=0;row<ROWS&&h2Array[row-1]!='.';row++){
        cin>>h2Array[row];
        if (row==10&&h2Array[row]!='.'){
            cout<<"Addition Overflow"<<endl;
            cout<<"Only first 10 numerals recorded"<<endl;
            h2Array[row]='.';
        }
    }
    
    //Calculations
    //Calculate value of first number
    h1val=hex_to_10(h1Array[],ROWS);
    //Calculate value of second number
    h2val=hex_to_10(h2Array[],ROWS);
    //Calculate sum of both numbers
    sum=h1val+h2val;
    
    //Output Results
    for(int row=0;row<ROWS&&h1Array[row]!='.';row++){
        cout<<h1Array[row];
    }
    cout<<" + ";
    for(int row=0;row<ROWS&&h2Array[row]!='.';row++){
        cout<<h2Array[row];
    }
    cout<<" = "<<sum<<" in base 10"<<endl;
    
    //Exit Stage Right
    cout<<endl<<endl;
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

//Function that converts a hexadecimal number to a base 10 Number
//Inputs
//    Array  ->Array containing the hexadecimal number and '.' terminator
//    n      ->Maximum Row Size
//Outputs
//    number ->Base 10 number
int hex_to_10(char Array[], int n){
    int number=0;//Number value in base 10
    int numeVal; //Value of numeral
    for(int row=0;row<n&&Array[row]!='.';row++){
       switch(Array[row]){
            case '0':{
                numeVal=0;
                break;
            }
            case '1':{
                numeVal=1;
                break;
            }
            case '2':{
                numeVal=2;
                break;
            }
            case '3':{
                numeVal=3;
                break;
            }
            case '4':{
                numeVal=4;
                break;
            }
            case '5':{
                numeVal=5;
                break;
            }
            case '6':{
                numeVal=6;
                break;
            }
            case '7':{
                numeVal=7;
                break;
            }
            case '8':{
                numeVal=8;
                break;
            }
            case '9':{
                numeVal=9;
                break;
            }
            case 'a':{
                numeVal=10;
                break;
            }
            case 'b':{
                numeVal=11;
                break;
            }
            case 'c':{
                numeVal=12;
                break;
            }
            case 'd':{
                numeVal=13;
                break;
            }
            case 'e':{
                numeVal=14;
                break;
            }
            case 'f':{
                numeVal=15;
                break;
            }
            default:{
                cout<<"Invalid Digit Used"<<endl;
            };
        }
       number+=pow(16,row)*numeVal;
    } 
    return number;
}