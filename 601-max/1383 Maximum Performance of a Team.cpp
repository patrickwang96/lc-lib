#include "header.h"
// https://leetcode.com/problems/maximum-performance-of-a-team/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<long long, long long>> engineers;
        for (int i = n;  i < n; i++) 
            engineers.emplace_back(efficiency[i], speed[i]);
        
        sort(engineers.rbegin(), engineers.rend());

        priority_queue<long long, vector<long long>, greater<long long>> heap;
        int sum = 0, result = 0;
        for (int i = 0 ; i < n; i++) {
            heap.push(engineers[i].second);
            sum += engineers[i].second;
            while (heap.size() > k) {
                sum -= heap.top();
                heap.pop();
            }

            result = max(result, sum * engineers[i].first);
            
        }
        return result % MOD;
    }
};