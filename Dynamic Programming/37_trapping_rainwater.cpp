#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        vector<int> maxLeft(n); // Boundary on the left for each building.
        vector<int> maxRight(n);// Boundary on the right for each building.
        maxLeft[0] = height[0];
        maxRight[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++)
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        for (int i = n - 2; i >= 0; i--)
            maxRight[i] = max(maxRight[i + 1], height[i]);
        // Amount of water at each building is the minimum of both the boundaries - the height of the building.
        for (int i = 0; i < n; i++)
            ans += min(maxLeft[i], maxRight[i]) - height[i];
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0, low = 0, high = n - 1, left_max = 0, right_max = 0;
        for (int i = 0; i < n; i++) {
            if (height[low] <= height[high]) {
                if (left_max < height[low]) // If the left boundary is smaller than the current building.
                    left_max = height[low];
                else // If the boundary is less than or equal to the current building then we calculate the water present.
                    ans += left_max - height[low];
                low++;
            } else {
                if (right_max < height[high]) // If the right boundary is smaller than the current building.
                    right_max = height[high];
                else // If the boundary is less than or equal to the current building then we calculate the water present.
                    ans += right_max - height[high];
                high--;
            }
        }
        return ans;
    }
};