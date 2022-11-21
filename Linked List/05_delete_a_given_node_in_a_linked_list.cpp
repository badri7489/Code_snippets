/**
  * The head of the linked list is not given.
  * We just need to delete the node that is given to us.
  * The solution of this is to copy the value of the node ahead of it and point it to next->next.
  * Then we can free the next node to the given node.
  */

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
  	int val;
  	ListNode* next;
  	ListNode() : val(0), next(nullptr) {}
  	ListNode(int x) : val(x), next(nullptr) {}
  	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void deleteNode(ListNode* node) {
  	node->val = node->next->val;
  	ListNode* temp = node->next;
  	node->next = temp->next;
  	delete temp;
}
