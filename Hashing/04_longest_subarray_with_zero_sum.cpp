/**
  * Optimal solution would be to use Kadane’s algorithm here.
  * We will sum the array one element at a time and store this sum in a hashmap(sum, i),if it isn’t there.
  * But if the sum is in the hashmap then we will store the length of the subarray
  * that makes the total sum again to one of those present in the hashmap.
  * Max_length = i - hashmap(sum, i).
  * One more case is where if the sum is itself zero then we know that all the elements from the beginning makes it zero.
  * So we store its length too as one of the subarrays.
  * This is all done in a single traversal, but to find the sum from the hashmap it takes O(log(n) time.
  * So overall time complexity is O(n * log(n)), and O(n) space.
  */

#include<bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n) {
    map<int, int> mp;
    int sumi = 0, maxi = 0;
    for (int i = 0; i < n; i++) {
        sumi += arr[i];
        if (sumi == 0)
            maxi = i + 1;
        else if (mp.find(sumi) == mp.end())
            mp[sumi] = i;
        else
            maxi = max(maxi, i - mp[sumi]);
    }
    return maxi;
}
