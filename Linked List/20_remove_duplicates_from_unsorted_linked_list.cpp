#include<iostream>
#include<unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    //Function to remove duplicates from unsorted linked list.
    ListNode* removeDuplicates(ListNode* head) {
        unordered_set<int> st;
        ListNode* curr = head, * prev = NULL;
        while (curr) {
            if (st.find(curr->val) == st.end()) {   // If not in map we store it and move ahead.
                st.insert(curr->val);
                prev = curr;
                curr = curr->next;
            } else {    // Else we delete that node.
                prev->next = curr->next;
                delete(curr);
                curr = prev->next;
            }
        }
        return head;
    }
};