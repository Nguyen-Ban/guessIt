#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int inIt(){
    return rand() % 10 + 1;
}

int playerNumber(){
    int guess;
    cout << "Enter your number : ";
    cin >> guess;
    return guess;
}

void check(int guess, int secretNumber){
    if(guess > secretNumber){
        cout << "The number is smaller\n";
    }
    else if(guess < secretNumber){
        cout << "The number is bigger\n";
    }
    else cout << "You're correct\n";
}

void playGuessIt(int &point){
    srand(time(0));
    int secretNumber = inIt();
    int guess;
    do{
        guess = playerNumber();
        check(guess, secretNumber);
        cout << endl;
        if(guess != secretNumber){
                cout << " Your point : " << --point <<endl;
        }
        if(point ==0){
            cout << "You're fail";
            break;
        }
	}while(guess != secretNumber);
}

int main(){

    int point = 10;
	string myAnswer;

	playGuessIt(point);

	do{
        cout << "Do you want to continue playing(Y/N)?\n";
        cin >> myAnswer;
        if(myAnswer == "Y"){
            playGuessIt(point);
        }
	}while(myAnswer == "Y");

	return 0;
}
