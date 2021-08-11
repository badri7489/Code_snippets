/**
  * Anagrams look the same when they are sorted.
  * So all we need to do is keep track of what words look the same when they're sorted.
  * To do this we iterate through all the words we're given.
  * Sort them one by one and add them to a list of words that also look the same when sorted.
  * Then each array of words in the map is a group of anagram.
  * Time complexity is O(m * n * log(m)).
  * m - length of longest word.
  * n - total number of words.
  * Space complexity O(n).
  */

#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> mp;
    for (auto& s : strs) {
        string t = s;
        sort(t.begin(), t.end());
        mp[t].push_back(s);
    }
    for (auto it : mp) {
        ans.push_back(it.second);
    }
    return ans;
}