#include "header.h"
class Solution {
private:
    void r(vector<char>& s, int start, int end) {
        if (start >= end) {
            return;
        } else {
            swap(s[start], s[end]);
            r(s, start+1, end-1);
        }
    }
public:
    void reverseString(vector<char>& s) {
        r(s, 0, s.size() -1);
    }
};