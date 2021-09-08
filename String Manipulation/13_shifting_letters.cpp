/**
  * Input: s = "abc", shifts = [3,5,9]
  * Output: "rpl"
  * Explanation: We start with "abc".
  * After shifting the first 1 letters of s by 3, we have "dbc".
  * After shifting the first 2 letters of s by 5, we have "igc".
  * After shifting the first 3 letters of s by 9, we have "rpl", the answer.
  * Time Complexity: O(n).
  */
#include<bits/stdc++.h>
using namespace std;

string shiftingLetters(string s, vector<int>& shifts) {
    int n = s.length(), shift = 0;
    for (int i = n - 1; i >= 0; i--) {
        shift = (shift + shifts[i]) % 26;   // Calculating the shift required and keeping it is in the range of 26.
        s[i] = (s[i] - 'a' + shift) % 26 + 'a'; // Adding the shift and again keeping it in range using modulo operator.
    }
    return s;
}