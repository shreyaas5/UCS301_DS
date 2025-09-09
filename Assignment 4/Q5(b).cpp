#include <iostream>
using namespace std;

#define MAX 10

class Queue {
    int arr[MAX], front, rear;
public:
    Queue() { front = 0; rear = -1; }
    void enqueue(int x) { arr[++rear] = x; }
    int dequeue() { return arr[front++]; }
    int size() { return rear - front + 1; }
    bool isEmpty() { return front > rear; }
};

class Stack {
    Queue q;
public:
    void push(int x) {
        q.enqueue(x);
        int sz = q.size();
        while (sz > 1) {
            q.enqueue(q.dequeue());
            sz--;
        }
    }
    int pop() {
        if (q.isEmpty()) { cout << "Empty stack" << endl; return -1; }
        return q.dequeue();
    }
};
