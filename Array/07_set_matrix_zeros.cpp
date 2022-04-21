// https://leetcode.com/problems/set-matrix-zeroes/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), col0 = 0;
        for (int i = 0; i < m; i++) {
            if (mat[i][0] == 0)
                col0 = 1;   // Storing if there is any 0 in the first column
            for (int j = 1; j < n; j++) {
                // Making the first row and first column as the marker for zeros in that column.
                if (mat[i][j] == 0)
                    mat[0][j] = mat[i][0] = 0;
            }
        }
        // Now traverse the whole matriz and make them 0 according to the first row and first col
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 1; j--) {  // Not traversing the last column
                if (mat[i][j] != 0 && (mat[i][0] == 0 || mat[0][j] == 0))
                    mat[i][j] = 0;
            }
            if (col0)   // Checking for the last column.
                mat[i][0] = 0;
        }
    }
};