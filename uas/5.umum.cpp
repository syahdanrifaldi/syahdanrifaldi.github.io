#include <iostream>

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int key) {
    // Implementation of BST insertion
}

int main() {
    TreeNode* root = nullptr;

    // Insert elements into BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Perform BST operations

    return 0;
}

