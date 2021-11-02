#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if (n < 3)
            return true;
        for (int i = 2; i < n; i++) {
            int dy1 = coordinates[i][1] - coordinates[i - 1][1];
            int dy0 = coordinates[i - 1][1] - coordinates[i - 2][1];
            int dx1 = coordinates[i][0] - coordinates[i - 1][0];
            int dx0 = coordinates[i - 1][0] - coordinates[i - 2][0];
            if (dy1 * dx0 != dy0 * dx1) // Check if two slopes are not equal
                return false;
        }
        return true;
    }
};