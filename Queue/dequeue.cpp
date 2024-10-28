#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next, *prev;

    Node(int data) {
        this -> data = data;
        this -> next = this -> prev = nullptr;
    }
};

class Dequeue {
    Node *front, *rear;
    int size;

    public:
    Dequeue() {
        front = rear = nullptr;
        this -> size = 0;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void insertFront(int data) {
        Node *newNode = new Node(data);
        if(front == NULL) {
            rear = front = newNode;
            size++;
            return;
        }
        newNode -> next = front;
        front -> prev = newNode;
        front = newNode;
        size++;
    }

    void insertRear(int data) {
        Node *newNode = new Node(data);
        if(rear == nullptr) {
            front = rear = newNode;
            size++;
            return;
        }
        newNode -> prev = rear;
        rear -> next = newNode;
        rear = newNode;
        size++;
    }

    void deleteFront() {
        if(isEmpty()) {
            cout << "Queue is empty"<<endl;
            return;
        }
        if(front -> next == nullptr) {
            delete front;
            front = rear = nullptr;
            return;
        }
        Node *toDelete = front;
        front = front -> next;
        front -> prev = nullptr;
        delete toDelete;
        size--;
    }

    void deleteRear() {
        if(isEmpty()) {
            cout << "Queue is empty"<<endl;
            return;
        }
        if(rear -> prev == nullptr) {
            delete rear;
            front = rear = nullptr;
            return;
        }
        Node *toDelete = rear;
        rear = rear -> prev;
        rear -> next = nullptr;
        delete toDelete;
        size--;
    }

    int getFront()
    {
        if (isEmpty()) return -1;
        return front -> data;
    }
   
    int getRear()
    {
        if (isEmpty()) return -1;
        return rear -> data;
    }

    void erase()
    {
        rear = NULL;
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        size = 0;
    }

    int getSize() {
        return size;
    }
};

int main()
{
    Dequeue dq;
    cout << "Insert element '5' at rear end\n";
    dq.insertRear(5);
 
    cout << "Insert element '10' at rear end\n";
    dq.insertRear(10);
 
    cout << "Rear end element: " << dq.getRear() << endl;
 
    dq.deleteRear();
    cout << "After deleting rear element new rear" << " is: " << dq.getRear() << endl;
 
    cout << "Inserting element '15' at front end \n";
    dq.insertFront(15);
 
    cout << "Front end element: " << dq.getFront() << endl;
 
    cout << "Number of elements in Deque: " << dq.getSize() << endl;
 
    dq.deleteFront();
    cout << "After deleting front element new " << "front is: " << dq.getFront() << endl;
 
    return 0;
}