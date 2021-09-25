#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Using DFS, better one for this.
class Solution {
private:
    bool isValid(int x, int y, int m, int n) {
        return (x >= 0) && (x < m) && (y >= 0) && (y < n);
    }
    vector<int> x_points = { -1, -1, -1, 0, 0, 1, 1, 1 };
    vector<int> y_points = { -1, 0, 1, -1, 1, -1, 0, 1 };
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        for (int k = 0; k < 8; k++) {
            int x = i + x_points[k], y = j + y_points[k];
            if (isValid(x, y, grid.size(), grid[0].size()) && grid[x][y] == '1')
                dfs(grid, x, y);
        }
    }
public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};

// BFS Solution
class Solution {
private:
    bool isValid(int x, int y, int m, int n) {
        return (x >= 0) && (x < m) && (y >= 0) && (y < n);
    }
    vector<int> x_points = { -1, -1, -1, 0, 0, 1, 1, 1 };
    vector<int> y_points = { -1, 0, 1, -1, 1, -1, 0, 1 };
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<vector<int>> q;
        q.push({ i, j });
        vector<int> curr;
        int x, y;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            for (int i = 0; i < 8; i++) {
                x = curr[0] + x_points[i];
                y = curr[1] + y_points[i];
                if (isValid(x, y, grid.size(), grid[0].size()) && grid[x][y] == '1') {
                    q.push({ x, y });
                    grid[x][y] = '0';
                }
            }
        }
    }
public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }
};