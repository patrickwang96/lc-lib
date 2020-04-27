#include "header.h"
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> ht;
        for (auto i: nums) {
            if (!ht.count(i)) ht.insert(i);
            else return true;
        }
        return false;
    }
};