#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
    if (!head || !head->next)
        return true;
    ListNode* slow = head, * fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow->next->next) {
        ListNode* prev = slow->next, * curr = prev->next, * temp = curr->next;
        prev->next = NULL;
        while (temp) {
            curr->next = prev;
            prev = curr;
            curr = temp;
            temp = temp->next;
        }
        curr->next = prev;
        slow->next = curr;
    }
    ListNode* ptr1 = head, * ptr2 = slow->next;
    while (ptr2) {
        if (ptr1->val != ptr2->val)
            return false;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;
}
