#include <iostream>
#include <cassert>

int greatestCommonDevider(int a, int b){

    if (a == 0)return b; // base case 
    
    return greatestCommonDevider( b % a, a);
    // return greatestCommonDevider(b % a, a);
}
int main(){

    std::cout << greatestCommonDevider(3, 4) << std::endl;
   // std::cout << greatestCommonDevider(3, 2) << std::endl;
    return 0;
}