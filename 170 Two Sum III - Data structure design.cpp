#include "header.h"
// https://leetcode.com/problems/two-sum-iii-data-structure-design/
class TwoSum {
private:
    unordered_map<int, int> container;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        if (container.count(number) == 0) {
            container[number] = 1;
        }else {
            container[number]++;
        }
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto i: container) {
            int need = value - i.first;
            if (need == i.first && i.second >= 2) {
                return true;
            } else if (need != i.first && container.count(need)) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */