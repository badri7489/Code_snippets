#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int titleToNumber(string c) {
    int ans = 0, n = c.length();
    for (int i = 0; i < n; i++) {
        ans += int(pow(26, n - i - 1)) * (c[i] - 64);
    }
    return ans;
}