/**
  * Only approach is to traverse the whole array and count the number of ones
  * and if we encounter a 0 we store the counter in the max and make the counter zero.
  * Hence we will have the max number of ones.
  * Time will be O(n) and space will be constant.
  */

#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size(), maxi = 0, k = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            k++;
        } else {
            maxi = max(maxi, k);
            k = 0;
        }
    }
    return max(maxi, k);
}