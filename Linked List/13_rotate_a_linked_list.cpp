/**
  * Brute force will be to go to the last node and change it to the head k times.
  * This will be O(n * k) time complexity.
  * Optimal approach would be to directly make the kth node from the end as the head.
  * If the value of k > n(size of list) then we need to mod it with n because after every n rotation the list is the same as before.
  * Then we change the head to the point where we find the kth node from the end and make the node before it NULL.
  * This is an O(n) time complexity algorithm.
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

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0)
        return head;
    ListNode* curr = head;
    int count = 1;
    while (curr->next && ++count)
        curr = curr->next;
    curr->next = head;
    k = k % count;
    k = count - k;
    while (k--)
        curr = curr->next;
    head = curr->next;
    curr->next = NULL;
    return head;
}
