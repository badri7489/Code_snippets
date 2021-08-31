/**
  * Nth root of the element lies between 1 and number.
  * Binary search can be applied within this range to find the nth root.
  * Calculate the mid value each time and its corresponding nth power and then compare it with the number.
  * If the value is less than the number, make low = mid else high = mid.
  * Run this loop until the difference between low and high is greater than 0.000001, or any precision of your choice.
  * Hence, low is our required nth root.
  * Time complexity of this solution is O(n * log (M*(10^d)) where d = no. of decimal places.
  */

#include<bits/stdc++.h>
using namespace std;

double multiply(double number, int n) {
    double ans = 1.0;
    for (int i = 0; i < n; i++)
        ans *= number;
    return ans;
}

double getNthRoot(int n, int m) {
    double low = 1, high = m, eps = 0.000001;
    while ((high - low) > eps) {
        double mid = (low + high) / 2.0;
        if (multiply(mid, n) < m)
            low = mid;
        else
            high = mid;
    }
    cout << low << " " << high << endl;
    cout << pow(m, (double)(1.0 / (double)n));
}
