#include<iostream>
#include<vector>
using namespace std;

// DP approach
int lengthOfLIS(vector<int>& arr) {
    int n = arr.size(), maxi = 1, ans = 1;
    vector<int> dp(n, 1);   // Stores the LIS which will end at arr[i]
    for (int i = 1; i < n; i++) {
        maxi = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i])
                maxi = max(dp[j], maxi);
        }
        dp[i] = maxi + 1;
        ans = max(dp[i], ans);  // Stores the maximum of all the LIS.
    }
    return ans;
}

/*
    1. The algo is O(nlogn) because lower_bound() is logarithmic on a sorted input.
       We keep our vector res sorted, so the search in dp is logarithmic.
    2. Res is composed to be:
        Sorted
        Having a length of the longest found increasing sub-sequence.
        So it doesn't contain that subsequence. Only it's length is valid.
    3. So what algo is doing? For each number we have 2 options:
        If it's the highest found value, we push it back, since a high value obviously makes our increasing sequence longer.
        If it's not the highest found value, then it could be a nice start (or continuation) of a shorter sequence.
        And we keep that sequence in place. Merging all found and possible sequences into one dp.
    See how res is changing when we go through the numbers:
    [1,2,7,8,3,4,5,9,0]
    1 -> [1]
    2 -> [1,2]
    7 -> [1,2,7]
    8 -> [1,2,7,8]
    3 -> [1,2,3,8]  // we replaced 7 with 3, since for the longest sequence we need only the last number and 1,2,3 is our new shorter sequence.
    4 -> [1,2,3,4] // we replaced 8 with 4, since the max len is the same but 4 has more chances for longer sequence.
    5 -> [1,2,3,4,5]
    9 -> [1,2,3,4,5,9]
    0 -> [0,2,3,4,5,9] // we replaced 1 with 0, so that it can become a new sequence.
*/

int lowerIndex(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int lengthOfLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp;
    dp.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (dp.back() < arr[i]) {
            dp.push_back(arr[i]);
        } else {
            int index = lowerIndex(dp, arr[i]);
            // int index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin(); By using the stl function.
            dp[index] = arr[i];
        }
    }
    return dp.size();
}