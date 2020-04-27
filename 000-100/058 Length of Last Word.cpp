#include "header.h"
// https://leetcode.com/problems/length-of-last-word/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int ptr = s.size() - 1;
        // check if string end with ' '
        while (s[ptr] == ' ') ptr--;
        
        while (ptr >= 0 && s[ptr] != ' ') {
            count++; ptr--;
        }
        return count;
    }
};