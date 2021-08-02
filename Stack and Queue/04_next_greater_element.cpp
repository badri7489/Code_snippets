/** In this question we need to find the next element on the right which is greater than the present element.
  * If no such element is present in the array on the right then it is a -1.
  * We must return an array of such elements for each value in the array.
  * This can be done by using brute force approach.
  * We traverse the array twice keeping two pointers.
  * Time complexity would be O(n ^ 2).
  * Space complexity would be O(1).
  * To improve the time complexity we can take stack.
  * We traverse the array from the end.
  * We keep the elements which are greater than the present element and remove those elements which are smaller than or equal to it.
  * We also store that element in the stack.
  * Time complexity comes out to be O(n + n).
  * Extra time comes because of the time taken to traverse the stack, every time we need to pop an element.
  * Space complexity is O(n) in worst case.
  */

#include<bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n) {
    vector<long long> ans(n, -1);
    stack<long long> stk;

    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && stk.top() <= arr[i])
            stk.pop();

        if (!stk.empty())
            ans[i] = stk.top();

        stk.push(arr[i]);
    }
    return ans;
}