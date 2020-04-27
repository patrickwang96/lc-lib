#include "header.h"
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> starts(n);
        vector<int> ends(n);
        
        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int result = 0;
        int p1=0, p2=0;
        for (int i = 0; i < n; i++) {
            if (starts[i] < ends[p2]) result++;
            else {
                p2++;
            }
        }
        return result;
        
        
    }
};