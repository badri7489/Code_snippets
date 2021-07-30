#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode* bottom;
    ListNode() : val(0), next(nullptr), bottom(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), bottom(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    ListNode(int x, ListNode* next, ListNode* bottom) : val(x), next(next), bottom(bottom) {}
};

ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    ListNode* temp = new ListNode(0);
    ListNode* res = temp;
    while (a && b) {
        if (a->val < b->val) {
            temp->bottom = a;
            a = a->bottom;
        } else {
            temp->bottom = b;
            b = b->bottom;
        }
        temp = temp->bottom;
    }
    if (a)
        temp->bottom = a;
    else
        temp->bottom = b;
    return res->bottom;
}

ListNode* flatten(ListNode* root) {
    if (!root || !root->next)
        return root;

    root->next = flatten(root->next);
    root = mergeTwoLists(root, root->next);
    return root;
}
