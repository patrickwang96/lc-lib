#include "header.h"
// https://leetcode.com/problems/valid-perfect-square/
class Solution {
public:
    bool isPerfectSquare(int num) {
        // newton's method
        if (num < 2) return true;
        long long x = num / 2;
        while (x * x > num) {
            x = (x + num/x)/2;
        }
        return (x * x == num);
        
    }
};