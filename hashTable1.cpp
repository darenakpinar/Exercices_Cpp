#include <iostream>
#include <unordered_map>
#include <string>

int firstUniqChar(string s){

    unordered_map<char, int>count;
    //first pass: count characters

    for (char c: s){
        count[c]++;
    }
    // Second pass: find the first unique character 
    for (int i = 0; i < s.size(); i++){
        if (count[s[i]] == 1){
            return i;
        }
    }

    return -1;
}