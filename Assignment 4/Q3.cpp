#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() { front = 0; rear = -1; }
    void enqueue(int x) { arr[++rear] = x; }
    int dequeue() { return arr[front++]; }
    bool isEmpty() { return front > rear; }
    int size() { return rear - front + 1; }
};

int main() {
    Queue q1, q2;
    int n, x;
    cout << "Enter even number of elements: ";
    cin >> n;
    int half = n/2;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i < half) q1.enqueue(x);
        else q2.enqueue(x);
    }

    cout << "Interleaved Queue: ";
    while (!q1.isEmpty() && !q2.isEmpty()) {
        cout << q1.dequeue() << " " << q2.dequeue() << " ";
    }
    cout << endl;
    return 0;
}
