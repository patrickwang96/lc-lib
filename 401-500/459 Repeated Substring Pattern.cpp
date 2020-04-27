#include "header.h"
class Solution {
private:
    bool isPattern(string s, string sub) {
        if (s.size() % sub.size() != 0) return false;
       
        for (int i = 0; i < s.size(); i+=sub.size()) {
            if (s.substr(i, sub.size()) == sub) continue;
            else return false;
        }
        return true;
    }
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i < s.size() / 2 + 1; i ++) {
            if (isPattern(s, s.substr(0, i))) return true;
        }
        return false;
    }
};