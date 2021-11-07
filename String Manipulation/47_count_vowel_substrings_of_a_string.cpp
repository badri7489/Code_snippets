#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        if (n < 5)
            return 0;
        int count = 0, vow = 0, j = 0, k = 0;
        unordered_map<char, int> mp{ {'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0} };
        for (int i = 0; i < n; i++) {
            if (mp.count(word[i])) {    // Checking for vowels
                mp[word[i]]++;
                if (mp[word[i]] == 1)   // increasing vowel count
                    vow++;
                while (vow == 5) {  // If we get all 5 vowels, we count the number of substrings
                    mp[word[k]]--;  // We decrease the window.
                    if (mp[word[k]] == 0)   // If a vowel count is 0 we decrease the vowel count.
                        vow--;
                    k++;
                }
                count += (k - j);   // Count the vowels.
            } else {
                mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = vow = 0;  // Make all to 0
                j = k = i + 1;  // move the window.
            }
        }
        return count;
    }
};