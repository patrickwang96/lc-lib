#include "header.h"
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> & i, const vector<int> &j){return i[0] < j[0];});
        if (intervals.size() == 0) return true;
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i][1] > intervals[i+1][0]) return false;
        }
        return true;
    }
};