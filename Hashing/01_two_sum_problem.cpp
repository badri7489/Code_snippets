/**
  * Here we need to find the index of two elements in the array which sum up to a target.
  * Brute force for this would be to take an element and check in the right side for the remainder.
  * This would be a O(n^2) time complexity approach.
  * Better approach would be to use a hashmap to store the difference of the target and the ith value.
  * And at each step we will try to check whether the diff of target and ith value is in the hashmap or not.
  * If not then we will insert it, else we found the solution and return the ans.
  * This is a O(n) time complexity solution and O(n) space complexity solution.
  */

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.find(target - nums[i]) != mp.end()) {
            ans.push_back(mp[target - nums[i]]);
            ans.push_back(i);
            return ans;
        }
        mp[nums[i]] = i;
    }
    return ans;
}
