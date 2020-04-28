#include "header.h"
class Solution {
private:
    void solve(vector<vector<int>> & ret, vector<int> nums, int i) {
        if (nums.size() == i + 1) {
            ret.push_back(nums);
            return ;
        }
        
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            solve(ret, nums, i+1);
            swap(nums[i], nums[j]);
        }
        return ;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        solve(ret, nums, 0);
        return ret;
    }
};