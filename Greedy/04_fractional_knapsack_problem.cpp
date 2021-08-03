/**
  * To maximize the profit. We sort in descending order of the to value / weight.
  * Then we need to take the weights one by one.
  * If the weight is less than the knapsack then we take it as a whole otherwise we take part of it.
  * And when a situation comes that we need to take part then the knapsack is full and we should stop.
  * Time complexity is O(n * log(n)) and space is constant.
  */

#include<bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool comparator(Item a, Item b) {
    return ((double)a.value / (double)a.weight) > ((double)b.value / (double)b.weight);
}
double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, comparator);
    int currWeight = 0;
    double profit = 0.0;
    for (int i = 0; i < n; i++) {
        if (currWeight + arr[i].weight <= W) {
            currWeight += arr[i].weight;
            profit += (double)arr[i].value;
        } else {
            int remain = W - currWeight;
            profit += (double)remain * ((double)arr[i].value / (double)arr[i].weight);
            break;
        }
    }
    return profit;
}
