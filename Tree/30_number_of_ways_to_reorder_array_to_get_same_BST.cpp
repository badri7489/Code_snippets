#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(n^2)
class Solution {
private:
    long long mod = 1e9 + 7;
    vector<vector<long long>> pascal;
    // Creating Pascal's Triangle for storing the permutations, nCr.
    void calculatePascal(int n) {
        pascal.resize(n);
        for (int i = 0; i < n; i++) {
            pascal[i] = vector<long long>(i + 1, 1);
            for (int j = 1; j < i; j++)
                pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % mod;
        }
    }
    long long dfs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return 1;
        vector<int> left;
        vector<int> right;
        // Find the left sub-sequence elements and the right sub-sequence elements.
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[0])
                right.push_back(nums[i]);
            else
                left.push_back(nums[i]);
        }
        // Recursion for left subtree and right subtree.
        long long left_res = dfs(left) % mod;
        long long right_res = dfs(right) % mod;
        // Look up the Pascal table and multiply them.
        // Mod them to keep the answer in the range of int.
        int left_len = left.size(), right_len = right.size();
        return (((pascal[n - 1][left_len] * left_res) % mod) * right_res) % mod;
    }
public:
    int numOfWays(vector<int>& nums) {
        calculatePascal(nums.size() + 1);
        long long ans = dfs(nums);
        return ans % mod - 1;
    }
};