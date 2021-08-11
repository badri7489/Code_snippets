/**
  * We have to find the anagrams of a given string in another string s.
  * We can simply brute force this, which will be very complex.
  * Another approach is to find all the anagrams of the pattern and find all of them in the string.
  * Optimal approach would be to use sliding window protocol.
  * Time complexity is O(n).
  * Space complexity is O(m).
  * m: size of the pattern.
  */

#include<bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    // j is the front of the window, i is the back of the window.
    // k is the size of the window, count stores the size of the map.
    int i = 0, j = 0, k = p.length(), n = s.length(), count = 0;
    vector<int> ans;
    unordered_map<char, int> mp;    // Map containg the frequency of all the characters in the pattern.
    for (auto it : p)
        mp[it]++;
    count = mp.size();  // Count keeps check as of how many of the values in the map are 0.
    while (j < n) {
        if (mp.find(s[j]) != mp.end()) {
            mp[s[j]]--;     // Decreasing the count in the map as we find a character using pointer j.
            if (!mp[s[j]])  // If the characters value is 0 we decrease count.
                count--;    // This keeps track of the characters we have found in the string.
        }
        if (j - i + 1 < k)  // Increasing the size of the window.
            j++;
        else if (j - i + 1 == k) {
            if (!count)     // If count is 0 we know that we have the sequence and we take i in the ans.
                ans.push_back(i);
            if (mp.find(s[i]) != mp.end()) {
                // We are increasing the value in the map because we are leaving that element from the window.
                mp[s[i]]++;
                if (mp[s[i]] == 1)
                    count++;    // Increasing the count if value of the character in the map is 1.
            }
            // Moving the window.
            i++;
            j++;
        }
    }
    return ans;
}