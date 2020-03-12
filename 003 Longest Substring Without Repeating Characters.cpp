#include "header.h"
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> map;
        int result = 0, ptr = -1;
        for (int i = 0; i < s.size(); i++) {
            if (map.count(s[i]) && map[s[i]] > ptr) {
                ptr = map[s[i]];
            }
            map[s[i]] = i;
            result = max(result, i - ptr);
        }
        return result;
        
    }
};