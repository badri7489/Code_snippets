#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        if (k <= 1)
            return 0;
        int n = arr.size(), prod = 1, ans = 0, left = 0, right = 0;
        while (right < n) {
            prod *= arr[right]; // Multiply the array elements
            while (prod >= k)
                prod /= arr[left++];    // Divide if greater than k
            ans += right - left + 1;    // Count all the subarrays
            right++;    // increment right
        }
        return ans;
    }
};