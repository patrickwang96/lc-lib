#include "header.h"

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        if (J.empty() || S.empty()) return 0;
        unordered_set<char> dic;
        for (auto c: J) dic.insert(c);
        
        int count = 0;
        for (auto c: S) {
            if (dic.count(c)) count++;
        }
        return count;
        
    }
};