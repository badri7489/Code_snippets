/**
  * This is a pretty straightforward question, if the array is sorted then it can be done easily.
  * If not then we need to sort the array.
  * Then considering the first as one of the intervals that will be in the answer,
  * we will check the range of each of them one by one and merge them if overlapping,
  * else we will take that interval and start doing the same again.
  * Until the intervals are not finished. The time complexity of this algorithm will be O(n * log(n)).
  * Space complexity of this would be O(n), in the worst case when there is no overlapping of the intervals.
  */

// https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    vector<int> it = intervals[0];
    for (int i = 0; i < intervals.size(); i++) {
        if (it[1] >= intervals[i][0]) {
            it[1] = max(intervals[i][1], it[1]);
        } else {
            ans.push_back(it);
            it = intervals[i];
        }
    }
    ans.push_back(it);
    return ans;
}
