#include<iostream>
#include<vector>
using namespace std;

// We need to maximise arr[i] + i + arr[j] - j for all i < j.
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& arr) {
        int n = arr.size(), ans = INT32_MIN, aiplusi = arr[0] + 0;  // Store the first arr[i] + i.
        for (int j = 1; j < n; j++) {   // Looping from 1 because we have i < j.
            ans = max(ans, aiplusi + arr[j] - j);
            aiplusi = max(aiplusi, arr[j] + j); // arr[i] + i is maximum of the previous and current.
        }
        return ans;
    }
};