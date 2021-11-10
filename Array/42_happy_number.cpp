#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
private:
    int digit_square(int n) {
        int rem, ans = 0;
        while (n > 0) {
            rem = n % 10;
            ans += rem * rem;
            n /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while (n != 1) {
            int dig = digit_square(n);  // The sum square of digits.
            if (dig == 1)   // If 1 we return true.
                return true;
            if (st.find(dig) != st.end())   // If it has been found before we are moving in a loop.
                return false;
            st.insert(dig);
            n = dig;
        }
        return true;
    }
};