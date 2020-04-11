#include "header.h"
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
class Solution {
private:
    int m, n;
    // hash<string> hasher;
    bool check(string& s, int start, unordered_map<string, int> dict) {
        // vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            string tmp = s.substr(start+i*m, m);
            if (dict.count(tmp)){
                if (dict[tmp]>0) dict[tmp]--;
                // else return false;
            } else return false;
        }
        // bool result = true;
        for (auto e: dict) {
            if (e.second != 0) return false;
        }
        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.size() == 0 || words.size() == 0) return result;
        unordered_map<string, int> dict;
        for (auto w: words) dict[w]++;
        m = words[0].size();
        n = words.size();
        
        if (s.size() < n * m) return result;
        for (int i = 0; i <= s.size() - n*m; i++) {
            if (check(s, i, dict))
                result.push_back(i);
        } 
        return result;
    }
};