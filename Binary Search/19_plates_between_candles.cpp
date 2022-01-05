// Problem link : https://leetcode.com/problems/plates-between-candles/

#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Time Complexity: O(n * log(n))
// Space Compexity: O(n)
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candle;
        vector<int> ans;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '|')
                candle.push_back(i);    // Having index of all the candles.
        }
        n = queries.size();
        int i, j;
        for (int q = 0; q < n; q++) {
            i = lower_bound(candle.begin(), candle.end(), queries[q][0]) - candle.begin();  // Lower bound of query
            j = upper_bound(candle.begin(), candle.end(), queries[q][1]) - candle.begin() - 1;  // Upper bound of query
            // cout << "i: " << i << " j: " << j << endl;
            ans.push_back(i < j ? (candle[j] - candle[i]) - (j - i) : 0);   // Calculating the number of plates in between candles.
        }
        return ans;
    }
};