#include "header.h"
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
private:
    int binary_search_left(vector<int>& nums, int target) {
        int ret = -1;
        
        int mid, start = 0, end = nums.size() - 1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] < target)
                start = mid + 1;
            else if (nums[mid] > target) 
                end = mid - 1;
            else {
                ret = mid;
                break;
            }
        }
        
        return ret;
        
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int found = binary_search_left(nums, target);
        if (found < 0) {
            result.push_back(-1);
            result.push_back(-1);
            
            return result;
        }
        
        int left = found, right = found;
        while (left > 0 && nums[left -1] == target) left--;
        while (right < nums.size() - 1 && nums[right + 1] == target) right ++;
        result.push_back(left);
        result.push_back(right);
        return result;
    }
};