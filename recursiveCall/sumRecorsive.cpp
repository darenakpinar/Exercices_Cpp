#include <iostream>

int sumOfAll(int n){
    if (n <= 0) return 0;
    return n + sumOfAll(n-1);
}
int main(){

    int result = sumOfAll(3);
    std::cout<<result<<std::endl;
    return 0;
}