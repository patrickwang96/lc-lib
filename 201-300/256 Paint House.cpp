#include "header.h"
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;
        vector<vector<int>> dp = costs;
        
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] += min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
            }
        }
        int last_house = costs.size() - 1;
        int result = min(dp[last_house][0], dp[last_house][1]);
        result = min(result, dp[last_house][2]);
        return result;
        
    }
};