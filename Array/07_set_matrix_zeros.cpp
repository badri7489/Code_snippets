/**
  * Better approach would be to take note of the rows where we need to put zeros and the same for the columns.
  * This will be O(m + n) space complexity.
  *
  * An optimal solution would be to have this count of the zeros for rows and columns in the first row and first column
  * and an extra 1 space for taking note of 0 at column 0.
  * Then we can make all the necessary places zero by traversing the matrix from the bottom.
  * Space complexity is O(1).
  */

#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0)
            col0 = 0;
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
        }
    }
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
        if (col0 == 0)
            matrix[i][0] = 0;
    }
}
