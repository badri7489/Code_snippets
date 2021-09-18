#include<iostream>
#include<string>
using namespace std;

string convertToTitle(int c) {
    string ans = "";
    while (c) {
        c--;    // To adjust for the value of 'Z'.
        ans = char(c % 26 + 'A') + ans;
        c /= 26;
    }
    return ans;
}