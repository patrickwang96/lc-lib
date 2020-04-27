#include "header.h"
// https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int boundary = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > boundary) return false;
            int tmp = nums[i] + i;
            if (tmp > nums.size() - 1) return true;
            if (tmp > boundary) boundary = tmp;
        }
        return true;
    }
};