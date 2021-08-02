/**
  * Min stack can be implemented by using extra space and without extra space also.
  * When we use extra space, we take a supporting stack, which contains the minimum of the stack at all times.
  * It contains all the minimum elements which is checked at each push step.
  * When we pop an element from the stack, we check if that is the same as the top of the min stack.
  * If yes then we pop it out of the min stack also, else we only pop it from the stack and not from the min stack.
  * For top it is same. For the min element we just get the top of the min stack.
  * Without extra space implementation is to put a flag element in the stack.
  * We take a global min variable. When we are pushing element, we check if the stack is empty or not.
  * If the stack is empty then we push it and update min to that element.
  * If the stack is not empty then two cases arise.
  * First case is when the element we are pushing is greater than the element in the stack, then we push it normally.
  * Second case is when the element we are pushing is lesser than the element in the stack, then we push (2 * val - min).
  * And min will be updated to val.
  * This is the corrupted or the flag data.
  * This is the one which will be only element in the stack which will be lesser than the min.
  * Hence when we pop elements we will get to know that the min is eliminated or not.
  * If yes then we update the min = 2 * min - stk.top().
  * It's just a little bit of tricky maths.
  * When we are getting the top, we check if the top is less than min or not.
  * If it is less than the top then we return the min else we return the top of the stack.
  * And lastly getting the min is simple, just return the min variable.
  */

#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> mini;
    MinStack() {}

    void push(int val) {
        stk.push(val);
        if (mini.empty() || val <= mini.top())
            mini.push(val);
    }

    void pop() {
        if (mini.top() == stk.top())
            mini.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return mini.top();
    }
};

class MinStack {
public:
    /** initialize your data structure here. */
    stack<long long> stk;
    long long mini;
    MinStack() {}

    void push(long long val) {
        if (stk.empty()) {
            stk.push(val);
            mini = val;
        } else {
            if (val >= mini)
                stk.push(val);
            else {
                long long x = 2 * (long long)val - mini;
                stk.push(x);
                mini = val;
            }
        }
    }

    void pop() {
        if (stk.top() < mini)
            mini = 2 * mini - stk.top();
        stk.pop();
    }

    int top() {
        return (stk.top() < mini) ? mini : stk.top();
    }

    int getMin() {
        return mini;
    }
};