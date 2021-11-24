#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        if (arr.size() < 3) // if array size is less than 3.
            return false;
        int n = arr.size(), left = INT32_MAX, mid = INT32_MAX;
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid)   // if we find element greater than mid.
                return true;
            else if (arr[i] > left && arr[i] < mid) // we change the mid.
                mid = arr[i];
            else if (arr[i] < left) // we change the left.
                left = arr[i];
        }
        return false;
    }
};