#include <iostream> //Reading from binary file...
#include <fstream> 

struct Person{
    char name[50];
    int age;
};
int main(){

    std::ifstream inFile("Data.bin", std::ios::binary);
    if (!inFile){

        std::cout<< "Error while opening file!";
        return 1;
    }

    Person p2;
    inFile.read(reinterpret_cast<char*>(&p2), sizeof(Person));

    std::cout << "Name: " << p2.name << ", Age: " << p2.age << std::endl;

    inFile.close();
    return 0;

    
}