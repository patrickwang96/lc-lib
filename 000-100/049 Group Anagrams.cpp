#include "header.h"
// https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;
        
        for (auto i: strs) {
            string sorted_str = i;
            sort(sorted_str.begin(), sorted_str.end());
            if (table.find(sorted_str) != table.end()) {
                table.at(sorted_str).push_back(i);
            } else {
                vector<string> tmp;
                tmp.push_back(i);
                // table.insert(sorted_str, tmp);
                table[sorted_str] = tmp;
            }
        }
        
        vector<vector<string>> result;
        
        for (auto kv: table) {
            result.push_back(kv.second);
        }
        return result;
        
    }
};