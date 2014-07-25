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
const int COLS1=4;//Set Columns to 4 for Problem 1
const int COLS10=3;//Set Columns to 3 for Problem 10
const int COLS11=5;//Set Columns to 5 for Problem 11

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
float stan_dev(float[],int);
void sortArray(int[],int);
bool add_num(char[],char[],char[],int);
bool add_dig(char,char,char&,bool=false);

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
    cout<<"Type 5 for problem 6"<<endl;
    cout<<"Type 6 for problem 7"<<endl;
    cout<<"Type 7 for problem 10"<<endl;
    cout<<"Type 8 for problem 11"<<endl;
    cout<<"Type 9 for problem 12"<<endl;
    cout<<"Type 10 for problem 19"<<endl;
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
    const int ROWS=11;    //Set Number of rows to 11 for 10 digits
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
    //Declare Variables
    //Inputs
    const int ROWS=10;     //Number of rows
    float numbers[ROWS]={};//Array containing numbers
    //Outputs
    int size=0;            //Size of array
    float staDev;          //Standard deviation of the array
    
    //Input Values
    cout<<"Enter up to ten numbers to find the standard deviation"<<endl;
    cout<<"Enter -99 at the end if there are less than ten numbers"<<endl;
    for (int row=0;row<ROWS&&numbers[row-1]!=-99;row++){
        cout<<"Enter a Number"<<endl;
        cin>>numbers[row];
    }
    
    //Calculations
    //Calculate Size of Array
    for (int row=0;row<ROWS&&numbers[row-1]!=-99;row++){
        if (numbers[row]!=-99){
            size++;
        }
    }
    //Calculate Standard Deviation
    staDev=stan_dev(numbers,size);
    
    //Output Results
    cout<<"The Standard Deviation for the numbers:"<<endl;
    for (int row=0;row<ROWS&&numbers[row-1]!=-99;row++){
        if (numbers[row]!=-99){
            cout<<numbers[row]<<" ";
        }
    }
    cout<<endl;
    cout<<"Is "<<staDev<<endl;
    
    //Exit Stage Right
    cout<<endl<<endl;
}

//Solution to problem 6
void problem5(){
    //Declare Variables
    //Inputs
    const int ROWS=10;             //Number of Rows for array
    int array[ROWS]={8,6,10,2,16,4,
                     18,14,12,10}; //Array Filled with integers
    
    //Output Unsorted Array
    cout<<"Unsorted Array:"<<endl;
    for (int row=0;row<ROWS;row++){
        cout<<array[row]<<" ";
    }
    cout<<endl;
    
    //Sort Array Numbers
    sortArray(array,ROWS);
    
    //Output Sorted Array
    cout<<"Sorted Array:"<<endl;
    for (int row=0;row<ROWS;row++){
        cout<<array[row]<<" ";
    }
    cout<<endl;
    
    //Exit Stage Right
    cout<<endl<<endl;
}

//Solution to problem 7
void problem6(){
    //Declare Variables
    //Inputs
    const int ROWS=21; //Set Number of rows to 21 for 20 digits
    char int1[ROWS]={};//1-d array for the first integer
    char int2[ROWS]={};//1-d array for the second integer
    //Outputs
    int resSize;       //Size of Result
    int size1;         //Size of first number
    int size2;         //Size of second number
    
    //Input Values
    cout<<"Enter two integers to add them together"<<endl;
    cout<<"Each number must not exceed 20 digits"<<endl;
    cout<<"Enter the first number"<<endl;
    cin>>int1;
    cout<<"Enter the second number"<<endl;
    cin>>int2;
    
    //Calculations
    //Calculate length of first number
    size1=strlen(int1);
    //Calculate length of second number
    size2=strlen(int2);
    //Calculate Result Size
    if (size1>size2){
        resSize=size1+1;
    }else{
        resSize=size2+1;
    }
    char result[resSize];
    //Calculate Summation of Numbers
    bool x=add_num(int1,int2,result,resSize);
    
    //Output Results
    cout<<endl;
    cout<<setw(resSize+1)<<int1<<endl;
    cout<<"+"<<setw(resSize)<<int2<<endl;
    cout<<"-------------"<<endl;
    if(x){
        cout<<"Overflow"<<endl;
    }else{
        cout<<setw(resSize+1)<<result;
    }
    
    //Exit Stage Right
    cout<<endl<<endl;
    
}

//Solution to problem 10
void problem7(){
    //Declare Variables
    //Inputs
    const int ROWS=3;                         //Set Rows to 3
    char tictato[ROWS][COLS10]={{'1','2','3'},
                               {'4','5','6'},
                               {'7','8','9'}};//Initialize tic-tac-toe game
    char player1='X';                         //Player One symbol
    char player2='O';                         //Player Two symbol
    char play1In;                             //Player One Input
    char play2In;                             //Player One Input
    //Outputs
    int turns=0;                              //Number of turns
    char winner='0';                          //Winner of tic-tac-toe                    
    
    //Start game Loop
    cout<<"----Tic-Tac-Toe----"<<endl;
    bool loop=true;
    do{
        //Player 1's turn
        if(winner=='0'&&turns<9){
            bool input;
            do{ 
                input=false;
                //Ask Player 1 for Decision
                cout<<"Player 1 choose a position from the table below"<<endl;

                //Output Game Positions
                for(int row=0;row<ROWS;row++){
                    for(int col=0;col<COLS10;col++){
                        cout<<tictato[row][col]<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;
                cin>>play1In;

                //Input Player 1 Symbol
                if(play1In=='1'&&tictato[0][0]=='1'){
                    tictato[0][0]=player1;
                }else if(play1In=='2'&&tictato[0][1]=='2'){
                    tictato[0][1]=player1;
                }else if(play1In=='3'&&tictato[0][2]=='3'){
                    tictato[0][2]=player1;
                }else if(play1In=='4'&&tictato[1][0]=='4'){
                    tictato[1][0]=player1;
                }else if(play1In=='5'&&tictato[1][1]=='5'){
                    tictato[1][1]=player1;
                }else if(play1In=='6'&&tictato[1][2]=='6'){
                    tictato[1][2]=player1;
                }else if(play1In=='7'&&tictato[2][0]=='7'){
                    tictato[2][0]=player1;
                }else if(play1In=='8'&&tictato[2][1]=='8'){
                    tictato[2][1]=player1;
                }else if(play1In=='9'&&tictato[2][2]=='9'){
                    tictato[2][2]=player1;
                }else{
                    cout<<"Invalid input or spot already taken"<<endl;
                    input=true;
                }
            }while(input);
            
            //Add one to turn
            turns++;

            //Determine if it was winning move
            //Winning by going across
            if(tictato[0][0]==tictato[0][1]&&tictato[0][0]==tictato[0][2]||
               tictato[1][0]==tictato[1][1]&&tictato[1][0]==tictato[1][2]||
               tictato[2][0]==tictato[2][1]&&tictato[2][0]==tictato[2][2]){
                winner='1';
                loop=false;
            //Winning by going down
            }else if(tictato[0][0]==tictato[1][0]&&tictato[0][0]==tictato[2][0]||
                     tictato[0][1]==tictato[1][1]&&tictato[0][1]==tictato[2][1]||
                     tictato[0][2]==tictato[1][2]&&tictato[0][2]==tictato[2][2]){
                winner='1';
                loop=false;
            //Winning By going diagonal
            }else if(tictato[0][0]==tictato[1][1]&&tictato[0][0]==tictato[2][2]||
                     tictato[2][0]==tictato[1][1]&&tictato[2][0]==tictato[0][2]){
                winner='1';
                loop=false;
            }
        }
        
        //Player 2's turn
        if(winner=='0'&&turns<9){
            bool input;
            do{
                input=false;
                //Ask Player 2 for Decision
                cout<<"Player 2 choose a position from the table below"<<endl;

                //Output Game Positions
                for(int row=0;row<ROWS;row++){
                    for(int col=0;col<COLS10;col++){
                        cout<<tictato[row][col]<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;
                cin>>play2In;

                //Input Player 2 Symbol
                if(play2In=='1'&&tictato[0][0]=='1'){
                    tictato[0][0]=player2;
                }else if(play2In=='2'&&tictato[0][1]=='2'){
                    tictato[0][1]=player2;
                }else if(play2In=='3'&&tictato[0][2]=='3'){
                    tictato[0][2]=player2;
                }else if(play2In=='4'&&tictato[1][0]=='4'){
                    tictato[1][0]=player2;
                }else if(play2In=='5'&&tictato[1][1]=='5'){
                    tictato[1][1]=player2;
                }else if(play2In=='6'&&tictato[1][2]=='6'){
                    tictato[1][2]=player2;
                }else if(play2In=='7'&&tictato[2][0]=='7'){
                    tictato[2][0]=player2;
                }else if(play2In=='8'&&tictato[2][1]=='8'){
                    tictato[2][1]=player2;
                }else if(play2In=='9'&&tictato[2][2]=='9'){
                    tictato[2][2]=player2;
                }else{
                    cout<<"Invalid input or spot already taken"<<endl;
                    input=true;
                }
            }while(input);
            
            //Add one to turn
            turns++;

            //Determine if it was winning move
            //Winning by going across
            if(tictato[0][0]==tictato[0][1]&&tictato[0][0]==tictato[0][2]||
               tictato[1][0]==tictato[1][1]&&tictato[1][0]==tictato[1][2]||
               tictato[2][0]==tictato[2][1]&&tictato[2][0]==tictato[2][2]){
                winner='2';
                loop=false;
            //Winning by going down
            }else if(tictato[0][0]==tictato[1][0]&&tictato[0][0]==tictato[2][0]||
                     tictato[0][1]==tictato[1][1]&&tictato[0][1]==tictato[2][1]||
                     tictato[0][2]==tictato[1][2]&&tictato[0][2]==tictato[2][2]){
                winner='2';
                loop=false;
            //Winning By going diagonal
            }else if(tictato[0][0]==tictato[1][1]&&tictato[0][0]==tictato[2][2]||
                     tictato[2][0]==tictato[1][1]&&tictato[2][0]==tictato[0][2]){
                winner='2';
                loop=false;
            }
        }
        
    //End of Game Loop    
    }while(loop&&turns!=9);
    
    //Output Winner
    if (turns==9){
        cout<<"No Winner"<<endl;
    }else{
        cout<<"The Winner is Player "<<winner<<endl;
    }
    for(int row=0;row<ROWS;row++){
        for(int col=0;col<COLS10;col++){
            cout<<tictato[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    
    //Exit Stage Right
    cout<<endl<<endl;
}

//Solution to problem 11
void problem8(){
    //Declare Variables
    //Inputs
    const int ROWS=7;//Number of rows for rows of chairs
    char seat[ROWS][COLS11]={{'1','A','B','C','D'},
                             {'2','A','B','C','D'},
                             {'3','A','B','C','D'},
                             {'4','A','B','C','D'},
                             {'5','A','B','C','D'},
                             {'6','A','B','C','D'},
                             {'7','A','B','C','D'}};//Seat layout for the plane
    int rownum;      //Row for the seats
    char chair;      //Chair in the row
    char choice;     //User's choice to repeat assignment of seats
    int open=28;     //Number of open seats
    
    //Output Seating Chart
    for(int row=0;row<ROWS;row++){
        for(int col=0;col<COLS11;col++){
            cout<<seat[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    //Begin Seating Loop
    bool loop;
    do{
        loop=true;
        
        
        //Input Values
        bool input;
        do{
            input=false;
            cout<<"Choose a seat for the plane."<<endl;
            cout<<"Refer to the chart above."<<endl;
            cout<<"Enter the row number and seat letter"<<endl;
            cout<<"Taken seats are marked with an 'X'"<<endl;
            cin>>rownum>>chair;
            cout<<"Row = "<<rownum<<" Chair = "<<chair<<endl;
            
            //Determine Seat
            if (rownum==1){
                if (chair=='A'||chair=='a'&&seat[0][1]!='X'){
                    seat[0][1]='X';
                }else if (chair=='B'||chair=='b'&&seat[0][2]!='X'){
                    seat[0][2]='X';
                }else if (chair=='C'||chair=='c'&&seat[0][3]!='X'){
                    seat[0][3]='X';
                }else if (chair=='D'||chair=='d'&&seat[0][4]!='X'){
                    seat[0][4]='X';
                }else{
                    cout<<"Invalid input or seat is already taken"<<endl;
                    input=true;
                }
            }else if (rownum==2){
                if (chair=='A'||chair=='a'&&seat[1][1]!='X'){
                    seat[1][1]='X';
                }else if (chair=='B'||chair=='b'&&seat[1][2]!='X'){
                    seat[1][2]='X';
                }else if (chair=='C'||chair=='c'&&seat[1][3]!='X'){
                    seat[1][3]='X';
                }else if (chair=='D'||chair=='d'&&seat[1][4]!='X'){
                    seat[1][4]='X';
                }else{
                    cout<<"Invalid input or seat is already taken"<<endl;
                    input=true;
                }
            }else if (rownum==3){
                if (chair=='A'||chair=='a'&&seat[2][1]!='X'){
                    seat[2][1]='X';
                }else if (chair=='B'||chair=='b'&&seat[2][2]!='X'){
                    seat[2][2]='X';
                }else if (chair=='C'||chair=='c'&&seat[2][3]!='X'){
                    seat[2][3]='X';
                }else if (chair=='D'||chair=='d'&&seat[2][4]!='X'){
                    seat[2][4]='X';
                }else{
                    cout<<"Invalid input or seat is already taken"<<endl;
                    input=true;
                }
            }else if (rownum==4){
                if (chair=='A'||chair=='a'&&seat[3][1]!='X'){
                    seat[3][1]='X';
                }else if (chair=='B'||chair=='b'&&seat[3][2]!='X'){
                    seat[3][2]='X';
                }else if (chair=='C'||chair=='c'&&seat[3][3]!='X'){
                    seat[3][3]='X';
                }else if (chair=='D'||chair=='d'&&seat[3][4]!='X'){
                    seat[3][4]='X';
                }else{
                    cout<<"Invalid input or seat is already taken"<<endl;
                    input=true;
                }
            }else if (rownum==5){
                if (chair=='A'||chair=='a'&&seat[4][1]!='X'){
                    seat[4][1]='X';
                }else if (chair=='B'||chair=='b'&&seat[4][2]!='X'){
                    seat[4][2]='X';
                }else if (chair=='C'||chair=='c'&&seat[4][3]!='X'){
                    seat[4][3]='X';
                }else if (chair=='D'||chair=='d'&&seat[4][4]!='X'){
                    seat[4][4]='X';
                }else{
                    cout<<"Invalid input or seat is already taken"<<endl;
                    input=true;
                }
            }else if (rownum==6){
                if (chair=='A'||chair=='a'&&seat[5][1]!='X'){
                    seat[5][1]='X';
                }else if (chair=='B'||chair=='b'&&seat[5][2]!='X'){
                    seat[5][2]='X';
                }else if (chair=='C'||chair=='c'&&seat[5][3]!='X'){
                    seat[5][3]='X';
                }else if (chair=='D'||chair=='d'&&seat[5][4]!='X'){
                    seat[5][4]='X';
                }else{
                    cout<<"Invalid input or seat is already taken"<<endl;
                    input=true;
                }
            }else if (rownum==7){
                if (chair=='A'||chair=='a'&&seat[6][1]!='X'){
                    seat[6][1]='X';
                }else if (chair=='B'||chair=='b'&&seat[6][2]!='X'){
                    seat[6][2]='X';
                }else if (chair=='C'||chair=='c'&&seat[6][3]!='X'){
                    seat[6][3]='X';
                }else if (chair=='D'||chair=='d'&&seat[6][4]!='X'){
                    seat[6][4]='X';
                }else{
                    cout<<"Invalid input or seat is already taken"<<endl;
                    input=true;
                }
            }else{
                cout<<"Invalid input or seat is already taken"<<endl;
                input=true;
            }
        }while(input);
        
        //Calculate Open Seats
        open--;
        
        //Output Seating Chart
        for(int row=0;row<ROWS;row++){
            for(int col=0;col<COLS11;col++){
                cout<<seat[row][col]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        
        if (open<1){
            cout<<"There are no more open seats"<<endl;
            loop=false;
        }else{
            //Ask to Assign Another seat
            cout<<"Do you want to claim another seat? Y/N"<<endl;
            cin>>choice;
            if (choice=='Y'||choice=='y'){
                loop=true;
            }else{
                loop=false;
            }
        }
        
    }while(loop);
    
    //Exit Stage Right
    cout<<endl<<endl;
}

//Solution to problem 12
void problem9(){
    //Declare Variables
    //Inputs
    const int ROWS=10;         //Number of rows
    char graph[ROWS][COLS1]={};//Array containing graph
    int item1;                 //First item being graphed
    int item2;                 //Second item being graphed
    int item3;                 //Third item being graphed
    int item4;                 //Fourth item being graphed
    //Outputs
    int bignum;                //Biggest number between the four numbers
    int size1;                 //Size of the first number on the graph
    int size2;                 //Size of the second number on the graph
    int size3;                 //Size of the third number on the graph
    int size4;                 //Size of the fourth number on the graph
    float starVal;             //Value of the asterisk on graph
    
    //Input Values
    cout<<"Enter four positive integers to graph"<<endl;
    cout<<"Enter first Number"<<endl;
    cin>>item1;
    cout<<"Enter second Number"<<endl;
    cin>>item2;
    cout<<"Enter third Number"<<endl;
    cin>>item3;
    cout<<"Enter fourth Number"<<endl;
    cin>>item4;
    
    //Calculations
    //Determine largest number
    if (item1>=item2&&item1>=item3&&item1>=item4){
        bignum=item1;
    }else if (item2>=item1&&item2>=item3&&item2>=item4){
        bignum=item2;
    }else if (item3>=item1&&item3>=item2&&item3>=item4){
        bignum=item3;
    }else{
        bignum=item4;
    }
    //Determine sizes of bars
    size1=item1*10/bignum;
    size2=item2*10/bignum;
    size3=item3*10/bignum;
    size4=item4*10/bignum;
    cout<<size1<<" "<<size2<<" "<<size3<<" "<<size4<<endl;
    //Fill Array with graph
    //Fill Bar 1
    for(int row=9;row>=ROWS-size1;row--){
        graph[row][0]='*';
    }
    //Fill Bar 2
    for(int row=9;row>=ROWS-size2;row--){
        graph[row][1]='*';
    }
    //Fill Bar 3
    for(int row=9;row>=ROWS-size3;row--){
        graph[row][2]='*';
    }
    //Fill Bar 4
    for(int row=9;row>=ROWS-size4;row--){
        graph[row][3]='*';
    }
    //Calculate Value of asterisk
    starVal=static_cast<float>(bignum)/10;
    
    //Output Results
    cout<<endl;
    cout<<right;
    cout<<" * = "<<starVal<<" (approx.)"<<endl;
    for(int row=0;row<ROWS;row++){
            for(int col=0;col<COLS1;col++){
                if (graph[row][col]=='*'){
                    cout<<setw(3)<<graph[row][col]<<"       ";
                }else{
                    cout<<setw(3)<<graph[row][col]<<"        ";
                }  
            }
            cout<<endl;
        }
        cout<<"Item 1    Item 2    Item 3    Item 4"<<endl;
        cout<<left;
        cout<<" "<<setw(10)<<item1<<setw(10)<<item2<<setw(10)<<item3<<setw(10)<<item4<<endl;
    
    //Exit Stage Right
    cout<<endl<<endl;
}

//Solution to problem 19
void problem10(){
    //Declare Variables
    const int ROWS=10;  //Number of rows
    char pin[ROWS]={};   //User's Pin Number
    char num[ROWS]={};   //Random Numbers between 1 and 3
    char input[ROWS]={}; //User's input for pin
    char actual[ROWS]={};//What the user should have inputted
    char choice;         //User's choice to repeat or not
    //Outputs
    
    //Set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Input Values
    cout<<"Input your new 'secret' pin number"<<endl;
    cout<<"Your pin must be less than 10 characters"<<endl;
    cin>>pin;
    
    bool loop;
    do{
        loop=true;
        //Fill Array with random numbers
        for(int row=0;row<ROWS;row++){
            int number;//Random number value
            number=(rand()%3+1);
            if (number==1){
                num[row]='1';
            }else if (number==2){
                num[row]='2';
            }else{
                num[row]='3';
            }       
        }
        cout<<"Now enter your pin by entering the numbers"<<endl;
        cout<<"that correspond to your pin number"<<endl;
        cout<<"PIN: 0 1 2 3 4 5 6 7 8 9"<<endl;
        cout<<"NUM: ";
        for(int row=0;row<ROWS;row++){
            cout<<num[row]<<" ";
        }
        cout<<endl;
        cin>>input;
        cout<<endl;
        
        //Determine What the User should have inputted
        for(int row=0;row<ROWS;row++){
            if (pin[row]=='0'){
                actual[row]=num[0];
            }else if (pin[row]=='1'){
                actual[row]=num[1];
            }else if (pin[row]=='2'){
                actual[row]=num[2];
            }else if (pin[row]=='3'){
                actual[row]=num[3];
            }else if (pin[row]=='4'){
                actual[row]=num[4];
            }else if (pin[row]=='5'){
                actual[row]=num[5];
            }else if (pin[row]=='6'){
                actual[row]=num[6];
            }else if (pin[row]=='7'){
                actual[row]=num[7];
            }else if (pin[row]=='8'){
                actual[row]=num[8];
            }else if (pin[row]=='9'){
                actual[row]=num[9];
            }else if (pin[row]=='\0'){
                actual[row]='\0';
            }else{
                cout<<"Logic Error"<<endl;
            }
        }
        //Check input with actual pin number
        if (!strcmp(actual,input)){
            cout<<"Access Granted"<<endl;
            cout<<"You have entered the correct number"<<endl;
        }else{
            cout<<"Access Denied"<<endl;
            cout<<"You have entered the incorrect number"<<endl;
            cout<<"You should have entered:"<<endl;
            cout<<actual<<endl;
        }
        
        //Ask to do it again
        cout<<"Would you like to try to gain access again? Y/N"<<endl;
        cin>>choice;
        if(choice=='n'||choice=='n'){
            loop=false;
        }           
    }while(loop);
                
    //Exit Stage Right
    cout<<endl<<endl;
}

//Exit Comment
void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

//Function that adds integers and the previous remainder
//Inputs
//    n1   ->Array containing a digit for the first hexadecimal number
//    n2   ->Array containing a digit for the second hexadecimal number
//    d    ->Digit for the result
//    c    ->digit addition result (0 or 1)
//Outputs
//    Digit for Resulting Number
bool add_dig(char n1,char n2,char& d,bool c){
    //Determine Values of Integers
    int i1=n1-48;
    int i2=n2-48;
    
    //Add Integers Together
    int sum=i1+i2+c;
    d=sum%10+48;

    //Return Result from addition
    return sum/10;
}

//Function that returns the remainder for the addition of two integers
//Inputs
//    num1   ->Array containing the first number
//    num2   ->Array containing the second number
//    size   ->Size of answer
//Outputs
//    c      ->Digit addition result remainder (0 or 1)
bool add_num(char num1[],char num2[],char result[],int size){
    //Initialize Result Array
    result[size-1]='\0';
    for(int i=0;i<=size-2;i++){
        result[i]='0';
    }
    //Start Counters
    int reCou=size-2;
    int n1Cou=strlen(num1)-1;
    int n2Cou=strlen(num2)-1;
    //Added to the first digit
    bool c=add_dig(num1[n1Cou--],num2[n2Cou--],result[reCou--]);
    do{
        if (n1Cou<0&&n2Cou<0){
            return c;
        }else if (n1Cou<0){
            c=add_dig('0',num2[n2Cou--],result[reCou--],c);
        }else if (n2Cou<0){
            c=add_dig(num1[n1Cou--],'0',result[reCou--],c);
        }else{
            c=add_dig(num1[n1Cou--],num2[n2Cou--],result[reCou--],c);
        }
    }while(true);
}

//Function that sorts an array
//Inputs
//    array  ->Array containing characters
//    size   ->Size of array
//Outputs
//    NONE
void sortArray(int array[],int size){
    bool swap;//Swap for integers
    int temp; //Temporary placement
    
    //Sort The Array
    do{
        swap=false;
        for(int count=0;count<(size-1);count++){
            if(array[count]>array[count+1]){
                temp=array[count];
                array[count]=array[count+1];
                array[count+1]=temp;
                swap=true;
            }
        }
    }while(swap);
}

//Function that calculates standard deviation
//Inputs
//    array  ->Array containing characters
//    size   ->Size of array being used
//Outputs
//    standard deviation
float stan_dev(float array[],int size){
    //Calculate average
    float ave;//Average
    int sum=0;//Initialize sum as zero
    for (int row=0;row<size;row++){
        sum+=array[row];
    }
    ave=sum/size;
    
    //Calculate Numerator for Standard Deviation
    float num=0;//Numerator
    for (int row=0;row<size;row++){
        num+=(array[row]-ave)*(array[row]-ave);
    }
    //Return Standard Deviation
    return sqrt(num/size);
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