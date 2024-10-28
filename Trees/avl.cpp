#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *right, *left;
    int height;
    Node(int data) {
        this -> data = data;
        this -> right = this -> left = nullptr;
        this -> height = 1;
    }
};

class AVLTree {
    private:
    Node *root;
    int height(Node *node) {
        if(node == nullptr) return 0;
        return node -> height;
    }

    int balanceFactor(Node *node) {
        if(node == nullptr) return 0;
        return height(node -> left) - height(node -> right);
    }

    Node *rightRotate(Node *subTreeRoot) {
        Node *newRoot = subTreeRoot -> left;
        Node *newRootChild = newRoot -> right;

        newRoot -> right = subTreeRoot;
        subTreeRoot -> left = newRootChild;

        subTreeRoot -> height = max(height(subTreeRoot -> left), height(subTreeRoot -> right)) + 1;
        newRoot -> height = max(height(newRoot -> left), height(newRoot -> right)) + 1;
        return newRoot;
    }

    Node *leftRotate(Node *subTreeRoot) {
        Node *newRoot = subTreeRoot -> right;
        Node *newRootChild = newRoot -> left;

        newRoot -> left = subTreeRoot;
        subTreeRoot -> right = newRootChild;

        subTreeRoot -> height = max(height(subTreeRoot -> right), height(subTreeRoot -> left)) + 1;
        newRoot -> height = max(height(newRoot -> right), height(newRoot -> left)) + 1;

        return newRoot;
    }

    Node *insert(Node *node, int data) {
        if(node == nullptr) return new Node(data);
        
        if(data < node -> data) node -> left = insert(node -> left, data);
        else  if(data > node -> data) node -> right = insert(node -> right, data);
        else return node;

        node -> height = 1 + max(height(node -> right), height(node -> left));
        int balance = balanceFactor(node);

        if(balance > 1 && data < node -> left -> data) return rightRotate(node);
        if(balance < -1 && data > node -> right -> data) return leftRotate(node);

        if(balance > 1 && data > node -> left -> data) {
            node -> left = leftRotate(node -> left);
            return rightRotate(node);
        }

        if(balance < -1 && data < node -> right -> data) {
            node -> right = rightRotate(node -> right);
            return leftRotate(node);
        }

        return node;
    }

    Node *getInorderSuccessor(Node *current) {
        current = current -> right;
        while(current != nullptr && current -> left != nullptr) {
            current = current -> left;
        }
        return current;
    }

    Node *deleteNode(Node *node, int data) {
        if(node == nullptr) return node;

        if(data < node -> data) node -> left = deleteNode(node -> left, data);
        else if(data > node -> data) node -> right = deleteNode(node -> right, data);
        else {
            if((node -> left == nullptr) || (node -> right == nullptr)) {
                Node *temp = node -> left ? node -> left : node -> right;
                if(temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else *node = *temp;
                delete temp;
            } else {
                Node *temp = getInorderSuccessor(node);
                node -> data = temp -> data;
                node -> right = deleteNode(node -> right, temp -> data);
            }
            
        }
        if(node == nullptr) return node;
        node -> height = 1 + max(height(node -> left), height(node -> right));
        int balance = balanceFactor(node);
        if(balance > 1 && data < node -> left -> data) return rightRotate(node);
        if(balance < -1 && data > node -> right -> data) return leftRotate(node);

        if(balance > 1 && data > node -> left -> data) {
            node -> left = leftRotate(node -> left);
            return rightRotate(node);
        }

        if(balance < -1 && data < node -> right -> data) {
            node -> right = rightRotate(node -> right);
            return leftRotate(node);
        }

        return node;    
    }

    bool search(Node *root, int target) {
        if(root == nullptr) return false;
        if(root -> data == target) return true;
        if(target < root -> data) return search(root -> left, target);
        return search(root -> right, target);
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root -> left);
            cout << root -> data << " ";
            inorder(root -> right);
        }
    }

    public:
    AVLTree() {
        root = nullptr;
    }
    void insert(int data) { root = insert(root, data); }

    void remove(int data) { root = deleteNode(root, data); }

    bool search(int data) { return search(root, data); }

    void printTree() {
        inorder(root);
        cout << endl;
    }  
};

int main() {
    AVLTree avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    cout << "Inorder traversal of the AVL tree: ";
    avl.printTree();

    avl.remove(30);
    cout << "Inorder traversal after removing 30: ";
    avl.printTree();

    cout << "Is 25 in the tree? " << (avl.search(25) ? "Yes" : "No") << endl;
    cout << "Is 30 in the tree? " << (avl.search(30) ? "Yes" : "No") << endl;

    return 0;
}