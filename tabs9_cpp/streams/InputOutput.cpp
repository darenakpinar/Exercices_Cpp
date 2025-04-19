#include <iostream>

int main(){
	int age;
	std::cout << "Enter your age: ";
	std::cin >> age;
	
	if (std::cin.fail()) {
		std::cout << "Input error: not a number!" << std::endl;
	}else{
		std::cout << "you are" << age << "years old." << std::endl;

	}
}

