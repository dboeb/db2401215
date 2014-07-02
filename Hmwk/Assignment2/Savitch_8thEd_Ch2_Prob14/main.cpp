/* Chapter 2 Problem 14
 * File:   main.cpp
 * Author: Daniel
 * Created on July 1, 2014, 4:04 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Starts Here!
int main(int argc, char** argv) {
    //Declare variables
    //Inputs, Constants, and Outputs
    const char NSIZE=25;//Includes the null terminator
    char instr[NSIZE];  //Name of instructor
    char name[NSIZE];   //Name of student
    const char FSIZE=15;//Includes the null terminator
    char food[FSIZE];   //A food name
    float number;         //A number between 100 and 120
    const char ASIZE=10;//Includes the null terminator
    char adj[ASIZE];    //An adjective
    char color[ASIZE];  //A Color
    char animal[NSIZE]; //An animal name
    
    //Input Values      
    cout<<"Enter the name of the instructor"<<endl;
    cin.getline(instr,NSIZE);
    cout<<"Enter the name of the student"<<endl;
    cin.getline(name,NSIZE);
    cout<<"Enter the name of a food"<<endl;
    cin.getline(food,FSIZE);
    cout<<"Enter a number between 100 and 120"<<endl;
    cin>>number;
    cin.ignore();
    cout<<"Enter an adjective"<<endl;
    cin.getline(adj,ASIZE);
    cout<<"Enter the name of a color"<<endl;
    cin.getline(color,ASIZE);
    cout<<"Enter the name of an animal"<<endl;
    cin.getline(animal,NSIZE);
    cout<<endl;
    cout<<endl;
   
    //Output the results
    if (number<100||number>120){
        cout<<"You have inputed an incorrect number"<<endl;
        cout<<"The number needs to be between 100 and 120"<<endl;
    }else{ 
        cout<<"Dear Instructor "<<instr<<","<<endl;
        cout<<endl;
        cout<<"I am sorry that I am unable to turn in my homework at this time, First"<<endl;
        cout<<"I ate a rotten "<<food<<", which made me turn "<<color<<" and extremely ill. I"<<endl;
        cout<<"came down with a fever of "<<number<<". Next, my "<<adj<<" pet"<<endl;
        cout<<animal<<" must have smelled the remains of the "<<food<<" on my homework,"<<endl;
        cout<<"because he ate it. I am currently rewriting my homework and hope you"<<endl;
        cout<<"will accept it late."<<endl;
        cout<<endl;
        cout<<"Sincerely,"<<endl;
        cout<<name<<endl;
    }
    
    //Exit stage right
    return 0;
}