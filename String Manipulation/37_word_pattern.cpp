#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<char, string> mp;
    unordered_map<string, bool> mp2;
    int n = s.length(), m = pattern.length(), i = 0, j = 0, k = 0, count = 0;
    string temp = "";
    while (i < n && j < m) {
        while (k < n && s[k] != ' ')
            k++;
        count++;
        if (mp.find(pattern[j]) != mp.end()) {
            if (mp[pattern[j]] != s.substr(i, k - i))
                return false;
        } else {
            if (mp2[s.substr(i, k - i)])
                return false;
            mp[pattern[j]] = s.substr(i, k - i);
            mp2[s.substr(i, k - i)] = true;
        }
        i = ++k;
        j++;
    }
    if (j < m || i < n)
        return false;
    return true;
}