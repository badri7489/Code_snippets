#include<unordered_map>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        if (m > n)
            return "";
        unordered_map<char, int> mp;
        for (char& c : t)   // Mapping all characters of t
            mp[c]++;
        int i = 0, j = 0, count = 0, len = 1e9, index = -1;
        while (i < n) {
            if (--mp[s[i]] >= 0)    // Decreasing from the front of the window(acquiring)
                count++;
            while (count == m) {    // If we find that we have got all the characters of t then we start releasing.
                if (i - j + 1 < len) {  // Storing max length
                    len = i - j + 1;
                    index = j;
                }
                mp[s[j]]++; // Releasing step.
                if (mp[s[j]] > 0)
                    count--;
                j++;
            }
            i++;
        }
        return len == 1e9 ? "" : s.substr(index, len);
    }
};