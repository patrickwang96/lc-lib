#include "header.h"
// https://leetcode.com/problems/unique-paths/
class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;n--;
        int total = n + m;
        n = min(m, n);
        
        double upper = 1, lower = 1;
        // double result = 1.0;
        // int a = total, b = n;
        // while (a > total - n && b >= 1) result *= (a-- * 1.0 / b--);
        // while (a > total - n) result *= a--;
        // while (b >= 1) result /= b--;
        
        for (long i = total; i > total - n; i--) upper *= i;
        for (int i = 1; i <= n; i++) lower *= i;
        
        return int(upper/lower);
    }
};