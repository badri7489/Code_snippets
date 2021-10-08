#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<int> x_points = { 0, 1, 0, -1 };
    vector<int> y_points = { 1, 0, -1, 0 };
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m&& y >= 0 && y < n;
    }
    void helper(vector<vector<int>>& image, int i, int j, int prev, int curr) {
        image[i][j] = curr;
        for (int k = 0; k < 4; k++) {
            int x = i + x_points[k];
            int y = j + y_points[k];
            if (isValid(x, y, image.size(), image[0].size()) && image[x][y] == prev)
                helper(image, x, y, prev, curr);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor)
            helper(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};