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

class Circular_Queue {
    private:
    Node *front, *rear;

    public:
    Circular_Queue() {
        this -> front = this-> rear = nullptr;
    }

    void enqueue(int data) {
        Node *newNode = new Node(data);
        if(front == nullptr) front = newNode;
        else rear -> next = newNode;
        rear = newNode;
        rear -> next = front;
    }

    void dequeue() {
        if(front == nullptr) {
            cout << "List is Empty" << endl;
            return;
        }
        if(front == rear) {
            delete front;
            front = nullptr;
            rear = nullptr;
        } else {
            Node *temp = front;
            front = front -> next;
            rear -> next = front;
            delete temp;
        }
    }

    void display() {
        if(front == nullptr) {
            cout << "List is Empty" << endl;
            return;
        }
        Node *temp = front;
        while(temp -> next != front) {
            cout << temp -> data <<" -> ";
            temp = temp -> next;
        }
        cout << temp -> data << endl;
        return;
    }
};
int main()
{
    Circular_Queue q;
 
    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(6);

    q.display();
 
    q.dequeue();
    q.dequeue();
 
    q.display();
 
    q.enqueue(9);
    q.enqueue(20);
    q.display();
 
    return 0;
}