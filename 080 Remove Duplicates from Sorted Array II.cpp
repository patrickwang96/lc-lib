#include "header.h"
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.size() <= 2) return nums.size();
        int ptr = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[ptr-2]) nums[ptr++] = nums[i];
        }
        return ptr;
    }
};