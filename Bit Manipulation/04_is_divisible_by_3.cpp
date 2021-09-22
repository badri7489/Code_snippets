#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int isDivisible(string s) {
    if (s == "0")
        return 1;
    if (s == "1")
        return 0;
    int odd = 0, even = 0, n = s.length(), bit = 0;
    for (int i = 0; i < n; i++) {
        bit = s[i] - '0';
        if (i % 2 == 0)
            even += bit;
        else
            odd += bit;
    }
    return abs(even - odd) % 3 == 0;
}