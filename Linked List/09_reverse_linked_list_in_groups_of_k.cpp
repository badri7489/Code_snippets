/** We have to reverse the linked list on groups of k and if the last group is less than k then we must leave it as it is.
  * We take a dummy node and point it to the head of the linked list.
  * Then for the first k elements we have to reverse the links of k - 1 elements.
  * Then this process will continue until the elements left are less than k.
  * This will take about O(n) time and a constant space.
  * A recursive solution is to call a reverse function on every group of k.
  * If we get k nodes then we will call the reverse function , else we will return the head.
  * The reverse function will reverse the k nodes and we will join it with the head of the present recursion.
  * Then we will call the function again on the rest of the nodes in the linked list.
  * This will take O(n) time and a space of O(n/k).
  * The space will be taken by the recursion stack.
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

// Iterative Code 
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1)	return head;
    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode* curr = dummy, * prev = dummy, * nex = dummy;
    int count = 0;
    while (curr->next) {
        count++;
        curr = curr->next;
    }
    while (count >= k) {
        curr = prev->next;
        nex = curr->next;
        for (int i = 1; i < k; i++) {
            curr->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
            nex = curr->next;
        }
        prev = curr;
        count -= k;
    }
    return dummy->next;
}

// Recursive Code 
ListNode* reverse(ListNode* first, ListNode* last) {
    ListNode* prev = last;
    while (first != last) {
        ListNode* temp = first->next;
        first->next = prev;
        prev = first;
        first = temp;
    }
    return prev;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* node = head;
    for (int i = 0; i < k; i++) {
        if (!node)
            return head;
        node = node->next;
    }
    ListNode* new_head = reverse(head, node);
    head->next = reverseKGroup(node, k);
    return new_head;
}
