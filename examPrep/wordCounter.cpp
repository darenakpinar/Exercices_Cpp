#include <iostream>
#include <string>
#include <unordered_map>

class WordCounter{
private:
    unordered_map<std::string, int>word_count;

public:
    void addWord(std::string word){
        word_count[word]++;
    }

    int getWordCount(string word){
        auto it = word_count.find(word);
        if (it != word_count.end())
            return it->second;
        else   
            return 0;
            
    }
