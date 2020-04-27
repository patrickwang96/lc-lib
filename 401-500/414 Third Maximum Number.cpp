#include "header.h"
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long n1 = (long)INT_MIN-1, n2 = (long)INT_MIN  -1, n3 = (long)INT_MIN-1;
        
        for (auto i : nums) {
            if (i > n1) {
                n3 = n2;
                n2 = n1;
                n1 = i;
            } else if (i > n2 && i < n1) {
                n3 = n2;
                n2 = i;
            } else if (i > n3 && i < n2) {
                n3 = i;
            }
        }
        if (n3 != (long)INT_MIN - 1) return n3;
        return n1; 
    }
};