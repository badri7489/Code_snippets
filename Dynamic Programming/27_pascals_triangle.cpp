/**
  * Pascal’s Triangle is a simple recursion algorithm. Time complexity is O(n^2).
  */

#include<iostream>
#include<vector>
using namespace std;

// Iterative Code
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);
    for (int i = 0; i < numRows; i++) {
        ans[i].resize(i + 1);
        ans[i][0] = ans[i][i] = 1;
        for (int j = 1; j < i; j++) {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }
    return ans;
}

// Recursive Code
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    if (numRows == 1) {
        vector<int>a;
        a.push_back(1);
        ans.push_back(a);
        return ans;
    }
    ans = generate(numRows - 1);
    vector<int>a(ans.size() + 1);
    a[0] = 1;
    a[a.size() - 1] = 1;
    for (int i = 1;i < a.size() - 1;i++)
        a[i] = ans[numRows - 2][i - 1] + ans[numRows - 2][i];
    ans.push_back(a);
    return ans;
}
