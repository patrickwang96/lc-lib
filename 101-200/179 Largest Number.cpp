#include "header.h"
// https://leetcode.com/problems/largest-number/
class Solution {
private:
    // inline static int digitCount(int num) {
    //     int result = 0;
    //     while (num) {
    //         result++;
    //         num /= 10;
    //     }
    //     return result;
    // }
    // bool static compare(int x, int y) {
    //     int xl = digitCount(x);
    //     int yl = digitCount(y);
    //     if (xl == yl) return x > y;
    //     else {
    //         for (int i = 1; i < xl; i++) x /= 10;
    //         for (int i = 1; i < yl; i++) y /= 10;
    //         return x > y;
    //     }
    // }
    
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y){
            return to_string(x)+to_string(y) > to_string(y) + to_string(x);
        });
        string result;
        for (auto i: nums)
            result += to_string(i);
        return result[0] == '0' ? "0" : result;
        
    }
};