/**
  * Brute force for this will be to just multiply X, n times with itself.
  * If the powers can be negative then we need to inverse the ans.
  * A slightly better approach is to take the power and if it is divisible by 2
  * then we will multiply X with itself and if not then we will multiply the ans with X.
  * We will be decreasing the powers by 2 if divisible by 2 else decrease by 1.
  */

// https://leetcode.com/problems/powx-n/

#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    double ans = 1.0;
    long long nn = abs(n);
    while (nn) {
        if (nn % 2) {
            ans *= x;
            nn--;
        } else {
            x *= x;
            nn /= 2;
        }
    }
    if (n < 0)
        return (double)(1.0) / ans;
    return ans;
}
