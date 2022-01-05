/**
  * n>>i is to keep looking at and removing the least significant bit.
  * If it is 1101, you look at 1, by doing & with 1, you are doing AND with 0001.
  * So that is basically to look at the bit 1, then next time in the loop, it looks at bit 2, so on and so forth.
  * Bit 1 should be bit 32(most significant bit) in the result,
  * result<<1 is like to enqueue the bit you just got from n (+ zero is still zero, + one is one),
  * add to the end of result, shift left.
  * By the end, the first bit you appended to result will end up as the most significant bit of the result,
  * thus "swapping" the bits.
  */

// https://leetcode.com/problems/reverse-bits/

#include<iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++)
            ans = (ans << 1) + (n >> i & 1);
        return ans;
    }
};