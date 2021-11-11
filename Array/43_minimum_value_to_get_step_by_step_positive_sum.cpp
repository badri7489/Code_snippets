#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& arr) {
        int n = arr.size(), preSum, mini = arr[0];
        preSum = arr[0];
        for (int i = 1; i < n; i++) {
            preSum = preSum + arr[i];
            mini = min(mini, preSum);
        }
        return mini >= 0 ? 1 : abs(mini) + 1;
    }
};