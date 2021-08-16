#include<bits/stdc++.h>
using namespace std;

vector<int> search(string pat, string txt) {
    vector<int> ans;
    int m = pat.length();
    int n = txt.length();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    int q = 101, d = 256;
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;
    for (i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == m)
                ans.push_back(i + 1);
        }

        if (i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if (t < 0)
                t = t + q;
        }
    }
    if (ans.size())
        return ans;
    return { -1 };
}