#include <iostream>
#include <fstream>
#include <string>

int main(){
	double balance = 0.0;
	int choice;
	
	do{
		std::cout << "\n--- Bank Account ---\n";
		std
		std::cout << "1. Deposit money\n";
		std::cout << "2. Withdraw money\n";
		std::cout << "3. Show balance\n";
		std::cout << "4. Exit\n";
		std::cin >>choice;
	
	  if (std::cin.fail()){
		std::cout << "Invalid input. Try again.\n";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		continue;
	}

	switch(choice){
		case 1: {
			double amount;
			std::cout << "Amount to deposit: ";
			std::cin >> amount;
			if (amount <= 0){
				std::cout << "Invalid deposit amount!\n";
			}else {
				balance += amount;
				std::cout << "Deposited: " << amount << "\n";
			}
			break;
		 }
		case 2: {
			double amount;
			std:: cout << "Amount to withdraw: "'
			std:: cin>> amount;
			if (amount <= 0 || amount < balance){
				std::cout << "Invalid withdraw amount!\n";
			}else{
				balance -= amount;
				std::cout "Deposited: " << amount << "\n";
			}
			break;
		}
	 
		case 3: {
			std::cout << "Account Balance: " << balance << std::endl;
		}
// enhance this code with the i/o save file!!
