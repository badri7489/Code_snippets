#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m&& y < n;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!mat[i][j]) {
                    dist[i][j] = 0;
                    q.push({ i, j });
                }
            }
        }
        int dx[] = { 0, 1, 0, -1 };
        int dy[] = { 1, 0, -1, 0 };
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (isValid(x, y, m, n) && dist[x][y] == -1) {
                    dist[x][y] = dist[i][j] + 1;
                    q.push({ x, y });
                }
            }
        }
        return dist;
    }
};