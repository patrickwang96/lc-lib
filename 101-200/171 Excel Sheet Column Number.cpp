#include "header.h"
// https://leetcode.com/problems/excel-sheet-column-number/
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (auto c: s) {
            result *= 26;
            result += c - 'A' + 1;
        }
        return result;
    }
};