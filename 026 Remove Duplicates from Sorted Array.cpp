
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int ptr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[ptr] != nums[i]) 
                nums[++ptr] = nums[i];
        }
        return ptr + 1;
    }
};