/**
  * To check if the parentheses are balanced or not.
  * We use a stack to implement this.
  * If its an opening bracket then we push its corresponding closing bracket.
  * Now when we find a closing bracket in the string, we check if the top is same as the current closing bracket or not.
  * If this is the case then we continue else we return a false.
  * When the string ends, if we find that the stack is empty then we return true else false.
  * Time complexity is O(n).
  * Space complexity is O(n).
  */

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