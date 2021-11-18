#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size(), x;
        for (int i = 0; i < n; i++) {
            x = abs(arr[i]) - 1;
            if (arr[x] > 0) // Marking all the visited indexs as -ve.
                arr[x] *= -1;
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) // All those indexs that are not visited are +ve and does not appear in the array.
                ans.push_back(i + 1);
        }
        return ans;
    }
};