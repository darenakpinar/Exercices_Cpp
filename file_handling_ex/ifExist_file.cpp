#include <iostream>
#include <fstream>
#include <string>

bool fileExists(const std:: string& filename){
    std::ifstream file(filename);
    return file.good();
}

int main (){

    std::string filename = "example.txt";
    if (fileExists(filename)){
        std::cout << "File exists!" << std:: endl;
    }else{
        std::cout << "File does not exists!" << std::endl;
    }
    return 0;
}