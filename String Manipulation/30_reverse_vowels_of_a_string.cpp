#include<iostream>
#include<string>
using namespace std;

string reverseVowels(string s) {
    int n = s.length(), start = 0, end = n - 1;
    int vowels[128] = { 0 };
    vowels['a'] = vowels['A'] = 1;
    vowels['e'] = vowels['E'] = 1;
    vowels['i'] = vowels['I'] = 1;
    vowels['o'] = vowels['O'] = 1;
    vowels['u'] = vowels['U'] = 1;
    while (start < end) {
        while (start < end && !vowels[s[start]])
            start++;
        while (end > start && !vowels[s[end]])
            end--;
        swap(s[start++], s[end--]);
    }
    return s;
}