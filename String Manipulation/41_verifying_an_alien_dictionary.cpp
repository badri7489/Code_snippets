#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isAlienSorted(vector<string>& words, string order) {
    int order_map[26];
    for (int i = 0; i < 26; i++)
        order_map[order[i] - 'a'] = i;
    for (int i = 0; i < words.size() - 1; i++) {
        string w1 = words[i];
        string w2 = words[i + 1];
        int j, len = min(w1.length(), w2.length());
        for (j = 0; j < len; j++) {
            if (w1[j] != w2[j]) {
                if (order_map[w1[j] - 'a'] > order_map[w2[j] - 'a'])
                    return false;
                break;
            }
        }
        if (j == len && w1.length() > w2.length())
            return false;
    }
    return true;
}