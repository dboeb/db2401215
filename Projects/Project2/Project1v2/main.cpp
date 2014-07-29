/*Project 1: BlackJack
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
void output_card(const vector<int> &,int);
void card_value(vector<int> &,int);
int hand_value(const vector<int> &,int);
void ace_val(vector<int> &,int,int&);

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
    int newbet;               //An additional Bet if needed
    int inbet;                //Insurance Bet if needed
    int totval;               //Player's Total value of all cards
    int htotval;              //Player's Total value of all cards for second hand
    int dtotval;              //Dealer's total value of all cards
    char choice;              //Player's Decision
    short wins=0;             //Number of wins
    short losses=0;           //Number of losses
    float winper;             //Winning percentage
    ofstream output;          //Output to file
    
    //Set the Random Seed
    srand(static_cast<unsigned int>(time(0)));
    
   
    //Output Pre-Game Directions
    cout<<"                     ----- BlackJack -----"<<endl;
    do{
        cout<<"Please enter your two initials"<<endl;
        cin>>user;
        if(strlen(user)>2){
            cout<<"You can only enter two characters"<<endl;
        }
    }while(strlen(user)>2);
    cout<<"Hello "<<user<<", you have started a new game of Blackjack and your"<<endl;
    cout<<"buy-in is $50. The minimum bet is $5 and all of the normal rules and options"<<endl;
    cout<<"of Blackjack will apply. Refer to Write-Up for detailed rules. Good luck."<<endl;
    
    //Input Values
    //Open the Leader Board file
    input.open("LeaderBoard.txt");
    //Test File For Open Failures
    if (!input){
        cout<<"File Open Failure"<<endl;
    //Input Leader Board 
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
        cout<<endl<<endl;
        cout<<"You started a new game"<<endl;
        do{
            cout<<"Enter your bet in dollars"<<endl;
            cin>>bet;
            if(bet<5){
                cout<<"The minimum bet is $5"<<endl;
            }else if(bet>money){
                cout<<"You do not have that much money."<<endl;
                cout<<"You only have $"<<money<<endl;
            }
        }while(bet<5||bet>money);
        money-=bet;
        cout<<"You were dealt two cards"<<endl;
       
        //Initialize Hands and Values
        cards.clear();
        hand2.clear();
        dcards.clear();
        inbet=0;
        newbet=0;
        hsize=0;
        
        
        //Determine Values for Card 1 and 2 for Player
        cards.push_back(rand()%13+1);
        cards.push_back(rand()%13+1);
        
        //Calculate Size of Vector for Player's Cards
        csize=cards.size();
        
        //Output Player's Cards
        output_card(cards,csize);
        cout<<endl;
        
        //Determine Value of Player's Cards
        card_value(cards,csize);
        
        //Determine Values for Card 1 and 2 for Dealer
        cout<<"The Dealer now deals him/herself two cards"<<endl;
        dcards.push_back(rand()%13+1);
        dcards.push_back(rand()%13+1);
        
        //Calculate Size of Vector for Dealer's Cards Minus One
        dsize=dcards.size()-1;
        
        //Output Dealer's Card 1
        output_card(dcards,dsize);
        //Output Dealer's Card 2 as Unknown
        cout<<"Card 2 = ?"<<endl;
        cout<<endl;
        
        //Calculate Actual Size of Vector for Dealer's Cards
        dsize=dcards.size();
        
        //Calculate total value of Player's cards
        totval=hand_value(cards,csize);
        
        //Determine Best Ace Value for Player's Cards
        if (totval>21){
            ace_val(cards,csize,totval);
        }
        
        //Ask Player for First Decision
        cout<<"The total value of your cards is "<<totval<<endl;
        cout<<endl;
        cout<<"Would you like to do?"<<endl;
        cout<<"Enter: 'H' to hit"<<endl;
        cout<<"       'S' to stay"<<endl;
        cout<<"       'F' to fold/surrender"<<endl;
        cout<<"       'D' to double down"<<endl;
        if(dcards[0]==1){
            cout<<"       'I' to buy insurance"<<endl;
        }
        if(cards[0]==cards[1]&&money>bet){
            cout<<"       'P' to split your pair"<<endl;
        }
        cin>>choice;
        
        //Evaluate Player's Decision and Change Bet Value If Needed
        //If Player chose to double down
        if(choice=='D'||choice=='d'){
            do{
                cout<<"Enter how much additional money you"<<endl;
                cout<<"will add to your bet"<<endl;
                cin>>newbet;
                if(newbet>bet){
                    cout<<"You must enter a value less than"<<endl;
                    cout<<"or equal to your original bet"<<endl;
                }
                if(newbet>money){
                    cout<<"You do not have enough money."<<endl;
                    cout<<"You only have $"<<money<<" left."<<endl;
                }
            }while(newbet>bet||newbet>money);
            bet+=newbet;
            money-=newbet;
            newbet=0;
            choice='H';
            cout<<endl;
        }
        //If Player chose to buy insurance
        if(choice=='I'||choice=='i'){
            do{
                cout<<"Enter how much money you will"<<endl;
                cout<<"put towards your insurance bet"<<endl;
                cin>>inbet;
                if(inbet>0.5*bet){
                    cout<<"You must enter a value less than"<<endl;
                    cout<<"or equal to half your original bet"<<endl;
                }
                if(inbet>money){
                    cout<<"You do not have enough money."<<endl;
                    cout<<"You only have $"<<money<<" left."<<endl;
                }
            }while(inbet>0.5*bet||inbet>money);
            money-=inbet;
            cout<<"Would you like to hit or stay? H/S"<<endl;
            cin>>choice;
            cout<<endl;
        }
        //If Player chose to split the pairs
        if(choice=='P'||choice=='p'){
            cout<<"You chose to split your pair"<<endl;
            cout<<"For your first hand:"<<endl;
            newbet=bet;
            money-=newbet;
            hand2[0]=cards[1];
            cards.pop_back();
            csize=1;
            hsize=1;
            choice='H';
            cout<<endl;
        }
        
        //Player Hit Loop For First Hand
        //While Total Value of Player's Card is Less than 22 and Player Chooses Hit
        while ((choice=='H'||choice=='h')&&totval<22){
            cout<<"You draw an additional card"<<endl;
            
            //Determine Value of Card for Player
            cards.push_back(rand()%13+1);
            
            //Calculate Size of Vector for Player's Cards
            csize++;

            //Output Player's Cards
            output_card(cards,csize);
            cout<<endl;

            //Determine Value of Player's Cards
            card_value(cards,csize);
            
            //Calculate total value of Player's cards
            totval=hand_value(cards,csize);

            //Determine Best Ace Value for Player's Cards
            if (totval>21){
                ace_val(cards,csize,totval);
            }
            
            //Output Value of Player's Cards
            cout<<"The total value of your cards is "<<totval<<endl;
            cout<<endl;
            
            //If Total Value of Player's Cards is less than 22
            if (totval<22){
                //Ask Player for Hit or Stay Decision
                cout<<"Would you like to Hit or Stay? H/S"<<endl;
                cin>>choice;
            //Else
            }else{
                //Exit Hit Loop
                choice=false;
            }
        }
        
        //Player Hit Loop For Second Hand if Needed
        if(hsize>0){
            choice='H';
        }
        //While Total Value of Player's Card is Less than 22 and Player Chooses Hit
        while ((choice=='H'||choice=='h')&&htotval<22&&hsize>0){
            cout<<"For your second hand:"<<endl;
            cout<<"You draw an additional card"<<endl;
            
            //Determine Value of Card for Player
            hand2.push_back(rand()%13+1);
            
            //Calculate Size of Vector for Player's Cards
            hsize++;

            //Output Player's Cards
            output_card(hand2,hsize);
            cout<<endl;

            //Determine Value of Player's Cards
            card_value(hand2,hsize);
            
            //Calculate total value of Player's cards
            htotval=hand_value(hand2,hsize);

            //Determine Best Ace Value for Player's Cards
            if (htotval>21){
                ace_val(hand2,hsize,htotval);
            }
            
            //If Total Value of Player's Cards is less than 22
            if (totval<22){
                //Ask Player for Hit or Stay Decision
                cout<<"Would you like to Hit or Stay? H/S"<<endl;
                cin>>choice;
            //Else
            }else{
                //Exit Hit Loop
                choice=false;
            }
        }
        
        //Calculate Total Value of Dealer's Cards
        //If Both Cards are Valued as 10
        if (dcards[0]>10&&dcards[1]>10){
            //Total Value of Dealer's Cards is 20
            dtotval=20;
        //Else if Both Cards are valued as 11
        }else if (dcards[0]==1&&dcards[1]==1){
            //Total Value of Dealer's Cards is 12
            dtotval=12;
        //Else if One Card is Ace and The Other is Valued as 10 and Ace Value is High or Either
        }else if (((dcards[0]>10&&dcards[1]==1)||(dcards[0]==1&&dcards[1]>10))){
            //Total Value of Dealer's Cards is 21 
            dtotval=21;
        //Else if Card 1 is Valued at 10
        }else if (dcards[0]>10){
            //Total Value of Dealer's Cards is 10 plus Card Number
            dtotval=10+dcards[1];
        //Else if Card 2 is Valued at 10
        }else if (dcards[1]>10){
            //Total Value of Dealer's Cards is 10 plus Card Number
            dtotval=10+dcards[0];
        //Else
        }else{
            //Total Value of Dealer's Cards is Card 1 Number plus Card 2 Number
            dtotval=dcards[0]+dcards[1];
        }
        
        //Dealer's Turn in relation to Player's First Hand
        //If Total Value of Dealer's Cards is greater than or equal to Total Value of Player's Cards
        if(totval==21&&csize==2){
            cout<<"Black Jack"<<endl;
            cout<<"You Win"<<endl;
            wins++;
            money+=2*bet;
            cout<<"You now have $"<<money<<" left"<<endl;
            cout<<endl;
        }else if(dtotval==21&dsize==2){
            //Calculate Size of Vector for Dealer's Cards
            dsize=dcards.size();

            //Output Dealer's Cards
            output_card(dcards,dsize);
            cout<<endl;

            //Determine Value of Dealer's Cards
            card_value(dcards,dsize);
            
            //Calculate total value of Dealer's cards
            dtotval=hand_value(cards,csize);

            //Determine Best Ace Value for Dealer's Cards
            if (dtotval>21){
                ace_val(cards,csize,dtotval);
            }
        
            //Output Total Value of Dealer's Cards
            cout<<"The total value of the Dealer's cards is "<<dtotval<<endl;
            cout<<endl;
            cout<<"Dealer's Black Jack"<<endl;
            cout<<"You Lose"<<endl;
            losses++;
            if(inbet!=0){
                cout<<"You win your insurance bet"<<endl;
                money+=2*inbet;
            }
            cout<<"You now have $"<<money<<" left"<<endl;
            cout<<endl;
        }else if (dtotval==totval){
            //Calculate Size of Vector for Dealer's Cards
            dsize=dcards.size();

            //Output Dealer's Cards
            output_card(dcards,dsize);
            cout<<endl;

            //Determine Value of Dealer's Cards
            card_value(dcards,dsize);
            
            //Calculate total value of Dealer's cards
            dtotval=hand_value(cards,csize);

            //Determine Best Ace Value for Dealer's Cards
            if (dtotval>21){
                ace_val(cards,csize,dtotval);
            }
        
            //Output Total Value of Dealer's Cards
            cout<<"The total value of the Dealer's cards is "<<dtotval<<endl;
            cout<<endl;
            cout<<"Push"<<endl;
            cout<<"Nobody wins"<<endl;
            money+=bet;
            cout<<"You now have $"<<money<<" left"<<endl;
            cout<<endl;
        }else if (dtotval>totval){
            cout<<"Dealer's shows his/her second card."<<endl;
            
            //Calculate Size of Vector for Dealer's Cards
            dsize=dcards.size();

            //Output Dealer's Cards
            output_card(dcards,dsize);
            cout<<endl;

            //Determine Value of Dealer's Cards
            card_value(dcards,dsize);
            
            //Calculate total value of Dealer's cards
            dtotval=hand_value(cards,csize);

            //Determine Best Ace Value for Dealer's Cards
            if (dtotval>21){
                ace_val(cards,csize,dtotval);
            }
        
            //Output Total Value of Dealer's Cards
            cout<<"The total value of the Dealer's cards is "<<dtotval<<endl;
            cout<<endl;
            //Output Dealer as Winner
            cout<<"Dealer Wins"<<endl;
            //Add Loss
            losses++;
            cout<<"You now have $"<<money<<" left"<<endl;
            cout<<endl;
            
        //if Total Value of Dealer's Cards is Less than Total Value of Player's Cards and Both are Less than 22
        }else if ((dtotval<totval||dtotval<=16)&&dtotval<22&&totval<22){
            cout<<"Dealer's shows his/her second card."<<endl;
            
            //Calculate Size of Vector for Dealer's Cards
            dsize=dcards.size();

            //Output Dealer's Cards
            output_card(dcards,dsize);
            cout<<endl;

            //Determine Value of Dealer's Cards
            card_value(dcards,dsize);
            
            //Calculate total value of Dealer's cards
            dtotval=hand_value(cards,csize);

            //Determine Best Ace Value for Dealer's Cards
            if (dtotval>21){
                ace_val(cards,csize,dtotval);
            }
            
            //Output Total Value of Dealer's Cards
            cout<<"The total value of the Dealer's cards is "<<dtotval<<endl;
            cout<<endl;
            
            //Dealer Hit Loop
            //While Total Value of Dealer's Cards is less than Total Value of Player's Cards or 16, and  Less than 22 
            while (dtotval<totval||dtotval<=16&&dtotval<22){
                cout<<"The Dealer now deals him/herself an additional card"<<endl;
                //Determine Value of Dealer's Card 3
                dcards.push_back(rand()%13+1);
                
                //Calculate Size of Vector for Dealer's Cards
                dsize=dcards.size();

                //Output Dealer's Cards
                output_card(dcards,dsize);
                cout<<endl;

                //Determine Value of Dealer's Cards
                card_value(dcards,dsize);

                //Calculate total value of Dealer's cards
                dtotval=hand_value(cards,csize);

                //Determine Best Ace Value for Dealer's Cards
                if (dtotval>21){
                    ace_val(cards,csize,dtotval);
                }
                
                //Output Total Value of Dealer's Cards
                cout<<"The total value of the Dealer's cards is "<<dtotval<<endl; 
                cout<<endl;
            }
            
            //Determine winner in accordance to first hand
            //If The hands Tie
            if (dtotval==totval){
                cout<<"Push"<<endl;
                cout<<"Nobody Wins"<<endl;
                money+=bet;
                cout<<"You now have $"<<money<<" left"<<endl;
                cout<<endl;
            //If Total Value of Dealer's Cards is Over 21
            }else if (dtotval>21){
                //Output That Dealer Busts and Player Wins
                cout<<"Dealer Busts"<<endl;
                cout<<"You Win!"<<endl;
                //Add Win
                wins++;
                money+=bet*2;
                cout<<"You now have $"<<money<<" left"<<endl;
                cout<<endl;
            //if Total Value of Dealer's Cards is Over Total Value of Player's Cards
            }else if (dtotval>totval){
                //Output That Dealer Wins
                cout<<"Dealer Wins"<<endl;
                //Add Loss
                losses++;
                cout<<"You now have $"<<money<<" left"<<endl;
                cout<<endl;
            //Else
            }else{
                //Output That Player Wins
                cout<<"You Win!"<<endl;
                //Add win
                wins++;
                money+=2*bet;
                cout<<"You now have $"<<money<<" left"<<endl;
                cout<<endl;
            }
        //Else
        }else{
            //Output That Player Busts
            cout<<"You Bust!"<<endl;
            //Add Loss
            losses++;
            cout<<"You now have $"<<money<<" left"<<endl;
            cout<<endl;
        }
        
        //Dealer's Turn in relation to Player's Second Hand if there is a second hand
        //If Total Value of Dealer's Cards is greater than or equal to Total Value of Player's Cards
        if(hsize>1){
            cout<<"For your second hand:"<<endl;
            if(htotval==21&&hsize==2){
                cout<<"Black Jack"<<endl;
                cout<<"You Win"<<endl;
                wins++;
                money+=2*bet;
                cout<<"You now have $"<<money<<" left"<<endl;
                cout<<endl;
            }else if(dtotval==21&dsize==2){
                cout<<"Dealer's Black Jack"<<endl;
                cout<<"You Lose"<<endl;
                losses++;
                if(inbet!=0){
                    cout<<"You win your insurance bet"<<endl;
                    money+=2*inbet;
                }
                cout<<"You now have $"<<money<<" left"<<endl;
                cout<<endl;
            }else if (dtotval==htotval){
                cout<<"Push"<<endl;
                cout<<"Nobody Wins"<<endl;
                money+=bet;
                cout<<"You now have $"<<money<<" left"<<endl;
                cout<<endl;
            }else if (dtotval>htotval){
                //Output Total Value of Dealer's Cards
                cout<<"The total value of the Dealer's cards is "<<dtotval<<endl;
                //Output Dealer as Winner
                cout<<"Dealer Wins"<<endl;
                //Add Loss
                losses++;
                cout<<"You now have $"<<money<<" left"<<endl;
                cout<<endl;
            //if Total Value of Dealer's Cards is Less than Player's Cards
            }else if (dtotval<htotval){
                cout<<"You Win"<<endl;
                wins++;
                money+=2*bet;
                cout<<"You now have $"<<money<<" left"<<endl;
                cout<<endl;
            //Else
            }else{
                //Output That Player Busts
                cout<<"You Bust!"<<endl;
                //Add Loss
                losses++;
                cout<<"You now have $"<<money<<" left"<<endl;
                cout<<endl;
            }
        }
        if(choice=='F'||choice=='f'){
            cout<<"You Surrendered"
            //Add Loss
            losses++;
            money+=0.5*bet;
            cout<<"You now have $"<<money<<" left"<<endl;
            cout<<endl;
        }
        
        //End of Game Loop
        
        if(money<5){
            cout<<"You do not have enough money to play again!"<<endl;
            loop=false;
        }else{
            //Ask to Play Again
            cout<<endl<<endl;
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
        }
    //While: Player Wants to Play and has enough money
    }while(loop);
    
    //Calculate Win Percentage
    winper=static_cast<float>(wins)/(wins+losses)*PERCENT;
    
    //Update Leader Board
    cout<<"Your total amount of money left (or score) is "<<money<<endl;
    cout<<"The Leader Board can be seen in the 'LeaderBoard.txt' file"<<endl;
    //for(int row=0;dddd)
    
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
void ace_val(vector<int> &card,int size,int& totval){
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
int hand_value(const vector<int> &card,int size){
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
void card_value(vector<int> &card,int size){
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
void output_card(const vector<int> &card,int size){
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
        if (card[size-1]==1){
            //Output Card as Ace
            cout<<"Card "<<size<<" = Ace"<<endl;
        //Else if Card is Jack
        }else if (card[size-1]==11){
            //Output Card as Jack
            cout<<"Card "<<size<<" = Jack"<<endl;
        //Else if Card is Queen
        }else if (card[size-1]==12){
            //Output Card as Queen
            cout<<"Card "<<size<<" = Queen"<<endl;
        //Else if Card is King
        }else if (card[size-1]==13){
            //Output Card as King
            cout<<"Card "<<size<<" = King"<<endl;
        //Else
        }else{
            //Output Card as Number
            cout<<"Card "<<size<<" = "<<card[size-1]<<endl;
        }
    }
}