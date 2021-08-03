/**
  * Here in this job sequencing problem we need to have maximum profit as well we need to submit the jobs before the deadline.
  * If a job’s deadline is on a 5th day then we can submit it from day 1 to day 5.
  * Hence To maximize the profit we sort the Job array according to the profit in descending order.
  * Then we take a deadline array of size equal to the max time deadline.
  * Then we traverse the Job array and mark the last date of each job's deadline in the deadline array.
  * If that particular position is taken then we move to the left and check for a vacant place to fit the job.
  * Side by side we also keep a count of the jobs done and the profit made.
  * Time complexity is O(n * log(n)) and space complexity is O(n).
  */

#include<bits/stdc++.h>
using namespace std;

struct Job {
    int dead;
    int profit;
};

static bool comparator(Job a, Job b) {
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) {
    sort(arr, arr + n, comparator);
    int maxi = arr[0].dead;
    for (int i = 1; i < n; i++)
        maxi = max(maxi, arr[i].dead);
    int slot[maxi + 1];
    for (int i = 0; i <= maxi; i++)
        slot[i] = -1;
    int countJobs = 0, jobProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }
    return vector<int> {countJobs, jobProfit};
}
