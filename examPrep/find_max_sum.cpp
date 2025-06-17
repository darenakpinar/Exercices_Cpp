#include <iostream>
#include <vector>

int find_max_sum(const std::vector<int>& v){

    int maxInt = v.at(0);
    int secondMax = v.at(1);

    if (maxInt < secondMax){
        int tmp = secondMax;
        secondMax = maxInt;
        maxInt = tmp;
    }
    for (int i = 2; i < v.size(); i++){

        int val = v.at(i);

        if (maxInt <= val){
            secondMax = maxInt;
            maxInt = val;
        }else if (val > secondMax && val < maxInt){
            secondMax = val;
        }
    } 

    return secondMax + maxInt;
}