#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

string toGoatLatin(string sentence) {
    string s = "";
    unordered_set<char> vowels({ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' });
    int i = 0, j = 0, n = sentence.length(), count = 0;
    while (i < n) {
        while (i < n && sentence[i] != ' ')
            i++;
        count++;
        if (vowels.find(sentence[j]) != vowels.end())
            s += sentence.substr(j, i - j) + "ma";
        else
            s += sentence.substr(j + 1, i - j - 1) + sentence[j] + "ma";
        j = ++i;
        for (int k = 0; k < count; k++)
            s += "a";
        s += " ";
    }
    return s.substr(0, s.length() - 1);
}