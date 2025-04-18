#include <iostream>
#include <algorithm>
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
    while (input != 1){
        std::cin>> input;
        
        v.push_back(input);
        
    }
    int size = v.size();
    buildInSort(v, size);
    return 0;
}