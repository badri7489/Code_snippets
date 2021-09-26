#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
    bool isValid(int x, int y, int m, int n) {
        return (x >= 0) && (x < m) && (y >= 0) && (y < n);
    }
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), x, y;
        vector<vector<int>> vis(m, vector<int>(n, -1));
        queue<vector<int>> q;
        q.push({ 0, 0, 0, k }); // i, j, steps taken, obstacle remaining.
        vector<int> curr;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            x = curr[0], y = curr[1];
            // Check if the cordinates are valid or not.
            if (!isValid(x, y, m, n))
                continue;
            // Destination reached
            if (x == m - 1 && y == n - 1)
                return curr[2];
            if (grid[x][y] == 1) {
                if (curr[3] > 0)    // If we encounter an obstacle and we can remove it.
                    curr[3]--;
                else    // Else we will not take that step into consideration.
                    continue;
            }
            // The cell was previously visited by some path and we were able to remove more obstacles from the previous path.
            // Then we don't need to continue on our current path
            if (vis[x][y] != -1 && vis[x][y] >= curr[3])
                continue;
            vis[x][y] = curr[3];

            q.push({ x + 1, y, curr[2] + 1, curr[3] });
            q.push({ x, y + 1, curr[2] + 1, curr[3] });
            q.push({ x - 1, y, curr[2] + 1, curr[3] });
            q.push({ x, y - 1, curr[2] + 1, curr[3] });
        }
        return -1;
    }
};