#include <iostream>
#include <fstream>
#include <string>

int main (){

    std::ifstream inFile("example.txt");
    if (inFile.is_open()){

        std::string line;
        while (getline(inFile, line)){
            std::cout<< line<<std::endl;
        }
        inFile.close();
    }else{

        std::cout << "Error while oppenning the file!" <<std::endl; 
    }
    return 0;
}