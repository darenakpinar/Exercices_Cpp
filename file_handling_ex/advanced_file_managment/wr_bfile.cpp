#include <iostream>
#include <fstream>

struct Person{
    char name[50];
    int age;
};

int main(){

    std::ofstream outFile("Data.bin", std::ios::binary);
    if(!outFile){
        std::cout << "Error oppening file!" << std::endl;
        return 1;
    }

    Person p1 = {"Alice", 25};
    outFile.write(reinterpret_cast<char*>(&p1), sizeof(Person));
    outFile.close();
    
    std::cout << "Binary data written succesfully !" << std::endl;
    return 0;
}