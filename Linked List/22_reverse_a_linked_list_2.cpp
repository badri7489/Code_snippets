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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head)  // Return if head is NULL.
            return head;
        ListNode* curr = head, * prev = NULL;
        while (left > 1) {
            prev = curr;    // Gets the node before left beginning.
            curr = curr->next;  // Gets the left beginning.
            left--;
            right--;
        }
        ListNode* con = prev, * tail = curr, * temp = NULL; // Have the tail
        // Reverse the list in between the range.
        while (right > 0) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            right--;
        }
        if (con)    // If con is, that means left was != 1
            con->next = prev;
        else    // This means left == 1 and we need to reverse the whole list.
            head = prev;
        tail->next = curr;  // After reversing the head becomes the tail so we join it.
        return head;
    }
};