#include<bits/stdc++.h>
using namespace std;

bool checkIfExist(vector<int>& arr) {
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]]++;
        if (arr[i] == 0 && mp[arr[i]] == 1)
            continue;
        if (mp.count(2 * arr[i]) || (arr[i] % 2 == 0 && mp.count(arr[i] / 2)))
            return true;
    }
    return false;
}