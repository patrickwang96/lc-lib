#include "header.h"
// https://leetcode.com/problems/reverse-words-in-a-string/
class Solution {
public:
    string reverseWords(string s) {
        
        if (s.size() == 0) return string("");
        string result;
        stack<string> words;
        
        int ptr = 0;
        while (ptr < s.size()) {
            if (s[ptr] == ' ') ptr++;
            else {
                int end = ptr;
                while (end < s.size() && s[end] != ' ') end++;
                words.push(s.substr(ptr, end - ptr ));
                ptr = end + 1;
            }
        }
        while (!words.empty()) {
            result += ' ';
            result += words.top();
            words.pop();
        }
        if (result.size() == 0) return result;
        return result.substr(1);
    }
};