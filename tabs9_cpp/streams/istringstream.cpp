#include <iostream>
#include <sstream>

int main(){
	std::string input = "123 45.67 Hello";
	std::istringstream iss(input); // reads from "input" string

	int number;
	double decimal;
	std::string word;

	iss >> number >> decimal >> word;

	std::cout << "Integer: " << number << std::endl;
	std::cout << "Double: " << decimal << std::endl;
	std::cout << "Word: " << word << std::endl;
}
