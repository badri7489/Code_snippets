#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void helper(vector<int>& arr, vector<vector<int>>& ans, vector<int>& temp, int pos) {
    if (temp.size() > 1)    // If the size of temp array is more than 1 we include in ans
        ans.push_back(temp);
    unordered_set<int> hash;    // Set to check if a certain element is visited or not.
    for (int i = pos; i < arr.size(); i++) {
        // We recusively call only if the temp is empty or back of vector is less than arr[i].
        // Additionally arr[i] must not be present in the hash set, in other words it must not be visited.
        if ((temp.empty() || arr[i] >= temp.back()) && hash.find(arr[i]) == hash.end()) {
            temp.push_back(arr[i]);
            helper(arr, ans, temp, i + 1);
            temp.pop_back();    // Backtracking our foot steps.
            hash.insert(arr[i]);    // Marking the value as visited.
        }
    }
}
vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    helper(nums, ans, temp, 0);
    return ans;
}