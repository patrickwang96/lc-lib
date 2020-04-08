#include "header.h"
// https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
private:
    int m(vector<vector<int>>& matrix, int index){
        int col_count = matrix[0].size();
        return matrix[index/col_count][index%col_count];
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_count = matrix.size();
        if (!row_count) return false;
        int col_count = matrix[0].size();
        if (!col_count) return false;
        
        int l = 0;
        int r = row_count * col_count - 1;
        
        if (target < m(matrix, l) || target > m(matrix, r)) return false;
        
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (m(matrix, mid) < target) l = mid;
            else if (m(matrix, mid) > target) r = mid;
            else return true;
        }
        if (m(matrix, r) == target || m(matrix, l) == target) return true;
        else return false;
        
    }
};