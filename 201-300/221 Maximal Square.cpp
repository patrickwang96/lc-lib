#include "header.h"
class Solution {
private: 
    inline int toi(char c) {return c - '0';}
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int result = 0;
        
        for (int i = 0; i < m; i++) {
            dp[i][0] = toi(matrix[i][0]);
            result = max(result, dp[i][0]);
        }
        for (int i = 0; i < n; i++) {
            dp[0][i] = toi(matrix[0][i]);
            result = max(result, dp[0][i]);
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (toi(matrix[i][j]) == 1) {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    result = max(result, dp[i][j]);
                }
            }
        }
        
        return result * result;
    }
};