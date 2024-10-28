#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node *left, *right;

    Node(int value) {
        this -> value = value;
        this -> right = this -> right = nullptr;
    }
};

Node *createNode(int data) {
    Node *newNode = new Node(data);
    newNode -> left =  newNode -> right = nullptr;
    return newNode;
}

void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root -> left);
    printf("%d ", root -> value);
    inorder(root -> right);
}

void preorder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root -> value);
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(Node *root) {
    if (root == NULL) return;
    postorder(root -> left);
    postorder(root -> right);
    printf("%d ", root -> value);
}

void levelOrder(Node *root) {
    if(!root) return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        Node *curr = q.front();
        q.pop();
        cout << curr -> value << " ";
        if(curr -> left) q.push(curr -> left);
        if(curr -> right) q.push(curr -> right);
    }
}

int main() {
    struct Node* root = createNode(40);  
    root->left = createNode(30);  
    root->right = createNode(50);  
    root->left->left = createNode(25);  
    root->left->right = createNode(35);  
    root->left->left->left = createNode(15);  
    root->left->left->right = createNode(28);  
    root->right->left = createNode(45);  
    root->right->right = createNode(60);  
    root->right->right->left = createNode(55);  
    root->right->right->right = createNode(70);    
    cout << "\nInorder traverasl: ";
    inorder(root);
    cout << endl;

    cout << "\nPreorder traverasl: ";
    preorder(root);
    cout << endl;

    cout << "\nPostorder traverasl: ";
    postorder(root);
    cout << endl;

    cout << "\nLevel order traverasl: ";
    levelOrder(root);
    cout << endl;
}