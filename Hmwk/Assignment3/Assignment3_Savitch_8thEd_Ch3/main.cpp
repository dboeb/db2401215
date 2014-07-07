/* Assignment 3: Savitch Chapter 3
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on July 3, 2014, 11:55 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Starts Here!
int main(int argc, char** argv) {
    //General Menu Format
    bool loop=true;
    do{
        //Display the selection
        cout<<endl;
        cout<<"Type 1 to solve problem 1"<<endl;
        cout<<"Type 2 to solve problem 2"<<endl;
        cout<<"Type 3 to solve problem 3"<<endl;
        cout<<"Type 4 to solve problem 4"<<endl;
        cout<<"Type 5 to solve problem 6"<<endl;
        cout<<"Type 6 to solve problem 8"<<endl;
        cout<<"Type 7 to solve problem 12"<<endl;
        cout<<"Type 8 to solve problem 15"<<endl;
        cout<<"Type 9 to solve problem 17"<<endl;
        cout<<"Type 0 to solve problem 19"<<endl;
        cout<<"Type anything else to quit with no solutions."<<endl;
        //Read the choice
        char choice;
        cin>>choice;
        //Solve a problem that has been chosen.
        switch(choice){
                case '1':{//Problem 1: Rock Paper Scissors
                    //Declare Variables
                    //Inputs
                    char player1;//player 1 input for rock(R), paper(P), or scissors(S)
                    char player2;//player 2 input for rock(R), paper(P), or scissors(S)
                    
                    //Input Values
                    cout<<"Player 1, enter 'R' for rock, 'P' for paper, or 'S' for scissors"<<endl;
                    cin>>player1;
                    cout<<"Player 2, enter 'R' for rock, 'P' for paper, or 'S' for scissors"<<endl;
                    cin>>player2;
                    
                    //Determine Winner, or if a tie
                    switch(player1){
                        case 'R':
                        case 'r':
                            switch(player2){
                                case 'R':
                                case 'r':
                                    cout<<"Winner: Tie"<<endl;
                                    cout<<"Nobody Wins"<<endl;
                                    break;
                                case 'P':
                                case 'p':
                                    cout<<"Winner: Player 2"<<endl;
                                    cout<<"Paper covers Rock"<<endl;
                                    break;
                                case 'S':
                                case 's':
                                    cout<<"Winner: Player 1"<<endl;
                                    cout<<"Rock breaks Scissors"<<endl;
                                    break;
                                default:{
                                    cout<<"Invalid Input for Player 2"<<endl;
                                }
                            }
                            break;
                        case 'P':
                        case 'p':
                            switch(player2){
                                case 'R':
                                case 'r':
                                    cout<<"Winner: Player 1"<<endl;
                                    cout<<"Paper covers Rock"<<endl;
                                    break;
                                case 'P':
                                case 'p':
                                    cout<<"Winner: Tie"<<endl;
                                    cout<<"Nobody Wins"<<endl;
                                    break;
                                case 'S':
                                case 's':
                                    cout<<"Winner: Player 2"<<endl;
                                    cout<<"Scissors cut Paper"<<endl;
                                    break;
                                default:{
                                    cout<<"Invalid Input for Player 2"<<endl;
                                }
                            }
                            break;
                        case 'S':
                        case 's':
                            switch(player2){
                                case 'R':
                                case 'r':
                                    cout<<"Winner: Player 2"<<endl;
                                    cout<<"Rock breaks Scissors"<<endl;
                                    break;
                                case 'P':
                                case 'p':
                                    cout<<"Winner: Player 1"<<endl;
                                    cout<<"Scissors cut Paper"<<endl;
                                    break;
                                case 'S':
                                case 's':
                                    cout<<"Winner: Tie"<<endl;
                                    cout<<"Nobody Wins"<<endl;
                                    break;
                                default:{
                                    cout<<"Invalid Input for Player 2"<<endl;
                                }
                            }
                            break;
                        default:{
                            cout<<"Invalid Input for Player 1"<<endl;
                        }
                    }
                    
                    //Exit Stage Right!
                    break;
                }
                case '2':{//Problem 2: Interest with account rate schedules
                    //Declare Variables
                    //Inputs 
                    float account;            //Account balance in dollars
                    const float INTFIR=1.5e-2;//Interest for the first $1000
                    const float INTAFT=1e-2;  //Interest after the first $1000
                    //Outputs
                    float intdue;             //Interest due in dollars
                    float totdue;             //Total amount due in dollars
                    float revolve;            //Minimum payment for a revolving credit amount
                    
                    //Input Values
                    cout<<"Enter the Account Balance in dollars"<<endl;
                    cin>>account;
                    
                    //Calculations
                    //Calculate Interest due
                    if (account<=1000){
                        intdue=INTFIR*account;
                    }else{
                        intdue=INTFIR*1000+INTAFT*(account-1000);
                    }
                    //Calculate total amount due
                    totdue=intdue+account;
                    //Calculate minimum payment for a revolving credit amount
                    if (totdue<=10){
                        revolve=intdue;
                    }else{
                        if (1.0e-2*totdue>10){
                            revolve=1.0e-2*totdue;
                        }else{
                            revolve=10;
                        }
                    }
                    
                    //Output the results
                    cout<<fixed<<showpoint<<setprecision(2);
                    cout<<"Interest Due =    $"<<setw(9)<<intdue<<endl;
                    cout<<"Total Due =       $"<<setw(9)<<totdue<<endl;
                    cout<<"Minimum Payment = $"<<setw(9)<<revolve<<endl;
                    
                    //Exit Stage Right!
                    break;
                }
                case '3':{//Problem 3: Astrology Program
                    //Declare Variables
                    //Inputs
                    float month;//month of the birthday between 1 and 12
                    float day;  //day of the month between 1 and 31
                    
                    //Input Values
                    cout<<"Enter your birthday:"<<endl;
                    cout<<"First the month:(1-12)"<<endl;
                    cin>>month;
                    cout<<"Then the day:"<<endl;
                    cin>>day;
                    
                    //Determine the horoscope sign
                    if (month==1){
                        if (day>=18&&day<=19){
                            cout<<"Your Horoscope Sign: Capricorn"<<endl;
                            cout<<"Your birthday is also on a cusp to Aquarius"<<endl;
                        }else if (day>=1&&day<=17){
                            cout<<"Your Horoscope Sign: Capricorn"<<endl;
                        }else if (day>=20&&day<=21){
                            cout<<"Your Horoscope Sign: Aquarius"<<endl;
                            cout<<"Your birthday is also on a cusp to Capricorn"<<endl;
                        }else if (day>=21&&day<=31){
                            cout<<"Your Horoscope Sign: Aquarius"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 31"<<endl;
                        }
                    }else if (month==2){
                        if (day>=1&&day<=16){
                            cout<<"Your Horoscope Sign: Aquarius"<<endl;
                        }else if (day>=17&&day<=18){
                            cout<<"Your Horoscope Sign: Aquarius"<<endl;
                            cout<<"Your birthday is also on a cusp to Pisces"<<endl;
                        }else if (day>=19&&day<=20){
                            cout<<"Your Horoscope Sign: Pisces"<<endl;
                            cout<<"Your birthday is also on a cusp to Aquarius"<<endl;
                        }else if (day>=21&&day<=29){
                            cout<<"Your Horoscope Sign: Pisces"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 29"<<endl;
                        }
                    }else if (month==3){
                        if (day>=1&&day<=18){
                            cout<<"Your Horoscope Sign: Pisces"<<endl;
                        }else if (day>=19&&day<=20){
                            cout<<"Your Horoscope Sign: Pisces"<<endl;
                            cout<<"Your birthday is also on a cusp to Aries"<<endl;
                        }else if (day>=21&&day<=22){
                            cout<<"Your Horoscope Sign: Aries"<<endl;
                            cout<<"Your birthday is also on a cusp to Pisces"<<endl;
                        }else if (day>=23&&day<=31){
                            cout<<"Your Horoscope Sign: Aries"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 31"<<endl;
                        }
                    }else if (month==4){
                        if (day>=1&&day<=17){
                            cout<<"Your Horoscope Sign: Aries"<<endl;
                        }else if (day>=18&&day<=19){
                            cout<<"Your Horoscope Sign: Aries"<<endl;
                            cout<<"Your birthday is also on a cusp to Taurus"<<endl;
                        }else if (day>=20&&day<=21){
                            cout<<"Your Horoscope Sign: Taurus"<<endl;
                            cout<<"Your birthday is also on a cusp to Aries"<<endl;
                        }else if (day>=22&&day<=30){
                            cout<<"Your Horoscope Sign: Taurus"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 30"<<endl;
                        }
                    }else if (month==5){
                        if (day>=1&&day<=18){
                            cout<<"Your Horoscope Sign: Taurus"<<endl;
                        }else if (day>=19&&day<=20){
                            cout<<"Your Horoscope Sign: Taurus"<<endl;
                            cout<<"Your birthday is also on a cusp to Gemini"<<endl;
                        }else if (day>=21&&day<=22){
                            cout<<"Your Horoscope Sign: Gemini"<<endl;
                            cout<<"Your birthday is also on a cusp to Taurus"<<endl;
                        }else if (day>=23&&day<=31){
                            cout<<"Your Horoscope Sign: Gemini"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 31"<<endl;
                        }
                    }else if (month==6){
                        if (day>=1&&day<=19){
                            cout<<"Your Horoscope Sign: Gemini"<<endl;
                        }else if (day>=20&&day<=21){
                            cout<<"Your Horoscope Sign: Gemini"<<endl;
                            cout<<"Your birthday is also on a cusp to Cancer"<<endl;
                        }else if (day>=22&&day<=23){
                            cout<<"Your Horoscope Sign: Cancer"<<endl;
                            cout<<"Your birthday is also on a cusp to Gemini"<<endl;
                        }else if (day>=24&&day<=30){
                            cout<<"Your Horoscope Sign: Cancer"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 30"<<endl;
                        }
                    }else if (month==7){
                        if (day>=1&&day<=20){
                            cout<<"Your Horoscope Sign: Cancer"<<endl;
                        }else if (day>=21&&day<=22){
                            cout<<"Your Horoscope Sign: Cancer"<<endl;
                            cout<<"Your birthday is also on a cusp to Leo"<<endl;
                        }else if (day>=23&&day<=24){
                            cout<<"Your Horoscope Sign: Leo"<<endl;
                            cout<<"Your birthday is also on a cusp to Cancer"<<endl;
                        }else if (day>=25&&day<=31){
                            cout<<"Your Horoscope Sign: Leo"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 31"<<endl;
                        }
                    }else if (month==8){
                        if (day>=1&&day<=20){
                            cout<<"Your Horoscope Sign: Leo"<<endl;
                        }else if (day>=21&&day<=22){
                            cout<<"Your Horoscope Sign: Leo"<<endl;
                            cout<<"Your birthday is also on a cusp to Virgo"<<endl;
                        }else if (day>=23&&day<=24){
                            cout<<"Your Horoscope Sign: Virgo"<<endl;
                            cout<<"Your birthday is also on a cusp to Leo"<<endl;
                        }else if (day>=25&&day<=31){
                            cout<<"Your Horoscope Sign: Virgo"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 31"<<endl;
                        }
                    }else if (month==9){
                        if (day>=1&&day<=20){
                            cout<<"Your Horoscope Sign: Virgo"<<endl;
                        }else if (day>=21&&day<=22){
                            cout<<"Your Horoscope Sign: Virgo"<<endl;
                            cout<<"Your birthday is also on a cusp to Libra"<<endl;
                        }else if (day>=23&&day<=24){
                            cout<<"Your Horoscope Sign: Libra"<<endl;
                            cout<<"Your birthday is also on a cusp to Virgo"<<endl;
                        }else if (day>=25&&day<=30){
                            cout<<"Your Horoscope Sign: Libra"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 30"<<endl;
                        }
                    }else if (month==10){
                        if (day>=1&&day<=20){
                            cout<<"Your Horoscope Sign: Libra"<<endl;
                        }else if (day>=21&&day<=22){
                            cout<<"Your Horoscope Sign: Libra"<<endl;
                            cout<<"Your birthday is also on a cusp to Scorpio"<<endl;
                        }else if (day>=23&&day<=24){
                            cout<<"Your Horoscope Sign: Scorpio"<<endl;
                            cout<<"Your birthday is also on a cusp to Libra"<<endl;
                        }else if (day>=25&&day<=31){
                            cout<<"Your Horoscope Sign: Scorpio"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 31"<<endl;
                        }
                    }else if (month==11){
                        if (day>=1&&day<=19){
                            cout<<"Your Horoscope Sign: Scorpio"<<endl;
                        }else if (day>=20&&day<=21){
                            cout<<"Your Horoscope Sign: Scorpio"<<endl;
                            cout<<"Your birthday is also on a cusp to Sagittarius"<<endl;
                        }else if (day>=22&&day<=23){
                            cout<<"Your Horoscope Sign: Sagittarius"<<endl;
                            cout<<"Your birthday is also on a cusp to Scorpio"<<endl;
                        }else if (day>=24&&day<=30){
                            cout<<"Your Horoscope Sign: Sagittarius"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 30"<<endl;
                        }
                    }else if (month==12){
                        if (day>=1&&day<=19){
                            cout<<"Your Horoscope Sign: Sagittarius"<<endl;
                        }else if (day>=20&&day<=21){
                            cout<<"Your Horoscope Sign: Sagittarius"<<endl;
                            cout<<"Your birthday is also on a cusp to Capricorn"<<endl;
                        }else if (day>=22&&day<=23){
                            cout<<"Your Horoscope Sign: Capricorn"<<endl;
                            cout<<"Your birthday is also on a cusp to Sagittarius"<<endl;
                        }else if (day>=24&&day<=31){
                            cout<<"Your Horoscope Sign: Capricorn"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 31"<<endl;
                        }
                    }else{
                        cout<<"The month needs to imputed as a number between 1 and 12"<<endl;
                    }
                    
                    //Exit Stage Right!
                    break;
                }
                case '4':{//Problem 4: Astrology Program with compatability
                    //Declare Variables
                    //Inputs
                    float month;//month of the birthday between 1 and 12
                    float day;  //day of the month between 1 and 31
                    
                    //Input Values
                    cout<<"Enter your birthday:"<<endl;
                    cout<<"First the month:(1-12)"<<endl;
                    cin>>month;
                    cout<<"Then the day:"<<endl;
                    cin>>day;
                    
                    //Determine the horoscope sign
                    if (month==1){
                        if (day>=18&&day<=19){
                            cout<<"Your Horoscope Sign: Capricorn"<<endl;
                            cout<<"Your birthday is also on a cusp to Aquarius"<<endl;
                            cout<<"You are compatible with Taurus and Virgo"<<endl;
                        }else if (day>=1&&day<=17){
                            cout<<"Your Horoscope Sign: Capricorn"<<endl;
                            cout<<"You are compatible with Taurus and Virgo"<<endl;
                        }else if (day>=20&&day<=21){
                            cout<<"Your Horoscope Sign: Aquarius"<<endl;
                            cout<<"Your birthday is also on a cusp to Capricorn"<<endl;
                            cout<<"You are compatible with Gemini and Libra"<<endl;
                        }else if (day>=21&&day<=31){
                            cout<<"Your Horoscope Sign: Aquarius"<<endl;
                            cout<<"You are compatible with Gemini and Libra"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 31"<<endl;
                        }
                    }else if (month==2){
                        if (day>=1&&day<=16){
                            cout<<"Your Horoscope Sign: Aquarius"<<endl;
                            cout<<"You are compatible with Gemini and Libra"<<endl;
                        }else if (day>=17&&day<=18){
                            cout<<"Your Horoscope Sign: Aquarius"<<endl;
                            cout<<"Your birthday is also on a cusp to Pisces"<<endl;
                            cout<<"You are compatible with Gemini and Libra"<<endl;
                        }else if (day>=19&&day<=20){
                            cout<<"Your Horoscope Sign: Pisces"<<endl;
                            cout<<"Your birthday is also on a cusp to Aquarius"<<endl;
                            cout<<"You are compatible with Cancer and Scorpio"<<endl;
                        }else if (day>=21&&day<=29){
                            cout<<"Your Horoscope Sign: Pisces"<<endl;
                            cout<<"You are compatible with Cancer and Scorpio"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 29"<<endl;
                        }
                    }else if (month==3){
                        if (day>=1&&day<=18){
                            cout<<"Your Horoscope Sign: Pisces"<<endl;
                            cout<<"You are compatible with Cancer and Scorpio"<<endl;
                        }else if (day>=19&&day<=20){
                            cout<<"Your Horoscope Sign: Pisces"<<endl;
                            cout<<"Your birthday is also on a cusp to Aries"<<endl;
                            cout<<"You are compatible with Cancer and Scorpio"<<endl;
                        }else if (day>=21&&day<=22){
                            cout<<"Your Horoscope Sign: Aries"<<endl;
                            cout<<"Your birthday is also on a cusp to Pisces"<<endl;
                            cout<<"You are compatible with Leo and Sagittarius"<<endl;
                        }else if (day>=23&&day<=31){
                            cout<<"Your Horoscope Sign: Aries"<<endl;
                            cout<<"You are compatible with Leo and Sagittarius"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 31"<<endl;
                        }
                    }else if (month==4){
                        if (day>=1&&day<=17){
                            cout<<"Your Horoscope Sign: Aries"<<endl;
                            cout<<"You are compatible with Leo and Sagittarius"<<endl;
                        }else if (day>=18&&day<=19){
                            cout<<"Your Horoscope Sign: Aries"<<endl;
                            cout<<"Your birthday is also on a cusp to Taurus"<<endl;
                            cout<<"You are compatible with Leo and Sagittarius"<<endl;
                        }else if (day>=20&&day<=21){
                            cout<<"Your Horoscope Sign: Taurus"<<endl;
                            cout<<"Your birthday is also on a cusp to Aries"<<endl;
                            cout<<"You are compatible with Virgo and Capricorn"<<endl;
                        }else if (day>=22&&day<=30){
                            cout<<"Your Horoscope Sign: Taurus"<<endl;
                            cout<<"You are compatible with Virgo and Capricorn"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 30"<<endl;
                        }
                    }else if (month==5){
                        if (day>=1&&day<=18){
                            cout<<"Your Horoscope Sign: Taurus"<<endl;
                            cout<<"You are compatible with Virgo and Capricorn"<<endl;
                        }else if (day>=19&&day<=20){
                            cout<<"Your Horoscope Sign: Taurus"<<endl;
                            cout<<"Your birthday is also on a cusp to Gemini"<<endl;
                            cout<<"You are compatible with Virgo and Capricorn"<<endl;
                        }else if (day>=21&&day<=22){
                            cout<<"Your Horoscope Sign: Gemini"<<endl;
                            cout<<"Your birthday is also on a cusp to Taurus"<<endl;
                            cout<<"You are compatible with Libra and Aquarius"<<endl;
                        }else if (day>=23&&day<=31){
                            cout<<"Your Horoscope Sign: Gemini"<<endl;
                            cout<<"You are compatible with Libra and Aquarius"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 31"<<endl;
                        }
                    }else if (month==6){
                        if (day>=1&&day<=19){
                            cout<<"Your Horoscope Sign: Gemini"<<endl;
                            cout<<"You are compatible with Libra and Aquarius"<<endl;
                        }else if (day>=20&&day<=21){
                            cout<<"Your Horoscope Sign: Gemini"<<endl;
                            cout<<"Your birthday is also on a cusp to Cancer"<<endl;
                            cout<<"You are compatible with Libra and Aquarius"<<endl;
                        }else if (day>=22&&day<=23){
                            cout<<"Your Horoscope Sign: Cancer"<<endl;
                            cout<<"Your birthday is also on a cusp to Gemini"<<endl;
                            cout<<"You are compatible with Scorpio and Pisces"<<endl;
                        }else if (day>=24&&day<=30){
                            cout<<"Your Horoscope Sign: Cancer"<<endl;
                            cout<<"You are compatible with Scorpio and Pisces"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 30"<<endl;
                        }
                    }else if (month==7){
                        if (day>=1&&day<=20){
                            cout<<"Your Horoscope Sign: Cancer"<<endl;
                            cout<<"You are compatible with Scorpio and Pisces"<<endl;
                        }else if (day>=21&&day<=22){
                            cout<<"Your Horoscope Sign: Cancer"<<endl;
                            cout<<"Your birthday is also on a cusp to Leo"<<endl;
                            cout<<"You are compatible with Scorpio and Pisces"<<endl;
                        }else if (day>=23&&day<=24){
                            cout<<"Your Horoscope Sign: Leo"<<endl;
                            cout<<"Your birthday is also on a cusp to Cancer"<<endl;
                            cout<<"You are compatible with Aries and Sagittarius"<<endl;
                        }else if (day>=25&&day<=31){
                            cout<<"Your Horoscope Sign: Leo"<<endl;
                            cout<<"You are compatible with Aries and Sagittarius"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 31"<<endl;
                        }
                    }else if (month==8){
                        if (day>=1&&day<=20){
                            cout<<"Your Horoscope Sign: Leo"<<endl;
                            cout<<"You are compatible with Aries and Sagittarius"<<endl;
                        }else if (day>=21&&day<=22){
                            cout<<"Your Horoscope Sign: Leo"<<endl;
                            cout<<"Your birthday is also on a cusp to Virgo"<<endl;
                            cout<<"You are compatible with Aries and Sagittarius"<<endl;
                        }else if (day>=23&&day<=24){
                            cout<<"Your Horoscope Sign: Virgo"<<endl;
                            cout<<"Your birthday is also on a cusp to Leo"<<endl;
                            cout<<"You are compatible with Taurus and Capricorn"<<endl;
                        }else if (day>=25&&day<=31){
                            cout<<"Your Horoscope Sign: Virgo"<<endl;
                            cout<<"You are compatible with Taurus and Capricorn"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 31"<<endl;
                        }
                    }else if (month==9){
                        if (day>=1&&day<=20){
                            cout<<"Your Horoscope Sign: Virgo"<<endl;
                            cout<<"You are compatible with Taurus and Capricorn"<<endl;
                        }else if (day>=21&&day<=22){
                            cout<<"Your Horoscope Sign: Virgo"<<endl;
                            cout<<"Your birthday is also on a cusp to Libra"<<endl;
                            cout<<"You are compatible with Taurus and Capricorn"<<endl;
                        }else if (day>=23&&day<=24){
                            cout<<"Your Horoscope Sign: Libra"<<endl;
                            cout<<"Your birthday is also on a cusp to Virgo"<<endl;
                            cout<<"You are compatible with Gemini and Aquarius"<<endl;
                        }else if (day>=25&&day<=30){
                            cout<<"Your Horoscope Sign: Libra"<<endl;
                            cout<<"You are compatible with Gemini and Aquarius"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 30"<<endl;
                        }
                    }else if (month==10){
                        if (day>=1&&day<=20){
                            cout<<"Your Horoscope Sign: Libra"<<endl;
                            cout<<"You are compatible with Gemini and Aquarius"<<endl;
                        }else if (day>=21&&day<=22){
                            cout<<"Your Horoscope Sign: Libra"<<endl;
                            cout<<"Your birthday is also on a cusp to Scorpio"<<endl;
                            cout<<"You are compatible with Gemini and Aquarius"<<endl;
                        }else if (day>=23&&day<=24){
                            cout<<"Your Horoscope Sign: Scorpio"<<endl;
                            cout<<"Your birthday is also on a cusp to Libra"<<endl;
                            cout<<"You are compatible with Cancer and Pisces"<<endl;
                        }else if (day>=25&&day<=31){
                            cout<<"Your Horoscope Sign: Scorpio"<<endl;
                            cout<<"You are compatible with Cancer and Pisces"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 31"<<endl;
                        }
                    }else if (month==11){
                        if (day>=1&&day<=19){
                            cout<<"Your Horoscope Sign: Scorpio"<<endl;
                            cout<<"You are compatible with Cancer and Pisces"<<endl;
                        }else if (day>=20&&day<=21){
                            cout<<"Your Horoscope Sign: Scorpio"<<endl;
                            cout<<"Your birthday is also on a cusp to Sagittarius"<<endl;
                            cout<<"You are compatible with Cancer and Pisces"<<endl;
                        }else if (day>=22&&day<=23){
                            cout<<"Your Horoscope Sign: Sagittarius"<<endl;
                            cout<<"Your birthday is also on a cusp to Scorpio"<<endl;
                            cout<<"You are compatible with Aries and Leo"<<endl;
                        }else if (day>=24&&day<=30){
                            cout<<"Your Horoscope Sign: Sagittarius"<<endl;
                            cout<<"You are compatible with Aries and Leo"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 30"<<endl;
                        }
                    }else if (month==12){
                        if (day>=1&&day<=19){
                            cout<<"Your Horoscope Sign: Sagittarius"<<endl;
                            cout<<"You are compatible with Aries and Leo"<<endl;
                        }else if (day>=20&&day<=21){
                            cout<<"Your Horoscope Sign: Sagittarius"<<endl;
                            cout<<"Your birthday is also on a cusp to Capricorn"<<endl;
                            cout<<"You are compatible with Aries and Leo"<<endl;
                        }else if (day>=22&&day<=23){
                            cout<<"Your Horoscope Sign: Capricorn"<<endl;
                            cout<<"Your birthday is also on a cusp to Sagittarius"<<endl;
                            cout<<"You are compatible with Taurus and Virgo"<<endl;
                        }else if (day>=24&&day<=31){
                            cout<<"Your Horoscope Sign: Capricorn"<<endl;
                            cout<<"You are compatible with Taurus and Virgo"<<endl;
                        }else{
                            cout<<"The day needs to imputed as a number between 1 and 31"<<endl;
                        }
                    }else{
                        cout<<"The month needs to imputed as a number between 1 and 12"<<endl;
                    }
                    
                    //Exit Stage Right!
                    break;
                }
                case '5':{//Problem 6: Roots with Complex Numbers
                    //Declare Variables
                    //Inputs
                    float a;    //First root of the quadratic equation
                    float b;    //Second root of the quadratic equation
                    float c;    //Third root of the quadratic equation
                    //Outputs
                    float root1;//First root
                    float root2;//Second root
                    
                    //Input Values
                    cout<<"Enter the a, b, and c values for the"<<endl;
                    cout<<"quadratic equation ax^2 + bx + c = 0"<<endl;
                    cout<<"to find the roots"<<endl;
                    cin>>a>>b>>c;
                    
                    //Calculations
                    //Calculate the roots
                    if (a==0){
                        root1=-c/b;
                        root2=root1;
                    }else if ((b*b-4*a*c)==0){
                        root1=-b/(2*a);
                        root2=root1;
                    }else if ((b*b-4*a*c)<0){
                        float complex;//Complex number for the root
                        complex=(pow(-1*(b*b-4*a*c),0.5)/(2*a));
                        root1=-b/(2*a);
                        root2=-b/(2*a);
                        cout<<"First root  = "<<root1<<"+"<<complex<<"i"<<endl;
                        cout<<"Second root = "<<root2<<"-"<<complex<<"i"<<endl;
                    }else{
                        root1=((-b+pow((b*b-4*a*c),0.5)))/(2*a);
                        root2=((-b-pow((b*b-4*a*c),0.5)))/(2*a);
                    }
                    
                    //Output the Results
                    if ((b*b-4*a*c)>=0){
                        cout<<"first root  = "<<root1<<endl;
                        cout<<"Second root = "<<root2<<endl;
                    }
                    
                    //Exit Stage Right!
                    break;
                }
                
                case '6':{//Problem 8: Blackjack
                    //Declare Variables
                    //Inputs
                    char numcard;//Number of cards
                    char card1;  //Card 1 value
                    char card2;  //Card 2 value
                    char card3;  //Card 3 value
                    char card4;  //Card 4 value
                    char card5;  //Card 5 value
                    //Outputs
                    int c1val;   //Card 1 number value
                    int c2val;   //Card 2 number value
                    int c3val;   //Card 3 number value
                    int c4val;   //Card 4 number value
                    int c5val;   //Card 5 number value
                    int totval;  //Total value of all cards
                    
                    //Input Values
                    cout<<"Enter the number of cards between 2 and 5"<<endl;
                    cin>>numcard;
                    switch (numcard){
                        case '2':{
                            cout<<"Enter the value of the first card"<<endl;
                            cout<<"(Input 10 as 'T', Jack as 'J', Queen as 'Q',"<<endl;
                            cout<<"King as 'K', and Ace as 'A')"<<endl;
                            cin>>card1;
                            cout<<"Enter the value of the second card"<<endl;
                            cin>>card2;
                            c3val=0;
                            c4val=0;
                            c5val=0;
                            break;
                        }
                        case '3':{
                            cout<<"Enter the value of the first card"<<endl;
                            cout<<"(Input 10 as 'T', Jack as 'J', Queen as 'Q',"<<endl;
                            cout<<"King as 'K', and Ace as 'A')"<<endl;
                            cin>>card1;
                            cout<<"Enter the value of the second card"<<endl;
                            cin>>card2;
                            cout<<"Enter the value of the third card"<<endl;
                            cin>>card3;
                            c4val=0;
                            c5val=0;
                            break;
                        }
                        case '4':{
                            cout<<"Enter the value of the first card"<<endl;
                            cout<<"(Input 10 as 'T', Jack as 'J', Queen as 'Q',"<<endl;
                            cout<<"King as 'K', and Ace as 'A')"<<endl;
                            cin>>card1;
                            cout<<"Enter the value of the second card"<<endl;
                            cin>>card2;
                            cout<<"Enter the value of the third card"<<endl;
                            cin>>card3;
                            cout<<"Enter the value of the fourth card"<<endl;
                            cin>>card4;
                            c5val=0;
                            break;
                        }
                        case '5':{
                            cout<<"Enter the value of the first card"<<endl;
                            cout<<"(Input 10 as 'T', Jack as 'J', Queen as 'Q',"<<endl;
                            cout<<"King as 'K', and Ace as 'A')"<<endl;
                            cin>>card1;
                            cout<<"Enter the value of the second card"<<endl;
                            cin>>card2;
                            cout<<"Enter the value of the third card"<<endl;
                            cin>>card3;
                            cout<<"Enter the value of the fourth card"<<endl;
                            cin>>card4;
                            cout<<"Enter the value of the fifth card"<<endl;
                            cin>>card5;
                            break;
                        }
                        default:{
                            cout<<"You needed to enter a value of 2, 3, 4, or 5"<<endl;
                            break;
                        }
                    }
                    
                    //Calculations
                    //Calculate the value of each card
                    switch(card1){
                        case 'j':
                        case 'J':{
                            c1val=10;
                            break;
                        }
                        case 'q':
                        case 'Q':{
                            c1val=10;
                            break;
                        }
                        case 'k':
                        case 'K':{
                            c1val=10;
                            break;
                        }
                        case 'a':
                        case 'A':{
                            c1val=11;
                            break;
                        }
                        case '2':{
                            c1val=2;
                            break;
                        }
                        case '3':{
                            c1val=3;
                            break;
                        }
                        case '4':{
                            c1val=4;
                            break;
                        }
                        case '5':{
                            c1val=5;
                            break;
                        }
                        case '6':{
                            c1val=6;
                            break;
                        }
                        case '7':{
                            c1val=7;
                            break;
                        }
                        case '8':{
                            c1val=8;
                            break;
                        }
                        case '9':{
                            c1val=9;
                            break;
                        }
                        case 't':
                        case 'T':{
                            c1val=10;
                            break;
                        }
                        default:{
                            c1val=0;
                            break;
                        }
                    }
                    switch(card2){
                        case 'j':
                        case 'J':{
                            c2val=10;
                            break;
                        }
                        case 'q':
                        case 'Q':{
                            c2val=10;
                            break;
                        }
                        case 'k':
                        case 'K':{
                            c2val=10;
                            break;
                        }
                        case 'a':
                        case 'A':{
                            c2val=11;
                            break;
                        }
                        case '2':{
                            c2val=2;
                            break;
                        }
                        case '3':{
                            c2val=3;
                            break;
                        }
                        case '4':{
                            c2val=4;
                            break;
                        }
                        case '5':{
                            c2val=5;
                            break;
                        }
                        case '6':{
                            c2val=6;
                            break;
                        }
                        case '7':{
                            c2val=7;
                            break;
                        }
                        case '8':{
                            c2val=8;
                            break;
                        }
                        case '9':{
                            c2val=9;
                            break;
                        }
                        case 't':
                        case 'T':{
                            c2val=10;
                            break;
                        }
                        default:{
                            c2val=0;
                            break;
                        }
                    }
                    switch(card3){
                        case 'j':
                        case 'J':{
                            c3val=10;
                            break;
                        }
                        case 'q':
                        case 'Q':{
                            c3val=10;
                            break;
                        }
                        case 'k':
                        case 'K':{
                            c3val=10;
                            break;
                        }
                        case 'a':
                        case 'A':{
                            c3val=11;
                            break;
                        }
                        case '2':{
                            c3val=2;
                            break;
                        }
                        case '3':{
                            c3val=3;
                            break;
                        }
                        case '4':{
                            c3val=4;
                            break;
                        }
                        case '5':{
                            c3val=5;
                            break;
                        }
                        case '6':{
                            c3val=6;
                            break;
                        }
                        case '7':{
                            c3val=7;
                            break;
                        }
                        case '8':{
                            c3val=8;
                            break;
                        }
                        case '9':{
                            c3val=9;
                            break;
                        }
                        case 't':
                        case 'T':{
                            c3val=10;
                            break;
                        }
                        default:{
                            c3val=0;
                            break;
                        }
                    }
                    switch(card4){
                        case 'j':
                        case 'J':{
                            c4val=10;
                            break;
                        }
                        case 'q':
                        case 'Q':{
                            c4val=10;
                            break;
                        }
                        case 'k':
                        case 'K':{
                            c4val=10;
                            break;
                        }
                        case 'a':
                        case 'A':{
                            c4val=11;
                            break;
                        }
                        case '2':{
                            c4val=2;
                            break;
                        }
                        case '3':{
                            c4val=3;
                            break;
                        }
                        case '4':{
                            c4val=4;
                            break;
                        }
                        case '5':{
                            c4val=5;
                            break;
                        }
                        case '6':{
                            c4val=6;
                            break;
                        }
                        case '7':{
                            c4val=7;
                            break;
                        }
                        case '8':{
                            c4val=8;
                            break;
                        }
                        case '9':{
                            c4val=9;
                            break;
                        }
                        case 't':
                        case 'T':{
                            c4val=10;
                            break;
                        }
                        default:{
                            c4val=0;
                            break;
                        }
                    }
                    switch(card5){
                        case 'j':
                        case 'J':{
                            c5val=10;
                            break;
                        }
                        case 'q':
                        case 'Q':{
                            c5val=10;
                            break;
                        }
                        case 'k':
                        case 'K':{
                            c5val=10;
                            break;
                        }
                        case 'a':
                        case 'A':{
                            c5val=11;
                            break;
                        }
                        case '2':{
                            c5val=2;
                            break;
                        }
                        case '3':{
                            c5val=3;
                            break;
                        }
                        case '4':{
                            c5val=4;
                            break;
                        }
                        case '5':{
                            c5val=5;
                            break;
                        }
                        case '6':{
                            c5val=6;
                            break;
                        }
                        case '7':{
                            c5val=7;
                            break;
                        }
                        case '8':{
                            c5val=8;
                            break;
                        }
                        case '9':{
                            c5val=9;
                            break;
                        }
                        case 't':
                        case 'T':{
                            c5val=10;
                            break;
                        }
                        default:{
                            c5val=0;
                            break;
                        }
                    }
                    
                    //Calculate and Output the Results
                    if ((c1val+c2val+c3val+c4val+c5val)>=22){
                        if (c1val==11){
                            c1val=1;
                            totval=c1val+c2val+c3val+c4val+c5val;
                            if (totval<22){
                                cout<<"The total value of your cards is "<<totval<<endl;
                            }
                        }else if (c2val==11){
                            c2val=1;
                            totval=c1val+1+c3val+c4val+c5val;
                            if (totval<22){
                                cout<<"The total value of your cards is "<<totval<<endl;
                            }
                        }else if (c3val==11){
                            c3val=1;
                            totval=c1val+c2val+1+c4val+c5val;
                            if (totval<22){
                                cout<<"The total value of your cards is "<<totval<<endl;
                            }
                        }else if (c4val==11){
                            c4val=1;
                            totval=c1val+c2val+c3val+1+c5val;
                            if (totval<22){
                                cout<<"The total value of your cards is "<<totval<<endl;
                            }
                        }else if (c5val==11){
                            c5val=1;
                            totval=c1val+c2val+c3val+c4val+1;
                            if (totval<22){
                                cout<<"The total value of your cards is "<<totval<<endl;
                            }
                        }else{
                        cout<<"You have busted!"<<endl;
                        }
                    }
                    else{
                        totval=c1val+c2val+c3val+c4val+c5val;
                        cout<<"The total value of your cards is "<<totval<<endl;
                    }
                    
                    //Exit Stage Right!
                    break;
                }
                case '7':{//Problem 12:Pi
                    //Declare Variables
                    //Inputs 
                    int n;   //number of terms in the approximation
                    //Outputs
                    float pi;//Approximated value of pi
                    
                    //Input Values
                    cout<<"Enter the number of terms for the approximation of pi"<<endl;
                    cin>>n;
                    
                    //Calculations
                    //Calculate pi
                    float sum=0;
                    for(unsigned int i=0;i<=n;i++){
                        sum+=((pow(-1,i))/(2*static_cast<float>(i)+1));
                    }
                    pi=4*sum;
                    
                    //Output the results
                    cout<<"Pi Approximation = "<<pi<<endl;
                    
                    //Exit Stage Right!
                    break;
                }
                case '8':{//Problem 15: Buoyancy
                    //Declare Variables
                    //Inputs 
                    float weight;          //Weight of the sphere in pounds
                    float radius;          //Radius of the sphere in feet
                    const float GAMMA=62.4;//Specific weight of water in pounds per feet cubed
                    //Outputs
                    float volume;          //Volume of sphere in feet cubed
                    float fb;              //Buoyant force in pounds
                    
                    //Input Values
                    cout<<"Enter the weight of the sphere in pounds"<<endl;
                    cin>>weight;
                    cout<<"Enter the radius of the sphere in feet"<<endl;
                    cin>>radius;
                    
                    //Calculations
                    //Calculate the volume of the sphere
                    volume=(4/3)*3.14159*radius*radius*radius;
                    //Calculate the buoyant force
                    fb=volume*GAMMA;
                    
                    //Output the results
                    if (fb>=weight){
                        cout<<"The sphere will float in water"<<endl;
                    }else{
                        cout<<"The sphere will sink in water"<<endl;
                    }
                    
                    //Exit Stage Right!
                    break;
                }
                case '9':{//Problem 17: Project 18, Candy Bars v.2.0
                    //Declare Variables
                    //Inputs 
                    unsigned short barcal=230;//Number of calories in a candy bar
                    unsigned short weight;    //weight in pounds
                    unsigned short age;       //Age in years
                    unsigned short height;    //Height in inches
                    char sex;                 //Male or Female
                    char active;                 //Activity level
                    //Outputs
                    float bmr;                //Basal Metabolic Rate
                    float numbar;             //Number of candy bars to maintain weight
                    
                    //Input Values
                    cout<<"Enter your sex: 'M' for Male or 'F' for Female"<<endl;
                    cin>>sex;
                    cout<<"Enter your weight in pounds:"<<endl;
                    cin>>weight;
                    cout<<"Enter your height in inches:"<<endl;
                    cin>>height;
                    cout<<"Enter your age in years:"<<endl;
                    cin>>age;
                    cout<<"Enter your level of activeness"<<endl;
                    cout<<"a. Sedentary"<<endl;
                    cout<<"b. Somewhat Active (exercise occasionally)"<<endl;
                    cout<<"c. Active (exercise 3-4 days per week)"<<endl;
                    cout<<"d. Highly Active (exercise every day)"<<endl;
                    cin>>active;
                    
                    //Calculations
                    if (sex=='F'||sex=='f'){
                        switch (active){
                            case 'a':
                            case 'A':{
                                bmr=(1+20e-2f)*(6.55e2f+4.3e0f*weight+4.7e0f*height-4.7e0f*age);
                                break;
                            }
                            case 'b':
                            case 'B':{
                                bmr=(1+30e-2f)*(6.55e2f+4.3e0f*weight+4.7e0f*height-4.7e0f*age);
                                break;
                            }
                            case 'c':
                            case 'C':{
                                bmr=(1+40e-2f)*(6.55e2f+4.3e0f*weight+4.7e0f*height-4.7e0f*age);
                                break;
                            }
                            case 'd':
                            case 'D':{
                                bmr=(1+50e-2f)*(6.55e2f+4.3e0f*weight+4.7e0f*height-4.7e0f*age);
                                break;
                            }
                            default:{
                                cout<<"You needed to enter a, b, c, or d"<<endl;
                                break;
                            }
                        }
                    }else if (sex=='M'||sex=='m'){
                        switch (active){
                            case 'a':
                            case 'A':{
                                bmr=(1+20e-2f)*(6.6e1f+6.3e0f*weight+1.29e1f*height-6.8e0f*age);
                                break;
                            }
                            case 'b':
                            case 'B':{
                                bmr=(1+30e-2f)*(6.6e1f+6.3e0f*weight+1.29e1f*height-6.8e0f*age);
                                break;
                            }
                            case 'c':
                            case 'C':{
                                bmr=(1+40e-2f)*(6.6e1f+6.3e0f*weight+1.29e1f*height-6.8e0f*age);
                                break;
                            }
                            case 'd':
                            case 'D':{
                                bmr=(1+50e-2f)*(6.6e1f+6.3e0f*weight+1.29e1f*height-6.8e0f*age);
                                break;
                            }
                            default:{
                                cout<<"You needed to enter a, b, c, or d"<<endl;
                                break;
                            }
                        }
                    }else{
                        cout<<"You needed to enter 'M' for Male or 'F' for Female"<<endl;
                    }
                    numbar=bmr/barcal;
                    
                    //Output the results
                    if (sex=='F'||sex=='f'||sex=='M'||sex=='m'){
                        cout<<"Your BMR = "<<bmr<<endl;
                        cout<<"Number of candy bars to consume to maintain"<<endl;
                        cout<<"current body weight = "<<numbar<<endl;
                    }else{
                        cout<<"No calculations were possible"<<endl;
                    }
                    //Exit Stage Right!
                    break;
                }
                case '0':{//Problem 19: Game of 23
                    //Declare Variables
                    //Inputs 
                    unsigned short picks=23;//Number of toothpicks left(23 at the beginning of game)
                    unsigned short player;        //Player input for picking up toothpicks
                    unsigned short comp;          //Computer input for picking up toothpicks
                    
                    //Game Loop Begins here
                    cout<<"---Game of 23---"<<endl;
                    
                    while (picks>0){
                        cout<<"Enter number of toothpicks to pick up:"<<endl;
                        cout<<"You must pick up 1-3 toothpicks"<<endl;
                        cin>>player;
                        if (player<1||player>3){
                            cout<<"CHEATER!!"<<endl;
                            cout<<"Computer made you pick up 3 toothpicks";
                            picks=picks-3;      
                        }else{
                            picks=picks-player;    
                        }
                        if (picks<=0){
                            cout<<"LOSER!"<<endl;
                            cout<<"Computer Wins"<<endl;
                        }else if (picks>4){
                            comp=4-player;
                            cout<<"Computer picks up "<<comp<<" toothpicks"<<endl;
                            picks=picks-comp;
                            cout<<"There are "<<picks<<" remaining"<<endl;
                        }else if (picks>=2&&picks<=4){
                            comp=picks-1;
                            cout<<"Computer picks up "<<comp<<" toothpicks"<<endl;
                            picks=picks-comp;
                            cout<<"There are "<<picks<<" remaining"<<endl;
                        }else{
                            comp=1;
                            picks=picks-comp;
                            cout<<"Computer picks up "<<comp<<" toothpicks"<<endl;
                            cout<<"WINNER!"<<endl;
                            cout<<"Player Wins"<<endl;
                        }
                    }
                    
                    //Exit Stage Right!
                    break;
                }
                default:{
                        cout<<"Exit?"<<endl;
                        loop=false;
                        break;
                }
        };
    }while(loop);//Upper do-while
    return 0;
}

