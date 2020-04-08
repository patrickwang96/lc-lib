#include "header.h"
// https://leetcode.com/problems/multiply-strings/
class Solution {
private: 
    int charToInt(char c) {return c - '0';}
    string addStrings(string num1, string num2) {
        
        // num1 length is equal or smaller than num2
        if (num1.size() > num2.size()) swap(num1, num2);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string result;
        int carry = 0;
        for (int i = 0; i < num2.size(); i++) {
           
            if (i < num1.size()) {
                int currentResult = num1[i] - '0' + num2[i] - '0' + carry;
                result += '0' + (currentResult % 10);
                carry = currentResult / 10;
            }
            else {
                int currentResult = num2[i] - '0' + carry;
                result += '0' + (currentResult % 10);
                carry = currentResult / 10;
            }
            
        }
        if (carry) {
            result += carry + '0';
        }
        reverse(result.begin(), result.end());

        return result;
     }
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return string("0");
        if (num1.size() > num2.size()) swap(num1, num2);
        
        vector<string> tempStr;
        
        reverse(num1.begin(), num1.end());
        
        for (int place = 0; place < num1.size(); place++) {
            string counter("0");
            int digit = num1[place] - '0';
            for (int i = 0; i < digit; i++) counter = addStrings(counter, num2);
            
            for (int i = 0; i < place; i++) counter += '0';
            tempStr.push_back(counter);
        }
        
        string result("0");
        for (auto s: tempStr) {
            
            result = addStrings(result, s);
        }
        
        return result;
        
    }
};