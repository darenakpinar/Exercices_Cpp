#include <iostream>
#include <string>
#include <unordered_map>

vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int, int>counts;
    vector<int> result;
    // count elements in nums1

    for (int n : nums1) counts[n]++;
    // For each element in nums2, if it's in the map, add to result and decrase count

    for (int n : nums2){
        if (counts[n] > 0){
            result.push_back(n);
            counts[n]--;
        }
    }
    return result;
}