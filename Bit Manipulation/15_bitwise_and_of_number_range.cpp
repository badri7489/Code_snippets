// https://leetcode.com/problems/bitwise-and-of-numbers-range/

#include<iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        while (left != right) {
            left = left >> 1;
            right = right >> 1;
            count++;
        }
        return left << count;
    }
};