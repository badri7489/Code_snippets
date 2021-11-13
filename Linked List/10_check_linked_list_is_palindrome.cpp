#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* rev(ListNode* head) {
        ListNode* prev = NULL, * curr = head;
        while (curr) {
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode* slow = head, * fast = head;
        // Finding the mid of the linked list.
        // The lesser of the two mids for even length linked list.
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = rev(slow->next);   // Reversing the last side of the linked list
        slow = slow->next;
        fast = head;
        while (slow) {
            if (slow->val != fast->val) // Checking if both the side of the linked list are equal or not.
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};