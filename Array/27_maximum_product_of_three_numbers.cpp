#include<iostream>
using namespace std;

long long maxProduct(int arr[], int n) {
    long long min1 = INT32_MAX, min2 = INT32_MAX, max1 = INT32_MIN, max2 = INT32_MIN, max3 = INT32_MIN;
    for (int i = 0; i < n; i++) {
        if (min1 > arr[i]) {
            min2 = min1;
            min1 = arr[i];
        } else if (min2 > arr[i]) {
            min2 = arr[i];
        }
        if (arr[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2) {
            max3 = max2;
            max2 = arr[i];
        } else if (arr[i] > max3) {
            max3 = arr[i];
        }
    }
    return max(min1 * min2 * max1, max1 * max2 * max3);
}