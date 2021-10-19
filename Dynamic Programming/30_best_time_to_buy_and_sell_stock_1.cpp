/**
  * Brute force solution will be to find out the profit for each possible transaction and
  * determine the max profit with a time complexity of O(n^2).
  * Optimal solution will be to find the minimum price upto the given day and
  * then calculating the profit by subtracting the current price with the minimum and
  * accordingly updating the maxprofit.Here,time complexity will be O(n).
  */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], pro = 0, n = prices.size();
        for (int i = 1; i < n; i++) {
            mini = min(prices[i], mini);
            pro = max(pro, prices[i] - mini);
        }
        return pro;
    }
};