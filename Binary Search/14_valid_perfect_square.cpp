// Problem link : https://leetcode.com/problems/valid-perfect-square/

#include<bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int num) {
    int l = 1, h = num, m, x;
    while (l <= h) {
        m = l + (h - l) / 2;
        x = num / m;
        if (x == m && num % m == 0)
            return true;
        else if (x < m)
            h = m - 1;
        else
            l = m + 1;
    }
    return false;
}