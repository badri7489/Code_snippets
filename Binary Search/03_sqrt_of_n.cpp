#include<iostream>
using namespace std;

int mySqrt(int x) {
    int l = 1, h = x, m, ans;
    while (l <= h) {
        m = l + (h - l) / 2;
        if (m <= x / m) {
            ans = m;
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    return ans;
}