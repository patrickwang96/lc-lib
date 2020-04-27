#include "header.h"
// https://leetcode.com/problems/valid-palindrome/
class Solution {
private: 
    string removeOther(string s) {
        auto i = s.begin();
        while (i != s.end()) {
            if (*i >= 'a' && *i <= 'z') i++;
            else if (*i >= '0' && *i <= '9') i++;
            else if (*i >= 'A' && *i <= 'Z') {
                *i = *i + 'a' - 'A';
                i++;
            }
            else i = s.erase(i);
        }
        return s;
    }
public:
    bool isPalindrome(string s) {
        s = removeOther(s);
        if (!s.size()) return true;
        
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] == s[s.size() - 1 - i]) continue;
            else return false;
        }
        return true;
        
    }
};