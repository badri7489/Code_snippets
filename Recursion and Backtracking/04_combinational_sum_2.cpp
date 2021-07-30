/** This is the same as the combination sum 1 problem,
  * with a slight change of using a single number only for once and all the rest of the conditions are the same.
  * Also there aren't supposed to be any duplicates.
  * So we start the recursion from the 0th index.
  * Then inside the recursive function we loop from 0th to the end of the array and include them.
  * If at any point the target becomes 0 then we add the pattern in the answer.
  * The time complexity will be O((2 ^ n) * k). k - size of average pattern.
  * Space complexity will be O(k * x).
  * x - combinations.
  */

#include<bits/stdc++.h>
using namespace std;

void helper(int index, int t, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
    if (t == 0) {
        ans.push_back(ds);
        return;
    }
    for (int i = index; i < nums.size(); i++) {
        if (i != index && nums[i] == nums[i - 1])
            continue;
        if (nums[i] <= t) {
            ds.push_back(nums[i]);
            helper(i + 1, t - nums[i], nums, ds, ans);
            ds.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    helper(0, target, nums, ds, ans);
    return ans;
}
