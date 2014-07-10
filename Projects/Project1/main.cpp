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
    int dcard1;       //Dealer's Card 1 value
    int dcard2;       //Dealer's Card 2 value
    int dcard3;       //Dealer's additional card value
    int dtotval;      //Dealer's total value of all cards
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
                cout<<"You started a new game and was dealt two cards"<<endl;
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
                cout<<"The Dealer now deals him/herself two cards"<<endl;
                int dcard1=rand()%13+1;
                int dcard2=rand()%13+1;
                if (dcard1==1){
                    cout<<"Dealer's Card 1 = Ace"<<endl;
                    dcard1=11;
                }else if (dcard1==11){
                    cout<<"Dealer's Card 1 = Jack"<<endl;
                    dcard1=10;
                }else if (dcard1==12){
                    cout<<"Dealer's Card 1 = Queen"<<endl;
                    dcard1=10;
                }else if (dcard1==13){
                    cout<<"Dealer's Card 1 = King"<<endl;
                    dcard1=10;
                }else{
                    cout<<"Dealer's Card 1 = "<<dcard1<<endl;
                }
                if (dcard2==1){
                    cout<<"Dealer's Card 2 = ???"<<endl;
                    dcard2=11;
                }else if (dcard2==11){
                    cout<<"Dealer's Card 2 = ???"<<endl;
                    dcard2=10;
                }else if (dcard2==12){
                    cout<<"Dealer's Card 2 = ???"<<endl;
                    dcard2=10;
                }else if (dcard2==13){
                    cout<<"Dealer's Card 2 = ???"<<endl;
                    dcard2=10;
                }else{
                    cout<<"Dealer's Card 2 = ???"<<endl;
                }
                //Calculate total value of cards
                totval=card1+card2;
                dtotval=dcard1+dcard2;
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
                    }else{
                        choice=false;
                    }
                    
                }
                
                //Dealer's Turn
                if (dtotval>=totval){
                    cout<<"Dealer's shows his/her second card."<<endl;
                    cout<<"Dealer's Card 2 = "<<dcard2<<endl;
                    cout<<"The total Value of the Dealer's cards is "<<dtotval<<endl;
                    cout<<"Dealer Wins"<<endl;
                    losses++;
                }else if (totval>21){
                    cout<<"You Bust!"<<endl;
                    losses++;
                }else if (dtotval<totval||dtotval<=16&&dtotval<22){
                    cout<<"Dealer's shows his/her second card."<<endl;
                    cout<<"Dealer's Card 2 = "<<dcard2<<endl;
                    cout<<"The total Value of the Dealer's cards is "<<dtotval<<endl;
                    while (dtotval<totval||dtotval<=16&&dtotval<22){
                        cout<<"The Dealer now deals him/herself an additional card"<<endl;
                        int dcard3=rand()%13+1;
                        if (dcard3==1){
                            cout<<"Dealer's Next Card = Ace"<<endl;
                            dcard3=11;
                        }else if (dcard3==11){
                            cout<<"Dealer's Next Card = Jack"<<endl;
                            dcard3=10;
                        }else if (dcard3==12){
                            cout<<"Dealer's Next Card = Queen"<<endl;
                            dcard3=10;
                        }else if (dcard3==13){
                            cout<<"Dealer's Next Card = King"<<endl;
                            dcard3=10;
                        }else{
                            cout<<"Dealer's Next Card = "<<dcard3<<endl;
                        }
                        //Calculate total value of the Dealer's cards
                        dtotval+=dcard3;
                        cout<<"The total value of the Dealer's cards is "<<dtotval<<endl;
                    }
                    if (dtotval>21){
                        cout<<"Dealer Busts"<<endl;
                        cout<<"You Win!"<<endl;
                        wins++;
                    }else if (dtotval>=totval){
                        cout<<"Dealer Wins"<<endl;
                        losses++;
                    }else{
                        cout<<"You Win!"<<endl;
                        wins++;
                    }
                    
                }else{
                    cout<<"Dealer's shows his/her second card."<<endl;
                    cout<<"Dealer's Card 2 = "<<dcard2<<endl;
                    cout<<"The total Value of the Dealer's cards is "<<dtotval<<endl;
                    cout<<"You win!"<<endl;
                    wins++;
                }
                //End of Game
                break;
            }
            case 'L':
            case 'l':{
                
                //End of Game
                break;
            }
            case 'E':
            case 'e':{
                
                //End of Game
                break;
            }
            default:{
                
                //End of Game
                break;
            }
        }
        
        //Ask to Play Again
        cout<<"Play Again? Y/N"<<endl;
        char repeat;
        cin>>repeat;
        cout<<endl;
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
    output.open("Results.txt");
    output<<"Total Wins = "<<wins<<endl;
    output<<" Total Losses = "<<losses<<endl;
    cout<<"Your Total Wins and Losses can be seen in the 'Results.txt' file"<<endl;
    
    //Exit Stage Right!
    input.close();
    output.close();
    return 0;
}