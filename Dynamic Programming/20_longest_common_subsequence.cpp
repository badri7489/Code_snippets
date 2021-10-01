#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Recursive
// Time Complexity: O(2^n)
class Solution {
private:
    int lcs(string& a, string& b, int m, int n) {
        if (m == -1 || n == -1) // When string is over.
            return 0;
        if (a[m] == b[n])   // When the subsequences in both string matches.
            return lcs(a, b, m - 1, n - 1) + 1; // Make a call for 1 less in both the strings and add 1 to answer.
        // Take max of the lcs which comes from visiting both sides, going one less on a and one less on b.
        return max(lcs(a, b, m - 1, n), lcs(a, b, m, n - 1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return lcs(text1, text2, text1.length() - 1, text2.length() - 1);
    }
};

// Memoised
// Time Complexity: O(n^2)
// Space Complexity: O(n) + Auxiliary Space
class Solution {
private:
    int lcs(string& a, string& b, int m, int n, vector<vector<int>>& memo) {
        if (m == -1 || n == -1)
            return 0;
        if (memo[m][n] != -1)   // Memoised step which makes it faster.
            return memo[m][n];
        if (a[m] == b[n])
            return memo[m][n] = lcs(a, b, m - 1, n - 1, memo) + 1;
        return memo[m][n] = max(lcs(a, b, m - 1, n, memo), lcs(a, b, m, n - 1, memo));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.length() + 1, vector<int>(text2.length() + 1, -1));
        return lcs(text1, text2, text1.length() - 1, text2.length() - 1, memo);
    }
};

// Tabular
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1])   // When the subsequences in both string matches.
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else// Take max of the lcs which comes from visiting both sides, going one less on a and one less on b.
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};