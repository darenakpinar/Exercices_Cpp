#include <iostream>
#include <string>

// even numbers >= 4 can be written as sum of two prime.

bool is_prime(int n){
    
    if (n <= 1)return false;
    if (n == 2)return true;
    int i = 2;
    while (i < n){
        if (n % i == 0)return false;
    }
    return true;
}

vector<vector<int>> verifyGoldbach(int n){

    vector<vector<int>> primePairs;
    int val = 4;
    while (primPairs.size()< n){

        int p = 2;
        bool found = false;
        while (!found){
            if(is_prime(p) && is_prime(val - p)){
                found = true;
                vector<int> pair = {p, val - p};
                primePairs.push_back(pair);
            }
            p = p + 1;
        }
        val = val + 2;
    }
    return primePairs;
}