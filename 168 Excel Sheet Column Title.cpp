#include "header.h"
// https://leetcode.com/problems/excel-sheet-column-title/
class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n) {
            if (n % 26 == 0) {
                result.push_back('Z');
                n -= 26;
            }
            else {
                char c = n % 26 + 'A' - 1;
                result.push_back(c);
            }
            n /= 26;
        }
        string a(result.rbegin(), result.rend());
        return a;
    }
};