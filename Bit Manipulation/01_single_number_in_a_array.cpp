/**
  * The array contains all numbers twice except for one.
  * We need to find that element in linear time and constant space.
  * When we xor an element with 0 we get that number.
  * When we xor an element with itself then we get 0.
  * Hence we xor all the elements of the array.
  * Since each element occurs twice in the array except for one
  * every element xor's with itself and becomes 0 and only the sinle element is left.
  * Time complexity is O(n).
  * Space complexity is constant.
  */

#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int it : nums)
        ans ^= it;
    return ans;
}