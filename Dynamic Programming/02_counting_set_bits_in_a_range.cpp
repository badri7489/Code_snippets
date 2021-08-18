/**
  * We need to give a vector of number of set bits in a range of numbers.
  * Brute force would be to loop from 0 to n then divide it by two and count the number of 1's.
  * Time complexity: O(n * log(n)).
  *
  * In this solution, we can think about whether the number is even or odd.
  * If the number is even, the number of 1s is equal to the number which is half of it.
  * For ex, the number 8 has the same 1s as the number 4.
  * The number 10 has the same 1s as the number 5.
  * That is because number i is just left shift by 1 bit from number i / 2.
  * Therefore, they should have the same number of 1 bits.
  * If the numbers are odd, ex 1, 3, 5, 7.
  * The number of 1 bits is equal to the number (i - 1) plus 1.
  * For e.g., for number 3, the number of 1 bits equals to the number 2 plus 1.
  * For number 11, it equals to number 10 + 1.
  * Time complexity: O(n).
  */

#include<bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
        ans[i] = ans[i / 2] + ((i % 2 == 1) ? 1 : 0);
    return ans;
}