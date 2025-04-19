#include <iostream>
#include <sstream>
#include <string>

int main(){
	std::string json = R"({"name":"Alice", "age":30, "isStudent":false})";
	std::istringstream iss(json);
	
	std::string temp, name, key;
	int age;
	std::string isStudent;
	
	getline(iss, temp, '{');

	getline(iss, key, ':');
	getline(iss, temp, '"');
	getline(iss, name, '"');

	getline(iss, key, ':');
	iss >> age;

	getline(iss, key, ':');
	getline(iss, isStudent, '}');

	std::cout << "Name: " << name << "\n";
	std::cout << "Age: " << age << "\n";
	std::cout << "Is Student: " << isStudent  << "\n";
}
