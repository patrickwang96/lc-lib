#include "header.h"
// https://leetcode.com/problems/subsets/
class Solution {
private:
    void dfs(vector<vector<int>> & result, int p, int total, vector<int> buf, vector<int>& nums){
        if (p == total) {
            result.push_back(buf);
            buf.push_back(nums[p]);
            result.push_back(buf);
            return;
        } else {
            dfs(result, p+1, total, buf, nums);
            buf.push_back(nums[p]);
            dfs(result, p+1, total, buf, nums);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int total = nums.size() - 1;
        vector<int> buf;
        dfs(result, 0, total, buf, nums);
        return result;
    }
};