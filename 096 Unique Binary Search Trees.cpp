#include "header.h"
class Solution {
private:
    
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        // dp[2] = 2;
        
        if (n < 2) return dp[n];
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                int left = j - 1;
                int right = i - j;
                dp[i] += dp[left] * dp[right];
            }
        }
        return dp[n];
        
    }
};