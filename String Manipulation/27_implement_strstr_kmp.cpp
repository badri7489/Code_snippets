#include<iostream>
#include<string>
#include<vector>
using namespace std;

int strstr(string haystack, string needle) {
    int m = haystack.length(), n = needle.length();
    for (int i = 0; i <= m - n; i++) {
        int j = 0;
        for (; j < n; j++) {
            if (haystack[i + j] != needle[j])
                break;
        }
        if (j == n)
            return i;
    }
    return -1;
}

vector<int> prefix_suffix(string s) {
    int j = 0, n = s.length();
    vector<int> lps(n, 0);
    for (int i = 1; i < n;) {
        if (s[i] == s[j])
            lps[i++] = ++j;
        else if (j)
            j = lps[j - 1];
        else
            lps[i++] = 0;
    }
    return lps;
}
int strStr(string haystack, string needle) {
    int m = haystack.length(), n = needle.length();
    if (!n)
        return 0;
    vector<int> lps = prefix_suffix(needle);
    for (int i = 0, j = 0; i < m;) {
        if (haystack[i] == needle[j])
            i++, j++;
        if (j == n)
            return i - j;
        if (i < m && haystack[i] != needle[j])
            j ? j = lps[j - 1] : i++;
    }
    return -1;
}