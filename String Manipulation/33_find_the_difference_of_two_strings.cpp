#include<iostream>
#include<string>
using namespace std;

char findTheDifference(string s, string t) {
    int arr[26] = { 0 };
    for (int i = 0; i < s.length(); i++) {
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']++;
    }
    arr[t[s.length()] - 'a']++;
    for (int i = 0; i < 26; i++) {
        if (arr[i] % 2)
            return i + 'a';
    }
    return ' ';
}

// XORing all the character will leave only one odd character of the two.
char findTheDifference(string s, string t) {
    char c = 0;
    for (int i = 0; i < s.length(); i++)
        c ^= s[i] ^ t[i];
    return c ^ t[s.length()];
}