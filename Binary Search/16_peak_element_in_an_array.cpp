#include<iostream>
using namespace std;

int peakElement(int arr[], int n) {
    if (n == 1)
        return 0;
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (mid > 0 && mid < n - 1) {
            if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
                return mid;
            else if (arr[mid - 1] >= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } else if (mid == 0) {
            if (arr[0] > arr[1])
                return 0;
            else
                return 1;
        } else if (mid == n - 1) {
            if (arr[n - 1] > arr[n - 2])
                return n - 1;
            else
                return n - 2;
        }
    }
    return -1;
}