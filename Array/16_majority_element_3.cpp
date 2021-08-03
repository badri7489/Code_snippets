/**
  * Taking the idea from the above problem we can extend it to find majority elements that appear more than n/3 times.
  * In this case, first we need to understand that there will be at most 2 majority elements.
  * So just like we did in the simpler version of the problem,
  * we take two elements as the majority element and maintain their frequency counts and
  * once we find an element that differs from the two, we decrement both the elements’ counts.
  * In this case we have to look for triplets instead of pairs.
  * This essentially means that we form a triplet out of 2 majority and one non-majority element and remove them from the array.
  * We repeat the process till we consider all array elements and simply verify if the elements we found are correct or not,
  * which can be done in a single pass.
  * Hence this becomes a O(n) time complexity algorithm.
  */

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int count = 0, count2 = 0, ele1 = -1, ele2 = -1, n = nums.size();
    for (int i = 0; i < n; i++) {
        if (ele1 == nums[i]) {
            count++;
        } else if (ele2 == nums[i]) {
            count2++;
        } else if (count == 0) {
            ele1 = nums[i];
            count = 1;
        } else if (count2 == 0) {
            ele2 = nums[i];
            count2 = 1;
        } else {
            count--;
            count2--;
        }
    }
    vector<int> ans;
    count = count2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == ele1)
            count++;
        else if (nums[i] == ele2)
            count2++;
    }
    if (count > n / 3)
        ans.push_back(ele1);
    if (count2 > n / 3)
        ans.push_back(ele2);
    return ans;
}
