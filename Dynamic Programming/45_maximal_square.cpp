#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        if (mat.size() <= 0 || mat[0].size() <= 0)
            return 0;
        int m = mat.size(), n = mat[0].size(), h = 0, w = 0, ans = 0;
        vector<int> height(n + 1, 0);
        for (int i = 0; i < m; i++) {
            stack<int> stk;
            for (int j = 0; j < n + 1; j++) {   // Set Value
                if (j < n) {
                    if (mat[i][j] == '1')
                        height[j] += 1;
                    else
                        height[j] = 0;
                }
                // Compute Area
                while (!stk.empty() && height[stk.top()] >= height[j]) {
                    h = height[stk.top()];
                    stk.pop();
                    w = stk.empty() ? j : j - stk.top() - 1;
                    if (h * w > ans)
                        ans = h * w;
                }
                stk.push(j);
            }
        }
        return ans;
    }
};