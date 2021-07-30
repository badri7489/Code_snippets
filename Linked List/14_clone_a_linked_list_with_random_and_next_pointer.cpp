/** Brute force would be to store each node and its corresponding random node.
  * Then we create a deep copy of the linked list without initializing the random pointers.
  * For the random pointers we take that hashmap into consideration and start pointing randoms with its help.
  * This takes O(n) time and O(n) space. Hence we can optimize it to better it.
  * We create a new node for each node in the list and place the copy one after the original.
  * This will result in a single linked list.
  * Then we join the random pointers of the new with the help of the original list.
  * Then we break them free. And we will have both the list separately.
  * Hence we made a deep copy without using extra space and with time complexity of O(n).
  */

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode* random;
    ListNode() : val(0), next(nullptr), random(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), random(nullptr) {}
    ListNode(int x, ListNode* next, ListNode* random) : val(x), next(next), random(nullptr) {}
};

ListNode* copyRandomList(ListNode* head) {
    ListNode* iter = head, * front = head;
    while (iter) {
        front = iter->next;
        ListNode* deep = new ListNode(iter->val);
        iter->next = deep;
        deep->next = front;
        iter = front;
    }
    iter = head;
    while (iter) {
        if (iter->random)
            iter->next->random = iter->random->next;
        iter = iter->next->next;
    }
    iter = head;
    ListNode* newHead = new ListNode(0);
    ListNode* copy = newHead;

    while (iter) {
        front = iter->next->next;
        copy->next = iter->next;
        iter->next = front;
        copy = copy->next;
        iter = front;
    }
    return newHead->next;
}
