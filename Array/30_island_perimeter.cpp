#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), perimeter = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    perimeter += 4;
                    if (i > 0)  // Up Side
                        perimeter -= grid[i - 1][j];
                    if (j > 0)  // Left Side
                        perimeter -= grid[i][j - 1];
                    if (i < m - 1)  // Down Side
                        perimeter -= grid[i + 1][j];
                    if (j < n - 1)  // Right Side
                        perimeter -= grid[i][j + 1];
                }
            }
        }
        return perimeter;
    }
};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0, repeat = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++;    // The count of 1's
                    if (i != 0 && grid[i - 1][j])   // Up Side
                        repeat++;
                    if (j != 0 && grid[i][j - 1])   // Left Side
                        repeat++;
                }
            }
        }
        return count * 4 - repeat * 2;  // Calculating the perimeter.
    }
};