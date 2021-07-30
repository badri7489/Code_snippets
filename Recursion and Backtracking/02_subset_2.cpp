#include<bits/stdc++.h>
using namespace std;

void helper(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
    ans.push_back(ds);
    for (int i = index; i < nums.size(); i++) {
        if (i != index && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        helper(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    vector<int> ds;
    helper(0, nums, ds, ans);
    return ans;
}
