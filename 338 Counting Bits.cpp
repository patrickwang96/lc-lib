#include "header.h"
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        if (num == 0) {
            return result;
        }
        else if (num == 1) {
            result[1] = 1;
            return result;
        }
        
        result[1]=1;
        
        int pows = 0;
        int counter = 2;
        while (num >> 1) {
            num >>= 1;
            pows++;
            int tmp = 0;
            
            while (tmp < 1 << pows && counter < result.size()) {
                result[counter++] = result[tmp++] + 1;
            }
            
            if (counter == result.size()) break;
        }
        return result;
        
    }
};