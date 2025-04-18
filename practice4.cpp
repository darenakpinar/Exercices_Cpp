#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

	int number, guess, attempts = 0;


	srand(time(0));
	number = rand() % 100 + 1;

	cout << "Welcome to the Number Guessing game!: " << endl;
	cout << "I have selected a number between 1 and 100. Can you guess it? " << endl;

	do{

		cout << "Enter your guess: ";
		cin >> guess;
		attempts++;

		if (guess < number){

			cout << "Too low! try again." << endl;
		}else if (guess > number){

			cout << " Too high! try again." << endl;

		}else{
			cout << "Congrutulations! You found the number in " << attempts << " attempts!" << endl;
		}
	
	}while (guess != number);

	return 0;
}