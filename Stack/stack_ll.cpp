#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        this -> next = nullptr;
    }
};

class Stack {
    private:
    Node *head;

    public:
    Stack() {
        this -> head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void push(int data) {
        Node *newNode = new Node(data);
        if(!newNode) {
            cout << "Stack Overflow"<<endl;
            return;
        }
        newNode -> next = head;
        head = newNode;
    }

    void pop() {
        if(isEmpty()) {
            cout << "Stack Underflow" <<endl;
            return;
        }
        Node *temp = head;
        head = head -> next;
        delete temp;
    }

    int peek() {
        if(isEmpty()) {
            cout << "Stack Underflow" <<endl;
            return INT_MIN; 
        } 
        return head -> data;
    }
};

int main() {
    Stack st;

    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);

    cout << "Top element is " << st.peek() << endl;

    cout << "Removing two elements..." << endl;
    st.pop();
    st.pop();

    cout << "Top element is " << st.peek() << endl;
    return 0;
}
