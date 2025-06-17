#include <iostream>
#include <string>
#include <unordered_map>

int longesSubstringWithDistinct(string s, int k){

    unordered_map<char, int>count;
    int maxLen = 0;
    int left = 0;

    for (int right = 0; right < s.length(); ++right){
        char c = s[right]++;

        // Shrink window until we have at most k ditinct chars
        while (count.size() > k){
            count[s[left]]--;
            if (count[s[left]] == 0){
                count.erase(s[left]);
                
            }
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}