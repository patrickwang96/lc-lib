#include "header.h"
// https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN, cur = 0;
        
        for (int i : nums) {
            cur = max(cur + i, i);
            result = max(cur, result);
        }
        return result;
        
    }
};