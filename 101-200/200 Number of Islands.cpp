#include "header.h"
class Solution {
private:
    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited) {
        
        if (i < 0 || j < 0 || j >= grid[0].size() || i >= grid.size()) return ;
        if (grid[i][j] == '0' || visited[i][j]) return ;
        visited[i][j] = true;
        dfs(grid, i+1, j, visited);
        dfs(grid, i-1, j, visited);
        dfs(grid, i, j+1, visited);
        dfs(grid, i, j-1, visited);
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // grid -> n * m
        int n = grid.size();
        if (n==0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        int ret = 0;
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    ret++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        
        return ret;
    }
};