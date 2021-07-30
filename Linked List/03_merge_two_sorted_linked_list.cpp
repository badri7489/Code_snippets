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
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    ListNode* head;
    if (l1->val < l2->val) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }
    ListNode* curr = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    curr->next = (l1) ? l1 : l2;
    return head;
}

// Recursive Code
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2)
        return NULL;
    else if (!l1)
        return l2;
    else if (!l2)
        return l1;
    ListNode* head;
    if (l1->val >= l2->val) {
        l2->next = mergeTwoLists(l1, l2->next);
        head = l2;
    } else {
        l1->next = mergeTwoLists(l1->next, l2);
        head = l1;
    }
    return head;
}
