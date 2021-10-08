#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// My Code.
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return NULL;
        ListNode* curr = head;
        while (curr && curr->val == val) {
            head = head->next;
            delete(curr);
            curr = head;
        }
        ListNode* prev = head, * temp;
        while (curr) {
            if (curr->val != val) {
                prev = curr;
                curr = curr->next;
            } else {
                temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete(temp);
            }
        }
        return head;
    }
};

// Improved Code.
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr = head, * prev = NULL;
        while (curr) {
            if (curr->val == val) {
                if (!prev) {
                    head = curr->next;
                    delete(curr);
                    curr = head;
                } else {
                    prev->next = curr->next;
                    delete(curr);
                    curr = prev->next;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};