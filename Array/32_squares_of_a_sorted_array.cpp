#include<iostream>
#include<vector>
using namespace std;

// My Solution
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i, n = nums.size();
        for (i = 0; i < n; i++) {
            if (nums[i] >= 0)   // Find the point from where numbers are positive
                break;
        }
        int j = i - 1, k = 0;
        vector<int> ans(n, 0);
        while (j >= 0 && i < n) {   // Go in opposite directions till the end.
            if (nums[i] > abs(nums[j])) {
                ans[k++] = nums[j] * nums[j];
                j--;
            } else {
                ans[k++] = nums[i] * nums[i];
                i++;
            }
        }
        while (j >= 0)  // If left side is incomplete
            ans[k++] = nums[j] * nums[j], j--;
        while (i < n)   // If right side is incomplete
            ans[k++] = nums[i] * nums[i], i++;
        return ans;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1, i = n - 1;
        vector<int> ans(n, 0);
        while (l <= r) {    // Start from both the ends and fill from the ending.
            if (abs(nums[l]) < abs(nums[r])) {
                ans[i--] = nums[r] * nums[r];
                r--;
            } else {
                ans[i--] = nums[l] * nums[l];
                l++;
            }
        }
        return ans;
    }
};