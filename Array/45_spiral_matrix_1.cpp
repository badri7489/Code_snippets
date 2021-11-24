#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), top = 0, down = m - 1, left = 0, right = n - 1, dir = 0;
        int k = 0, x = m * n;
        vector<int> ans(x);
        while (top <= down && left <= right && k < x) {
            if (dir == 0) { // Going left to right.
                for (int i = left; i <= right; i++)
                    ans[k++] = mat[top][i];
                top++;
            } else if (dir == 1) {  // Going top to down
                for (int i = top; i <= down; i++)
                    ans[k++] = mat[i][right];
                right--;
            } else if (dir == 2) {  // Going right to left
                for (int i = right; i >= left; i--)
                    ans[k++] = mat[down][i];
                down--;
            } else {    // Going down to up.
                for (int i = down; i >= top; i--)
                    ans[k++] = mat[i][left];
                left++;
            }
            dir = (dir + 1) % 4;    // Changing direction
        }
        return ans;
    }
};