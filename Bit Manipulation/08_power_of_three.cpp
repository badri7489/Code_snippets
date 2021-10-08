#include<iostream>
using namespace std;

class Solution {
private:
    const int max3Power = 1162261467;
public:
    bool isPowerOfThree(int n) {
        if (n <= 0 || n > max3Power)
            return false;
        return max3Power % n == 0;
    }
};