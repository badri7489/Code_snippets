/** Use simple brute force to solve it.
  * It can also be done using trie.
  * For smaller test cases brute force will be better, but as the number of test cases increases trie is better.
  */

#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int mini = INT_MAX, k;
    for (int i = 0; i < strs.size(); i++) {
        if (mini > strs[i].size()) {
            k = i;
            mini = strs[i].size();
        }
    }
    int count = 0, flag = 1;
    for (int i = 0; i < strs[k].length(); i++) {
        for (int j = 0; j < strs.size(); j++) {
            if (strs[k][i] != strs[j][i])
                flag = 0;
        }
        if (flag)
            count++;
    }
    return strs[0].substr(0, count);
}