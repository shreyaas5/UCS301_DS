#include <iostream>
using namespace std;

#define MAX 5

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return (rear == MAX - 1); }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (isEmpty()) front = 0;
        arr[++rear] = x;
        cout << x << " enqueued." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << arr[front] << " dequeued." << endl;
        if (front == rear) front = rear = -1;
        else front++;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is empty!" << endl;
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int ch, val;

    while (true) {
        cout << endl << "--- Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: cout << (q.isEmpty() ? "Empty" : "Not Empty") << endl; break;
            case 4: cout << (q.isFull() ? "Full" : "Not Full") << endl; break;
            case 5: q.display(); break;
            case 6: q.peek(); break;
            case 7: return 0;
            default: cout << "Invalid choice!" << endl;
        }
    }
}
