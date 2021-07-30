/** Here we sort the array in ascending order.
  * Then to count the number of coins we start from the back,
  * we subtract the value of the coins from the amount until the amount is bigger than the coin.
  * If the coin value is bigger then we go to a low value coin and carry the same process.
  * Meanwhile doing this process we also count the coins.
  * Time taken is O(n).
  * It must be kept in mind that we can use the greedy algorithm in this question because of the fact that
  * the sum of any two small coins is not greater than or equal to one of the bigger coins.
  * Ex. [1, 5, 6, 9]	V = 11
  * Then two solutions are: 9 + 1 + 1 and 6 + 5.
  * In this case to find the minimum number of coins we will use dp.
  */

#include<bits/stdc++.h>
using namespace std;

void minCoin(int V) {
    vector<int> deno{ 1, 2, 5, 10, 20, 50, 100, 500, 1000 };
    int n = deno.size(), ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (V >= deno[i]) {
            V -= deno[i];
            ans++;
        }
    }
    cout << "Minimum coins: " << ans;
}
