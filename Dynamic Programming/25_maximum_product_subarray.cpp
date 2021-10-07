#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

// 1. When all are positive, we multiply all to get the max.
// 2. When negatives come then we need to multiply the previous max to the number and the previous min to the number
//    and the number itself, then we find the max and same for the min
// 3. When there is a 0 in between the product gets divided into parts.
//      ....... 0 ...... 0 ......
// Time Complexity: O(n).
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), max_prod = 1, min_prod = 1, temp, ans = INT32_MIN;
        for (int i : nums) {
            temp = max_prod;
            max_prod = max({ temp * i, min_prod * i, i });
            min_prod = min({ temp * i, min_prod * i, i });
            ans = max(ans, max_prod);
        }
        return ans;
    }
};