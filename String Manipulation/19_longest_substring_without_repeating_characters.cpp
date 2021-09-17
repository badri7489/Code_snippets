#include<bits/stdc++.h>
using namespace std;

// Using map
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp;
    int i = 0, j = 0, n = s.length(), maxi = 0;
    while (i < n) {
        mp[s[i]]++;
        if (mp.size() == i - j + 1) {
            maxi = mp.size() > maxi ? mp.size() : maxi;
        } else if (mp.size() < i - j + 1) {
            while (mp.size() < i - j + 1) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    mp.erase(s[j]);
                }
                j++;
            }
        }
        i++;
    }
    return maxi;
}

// Using set
int lengthOfLongestSubstring(string s) {
    unordered_set<char> st;
    int i = 0, j = 0, n = s.length(), ans = 0;
    while (i < n && j < n) {
        if (st.find(s[i]) == st.end()) {
            st.insert(s[i++]);
            ans = max(ans, i - j);
        } else {
            s.erase(s[j++]);
        }
    }
    return ans;
}

// Linear Time and constant space.
int lengthOfLongestSubstring(string s) {
    vector<int> mp(256, -1);
    int left = 0, right = 0, n = s.length(), ans = 0;
    while (right < n) {
        if (mp[s[right]] != -1)
            left = max(left, mp[s[right]] + 1);
        mp[s[right]] = right;
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}