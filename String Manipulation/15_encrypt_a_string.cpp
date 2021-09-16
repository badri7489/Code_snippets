#include<bits/stdc++.h>
using namespace std;

string encryptString(string s) {
    string ans = "";
    int i = 0;
    for (; i < s.length() - 1; i++) {
        int count = 1;
        while (s[i] == s[i + 1])
            count++, i++;
        ans += s[i] + to_string(count);
    }
    if (i < s.length() && s[i] != s[i - 1])
        ans += s[i] + to_string(1);
    reverse(ans.begin(), ans.end());
    return ans;
}