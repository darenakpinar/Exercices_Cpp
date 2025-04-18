#include <iostream>
#include <fstream>

int main(){
    std::ifstream infile("example.txt");
        if(!infile){

            std::cout << "Error while opening the file!" << std::endl;
            return 1;
        }
        infile.seekg(10, std::ios::beg); // Move to the 10th byte from the start
        char ch;
        infile.get(ch); // Read a character at position 10
        std::cout << "Character at position 10: " << ch << std::endl;

        std::cout <<"Current position: " << infile.tellg() << std::endl;

        infile.close();
        return 0;

}
