/**
  * We need to find the median of 2 sorted arrays.
  * Median means the middle element of an array.
  * If an odd number of elements then its the element itself,
  * if even then its the half of the first and the second middle element.
  * We can do binary search on the shorter array.
  * The time to find the median depends solely on the size of the shorter array.
  * It makes sense because if A has only one element while B has 100 elements,
  * the median must be one of A[0], B[49], and B[50] without even checking everything else.
  * If A[0] <= B[49], B[49] is the answer; if B[49] < A[0] <= B[50], A[0] is the answer; else, B[50] is the answer.
  *
  * We take a total of (m + n) / 2 elements all total as a combination of arr1, arr2.
  * Then we check if last of arr1 is <= first of arr2 and last of arr2 <= first of arr1.
  * If this condition satisfies then we return the median for odd elements as the max(l1, l2)
  * and for even elements as (max(l1, l2) + min(r1, r2)) / 2.
  * If the condition fails then we try to move the partition to the left or the right accordingly.
  * Also we need to take the edge case as it is when the partition is done at the point
  * where all elements are on one side and the rest on the other.
  * Then we need to initialize the left as -infinity and right as +infinity.
  * Time complexity O(log(min(m, n))).
  * Constant space.
  */

#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums2.size() < nums1.size())
        return findMedianSortedArrays(nums2, nums1);
    int n1 = nums1.size(), n2 = nums2.size(), low = 0, high = n1, cut1, cut2;
    while (low <= high) {
        cut1 = (low + high) >> 1;
        cut2 = (n1 + n2 + 1) / 2 - cut1;
        int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

        int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
        int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

        if (l1 <= r2 && l2 <= r1) {
            if ((n1 + n2) % 2)
                return (double)max(l1, l2);
            else
                return (max(l1, l2) + min(r1, r2)) / 2.0;
        } else if (l1 > r2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }
    return 0.0;
}