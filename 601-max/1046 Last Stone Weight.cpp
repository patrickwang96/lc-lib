#include "header.h"
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.rbegin(), stones.rend());
        
        int n = stones.size();
        if (n == 0) return 0;
        else if (n == 1) return stones[0];
        
        while (stones[1] > 0) {
            
            if (stones[0] == stones[1]) {
                stones[0] = stones[1] = 0;
            } else {
                stones[0] -= stones[1];
                stones[1] = 0;
            }
            sort(stones.rbegin(), stones.rend());
        } 
        
        return stones[0];
        
    }
};