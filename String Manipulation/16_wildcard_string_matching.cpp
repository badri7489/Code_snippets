/**
  * https://practice.geeksforgeeks.org/problems/wildcard-string-matching1126/1
  * Here we use dp to solve the question.
  * Bottom up approach is used here.
  */

#include<bits/stdc++.h>
using namespace std;

bool match(string wild, string pattern) {
    int m = wild.length(), n = pattern.size();
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[m][n] = 1;   // No wild will have no pattern, which is true.
    for (int i = m - 1; i >= 0; i--) {
        if (wild[i] == '*')
            dp[i][n] = dp[i + 1][n];
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (wild[i] == '*')
                dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
            else if (wild[i] == '?' || wild[i] == pattern[j])
                dp[i][j] = dp[i + 1][j + 1];
            else
                dp[i][j] = 0;
        }
    }
    return dp[0][0];
}