#include <iostream>
#include <string>
#include <unordered_map>

int countSubstr(string s){
    unordered_map<char, int> lastIndex;
    int maxLen = 0;
    int left = 0; // start of current window

    for (int right = 0; right < s.length(); ++right ){
        char c = s[right];
        // If we've seen this char and it's indide the current window
        if (lastIndex.count(c) && lastIndex[c] >= left){
            left = lastIndex[c] + 1; // Move left just after this character 
        }
        lastIndex[c] = right; // update last seen index
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}