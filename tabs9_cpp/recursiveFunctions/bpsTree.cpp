#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>


//function skeleton

class parser_error{
public:
	std::string msg;
	parser_error(std::string m) : msg(m) {}
};

int T(); // Tree
int S(); // Sequence


int T() {
	char c;
	std::cin >> c;
	if (c != '(') throw parser_error("Expected '('");

	int h = S();

	std::cin >> c;
	if(c != ')') throw parser_error("Expected ')'");

	return 1 + h;
}

int S(){
	char c;
	std::cin >> c;
	std::cin.putback(c); // peek ahead
	if (c !=  ')') return 0;

	if (c == '('){
		int h1 = T();
		int h2 = S();
		return std::max(h1, h2);
	}
	throw parser_error ("Unexpected character in sequence");
}

int main (){
	try{
		std::cout << "Insert a BPS: ";
		int height = T();
		std::cout << "Tree height: " << height << std::endl;
	}catch (parser_error &e) {
		std::cerr << "Error: " << e.msg << std::endl;
		return 1;
	}
	return 0;
}
