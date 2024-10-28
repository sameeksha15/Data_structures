#include<bits/stdc++.h>
using namespace std;

class Queue {
    public:
    int front;
    int rear;
    int size;
    unsigned capacity;
    int *array;
};

void print(Queue *queue) {
    for(int i = queue -> front; i <= queue -> rear; i++) {
        cout << queue -> array[i] << " ";
    }
    cout << endl;
}

Queue *createQueue(unsigned capacity) {
    Queue *queue = new Queue();
    queue -> capacity = capacity;
    queue -> front = queue -> rear = -1;
    queue -> size = 0;

    queue -> array = new int[queue -> capacity];
    return queue;
}

bool isFull(Queue *queue) {
    return queue -> rear == queue -> capacity - 1;
}

bool isEmpty(Queue *queue) {
    return queue -> front == -1;
}

void enqueue(Queue *queue, int data) {
    if(isFull(queue)) {
        cout << "Full" << endl;
        return;
    }
    if (isEmpty(queue)) {
        queue -> front ++;
    }
    queue -> rear ++;
    queue -> array[queue -> rear] = data;
}

void dequeue(Queue *queue) {
    if(isEmpty(queue)) {
        cout << "Empty" << endl;
        return;
    }
    int popped = queue -> array[queue -> front];
    cout << "Popped Element: "<< popped << endl;
    queue -> front++;
    if (queue -> front == queue -> rear) {
        queue -> front = queue -> rear = -1;
    }
}

int getFront(Queue *queue) {
    return queue -> array[queue -> front];
}

int getRear(Queue *queue) {
    return queue -> array[queue -> rear];
}

int main() {
    Queue *queue = createQueue(10);
    enqueue(queue, 30);
    enqueue(queue, 20);
    enqueue(queue, 90);
    enqueue(queue, 10);
    print(queue);
    dequeue(queue);
    print(queue);
}