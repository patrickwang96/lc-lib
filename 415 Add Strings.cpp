#include "header.h"
class Solution {
public:
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
};