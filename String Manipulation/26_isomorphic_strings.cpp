#include<iostream>
#include<unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> char_map; // To map characters of one string to character of other string.
    unordered_map<char, bool> mp;       // To check if charcters of the other string are all mapped or not.
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (char_map.find(s[i]) != char_map.end()) {    // Char of s is mapped with char of t.
            if (char_map[s[i]] != t[i]) // If we find that the char of s which is mapped with char of t are not same then its not isomorphic
                return false;
        } else {
            if (mp[t[i]])   // If char of t is already mapped with char of s and we try to map it again.
                return false;
            char_map[s[i]] = t[i];  // Mapping s[i] to t[i]
            mp[t[i]] = true;        // Marking t[i] as true
        }
    }
    return true;
}

// Instead of mapping s[i] with t[i] we can also keep the index position of them.
bool isIsomorphic(string s, string t) {
    int mp1[256] = { 0 }, mp2[256] = { 0 }, n = s.length();
    for (int i = 0; i < n; i++) {
        if (mp1[s[i]] != mp2[t[i]])
            return false;
        mp1[s[i]] = i + 1;  // Index + 1 position is mapped.
        mp2[t[i]] = i + 1;
    }
    return true;
}