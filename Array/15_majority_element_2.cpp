/** We need to find the element which has more than floor of n / 2 appearances.
  * Brute force would be to take an element and count its occurrences, and keep on doing for the rest.
  * This will be an O(n * 2) time complexity algorithm.
  * Better approach would be to sort the array and find the one with majority count by linearly traversing the array.
  * We can use hashing also. We can use a hashmap to store the count of each element and eureka, problem solved.
  * Time complexity will be O(n) and space will be O(n).
  * Optimal Solution will be to use Moore’s Voting Algorithm.
  * Here what we are essentially doing is making pairs with the majority element, fix a majority element,
  * increment the count till you find a different element and decrease the count for a different element.
  * Here decreasing the count simply means, making a pair of majority and non-majority elements and removing them from the array.
  * Once the count reaches zero, make a new majority element because the deleted pairs had an equal count of majority
  * and non-majority elements.
  * When we reach the end we will have the majority element selected due to the process we followed and
  * since it was mentioned in the question that
  * "You may assume that the array is not empty and the majority element always exists in the array",
  * we do not need to verify the solution.
  * Hence it becomes an O(n) time complexity solution.
  */

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0, ele;
    for (int i = 0; i < nums.size(); i++) {
        if (count == 0) {
            ele = nums[i];
        }
        if (ele == nums[i]) {
            count++;
        } else {
            count--;
        }
    }
    return ele;
}
