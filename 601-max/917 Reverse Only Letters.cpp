#include "header.h"
class Solution {
private:
    inline bool isLetter(char c) {
        return (c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a');
    }
public:
    string reverseOnlyLetters(string S) {
        if (S.size() < 2) return S;
        
        int i = 0, j = S.size() - 1;
        
        while (i < j) {
            if (!isLetter(S[i])) {
                i++;
                continue;
            }
            if (!isLetter(S[j])) {
                j--;
                continue;
            }
            
            swap(S[i], S[j]);
            i++; j--;
        }
        return S;
        
        
    }
};