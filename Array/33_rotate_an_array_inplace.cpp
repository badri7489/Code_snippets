#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // If k > n.
        if (k == 0)
            return;
        reverse(nums.begin(), nums.end());  // Reverse the whole array.
        reverse(nums.begin(), nums.begin() + k);    // Reverse the first k elements.
        reverse(nums.begin() + k, nums.end());  // Reverse the last n - k elements.
    }
};
