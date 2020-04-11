#include "header.h"
// https://leetcode.com/problems/word-pattern/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (str.size() == 0 || pattern.size() == 0) return false;
        
        // str to words
        vector<string> words;
        int p1 = 0, p2 = 0;
        while (p2 <str.size() && p1 < str.size()) {
            if (str[p2] != ' ') p2++;
            else {
                words.push_back(str.substr(p1, p2-p1));
                p1 = ++p2;
            }
        }
        words.push_back(str.substr(p1));
        
        unordered_map<char, string> dict1;
        unordered_map<string, char> dict2;
        
        if (pattern.size() != words.size()) return false;
        for (int i = 0; i < words.size(); i++) {
            if (dict1.count(pattern[i])) {
                if (dict1[pattern[i]] != words[i]) return false;
                
            } else if (dict2.count(words[i])){
                if (dict2[words[i]] != pattern[i]) return false;
            } else {
                dict1[pattern[i]] = words[i];
                dict2[words[i]] = pattern[i];
            }
        }
        return true;
    }
};