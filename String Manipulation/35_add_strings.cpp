#include<iostream>
#include<string>
using namespace std;

string addStrings(string num1, string num2) {
    int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
    string ans = "";
    while (i >= 0 || j >= 0 || carry) {
        carry += i >= 0 ? num1[i] - '0' : 0;
        carry += j >= 0 ? num2[j] - '0' : 0;
        ans = to_string(carry % 10) + ans;
        carry /= 10;
        i--, j--;
    }
    return ans;
}