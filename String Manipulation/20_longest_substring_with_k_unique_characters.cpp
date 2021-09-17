#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k) {
    int i = 0, j = 0, ans = -1, n = s.length();
    unordered_map<char, int> mp;
    while (j < n) {
        mp[s[j]]++; // Storing all characters in the map.
        if (mp.size() == k) {   // When map size is k means map has k distinct characters.
            ans = max(ans, j - i + 1);  // Then we store the current window size.
        } else if (mp.size() > k) {     // No. of distinct elements is more than k.
            while (mp.size() > k) {
                mp[s[i]]--;             // We start decreasing count of each element.
                if (mp[s[i]] == 0)      // We remove the element once its count becomes 0.
                    mp.erase(s[i]);
                i++;    // Back of the window is moved by 1.
            }
        }
        j++;    // Front of the window is moved by 1.
    }
    return ans;
}