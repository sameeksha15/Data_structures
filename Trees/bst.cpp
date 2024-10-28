#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this -> data = data;
        this -> right = this ->left = nullptr;
    }
};

Node* createNode(int data) {
    Node *newNode = new Node(data);
    newNode -> data = data;
    newNode -> left = newNode -> right = nullptr;
    return newNode;
}

void inorder(Node *root) {
    if(root != nullptr) {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}

Node* insert(Node *node, int data) {
    if(node == nullptr) return createNode(data);
    if(data < node -> data) node -> left = insert(node -> left, data);
    else node -> right = insert(node -> right, data);
    return node;
}

Node* getInorderSuccessor(Node *node) {
    node = node -> right;
    while(node != nullptr && node -> left != nullptr) {
        node = node -> left;
    }
    return node;
}

Node* deleteNode(Node *node, int target) {
    if(node == nullptr) return node;
    if(node -> data < target) node -> right = deleteNode(node -> right, target);
    else if(node -> data > target) node -> left = deleteNode(node -> left, target);
    else {
        if(node -> left == nullptr) {
            Node *temp = node -> right;
            delete node;
            return temp;
        }
        if(node -> right == nullptr) {
            Node *temp = node -> left;
            delete node;
            return temp;
        }
        Node *successorNode = getInorderSuccessor(node);
        node -> data = successorNode -> data;
        node -> right = deleteNode(node -> right, successorNode -> data);
    } 
    return node;
}

Node *search(Node *root, int target) {
    if(root == nullptr || root -> data == target) {
        return root;
    }
    if(root -> data < target) {
        return search(root -> right, target);
    }
    return search(root -> left, target);
}

int main() {
    Node* root = new Node(50); 
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 90);
    root = insert(root, 10);
    root = insert(root, 60);
  
    (search(root, 19) != NULL)? cout << "Found\n" : cout << "Not Found\n";
    (search(root, 70) != NULL)? cout << "Found\n" : cout << "Not Found\n";
    
    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;
    
    int x = 30;
    root = deleteNode(root, x);
    
    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;
}