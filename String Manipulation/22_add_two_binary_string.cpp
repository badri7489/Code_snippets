#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string sum_binary(string& a, string& b) {
    string result = "";
    int carry = 0, i = a.length() - 1, j = b.length() - 1;
    while (i >= 0 || j >= 0 || carry) {
        carry += (i >= 0) ? a[i] - '0' : 0;
        carry += (j >= 0) ? b[j] - '0' : 0;
        result = (char)(carry % 2 + '0') + result;
        carry = carry / 2;
        i--;
        j--;
    }
    return result;
}

int main() {
    string a, b;
    fstream file;
    file.open("22_test_cases.txt");
    while (file >> a >> b) {
        cout << a << " + " << b << " = ";
        cout << sum_binary(a, b) << endl;
    }
    file.close();
    return 0;
}