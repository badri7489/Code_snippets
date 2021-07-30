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
    ListNode* temp = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}
