#include "header.h"
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
private:
    void bfs(vector<string>& result, string digits, unordered_map<string, string> & dict, string cur_string) {
        if (digits.size() == 0) {
            result.push_back(cur_string);
            return ;
        }
        string cur = digits.substr(0,1);
        string candidates = dict[cur];
        string new_digits = digits.substr(1);
        for (auto c: candidates) {
            bfs(result, new_digits, dict, cur_string+c);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        unordered_map<string, string> dict ({
            {"2", "abc"},
            {"3", "def"},
            {"4","ghi"},
            {"5", "jkl"},
            {"6", "mno"},
            {"7", "pqrs"},
            {"8", "tuv"},
            {"9", "wxyz"}
        });
        if (digits.size() == 0) return result;
        bfs(result, digits, dict, "");
        return result;
    }
};