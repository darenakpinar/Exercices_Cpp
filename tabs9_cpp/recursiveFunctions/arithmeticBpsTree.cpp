#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

class parser_error {
public:
	std::string msg;
	parser_error(std::string m) : msg(m) {}
};

double E(); // Expression
double S(char op) // Sequence


double E(){
	char c;
	std::cin>>c;
	if (c != "(")throw parser_error("Expected '('");

	int h = S();

	if (


int main() {
	try {
		
