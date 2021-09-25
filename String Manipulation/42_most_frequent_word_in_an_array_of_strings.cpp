#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Class containing the TrieNode.
class TrieNode {
public:
    bool isLeaf;
    int count;
    int firstAppear;
    vector<TrieNode*> child;
    TrieNode() {
        this->count = 0;
        this->firstAppear = 0;
        this->isLeaf = false;
        this->child = vector<TrieNode*>(26, NULL);
    }
};

// Using Trie Data Structure.
string mostFrequentWord(string arr[], int n) {
    TrieNode* root = new TrieNode();
    TrieNode* curr;
    string ans = "";
    int max_count = 0, res_first_appear;
    for (int i = 0; i < n; i++) {
        curr = root;
        for (int j = 0; j < arr[i].length(); j++) {
            if (!curr->child[arr[i][j] - 'a'])
                curr->child[arr[i][j] - 'a'] = new TrieNode();
            curr = curr->child[arr[i][j] - 'a'];
        }
        curr->count++;
        if (curr->count == 1)
            curr->firstAppear = i;
        if (curr->count > max_count || (curr->count == max_count && curr->firstAppear > res_first_appear)) {
            ans = arr[i];
            max_count = curr->count;
            res_first_appear = curr->firstAppear;
        }
    }
    return ans;
}

// Using unordered map, more efficient.
string mostFrequentWord(string arr[], int n) {
    unordered_map<string, int> freq;
    int max_count = 0;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
        max_count = max(max_count, freq[arr[i]]);
    }
    string ans = "";
    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] == max_count) {
            ans = arr[i];
            // Decreasing the frequency of that string so that when we traverse the array and find it again we don't update it.
            // This is because in the meanwhile we might have got someone with same count and we need that word.
            // xejdcj xejdcj lvjpb tmyuiu lvjpb tmyuiu ovoba lvjpb lvjpb fqhyu fqhyu tmyuiu xejdcj tmyuiu fqhyu ovoba xejdcj
            // Here answer is tmyuiu
            // But if we don't update the count we will get answer as xejdcj.
            freq[arr[i]]--;
        }
    }
    return ans;
}