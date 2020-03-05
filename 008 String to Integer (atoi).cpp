#include "header.h"
// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string str) {
        const char * cstr = str.c_str();
        char *head;
        head = (char*)cstr;
        while (*head == ' ') head++;
        
        bool sign;
        if (*head == '-') {
            sign = false;
            head++;
        }
        else if (*head == '+') {
            sign = true;
            head++;
        }
        else if (*head - '0' <= 9 && *head - '0' >= 0) sign = true;
        else return 0;
        
        if (*head - '0' > 9 || *head - '0' < 0) return 0;
        
        long long result = 0;
        int digit = 0;
        for (head;*head - '0' <= 9 && *head - '0' >= 0; head++) {
            digit = *head - '0';
            if (sign &&result * 10 + digit <= INT_MAX){
                result *= 10;
                result += digit;
            }
            else if ((!sign) && result * 10 + digit - 1 <= INT_MAX) {
                result = result * 10 + digit;
            }
            else {
                if (sign) return INT_MAX;
                else return INT_MIN;
            }
        }
        
        if (sign) return result;
        else return -1 * result;
    }
};