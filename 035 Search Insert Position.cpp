
// https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int found = -1;
        int start = 0, mid, end = nums.size() - 1;
        
        while (start <= end) {
            mid = start + (end - start) / 2;
            
            if (nums[mid] < target)
                start = mid + 1;
            else if (nums[mid] > target)
                end = mid - 1;
            else {
                found = mid;
                break;
            }
        }
        if (found != -1) return found;
        else return start;
    }
};