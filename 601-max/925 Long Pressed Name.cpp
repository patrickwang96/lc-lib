#include "header.h"
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (i < name.size() && j < typed.size()) {
            if (name[i] == typed[j]) {
                i++;
                j++;
            } else if (j > 0 && typed[j-1] == typed[j]){
                j++;
            } else return false;
        }
        if (i != name.size()) return false;
        else if (j == typed.size()) return true;
        else {
            for (int k = j; k < typed.size(); k++) {
                if (typed[k] != typed[j]) return false;
            }
            return true;
        }
        
        
    }
};