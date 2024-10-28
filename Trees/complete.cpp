#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node* right, *left;

    Node(int value) {
        this -> value = value;
        this -> right = nullptr;
        this -> left = nullptr;
    }
};

Node* createNode(int value) {
    Node *newNode = new Node(value);
    newNode -> value = value;
    newNode -> right = newNode -> left = nullptr;
    return newNode;
}

int countNum(Node *root) {
    if(root == NULL) {
        return 0;
    }
    return (1 + countNum(root -> left) + countNum(root -> right));
}
bool checkComplete(Node* root, int index, int numOfNodes) {
    if(root == NULL) return true;
    if(index >= numOfNodes) return false;
    return (checkComplete(root -> left, 2 * index + 1, numOfNodes) && checkComplete(root -> right, 2 * index + 2, numOfNodes));
}

int main() {
    Node *newNode = new Node(1);
    newNode -> left = createNode(2);
    newNode -> right = createNode(3);
    newNode -> left -> left = createNode(4);
    newNode -> left -> right = createNode(5);
    newNode -> right -> left = createNode(6);
    
    int node_count = countNum(newNode);
    int index = 0;
    if(checkComplete(newNode, index, node_count)) {
        cout << "The tree is a complete binary tree\n";
    }
    else {
        cout << "The tree is not a complete binary tree\n";
    }
    return 0;
}

