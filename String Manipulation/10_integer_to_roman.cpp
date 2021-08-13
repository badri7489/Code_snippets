#include<bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
    string roman[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    int i = 0;
    string ans = "";
    for (int i = 0; num != 0; i++) {
        while (num >= value[i]) {
            num -= value[i];
            ans += roman[i];
        }
    }
    return ans;
}