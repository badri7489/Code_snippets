/** We can simply sort(Brute) the whole array and then find the one which is duplicate and the missing one.
  * A better approach than this would be to keep track of all the numbers from 1 to N, using a map.
  * A much better approach would be to change the values to negative so
  * that we can keep a track of those who have been visited and the ones that haven't been visited.
  * So the one value which is positive is supposed to be the one which is missing.
  * The repeating one will have the negative value in the array at ith position.
  */

#include <bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(int* arr, int n) {
    int i;
    vector<int> ans;
    for (i = 0; i < n; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            ans.push_back(abs(arr[i]));
    }
    for (i = 0; i < n; i++) {
        if (arr[i] > 0)
            ans.push_back(i + 1);
    }
    return ans;
}
