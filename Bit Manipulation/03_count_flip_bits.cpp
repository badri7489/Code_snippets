// https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1

#include<iostream>
using namespace std;

int countBitsFlip(int a, int b) {
    int x = a ^ b;  // The difference of set bits.
    int count = 0;
    while (x > 0) {
        count++;
        x &= (x - 1);
    }
    return count;
}