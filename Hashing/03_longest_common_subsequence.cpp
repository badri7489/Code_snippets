/** Brute force would be to simply sort and find the streak, which is O(n * log(n)).
  * To optimize it we can store all the distinct elements,
  * then loop to check for the element whose predecessor doesn’t exist.
  * Then loop forward until the successors of that particular element exist.
  * Then repeat till the array is exhausted and we find the maximum streak.
  * Time complexity would be O(n).
  * Space complexity will be O(n).
  */

#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    set<int> hash;
    for (int i = 0; i < nums.size(); i++) {
        hash.insert(nums[i]);
    }
    int maxi = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (!hash.count(nums[i] - 1)) {
            int currentNum = nums[i], currentStreak = 1;
            while (hash.count(currentNum + 1)) {
                currentNum++;
                currentStreak++;
            }
            maxi = max(maxi, currentStreak);
        }
    }
    return maxi;
}
