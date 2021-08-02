/**
  * We traverse both lists and store the sum in a new list.
  * We start from the beginning of the lists and calculate the sum,
  * calculate the carry and store it in a new node.
  * Then move both lists one step and also the new node created by one list.
  * Then we will do it until both the lists are exhausted and there is no carry present.
  * Time taken will be O(max(size(l1), size(l2))), and space will be O(n).
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ans = new ListNode();
    ListNode* curr = ans;
    int carry = 0, x, y, sumi = 0;
    while (l1 || l2) {
        x = (l1) ? l1->val : 0;
        y = (l2) ? l2->val : 0;
        sumi = x + y + carry;
        carry = sumi / 10;
        curr->next = new ListNode(sumi % 10);
        curr = curr->next;
        if (l1)		l1 = l1->next;
        if (l2)		l2 = l2->next;
    }
    if (carry)		curr->next = new ListNode(carry);
    return ans->next;
}
