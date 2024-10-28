#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this -> data = data;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

int height (Node *node) {
    if(node == nullptr) return 0;
    return 1 + max(height(node -> left), height(node -> right));
}

bool isBalanced(Node *root) {
    int leftHeight = 0;
    int rightHeight = 0;
    if(root == nullptr) return 1;
    leftHeight = height(root -> left);
    rightHeight = height(root -> right);
    if(abs(leftHeight - rightHeight) <= 1 && isBalanced(root -> right) && isBalanced(root -> left)) return 1;
    return 0;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);

    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";
    return 0;
}