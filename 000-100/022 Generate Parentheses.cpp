#include "header.h"
// https://leetcode.com/problems/generate-parentheses/
class Solution {
private:
    void gen(int n, int formed, int left, string current, vector<string>& result) {
        if (formed == n) {
            result.push_back(current);
            return ;
        }
        if (left) 
            gen(n, formed + 1, left - 1, current + ")", result);
        if (formed + left < n) 
            gen(n, formed, left + 1, current + "(", result);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string cur;
        gen(n, 0, 0, cur, result);
        return result;  
    }
};