#include<iostream>
#include<vector>
using namespace std;

int minSwaps(vector<int> arr) {
    int n = arr.size(), k = 0;
    for (int it : arr)
        k += it;
    cout << "k: " << k << endl;
    int i = 0, j = 0, zero = 0, ans = INT32_MAX;
    while (i < n) {
        if (arr[i] == 0)
            zero++;
        if (i - j + 1 < k) {    // window size is less than k
            i++;
        } else {    // window size is equal to k
            ans = min(ans, zero);   // we take the maximum
            if (arr[j++] == 0)  // we decrease the window
                zero--; // if that number at index j is '0' then we decrease the count of zeros
        }
    }
    return ans;
}

int main() {
    vector<int> arr = { 1, 0, 1, 0, 1 };
    cout << "1. " << minSwaps(arr) << endl;
    vector<int> arr1 = { 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1 };
    cout << "2. " << minSwaps(arr1) << endl;
    return 0;
}