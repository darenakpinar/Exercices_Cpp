#include <iostream>
#include <fstream>
#include <string>

int main(){

    std::ofstream outFile("example.txt", std::ios::app);
    if (outFile.is_open())
    {
       outFile << "Appending a new line to existing file !\n";
       outFile.close();
       std::cout << "Data appended succecfully." << std::endl;
    }else{
        
        std::cout << "Error while oppenning file !" << std::endl;

    }
    return 0;
    
}