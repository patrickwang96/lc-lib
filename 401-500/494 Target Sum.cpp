#include "header.h"
// https://leetcode.com/problems/target-sum/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        
        for (auto num: nums) {
            unordered_map<int, int> tmp;
            for (auto entry: dp) {
                tmp[entry.first - num] += entry.second;
                tmp[entry.first + num] += entry.second;
            }
            dp = tmp;
        }
        return dp[S];
        
    }
};