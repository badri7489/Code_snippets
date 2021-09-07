#include<bits/stdc++.h>
using namespace std;

int getMaximumGenerated(int n) {
    if (n == 0)
        return 0;
    vector<int> nums(n + 1, 0);
    nums[1] = 1;
    int maxi = 1;
    for (int i = 2; i <= n; i++) {
        nums[i] = (i % 2) ? nums[i / 2] + nums[i / 2 + 1] : nums[i / 2];
        maxi = max(nums[i], maxi);
    }
    return maxi;
}