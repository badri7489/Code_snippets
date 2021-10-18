#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    void helper(vector<int>& arr, int ind) {
        if (ind == arr.size()) {    // When we reach the end of the array.
            ans.push_back(arr); // Push it into the answer.
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            swap(arr[i], arr[ind]); // Swap the ith with the ind.
            helper(arr, ind + 1);   // Recurse.
            swap(arr[i], arr[ind]); // Re-Swap the ith and the ind.
        }
    }
public:
    vector<vector<int>> permute(vector<int>& arr) {
        helper(arr, 0);
        return ans;
    }
};