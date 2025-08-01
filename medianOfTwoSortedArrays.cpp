#include <iostream>
#include <string>
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size();
        int n = nums2.size();
        int imin = 0, imax = m;
        int half_len = (m + n + 1) / 2;

        while (imin <= imax) {
            int i = (imin + imax) / 2;
            int j = half_len - i;

            // i is too small, must increase it
            if (i < m && nums2[j - 1] > nums1[i]) {
                imin = i + 1;
            }
            // i is too big, must decrease it
            else if (i > 0 && nums1[i - 1] > nums2[j]) {
                imax = i - 1;
            }
            // i is perfect
            else {
                int max_of_left = 0;
                if (i == 0)
                    max_of_left = nums2[j - 1];
                else if (j == 0)
                    max_of_left = nums1[i - 1];
                else
                    max_of_left = max(nums1[i - 1], nums2[j - 1]);
                
                // Odd total length: median is max of left
                if ((m + n) % 2 == 1)
                    return max_of_left;

                int min_of_right = 0;
                if (i == m)
                    min_of_right = nums2[j];
                else if (j == n)
                    min_of_right = nums1[i];
                else
                    min_of_right = min(nums1[i], nums2[j]);

                // Even total length: median is average of two middle values
                return (max_of_left + min_of_right) / 2.0;
            }
        }
        // Should never reach here if input is valid
        return 0.0;
    }

int main (){

    int nums1[1, 3];
    int nums2[2, 4, 5, 6];

    medianOfTwoSortedArray(nums1, nums2);

    return 0;
}