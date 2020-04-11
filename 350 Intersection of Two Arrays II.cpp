#include "header.h"
// https://leetcode.com/problems/intersection-of-two-arrays-ii/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for (auto i: nums1) map[i]++;
        vector<int> result;
        for (auto i: nums2) {
            if (map[i] > 0) {
                map[i]--;
                result.push_back(i);
            }
        }
        return result;
    }
};