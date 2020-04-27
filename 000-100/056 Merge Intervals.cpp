#include "header.h"
// https://leetcode.com/problems/merge-intervals/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.size() == 0) return result;
        sort(intervals.begin(), intervals.end(), comp);
        int start = intervals[0].start;
        int end = intervals[0].end;
        
        for (auto i: intervals) {
            if (i.start <= end) end = max(i.end, end); // merge
            else {
                Interval tmp(start, end);
                result.push_back(tmp);
                start = i.start;
                end = max(i.end, end);
            }
        }
        
        Interval tmp(start, end);
        result.push_back(tmp);
        return result;
    }
private: 
    static bool comp(const Interval& a, const Interval &b) {
        return a.start < b.start;
    }
 };
 