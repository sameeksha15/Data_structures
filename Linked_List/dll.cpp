#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;
    
    Node(int data) {
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

class DLL {
    Node *head;

    public:
    DLL() {
        head = NULL;
    }

    void insertAtBeginning(int data) {
        Node *newNode = new Node(data);
        if(!head) {
            head = newNode;
            return;
        }
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node *newNode = new Node(data);
        if(!head) {
            head = newNode;
            return;
        }
        Node *temp = head;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> prev = temp;
    }

    void insertAtPosition(int data, int position) {
        if(position < 1) {
            cout << "Position should be greater than 1";
            return;
        }
        if(position == 1) {
            insertAtBeginning(data);
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
        newNode -> prev = temp;
        if(temp -> next != NULL) {
            temp -> next -> prev = newNode;
        }
        temp -> next = newNode;
    }

    void deleteAtBeginning() {
        if(head == NULL) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node *temp = head;
        head = head -> next;
        if(head) {
            head -> prev = NULL;
        }
        delete temp;
    }

    void deleteAtEnd() {
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
            deleteAtBeginning();
            return;
        }
        Node *temp = head;
        for(int i = 1; i < position && temp; i++) {
            temp = temp -> next;
        }
        if(!temp || temp -> next == NULL) {
            cout<<"Position out of bound";
            return;
        }
        if(temp -> next != NULL) {
            temp -> next -> prev = temp -> prev;
        }
        if(temp -> prev != NULL) {
            temp -> prev -> next = temp -> next;
        }
        delete temp;
    }

    void printForward() {
        if(head == NULL) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp = head;
        cout << "\nForward List: ";
        while (temp != NULL) {
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << "NULL" << endl; 
    }

    void printListReverse() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "The list is empty." << endl;
            return;
        }
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        cout << "\nReverse List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl; 
    }

};

int main() {
    DLL dll;

    dll.insertAtBeginning(30);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(40);
    dll.insertAtPosition(50, 2);
    dll.insertAtPosition(60, 3);
    dll.printForward();
    dll.deleteAtBeginning();
    dll.deleteAtEnd();
    dll.deleteAtPosition(1);
    dll.printForward();
    dll.printListReverse();
    return 0;
}