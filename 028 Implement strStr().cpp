#include "header.h"
// https://leetcode.com/problems/implement-strstr/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                for (int j = 0; j < needle.size(); j++) {
                    if (haystack[i+j] != needle[j]) break;
                    else if (j == needle.size() - 1) return i;
                    else continue;
                }
            }
        }
        return -1;
        
    }
};