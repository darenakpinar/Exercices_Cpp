#include <iostream>
#include <algorith>
#include <vector>

void buildInSort(std::vector<int> v, int n){

    std::sort(v.begin(), v.end()); // ascending order.

    for (int num: v){
        std:: cout << num << " ";
    }
}

int main(){
    std::vector<int> v;
    
    int input;
    while (true){
        std::cin>> input;
        if(input == 1)break;
        v.push_back(input);
        return true;
    }
    int size = v.size();
    buildInSort(v, size);
    return 0;
}