/**
  * Naive approach would be to count the number of nodes in first traversal and
  * then delete the (N - x)th node from the beginning.
  * This can be optimised to a single pass.
  * We first take a pointer ‘fast’ and move it x times.
  * Then we take another pointer ‘slow’ pointing to the head.
  * If we find that after x steps the fast pointer’s next one is NULL then we have to delete the head.
  * Else we need to move both fast and slow by one step till fast->next != NULL.
  * Then we need to delete the slow->next.
  * Here it will take a single pass, as fast is only travelling once throughout the list.
  * Time complexity will be O(n).
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slow = head, * fast = head;
    for (int i = 0; i < n; i++)
        fast = fast->next;
    if (!fast)
        return head->next;
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete(temp);
    return head;
}
