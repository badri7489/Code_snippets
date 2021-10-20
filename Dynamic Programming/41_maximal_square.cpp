#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size(), n = mat[0].size(), largest = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == '1') {
                    dp[i + 1][j + 1] = 1 + min({ dp[i][j + 1], dp[i + 1][j], dp[i][j] });
                    largest = max(largest, dp[i + 1][j + 1]);
                }
            }
        }
        return largest * largest;
    }
};