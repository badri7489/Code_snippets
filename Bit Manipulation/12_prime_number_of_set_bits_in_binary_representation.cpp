// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
private:
    unordered_set<int> prime;
    bool setBit(int n) {
        int count = 0;
        while (n > 0) {
            count += n % 2;
            n /= 2;
        }
        return prime.find(count) != prime.end();
    }
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        prime = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
        for (int i = left; i <= right; i++) {
            if (setBit(i))
                count++;
        }
        return count;
    }
};