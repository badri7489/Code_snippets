#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class NumArray {
private:
    vector<int> arr;
    vector<int> segmentTree;
    int buildTree(int si, int left, int right) {
        if (left == right)  // Leaf is reached.
            return segmentTree[si] = arr[left];
        int mid = left + (right - left) / 2;
        // recursively build left, and right child, then parent value will be sum of both
        return segmentTree[si] = buildTree(2 * si + 1, left, mid) + buildTree(2 * si + 2, mid + 1, right);
    }
    int getSum(int si, int sl, int sr, int left, int right) {
        if (sl >= left && sr <= right)  // Full Overlap.
            return segmentTree[si];
        if (sr < left || sl > right)    // No Overlap.
            return 0;
        int mid = sl + (sr - sl) / 2;
        // Partial Overlap, get answer from both the childs.
        return getSum(2 * si + 1, sl, mid, left, right) + getSum(2 * si + 2, mid + 1, sr, left, right);
    }
    void updateTree(int si, int sl, int sr, int pos, int diff) {
        if (sl > pos || sr < pos)   // Out of bound check.
            return;
        segmentTree[si] += diff;    // Add difference to the current node.
        if (sl != sr) {
            int mid = sl + (sr - sl) / 2;
            updateTree(si * 2 + 1, sl, mid, pos, diff); // Call to add diff to left.
            updateTree(si * 2 + 2, mid + 1, sr, pos, diff); // Call to add diff to right.
        }
    }
public:
    NumArray(vector<int>& nums) {
        arr = nums;
        int n = nums.size(), x = (int)(ceil(log2(n)));
        int max_size = 2 * (int)pow(2, x);
        segmentTree = vector<int>(max_size, 0);
        buildTree(0, 0, n - 1);
    }

    void update(int index, int val) {
        int diff = val - arr[index];
        arr[index] = val;
        updateTree(0, 0, arr.size() - 1, index, diff);
    }

    int sumRange(int left, int right) {
        return getSum(0, 0, arr.size() - 1, left, right);
    }
};