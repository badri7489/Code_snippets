#include<bits/stdc++.h>
using namespace std;

// Min heap will contain the largest numbers at the bottom.
// Hence we use a min heap for finding the kth largest.
// Time Complexity: O(n * log(k)).
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> p;   // Creating a min heap.
    for (int i = 0; i < nums.size(); i++) {
        p.push(nums[i]);    // Pushing an element in the heap.
        if (p.size() > k)   // If there are more than k elements then we pop it out so we only have k elements in the min heap.
            p.pop();
    }
    return p.top(); // Top contains the kth largest.
}

// Time Complexity: O(n).
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        shuffle(nums);
        k = nums.size() - k;
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int  j = partition(nums, lo, hi);
            if (j < k)  // if k is on the left side.
                lo = j + 1;
            else if (j > k) // if k is on the right side.
                hi = j - 1;
            else    // found the value of k.
                break;
        }
        return nums[k];
    }
private:
    // Hoare's Partitioning for Quick Sort.
    int partition(vector<int>& nums, int lo, int hi) {
        int i = lo, j = hi + 1;
        while (true) {
            while (i < hi && nums[++i] < nums[lo]);
            while (j > lo && nums[lo] < nums[--j]);
            if (i >= j)
                break;
            swap(nums[i], nums[j]);
        }
        swap(nums[lo], nums[j]);
        return j;
    }
    // Shuffling the elements of the array so the quick select is randomised.
    void shuffle(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int r = rand() % n;
            swap(nums[i], nums[r]);
        }
    }
};