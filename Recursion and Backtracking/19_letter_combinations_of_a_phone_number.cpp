#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<string> alpha = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> ans;
    void helper(string& s, int ind, string temp) {
        if (ind == s.length()) {    // base condition
            ans.push_back(temp);
            return;
        }
        int n = s[ind] - '0';
        for (char c : alpha[n]) {
            temp += c;
            helper(s, ind + 1, temp);
            temp.pop_back();    // Backtracking our steps
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
            return {};
        helper(digits, 0, "");
        return ans;
    }
};