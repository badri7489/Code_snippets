#include<iostream>
#include<vector>
using namespace std;

// Modifying the grid itself
// In some questions it is specified not to modify any of the input so don't use.
// Make a copy of the grid and use that.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i < m; i++)
            grid[i][0] += grid[i - 1][0];
        for (int j = 1; j < n; j++)
            grid[0][j] += grid[0][j - 1];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
        return grid[m - 1][n - 1];
    }
};

// Using only two columns(vectors).
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(m, grid[0][0]), curr(m);
        for (int i = 1; i < m; i++)
            prev[i] = prev[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) {
            curr[0] = prev[0] + grid[0][j];
            for (int i = 1; i < m; i++)
                curr[i] = min(curr[i - 1], prev[i]) + grid[i][j];
            swap(curr, prev);
        }
        return prev[m - 1]; // Its prev because at the end of the loop, it will be swapped.
    }
};

// Then we found put that we don't need 2 vectors but only one.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> curr(m, grid[0][0]);
        for (int i = 1; i < m; i++)
            curr[i] = curr[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) {
            curr[0] = curr[0] + grid[0][j];
            for (int i = 1; i < m; i++)
                curr[i] = min(curr[i], curr[i - 1]) + grid[i][j];
        }
        return curr[m - 1];
    }
};