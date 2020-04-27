#include "header.h"
// https://leetcode.com/problems/regular-expression-matching/
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.size() == 0 && p.size() == 0) return true;
        if (p.size() == 1) {
            if (p[0] == '.' && s.size() == 1) return true;
            else return p == s;
        }  else {
            if (p[1] == '*') {
                auto c = p[0];
                // if (c == '.') return true;
                if (isMatch(s, p.substr(2))) return true;;
                for(int i = 0; i < s.size(); i++) {
                    if (s[i] != c && c != '.') return false;
                    else {
                        if (isMatch(s.substr(i+1), p.substr(2))) return true;
                    }
                }
            } else if (p[0] == '.') {
                if (s.size() == 0) return false;
                return isMatch(s.substr(1), p.substr(1));
            } else {
                if (s.size() == 0) return false;
                if (s[0] == p[0]) return isMatch(s.substr(1), p.substr(1));
                else return false;
            }
        }
        return false;
        
    }
};