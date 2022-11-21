#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Iterative Code
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next)
        return head;
    ListNode* prev = head, * curr = head->next;
    head = head->next->next;
    prev->next = NULL;
    while (head) {
        curr->next = prev;
        prev = curr;
        curr = head;
        head = head->next;
    }
    curr->next = prev;
    return curr;
}

// Recursive Code
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next)
        return head;
    ListNode* temp = reverseList(head->next); // Temp goes to the end and contains the head, or the last node.
    head->next->next = head; // Circles the linked list.
    head->next = NULL;  // Then removes the circle.
    return temp; // Returns the head of the linked list in all the function calls.
}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL, * curr = head;
    while (curr) {
        head = head->next;
        curr->next = prev;
        prev = curr;
        curr = head;
    }
    return prev;
}

// Taking the current and the previous pointer.
ListNode* helper(ListNode* curr, ListNode* prev) {
    if (!curr)
        return prev;
    ListNode* temp = helper(curr->next, curr);  // Temp goes to the end and contains the head, or the last node.
    curr->next = prev;
    return temp; // Returns the head of the linked list in all the function calls.
}
ListNode* reverseList(ListNode* head) {
    return helper(head, NULL);
}
