#include "header.h"
// https://leetcode.com/problems/triangle/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        if (triangle.size() == 1) return triangle[0][0];
        
        // vector<vector<int>> dp = triangle;
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0)
                    triangle[i][j] += triangle[i-1][j];
                else if (j == triangle[i].size() - 1) 
                    triangle[i][j] += triangle[i-1][j-1];
                else 
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        int result = INT_MAX;
        int depth = triangle.size() - 1;
        for (int i = 0; i < triangle[depth].size(); i++) {
            result = min(result, triangle[depth][i]);
        }
        return result;
    }
};