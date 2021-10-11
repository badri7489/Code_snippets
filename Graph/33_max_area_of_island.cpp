#include<iostream>
#include<vector>
using namespace std;

// My code.
class Solution {
private:
    vector<int> x_points = { 0, -1, 0, 1 };
    vector<int> y_points = { 1, 0, -1, 0 };
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m&& y >= 0 && y < n;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, int& isl) {
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int x = i + x_points[k];
            int y = j + y_points[k];
            if (isValid(x, y, grid.size(), grid[0].size()) && grid[x][y] && !vis[x][y])
                dfs(grid, vis, x, y, ++isl);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), isl = 1, maxi = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    isl = 1;
                    dfs(grid, vis, i, j, isl);
                    maxi = max(maxi, isl);
                }
            }
        }
        return maxi;
    }
};

// My Code without the visited array.
class Solution {
private:
    vector<int> x_points = { 0, -1, 0, 1 };
    vector<int> y_points = { 1, 0, -1, 0 };
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m&& y >= 0 && y < n;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int& isl) {
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            int x = i + x_points[k], y = j + y_points[k];
            if (isValid(x, y, grid.size(), grid[0].size()) && grid[x][y])
                dfs(grid, x, y, ++isl);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), isl = 1, maxi = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    isl = 1;
                    dfs(grid, i, j, isl);
                    maxi = max(maxi, isl);
                }
            }
        }
        return maxi;
    }
};

// Modified and concise solution.
class Solution {
private:
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m&& y >= 0 && y < n;
    }
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (isValid(i, j, grid.size(), grid[0].size()) && grid[i][j]) {
            grid[i][j] = 0;
            return 1 + dfs(grid, i + 1, j) + dfs(grid, i, j + 1) + dfs(grid, i - 1, j) + dfs(grid, i, j - 1);
        }
        return 0;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxi = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j])
                    maxi = max(maxi, dfs(grid, i, j));
            }
        }
        return maxi;
    }
};