/*Project 1: 21 
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on July 9, 2014, 2:55 PM
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Starts Here!
int main(int argc, char** argv) {
    //Declare Variables
    //Inputs and Constants
    ifstream input;   //Input from file
    char aceval;      //Input character from file
    char dum;         //Dummy character
    //Outputs
    int card1;        //Card 1 value
    int card2;        //Card 2 value
    int card3;        //Additional card value
    int totval;       //Total value of all cards
    float wins=0;     //Number of wins
    float losses=0;   //Number of losses
    ofstream output;  //Output to file
    
    //Set the Random Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Input Values
    cout<<"                     ----- 21 -----"<<endl;
    cout<<"Before playing, open the file 'Ace.txt' and clear the file,"<<endl;
    cout<<"then type in 'H' for High, 'L' for Low, or 'E' for Either to"<<endl;
    cout<<"set up the value of the Ace card. High means that an Ace has"<<endl;
    cout<<"a value of 11, low means that an Ace has a value of 1, and"<<endl;
    cout<<"either means that an Ace has a value of 1 or 11. It is recommended"<<endl;
    cout<<"to play with 'Either'."<<endl;
    cout<<endl;
    //Open the Input file
    input.open("Ace.txt");
    input>>aceval>>dum;
    
    //Begin Game Loop
    bool loop=true;
    do{
        switch(aceval){
            case 'H':
            case 'h':{
                cout<<"You started a new game and drew two cards"<<endl;
                int card1=rand()%13+1;
                int card2=rand()%13+1;
                if (card1==1){
                    cout<<"Card 1 = Ace"<<endl;
                    card1=11;
                }else if (card1==11){
                    cout<<"Card 1 = Jack"<<endl;
                    card1=10;
                }else if (card1==12){
                    cout<<"Card 1 = Queen"<<endl;
                    card1=10;
                }else if (card1==13){
                    cout<<"Card 1 = King"<<endl;
                    card1=10;
                }else{
                    cout<<"Card 1 = "<<card1<<endl;
                }
                if (card2==1){
                    cout<<"Card 2 = Ace"<<endl;
                    card2=11;
                }else if (card2==11){
                    cout<<"Card 2 = Jack"<<endl;
                    card2=10;
                }else if (card2==12){
                    cout<<"Card 2 = Queen"<<endl;
                    card2=10;
                }else if (card2==13){
                    cout<<"Card 2 = King"<<endl;
                    card2=10;
                }else{
                    cout<<"Card 2 = "<<card2<<endl;
                }
                //Calculate total value of cards
                totval=card1+card2;
                cout<<"The total value of your cards is "<<totval<<endl;
                cout<<"would you like to Hit or Stay? H/S"<<endl;
                char choice;
                cin>>choice;
                while (choice=='H'||choice=='h'&&totval<22){
                    cout<<"You draw an additional card"<<endl;
                    int card3=rand()%13+1;
                    if (card3==1){
                        cout<<"Next Card = Ace"<<endl;
                        card3=11;
                    }else if (card3==11){
                        cout<<"Next Card = Jack"<<endl;
                        card3=10;
                    }else if (card3==12){
                        cout<<"Next Card = Queen"<<endl;
                        card3=10;
                    }else if (card3==13){
                        cout<<"Next Card = King"<<endl;
                        card3=10;
                    }else{
                        cout<<"Next Card = "<<card3<<endl;
                    }
                    //Calculate total value of cards
                    totval+=card3;
                    cout<<"The total value of your cards is "<<totval<<endl;
                    if (totval<=21){
                        cout<<"would you like to Hit or Stay? H/S"<<endl;
                        cin>>choice;
                    }
                    
                }
                if (totval>21){
                    cout<<"You Busted"<<endl;
                    losses++;
                }else if(totval==21){
                    cout<<"You Win!"<<endl;
                    wins++;
                }else if(totval<21){
                    cout<<"You lose"<<endl;
                    losses++;
                }
                break;
            }
            case 'L':
            case 'l':{
                
                break;
            }
            case 'E':
            case 'e':{
                
                break;
            }
            default:{
                
                break;
            }
        }
        
        //Ask to Play Again
        cout<<"Play Again? Y/N"<<endl;
        char repeat;
        cin>>repeat;
        switch(repeat){
            case 'Y':
            case 'y':{
                break;
            }default:{
                loop=false;
                break;
            }    
        }
    }while(loop);
    
    //Calculations???
    
    
    //Output the results to file
    output.open("Ace.txt");
    output<<"Total Wins = "<<wins<<endl;
    output<<" Total Losses = "<<losses<<endl;
    cout<<"Your Total Wins and Losses were exported to 'Ace.txt' file"<<endl;
    
    //Exit Stage Right!
    input.close();
    output.close();
    return 0;
}