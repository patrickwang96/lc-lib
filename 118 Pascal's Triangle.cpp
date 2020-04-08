#include "header.h"
// https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) return result;
        else if (numRows == 1) {
            result.push_back({1});
            return result;
        }
        else if (numRows == 2) {
            result.push_back({1});
            result.push_back({1,1});
            return result;
        }
        
        result.push_back({1});
        result.push_back({1,1});
        
        for (int i = 2; i < numRows; i++) {
            vector<int> tmp(i + 1);
            tmp[0] = 1;
            tmp[i] = 1;
            for (int j = 1 ; j < i; j++) {
                tmp[j] = result[i - 1][j-1] + result[i-1][j];
            }
            result.push_back(tmp);
        }
        return result;
        
        
    }
};