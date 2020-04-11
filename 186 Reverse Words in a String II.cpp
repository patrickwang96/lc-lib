#include "header.h"
// https://leetcode.com/problems/reverse-words-in-a-string-ii/
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int p1=0, p2=0;
        while (p2 < s.size() && p1 < s.size()) {
            if (p2 == s.size() - 1){
                reverse(s.begin() + p1, s.begin() + p2+1);
                p2++;
            } else if (s[p2] != ' '){
                p2++;
            } else {
                reverse(s.begin() + p1, s.begin() +p2);
                p1 = p2+1;
                p2 = p1;
            }
        }
    }
};