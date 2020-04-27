#include "header.h"
// https://leetcode.com/problems/combination-sum/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
        
        for (int i = start_index; i < candidates.size(); i++) {
            if (candidates[i] > target) return ;
            
            path.push_back(candidates[i]);
            
            dfs(candidates, target - candidates[i], path, result, i);
            
            path.pop_back();
        }
    }
};