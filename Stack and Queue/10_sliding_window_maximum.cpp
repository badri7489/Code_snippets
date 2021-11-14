/**
  * Here we need to take the maximum of the elements that are there in a window of size k.
  * We begin from the left and start moving a window of size k to the right by one step at a time.
  * We find the maximum and keep it in a vector.
  * The size of the vector will be n - k + 1.
  * This algorithm implemented using brute force would be of time O(n*k).
  * Better approach would be to do it in one pass and using extra space.
  * We use a doubly ended queue.
  * We traverse the vector form left to right.
  * If the deque is empty we push the first index.
  * Else we pop from the back of the queue until the elements in the deque is less than the current element in the vector.
  * We also need to keep in check if the element in the queue is removed or not.
  * To do this we check everytime that the front of the deque is not out of bound.
  * Here out of bound means out of the k sized window.
  * We start storing ans once the value of i is greater than k.
  * We only store k indexes in the deque.
  * Time is 2*n because we iterate over n elements and we pop and push those elements also.
  * This comes out to be amortised to O(n).
  * Time complexity is O(2n).
  * Space complexity is O(k).
  */

#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        if (!dq.empty() && dq.front() == i - k) // Out of bound for the window of size 'k'
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i])    // remove all elements < a[i]
            dq.pop_back();
        dq.push_back(i);    // Take the current element
        if (i >= k - 1) // Start taking elements after i >= k - 1
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}