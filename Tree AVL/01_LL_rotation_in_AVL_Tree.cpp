#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    int height;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), height(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), height(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, int h) : val(x), height(h), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* start = NULL;

int heightTree(TreeNode* root) {
    int lh = root && root->left ? root->left->height : 0;
    int rh = root && root->right ? root->right->height : 0;
    return max(lh, rh) + 1;
}

int balanceFactor(TreeNode* root) {
    int lh = root && root->left ? root->left->height : 0;
    int rh = root && root->right ? root->right->height : 0;
    return lh - rh;
}

TreeNode* llRotation(TreeNode* root) {
    TreeNode* temp = root->left;
    TreeNode* tempR = temp->right;
    temp->right = root;
    root->left = tempR;
    root->height = heightTree(root);
    temp->height = heightTree(temp);
    if (start == root)
        start = root;
    return temp;
}

TreeNode* lrRotation(TreeNode* root) {
    return NULL;
}

TreeNode* rrRotation(TreeNode* root) {
    return NULL;
}

TreeNode* rlRotation(TreeNode* root) {
    return NULL;
}

TreeNode* insert(TreeNode* root, int key) {
    if (!root) {
        TreeNode* temp = new TreeNode(key, 1);
        return temp;
    }
    if (root->val > key)
        root->left = insert(root->left, key);
    else if (root->val < key)
        root->right = insert(root->right, key);
    root->height = heightTree(root);
    if (balanceFactor(root) == 2 && balanceFactor(root->left) == 1)
        return llRotation(root);
    else if (balanceFactor(root) == 2 && balanceFactor(root->left) == -1)
        return lrRotation(root);
    else if (balanceFactor(root) == -2 && balanceFactor(root->right) == -1)
        return rrRotation(root);
    else if (balanceFactor(root) == -2 && balanceFactor(root->right) == 1)
        return rlRotation(root);
    return root;
}

void inOrder(TreeNode* root) {
    if (root) {
        inOrder(root->left);
        cout << root->val << " -> ";
        inOrder(root->right);
    }
}

int main() {
    cout << "Program Started\n";
    start = insert(start, 10);
    insert(start, 5);
    insert(start, 2);
    inOrder(start);
    return 0;
}