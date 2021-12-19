// Problem link : https://leetcode.com/problems/insertion-sort-list/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

// Code Samajh lena humko samajh nahi aaya.
ListNode* insertionSortList(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = dummy, * cur = head; 
    while (cur) {
        if ((cur->next) && (cur->next->val < cur->val)) { //Check if there is a next node & it's value is lesser than curr node
            while ((pre->next) && (pre->next->val < cur->next->val)) { // Finding node after which curr->next should be placed 
                pre = pre->next;
            }
            ListNode* temp = pre->next; // storing the next node before which curr->next will be placed
            pre->next = cur->next; // Pointing the node->next to curr->next
            cur->next = cur->next->next; // removing the curr->next from its original position
            pre->next->next = temp; // Pointing the newly placed node to the next node stored previously.
            pre = dummy; // Again pointing prev to the beginning
        } else {
            cur = cur->next; // Else move to the next node
        }
    }
    return dummy->next;
}