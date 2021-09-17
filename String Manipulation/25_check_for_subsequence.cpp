#include<iostream>
#include<string>
using namespace std;

bool isSubSequence(string a, string b) {
    int m = a.length(), n = b.length(), i = 0, j = 0;
    while (i < m && j < n) {
        if (a[i] == b[j])
            i++;
        j++;
    }
    return i == m;
}