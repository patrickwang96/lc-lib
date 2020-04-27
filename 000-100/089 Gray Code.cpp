#include "header.h"
// https://leetcode.com/problems/gray-code/
// GOOD
// see explaination on evernote -- patrick wang 08 april 2020
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        // int count = pow(2,n);
        int count = 1<<n;
        for (int i = 0; i < count; ++i) {
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
};