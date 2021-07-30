/** Naive approach would be to take a hashset and store one by one the nodes of the linked list
  * and if there is a node which is already present in the hashset then we can say that a cycle is present in the linked list.
  * Time will be O(n) and space is O(n).
  * Optimal solution will be to use the fast and slow pointers.
  * Both will start from the head, slow will move by one step and fast will move by two steps.
  * At a point when both the pointers will point to the same node, we can say that there is a cycle present.
  * If while travelling through the list, fast or fast -> next points to null then we can stop looping and
  * say that there is no cycle present in the linked list.
  * Time taken will be O(n) and O(1) space.
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

bool hasCycle(ListNode* head) {
    ListNode* slow = head, * fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}