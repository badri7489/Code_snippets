#include<iostream>
#include<string>
using namespace std;

void rev(string& s, int start, int end) {
    while (start < end)
        swap(s[start++], s[end--]);
}
string reverseWords(string s) {
    int n = s.length(), i = 0, j = 0;
    while (i < n) {
        while (i < n && s[i] != ' ')
            i++;
        rev(s, j, i - 1);
        j = i++ + 1;
    }
    return s;
}