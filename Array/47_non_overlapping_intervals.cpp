#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inti) {
        sort(inti.begin(), inti.end());
        vector<int> temp = inti[0];
        int n = inti.size(), count = 0, left = 0, right = 1;
        while (right < n) {
            if (inti[left][1] <= inti[right][0]) {  // Not overlapping
                left = right++;
            } else if (inti[left][1] <= inti[right][1]) {   // Overlapping and right's end is at later than left's end.
                count++;
                right++;    // Remove right.
            } else if (inti[left][1] > inti[right][1]) {    // Overlapping and left's end is at later than right's end.
                count++;
                left = right++; // Remove left and increment right.
            }
        }
        return count;
    }
};