#include "header.h"
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1 = 0, p2 = 0;
        
        while (p1 < nums.size()) {
            if (nums[p1]) 
                swap(nums[p1], nums[p2++]);
            p1++;
        }
    }
};