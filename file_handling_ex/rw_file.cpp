#include <iostream>
#include <fstream>

int main() {
    std::ofstream outFile("example.txt"); // Create and open a file
    if (outFile.is_open()) {
        outFile << "Hello, this is a test file.\n";
        outFile << "Writing to a file in C++ is easy!";
        outFile.close(); // Close the file
        std::cout << "Data written successfully!" << std::endl;
    } else {
        std::cout << "Error opening file!" << std::endl;
    }
    return 0;
}
