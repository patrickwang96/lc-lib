#include "header.h"
class Solution {
private:
    string make(string s) {
        int p1 = 0, p2 = 0;
        while (p2 < s.size()) {
            if (s[p2] != '#') {
                s[p1] = s[p2];
                p1++;p2++;
            } else if (p1 == 0){
                p2++;
            } else {
                p1--;
                p2++;
            }
        }
        return s.substr(0, p1);
    }
public:
    bool backspaceCompare(string S, string T) {
        S = make(S);
        T = make(T);
        return S == T;
        
    }
};