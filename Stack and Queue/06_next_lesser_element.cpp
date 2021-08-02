/**
 * This is same as finding the next greater element to the right.
 */

#include<bits/stdc++.h>
using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    stack<int> stk;
    vector<int> ans(n, -1);

    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && prices[i] < stk.top())
            stk.pop();
        if (!stk.empty())
            ans[i] = prices[i];
        stk.push(prices[i]);
    }
    return ans;
}