#include "header.h"
// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int start, end;
        vector<vector<int>> result;
        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            start = i + 1; 
            end = len - 1;
            while (start < end ) {
                if (start > i + 1 && nums[start] == nums[start-1]) {
                    start++;
                    continue;
                }
                if (end < len - 1 && nums[end] == nums[end+1]) {
                    end --;
                    continue;
                }
                int tmp_sum = nums[start] + nums[i] + nums[end];
                if (tmp_sum == 0) {
                    vector<int> tmp = { nums[start], nums[i], nums[end]};
                    result.push_back(tmp);
                    start++; 
                    end--;
                }
                else if (tmp_sum < 0) 
                    start++;
                else  end--;
            }
            
        }
        
        return result;
    }
};