#include <iostream>
using namespace std;

#define MAX 10

class Queue {
    int arr[MAX], front, rear;
public:
    Queue() { front = 0; rear = -1; }
    void enqueue(int x) { arr[++rear] = x; }
    int dequeue() { return arr[front++]; }
    bool isEmpty() { return front > rear; }
};

class Stack {
    Queue q1, q2;
public:
    void push(int x) {
        q2.enqueue(x);
        while (!q1.isEmpty()) q2.enqueue(q1.dequeue());
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }
    int pop() {
        if (q1.isEmpty()) { cout << "Empty stack" << endl; return -1; }
        return q1.dequeue();
    }
};
