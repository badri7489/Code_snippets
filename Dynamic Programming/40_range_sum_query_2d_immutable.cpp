#include<iostream>
#include<vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> rangeSum;
public:
    NumMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        rangeSum.resize(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                rangeSum[i + 1][j + 1] = rangeSum[i + 1][j] + rangeSum[i][j + 1] - rangeSum[i][j] + mat[i][j];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return rangeSum[row2 + 1][col2 + 1] - rangeSum[row2 + 1][col1] - rangeSum[row1][col2 + 1] + rangeSum[row1][col1];
    }
};