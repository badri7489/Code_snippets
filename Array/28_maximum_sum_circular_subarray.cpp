#include<iostream>
#include<vector>
using namespace std;

// My Code.
int maxSubarraySumCircular(vector<int>& nums) {
    int sumi = 0, max_sum = INT32_MIN, temp_max_sum = 0;
    int min_sum = INT32_MAX, temp_min_sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        sumi += nums[i];
        temp_max_sum += nums[i];
        if (max_sum < temp_max_sum)
            max_sum = temp_max_sum;
        if (temp_max_sum < 0)
            temp_max_sum = 0;
        temp_min_sum += nums[i];
        if (min_sum > temp_min_sum)
            min_sum = temp_min_sum;
        if (temp_min_sum > 0)
            temp_min_sum = 0;
    }
    if (sumi == min_sum)
        return max_sum;
    return max(max_sum, sumi - min_sum);
}

// Smooth Code.
int maxSubarraySumCircular(vector<int>& A) {
    int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
    for (int& a : A) {
        curMax = max(curMax + a, a);
        maxSum = max(maxSum, curMax);
        curMin = min(curMin + a, a);
        minSum = min(minSum, curMin);
        total += a;
    }
    return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
}