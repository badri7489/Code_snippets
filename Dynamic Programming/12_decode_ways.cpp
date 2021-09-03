#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int helper(string s, int i) {
    if (s.length() == i)    // Recursively we reach the end of the string so we return 1.
        return 1;
    if (s[i] == '0')    // First character of any substring is 0 then it is not valid.
        return 0;
    int ans = helper(s, i + 1); // Taking 1 charachter at a time.
    if (i + 1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))    // Condition check for 2 character.
        ans += helper(s, i + 2);    // Taking 2 character at a time.
    return ans;
}
int numDecodings(string s) {
    return helper(s, 0);
}

// Memoised Approach
int helper(string s, int i, vector<int>& memo) {
    if (memo[i] != -1)
        return memo[i];
    if (s.length() == i)
        return 1;
    if (s[i] == '0')
        return memo[i] = 0;
    int ans = helper(s, i + 1, memo);
    if (i + 1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
        ans += helper(s, i + 2, memo);
    return memo[i] = ans;
}
int numDecodings(string s) {
    vector<int> memo(s.length() + 1, -1);
    return helper(s, 0, memo);
}

// DP Bottom Up Approach
int numDecodings(string s) {
    int n = s.length();
    vector<int> dp(n + 1);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0')
            dp[i] = 0;
        else {
            dp[i] = dp[i + 1];
            if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
                dp[i] += dp[i + 2];
        }
    }
    return dp[0];
}

// DP Top Down Approach
int numDecodings(string s) {
    int n = s.length();
    int dp[n];
    dp[0] = (s[0] != '0') ? 1 : 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '0' && s[i] == '0') {
            dp[i] = 0;
        } else if (s[i - 1] == '0' && s[i] != '0') {
            dp[i] = dp[i - 1];
        } else if (s[i - 1] != '0' && s[i] == '0') {
            if (s[i - 1] == '1' || s[i - 1] == '2')
                dp[i] = i >= 2 ? dp[i - 2] : 1;
            else
                dp[i] = 0;
        } else {
            if (stoi(s.substr(i - 1, 2)) <= 26)
                dp[i] = dp[i - 1] + (i >= 2 ? dp[i - 2] : 1);
            else
                dp[i] = dp[i - 1];
        }
    }
    return dp[n - 1];
}

// DP Constant Memory Approach
int numDecodings(string s) {
    int n = s.length(), p = 1, pp;
    for (int i = n - 1; i >= 0; i--) {
        int curr = s[i] == '0' ? 0 : p; //contains dp[i - 1].
        if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) // check if 2 digits are valid or not.
            curr += pp; // Updates for 2 digits from pp.
        pp = p; // contains dp[i - 2].
        p = curr;   // contains dp[i - 1].
    }
    return p;
}