#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, m;
    while (l <= r) {
        m = (l + r) >> 1;
        if (nums[m] == target)  // Element Found.
            return m;
        else if (nums[m] > target)  // Searching in the left half.
            r = m - 1;
        else    // Searching in the right half.
            l = m + 1;
    }
    return -1;  // ELement not found.
}