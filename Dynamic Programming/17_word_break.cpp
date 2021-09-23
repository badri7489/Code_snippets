#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

// Recursive Solution
unordered_set<string> st;
bool helper(string& s, int pos) {
    if (pos == s.length())
        return true;
    for (int i = pos; i < s.length(); i++) {
        if (st.find(s.substr(pos, i - pos + 1)) != st.end() && helper(s, i + 1))
            return true;
    }
    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    for (string& a : wordDict)
        st.insert(a);
    return helper(s, 0);
}

// Memoised Solution
unordered_set<string> st;
bool helper(string& s, int pos, vector<int>& memo) {
    if (pos == s.length())
        return true;
    if (memo[pos] != -1)
        return memo[pos];
    for (int i = pos; i < s.size(); i++) {
        if (st.find(s.substr(pos, i - pos + 1)) != st.end() && helper(s, i + 1, memo))
            return memo[pos] = true;
    }
    return memo[pos] = false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    for (string& a : wordDict)
        st.insert(a);
    vector<int> memo(s.length(), -1);
    return helper(s, 0, memo);
}

// DP
bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    vector<bool> dp(n + 1);
    dp[0] = true;
    unordered_set<string> st(wordDict.begin(), wordDict.end());
    for (int end = 1; end <= n; end++) {
        for (int start = 0; start < end; start++) {
            if (dp[start] && st.find(s.substr(start, end - start)) != st.end()) {
                dp[end] = true;
                break;
            }
        }
    }
    return dp[n];
}