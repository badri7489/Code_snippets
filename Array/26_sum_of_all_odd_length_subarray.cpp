/**
  * We need to find the sum of all the subarrays of odd length.
  * For this we need to how many times a particular index of the array is the beginning of a subarray.
  * And the number of times an index is the end of a subarray.
  * This denotes how many times that particular index will appear in the subarrays.
  * Total = start * end.
  * To find the odd lenghts, we need to divide by 2.
  * If the total is odd then number of odd length subarrays will be 1 more than even length subarrays.
  * The sum is simply the value at index i times the occurence of that index in subarray.
  * Time complexity: O(n).
  * Space complexity: O(1).
  */

#include<bits/stdc++.h>
using namespace std;

int sumOddLengthSubarrays(vector<int>& arr) {
    int n = arr.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        int start = n - i;
        int end = i + 1;
        int total = start * end;
        int odd = total / 2;
        if (total % 2 == 1)
            odd++;
        ans += odd * arr[i];
    }
    return ans;
}