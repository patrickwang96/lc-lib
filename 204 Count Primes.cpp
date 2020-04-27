#include "header.h"
class Solution {
private:
    bool isp(int t) {
        if (t % 2 == 0) return false;
        for (int i = 3; i <= sqrt(t); i+=2) {
            if (t % i == 0) return  false;
        }
        return true;
        
    }
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        if (n == 2) return 0;
        if (n == 3) return 1;
        
        int counter = 1;
        for (int i = 3; i < n; i++) {
            if (isp(i)) counter ++;
        }
        return counter;
    }
};