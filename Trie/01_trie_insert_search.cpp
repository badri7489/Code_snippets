#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode* getNode(void) {
    struct TrieNode* pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

//Function to insert string into TRIE.
void insert(struct TrieNode* root, string key) {
    struct TrieNode* curr = root;
    int index;
    for (int i = 0; i < key.length(); i++) {
        index = key[i] - 'a';
        if (!curr->children[index])
            curr->children[index] = getNode();
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode* root, string key) {
    struct TrieNode* curr = root;
    int index;
    for (int i = 0; i < key.length(); i++) {
        index = key[i] - 'a';
        if (!curr->children[index])
            return false;
        curr = curr->children[index];
    }
    return curr->isEndOfWord;
}