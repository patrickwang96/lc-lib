#include "header.h"
class Solution {
private:
    void dfs(int n, int start, vector<vector<int>> &result, vector<int> cur) {
        if (n == 1 && cur.size() > 1) {
            result.push_back(cur);
            return ;
        } else if (n == 1) return ;
        
        for (int i = start; i <= n; i++) {
            if (n%i == 0) {
                cur.push_back(i);
                dfs(n/i,i, result, cur);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> cur;
        dfs(n,2, result, cur);
        return result;
        
    }
};