/**
  * We need to find all the distinct quadruplets which give a target sum.
  * The brute force would be to loop the array 4 times and find them and store them.
  * Then we will at the end try to find all the unique ones and give it as an answer.
  * Better approach would be to loop the array twice and then solve as a two sum question for the right part of the array.
  * We can also take advantage of the situation that the array is sorted to solve the two sum problem.
  * The problem of uniqueness still remains.
  * To solve this, when we are looping over the array we will jump over the values which are repeated.
  * We will do this for i, j, left and right.
  * Hence we won’t find duplicates in the solution.
  * The time complexity for this would be O(n^3), since we have to loop over the array twice and
  * then once more for finding the two sum problem.
  */

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int front = j + 1, back = n - 1, target_2 = target - nums[i] - nums[j];
            while (front < back) {
                int two_sum = nums[front] + nums[back];
                if (two_sum > target_2) {
                    back--;
                } else if (two_sum < target_2) {
                    front++;
                } else {
                    vector<int> res;
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                    res.push_back(nums[front]);
                    res.push_back(nums[back]);
                    ans.push_back(res);
                    while (front < back && nums[front] == res[2])
                        front++;
                    while (front < back && nums[back] == res[3])
                        back--;
                }
            }
            while (j + 1 < n && nums[j] == nums[j + 1])
                j++;
        }
        while (i + 1 < n && nums[i] == nums[i + 1])
            i++;
    }
    return ans;
}
