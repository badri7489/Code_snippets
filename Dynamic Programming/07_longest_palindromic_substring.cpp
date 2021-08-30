#include<bits/stdc++.h>
using namespace std;

// DP
string longestPalindrome(string s) {
    if (s.length() == 1)
        return s;
    int n = s.length(), i = 0, j = 0, maxi = 1, end;
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int k = 0; k < n; k++)
        dp[k][k] = 1;
    for (int k = 0; k < n - 1; k++) {
        if (s[k] == s[k + 1])
            dp[k][k + 1] = 1, i = k, j = k + 1, maxi = 2;
    }
    for (int k = 2; k <= n; k++) {
        for (int start = 0; start < n - k + 1; start++) {
            end = start + k - 1;
            cout << "Compairing: " << s.substr(start, end - start + 1) << endl;
            if (s[start] == s[end] && dp[start + 1][end - 1]) {
                dp[start][end] = 1;
                if (maxi < end - start + 1)
                    i = start, j = end, maxi = end - start + 1;
            }
        }
    }
    return s.substr(i, j - i + 1);
}

// Expand Around the center approach.
int expandAroundCenter(string s, int left, int right) {
    if (left > right)
        return 0;
    while (left >= 0 && right < s.length() && s[left] == s[right])
        left--, right++;
    return right - left - 1;
}
string longestPalindrome(string s) {
    if (s.length() == 1)
        return s;
    int start = 0, end = 0, n = s.length();
    for (int i = 0; i < n; i++) {
        int l1 = expandAroundCenter(s, i, i);
        int l2 = expandAroundCenter(s, i, i + 1);
        int l = max(l1, l2);
        if (l > end - start) {
            start = i - (l - 1) / 2;
            end = i + l / 2;
        }
    }
    return s.substr(start, end - start + 1);
}