#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        int a, b, c;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++)
                dp[i] = max({ (i - j) * j, dp[i - j] * j, dp[i] });
        }
        return dp[n];
    }
};

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        int ans = 1;
        while (n > 4) {
            ans *= 3;
            n -= 3;
        }
        ans *= n;
        return ans;
    }
};