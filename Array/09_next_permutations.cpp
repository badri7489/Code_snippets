/** Here to find the next permutation, there is a particular algorithm which was devised in the 1400’s.
  * The time complexity comes out to be O(n) and space complexity comes out to be O(1).
  */

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    if (nums.size() <= 1)
        return;
    int i = nums.size() - 1, j;
    for (j = nums.size() - 2; j >= 0; j--) {
        if (nums[j] < nums[j + 1])
            break;
    }
    if (j >= 0) {
        while (nums[i] <= nums[j])
            i--;
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + j + 1, nums.end());
}
