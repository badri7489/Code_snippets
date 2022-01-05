/**
 * Problem link : https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
 */

#include<bits/stdc++.h>
using namespace std;

bool possible(int arr[], int n, int m, int barrier) {
    int stud = 0, pages = 0;
    for (int i = 0; i < n; i++) {
        if (pages + arr[i] > barrier) {
            stud++;
            pages = arr[i];
            if (pages > barrier)
                return false;
        } else {
            pages += arr[i];
        }
    }
    if (stud < m)
        return true;
    return false;
}

int findPages(int arr[], int n, int m) {
    if (m > n)
        return -1;
    int low = arr[0], high = 0, ans = -1;
    for (int i = 0; i < n; i++) {
        high += arr[i];
        low = min(low, arr[i]);
    }
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (possible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}