#include<iostream>
#include<string>
using namespace std;

int longestPalindrome(string s) {
    int alpha[128] = { 0 };
    for (char& i : s)
        alpha[i]++;
    int count = 0, k = 1;
    for (int i = 0; i < 128; i++) {
        if (alpha[i]) {
            if (alpha[i] % 2 == 0)
                count += alpha[i];
            else if (k)
                count += alpha[i], k = 0;
            else
                count += alpha[i] - 1;
        }
    }
    return count;
}