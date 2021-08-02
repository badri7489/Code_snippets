/**
  * Stack can be implemented using 2 queues.
  * To implement a stack using 2 queues we first use the queue 1.
  * We push the elements in queue 1.
  * Then we put all the element of queue 2 at the back of queue 1.
  * Then we swap queue 1 and queue 2.
  * This process is carried each time we push an element.
  * Then pop, top and empty are as usual.
  * They are carried on queue 1.
  * Optimised solution can be to implement using only one queue.
  * We push the element in the queue.
  * Then we move q1.size() - 1 elements to the back of the queue.
  * Hence we can say that the last element of the queue is at the front.
  * When we carry this everytime we insert an element in the queue.
  * The elements in the queue is in the order as they are supposed to be in the stack.
  */

#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    /** Get the top element. */
    int top() {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};