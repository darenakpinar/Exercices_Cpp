#include <iostream>
#include <vector>

int minimumDivisor(vector<int>arr, int thresh){

    int min_div = 1;
    int mac_div = 0;

    for (int V: arr){
        if (V > max_div){
            max_div = v;
        }
    while (min_div < max_div){
        int m_div = (max_div + min_div) / 2;
        int sum = 0;
        for (int v: arr){
            int d = (v % m_div == 0)? v/m_div : v/m_div+1;
            sum = sum + d;
        }
        if (sum > thresh){
            min_div = m_div + 1;

        }else{
        max_div = m_div;
        }
    }
    return max_div;
}
