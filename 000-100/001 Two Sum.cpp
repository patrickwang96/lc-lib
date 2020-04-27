#include "header.h"
// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            map.insert({nums[i], i});
        }
        for(int i = 0; i < nums.size(); i++) {
            int rest = target - nums[i];
            if (map.count(rest) > 0 && i != map[rest]) {
                result.push_back(i);
                result.push_back(map[rest]);
                return result;
            }
        }
        return result;
        
    }
};