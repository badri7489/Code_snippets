#include<iostream>
#include<queue>
#define ll long long
using namespace std;

ll minCost(ll arr[], ll n) {
    priority_queue<ll, vector<ll>, greater<ll>> pq(arr, arr + n);
    // for (ll i = 0; i < n; i++)
    //     pq.push(arr[i]);
    ll cost = 0, min1, min2;
    while (pq.size() > 1) {
        min1 = pq.top();
        pq.pop();
        min2 = pq.top();
        pq.pop();
        cost += min1 + min2;
        pq.push(min1 + min2);
    }
    return cost;
}