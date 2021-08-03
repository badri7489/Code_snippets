/**
  * We need to find the maximum area of the rectangle formed in the histogram.
  * If we take a particular hist and find the left minimum and the right minimum.
  * Once we have the min on the left and and right, we got the width of the rectangle.
  * The height will be the height of the hist.
  * We will maintain a left min array for all the values and also a right minimum array.
  * This can be done in O(n) time using a stack.
  * So this has a time complexity of O(n) + O(n) + O(n).
  * Space complexity will be O(n) + O(n) + O(n).
  * This algorithm takes 3 passes to calculate.
  * It can be optimised to only a single pass, and O(n) space only.
  * We take a stack. If the stack is empty we take that height and
  */

#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0, n = heights.size();
    stack<int> stk;
    for (int i = 0; i <= n; i++) {
        while (!stk.empty() && (i == n || heights[stk.top()] >= heights[i])) {
            int height = heights[stk.top()];
            stk.pop();
            if (stk.empty())
                maxArea = max(maxArea, height * i);
            else
                maxArea = max(maxArea, height * (i - stk.top() - 1));
        }
        stk.push(i);
    }
    return maxArea;
}