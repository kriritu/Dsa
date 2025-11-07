#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Inorder traversal function
void inorderTraversal(Node* root) {
    if (root == nullptr) return;

    // Traverse left subtree
    inorderTraversal(root->left);

    // Visit node
    cout << root->data << " ";

    // Traverse right subtree
    inorderTraversal(root->right);
}

int main() {
    // Construct example tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
