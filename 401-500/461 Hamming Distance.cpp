#include "header.h"
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int result = 0;
        while (z) {
            
            if (z & 1) result++;
            z  = z >>1;
        }
        return result;
        
    }
};