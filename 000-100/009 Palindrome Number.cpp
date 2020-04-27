#include "header.h"
// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        long long a = x;
        long long r = 0;
        for (; a; a/=10) 
            r = r * 10 + a % 10;
        if (r == x) return true;
        else return false;
    }
};