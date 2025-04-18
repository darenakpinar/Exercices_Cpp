#include "lz77.hpp"  // ✅ Include the header file
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<LZ77Token> compressLZ77(const string& s, int windowSize) {
    vector<LZ77Token> result;
    int i = 0;

    while (i < s.length()) {
        int maxMatchLength = 0, bestOffset = 0;

        for (int j = max(0, i - windowSize); j < i; j++) {
            int matchLength = 0;
            while ((matchLength < windowSize) && (i + matchLength < s.length()) &&
                   (s[j + matchLength] == s[i + matchLength])) {
                matchLength++;
            }

            if (matchLength > maxMatchLength) {
                maxMatchLength = matchLength;
                bestOffset = i - j;
            }
        }

        char nextChar = (i + maxMatchLength < s.length()) ? s[i + maxMatchLength] : '\0';
        result.push_back({maxMatchLength, bestOffset, nextChar});
        i += maxMatchLength + 1;
    }

    return result;
}
int main() {
    string input;
    cout << "Enter a string to compress: ";
    getline(cin, input);

    int windowSize = 10;  // Set the sliding window size
    vector<LZ77Token> compressedData = compressLZ77(input, windowSize);

    // Print compressed output
    cout << "Compressed Data:\n";
    for (const auto& token : compressedData) {
        cout << "(" << token.length << ", " << token.offset << ", '" << token.nextChar << "') ";
    }
    cout << endl;

    return 0;
}


