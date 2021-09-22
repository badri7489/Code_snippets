#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

void sortList(ListNode** head) {
    ListNode* temp = *head;
    if (!temp || !temp->next)
        return;
    ListNode* curr = temp->next, * prev = temp;
    while (curr) {
        if (curr->val >= 0) {
            prev = curr;
            curr = curr->next;
        } else {
            prev->next = curr->next;
            curr->next = temp;
            temp = curr;
            curr = prev->next;
        }
    }
    *head = temp;
}