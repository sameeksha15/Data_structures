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

class Circular_LL {
    private:
    Node *head;

    public:
    Circular_LL() {
        this -> head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node *newNode = new Node(data);
        if(!head) {
            head = newNode;
            head -> next = head;
            return;
        }
        Node *temp = head;
        while(temp -> next != head) {
            temp = temp -> next;
        }
        newNode -> next = head;
        temp -> next = newNode;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node *newNode = new Node(data);
        if(!head) {
            head = newNode;
            head -> next = head;
            return;
        }
        Node *temp = head;
        while(temp -> next != head) {
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> next = head;
    }


    void insertAtPosition(int data, int position) {
        if(position < 1) {
            cout << "Position should be greater than 1";
            return;
        }
        if(position == 1) {
            insertAtBeginning(data);
            return;
        }
        Node *newNode = new Node(data);
        Node *temp = head;
        for(int i = 1; i < position - 1 && temp -> next != head; i++) {
            temp = temp -> next;
        }
        if(temp -> next == head && position != 2) {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }

    void deleteAtBeginning() {
        if(!head) {
            cout<<"List is empty"<<endl;
            return;
        }
        if(head -> next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while(temp -> next != head) {
            temp = temp -> next;
        }
        Node *nodeToDelete = head;
        temp -> next = head -> next;
        head = head -> next;
        delete nodeToDelete;
    }

    void deleteFromEnd() {
        if(!head) {
            cout<<"List is empty"<<endl;
            return;
        }
        if(head -> next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while(temp -> next -> next != head) {
            temp = temp -> next;
        }
        Node *nodeToDelete = temp -> next;
        temp -> next = head;
        delete nodeToDelete;
    }

    void deleteAtPosition(int position) {
        if(!head) {
            cout<<"List is empty"<<endl;
            return;
        }
        if(position < 1) {
            cout << "Position should be greater than 1";
            return;
        }
        if(position == 1) {
            deleteAtBeginning();
            return;
        }
        Node *temp = head;
        for(int i = 1; i < position - 1 && temp -> next != head; i++) {
            temp = temp -> next;
        }
        if (temp -> next == head || temp -> next == nullptr) {
            cout << "Position out of range." << endl;
            return;
        }
        if(temp -> next -> next == head) {
            deleteFromEnd();
            return;
        }
        Node *nodeToDelete = temp -> next;
        temp -> next = temp -> next -> next;
        delete nodeToDelete;
    }

    void display() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    Circular_LL cll;

    cll.insertAtBeginning(90);   
    cll.insertAtBeginning(100);   
    cll.insertAtPosition(20, 2);
    cll.insertAtEnd(30);    
    cll.insertAtPosition(50, 4); 
    cll.display();               
    cll.deleteAtBeginning();     
    cll.deleteFromEnd();        
    cll.deleteAtPosition(2);
    cll.display();               

    return 0;
}