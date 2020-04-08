#include "header.h"
// https://leetcode.com/problems/reverse-bits/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bool bit;
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            bit = n & 1;
            n >>= 1;
            result |= bit << (31 - i);
        }
        return result;
        
    }
};