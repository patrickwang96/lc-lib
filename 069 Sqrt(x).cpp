#include "header.h"
// https://leetcode.com/problems/sqrtx/
class Solution {
private:
    bool isSqrt(long long x, long long y) {
        return (y*y <= x && (y+1)*(y+1) > x);
    }
public:
    int mySqrt(int x) {
        if (x == 0) return 0; 
        int result = 1;
        while (!isSqrt(x, result)) {
            result++;
        }
        return result;
    }
};