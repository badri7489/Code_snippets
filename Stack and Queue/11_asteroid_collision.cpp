#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> asteroidCollision(vector<int>& arr) {
    vector<int> ans;
    stack<int> st;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            st.push(i);
        else {
            while (!st.empty() && abs(arr[i]) > arr[st.top()]) {
                arr[st.top()] = 0;
                st.pop();
            }
            if (!st.empty()) {
                if (abs(arr[i]) == arr[st.top()])
                    arr[st.top()] = 0;
                arr[i] = 0;
            }
        }
    }
    for (int i : arr) {
        if (i)
            ans.push_back(i);
    }
    return ans;
}

vector<int> asteroidCollision(vector<int>& arr) {
    stack<int> st;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            st.push(arr[i]);
        else {
            while (!st.empty() && st.top() > 0 && abs(arr[i]) > st.top())
                st.pop();
            if (!st.empty() && st.top() == abs(arr[i]))
                st.pop();
            else {
                if (st.empty() || st.top() < 0)
                    st.push(arr[i]);
            }
        }
    }
    vector<int> ans(st.size());
    for (int i = st.size() - 1; i >= 0; i--) {
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}