#include "header.h"
// https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int t = nums.size();
        t /= 2;
        sort(nums.begin(), nums.end());
        return nums[t];
    }
};