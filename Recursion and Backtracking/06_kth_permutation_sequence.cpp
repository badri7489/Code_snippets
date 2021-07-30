/** The kth permutation of n numbers from 1 to n.
  * We can do it linearly by using maths.
  * We know that each number will appear at the first position for a certain factorial number of times.
  * Hence we calculate that and subtract that from k, until k is not 0.
  * This is O(n^2) time complexity.
  */

#include<bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k) {
    vector<int> numbers;
    int fact = 1;
    for (int i = 1; i < n; i++) {
        fact *= i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k--;
    while (true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0)	break;
        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}
