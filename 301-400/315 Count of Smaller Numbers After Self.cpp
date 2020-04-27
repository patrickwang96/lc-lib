#include "header.h"
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> sorted, ret(n);
        for (int i = nums.size() - 1; i >= 0; --i) {
            int left = 0, right = sorted.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (sorted[mid] >= nums[i]) right = mid;
                else left = mid + 1;
            }
            ret[i] = right;
            sorted.insert(sorted.begin() + right, nums[i]);
        }
        return ret;
    }
};