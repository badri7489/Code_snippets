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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* odd = head, * even = head->next, * evenHead = even;
        while (even && even->next) {
            odd->next = odd->next->next;    // Joining odd pointers
            even->next = even->next->next;  // Joining even pointers
            odd = odd->next;    // Moving odd pointer
            even = even->next;  // Moving even pointer
        }
        odd->next = evenHead;   // Joining the end of odd to the head of even pointer
        return head;
    }
};