#include<iostream>
#include<vector>
using namespace std;

// We modify the given array and use it as a hash table.
class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (arr[abs(arr[i]) - 1] > 0)
                arr[abs(arr[i]) - 1] *= -1; // Negate all the visited ones.
            else
                ans.push_back(abs(arr[i])); // If we find if any value at a position is negative then we know we have visited it before.
        }
        return ans;
    }
};