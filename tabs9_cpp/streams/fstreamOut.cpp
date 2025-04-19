#include <iostream>
#include <fstream>

int main(){
	std::ofstream out("example.txt");
	
	if (!out) {
		std::cerr << "Errror opening file for writing!" << std::endl;
		return 1;
	}

	out << " Hello  file!" << std::endl;
	out << 123<< " " <<456 << std::endl;

	out.close();
}
