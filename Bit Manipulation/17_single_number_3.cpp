#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xy = 0;    // Contains xor of all numbers.
        for (int i : nums)
            xy ^= i;
        // Finally xy will have xor of all numbers.
        xy &= -xy;  // Now xy will have the first set bit.
        vector<int> ans = { 0, 0 };
        for (int i : nums) {
            if (xy & i) // Divide all numbers into two groups
                ans[0] ^= i;    // And xoring all of them will give the number because they will be in diff groups.
            else
                ans[1] ^= i;
        }
        return ans;
    }
};