#include "header.h"
class Solution {
public:
    string solve(string &s, int & i) {
        string ret = "";
        
        while (i < s.size() && s[i] != ']') {
            if (s[i] < '0' || s[i] > '9') {
                ret += s[i++];
            } else {
                int count = 0;
                while (s[i] >= '0' && s[i] <= '9') {
                    count *= 10;
                    count += s[i++] - '0';
                }
                i++; // '['
                string tmp = solve(s, i); // jump to next level
                i++; // ']'
                // TODO string multiple?
                for (int j = 0; j < count; j++) ret += tmp;
            }
        }
        return ret;
        
    }
    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }
};