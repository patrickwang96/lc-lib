#include "header.h"
// https://leetcode.com/problems/longest-valid-parentheses/
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() < 2) return 0;
        
        vector<int> dp(s.length(), 0);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') continue;
            if (s[i] == ')') {
                if (i == 0) dp[i] = 0;
                else if (s[i - 1] == '('){
                    if (i > 1) dp[i] = dp[i-2] + 2;
                    else dp[i] = 2;
                }
                else if (i - dp[i-1] - 1>=0 && s[i - dp[i-1] - 1] == '(') {
                    dp[i] = dp[i-1] + 2;
                    if (i - dp[i-1] - 2 >= 0) dp[i]+=dp[i - dp[i-1] - 2];
                }
                
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};