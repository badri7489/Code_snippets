#include<iostream>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* prev = head, * curr = head->next, * temp = head;
        while (curr) {
            if (prev->val != curr->val) {   // If two value are not equal we move ahead.
                prev = curr;
                curr = curr->next;
            } else {
                while (curr && prev->val == curr->val) {    // Till all the values are same, we delete them
                    prev->next = curr->next;
                    delete(curr);
                    curr = prev->next;
                }
                // We also need to remove the element itself, all its occurence.
                if (prev == head) { // If it is the head, then we need to change the head
                    delete(prev);
                    prev = head = curr;
                    if (!curr)  // When all the elements are same, we reach the end(null).
                        return head;
                    curr = curr->next;
                } else {
                    temp = head;    // We get the element just before prev.
                    while (temp->next != prev)
                        temp = temp->next;
                    temp->next = curr;  // We join it with current 
                    delete(prev);   // We delete prev.
                    prev = temp;
                }
            }
        }
        return head;
    }
};