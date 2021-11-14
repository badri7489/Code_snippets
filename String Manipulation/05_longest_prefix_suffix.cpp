/**
  * Here we need to find the longest prefix which is also a suffix.
  * We use the Knuth Morris Pratt(KMP) Algorithm in this question.
  * We use the preprocessing step which is used in the KMP algorithm.
  * We build the lps array which stores the value:
  * lps[i] = the longest proper prefix of pattern[0..i] which is also a suffix of pattern[0..i].
  * Time complexity is O(n).
  * Space complexity is O(n).
  */

#include<bits/stdc++.h>
using namespace std;

int lps(string s) {
    vector<int> arr(s.length() + 1);
    for (int sp = 1, pp = 0; sp < s.length();) {
        if (s[pp] == s[sp] || pp == 0) {
            pp = s[pp] == s[sp] ? pp + 1 : 0;
            arr[++sp] = pp;
        } else {
            pp = arr[pp];
        }
    }
    return arr[s.length()];
}

class Solution {
public:
    int lps(string s) {
        int n = s.length(), index = 0, ans = 0;
        vector<int> arr(n, 0);
        for (int i = 1; i < n;) {
            if (s[i] == s[index]) { // if equal then we store the increased index
                arr[i] = ++index;
                i++;
            } else {
                if (index != 0) // if index is not the beginning then we check just before element
                    index = arr[index - 1];
                else    // else we put that as 0
                    arr[i++] = 0;
            }
        }
        for (int i : arr)
            ans = max(ans, i);
        return ans;
    }
};