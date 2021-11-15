#include<bits/stdc++.h>
using namespace std;

// Min heap will contain the largest numbers at the bottom.
// Hence we use a min heap for finding the kth largest.
// Time Complexity: O(n * log(k)).
int findKthLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;   // Creating a min heap.
    for (int i = 0; i < arr.size(); i++) {
        // Pushing element if heap size less than k and when the top is smaller than the current.
        if (pq.size() < k || pq.top() < arr[i])
            pq.push(arr[i]);
        // If there are more than k elements then we pop it out so we only have k elements in the min heap.
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top(); // Top contains the kth largest.
}

// Time Complexity: O(n).
class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        srand(time(0));
        shuffle(arr);
        k = arr.size() - k;
        int lo = 0, hi = arr.size() - 1;
        while (lo < hi) {
            int  j = partition(arr, lo, hi);
            if (j < k)  // if k is on the left side.
                lo = j + 1;
            else if (j > k) // if k is on the right side.
                hi = j - 1;
            else    // found the value of k.
                break;
        }
        return arr[k];
    }
private:
    // Hoare's Partitioning for Quick Sort.
    int partition(vector<int>& arr, int lo, int hi) {
        int i = lo, j = hi + 1;
        while (true) {
            while (i < hi && arr[++i] < arr[lo]);
            while (j > lo && arr[lo] < arr[--j]);
            if (i >= j)
                break;
            swap(arr[i], arr[j]);
        }
        swap(arr[lo], arr[j]);
        return j;
    }
    // Shuffling the elements of the array so the quick select is randomised.
    void shuffle(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int r = rand() % n;
            swap(arr[i], arr[r]);
        }
    }
};