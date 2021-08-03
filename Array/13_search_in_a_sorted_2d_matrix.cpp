/**
  * Brute force approach would be to linearly search the array, and its time complexity would be O(n^2).
  * Optimal approach would be to make use of the fact that the array is sorted.
  * The matrix is sorted both row wise and column wise. We can start from the top right side of the matrix.
  * If the element to be searched is greater we will go down in that column else we will go left in that row.
  * Hence in the worst case an element can be searched by traversing the length and the breadth of the matrix.
  * So time complexity is O(m + n).
  */

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i = 0, j = matrix[0].size() - 1;
    while (i < matrix.size() && j >= 0) {
        if (matrix[i][j] == target) {
            return true;
        } else if (matrix[i][j] > target) {
            j--;
        } else {
            i++;
        }
    }
    return false;
}
