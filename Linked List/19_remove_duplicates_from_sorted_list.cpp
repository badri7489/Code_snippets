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
        ListNode* curr = head->next, * prev = head;
        while (curr) {
            if (curr->val == prev->val) {   // If prev and curr have same value, we remove the curr and make curr point to its next.
                prev->next = curr->next;
                delete(curr);   // Freeing memory is imp.
                curr = prev->next;
            } else {    // Else we simply move both the pointers.
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};