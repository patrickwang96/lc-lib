#include "header.h"
// https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0; 
        int current_boundary = 0;
        int prev_boundary = 0;
        // if (nums.size() == 1) return 0;
        int steps = 0;
        
        
        while (current_boundary < nums.size() - 1) {
            steps++;
            int tmp = current_boundary;
            for (int i = prev_boundary; i <= current_boundary; i++) {
                if (nums[i] + i > tmp) tmp = nums[i] + i;
            }
            prev_boundary = current_boundary;
            current_boundary = tmp;
        }
        return steps;
    }
};