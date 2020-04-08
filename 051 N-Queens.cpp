#include "header.h"
// https://leetcode.com/problems/n-queens/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> map(n, -1);
        vector<vector<string>> result;
        
        dfs(map, result, 0);
        
        return result;
    }

private:
    void dfs(vector<int> & map,vector<vector<string>> &result, int row) {
        int n = map.size();
        if (row == n) {
            vector<string> solution;
            for (int i = 0; i < n; i++) {
                string tmp(n, '.');
                tmp[map[i]] = 'Q';
                solution.push_back(tmp);
            } 
            
            result.push_back(solution);
            return ;
        }
        
        for (int i = 0; i < n; i++) {
            if (check(map, row, i)) {
                map[row] = i;
                dfs(map, result, row + 1);
            } 
            else continue;
        }
    }
    
    bool check(vector<int> map, int row, int col) {
        for (int i = 0; i < row; i++) {
            int delta_row = i - row;
            int delta_col = map[i] - col;
            if (delta_col == 0) return false;
            if (abs(delta_row) == abs(delta_col)) return false;
        }
        return true;
    }
};