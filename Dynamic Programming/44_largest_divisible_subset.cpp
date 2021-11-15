#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());   // Sorting as a % b == 0 if b >= 0, so we have to check only one and not twice.
        int n = arr.size(), maxi = 1;
        vector<int> dp(n, 1);   // Calculating the Longest Increasing Subsequence
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0)   // with just a little bit of modification(the dividibility check).
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            maxi = max(maxi, dp[i]);
        }
        int prev = -1;  // Previous element
        vector<int> ans;
        // Traversing the dp array to get the longest subsequence.
        for (int i = n - 1; i >= 0; i--) {
            // If value is equal to maxi and is divisible by previous then we store it.
            if (maxi == dp[i] && (prev == -1 || prev % arr[i] == 0)) {
                ans.push_back(arr[i]);
                maxi--;
                prev = arr[i];
            }
        }
        return ans;
    }
};