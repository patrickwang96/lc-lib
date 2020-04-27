#include "header.h"
// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, mid, end = nums.size() - 1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            
            if (nums[mid] == target) return mid;
            else if (nums[mid] >= nums[start]){
                if (target >= nums[start] && target < nums[mid]) end = mid - 1;
                else start = mid + 1;
            } else {
                if (target <= nums[end] && target > nums[mid]) start = mid + 1;
                else end = mid -1;
            }
            
        }
        
        return -1;
    }
};