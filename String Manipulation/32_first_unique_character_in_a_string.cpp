#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> mp;
    for (char& c : s)
        mp[c]++;
    for (int i = 0; i < s.length(); i++) {
        if (mp[s[i]] == 1)
            return i;
    }
    return -1;
}