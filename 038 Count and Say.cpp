#include "header.h"
// https://leetcode.com/problems/count-and-say/
class Solution {

public:
    string countAndSay(int n) {
        string buf = "1";
        string next = buf;
        int counter;
        char cur;
        for (int i = 1; i < n; i++) {
            cur = buf[0];
            counter = 1;
            next = "";
            for (int j = 1; j < buf.size(); j++) {
                if (buf[j] == buf[j-1]){
                    counter++;
                } else {
                    next += to_string(counter);
                    counter = 1;
                    next += cur;
                    cur = buf[j];
                }
            }
            if (counter){
                next += to_string(counter);
                next += cur;
            }
            buf = next;
        }
        
        return buf;
    }
};
