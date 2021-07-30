/** Brute Force is to store all the nodes in a hashset and check whether a node is repeating or not,
  * if yes then loop is present and starts at the repeating node.
  * Optimal solution in O(1) space is to take slow(moves 1 step) and fast(move 2 step) and check where they meet.
  * Then take fast to head and make it move one step and
  * slow also starts moving one step and the node at which they meet is the node where the loop begins.
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

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head, * fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (!fast || !fast->next)
        return NULL;
    fast = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
