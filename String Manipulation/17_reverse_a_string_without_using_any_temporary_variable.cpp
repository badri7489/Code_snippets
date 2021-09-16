#include<bits/stdc++.h>
using namespace std;

string rev(string s, int start, int end) {
    while (start < end) {
        s[start] = s[start] ^ s[end];
        s[end] = s[start] ^ s[end];
        s[start] = s[start] ^ s[end];
        ++start, --end;
    }
    return s;
}

int main() {
    string s;
    cin >> s;
    cout << rev(s, 0, s.length() - 1) << endl;
    return 0;
}