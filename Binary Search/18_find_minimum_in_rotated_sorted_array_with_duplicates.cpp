#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size(), low = 0, high = arr.size() - 1, mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (arr[mid] > arr[high])
                low = mid + 1;
            else if (arr[mid] < arr[high])
                high = mid;
            else    // when num[mid] and num[hi] are same
                high--;
        }
        return arr[low];
    }
};