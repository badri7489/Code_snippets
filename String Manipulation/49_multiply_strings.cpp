#include<iostream>
using namespace std;

class Solution {
private:
    string addi(string a, string b) {
        if (a.length() < b.length())
            return addi(b, a);
        int m = a.length(), n = b.length(), carry = 0, sumi, x, y;
        string ans = "";
        for (int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry; i--, j--) {
            x = i >= 0 ? a[i] - '0' : 0;
            y = j >= 0 ? b[j] - '0' : 0;
            sumi = x + y + carry;
            carry = sumi / 10;
            sumi = sumi % 10;
            ans = to_string(sumi) + ans;
        }
        return ans;
    }
public:
    string multiply(string a, string b) {
        if (a == "0" || b == "0")
            return "0";
        if (a.length() < b.length())
            return multiply(b, a);
        string ans = "", temp = "";
        int pro = 0, carry = 0;
        int n = b.length(), m = a.length(), k = 0;
        for (int i = n - 1; i >= 0; i--) {
            temp = "";
            for (int l = 0; l < k; l++)
                temp += "0";
            k++;
            carry = 0;
            for (int j = m - 1; j >= 0; j--) {
                pro = (a[j] - '0') * (b[i] - '0') + carry;
                carry = pro / 10;
                pro = pro % 10;
                temp = to_string(pro) + temp;
            }
            if (carry)
                temp = to_string(carry) + temp;
            ans = addi(ans, temp);
        }
        return ans;
    }
};