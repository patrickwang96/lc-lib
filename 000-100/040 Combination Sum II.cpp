#include "header.h"
// https://leetcode.com/problems/combination-sum-ii/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> result;
        vector<int> path;
        dfs(candidates, target, path, result, 0);
        return result;
    }
    
private:
    void dfs(vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& result, int start_index) {
        if (target == 0) {
            result.push_back(path);
            return ;
        }
        
        int previous = -1;
        for (int i = start_index; i < candidates.size(); i++) {
            if (candidates[i] > target) return ;
            if (previous == candidates[i]) continue;
            
            path.push_back(candidates[i]);
            previous = candidates[i];
            
            dfs(candidates, target - candidates[i], path, result, i + 1);
            
            path.pop_back();
        }
    }
};