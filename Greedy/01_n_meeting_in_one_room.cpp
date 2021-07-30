/** To have the max number of meetings in a room we must sort according to the finish time
  * because if we sort according to the starting time then once a meeting starts it might take a long time to end.
  * But if we sort according to the end time then we can finish a meeting as soon as possible and more meetings can be held.
  * Time complexity is O(n * log(n)) and space is O(n).
  */

#include<bits/stdc++.h>
using namespace std;

struct meet {
    int start, end;
};

bool comparator(struct meet a, struct meet b) {
    return a.end < b.end;
}

int maxMeetings(int start[], int end[], int n) {
    struct meet arr[n];
    for (int i = 0; i < n; i++)
        arr[i].start = start[i], arr[i].end = end[i];
    sort(arr, arr + n, comparator);
    int ans = 1, end_time = arr[0].end;
    for (int i = 1; i < n; i++) {
        if (arr[i].start > end_time) {
            ans++;	end_time = arr[i].end;
        }
    }
    return ans;
}
