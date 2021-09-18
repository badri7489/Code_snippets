#include<iostream>
#include<string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    int arr[26] = { 0 };
    for (char& c : ransomNote)
        arr[c - 'a']++;
    for (char& c : magazine) {
        if (arr[c - 'a'])
            arr[c - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (arr[i])
            return false;
    }
    return true;
}