#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string& s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

int longest_palindrome(string s) {
    int i = 0, len = s.length(), j, maxi = 0;
    while (i < len) {
        j = i;
        while (i < len && s[i] != ' ') i++;
        if (is_palindrome(s, j, i - 1))
            maxi = max(maxi, i - j);
        i++;
    }
    return maxi;
}

int main() {
    string s;
    getline(cin, s);
    cout << longest_palindrome(s);
    return 0;
}