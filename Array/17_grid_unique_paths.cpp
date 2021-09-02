/**
  * The question is to find the total number of unique paths from start of the matrix to the end.
  * This is a basic recursive question.
  * We have two choices, one is to go right, other to go down.
  * Hence we can go recursively and find the path which exists.
  * Time complexity would be O(2^n) and space would be the height of the recursive tree.
  * We can optimize the solution by using dp.
  * It is an overlapping subproblem and hence dp can improve the time complexity to O(n * m) and a space of O(n * m).
  * There is a further better optimal solution, which uses combinatorics.
  * As we know that by taking m - 1 + n - 1 steps we will reach the end, and the steps are only down and right.
  * So fact(m + n - 2) / (fact(m - 1) * fact(n - 1)).
  * This can be calculated in O(n) time complexity and constant space.
  */

#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    m--;
    n--;
    int maxi = max(m, n), mini = min(m, n);
    long long f = 1;
    for (int i = m + n, j = 1; i > maxi && j <= mini; i--, j++) {
        f *= i;
        f /= j;
    }
    return (int)f;
}

// DP code
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
    return dp[m - 1][n - 1];
}
