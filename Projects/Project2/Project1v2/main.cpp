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
#include <vector>
using namespace std;

//User Libraries

//Global Constants
const int PERCENT=100;//Ratio to Percent Conversion
const int COLS=6;//Number of columns for the 2-d array

//Function Prototypes
void output_card(int[],int);
void card_value(int[],int);
int hand_value(int[],int);
void ace_val(int[],int,int&);

//Execution Starts Here!
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    //Inputs and Constants
    ifstream input;           //Input from file
    const int ROWS=10;
    char board[ROWS][COLS]={};//Leader Board with initials and scores from file
    const int SIZE=3;         //Size set to 3 for the 2 initials and null terminator
    char user[SIZE];          //Initials of User
    //Outputs
    int money=50;             //User's Money (Buy-in at $50)
    vector<int> cards;        //Player's Cards
    vector<int> hand2;        //Player's Second hand if splitting cards
    vector<int> dcards;       //Dealer's Cards
    int csize;                //Size of vector for player's cards
    int hsize;                //Size of vector for player's second hand
    int dsize;                //Size of vector for dealer's cards
    int bet;                  //User's Bet in dollars
    int totval;               //Player's Total value of all cards
    int dtotval;              //Dealer's total value of all cards
    short wins=0;             //Number of wins
    short losses=0;           //Number of losses
    float winper;             //Winning percentage
    ofstream output;          //Output to file
    
    //Set the Random Seed
    srand(static_cast<unsigned int>(time(0)));
    
   
    //Output Pre-Game Directions
    cout<<"                     ----- BlackJack -----"<<endl;
    cout<<"Please enter your two initials"<<endl;
    cin>>user;
    cout<<"Hello "<<user<<", you have started a new game of Blackjack and your"<<endl;
    cout<<"buy-in is $50. The minimum bet is $5 and all of the normal rules and options"<<endl;
    cout<<"of Blackjack will apply. Good luck."<<endl;
    
    //Input Values
    //Open the Leader Board file
    input.open("LeaderBoard.txt");
    //Test File For Open Failures
    if (!input){
        cout<<"File Open Failure"<<endl;
    //Input Ace Type
    }else{
        for (int row=0;row<ROWS;row++){
            for (int col=0;col<COLS;col++){
                input>>board[row][col];
            }
        }
    }
    
    //Set loop=true
    bool loop=true;
    //Do: Game Loop
    do{
        //Output Start of New Game Information
        cout<<"You started a new game and was dealt two cards"<<endl;
        
        //Initialize Hands
        cards(2,0);
        hand2(1,0);
        dcards(2,0);
        
        //Determine Values for Card 1 and 2 for Player
        int cards[1]=rand()%13+1;
        int cards[2]=rand()%13+1;
        
        //Calculate Size of Vector for Player's Cards
        csize=cards.size();
        
        //Output Player's Cards
        output_card(cards,csize);
        
        //Determine Value of Player's Cards
        card_value(cards,csize);
        
        //Determine Values for Card 1 and 2 for Dealer
        cout<<"The Dealer now deals him/herself two cards"<<endl;
        int dcards[1]=rand()%13+1;
        int dcards[2]=rand()%13+1;
        
        //Calculate Size of Vector for Dealer's Cards Minus One
        dsize=dcards.size()-1;
        
        //Output Dealer's Card 1
        output_card(dcards,dsize);
        //Output Dealer's Card 2 as Unknown
        cout<<"Dealer's Card 2 = ?"<<endl;
        
        //Calculate Actual Size of Vector for Dealer's Cards
        dsize=dcards.size();
        
        //Calculate total value of Player's cards
        totval=hand_value(cards,csize);
        
        //Determine Best Ace Value for Player's Cards
        if (totval>21){
            ace_val(cards,csize,totval);
        }
        
        //Ask Player for First Decision
        Xcout<<"The total value of your cards is "<<totval<<endl;
        cout<<"Would you like to Hit or Stay? H/S"<<endl;
        cin>>choice;
        
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
    output<<"Total Wins = "<<wins<<"\n";
    //Output Total Losses
    output<<"  Total Losses = "<<losses<<"\n";
    //Output Win Percentage
    output<<"  Win Percentage = "<<winper<<"%";
    //Inform Player Results were Outputted to File
    cout<<"Your Total Wins and Losses as well as your Win Percentage"<<endl;
    cout<<"can be seen in the 'Results.txt' file"<<endl;
    
    //Exit Stage Right!
    //Close Files
    input.close();
    output.close();
    return 0;
}

//Function For Determining Best Ace Value
//Inputs
//    cards  ->Vector containing cards
//    size   ->Size of vector
//Outputs
//    Best Ace Value
void ace_val(int card[],int size,int& totval){
    for(int row=0;row<size&&totval>21;row++){
        if (card[size]==11){
            card[size]=1;
            totval-=10;
        }
    }
}

//Function For Determining Card Value
//Inputs
//    cards  ->Vector containing cards
//    size   ->Size of vector
//Outputs
//    sum    ->Total value of Cards
int hand_value(int card[],int size){
    int sum=0;
    for (int row=0;row<size;row++){
        sum+=card[row];
    }
    return sum;
}

//Function For Determining Card Value
//Inputs
//    cards  ->Vector containing cards
//    size   ->Size of vector
//Outputs
//    Values of Cards
void card_value(int card[],int size){
    //If there are only two cards
    if (size<3){
        //Calculate Both Cards
        for(int row=0;row<size;row++){    
            //If Card is Ace
            if (card[row]==1){
                //Set Ace as 11
                card[row]=11;
            //Else if Card is Jack
            }else if (card[row]==11){
                //Set Jack as 10
                card[row]=10;
            //Else if Card is Queen
            }else if (card[row]==12){
                //Set Queen as 10
                card[row]=10;
            //Else if Card is King
            }else if (card[row]==13){
                //Set King as 10
                card[row]=10;
            //Else
            }else{
                //Leave Card as Number
                card[row]=card[row];
            }
        }
    //Else
    }else{
        //Calcualte Most Recent Card
        //If Card is Ace
        if (card[size]==1){
            //Set Ace as 11
            card[size]=11;
        //Else if Card is Jack
        }else if (card[size]==11){
            //Set Jack as 10
            card[size]=10;
        //Else if Card is Queen
        }else if (card[size]==12){
            //Set Queen as 10
            card[size]=10;
        //Else if Card is King
        }else if (card[size]==13){
            //Set King as 10
            card[size]=10;
        //Else
        }else{
            //Leave Card as Number
            card[size]=card[size];
        }
    }
}

//Function For Outputting Cards
//Inputs
//    cards  ->Vector containing cards
//    size   ->Size of vector
//Outputs
//    Names of Cards
void output_card(int card[],int size){
    //If there are only two cards
    if (size<3){
        //Output Both Cards
        for(int row=0;row<size;row++){    
            //If Card is Ace
            if (card[row]==1){
                //Output Card as Ace
                cout<<"Card "<<row+1<<" = Ace"<<endl;
            //Else if Card is Jack
            }else if (card[row]==11){
                //Output Card as Jack
                cout<<"Card "<<row+1<<" = Jack"<<endl;
            //Else if Card is Queen
            }else if (card[row]==12){
                //Output Card as Queen
                cout<<"Card "<<row+1<<" = Queen"<<endl;
            //Else if Card is King
            }else if (card[row]==13){
                //Output Card as King
                cout<<"Card "<<row+1<<" = King"<<endl;
            //Else
            }else{
                //Output Card as Number
                cout<<"Card "<<row+1<<" = "<<card[row]<<endl;
            }
        }
    //Else
    }else{
        //Output Most Recent Card
        //If Card is Ace
        if (card[size]==1){
            //Output Card as Ace
            cout<<"Card "<<size<<" = Ace"<<endl;
        //Else if Card is Jack
        }else if (card[size]==11){
            //Output Card as Jack
            cout<<"Card "<<size<<" = Jack"<<endl;
        //Else if Card is Queen
        }else if (card[size]==12){
            //Output Card as Queen
            cout<<"Card "<<size<<" = Queen"<<endl;
        //Else if Card is King
        }else if (card[size]==13){
            //Output Card as King
            cout<<"Card "<<size<<" = King"<<endl;
        //Else
        }else{
            //Output Card as Number
            cout<<"Card "<<size<<" = "<<card[size]<<endl;
        }
    }
}