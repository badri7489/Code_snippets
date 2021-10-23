#include<iostream>
#include<vector>
using namespace std;

// My approach with out of bound condition I couldn't figure out.
class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size(), low = 0, high = n - 1, mid, prev, next;
        while (low <= high) {
            mid = low + (high - low) / 2;
            prev = (mid - 1 + n) % n;   // Previous with out of bound check.
            next = (mid + 1) % n;       // Next with out of bound check.
            // If mid is smaller than its next and smaller than its previous, we got the pivot.
            if (arr[mid] < arr[next] && arr[mid] < arr[prev])
                return arr[mid];
            else if (arr[mid] <= arr[high]) // If right side is all sorted, we go to the left to find pivot.
                high = mid - 1;
            else    // Else the left side is sorted so we find it on the right.
                low = mid + 1;
        }
        return arr[mid];
    }
};

class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0, high = arr.size() - 1, mid, ans = arr[0];
        while (low <= high) {
            if (arr[low] < arr[high]) { // If the boundary is sorted.
                ans = min(arr[low], ans);   // We find min and break the loop.
                break;
            }
            mid = low + (high - low) / 2;
            ans = min(ans, arr[mid]);   // Check if mid is the minimum.
            if (arr[low] <= arr[mid])   // If left is all sorted, we go to check on right.
                low = mid + 1;
            else    // If right is all sorted, we go to check on left.
                high = mid - 1;
        }
        return ans;
    }
};