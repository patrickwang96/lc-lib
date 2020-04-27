#include "header.h"
// https://leetcode.com/problems/sort-colors/
// GOOD
// this is a great two pointer question
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = nums.size() - 1;
        for (int i = 0; i <= blue; i++) {
            if (nums[i] == 0) {
                swap(nums[red], nums[i]);
                red++;
                // i--;
            } else if (nums[i] == 2) {
                swap(nums[blue], nums[i]);
                blue--;
                i--;
            } 
        }
    }
};