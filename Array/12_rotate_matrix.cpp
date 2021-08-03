/**
  * Brute force for this will be to take another matrix and fill the values accordingly.
  * But without using an extra space doing inplace rotation of the matrix by 90° can also be done.
  * We just need to do a little bit of matrix manipulation.
  * We will first transpose the matrix and then reverse each row and voila! the answer.
  * Here space used is constant and time complexity will be O(n * m).
  */

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& arr) {
    int rows = arr.size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for (int i = 0; i < rows; i++) {
        reverse(arr[i].begin(), arr[i].end());
    }
}