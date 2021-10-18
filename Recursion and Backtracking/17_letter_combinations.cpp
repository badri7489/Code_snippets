#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    vector<string> ans;
    void helper(string& s, int index) {
        if (index == s.length()) {
            ans.push_back(s);
            return;
        }
        helper(s, index + 1);   // Recursively calling the function.
        if (isalpha(s[index])) {    // If it is a character we call the function again.
            s[index] = s[index] ^ 32;   // We change the case of the character.
            helper(s, index + 1);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        helper(s, 0);
        return ans;
    }
};