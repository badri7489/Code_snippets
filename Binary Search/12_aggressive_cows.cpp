/**
  * Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls.
  * The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
  * His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall.
  * To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls,
  * such that the minimum distance between any two of them is as large as possible.
  * What is the largest minimum distance?
  * Brute force would be to check for all the distances possible, starting from 1 to difference (max(arr), min(arr)).
  * This will be O(n^2) time complexity.
  * To optimise this solution we can apply binary search on this question.
  * Now the main question is what is the search space.
  * Since we are told that the array of positions given is not sorted.
  * We will apply binary search on the distance.
  * 1 to difference (max(arr), min(arr)).
  * We take the mid of the distane and try to place all the c cows.
  * If we are successfully able to place all the cows, we take that mid as one of the answer.
  * Now we will modify our search space since we are asked to find the largest minimum distance.
  * Search space will start from low = mid + 1.
  * If it isn't possible to place all c cows then we modify the search space to high = mid - 1.
  * Beacuse all the distances greater than mid won't be able to place all the c cows.
  * Time complexity will be O(n * log(n)).
  * Log(n) time for binary search.
  * N time for checking if it is possible to place all the cows or not.
  */

// Problem link : https://www.spoj.com/problems/AGGRCOW/
#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int> arr, int cows, int distance) {
    int n = arr.size(), cord = arr[0], count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] - cord >= distance) {
            count++;
            cord = arr[i];
        }
        if (count == cows)
            return true;
    }
    return false;
}

int aggressive_cows(vector<int> arr, int cows) {
    int n = arr.size(), low = 1, high = arr[n - 1] - arr[0], res = 1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (possible(arr, cows, mid)) {
            low = mid + 1;
            res = mid;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        cout << aggressive_cows(arr, c) << endl;
    }
    return 0;
}