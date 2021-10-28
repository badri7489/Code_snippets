#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "", s2 = "";
        for (char c : s) {
            if (c == '#' && s1.empty())
                continue;
            else if (c == '#')
                s1.pop_back();
            else
                s1.push_back(c);
        }
        for (char c : t) {
            if (c == '#' && s2.empty())
                continue;
            else if (c == '#')
                s2.pop_back();
            else
                s2.push_back(c);
        }
        return s1 == s2;
    }
};

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1, backspace;
        while (true) {
            backspace = 0;
            // Search from back of string s to find all backspaces and skip those many characters.
            while (i >= 0 && (backspace > 0 || s[i] == '#')) {
                backspace += s[i] == '#' ? 1 : -1;
                i--;
            }
            backspace = 0;
            // Search from back of string t to find all backspaces and skip those many characters.
            while (j >= 0 && (backspace > 0 || t[j] == '#')) {
                backspace += t[j] == '#' ? 1 : -1;
                j--;
            }
            if (i >= 0 && j >= 0 && s[i] == t[j])   // Now we check if the ith and jth are equal or not.
                i--, j--;
            else    // Else we break.
                break;
        }
        return i == -1 && j == -1;  // If we reach the end of both the strings the strings are same.
    }
};