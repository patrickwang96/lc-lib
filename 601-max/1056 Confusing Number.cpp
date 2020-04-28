#include "header.h"
class Solution {
public:
    bool confusingNumber(int N) {
        if (N == 0) return false;
        unordered_map<int, int> map = {{0,0},{1,1},{6,9},{8,8}, {9,6}, {2,-1}, {3,-1}, {4, -1}, {5, -1}, {7, -1}};
        
        int fliped = 0;
        int n = N;
        
        while (n) {
            auto cur = n % 10;
            if (map[cur] < 0) return false;
            fliped = fliped * 10 + map[cur];
            n /= 10;
        }
        
        if (fliped == N) return false;
        return true;
        
        
    }
};