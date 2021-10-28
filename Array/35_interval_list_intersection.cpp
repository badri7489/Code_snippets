#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& list1, vector<vector<int>>& list2) {
        if (list1.empty() || list2.empty())
            return {};
        int m = list1.size(), n = list2.size(), i = 0, j = 0;
        vector<vector<int>> ans;
        while (i < m && j < n) {
            int first = max(list1[i][0], list2[j][0]);
            int second = min(list1[i][1], list2[j][1]);
            if (first <= second)
                ans.push_back({ first, second });
            if (list1[i][1] < list2[j][1])
                i++;
            else if (list1[i][1] > list2[j][1])
                j++;
            else
                i++, j++;
        }
        return ans;
    }
};