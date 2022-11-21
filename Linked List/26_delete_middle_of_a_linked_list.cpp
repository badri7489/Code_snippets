/**
  * First find the middle of a linked list using two pointer approach.
  * Using the slow and fast pointer approach also known as tortoise approach.
  * Then delete the slow pointer which will be pointing towards the mid.
  * https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
  */

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next)
            return NULL;
        ListNode* slow, *fast, *prev;
        slow = fast = prev = head;
        while (fast && fast->next) {
            prev = slow;    // Keeping the previous pointer, so that we can join after deletion.
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        slow->next = NULL;  // Instead we can free that pointer also.
        return head;
    }
};