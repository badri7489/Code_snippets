#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(26 * size(s2))
// Space Complexity: O(26 * 2)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        if (m > n)
            return false;
        vector<int> hash1(26, 0);   // Hash for s1
        vector<int> hash2(26, 0);   // Hash for s2
        int i = 0, j = 0;
        while (i < m) {
            hash1[s1[i] - 'a']++;   // Count of chars of s1
            hash2[s2[i] - 'a']++;   // COunt of chars of s2 till the size of s1
            i++;
        }
        i--;
        // Now we slide the window and check when do we have maps equal.
        while (i < n) {
            if (hash1 == hash2) // If both the maps are equal we have got the permutation of the string.
                return true;
            i++;
            if (i != n)
                hash2[s2[i] - 'a']++;   // We slide the window forward from the front position.
            hash2[s2[j++] - 'a']--;     // We slide the window forward from the end postion.
        }
        return false;
    }
};

// Time Complexity: O(size(s2))
// Space Complexity: O(26)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp(26, 0);
        for (char& c : s1)
            mp[c - 'a']++;
        int i = 0, j = 0, m = s1.size(), count = m, n = s2.size();
        while (i < n) {
            if (mp[s2[i++] - 'a']-- > 0)
                count--;
            if (count == 0)
                return true;
            if (i - j == m && mp[s2[j++] - 'a']++ >= 0)
                count++;
        }
        return false;
    }
};