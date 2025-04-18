#ifndef LZ77_HPP
#define LZ77_HPP

#include <vector>
#include <string>

struct LZ77Token {
    int length;
    int offset;
    char nextChar;
};

std::vector<LZ77Token> compressLZ77(const std::string& s, int windowSize);

#endif // LZ77_HPP