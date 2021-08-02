/**
  * Naive O(n * m) approach is to traverse both the lists and check which of the two are the same.
  * Better approach would be to use a hashset of nodes.
  * Store all the nodes of list one and traverse the other node and check if the same is present in the hashset.
  * This takes O(n) time and a space of O(n). Considering that it takes constant time to check in the hashset.
  * A much better approach is O(n) time and constant space. We count the number of nodes in each list.
  * Then calculate their difference and move that many steps ahead in the list which is bigger.
  * Now two pointers, one at the head of the smaller and other at the difference of them,
  * steps ahead in the bigger one, start travelling and stop when both point to the same node or both are NULL.
  * This same algorithm can be written in short, if we start by both at their respective heads and then moving until both are equal.
  * If at any point one of the pointers is NULL then that one moves to the head of the other list.
  * What actually happens is that first we travel as many steps as the shorter list,
  * then the pointer of the shorter list goes to point the head of the bigger list.
  * Then it travels the difference of both the lists, that is both the pointers are on the bigger list and
  * the one at the head goes one step and so as the pointer that is anywhere in between.
  * Then this second pointer goes to the head of the smaller list and
  * then they both travel simultaneously and stop when both point to the same node.
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

// Code 1
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* l1 = headA, * l2 = headB;
    int m = 0, n = 0;
    while (l1) {
        m++;
        l1 = l1->next;
    }
    while (l2) {
        n++;
        l2 = l2->next;
    }
    int diff = abs(m - n);
    l1 = (m > n) ? headA : headB;
    l2 = (m > n) ? headB : headA;
    while (diff--) {
        l1 = l1->next;
    }
    while (l1 && l2 && l1 != l2) {
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1;
}

// Code 2
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB)
        return NULL;
    ListNode* a = headA, * b = headB;
    while (a != b) {
        a = (a) ? a->next : headB;
        b = (b) ? b->next : headA;
    }
    return a;
}