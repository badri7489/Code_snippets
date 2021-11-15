#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    string FirstNonRepeating(string s) {
        queue<char> q;
        vector<int> mp(26, 0);
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n; i++) {
            mp[s[i] - 'a']++;
            q.push(s[i]);
            while (!q.empty() && mp[q.front() - 'a'] > 1)
                q.pop();
            if (q.empty())
                ans += '#';
            else
                ans += q.front();
        }
        return ans;
    }
};

class Solution {
private:
    struct Node {
        char a;
        Node* prev, * next;
    };
    void addNode(Node** head, Node** tail, char x) {
        Node* temp = new Node;
        temp->a = x;
        temp->prev = temp->next = NULL;
        if (!(*head)) {
            *head = *tail = temp;
            return;
        }
        (*tail)->next = temp;
        temp->prev = *tail;
        *tail = temp;
    }
    void removeNode(Node** head, Node** tail, Node* temp) {
        if (!(*head))
            return;
        if (*head == temp)
            *head = (*head)->next;
        if (*tail == temp)
            *tail = (*tail)->prev;
        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = temp->next;
        delete(temp);
    }
public:
    string FirstNonRepeating(string s) {
        Node* inDLL[26];
        bool repeated[26];
        string ans = "";
        Node* head = NULL, * tail = NULL;
        for (int i = 0; i < 26; i++) {
            inDLL[i] = NULL;
            repeated[i] = false;
        }
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (!repeated[c - 'a']) {
                if (!inDLL[c - 'a']) {
                    addNode(&head, &tail, s[i]);
                    inDLL[c - 'a'] = tail;
                } else {
                    removeNode(&head, &tail, inDLL[c - 'a']);
                    inDLL[c - 'a'] = NULL;
                    repeated[c - 'a'] = true;
                }
            }
            if (head)
                ans += head->a;
            else
                ans += "#";
        }
        return ans;
    }
};