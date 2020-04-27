#include "header.h"
// https://leetcode.com/problems/powx-n/
class Solution {
public:
    double myPow(double x, int n) {
        return Pow(x, n);
    }
private: 
    double Pow(double x, long long n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n < 0) return 1 / Pow(x, -n);
        double tmp = Pow(x, n/2);
        if (n & 1) return x * tmp * tmp;
        else return tmp * tmp;
    }
};