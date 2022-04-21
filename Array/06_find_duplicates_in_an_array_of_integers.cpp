/**
  * Brute force approach will be to sort the array and then find the duplicate which will be of O(n * log(n)) time complexity.
  * Better approach will be to use extra space.
  * We will take a map and count the occurrence of all the numbers and whose count will be more than 1 will be the imposter.
  * This will be O(n) time complexity and O(n) space complexity.
  *
  * Optimal approach will be to use tortoise and hare algorithm.
  * In this algorithm slow will move 1 step and fast will move 2 steps. They will meet in the loop.
  * Then slow will start from the beginning and move 1 step. Fast will also move 1 step.
  * Then they will meet at the start of the loop.
  * Hence we will find the duplicate in the array by traversing the array twice.
  * Time complexity will be O(n).
  */

// https://leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& arr) {
    int slow = arr[0], fast = arr[0];
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
