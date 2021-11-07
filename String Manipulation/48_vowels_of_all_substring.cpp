#include<iostream>
using namespace std;

class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    long long countVowels(string word) {
        long long n = word.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(word[i]))
                ans += (n - i) * (i + 1);   // Contribution of each character in substrings
        }
        return ans;
    }
};