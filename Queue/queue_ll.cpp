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

class Queue {
    private:
    Node *front, *rear;

    public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int data) {
        Node *newNode = new Node(data);
        if(isEmpty()) {
            front = rear = newNode;
            return;
        }
        rear -> next = newNode;
        rear = newNode;
    } 

    void dequeue() {
        if(isEmpty()) {
            cout << "Queue is empty"<<endl;
            return;
        }
        Node *toDelete = front;
        front = front -> next;
        if(front == nullptr) rear = nullptr;
        delete toDelete;
    }

    int getFront() {
        if(isEmpty()) {
            cout << "Queue is empty"<<endl;
            return INT_MIN;
        }
        return front -> data;
    }

    int getRear() {
        if(isEmpty()) {
            cout << "Queue is empty"<<endl;
            return INT_MIN;
        }
        return rear -> data;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);

    cout << "Queue Front: " << q.getFront() << endl;
    cout << "Queue Rear: " << q.getRear() << endl;

    q.dequeue();
    q.dequeue();

    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();

    cout << "Queue Front: " << q.getFront() << endl;
    cout << "Queue Rear: " << q.getRear() << endl << endl;

    return 0;
}