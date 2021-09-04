/**
  * Your KthLargest object will be instantiated and called as such:
  * KthLargest* obj = new KthLargest(k, nums);
  * int param_1 = obj->add(val);
  */

  /**
    * We put a value in the heap.
    * We try to maintain only k values in the heap.
    * For kth largest we take min heap.
    * This is because in min heap we always have the minimum at the top.
    * After we have k elements, we don't need any element which is smaller than the top of the heap.
    * Because those elements won't effect the kth largest element.
    * But if the element to be inserted is greater than the top of the heap, then we need to put the element in the heap,
    * and take out the element which is at the top.
    * This is because we have k + 1 elements in the heap.
    * Time Complexity of Constructor: O(n * log(k)).
    * Space Complexity: O(k).
    */

#include<iostream>
#include<queue>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> p;
    int l;
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            p.push(nums[i]);    // Putting in the heap.
            if (p.size() > k)   // If size of heap is greater than k then we pop out all.
                p.pop();
        }
        l = k;
    }

    int add(int val) {
        p.push(val);
        if (p.size() > l)
            p.pop();
        return p.top();
    }
};