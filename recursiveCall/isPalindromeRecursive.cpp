#include <iostream>
#include <string>


bool isPalindrome(std::string word, int left, int right ){
    if (left >= right) return true;
    if(word[left] != word[right])return false;
    return isPalindrome(word, left+1, right -1);
}
int main (){

    std::string str = "daren";
    std::string str3 = "";
    std::string str2 = "abba";

     
     
     

     std::cout << "1. ==  " << isPalindrome(str, 0, 5) << std::endl;
     std::cout << "2. == "  << isPalindrome(str2, 0, 0) << std::endl;
     std::cout << "3. ==  " << isPalindrome(str3, 0, 4) << std::endl;
     return 0;
}