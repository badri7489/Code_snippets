/**
  * Take 1st as constant at a time and solve the rest as the Two sum problem.
  */

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
            int low = i + 1, high = nums.size() - 1;
            int sumi = -nums[i];
            while (low < high) {
                if (nums[low] + nums[high] < sumi) {
                    low++;
                } else if (nums[low] + nums[high] > sumi) {
                    high--;
                } else {
                    ans.push_back(vector<int> {nums[i], nums[low], nums[high]});
                    while (low < high && nums[low] == nums[low + 1])
                        low++;
                    while (low < high && nums[high] == nums[high - 1])
                        high--;
                    low++;
                    high--;
                }
            }
        }
    }
    return ans;
}
