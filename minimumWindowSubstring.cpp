#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    // Count required characters in t
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0; // number of chars that meet the required count
    int start = 0, minLen = INT_MAX;

    while (right < s.size()) {
        char c = s[right];
        right++;
        // If c is needed, add it to window
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c])
                valid++;
        }
        // Try to shrink from the left if all required chars are satisfied
        while (valid == need.size()) {
            // Update the answer if this window is smaller
            if (right - left < minLen) {
                start = left;
                minLen = right - left;
            }
            // Remove s[left] from window
            char d = s[left];
            left++;
            if (need.count(d)) {
                if (window[d] == need[d])
                    valid--;
                window[d]--;
            }
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main(){

    string s, t;
    cin >> s >> t>> endl;
   
    cout >> smallestSubstring(s, t); >> endl;
    
    return 0;
} 