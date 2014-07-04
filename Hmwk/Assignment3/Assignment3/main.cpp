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
        cout<<"Type 1 to solve problem 1"<<endl;
        cout<<"Type 2 to solve problem 2"<<endl;
        cout<<"Type 3 to solve problem 3"<<endl;
        cout<<"Type 4 to solve problem 6"<<endl;
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
                case '4':{//Problem 6: Roots with Complex Numbers
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
                default:{
                        cout<<"Exit?"<<endl;
                        loop=false;
                        break;
                }
        };
    }while(loop);//Upper do-while
    return 0;
}

