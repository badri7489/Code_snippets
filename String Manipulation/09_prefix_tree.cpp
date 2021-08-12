/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

#include<bits/stdc++.h>
using namespace std;

class Trie {
private:
    Trie* next[26] = {};
    bool end_of_word = false;

public:
    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (!node->next[ch - 'a'])
                node->next[ch - 'a'] = new Trie();
            node = node->next[ch - 'a'];
        }
        node->end_of_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (!node->next[ch - 'a'])
                return false;
            node = node->next[ch - 'a'];
        }
        return node->end_of_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            if (!node->next[ch - 'a'])
                return false;
            node = node->next[ch - 'a'];
        }
        return true;
    }
};