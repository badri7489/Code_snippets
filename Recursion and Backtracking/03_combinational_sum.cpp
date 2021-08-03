/**
  * We need to find the numbers from the array that sum up to a given target
  * and a particular number can be picked any number of times.
  * So we will start recursively and starting from the 0th index we begin to make calls.
  * There are two recursion calls to be made.
  * First recursion takes the ith element and reduces the target value, but doesn’t change the index it is at.
  * This means that the ith number is to be taken into consideration until target is reached or target is exhausted.
  * Second recursion doesn’t take the ith number and calls a recursive call to the (i + 1)th number.
  * Base case is when i == n, then we check if the target is 0 or not.
  * If target is 0 then the pattern is stored else the pattern is not stored.
  * The time complexity is O((2 ^ t) * k), where k - average length of a pattern, that means it is the time to put it in the ans.
  * t - is recursive calls made.
  * Space complexity will be O(k * x). x - combinations.
  */

#include<bits/stdc++.h>
using namespace std;

void helper(vector<int>& nums, int i, int t, vector<int>& ds, vector<vector<int>>& ans) {
    if (i == nums.size()) {
        if (t == 0)
            ans.push_back(ds);
        return;
    }
    if (nums[i] <= t) {
        ds.push_back(nums[i]);
        helper(nums, i, t - nums[i], ds, ans);
        ds.pop_back();
    }
    helper(nums, i + 1, t, ds, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    helper(candidates, 0, target, ds, ans);
    return ans;
}