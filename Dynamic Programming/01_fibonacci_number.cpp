#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int fib(int N) {
    if (N == 0)  return 0;
    if (N == 1)  return 1;
    return fib(N - 1) + fib(N - 2);
}

// Dynamic Approach
int fib(int n) {
    if (n == 0)
        return 0;
    vector<int> f(n + 1);
    f[0] = 0, f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}