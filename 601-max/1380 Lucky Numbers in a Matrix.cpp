#include "header.h"
// https://leetcode.com/problems/lucky-numbers-in-a-matrix/
class Solution {
private:
    bool isMin(vector<int> row, int target) {
        for (auto i: row)
            if (i < target) return false;
        return true;
    }

public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_map<int, int> map;
        int tmp = INT_MIN;
        int current_row;
        vector<int> result;
        for (int n = 0; n < matrix[0].size(); n++) {
            tmp = INT_MIN;
            for (int m = 0; m < matrix.size(); m++) {
                if (matrix[m][n] > tmp) {
                    tmp = matrix[m][n];
                    current_row = m;
                }
            }
            if (map.count(current_row) && map[current_row] > tmp)
                map[current_row] = tmp;
            else if (!map.count(current_row))
                map[current_row] = tmp;
        }
        for (int i = 0; i < matrix.size(); i++) {
            if (map.count(i) && isMin(matrix[i], map[i])) result.push_back(map[i]);
        }
        return result;
        
    }
};