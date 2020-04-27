#include "header.h"
class Solution {
private: 
    int add(int num) {
        int r = 0;
        while (num) {
            r += num % 10;
            num /= 10;
        }
        return r;
    }
public:
    int addDigits(int num) {
        int r= add(num);
        while (r >= 10) r = add(r);
        return r;
        
    }
};