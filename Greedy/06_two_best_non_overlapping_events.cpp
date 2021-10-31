#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end()); // Sort events according to start time
        int n = events.size(), ans = 0, maxi = 0;
        map<int, int> mp;
        while (n--) {
            auto it = mp.upper_bound(events[n][1]); // Trying to find the event in map.
            maxi = max(maxi, events[n][2]); // Get max.
            mp[events[n][0]] = maxi;    // Map the event with max value.
            if (it == mp.end()) // If event not present then check that for maximum.
                ans = max(ans, maxi);
            else    // Else check if the current + any the mapped one for the maximum.
                ans = max(ans, events[n][2] + it->second);
        }
        return ans;
    }
};