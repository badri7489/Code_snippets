/**
  * Here we need to find all the subsets and the sum of all those subsets.
  * To find all the subsets we need to clearly observe that it is just a matter of choice.
  * An element from the array is taken or not taken.
  * This is the reason there are 2^n elements in the power set.
  * So by using recursion we will try to take an element and once we will include it and then we will not include it.
  * Base condition will be when the whole array is exhausted.
  * Time taken will be O(2^n).
  * Space will also be O(2^n).
  */

#include<bits/stdc++.h>
using namespace std;

void helper(int index, int sum, vector<int>& arr, int n, vector<int>& subset) {
    if (index == n) {
        subset.push_back(sum);
        return;
    }
    helper(index + 1, sum + arr[index], arr, n, subset);
    helper(index + 1, sum, arr, n, subset);
}
vector<int> subsetSums(vector<int> arr, int n) {
    vector<int> ans;
    helper(0, 0, arr, n, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
