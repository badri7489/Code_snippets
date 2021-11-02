#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head)
            return head;
        Node* curr = head;
        while (curr->next && !curr->child)
            curr = curr->next;
        if (!curr->next && !curr->child)
            return head;
        Node* temp = curr->next;
        curr->next = flatten(curr->child);
        curr->next->prev = curr;
        curr->child = NULL;
        while (curr->next)
            curr = curr->next;
        curr->next = temp;
        if (temp)
            temp->prev = curr;
        return head;
    }
};