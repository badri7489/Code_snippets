#include<bits/stdc++.h>
using namespace std;

void helper(string s, int i, vector<string>& ans) {
    if (i == s.length()) {
        ans.push_back(s);   // Pushing it into answer.
        return;
    }
    for (int j = i; j < s.length(); j++) {
        swap(s[i], s[j]);   // Swapping two characters.
        helper(s, i + 1, ans);
        swap(s[i], s[j]);   // Swapping them back.
    }
}
vector<string> find_permutation(string S) {
    vector<string> ans;
    helper(S, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}