#include<iostream>
#include<string>
#include<queue>
using namespace std;

string frequencySort(string s) {
    int arr[128] = { 0 };
    for (char& c : s)
        arr[c]++;   // Storing the frequency of all the characters,
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;  // Priority Queue to store the freq and characters.
    for (int i = 0; i < 128; i++) {
        if (arr[i])
            pq.push({ arr[i], (char)i });
    }
    char c;
    int n;
    string ans = "";
    while (!pq.empty()) {
        n = pq.top().first;
        c = pq.top().second;
        pq.pop();
        while (n > 0) {
            ans += c;
            n--;
        }
    }
    return ans;
}