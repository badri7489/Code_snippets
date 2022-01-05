// https://leetcode.com/problems/binary-watch/

#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (bitset<10>(h << 6 | m).count() == turnedOn)
                    ans.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
            }
        }
        return ans;
    }
};