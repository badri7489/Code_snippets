/** Matrix median is finding the median of the matrix values if placed in a sorted order.
  * We suppose that the median lies in range 1-10^9 (Taken as such beacuse of the constraints).
  * Binary search is applied and each time we calculate the mid value,
  * then we count the number of values in the matrix which are less than or equal to mid(using binary search).
  * If the count is less than or equal to half of the number of elements, then make low = mid+1 else high = mid-1.
  * Low value is the required median.
  * In order to calculate the number of elements in the matrix which are less than or equal to mid,
  * for every row of the matrix run a binary search to find the index of the element greater than mid.
  * Low value gives the count of the number of elements less than or equal to mid.
  */

#include<bits/stdc++.h>
using namespace std;

int countSmaller(vector<int>& row, int mid) {
    int l = 0, h = row.size() - 1;
    while (l <= h) {
        int md = (l + h) >> 1;
        if (row[md] <= mid)
            l = md + 1;
        else
            h = md - 1;
    }
    return l;
}
int median(vector<vector<int>>& matrix, int r, int c) {
    int low = 1, high = 1e9;
    while (low <= high) {
        int mid = (high + low) >> 1, count = 0;
        for (int i = 0; i < r; i++)
            count += countSmaller(matrix[i], mid);
        if (count <= (r * c) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
