#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// DP Solution.
int findLongestChain(vector<vector<int>>& pairs) {
    // Sort all the pairs increasingly.
    sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1];});
    int n = pairs.size(), maxi = 1;
    // Now solve same as LIS.
    // Slight change is that we compare 1st of ith and 2nd of jth.
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (pairs[i][0] > pairs[j][1])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxi = max(dp[i], maxi);
    }
    return maxi;
}

// Loop Hole of the DP question.
int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1];});
    int n = pairs.size(), count = 0;
    for (int i = 0, j = 0; j < n; j++) {
        if (j == 0 || pairs[i][1] < pairs[j][0]) {
            i = j;
            count++;
        }
    }
    return count;
}