/** This question is the same question as the next greater element.
  * Just a slight modification is that it has a circular array.
  * So when we reach the end of the array we must not stop there, we must start from the begining of the array.
  * To solve this problem we take an imaginary duplicate array and add it at the end of the array.
  * Then we loop the whole 2n array and find the next greater element.
  * But we store them only for i < n.
  * We do this by simply using mod operator.
  * Time complexity will be O(2n + 2n).
  * Space complexity will be O(2n).
  */

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> stk;
    int n = nums.size();
    vector<int> ans(n, -1);

    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!stk.empty() && nums[i % n] >= stk.top())
            stk.pop();

        if (i < n && !stk.empty())
            ans[i % n] = stk.top();

        stk.push(nums[i % n]);
    }
    return ans;
}