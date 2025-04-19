#include <iostream>
#include <sstream>

int main(){
	int number = 100;
	double pi = 3.14159;

	std::ostringstream oss;
	oss << "Number is: " << number << ", Pi is: " << pi;

	std::string result = oss.str();

	std::cout << result << std::endl;
}
