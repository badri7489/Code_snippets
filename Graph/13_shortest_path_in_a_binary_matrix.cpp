#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Leetcode version, with 8 directions.
class Solution {
private:
    bool isValid(int x, int y, int n) {
        return x >= 0 && x < n&& y >= 0 && y < n;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1])
            return -1;
        vector<int> x_points = { -1, -1, -1, 0, 0, 1, 1, 1 };
        vector<int> y_points = { -1, 0, 1, -1, 1, -1, 0, 1 };
        queue<vector<int>> q;
        vector<int> curr;
        q.push({ 0, 0, 1 });
        grid[0][0] = 1;
        int i, j;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            if (curr[0] == n - 1 && curr[1] == n - 1)
                return curr[2];
            for (int k = 0; k < 8; k++) {
                i = curr[0] + x_points[k];
                j = curr[1] + y_points[k];
                if (isValid(i, j, n) && !grid[i][j]) {
                    q.push({ i, j, curr[2] + 1 });
                    grid[i][j] = 1;
                }
            }
        }
        return -1;
    }
};

// Leetcode version without the extra space to store the count.
// Storing the count in the grid, hence it also serves as a visited array.
class Solution {
private:
    bool isValid(int x, int y, int n) {
        return x >= 0 && x <= n && y >= 0 && y <= n;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() - 1;
        if (grid[0][0] == 1 || grid[n][n])
            return -1;
        vector<int> x_points = { -1, -1, -1, 0, 0, 1, 1, 1 };
        vector<int> y_points = { -1, 0, 1, -1, 1, -1, 0, 1 };
        queue<vector<int>> q;
        vector<int> curr;
        q.push({ 0, 0 });
        grid[0][0] = 1;
        while (!q.empty() && !grid[n][n]) {
            curr = q.front();
            q.pop();

            for (int i = 0; i < 8; i++) {
                int x = curr[0] + x_points[i];
                int y = curr[1] + y_points[i];
                if (isValid(x, y, n) && grid[x][y] == 0) {
                    grid[x][y] = grid[curr[0]][curr[1]] + 1;
                    q.push({ x, y });
                }
            }
        }
        return grid[n][n] ? grid[n][n] : -1;
    }
};

// Geeks for Geeks version with 4 directions.
int shortestDistance(int n, int m, vector<vector<int>> arr, int x, int y) {
    if (!arr[0][0] || !arr[x][y])
        return -1;
    queue<vector<int>> q;
    vector<int> curr;
    q.push({ 0, 0, 0 });
    int i, j;
    arr[0][0] = 0;
    vector<vector<int>> dir = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
    while (!q.empty()) {
        curr = q.front();
        q.pop();
        if (curr[0] == x && curr[1] == y)
            return curr[2];
        for (auto d : dir) {
            i = curr[0] + d[0];
            j = curr[1] + d[1];
            if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j]) {
                q.push({ i, j, curr[2] + 1 });
                arr[i][j] = 0;
            }
        }
    }
    return -1;
}