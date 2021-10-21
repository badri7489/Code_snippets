#include<iostream>
#include<vector>
using namespace std;

// Recursive Code
class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) {
        if (w == 0 || n == 0)
            return 0;
        if (wt[n - 1] <= w)
            return max(knapSack(w - wt[n - 1], wt, val, n - 1) + val[n - 1], knapSack(w, wt, val, n - 1));
        return knapSack(w, wt, val, n - 1);
    }
};

// Memoized Code.
class Solution
{
private:
    vector<vector<int>> dp;
    int knap(int w, int wt[], int val[], int n) {
        if (w == 0 || n == 0)
            return 0;
        if (dp[n][w] != -1)
            return dp[n][w];
        if (wt[n - 1] <= w)
            return dp[n][w] = max(knap(w - wt[n - 1], wt, val, n - 1) + val[n - 1], knap(w, wt, val, n - 1));
        return dp[n][w] = knap(w, wt, val, n - 1);
    }
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) {
        dp.resize(n + 1, vector<int>(w + 1, -1));
        return knap(w, wt, val, n);
    }
};

// Top Down DP.
class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) {
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= w; j++) {
                if (wt[i - 1] <= j)
                    dp[i][j] = max(dp[i - 1][j - wt[i - 1]] + val[i - 1], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][w];
    }
};