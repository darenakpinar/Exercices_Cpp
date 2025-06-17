#include <iostream>
#include <vector>

int count(vector<int>& numbers, int n ){

    if (n == 0){
        return 1;
    }else if (n < 0)return 0;


    int total_count = 0;

    for (int i = 0; i < numbers.size(); i++){
        int t = count(numbers, n - numbers.at(i));
        tot_count = tot_count + t;
    }


}