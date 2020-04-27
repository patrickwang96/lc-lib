#include "header.h"
class Solution {
private:
    vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    vector<string> v3 = {"Thousand", "Million", "Billion"};
    
    string parse_under_1000(int num) {
        
        string result;
        
        auto a = num / 100;
        auto b = num % 100;
        auto c = num % 10;
        
        result = b < 20 ? v1[b] : v2[b/10] + (c ? " " + v1[c] : "");
        if (a>0) result = v1[a] + " Hundred" + (b ? " " + result : "");
        return result;
        
    }
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res = parse_under_1000(num % 1000);
        for (int i = 0; i < 3; ++i) {
            num /= 1000;
            res = num % 1000 ? parse_under_1000(num % 1000) + " " + v3[i] + " " + res : res;
        }
        while (res.back() == ' ') res.pop_back();
        return res.empty() ? "Zero" : res;
        
    }
};