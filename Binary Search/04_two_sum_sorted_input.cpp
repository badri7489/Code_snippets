#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int l = 0, h = nums.size() - 1, x;
    while (l < h) {
        x = nums[l] + nums[h];
        if (x == target)
            return { l + 1, h + 1 };
        else if (x > target)
            h--;
        else
            l++;
    }
    return {};
}