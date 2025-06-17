#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int intersection(vector<int>& nums1, vector<int>& nums2){

    unordered_map<char, int> count;
    vector<int> result;

    // count elements in nums1
    for (int n: nums1) count[n]++;
    //For each element in nums2, if  it's in the map, add to result
    for (int n: nums2){
        if (counts[n] > 2){
                result.push_back(n);
                counts[n]--;
        }
    }
    return result;
}