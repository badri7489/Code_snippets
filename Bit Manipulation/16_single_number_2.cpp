#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(n * log(n)), all cases.
class Solution {
public:
    int singleNumber(vector<int>& arr) {
        unsigned int n = arr.size(), ans = 0, shift = 1;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int i : arr) {
                if (i & shift)  // Counting all the set bits.
                    count++;
            }
            if (count % 3)  // All the set bits count must be divisible by 3, if not then it is occuring once.
                ans += shift;
            shift *= 2;
        }
        return ans;
    }
};

// Time Complexity: O(n * log(n)), worst case
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() < 3)
            return nums[0];
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i += 3) {
            if (nums[i] != nums[i + 1])
                return nums[i];
        }
        return nums[n - 1];
    }
};

// O(n) time complexity.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int i : nums) {
            ones = (ones ^ i) & (~twos);    // Masking and containing once occuring element.
            twos = (twos ^ i) & (~ones);    // Masking and containing twice occuring element.
        }
        return ones;
    }
};