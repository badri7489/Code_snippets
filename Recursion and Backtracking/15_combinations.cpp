#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
    void helper(int n, int k, int index) {
        if (k == temp.size()) { // When tempsize is equal to k we push it in ans.
            ans.push_back(temp);
            return;
        }
        for (int i = index; i <= n; i++) {
            temp.push_back(i);  // Pushing the ith element and then recursively calling.
            helper(n, k, i + 1);
            temp.pop_back();    // Popping out the last element so that others can be put in.
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        helper(n, k, 1);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        int i = 0;
        vector<int> p(k, 0);    // K size vector having all zeros.
        while (i >= 0) {
            p[i]++; // incrementing ith element.
            if (p[i] > n)
                --i;
            else if (i == k - 1)    // When pointer is at last location, we push the p in ans.
                ans.push_back(p);
            else {
                ++i;    // Incrementing the pointer.
                p[i] = p[i - 1];    // Taking the previous value.
            }
        }
        return ans;
    }
};