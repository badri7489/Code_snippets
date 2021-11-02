#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();
        // add all intervals ending before newinterval starts
        while (i < n && intervals[i][1] < newInterval[0])
            ans.push_back(intervals[i++]);
        // merge all overlapping intervals to one 
        vector<int> mi = newInterval;
        while (i < n && intervals[i][0] <= newInterval[1]) {
            mi[0] = min(mi[0], intervals[i][0]);
            mi[1] = max(mi[1], intervals[i][1]);
            i++;
        }
        ans.push_back(mi);
        // add the rest of the non overlapping intervals.
        while (i < n)
            ans.push_back(intervals[i++]);
        return ans;
    }
};