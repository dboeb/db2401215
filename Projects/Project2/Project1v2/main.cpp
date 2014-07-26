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
#include <string.h>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const int PERCENT=100;//Ratio to Percent Conversion

//Function Prototypes

//Execution Starts Here!
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    //Inputs and Constants
    ifstream input;            //Input from file
    char aceval;               //Ace Value
    const int SIZE=7;          //Character length
    char acetype[SIZE];        //Ace Type, Inputted from file
    char High[SIZE]="High";    //Character string to compare input string to
    char Low[SIZE]="Low";      //Character string to compare input string to
    char Either[SIZE]="Either";//Character string to compare input string to
    //Outputs
    int card1;                 //Player's Card 1 value
    int card2;                 //Player's Card 2 value
    int card3=0;               //Player's Additional card value
    int card4=0;               //Player's Additional card value
    int totval;                //Player's Total value of all cards
    int dcard1;                //Dealer's Card 1 value
    int dcard2;                //Dealer's Card 2 value
    int dcard3=0;              //Dealer's additional card value
    int dcard4=0;              //Dealer's additional card value
    int dtotval;               //Dealer's total value of all cards
    short wins=0;              //Number of wins
    short losses=0;            //Number of losses
    float winper;              //Winning percentage
    ofstream output;           //Output to file
    
    //Set the Random Seed
    srand(static_cast<unsigned int>(time(0)));
    
   
    //Output Pre-Game Directions
    cout<<"                     ----- 21 -----"<<endl;
    cout<<"Before playing, open the file 'Ace.txt' and clear the file,"<<endl;
    cout<<"then type in 'High', 'Low', or 'Either' to set up the value"<<endl;
    cout<<"of the Ace card. High means that an Ace has a value of 11,"<<endl;
    cout<<"low means that an Ace has a value of 1, and either means "<<endl;
    cout<<"that an Ace has a value of 1 or 11. It is recommended to"<<endl;
    cout<<"play with 'Either'."<<endl;
    cout<<endl;
    
    //Input Values
    //Open the Input file
    input.open("Ace.txt");
    //Test File For Open Failures
    if (!input){
        cout<<"File Open Failure"<<endl;
    //Input Ace Type
    }else{
        input>>acetype;
    }
    
    //Determine Game Type
    //If file reads High
    if (!strcmp(acetype,High)){
        //Set Ace Value to High
        aceval='H';
    //Else if file reads Low
    }else if (!strcmp(acetype,Low)){
        //Set Ace Value to Low
        aceval='L';
    //Else if file reads Either
    }else if (!strcmp(acetype,Either)){
        //Set Ace Value to Either
        aceval='E';
    //Else Default to Either
    }else{
        cout<<"Invalid Ace Type, Defaulted Ace to 'Either'"<<endl;
        aceval='E';
    }
    
    //Set loop=true
    bool loop=true;
    //Do: Game Loop
    do{
        //Output Start of New Game Information
        cout<<"You started a new game and was dealt two cards"<<endl;
        //If Ace Values are High
        if (aceval=='H'){
            //Output Ace Value as High
            cout<<"Aces are High"<<endl;
        //Else if Ace Values are Low
        }else if (aceval=='L'){
            //Output Ace Value as Low
            cout<<"Aces are Low"<<endl;
        //Else Default to Either
        }else{
            cout<<"Aces are Either High or Low"<<endl;
        }
        
        //Determine Values for Card 1 and 2 for Player
        int card1=rand()%13+1;
        int card2=rand()%13+1;
        
        //Output Player's Cards
        //Output Player's Card 1
        //If Card 1 is Ace
        if (card1==1){
            //Output Card 1 as Ace
            cout<<"Card 1 = Ace"<<endl;
            //If Ace Value is High or Either
            if (aceval=='H'||aceval=='E'){
                //Set Ace Value as 11
                card1=11;
            //Else
            }else{
                //Set Ace Value as 1
                card1=1;
            }
        //Else if Card 1 is Jack
        }else if (card1==11){
            //Output Card 1 as Jack
            cout<<"Card 1 = Jack"<<endl;
            //Set Jack Value as 10
            card1=10;
        //Else if Card 1 is Queen
        }else if (card1==12){
            //Output Card 1 as Queen
            cout<<"Card 1 = Queen"<<endl;
            //Set Queen Value as 10
            card1=10;
        //Else if Card 1 is King
        }else if (card1==13){
            //Output Card 1 as King
            cout<<"Card 1 = King"<<endl;
            //Set King Value as 10
            card1=10;
        //Else
        }else{
            //Output Card 1 as Number
            cout<<"Card 1 = "<<card1<<endl;
        }
        //Output Player's Card 2
        //If Card 2 is Ace
        if (card2==1){
            //Output Card 2 as Ace
            cout<<"Card 2 = Ace"<<endl;
            //If Ace Value is High or Either
            if (aceval=='H'||aceval=='E'){
                //Set Ace Value as 11
                card2=11;
            //Else
            }else{
                //Set Ace Value as 1
                card2=1;
            }
        //Else if Card 2 is Jack
        }else if (card2==11){
            //Output Card 2 as Jack
            cout<<"Card 2 = Jack"<<endl;
            //Set Jack Value as 10
            card2=10;
        //Else if Card 2 is Queen
        }else if (card2==12){
            //Output Card 2 as Queen
            cout<<"Card 2 = Queen"<<endl;
            //Set Queen Value as 10
            card2=10;
        //Else if Card 2 is King
        }else if (card2==13){
            //Output Card 2 as King
            cout<<"Card 2 = King"<<endl;
            //Set King Value as 10
            card2=10;
        //Else
        }else{
            //Output Card 2 as Number
            cout<<"Card 2 = "<<card2<<endl;
        }
        
        //Determine Values for Card 1 and 2 for Dealer
        cout<<"The Dealer now deals him/herself two cards"<<endl;
        int dcard1=rand()%13+1;
        int dcard2=rand()%13+1;
        
        //Output Dealer's Cards
        //Output Dealer's Card 1
        //If Card 1 is Ace
        if (dcard1==1){
            //Output Card 1 as Ace
            cout<<"Dealer's Card 1 = Ace"<<endl;
        //Else if Card 1 is Jack
        }else if (dcard1==11){
            //Output Card 1 as Jack
            cout<<"Dealer's Card 1 = Jack"<<endl;
        //Else if Card 1 is Queen
        }else if (dcard1==12){
            //Output Card 1 as Queen
            cout<<"Dealer's Card 1 = Queen"<<endl;
        //Else if Card 1 is King
        }else if (dcard1==13){
            //Output Card 1 as King
            cout<<"Dealer's Card 1 = King"<<endl;
        //Else
        }else{
            //Output Card 1 as Number
            cout<<"Dealer's Card 1 = "<<dcard1<<endl;
        }
        //Output Dealer's Card 2 as Unknown
        cout<<"Dealer's Card 2 = ?"<<endl;
        
        //Calculate total value of Player's cards
        totval=card1+card2;
        
        //Initialize Player Decision as Stay
        char choice='S';
        //If Total Value of Player's Card is Less than 22
        if (totval<22){
            //Ask Player for Hit or Stay Decision
            cout<<"The total value of your cards is "<<totval<<endl;
            cout<<"Would you like to Hit or Stay? H/S"<<endl;
            cin>>choice;
        }
        //Player Hit Loop
        //While Total Value of Player's Card is Less than 22 and Player Chooses Hit
        while ((choice=='H'||choice=='h')&&totval<22){
            cout<<"You draw an additional card"<<endl;
            //Determine Value for Card3 for Player
            int card3=rand()%13+1;
            
            //Output Player's Card 3
            //If Card 3 is Ace
            if (card3==1){
                //Output Card 3 as Ace
                cout<<"Next Card = Ace"<<endl;
                //If Ace Value is High or Either
                if (aceval=='H'||aceval=='E'){
                    //Set Ace Value as 11
                    card3=11;
                //Else
                }else{
                    //Set Ace Value as 1
                    card3=1;
                }
            //Else if Card 3 is Jack
            }else if (card3==11){
                //Output Card 3 as Jack
                cout<<"Next Card = Jack"<<endl;
                //Set Jack Value as 10
                card3=10;
            //Else if Card 3 is Queen
            }else if (card3==12){
                //Output Card 3 as Queen
                cout<<"Next Card = Queen"<<endl;
                //Set Queen Value as 10
                card3=10;
            //Else if Card 3 is King
            }else if (card3==13){
                //Output Card 3 as King
                cout<<"Next Card = King"<<endl;
                //Set King Value as 10
                card3=10;
            //Else
            }else{
                //Output Card 3 as Number
                cout<<"Next Card = "<<card3<<endl;
            }
            
            //Calculate total value of Player's cards
            totval+=card3;
            //If Ace Value is Either Determine Best Ace Value
            if (aceval=='E'){
                //If Card 1 is High Ace and Total Value of Player's Cards is Over 22
                if (card1==11&&totval>21){
                    //Set Ace Value as 1
                    card1=1;
                    //Calculate new Total Value of Player's Cards
                    totval-=10;
                }
                //If Card 2 is High Ace and Total Value of Player's Cards is Over 22
                if (card2==11&&totval>21){
                    //Set Ace Value as 1
                    card2=1;
                    //Calculate new Total Value of Player's Cards
                    totval-=10;
                }
                //If Card 3 is High Ace and Total Value of Player's Cards is Over 22
                if (card3==11&&totval>21){
                    //Set Ace Value as 1
                    card3=1;
                    //Calculate new Total Value of Player's Cards
                    totval-=10;
                }
                //If Card 4 is High Ace and Total Value of Player's Cards is Over 22
                if (card4==11&&totval>21){
                    //Set Ace Value as 1
                    card4=1;
                    //Calculate new Total Value of Player's Cards
                    totval-=10;
                }
            }
            
            //Output Total Value of Player's Cards
            cout<<"The total value of your cards is "<<totval<<endl;
            
            //If Total Value of Player's Cards is less than 22
            if (totval<22){
                //Ask Player for Hit or Stay Decision
                cout<<"Would you like to Hit or Stay? H/S"<<endl;
                cin>>choice;
                //If Player Hits
                if (choice=='H'||choice=='h'){
                    cout<<"You draw an additional card"<<endl;
                    //Determine Value for Card 4 for Player
                    int card4=rand()%13+1;
                    
                    //Output Player's Card 4
                    //If Card 4 is Ace
                    if (card4==1){
                        //Output Card 4 as Ace
                        cout<<"Next Card = Ace"<<endl;
                        //If Ace Value is High or Either
                        if (aceval=='H'||aceval=='E'){
                            //Set Ace Value as 11
                            card4=11;
                        //Else
                        }else{
                            //Set Ace Value as 1
                            card4=1;
                        }
                    //Else if Card 4 is Jack
                    }else if (card4==11){
                        //Output Card 4 as Jack
                        cout<<"Next Card = Jack"<<endl;
                        //Set Jack Value as 10
                        card4=10;
                    //Else if Card 4 is Queen
                    }else if (card4==12){
                        //Output Card 4 as Queen
                        cout<<"Next Card = Queen"<<endl;
                        //Set Queen Value as 10
                        card4=10;
                    //Else if Card 4 is King
                    }else if (card4==13){
                        //Output Card 4 as King
                        cout<<"Next Card = King"<<endl;
                        //Set King Value as 10
                        card4=10;
                    //Else
                    }else{
                        //Output Card 4 as Number
                        cout<<"Next Card = "<<card4<<endl;
                    }
                    
                    //Calculate total value of cards
                    totval+=card4;
                    //If Ace Value is Either Determine Best Ace Value
                    if (aceval=='E'){
                        //If Card 1 is High Ace and Total Value of Player's Cards is Over 22
                        if (card1==11&&totval>21){
                            //Set Ace Value as 1
                            card1=1;
                            //Calculate New Total Value for Player's Cards
                            totval-=10;
                        }
                        //If Card 2 is High Ace and Total Value of Player's Cards is Over 22
                        if (card2==11&&totval>21){
                            //Set Ace Value as 1
                            card2=1;
                            //Calculate New Total Value for Player's Cards
                            totval-=10;
                        }
                        //If Card 3 is High Ace and Total Value of Player's Cards is Over 22
                        if (card3==11&&totval>21){
                            //Set Ace Value as 1
                            card3=1;
                            //Calculate New Total Value for Player's Cards
                            totval-=10;
                        }
                        //If Card 4 is High Ace and Total Value of Player's Cards is Over 22
                        if (card4==11&&totval>21){
                            //Set Ace Value as 1
                            card4=1;
                            //Calculate New Total Value for Player's Cards
                            totval-=10;
                        }
                    }
                    
                    //Output Total Value of Player's Cards
                    cout<<"The total value of your cards is "<<totval<<endl;
                    
                    //If Total Value of Player's Cards are less than 22
                    if (totval<22){
                        //Ask Player for Hit or Stay Decision
                        cout<<"Would you like to Hit or Stay? H/S"<<endl;
                        cin>>choice;
                    }
                }
            //Else
            }else{
                //Exit Hit Loop
                choice=false;
            }
        }
        
        //Calculate Total Value of Dealer's Cards
        //If Both Cards are Valued as 10
        if (dcard1>10&&dcard2>10){
            //Total Value of Dealer's Cards is 20
            dtotval=20;
        //Else if One Card is Ace and The Other is Valued as 10 and Ace Value is High or Either
        }else if (((dcard1>10&&dcard2==1)||(dcard1==1&&dcard2>10))&&(aceval=='H'||aceval=='E')){
            //Total Value of Dealer's Cards is 21 
            dtotval=21;
        //Else if Card 1 is Valued at 10
        }else if (dcard1>10){
            //Total Value of Dealer's Cards is 10 plus Card Number
            dtotval=10+dcard2;
        //Else if Card 2 is Valued at 10
        }else if (dcard2>10){
            //Total Value of Dealer's Cards is 10 plus Card Number
            dtotval=10+dcard1;
        //Else
        }else{
            //Total Value of Dealer's Cards is Card 1 Number plus Card 2 Number
            dtotval=dcard1+dcard2;
        }
        
        //Dealer's Turn
        //If Total Value of Dealer's Cards is greater than or equal to Total Value of Player's Cards
        if (dtotval>=totval){
            cout<<"Dealer's shows his/her second card."<<endl;
            //Output Dealer's Cards
            //Output Dealer's Card 1
            //If Card 1 is Ace
            if (dcard1==1){
                //Output Card 1 as Ace
                cout<<"Dealer's Card 1 = Ace"<<endl;
            //Else if Card 1 is Jack
            }else if (dcard1==11){
                //Output Card 1 as Jack
                cout<<"Dealer's Card 1 = Jack"<<endl;
            //Else if Card 1 is Queen
            }else if (dcard1==12){
                //Output Card 1 as Queen
                cout<<"Dealer's Card 1 = Queen"<<endl;
            //Else if Card 1 is King
            }else if (dcard1==13){
                //Output Card 1 as King
                cout<<"Dealer's Card 1 = King"<<endl;
            //Else
            }else{
                //Output Card as Number
                cout<<"Dealer's Card 1 = "<<dcard1<<endl;
            }
            //Output Dealer's Card 2
            //If Card 2 is Ace
            if (dcard2==1){
                //Output Card 2 as Ace
                cout<<"Dealer's Card 2 = Ace"<<endl;
            //Else if Card 2 is Jack
            }else if (dcard2==11){
                //Output Card 2 as Jack
                cout<<"Dealer's Card 2 = Jack"<<endl;
            //Else if Card 2 is Queen
            }else if (dcard2==12){
                //Output Card 2 as Queen
                cout<<"Dealer's Card 2 = Queen"<<endl;
            //Else if Card 2 is King
            }else if (dcard2==13){
                //Output Card 2 as King
                cout<<"Dealer's Card 2 = King"<<endl;
            //Else
            }else{
                //Output Card 2 as Number
                cout<<"Dealer's Card 2 = "<<dcard2<<endl;
            }
            //Output Total Value of Dealer's Cards
            cout<<"The total value of the Dealer's cards is "<<dtotval<<endl;
            //Output Dealer as Winner
            cout<<"Dealer Wins"<<endl;
            //Add Loss
            losses++;
        //if Total Value of Dealer's Cards is Less than Total Value of Player's Cards and Both are Less than 22
        }else if ((dtotval<totval||dtotval<=16)&&dtotval<22&&totval<22){
            cout<<"Dealer's shows his/her second card."<<endl;
            //Output Dealer's Cards
            //Output Dealer's Card 1
            //If Card 1 is Ace
            if (dcard1==1){
                //Output Card 1 as Ace
                cout<<"Dealer's Card 1 = Ace"<<endl;
                //If Ace Value is High or Either
                if (aceval=='H'||aceval=='E'){
                    //Set Ace Value as 11
                    dcard1=11;
                //Else
                }else{
                    //Set Ace Value as 1
                    dcard1=1;
                }
            //Else if Card 1 is Jack
            }else if (dcard1==11){
                //Output Card 1 as Jack
                cout<<"Dealer's Card 1 = Jack"<<endl;
                //Set Jack Value as 10
                dcard1=10;
            //Else if Card 1 is Queen
            }else if (dcard1==12){
                //Output Card 1 as Queen
                cout<<"Dealer's Card 1 = Queen"<<endl;
                //Set Queen Value as 10
                dcard1=10;
            //Else if Card 1 is King
            }else if (dcard1==13){
                //Output Card 1 as King
                cout<<"Dealer's Card 1 = King"<<endl;
                //Set King Value as 10
                dcard1=10;
            //Else
            }else{
                //Output Card 1 as Number
                cout<<"Dealer's Card 1 = "<<dcard1<<endl;
            }
            //Output Dealer's Card 2
            //If Card 2 is Ace
            if (dcard2==1){
                //Output Card 2 as Ace
                cout<<"Dealer's Card 2 = Ace"<<endl;
                //If Ace Value is High or Either
                if (aceval=='H'||aceval=='E'){
                    //Set Ace Value as 11
                    dcard2=11;
                //Else
                }else{
                    //Set Ace Value as 1
                    dcard2=1;
                }
            //Else if Card 2 is Jack
            }else if (dcard2==11){
                //Output Card 2 as Jack
                cout<<"Dealer's Card 2 = Jack"<<endl;
                //Set Jack Value as 10
                dcard2=10;
            //Else if Card 2 is Queen
            }else if (dcard2==12){
                //Output Card 2 as Queen
                cout<<"Dealer's Card 2 = Queen"<<endl;
                //Set Queen Value as 10
                dcard2=10;
            //Else if Card 2 is King
            }else if (dcard2==13){
                //Output Card 2 as King
                cout<<"Dealer's Card 2 = King"<<endl;
                //Set King Value as 10
                dcard2=10;
            //Else
            }else{
                //Output Card 2 as Number
                cout<<"Dealer's Card 2 = "<<dcard2<<endl;
            }
            
            //Calculate Total Value of Dealer's Cards
            dtotval=dcard1+dcard2;
            
            //Output Total Value of Dealer's Cards
            cout<<"The total value of the Dealer's cards is "<<dtotval<<endl;
            
            //Dealer Hit Loop
            //While Total Value of Dealer's Cards is less than Total Value of Player's Cards or 16, and  Less than 22 
            while (dtotval<totval||dtotval<=16&&dtotval<22){
                cout<<"The Dealer now deals him/herself an additional card"<<endl;
                //Determine Value of Dealer's Card 3
                int dcard3=rand()%13+1;
                
                //Output Dealer's Card 3
                //If Card 3 is Ace
                if (dcard3==1){
                    //Output Card 3 as Ace
                    cout<<"Dealer's Next Card = Ace"<<endl;
                    //If Ace Value is High or Either
                    if (aceval=='H'||aceval=='E'){
                        //Set Ace Value as 11
                        dcard3=11;
                    //Else
                    }else{
                        //Set Ace Value as 1
                        dcard3=1;
                    }
                //Else if Card 3 is Jack
                }else if (dcard3==11){
                    //Output Card 3 as Jack
                    cout<<"Dealer's Next Card = Jack"<<endl;
                    //Set Jack Value as 10
                    dcard3=10;
                //Else if Card 3 is Queen
                }else if (dcard3==12){
                    //Output Card 3 as Queen
                    cout<<"Dealer's Next Card = Queen"<<endl;
                    //Set Queen Value as 10
                    dcard3=10;
                //Else if Card 3 is King
                }else if (dcard3==13){
                    //Output Card 3 as King
                    cout<<"Dealer's Next Card = King"<<endl;
                    //Set King Value as 10
                    dcard3=10;
                //Else 
                }else{
                    //Output Card 3 as Number
                    cout<<"Dealer's Next Card = "<<dcard3<<endl;
                }
                
                //Calculate Total Value of Dealer's Cards
                dtotval+=dcard3;
                
                //If Ace Value is Either Determine Best Ace Value for Dealer
                if (aceval=='E'){
                    //If Card 1 is High Ace and Total Value of Dealer's Cards is over 21
                    if (dcard1==11&&dtotval>21){
                        //Set Ace Value as 1
                        dcard1=1;
                        //Calculate New Total Value of Dealer's Cards
                        dtotval-=10;
                    }
                    //If Card 2 is High Ace and Total Value of Dealer's Cards is over 21
                    if (dcard2==11&&dtotval>21){
                        //Set Ace Value as 1
                        dcard2=1;
                        //Calculate New Total Value of Dealer's Cards
                        dtotval-=10;
                    }
                    //If Card 3 is High Ace and Total Value of Dealer's Cards is over 21
                    if (dcard3==11&&dtotval>21){
                        //Set Ace Value as 1
                        dcard3=1;
                        //Calculate New Total Value of Dealer's Cards
                        dtotval-=10;
                    }
                    //If Card 4 is High Ace and Total Value of Dealer's Cards is over 21
                    if (dcard4==11&&dtotval>21){
                        //Set Ace Value as 1
                        dcard4=1;
                        //Calculate New Total Value of Dealer's Cards
                        dtotval-=10;
                    }
                }
                
                //Output Total Value of Dealer's Cards
                cout<<"The total value of the Dealer's cards is "<<dtotval<<endl;
                
                //If Total Value of Dealer's Cards is less than Total Value of Player's Cards or 16, and  Less than 22 
                if (dtotval<totval||dtotval<=16&&dtotval<22){
                    cout<<"The Dealer now deals him/herself an additional card"<<endl;
                    //Determine Value of Dealer's Card 4
                    int dcard4=rand()%13+1;
                    
                    //Output Dealer's Card 4
                    //If Card 4 is Ace
                    if (dcard4==1){
                        //Output Card 4 as Ace
                        cout<<"Dealer's Next Card = Ace"<<endl;
                        //If Ace Value is High or Either
                        if (aceval=='H'||aceval=='E'){
                            //Set Ace Value as 11
                            dcard4=11;
                        //Else
                        }else{
                            //Set Ace Value as 1
                            dcard4=1;
                        }
                    //Else if Card 4 is Jack
                    }else if (dcard4==11){
                        //Output Card 4 as Jack
                        cout<<"Dealer's Next Card = Jack"<<endl;
                        //Set Jack Value as 10
                        dcard4=10;
                    //Else if Card 4 is Queen
                    }else if (dcard4==12){
                        //Output Card 4 as Queen
                        cout<<"Dealer's Next Card = Queen"<<endl;
                        //Set Queen Value as 10
                        dcard4=10;
                    //Else if Card 4 is King
                    }else if (dcard4==13){
                        //Output Card 4 as King
                        cout<<"Dealer's Next Card = King"<<endl;
                        //Set King Value as 10
                        dcard4=10;
                    //Else
                    }else{
                        //Output Card 4 as Number
                        cout<<"Dealer's Next Card = "<<dcard4<<endl;
                    }
                    
                    //Calculate total value of Dealer's cards
                    dtotval+=dcard4;
                    
                    //If Ace Value is Either Determine Best Ace Value for Dealer
                    if (aceval=='E'){
                        //If Card 1 is High Ace and Total Value of Dealer's Cards is over 21
                        if (dcard1==11&&dtotval>21){
                            //Set Ace Value as 1
                            dcard1=1;
                            //Calculate New Total Value of Dealer's Cards
                            dtotval-=10;
                        }
                        //If Card 2 is High Ace and Total Value of Dealer's Cards is over 21
                        if (dcard2==11&&dtotval>21){
                            //Set Ace Value as 1
                            dcard2=1;
                            //Calculate New Total Value of Dealer's Cards
                            dtotval-=10;
                        }
                        //If Card 3 is High Ace and Total Value of Dealer's Cards is over 21
                        if (dcard3==11&&dtotval>21){
                            //Set Ace Value as 1
                            dcard3=1;
                            //Calculate New Total Value of Dealer's Cards
                            dtotval-=10;
                        }
                        //If Card 4 is High Ace and Total Value of Dealer's Cards is over 21
                        if (dcard4==11&&dtotval>21){
                            //Set Ace Value as 1
                            dcard4=1;
                            //Calculate New Total Value of Dealer's Cards
                            dtotval-=10;
                        }
                    }
                    
                    //Output Total Value of Dealer's Cards
                    cout<<"The total value of the Dealer's cards is "<<dtotval<<endl;
                }
            }
            
            //Determine winner
            //If Total Value of Dealer's Cards is Over 21
            if (dtotval>21){
                //Output That Dealer Busts and Player Wins
                cout<<"Dealer Busts"<<endl;
                cout<<"You Win!"<<endl;
                //Add Win
                wins++;
            //if Total Value of Dealer's Cards is Over Total Value of Player's Cards
            }else if (dtotval>=totval){
                //Output That Dealer Wins
                cout<<"Dealer Wins"<<endl;
                //Add Loss
                losses++;
            //Else
            }else{
                //Output That Player Wins
                cout<<"You Win!"<<endl;
                //Add win
                wins++;
            }
        //Else
        }else{
            //Output That Player Busts
            cout<<"You Bust!"<<endl;
            //Add Loss
            losses++;
        }
        //End of Game Loop
        
        //Ask to Play Again
        cout<<"Play Again? Y/N"<<endl;
        char repeat;
        cin>>repeat;
        cout<<endl;
        switch(repeat){
            //If Player Chooses Yes Continue Game Loop
            case 'Y':
            case 'y':{
                break;
            //Default End Game Loop
            }default:{
                loop=false;
                break;
            }    
        }
    //While: Player Wants to Play
    }while(loop);
    
    //Calculate Win Percentage
    winper=static_cast<float>(wins)/(wins+losses)*PERCENT;
    
    //Output the results to file
    output<<fixed<<showpoint<<setprecision(1);
    output.open("Results.txt");
    //Output Total Wins
    output<<"Total Wins = "<<wins<<endl;
    //Output Total Losses
    output<<"  Total Losses = "<<losses<<endl;
    //Output Win Percentage
    output<<"  Win Percentage = "<<winper<<"%"<<endl;
    //Inform Player Results were Outputted to File
    cout<<"Your Total Wins and Losses as well as your Win Percentage"<<endl;
    cout<<"can be seen in the 'Results.txt' file"<<endl;
    
    //Exit Stage Right!
    //Close Files
    input.close();
    output.close();
    return 0;
}