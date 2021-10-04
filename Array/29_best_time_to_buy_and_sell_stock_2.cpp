#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size(), pro = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1])
                pro += arr[i] - arr[i - 1]; // We add the difference of any two increasing sequence(valley peak).
        }
        return pro;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size(), buy_date = 0, sell_date = 0, profit = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] <= arr[i])
                sell_date++;    // Increasing the sell date until we find a peak.
            else {
                profit += arr[sell_date] - arr[buy_date];   // Calculating profit when we find the drop.
                sell_date = buy_date = i;   // Changing sell and buy date to current date.
            }
        }
        profit += arr[sell_date] - arr[buy_date];
        return profit;
    }
};