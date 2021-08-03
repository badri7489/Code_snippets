/**
  * Brute force is to take an array and while traversing the given array we will store all the unique one
  * and then return the size of the new array.
  * Optimal solution without extra space would be to use two pointers.
  * One pointer will traverse the whole array and the other will only be updated if we find a new value.
  * Now we return the value of the second pointer + 1.
  * One edge condition would be there when the size of the array is zero.
  */

#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i = 0, n = nums.size(), k = 1;
    while (k < n) {
        if (nums[i] != nums[k])
            nums[++i] = nums[k];
        k++;
    }
    return (n) ? i + 1 : 0;
}
