#include "header.h"
// https://leetcode.com/problems/bitwise-and-of-numbers-range/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        if (m < n) return rangeBitwiseAnd(m>>1, n>>1) << 1;
        else return m;
    }
};