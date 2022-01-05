/**
  * In this question we need to take a subset, xor all its elements and sum all the xored values.
  * We can use recursion to find all the subsets and xor all of them.
  * The base case would be to store the xor sum.
  * Time complexity: O(2 ^ n).
  * Space complexity: O(n) auxilliary.

  * Once we observe all these binary number of the XORs, we can observe that
  * set bit occurs at all the position of i (0 <= i < n) will exactly contribute to half of pow(2,n).

  * Why exactly half of 2^n??

  * Consider the size of nums array is n and m elements in nums have i th bit set.
  * Now, to have a subset with ith bit set in its xor, we need it to have odd number of elements
  * with ith bit set or else xor will become 0.
  * Number of ways of choosing elements with ith bit not set = 2^(n-m).
  * Also, Number of ways of choosing elements with ith bit set = mC1 + mC3 + mC5 …. = 2^(m-1)
  * So that we get total number of ways = 2^(n-1) which is exactly half of 2^n.
  *
  * Now, we have two conditions:

  * If there is any value of nums that has set ith bit set,
  * then exactly half of 2^n subsets will be of the form, so they will contribute to 2^(n-1+i) to the final sum.
  * If there is no value of nums that ith bit set,
  * then we can say that there will be no term in all subsets that have a ith bit set.
  * Now the question is to check which position of element of the nums will be set or not.
  * But instead of iterating for all elements ,
  * we can use a trick that is simply take the OR of all such values and multiply with 2^(n-1)
  */


// https://leetcode.com/problems/sum-of-all-subset-xor-totals/


#include<bits/stdc++.h>
using namespace std;

// Recursive Solution
void helper(vector<int>& nums, int i, int xo, int& ans) {
    if (i == nums.size()) {
        ans += xo;
        return;
    }
    helper(nums, i + 1, xo ^ nums[i], ans);
    helper(nums, i + 1, xo, ans);
}
int subsetXORSum(vector<int>& nums) {
    int ans = 0;
    helper(nums, 0, 0, ans);
    return ans;
}

// Bit Manipulation
int subsetXORSum(vector<int>& nums) {
    int ans = 0;
    for (int i : nums)
        ans |= i;
    return ans * (1 << nums.size() - 1);
}