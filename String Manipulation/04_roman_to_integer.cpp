/**
  * Roman numbers are written with first number as the biggest.
  * Then the smaller numbers follow.
  * Only exception occurs when there is 4, 9, 49...
  * Then we write the smaller number first and then the bigger number.
  * So we loop the string from the end.
  * We check if the number before is less then we subtract that number.
  * Else we simply keep on adding.
  * We are using integer array because it is faster to access than a map or unordered map.
  * Time is O(n).
  */

#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    int roman[26];
    roman['I' - 'A'] = 1;
    roman['V' - 'A'] = 5;
    roman['X' - 'A'] = 10;
    roman['L' - 'A'] = 50;
    roman['C' - 'A'] = 100;
    roman['D' - 'A'] = 500;
    roman['M' - 'A'] = 1000;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i == s.length() - 1 || roman[s[i] - 'A'] >= roman[s[i + 1] - 'A'])
            ans += roman[s[i] - 'A'];
        else
            ans -= roman[s[i] - 'A'];
    }
    return ans;
}