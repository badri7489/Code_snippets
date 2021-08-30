/**
  * We need to find the total number of integers whose square sum up to give the desired number.
  * We use the DP approach.
  * We create a array of size n + 1 and initialise n = 0, n = 1.
  * Then to calculate for n.
  * We start filling for all the values starting from n.
  * We keep on subtracting 1^2, 2^2, 3^2,.... from i and try to find the remaining in the dp.
  * We store the minimum of them in it.
  * Time complexity: O(n^2).
  * Space complexity: O(n).
  * Lagrange's 4 square Theorem.
  * It says that any natural number can be represented as a sum of squares of only 4 integers.
  * Legendre's 3 square Theorem.
  * It says that any natural number can be represented as a sum of suqares of 3 integers.
  * If any number can be represented in the form of 4^a(8x + 7) then it is a sum of squares of 4 integers.
  * Time Complexity: O(sqrt(n)).
  */

#include<bits/stdc++.h>
using namespace std;

// DP
int numSquares(int n) {
    int dp[n + 1];
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int j = 1, mini = INT32_MAX;
        while (j * j <= i)
            mini = min(mini, dp[i - j * j]), j++;
        dp[i] = mini + 1;
    }
    return dp[n];
}

// Legendre's 3 square Theorem.
int numSquares(int n) {
    if (sqrt(n) == floor(sqrt(n)))  // Checking if the number is a perfect square or not.
        return 1;
    while (n % 4 == 0)              // Divides it by 4 until it is not divisible.
        n /= 4;
    if (n % 8 == 7)                 // Check if it is of the form 8x + 7 or not
        return 4;                   // If yes then we return 4.
    for (int i = 1; i * i <= n; i++) {
        int base = sqrt(n - i * i);
        if (base * base == (n - i * i))     // Check if it is a sum of 2 perfect squares or not.
            return 2;
    }
    return 3;   // All conditions fail then we give 3.
}