#include<iostream>
#include<ctime>
using namespace std;

int main(){
    srand(time(0));//Statement used to change the random number

    bool playAgain=true;
    while(playAgain){
    int random_num=rand()%100+1;//Genarating random number
    int guess=0;
    int attempt=0;
    cout<<"*********WELCOME TO NUMBER GUESSING GAME**********"<<endl;
    string name;
    cout<<"Enter Your Name: ";
    getline(cin,name);
    cout<<name<<", Let's play the game."<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"Hints:Guess a number in range of 1 to 100"<<endl;
    cout<<endl;
    do{
        attempt++;
        cout<<"Enter your guess"<<endl;
        cin>>guess;
        if(guess==random_num){
            if(attempt==0){
            cout<<"Congrats "<<name<<", You guess the right number in the first attempt. "<<endl;
            }
            else{
            cout<<"Congrats "<<name <<", You guess the right number after "<<attempt<<" attempt."<<endl;
            }
        }
        else if(guess>random_num){
            cout<<"Wrong guesss!! You entered a higher number."<<endl;
            cout<<"Try again!!"<<endl;
        }
        else{
             cout<<"Wrong guesss!! You entered a lower number."<<endl;
             cout<<"Try again!!"<<endl;
        }

    }while(guess!=random_num);

     char playChoice;
        cout << "Do you want to play again? (Y/N): ";
        cin >> playChoice;
        if (playChoice != 'Y' && playChoice != 'y') {
            cout<<"Thanks for Playing"<<endl;
            playAgain = false; // Exit the game loop
        }
        cin.ignore(); // Clear the input buffer
}

    return 0;
}
