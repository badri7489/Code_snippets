/**
  * If a number is a power of 4 then the number 4^n -1 is a multiple of 3
  * (1) 4^n - 1 = (2^n + 1) * (2^n - 1)
  * (2) among any 3 consecutive numbers, there must be one that is a multiple of 3
  *     among (2^n-1), (2^n), (2^n+1), one of them must be a multiple of 3, and (2^n) cannot be the one,
  *     therefore either (2^n-1) or (2^n+1) must be a multiple of 3, hence 4^n-1 must be a multiple of 3 as well.
  */

#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};