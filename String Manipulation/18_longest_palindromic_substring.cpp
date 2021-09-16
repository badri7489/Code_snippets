#include<bits/stdc++.h>
using namespace std;

string longestPalin(string s) {
    if (s.length() == 1)
        return s;
    int n = s.length(), maxi = 1, i = 0, j = 0, end;
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int k = 0; k < n; k++)
        dp[k][k] = 1;
    for (int k = 0; k < n - 1; k++) {
        if (s[k] == s[k + 1]) {
            dp[k][k + 1] = 1;
            if (maxi != 2)
                maxi = 2, i = k, j = k + 1;
        }
    }
    for (int k = 2; k <= n; k++) {
        for (int start = 0; start < n - k + 1; start++) {
            end = start + k - 1;
            if (s[start] == s[end] && dp[start + 1][end - 1]) {
                dp[start][end] = 1;
                if (maxi < end - start + 1)
                    i = start, j = end, maxi = end - start + 1;
            }
        }
    }
    return s.substr(i, j - i + 1);
}