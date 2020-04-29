#include "header.h"
class Solution {
private:
    int solve(vector<int>& nums, int start, int end) {
        if (end - start <= 1) return nums[start];
        
        vector<int> dp(end);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);
        for (int i = start+2; i < end; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[end-1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        
        return max(solve(nums, 0, n-1), solve(nums, 1, n));
    }
};