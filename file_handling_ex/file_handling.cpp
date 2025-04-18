#include <iostrem>
#include <fstream>  // ofstream ifstream fstream

int main(){

    std::ofstream outFile("example.txt"); // Create and open file
    if (outFile.if_open()){
        outFile << "Hello this is a test file.\n";
        outFile << "Writing to a file C++ is easy!";
        outFile.close(); //close the file
        std::cout << " Data written succesfully!";

    }else{

        std::cout<< "Error opening file !" << std::endl;
    }
    return 0;
}


