#include "header.h"
class Solution {
private: 
    bool check(int n, unordered_set<int> &set) {
        if (n == 1) return true;
        int next = 0;
        while (n) {
            next += pow(n%10, 2);
            n /= 10;
        }
        if (set.count(next) > 0) return false;
        set.insert(next);
        return check(next, set);
    }
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        return check(n, set);    
    }
};