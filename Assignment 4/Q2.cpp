#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
    int arr[MAX];
    int front, rear;
public:
    CircularQueue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return (front == (rear + 1) % MAX); }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Overflow!" << endl; return; }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        cout << x << " enqueued." << endl;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Underflow!" << endl; return; }
        cout << arr[front] << " dequeued." << endl;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is empty!" << endl;
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty!" << endl; return; }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};
