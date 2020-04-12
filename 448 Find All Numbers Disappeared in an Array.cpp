#include "header.h"
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        vector<int> map(n, 0);
        for (auto num: nums) {
            map[num-1] = 1;
        }
        
        for (int i = 0; i < n; i++) {
            if (map[i] == 0) result.push_back(i+1);
        }
        return result;
    }
};