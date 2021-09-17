#include<bits/stdc++.h>
using namespace std;

string change_case(string s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;
        else if (s[i] >= 97 && s[i] <= 122)
            s[i] -= 32;
    }
    return s;
}

string change_case_xor(string s) {
    for (char& c : s) {
        if (isalpha(c))
            c ^= 32;
    }
    return s;
}

int main() {
    string s;
    fstream file;
    file.open("23_test_cases.txt");
    while (getline(file, s)) {
        cout << s << ": " << change_case(s) << endl;
    }
    return 0;
}
