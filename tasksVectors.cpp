#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<std::string> tasks;
    int input;

    std::cout << "For Remove the last task (0) | For View The Tasks (2) } For Exit (-1)" << std::endl;
    while (std::cin >> input && input != -1){
            std::cin>> tasks.push_back();
            if (input == 0){
                tasks.pop_back();
            }
            if (input == 2){
                for(int task : tasks){
                    std::cout << tasks[task] << std::endl;
                }
            }
        
    }
    return 0;
}