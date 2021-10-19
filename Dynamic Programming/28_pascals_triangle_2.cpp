#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> ans(n + 1, 0);
        ans[0] = 1;
        for (int i = 1; i < n + 1; i++) {
            for (int j = i; j >= 1; j--)
                ans[j] += ans[j - 1];
        }
        return ans;
    }
};