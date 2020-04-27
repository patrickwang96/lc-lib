#include "header.h"
// https://leetcode.com/problems/pascals-triangle-ii/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1, 0);
        
        for (int i = 0; i < rowIndex+1; i++) {
            for (int j = i; j > 0; j--) {
                result[j] += result[j-1];
            }
            result[i] = 1;
        }
        return result;
        
        
    }
};