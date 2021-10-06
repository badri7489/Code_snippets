/**
  * Codechef.
  * You are given an integer N.
  * Consider the sequence containing the integers 1,2,…,N in increasing order (each exactly once.
  * Find the length of the longest subarray in this sequence such that
  * the bitwise AND of all elements in the subarray is positive.
  * Input: 7
  * Output: 4
  * Input: 1
  * Output: 1
  * Input: 2
  * Output: 1
  */
#include<iostream>
#include<cmath>
using namespace std;

// Just look and try to find the pattern.
int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        int x = log2(n);
        int ans1 = pow(2, x - 1);
        int ans2 = n - pow(2, x) + 1;
        cout << max(ans1, ans2) << endl;
    }
}