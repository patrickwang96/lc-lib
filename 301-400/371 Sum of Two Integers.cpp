#include "header.h"
class Solution {
public:
    int getSum(int a, int b) {
        
        while (b) {
            int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
            
    }
};