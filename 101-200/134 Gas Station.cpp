#include "header.h"
// https://leetcode.com/problems/gas-station/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int result = 0;
        int total = 0;
        vector<int> delta(gas.size());
        for (int i = 0; i < gas.size(); i++) {
            delta[i] = gas[i] - cost[i];
            total += delta[i];
        }
        if (total < 0) return -1;
        
        for (int i = 0; i < gas.size(); i++) {
            result = i;
            total = 0;
            for (int j = 0; j < gas.size(); j++) {
                total += delta[(i+j)%gas.size()];
                if (total < 0)
                    break;
                else if (j == gas.size() - 1)
                    return i;
            }
            
        }
        return result;
        
    }
};