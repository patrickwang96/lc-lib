#include "header.h"
// https://leetcode.com/problems/add-binary/
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) swap(a, b);
        auto a_ptr = a.end();
        auto b_ptr = b.end(); 
        string result;
        int carry = 0;
        int num1 = 0;
        int num2 = 0;
        int tmp = 0;
        while (a_ptr != a.begin() && b_ptr != b.begin()) {
            if (*a_ptr == '0') num1 = 0;
            else num1 = 1;
            
            if (*b_ptr == '0') num2 = 0;
            else num2 = 1;
            tmp = num1 + num2 + carry;
            carry = tmp / 2;
            tmp %= 2;
            a_ptr++; b_ptr++;
            
            result.insert(0, '0' + tmp);
        }
        while (a_ptr != a.begin()) {
            if (*a_ptr == '0') num1 = 0;
            else num1 = 1;
            
            tmp = num1 + carry;
            carry = tmp / 2;
            tmp %= 2;
            a_ptr++;
            
            result.insert(0, '0' + tmp);
        }
        return result;
    }
};