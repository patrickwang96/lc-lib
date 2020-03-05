#include "header.h"
// https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        if (!x) return 0;
        int result = 0;
        
        while (x) {
            int digit = x % 10;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) return 0;
            result *= 10;
            result += digit;
            x /= 10;
        }
        return result;
        
    }
};