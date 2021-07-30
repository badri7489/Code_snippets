#include<bits/stdc++.h>
using namespace std;

int countSmaller(vector<int>& row, int mid) {
    int l = 0, h = row.size() - 1;
    while (l <= h) {
        int md = (l + h) >> 1;
        if (row[md] <= mid)
            l = md + 1;
        else
            h = md - 1;
    }
    return l;
}
int median(vector<vector<int>>& matrix, int r, int c) {
    int low = 1, high = 1e9;
    while (low <= high) {
        int mid = (high + low) >> 1, count = 0;
        for (int i = 0; i < r; i++)
            count += countSmaller(matrix[i], mid);
        if (count <= (r * c) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
