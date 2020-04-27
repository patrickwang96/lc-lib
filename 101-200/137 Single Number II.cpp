#include "header.h"
// https://leetcode.com/problems/single-number-ii/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum;
        int result = 0;
        for (int i = 0; i < 32; i++){
            sum = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] & 1) sum ++;
                nums[j] = nums[j] >> 1;
            }
            sum %= 3;
            if (sum) {
                result ^= (1 << i);
            }
        }
        return result;
    }
};