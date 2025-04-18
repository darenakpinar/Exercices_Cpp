#include <iostream>
#include <vector>

int main(){

    std::vector<int> v = {1, 2, 3, 4, 5};

    std::cout << "Vectors elements: ";
    for (int i = 0; i < 5; i++){
        std::cout <<v[i] << " " ;
    }
    std::cout << std::endl;
    return 0;
}