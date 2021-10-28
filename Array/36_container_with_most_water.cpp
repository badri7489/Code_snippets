#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), low = 0, high = n - 1, ans = 0, h;
        while (low < high) {
            h = min(height[low], height[high]);
            ans = max(ans, h * (high - low));
            while (low < high && height[low] <= h)
                low++;
            while (low < high && height[high] <= h)
                high--;
        }
        return ans;
    }
};