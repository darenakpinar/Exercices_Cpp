#include <iostream>
#include <fstream>
#include <string>

double load_balance(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cout << "No previous balance found. Starting at 0.\n";
        return 0.0; // default balance
    }
    double balance;
    infile >> balance;
    return balance;
}

void save_balance(const std::string& filename, double balance) {
    std::ofstream outfile(filename);
    if (!outfile) {
        std::cerr << "Error saving balance!\n";
        return;
    }
    outfile << balance;
}

int main() {
    const std::string filename = "balance.txt";
    double balance = load_balance(filename);
    int choice;

    do {
        std::cout << "\n--- Bank Account ---\n";
        std::cout << "1. Deposit money\n";
        std::cout << "2. Withdraw money\n";
        std::cout << "3. Show balance\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Try again.\n";
            std::cin.clear(); 
            std::cin.ignore(1000, '\n');
            continue; 
        }

        switch (choice) {
            case 1: {
                double amount;
                std::cout << "Amount to deposit: ";
                std::cin >> amount;
                if (amount <= 0) {
                    std::cout << "Invalid deposit amount!\n";
                } else {
                    balance += amount;
                    save_balance(filename, balance);  // save after deposit
                    std::cout << "Deposited: " << amount << "\n";
                }
                break;
            }
            case 2: {
                double amount;
                std::cout << "Amount to withdraw: ";
                std::cin >> amount;
                if (amount <= 0 || amount > balance) {
                    std::cout << "Invalid or insufficient balance!\n";
                } else {
                    balance -= amount;
                    save_balance(filename, balance);  // save after withdrawal
                    std::cout << "Withdrew: " << amount << "\n";
                }
                break;
            }
            case 3: {
                std::cout << "Current balance: " << balance << "\n";
                break;
            }
            case 4: {
                save_balance(filename, balance);  // save before exiting
                std::cout << "Balance saved. Goodbye!\n";
                break;
            }
            default:
                std::cout << "Invalid option!\n";
                break;
        }
    } while (choice != 4);
}

