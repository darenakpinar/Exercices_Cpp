#include <iostream>
#include <fstream>
#include <string>

int main(){
	std::ifstream in("example.txt");
	
	if (!in) {
		std::cerr << "Error opening file for reading! " << std::endl;
		return 1;
	}
	
	std::string line;
	while (std::getline(in, line )){
		std::cout << line <<std::endl;
	}
	
	in.close();
}
