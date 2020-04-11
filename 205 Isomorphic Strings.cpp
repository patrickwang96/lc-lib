#include "header.h"
// https://leetcode.com/problems/isomorphic-strings/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> dict1;
        unordered_map<char, char> dict2;
        
        for (int i = 0; i < s.size(); i++) {
            if (dict1.count(s[i])) {
                if (t[i] == dict1[s[i]]) ;
                else return false;
            } else if (dict2.count(t[i])) {
                if (s[i] != dict2[t[i]]) return false;
            }
            else {
                dict1[s[i]] = t[i];
                dict2[t[i]] = s[i];
            }
        }
        return true;
        
    }
};