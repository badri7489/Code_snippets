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
                if (!mat[i][j]) {   // Making all 0's at a distance of 0
                    dist[i][j] = 0;
                    q.push({ i, j });   // pushing in queue.
                }
            }
        }
        int dx[] = { 0, 1, 0, -1 };
        int dy[] = { 1, 0, -1, 0 };
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {   // Going all 4 directions
                int x = i + dx[k];
                int y = j + dy[k];
                if (isValid(x, y, m, n) && dist[x][y] == -1) {  // If valid and not marked
                    dist[x][y] = dist[i][j] + 1;    // Calculate the distance from its neighbour
                    q.push({ x, y });   // push to queue.
                }
            }
        }
        return dist;
    }
};

/** In DP, we can only use prevous values if they're already computed.
  * In this problem, a cell has at most 4 neighbors that are left, top, right, bottom.

  * If we use dynamic programming to compute the distance of the current cell based on 4 neighbors simultaneously,
  * it's impossible because we are not sure if distance of neighboring cells is already computed or not.

  * That's why, we need to compute the distance one by one:
  * Firstly, for a cell, we restrict it to only 2 directions which are left and top.

  * Then we iterate cells from top to bottom, and from left to right,
  * we calculate the distance of a cell based on its leftand top neighbors.

  * Secondly, for a cell, we restrict it only have 2 directions which are right and bottom.
  * Then we iterate cells from bottom to top, and from right to left,
  * we update the distance of a cell based on its rightand bottom neighbors.
  */
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size(), top, left, inf = row + col;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0)
                    continue;
                top = left = inf;
                if (i > 0)
                    top = mat[i - 1][j];
                if (j > 0)
                    left = mat[i][j - 1];
                mat[i][j] = min(top, left) + 1;
            }
        }
        int bottom, right;
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (mat[i][j] == 0)
                    continue;
                bottom = right = inf;
                if (i + 1 < row)
                    bottom = mat[i + 1][j];
                if (j + 1 < col)
                    right = mat[i][j + 1];
                mat[i][j] = min(mat[i][j], min(bottom, right) + 1);
            }
        }
        return mat;
    }
};