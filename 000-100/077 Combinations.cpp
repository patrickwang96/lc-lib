#include "header.h"
// https://leetcode.com/problems/combinations/
class Solution {
private:
    void bfs(vector<vector<int>> &v, int n, int k, int c, vector<int>  buf) {
        if (buf.size() == k - 1) {
            buf.push_back(c);
            v.push_back(buf);
            return;
        } else {
            buf.push_back(c);
            for (c; c < n; c++) {
                bfs(v, n, k, c+1, buf);
            }
        }
        
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> buf;
        for (int i = 1; i <= n; i++) 
            bfs(result, n, k, i, buf);
        return result;
        
    }
};