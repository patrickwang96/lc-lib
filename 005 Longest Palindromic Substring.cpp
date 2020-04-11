#include "header.h"
// https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        int n = s.size();
        bool dp[n][n];
        memset(dp, 0, sizeof(bool) * n * n);
        for (int i = 0; i < n; i++) dp[i][i] = true;
        int start = 0, length = 1;
        
        for (int i = n-1; i >= 0;i--) {
            for (int j = i+1; j < n; j++) {
                if (i +1 == j) {
                    if (s[i] == s[j]) dp[i][j] = true;
                } else {
                    if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
                }
                if (dp[i][j] && j - i + 1 > length){
                    start = i;
                    length = j-i+1;
                }
            }
        }
        
        return s.substr(start, length);
        
    }
};