/**
  * You might have noticed here :
  * ra >> buff >> ia >> buff;
  * int >> char >> int >> char
  * ra - int => it will get integer value including any prefix sign
  * buff - char => it will take '+' delimiter which divides real and imaginary val
  * ia -int => it will get integer value including any prefix sign
  * buff - char => it will take the value 'i'
  * e.g.
  * 1. "1+1i"
  * ra = 1, buff = '+', ia = 1, buff = 'i'
  * 2. "-1+-1i"
  * ra = -1, buff = '+', ia = -1, buff = 'i'
  * ( -1 is valid integer )
  */

#include<bits/stdc++.h>
using namespace std;

// Using String Stream Class
string complexNumberMultiply(string num1, string num2) {
    int ra, ia, rb, ib;
    char buff;
    stringstream aa(num1), bb(num2), ans;
    aa >> ra >> buff >> ia >> buff;
    bb >> rb >> buff >> ib >> buff;
    ans << ra * rb - ia * ib << "+" << ra * ib + rb * ia << "i";
    return ans.str();
}

// Without using String Stream Class of Strings.
pair<int, int> extract(string s) {
    int l = s.length(), i = 1, a, b;
    while (i < l && s[i] != '+')
        i++;
    a = stoi(s.substr(0, i));
    b = stoi(s.substr(i + 1));
    return make_pair(a, b);
}
string complexNumberMultiply(string a, string b) {
    if (a == "")
        return b;
    if (b == "")
        return a;
    auto p1 = extract(a);
    auto p2 = extract(b);
    int x = p1.first * p2.first - p1.second * p2.second;
    int y = p1.second * p2.first + p1.first * p2.second;
    string s;
    return to_string(x) + "+" + to_string(y) + "i";
}