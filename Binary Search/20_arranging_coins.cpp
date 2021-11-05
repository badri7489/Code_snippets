#include<iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long low = 1, high = n, mid, ans, x;
        while (low <= high) {
            mid = low + (high - low) / 2;
            x = mid * (mid + 1) / 2;
            if (x == n)
                return mid;
            else if (x <= n) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return ans;
    }
};