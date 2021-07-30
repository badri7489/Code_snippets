#include<bits/stdc++.h>
using namespace std;

void helper(int i, int j, vector<vector<int>>& m, int n, string move, vector<string>& ans, vector<vector<int>> vis) {
    if (i == n - 1 && j == n - 1) {
        ans.push_back(move);
        return;
    }
    vis[i][j] = 1;
    if (i + 1 < n && !vis[i + 1][j] && m[i + 1][j]) {
        helper(i + 1, j, m, n, move + "D", ans, vis);
    }
    if (j - 1 >= 0 && !vis[i][j - 1] && m[i][j - 1]) {
        helper(i, j - 1, m, n, move + "L", ans, vis);
    }
    if (j + 1 < n && !vis[i][j + 1] && m[i][j + 1]) {
        helper(i, j + 1, m, n, move + "R", ans, vis);
    }
    if (i - 1 >= 0 && !vis[i - 1][j] && m[i - 1][j]) {
        helper(i - 1, j, m, n, move + "U", ans, vis);
    }
    vis[i][j] = 0;
}
vector<string> findPath(vector<vector<int>>& m, int n) {
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    if (m[0][0] == 1)
        helper(0, 0, m, n, "", ans, vis);
    return ans;
}

// Compact Code
void helper(int i, int j, vector<vector<int>>& m, int n, string move, vector<string>& ans, vector<vector<int>>& vis, int di[], int dj[]) {
    if (i == n - 1 && j == n - 1) {
        ans.push_back(move);
        return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
        int nexti = i + di[ind], nextj = j + dj[ind];
        if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < n && !vis[nexti][nextj] && m[nexti][nextj]) {
            vis[i][j] = 1;
            helper(nexti, nextj, m, n, move + dir[ind], ans, vis, di, dj);
            vis[i][j] = 0;
        }
    }
}
vector<string> findPath(vector<vector<int>>& m, int n) {
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int di[] = { 1, 0, 0, -1 };
    int dj[] = { 0, -1, 1, 0 };
    if (m[0][0] == 1)
        helper(0, 0, m, n, "", ans, vis, di, dj);
    return ans;
}
