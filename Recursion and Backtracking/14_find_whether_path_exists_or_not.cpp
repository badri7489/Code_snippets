#include<iostream>
#include<vector>
using namespace std;

bool isPath(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, int n) {
    if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0)
        return false;
    if (vis[i][j])
        return false;
    if (grid[i][j] == 2)
        return true;
    vis[i][j] = true;
    bool ans = isPath(grid, vis, i + 1, j, n);
    ans = ans || isPath(grid, vis, i - 1, j, n);
    ans = ans || isPath(grid, vis, i, j + 1, n);
    ans = ans || isPath(grid, vis, i, j - 1, n);
    return ans;
}
bool is_Possible(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> vis(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1)
                return isPath(grid, vis, i, j, n);
        }
    }
    return false;
}