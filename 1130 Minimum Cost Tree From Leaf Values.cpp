#include "header.h"
class Solution {
private:
    vector<vector<int>> dp;
    vector<vector<int>> arr_max;
    
    int solve(int i, int j) {
        if (i == j) return 0; // leaf only
        if (dp[i][j] != INT_MIN) return dp[i][j];
        
        int cur = INT_MAX;
        
        for (int k = i; k < j; k++) {
            cur = min(cur, arr_max[i][k] * arr_max[k+1][j] + solve(i, k) + solve(k+1, j));
        }
        
        dp[i][j] = cur;
        return cur;
    }
    
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++){
            vector<int> tmp(n, INT_MIN);
            dp.push_back(tmp);
            
            vector<int> row_max(n, 0);
            row_max[i] = arr[i];
            for (int j = i+1; j < n; j++) {
                row_max[j] = max(arr[j], row_max[j-1]);
            }
            arr_max.push_back(row_max);
        }
        
        return solve(0, n-1);
    }
};