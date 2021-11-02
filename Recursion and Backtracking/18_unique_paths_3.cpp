#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int dir[5] = { 0, 1, 0, -1, 0 };
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m&& y >= 0 && y < n;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int count, int& ans) {
        if (grid[i][j] == 2) {  // Reached the end.
            ans += count == 0 ? 1 : 0;  // if count is zero then increment ans.
            return;
        }
        grid[i][j] = -1;    // marked visited
        int x, y;
        for (int k = 0; k < 4; k++) {
            x = i + dir[k], y = j + dir[k + 1];
            if (isValid(x, y, grid.size(), grid[0].size())) {
                if (grid[x][y] == 0)    // empty space
                    dfs(grid, x, y, count - 1, ans);    // Decrease count of zeros.
                else if (grid[x][y] == 2)   // reached destination
                    dfs(grid, x, y, count, ans);
            }
        }
        grid[i][j] = 0; // backtracking our steps
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), count = 0, x, y, ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0)    // Count all zeros
                    count++;
                if (grid[i][j] == 1)
                    x = i, y = j;
            }
        }
        dfs(grid, x, y, count, ans);
        return ans;
    }
};