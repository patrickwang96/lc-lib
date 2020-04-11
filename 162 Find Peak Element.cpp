#include "header.h"
// https://leetcode.com/problems/find-peak-element/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) {
            if (nums[0] > nums[1]) return 0;
            else return 1;
        }
        int n = nums.size();
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;
        
        for (int i = 1; i < n-1; i++) {
            if (nums[i] > nums[i+1] && nums[i] > nums[i-1]) return i;
        }
        return 0;
        
        
    }
};