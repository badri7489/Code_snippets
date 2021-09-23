#include<bits/stdc++.h>
using namespace std;

struct trie {
    struct trie* children[26];
    bool isLeaf;
    int counter;
};

struct trie* getNode() {
    struct trie* newNode = new trie;
    for (int i = 0; i < 26; i++)
        newNode->children[i] = NULL;
    newNode->isLeaf = false;
    newNode->counter = 0;
    return newNode;
}

void insertNode(struct trie* root, string key) {
    struct trie* curr = root;
    int index;
    for (int i = 0; i < key.length(); i++) {
        index = key[i] - 'a';
        if (!curr->children[index])
            curr->children[index] = getNode();
        curr = curr->children[index];
        curr->counter++;
    }
    curr->isLeaf = true;
}

bool search(struct trie* root, string key) {
    struct trie* curr = root;
    int index;
    for (int i = 0; i < key.length(); i++) {
        index = key[i] - 'a';
        if (!curr->children[index])
            return false;
        curr = curr->children[index];
    }
    return curr->isLeaf;
}

vector<string> findPrefixes(string arr[], int n) {
    struct trie* root = getNode();
    for (int i = 0; i < n; i++)
        insertNode(root, arr[i]);
    vector<string> ans(n);
    struct trie* curr = root;
    int index;
    for (int i = 0; i < n; i++) {
        curr = root;
        for (int j = 0; j < arr[i].length(); j++) {
            index = arr[i][j] - 'a';
            if (curr->children[index] && curr->children[index]->counter == 1) {
                ans[i] = arr[i].substr(0, j + 1);
                break;
            }
            curr = curr->children[index];
        }
    }
    return ans;
}

int main() {
    int n;
    fstream file;
    file.open("15_test_cases.txt");
    file >> n;
    while (n != -1) {
        string arr[n];
        int i = 0;
        while (i < n)
            file >> arr[i++];
        vector<string> ans = findPrefixes(arr, n);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
        file >> n;
    }
    return 0;
}