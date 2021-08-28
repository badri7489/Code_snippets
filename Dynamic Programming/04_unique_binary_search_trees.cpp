/**
  * To find the number of unique binary search trees for a given number of nodes.
  * When we start calculating it, we find out that it is similar as CATALAN NUMBER.
  * We do this by using DP.
  */

#include<bits/stdc++.h>
using namespace std;

// Using DP.
int numTrees(int n) {
    vector<int> ans(n + 1, 0);
    ans[0] = ans[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++)
            ans[i] += ans[j] * ans[i - j - 1];
    }
    return ans[n];
}

// Binomial Formula.
int numTrees(int n) {
    long int res = 1;
    for (int i = 0; i < n; ++i) {
        res *= (2 * n - i);
        res /= (i + 1);
    }
    return res / (n + 1);
}