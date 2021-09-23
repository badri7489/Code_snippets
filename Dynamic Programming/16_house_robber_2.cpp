#include<iostream>
#include<vector>
using namespace std;

int robber(vector<int>& nums) {
    int prev1 = 0, prev2 = 0, temp;
    for (int num : nums) {
        temp = prev1;
        prev1 = max(prev2 + num, prev1);
        prev2 = temp;
    }
    return prev1;
}
int rob(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0];
    vector<int> a(nums.begin() + 1, nums.end());
    vector<int> b(nums.begin(), nums.end() - 1);
    return max(robber(a), robber(b));
}