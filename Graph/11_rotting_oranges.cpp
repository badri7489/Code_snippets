/**
  * Use BFS traversal to check rot the oranges and calculate the time.
  */

#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), count = 0, min = 0, total = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 0)
                count++;
            if (grid[i][j] == 2)
                q.push(make_pair(i, j));
        }
    }
    while (!q.empty()) {
        int s = q.size(), i, j;
        total += s;
        for (int a = 0; a < s; a++) {
            pair p = q.front();
            i = p.first;
            j = p.second;
            q.pop();
            if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                grid[i - 1][j] = 2;
                q.push(make_pair(i - 1, j));
            }
            if (i + 1 < m && grid[i + 1][j] == 1) {
                grid[i + 1][j] = 2;
                q.push(make_pair(i + 1, j));
            }
            if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                grid[i][j - 1] = 2;
                q.push(make_pair(i, j - 1));
            }
            if (j + 1 < n && grid[i][j + 1] == 1) {
                grid[i][j + 1] = 2;
                q.push(make_pair(i, j + 1));
            }
        }
        if (!q.empty())
            min++;
    }
    if (total == count)
        return min;
    return -1;
}