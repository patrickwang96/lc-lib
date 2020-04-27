#include "header.h"
// https://leetcode.com/problems/plus-one/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        auto focus = digits.end();
        
        while (focus != digits.begin() && carry) {
            (*focus)++;
            if (*focus > 9) {
                carry = 1;
                *focus %= 10;
            }else carry = 0;
            focus++;
        }
        
        if (carry) digits.insert(focus, 1);
        
            
        return digits;
    }
};