#include "header.h"
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        if (num <= 0) return false;
        int sqt = sqrt(num);
        
        int count = 0;
        
        for (int i = 1; i <= sqt; i++) {
            if (num == (num/i)*i) {
                count += num / i + i;
            }
        }
        count -= num;
        return count == num;
        
    }
};