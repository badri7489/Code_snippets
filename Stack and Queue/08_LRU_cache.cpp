#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class node {    // Doubly ended Linked List
    public:
        int key, val;
        node* next;
        node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    // Head and tail, with dummy values.
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int cap;    // Maximum size of the cache.
    unordered_map<int, node*> m;    // Data inserted into the cache and its address in the doublu linked list.

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Add a node just after the head node.
    void addNode(node* newNode) {
        node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    // Delete a node just before a tail.
    void deleteNode(node* delNode) {
        node* delPrev = delNode->prev;
        node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node* resNode = m[key_];    // Getting the node in the list from the key.
            int res = resNode->val;     // Storing the value.
            m.erase(key_);              // Deleting from the hashmap.
            deleteNode(resNode);        // Deleting node as it has been used and it is not the LRU.
            addNode(resNode);           // Adding it after head as it has been used recently.
            m[key_] = head->next;       // Updating hashmap since the node is changed.
            return res;
        }
        return -1;  // If the element is not present in the cache then return -1.
    }

    void put(int key_, int value) {
        if (m.find(key_) != m.end()) {      // If the node is present in the map then we delete it first and add again.
            node* existingNode = m[key_];   // This changes is priority and moves it at the top.
            m.erase(key_);
            deleteNode(existingNode);
        }
        if (m.size() == cap) {      // When capacity is full, we erase the LRU, that is the node just before the tail.
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key_, value)); // Simply adding a node.
        m[key_] = head->next;
    }
};