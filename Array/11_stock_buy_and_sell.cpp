/**
  * Brute force solution will be to find out the profit for each possible transaction and
  * determine the max profit with a time complexity of O(n^2).
  * Optimal solution will be to find the minimum price upto the given day and
  * then calculating the profit by subtracting the current price with the minimum and
  * accordingly updating the maxprofit.Here,time complexity will be O(n).
  */

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size(), mini = prices[0], maxi = 0;
    for (int i = 1; i < n; i++) {
        if (maxi < (prices[i] - mini))
            maxi = prices[i] - mini;
        if (mini > prices[i])
            mini = prices[i];
    }
    return maxi;
}
