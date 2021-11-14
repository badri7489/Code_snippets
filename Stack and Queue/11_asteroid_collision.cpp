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

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> stk;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (stk.empty() || arr[i] > 0)  // If element is positive we simply add it to the stack.
                stk.push(arr[i]);
            else {
                while (true) {
                    int top = stk.top();
                    if (top < 0) {  // If top is also negative we simply push the element and break.
                        stk.push(arr[i]);
                        break;
                    } else if (top == -arr[i]) {    // If both are of same size, we pop and break.
                        stk.pop();
                        break;
                    } else if (top > -arr[i]) {     // If top is more then the present one breaks.
                        break;
                    } else {    // If the present asteroid is bigger then it breaks the present and also the rest.
                        stk.pop();
                        if (stk.empty()) {  // If no more asteroids left, we take this asteroid and break.
                            stk.push(arr[i]);
                            break;
                        }
                    }
                }
            }
        }
        vector<int> ans(stk.size());
        for (int i = stk.size() - 1; i >= 0; i--) {
            ans[i] = stk.top();
            stk.pop();
        }
        return ans;
    }
};