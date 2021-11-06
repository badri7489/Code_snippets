#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int i = 0, j = 0, sumi = 0, ans = INT32_MAX, n = arr.size();
        while (i < n) {
            if (i < n && sumi < target) // Expanding the window.
                sumi += arr[i];
            while (j < n && sumi >= target) {   // Contracting the window.
                ans = min(ans, i - j + 1);
                sumi -= arr[j++];
            }
            i++;
        }
        return ans == INT32_MAX ? 0 : ans;
    }
};