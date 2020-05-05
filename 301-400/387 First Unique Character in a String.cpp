#include "header.h"
class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size() == 0) return -1;
        unordered_map<char, int> chars;
        for (auto c: s) {
            chars[c]++;
        }
        int index = 0;
        for (index = 0; index < s.size(); index++) {
            if (chars[s[index]] <= 1) return index;
        }
        return -1;
        
    }
};