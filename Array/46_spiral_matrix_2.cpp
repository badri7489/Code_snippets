#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0, down = n - 1, left = 0, right = n - 1, dir = 0, k = 1;
        vector<vector<int>> ans(n, vector<int>(n));
        while (top <= down && left <= right) {
            if (dir == 0) {
                for (int i = left; i <= right; i++)
                    ans[top][i] = k++;
                top++;
            } else if (dir == 1) {
                for (int i = top; i <= down; i++)
                    ans[i][right] = k++;
                right--;
            } else if (dir == 2) {
                for (int i = right; i >= left; i--)
                    ans[down][i] = k++;
                down--;
            } else {
                for (int i = down; i >= top; i--)
                    ans[i][left] = k++;
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};