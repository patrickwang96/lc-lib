#include "header.h"
// https://leetcode.com/problems/factorial-trailing-zeroes/
class Solution {
// private:
    // inline int count(int n, int m) { 
    //     int result = 0;
    //     while (n%m == 0) {
    //         result ++;
    //         n /= m;
    //     }
    //     return result;
    // }
public:
    int trailingZeroes(int n) {
        int n2 = 0, n5 = 0;
        // for (int i = 1; i <= n; i++) {
        //     n2 += count(i, 2);
        //     n5 += count(i, 5);
        // }
        // return min(n2, n5);
        // 超时， 换打表吧
        
        while (n) {
            n5 += n / 5;
            n /= 5;
        }
        return n5; 
    }
};