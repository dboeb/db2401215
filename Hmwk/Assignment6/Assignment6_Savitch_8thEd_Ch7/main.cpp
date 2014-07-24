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
bool add_hex_dig(char,char,char&,bool=false);
bool add_hex_num(char[],char[],char[],int);
void delete_repeats(char[],int);
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
    int resSize;          //Size of Result
    int h1size;           //Size of first number
    int h2size;           //Size of second number
    
    //Input Values
    cout<<"Enter two hexadecimal numbers to add them together"<<endl;
    cout<<"Each number must not exceed 10 numerals"<<endl;
    cout<<"Enter the first hexadecimal number"<<endl;
    cin>>h1Array;
    cout<<"Enter the second hexadecimal number"<<endl;
    cin>>h2Array;
    
    //Calculations
    //Calculate length of first number
    h1size=strlen(h1Array);
    //Calculate length of second number
    h2size=strlen(h2Array);
    //Calculate Result Size
    if (h1size>h2size){
        resSize=h1size+1;
    }else{
        resSize=h2size+1;
    }
    char result[resSize];
    //Calculate Summation of Numbers
    bool x=add_hex_num(h1Array,h2Array,result,resSize);
    
    //Output Results
    cout<<endl;
    cout<<setw(resSize+1)<<h1Array<<endl;
    cout<<"+"<<setw(resSize)<<h2Array<<endl;
    cout<<"-------------"<<endl;
    if(x){
        cout<<"Overflow"<<endl;
    }else{
        cout<<setw(resSize+1)<<result;
    }
    
    //Exit Stage Right
    cout<<endl<<endl;
}

//Solution to problem 3
void problem3(){
    //Declare Variables
    //Inputs
    const int ROWS=11;  //Number of Rows
    char array[ROWS]={};//Array Containing Random Characters
    //Outputs
    int size;           //Size of the Array (Number of spaces being used)
    
    //Input Values
    cout<<"Enter up to 10 random characters with some that repeat"<<endl;
    cin>>array;
    
    //Calculate Size of Array Before
    size=strlen(array);
    cout<<"Your number of characters = "<<size<<endl;
    //Delete Repeats
    delete_repeats(array,size);
    //Calculate Size of Array After
    size=strlen(array);
    
    //Output Results
    cout<<"After deleting repeating characters,"<<endl;
    cout<<"Your characters are:"<<endl;
    for (int row=0;row<ROWS;row++){
        cout<<array[row];
    }
    cout<<endl;
    cout<<"Making it only "<<size<<" characters"<<endl;
    
    //Exit Stage Right
    cout<<endl<<endl;
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

//Function that deletes repeating characters
//Inputs
//    array  ->Array containing characters
//    size   ->Size of array being used
//Outputs
//    NONE
void delete_repeats(char array [],int size){
    int scan;         //Scan for characters
    int charLoc;      //Character Location
    char charact;     //Character Being compared to
    
    //Find Repeats
    for (scan=0;scan<size;scan++){
        charLoc=scan;
        charact=array[scan];
        for(int locat=scan+1;locat<size;locat++){
            if (array[locat]==charact){
                for(int spot=locat;spot<size;spot++){
                    array[spot]=array[spot+1];
                }               
            }
        }
    }
}

//Function that adds hexadecimal numbers and the previous remainder
//Inputs
//    h1   ->Array containing a digit for the first hexadecimal number
//    h2   ->Array containing a digit for the second hexadecimal number
//    d    ->Digit for the result
//    c    ->Hex digit addition result (0 or 1)
//Outputs
//    Digit for Resulting Number
bool add_hex_dig(char h1,char h2,char& d,bool c){
    //Determine Values of Integers
    int i1=h1-48;
    int i2=h2-48;
    if (h1>=65){
        i1=h1-55;
    }
    if (h2>=65){
        i2=h2-55;
    }
    //Add Integers Together
    int sum=i1+i2+c;
    if(sum%16>9){
        d=sum%16+55;
    }else{
        d=sum%16+48;
    }
    //Return Result from addition
    return sum/16;
}

//Function that returns the remainder for the addition of hexadecimal numbers
//Inputs
//    h1   ->Array containing the first hexadecimal number
//    h2   ->Array containing the second hexadecimal number
//    size ->Size of answer
//Outputs
//    c    ->Hex digit addition result remainder (0 or 1)
bool add_hex_num(char h1 [],char h2 [],char re [],int size){
    //Initialize Result Array
    re[size-1]='\0';
    for(int i=0;i<=size-2;i++){
        re[i]='0';
    }
    //Start Counters
    int reCou=size-2;
    int h1Cou=strlen(h1)-1;
    int h2Cou=strlen(h2)-1;
    //Added to the first digit
    bool c=add_hex_dig(h1[h1Cou--],h2[h2Cou--],re[reCou--]);
    do{
        if (h1Cou<0&&h2Cou<0){
            return c;
        }else if (h1Cou<0){
            c=add_hex_dig('0',h2[h2Cou--],re[reCou--],c);
        }else if (h2Cou<0){
            c=add_hex_dig(h1[h1Cou--],'0',re[reCou--],c);
        }else{
            c=add_hex_dig(h1[h1Cou--],h2[h2Cou--],re[reCou--],c);
        }
    }while(true);
}