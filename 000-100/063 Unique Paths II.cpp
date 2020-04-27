#include "header.h"
// https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long>> map;
        for(int i = 0; i < m; i++) {
            vector<long long> tmp(n, 0);
            map.push_back(tmp);
        }
        
        if (obstacleGrid[0][0] == 1) return 0;
        else map[0][0] = 1;
        
        // first row
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 1) map[0][i] = 0;
            else map[0][i] = map[0][i-1];
        }
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) map[i][0] = 0;
            else map[i][0] = map[i-1][0];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) map[i][j] = 0;
                else map[i][j] = map[i][j-1] + map[i-1][j];
            }
        }
        return map[m-1][n-1];
    }
};