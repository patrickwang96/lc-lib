#include "header.h"
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dic;
        for (auto c: magazine) dic[c]++;
        
        for (auto c: ransomNote) dic[c]--;
        
        for (auto e: dic) if (e.second < 0) return false;
        return true;
    }
};