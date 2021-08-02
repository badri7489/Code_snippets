/**
  * Queue is implemented using two stack.
  * We take a input and an output stack.
  * When we get an element to push, we push it into the input stack.
  * But when we get a pop/top operation, we check if the output stack is empty or not.
  * If the output stack is not empty then we simply return the top of the output stack.
  * Else we take all the elements of the input stack and put it into the output stack.
  * Now we return the top of the output stack.
  * Since we take out from input stack and put it in output stack, we have the output stack in order of a queue.
  * So output stack will have all the elements that are supposed to be popped or peeked.
  * Now we have two seperate channels for output and for input.
  * This helps in multithreading.
  * The time complexity is O(1) for push, O(n) for pop and top.
  * But we can say that amortized time complexity for pop and top is O(1).
  * Because we have to move the elements once or twice for a set of pop or top operations.
  */

#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> input;
    stack<int> output;
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = peek();
        output.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }
};