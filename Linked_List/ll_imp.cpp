#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

class LinkedList {
    Node *head;

    public:
    LinkedList() {
        head = NULL;
    }

    void insertAtHead(int data) {
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            return;
        }
        newNode -> next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            return;
        }
        Node *temp = head;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }

    void insertAtPosition(int data, int position) {
        if(position < 1) {
            cout << "Position should be greater than 1";
            return;
        }
        if(position == 1) {
            insertAtHead(data);
        }
        Node *newNode = new Node(data);
        Node *temp = head;
        for(int i = 1; i < position - 1 && temp; i++) {
            temp = temp -> next;
        }
        if (!temp) {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }

    void deleteFromBeginning() {
        if(head == NULL) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node *temp = head;
        head = head -> next;
        delete temp;
    }

    void deleteFromEnd() {
        if(head == NULL) {
            cout<<"List is empty"<<endl;
            return;
        }
        if(head -> next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head;
        while(temp -> next -> next != NULL) {
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = NULL;
    }

    void deleteAtPosition(int position) {
        if(head == NULL) {
            cout<<"List is empty"<<endl;
            return;
        }
        if(position == 1) {
            deleteFromBeginning();
            return;
        }
        Node *temp = head;
        for(int i = 1; i < position - 1 && temp; i++) {
            temp = temp -> next;
        }
        if(!temp || temp -> next == NULL) {
            cout<<"Position out of bound";
            return;
        }
        Node *nodeToDelete = temp -> next;
        temp -> next = temp -> next -> next;
        delete nodeToDelete;
    }

    void display() {
        if(!head) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node *temp = head;
        while(temp) {
            cout << temp->data << " -> "; 
            temp = temp -> next;
        }
        cout << "NULL" << endl; 
    }

};

int main() {
    LinkedList ll;

    ll.insertAtHead(90);
    ll.insertAtHead(100);
    ll.insertAtPosition(20, 2);
    ll.insertAtEnd(30);
    ll.insertAtPosition(50, 4);
    ll.display();
    ll.deleteFromBeginning();
    ll.deleteFromEnd();
    ll.deleteAtPosition(2);
    ll.display();
    return 0;
}
