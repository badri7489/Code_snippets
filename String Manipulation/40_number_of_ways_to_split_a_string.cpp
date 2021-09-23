#include<iostream>
#include<string>
using namespace std;

int numWays(string s) {
    long long ones = 0, n = s.length(), MOD = 1000000007;
    for (char& c : s)
        ones += c - '0';
    if (ones == 0)
        return (((n - 1) * (n - 2)) / 2) % MOD;
    if (ones % 3 != 0)
        return 0;
    long long onethird = ones / 3;
    ones = 0;
    long long way1 = 0, way2 = 0;
    for (char& c : s) {
        ones += c - '0';
        if (ones == onethird)
            way1++;
        if (ones == 2 * onethird)
            way2++;
    }
    return (way1 * way2) % MOD;
}