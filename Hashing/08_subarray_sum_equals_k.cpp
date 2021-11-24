#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(), count = 0, sumi = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            sumi += arr[i];
            if (sumi == k)  // if sum is directly equal to k
                count++;
            if (mp.find(sumi - k) != mp.end())  // if we find the current sum - k in the map it means we have found
                count += mp[sumi - k];  // the same sum again so we increment the count that many time, we found the sum.
            mp[sumi]++; // put it in the map.
        }
        return count;
    }
};