#include "header.h"
class Solution {
public:
    int findComplement(int num) {
        int totalComplement = ~num ;
        int bitLen = 0;
        while (num) {
            num >>= 1;
            bitLen++;
        }
        int one = 0;
        for (int i = 0; i < bitLen; i++) {
            one |= 1 << i;
        }
        return one & totalComplement;
        
    }
};