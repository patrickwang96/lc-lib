#include "header.h"
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> ht;
        
        for (int i = 0; i < nums.size(); i++) {
            if (!ht[nums[i]]) ht[nums[i]] = i + 1;
            else {
                if (i - ht[nums[i]] + 1> k) ht[nums[i]] = i + 1;
                else return true;
            }
        }
        return false;
        
    }
};