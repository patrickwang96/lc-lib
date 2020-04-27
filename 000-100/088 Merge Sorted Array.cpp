#include "header.h"
// https://leetcode.com/problems/merge-sorted-array/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> nums3(nums1.begin(), nums1.begin() + m);
        int ptr1 = 0;
        int ptr2 = 0;
        int counter = 0;
        while (ptr1 < m && ptr2 < n) {
            if (nums3[ptr1] < nums2[ptr2]) {
                nums1[counter++] = nums3[ptr1++];
            }
            else nums1[counter++] = nums2[ptr2++];
        }
        while (ptr1 < m) nums1[counter++] = nums3[ptr1++];
        while (ptr2 < n) nums1[counter++] = nums2[ptr2++];
        return;
    }
};