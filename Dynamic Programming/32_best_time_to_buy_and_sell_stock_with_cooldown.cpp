#include<iostream>
#include<vector>
using namespace std;

// Using recursion and memoisation. 
class Solution {
private:
    vector<int> memo;
    int helper(vector<int>& arr, int curr) {
        if (curr >= arr.size()) // Base case of out of bound.
            return 0;
        if (memo[curr] != -1)   // If found in the memo array.
            return memo[curr];
        int maxi = 0;
        for (int i = curr + 1; i < arr.size(); i++) {
            if (arr[curr] < arr[i]) // We can sell it on that day and buy again after cooldown time or not sell it.
                maxi = max(maxi, arr[i] - arr[curr] + helper(arr, i + 2));

        }
        maxi = max(maxi, helper(arr, curr + 1));    // We may exclude the current day also.
        return memo[curr] = maxi;
    }
public:
    int maxProfit(vector<int>& prices) {
        memo.resize(prices.size(), -1);
        return helper(prices, 0);
    }
};

// Using the state machine diagram.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> noStock(n, 0), inHand(n, 0), sold(n, 0);
        noStock[0] = 0;
        inHand[0] = -prices[0];
        sold[0] = 0;
        for (int i = 1; i < n; i++) {
            noStock[i] = max(noStock[i - 1], sold[i - 1]);
            inHand[i] = max(inHand[i - 1], noStock[i - 1] - prices[i]);
            sold[i] = inHand[i - 1] + prices[i];
        }
        return max(noStock[n - 1], sold[n - 1]);
    }
};

// Using State machine diagram and not using extra space.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), noStock = 0, inHand = -prices[0], sold = 0, prevSold;
        for (int i = 1; i < n; i++) {
            prevSold = sold;
            sold = inHand + prices[i];
            inHand = max(inHand, noStock - prices[i]);
            noStock = max(noStock, prevSold);

        }
        return max(noStock, sold);
    }
};