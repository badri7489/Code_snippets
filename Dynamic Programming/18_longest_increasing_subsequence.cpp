#include<iostream>
#include<vector>
using namespace std;

// DP approach
int lengthOfLIS(vector<int>& arr) {
    int n = arr.size(), maxi = 1, ans = 1;
    vector<int> dp(n, 1);   // Stores the LIS which will end at arr[i]
    for (int i = 1; i < n; i++) {
        maxi = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i])
                maxi = max(dp[j], maxi);
        }
        dp[i] = maxi + 1;
        ans = max(dp[i], ans);  // Stores the maximum of all the LIS.
    }
    return ans;
}

int lowerIndex(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int lengthOfLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp;
    dp.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (dp.back() < arr[i]) {
            dp.push_back(arr[i]);
        } else {
            int index = lowerIndex(dp, arr[i]);
            // int index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin(); By using the stl function.
            dp[index] = arr[i];
        }
    }
    return dp.size();
}