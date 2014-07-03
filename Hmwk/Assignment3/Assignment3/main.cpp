/* Assignment 3: Savitch Chapter 3
 * File:   main.cpp
 * Author: Daniel Boebinger
 * Created on July 3, 2014, 11:55 AM
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //General Menu Format
    bool loop=true;
    do{
        //Display the selection
        cout<<"Type 1 to solve problem 1"<<endl;
        cout<<"Type 2 to solve problem 2"<<endl;
        cout<<"Type 3 to solve problem 3"<<endl;
        cout<<"Type 4 to solve problem 3 again"<<endl;
        cout<<"Type anything else to quit with no solutions."<<endl;
        //Read the choice
        char choice;
        cin>>choice;
        //Solve a problem that has been chosen.
        switch(choice){
                case '1':{
                    int sum=0;
                    for(int num=1;num<=10;num++){
                        sum+=num;
                    }
                    cout<<endl;
                    cout<<"Solution to 1 for-loop, sum(1->10)="<<sum<<endl;
                    cout<<endl;
                    break;
                }
                case '2':{
                    int sum=0,num=1;
                    while(num<=10){
                        sum+=num++;
                    }
                    cout<<endl;
                    cout<<"Solution to 2 While-loop, sum(1->10)="<<sum<<endl;
                    cout<<endl;
                    break;
                }
                case '3':{
                    int sum=0,num=1;
                    do{
                        sum+=num++;
                    }while(num<=10);
                    cout<<endl;
                    cout<<"Solution to 3 Do-While-loop, sum(1->10)="<<sum<<endl;
                    cout<<endl;
                    break;
                }
                case '4':{
                    int sum=0,num=1;
                    do{
                        sum+=num++;
                    }while(num<=10);
                    cout<<endl;
                    cout<<"Solution to 3 Do-While-loop, sum(1->10)="<<sum<<endl;
                    cout<<endl;
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

