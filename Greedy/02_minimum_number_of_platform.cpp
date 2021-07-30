/** We need to sort the arrival and the departure array separately.
  * This will tell us when the next train is arriving and when a train at one of the platforms is leaving.
  * Now keeping track of the arrivals and departures by two separate pointers we will start counting the platforms.
  * If arriving train time is less than equal to the departure train time then we need one more station.
  * If the departure train time is less than the arriving train time then we need one less platform.
  * Thus by increasing and decreasing the number of platforms we can find the max number of platforms required.
  * Time complexity will be O(n) and space is constant.
  */

#include<bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);
    int plat = 1, i = 1, j = 0, ans = 1;
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat++;
            i++;
        } else if (arr[i] > dep[j]) {
            plat--;
            j++;
        }
        ans = max(ans, plat);
    }
    return ans;
}
