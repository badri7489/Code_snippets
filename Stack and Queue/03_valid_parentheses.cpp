#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (auto& c : s) {
        switch (c) {
            case '(': st.push(')');
                break;
            case '{': st.push('}');
                break;
            case '[': st.push(']');
                break;
            default:
                if (st.empty() || c != st.top())
                    return false;
                st.pop();
        }
    }
    return st.empty();
}