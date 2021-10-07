#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n;) {
            int s = i;
            while (s < n && nums[s] == 0)
                s++;
            // A frame is all the numbers in betwee 0s.
            // s: start of a frame, e: end of a frame.
            int e = s, count = 0, startNegative = -1, lastNegative = -1;
            while (e < n && nums[e] != 0) {
                if (nums[e] < 0) {
                    count++;    // Counting negative numbers in the frame.
                    if (startNegative == -1)
                        startNegative = e;  // First negative number of the frame.
                    lastNegative = e;   // Last negative number of the frame.
                }
                e++;
            }
            if (count % 2 == 0) // If we have even negative then all the negatives will be taken into consideration.
                ans = max(ans, e - s);
            else {
                if (startNegative != -1)    // We exclude the first negative number.
                    ans = max(ans, e - startNegative - 1);
                if (lastNegative != -1)     // We exclude the last negative number.
                    ans = max(ans, lastNegative - s);
            }
            i = e + 1;  // i moves to the end of the frame.
        }
        return ans;
    }
};

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int frameStart = -1, firstNegative = -2, len = 0, count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)   // If we encounter 0 we make that as the frame start and init first negative and the count.
                count = 0, frameStart = i, firstNegative = -2;
            else {
                if (nums[i] < 0)    // Count the negatives in the frame.
                    count++;
                if (count == 1 && firstNegative == -2)  // Init the first negative number.
                    firstNegative = i;
                if (count % 2 == 0) // If the negative number count is even.
                    len = max(len, i - frameStart);
                else    // If the negative number count is odd, we exclude the first negative number and take its length.
                    len = max(len, i - firstNegative);
            }
        }
        return len;
    }
};