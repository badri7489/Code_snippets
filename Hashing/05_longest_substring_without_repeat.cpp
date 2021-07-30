/** We’ll use kadane’s algorithm. We take a hashset to store the elements one by one.
  * Keeping a left and right pointer we move the right until the array has been exhausted.
  * If at any point the right pointer points to a character which is present in the hashset
  * then we move the left pointer until the character which causes duplicacy has been removed.
  * O(n) for traversing the array and O(n) to remove a duplicate character.
  * So time taken is O(n^2) and space is O(n).
  * We can optimise further by improving duplicate removal.
  * Before we were traversing left one by one,
  * now we directly make the left jump to one more than the position where the duplicate is found.
  * Now a hashmap will store the location of each element.
  * This improves the efficiency and time complexity becomes O(n).
  */

#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> mp(256, -1);
    int left = 0, right = 0, n = s.length(), len = 0;
    while (right < n) {
        if (mp[s[right]] != -1)
            left = max(left, mp[s[right]] + 1);
        mp[s[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }
    return len;
}
