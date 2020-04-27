#include "header.h"
class Solution {
private:
    bool check(string s) {
        int counter = 0;
        for (auto c: s) {
            if (c == '(') counter++;
            else if (c == ')') {
                counter--;
                if (counter < 0) return false;
            }
        }
        return counter == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        
        vector<string> ret;
        unordered_set<string> checked;
        
        queue<string> to_check;
        
        checked.insert(s);
        to_check.push(s);
        
        bool found = false;
        
        while (!to_check.empty()) {
            auto cur = to_check.front();
            to_check.pop();
            
            if (check(cur)) {
                ret.push_back(cur);
                found = true;
            }
            
            // if found, do not do further removal on the str
            if (found) continue; 
            
            for (int i = 0; i < cur.size(); i++) {
                // remove one char to gen a new node to search
                if (cur[i] == '(' || cur[i] == ')') {
                    auto candidate = cur.substr(0, i) + cur.substr(i+1);
                    if (checked.count(candidate) == 0) {
                        to_check.push(candidate);
                        checked.insert(candidate);
                    }
                }
            } 
        }
        return ret;
        
    }
};