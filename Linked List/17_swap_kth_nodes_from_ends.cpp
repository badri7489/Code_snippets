#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

ListNode* swapkthNode(ListNode* head, int n, int k) {
    if (k > n || 2 * k - 1 == n)
        return head;
    ListNode* curr1 = head, * curr2 = head, * prev1 = NULL, * prev2 = NULL;
    for (int i = 1; i < k; i++) {
        prev1 = curr1;
        curr1 = curr1->next;
    }
    for (int i = 1; i < n - k + 1; i++) {
        prev2 = curr2;
        curr2 = curr2->next;
    }
    if (prev1)
        prev1->next = curr2;
    if (prev2)
        prev2->next = curr1;
    ListNode* temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
    if (k == 1)
        return curr2;
    if (k == n)
        return curr1;
    return head;
}