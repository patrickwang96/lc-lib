#include "header.h"
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total & 1) return false;
        // total is even
        total /= 2;
        
        bitset<5001> map(1); // 0 bit is set to 1
        for (auto num: nums) if (num <= total) map |= map << num;
        return map[total];
    }
};