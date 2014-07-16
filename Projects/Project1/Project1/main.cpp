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
    int card1;                 //Card 1 value
    int card2;                 //Card 2 value
    int card3=0;               //Additional card value
    int card4=0;               //Additional card value
    int totval;                //Total value of all cards
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
    
    //Input Values
    cout<<"                     ----- 21 -----"<<endl;
    cout<<"Before playing, open the file 'Ace.txt' and clear the file,"<<endl;
    cout<<"then type in 'High', 'Low', or 'Either' to set up the value"<<endl;
    cout<<"of the Ace card. High means that an Ace has a value of 11,"<<endl;
    cout<<"low means that an Ace has a value of 1, and either means "<<endl;
    cout<<"that an Ace has a value of 1 or 11. It is recommended to"<<endl;
    cout<<"play with 'Either'."<<endl;
    cout<<endl;
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
    if (!strcmp(acetype,High)){
        aceval='H';
    }else if (!strcmp(acetype,Low)){
        aceval='L';
    }else if (!strcmp(acetype,Either)){
        aceval='E';
    }else{
        cout<<"Invalid Ace Type, Defaulted Ace to 'Either'"<<endl;
        aceval='E';
    }
    
    //Begin Game Loop
    bool loop=true;
    do{
        //Output Game Information
        cout<<"You started a new game and was dealt two cards"<<endl;
        if (aceval=='H'){
            cout<<"Aces are High"<<endl;
        }else if (aceval=='L'){
            cout<<"Aces are Low"<<endl;
        }else{
            cout<<"Aces are Either High or Low"<<endl;
        }
        
        //Determine Values for Card 1 and 2 for Player
        int card1=rand()%13+1;
        int card2=rand()%13+1;
        
        //Output Player's Cards
        //Output Player's Card 1
        if (card1==1){
            cout<<"Card 1 = Ace"<<endl;
            if (aceval=='H'||aceval=='E'){
                card1=11;
            }else{
                card1=1;
            }
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
        //Output Player's Card 2
        if (card2==1){
            cout<<"Card 2 = Ace"<<endl;
            if (aceval=='H'||aceval=='E'){
                card2=11;
            }else{
                card2=1;
            }
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
        
        //Determine Values for Card 1 and 2 for Dealer
        cout<<"The Dealer now deals him/herself two cards"<<endl;
        int dcard1=rand()%13+1;
        int dcard2=rand()%13+1;
        
        //Output Dealer's Cards
        //Output Dealer's Card 1
        if (dcard1==1){
            cout<<"Dealer's Card 1 = Ace"<<endl;
        }else if (dcard1==11){
            cout<<"Dealer's Card 1 = Jack"<<endl;
        }else if (dcard1==12){
            cout<<"Dealer's Card 1 = Queen"<<endl;
        }else if (dcard1==13){
            cout<<"Dealer's Card 1 = King"<<endl;
        }else{
            cout<<"Dealer's Card 1 = "<<dcard1<<endl;
        }
        //Output Dealer's Card 2
        cout<<"Dealer's Card 2 = ?"<<endl;
        
        //Calculate total value of Player's cards
        totval=card1+card2;
        
        //Ask Player for Hit or Stay Decision
        char choice='S';
        if (totval<22){
            cout<<"The total value of your cards is "<<totval<<endl;
            cout<<"Would you like to Hit or Stay? H/S"<<endl;
            cin>>choice;
        }
        //Player Hit Loop
        while ((choice=='H'||choice=='h')&&totval<22){
            cout<<"You draw an additional card"<<endl;
            //Determine Value for Card3 for Player
            int card3=rand()%13+1;
            
            //Output Player's Card 3
            if (card3==1){
                cout<<"Next Card = Ace"<<endl;
                if (aceval=='H'||aceval=='E'){
                    card3=11;
                }else{
                    card3=1;
                }
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
            
            //Calculate total value of Player's cards
            totval+=card3;
            //Determine Best Ace Value
            if (aceval=='E'){
                if (card1==11&&totval>21){
                    card1=1;
                    totval-=10;
                }
                if (card2==11&&totval>21){
                    card2=1;
                    totval-=10;
                }
                if (card3==11&&totval>21){
                    card3=1;
                    totval-=10;
                }
                if (card4==11&&totval>21){
                    card4=1;
                    totval-=10;
                }
            }
            cout<<"The total value of your cards is "<<totval<<endl;
            
            //Player Hit Part 2
            if (totval<=21){
                //Ask Player for Hit or Stay Decision
                cout<<"Would you like to Hit or Stay? H/S"<<endl;
                cin>>choice;
                if (choice=='H'||choice=='h'){
                    cout<<"You draw an additional card"<<endl;
                    //Determine Value for Card 4 for Player
                    int card4=rand()%13+1;
                    
                    //Output Player's Card 4
                    if (card4==1){
                        cout<<"Next Card = Ace"<<endl;
                        if (aceval=='H'||aceval=='E'){
                            card4=11;
                        }else{
                            card4=1;
                        }
                    }else if (card4==11){
                        cout<<"Next Card = Jack"<<endl;
                        card4=10;
                    }else if (card4==12){
                        cout<<"Next Card = Queen"<<endl;
                        card4=10;
                    }else if (card4==13){
                        cout<<"Next Card = King"<<endl;
                        card4=10;
                    }else{
                        cout<<"Next Card = "<<card4<<endl;
                    }
                    
                    //Calculate total value of cards
                    totval+=card4;
                    //Determine Best Ace Value
                    if (aceval=='E'){
                        if (card1==11&&totval>21){
                            card1=1;
                            totval-=10;
                        }
                        if (card2==11&&totval>21){
                            card2=1;
                            totval-=10;
                        }
                        if (card3==11&&totval>21){
                            card3=1;
                            totval-=10;
                        }
                        if (card4==11&&totval>21){
                            card4=1;
                            totval-=10;
                        }
                    }
                    cout<<"The total value of your cards is "<<totval<<endl;
                    
                    //Ask Player for Hit or Stay Decision
                    if (totval<22){
                        cout<<"Would you like to Hit or Stay? H/S"<<endl;
                        cin>>choice;
                    }
                }
            }else{
                choice=false;
            }
        }
        //Calculate Total Value of Dealer's Cards
        if (dcard1>10&&dcard2>10){
            dtotval=20;
        }else if (((dcard1>10&&dcard2==1)||(dcard1==1&&dcard2>10))&&(aceval=='H'||aceval=='E')){
            dtotval=21;
        }else if (dcard1>10){
            dtotval=10+dcard2;
        }else if (dcard2>10){
            dtotval=10+dcard1;
        }else{
            dtotval=dcard1+dcard2;
        }
        //Dealer's Turn
        //If dtotval>=totval
        if (dtotval>=totval){
            cout<<"Dealer's shows his/her second card."<<endl;
            //Output Dealer's Cards
            //Output Dealer's Card 1
            if (dcard1==1){
                cout<<"Dealer's Card 1 = Ace"<<endl;
            }else if (dcard1==11){
                cout<<"Dealer's Card 1 = Jack"<<endl;
            }else if (dcard1==12){
                cout<<"Dealer's Card 1 = Queen"<<endl;
            }else if (dcard1==13){
                cout<<"Dealer's Card 1 = King"<<endl;
            }else{
                cout<<"Dealer's Card 1 = "<<dcard1<<endl;
            }
            //Output Dealer's Card 2
            if (dcard2==1){
                cout<<"Dealer's Card 2 = Ace"<<endl;
            }else if (dcard2==11){
                cout<<"Dealer's Card 2 = Jack"<<endl;
            }else if (dcard2==12){
                cout<<"Dealer's Card 2 = Queen"<<endl;
            }else if (dcard2==13){
                cout<<"Dealer's Card 2 = King"<<endl;
            }else{
                cout<<"Dealer's Card 2 = "<<dcard2<<endl;
            }
            cout<<"The total value of the Dealer's cards is "<<dtotval<<endl;
            cout<<"Dealer Wins"<<endl;
            //Add Loss
            losses++;
        //if (dtotval<totval||dtotval<=16)&&dtotval<22&&totval<22
        }else if ((dtotval<totval||dtotval<=16)&&dtotval<22&&totval<22){
            cout<<"Dealer's shows his/her second card."<<endl;
            //Output Dealer's Cards
            //Output Dealer's Card 1
            if (dcard1==1){
                cout<<"Dealer's Card 1 = Ace"<<endl;
                if (aceval=='H'||aceval=='E'){
                    dcard1=11;
                }else{
                    dcard1=1;
                }
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
            //Output Dealer's Card 2
            if (dcard2==1){
                cout<<"Dealer's Card 2 = Ace"<<endl;
                if (aceval=='H'||aceval=='E'){
                    dcard2=11;
                }else{
                    dcard2=1;
                }
            }else if (dcard2==11){
                cout<<"Dealer's Card 2 = Jack"<<endl;
                dcard2=10;
            }else if (dcard2==12){
                cout<<"Dealer's Card 2 = Queen"<<endl;
                dcard2=10;
            }else if (dcard2==13){
                cout<<"Dealer's Card 2 = King"<<endl;
                dcard2=10;
            }else{
                cout<<"Dealer's Card 2 = "<<dcard2<<endl;
            }
            
            //Calculate total value of Dealer's cards
            dtotval=dcard1+dcard2;
            cout<<"The total value of the Dealer's cards is "<<dtotval<<endl;
            
            //Dealer Hit Loop
            while (dtotval<totval||dtotval<=16&&dtotval<22){
                cout<<"The Dealer now deals him/herself an additional card"<<endl;
                //Determine Value of Dealer's Card 3
                int dcard3=rand()%13+1;
                
                //Output Dealer's Card 3
                if (dcard3==1){
                    cout<<"Dealer's Next Card = Ace"<<endl;
                    if (aceval=='H'||aceval=='E'){
                        dcard3=11;
                    }else{
                        dcard3=1;
                    }
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
                
                //Calculate total value of Dealer's cards
                dtotval+=dcard3;
                
                //Determine Best Ace Value for Dealer
                if (aceval=='E'){
                    if (dcard1==11&&dtotval>21){
                        dcard1=1;
                        dtotval-=10;
                    }
                    if (dcard2==11&&dtotval>21){
                        dcard2=1;
                        dtotval-=10;
                    }
                    if (dcard3==11&&dtotval>21){
                        dcard3=1;
                        dtotval-=10;
                    }
                    if (dcard4==11&&dtotval>21){
                        dcard4=1;
                        dtotval-=10;
                    }
                }
                cout<<"The total value of the Dealer's cards is "<<dtotval<<endl;
                
                //Dealer Hit Part 2
                if (dtotval<totval||dtotval<=16&&dtotval<22){
                    cout<<"The Dealer now deals him/herself an additional card"<<endl;
                    //Determine Value of Dealer's Card 4
                    int dcard4=rand()%13+1;
                    
                    //Output Dealer's Card 4
                    if (dcard4==1){
                        cout<<"Dealer's Next Card = Ace"<<endl;
                        if (aceval=='H'||aceval=='E'){
                            dcard4=11;
                        }else{
                            dcard4=1;
                        }
                    }else if (dcard4==11){
                        cout<<"Dealer's Next Card = Jack"<<endl;
                        dcard4=10;
                    }else if (dcard4==12){
                        cout<<"Dealer's Next Card = Queen"<<endl;
                        dcard4=10;
                    }else if (dcard4==13){
                        cout<<"Dealer's Next Card = King"<<endl;
                        dcard4=10;
                    }else{
                        cout<<"Dealer's Next Card = "<<dcard4<<endl;
                    }
                    
                    //Calculate total value of Dealer's cards
                    dtotval+=dcard4;
                    
                    //Determine Best Ace Value for Dealer
                    if (aceval=='E'){
                        if (dcard1==11&&dtotval>21){
                            dcard1=1;
                            dtotval-=10;
                        }
                        if (dcard2==11&&dtotval>21){
                            dcard2=1;
                            dtotval-=10;
                        }
                        if (dcard3==11&&dtotval>21){
                            dcard3=1;
                            dtotval-=10;
                        }
                        if (dcard4==11&&dtotval>21){
                            dcard4=1;
                            dtotval-=10;
                        }
                    }
                    cout<<"The total value of the Dealer's cards is "<<dtotval<<endl;
                }
            }
            //Determine winner
            //if dtotval>21
            if (dtotval>21){
                cout<<"Dealer Busts"<<endl;
                cout<<"You Win!"<<endl;
                //Add win
                wins++;
            //if dtotval>=totval
            }else if (dtotval>=totval){
                cout<<"Dealer Wins"<<endl;
                //Add Loss
                losses++;
            //Else
            }else{
                cout<<"You Win!"<<endl;
                //Add win
                wins++;
            }
        //Else
        }else{
            cout<<"You Bust!"<<endl;
            //Add Loss
            losses++;
        }
        //End of Game
        
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
    
    //Calculations
    //Calculate Win Percentage
    winper=static_cast<float>(wins)/(wins+losses)*PERCENT;
    
    //Output the results to file
    output<<fixed<<showpoint<<setprecision(1);
    output.open("Results.txt");
    output<<"Total Wins = "<<wins<<endl;
    output<<"  Total Losses = "<<losses<<endl;
    output<<"  Win Percentage = "<<winper<<"%"<<endl;
    cout<<"Your Total Wins and Losses as well as your Win Percentage"<<endl;
    cout<<"can be seen in the 'Results.txt' file"<<endl;
    
    //Exit Stage Right!
    input.close();
    output.close();
    return 0;
}