#include<bits/stdc++.h>
using namespace std;
#define number_of_chars 256

char second_most(string s) {
    int count[number_of_chars] = { 0 };
    for (char& c : s)
        count[c]++;
    int maxi = 0, second_maxi = 0;
    for (int i = 0; i < number_of_chars; i++) {
        if (count[i] > count[maxi]) {
            second_maxi = maxi;
            maxi = i;
        } else if (count[i] > count[second_maxi] && count[i] != count[maxi]) {
            second_maxi = i;
        }
    }
    return second_maxi;
}

int main() {
    fstream file;
    file.open("24_test_cases.txt");
    string s;
    while (getline(file, s)) {
        char c = second_most(s);
        if (c == '\0')
            cout << s << " has no second most unique characters." << endl;
        else
            cout << s << ": " << c << endl;
    }
    return 0;
}