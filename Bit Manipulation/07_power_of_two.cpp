// https://leetcode.com/problems/power-of-two/

#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 ? !(n & (n - 1)) : false;
    }
};