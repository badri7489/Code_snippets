/**
  * Brute force will cause Time Limit Exceeded error will come.
  * Use Seive of Erasthones method is used.
  * Time complexity will reduce to O(n * log(n) * log(n)).
  */

#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    if (n == 0 || n == 1)
        return 0;
    vector<int> vis(n, 0);
    for (int i = 2; i * i < n; i++) {
        if (!vis[i]) {
            for (int j = i + i; j < n; j += i)
                vis[j] = 1;
        }
    }
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (!vis[i])
            count++;
    }
    return count;
}