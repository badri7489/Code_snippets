#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    void helper(vector<int>& arr, int ind) {
        if (ind == arr.size()) {
            ans.push_back(arr);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            swap(arr[i], arr[ind]);
            helper(arr, ind + 1);
            swap(arr[i], arr[ind]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& arr) {
        helper(arr, 0);
        return ans;
    }
};