/**
  * Here we need to find all the pairs of numbers.
  * The pairs are as such arr[i] = 2 * arr[j].
  * To find this pattern in O(n) time, we use map and we also sort the array.
  * We sort the whole array.
  * We keep the count of all the values.
  * Now while traversing through the array we decrease the count of the number as well as
  * the count of 2 * number.
  * Now we check if at the end the count of all the numbers is equal to 0 or not.
  * If not then we we return false, else true.
  * Time complexity is O(n * log(n)).
  * Space complexity is O(n).
  */

#include<bits/stdc++.h>
using namespace std;

bool canReorderDoubled(vector<int>& arr) {
    unordered_map<int, int> count;
    for (int i : arr)
        count[i]++;
    sort(arr.begin(), arr.end());
    for (int i : arr) {
        if (count[i] && count[2 * i]) {
            count[i]--;
            count[2 * i]--;
        }
    }
    for (auto it : count) {
        if (it.second)
            return false;
    }
    return true;
}