#include <iostream>
using namespace std;

#define MAX 256

class Queue {
    char arr[100];
    int front, rear;
public:
    Queue() { front = 0; rear = -1; }
    void enqueue(char c) { arr[++rear] = c; }
    void dequeue() { front++; }
    char frontChar() { return arr[front]; }
    bool isEmpty() { return front > rear; }
};

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    Queue q;
    int freq[MAX] = {0};

    cout << "Output: ";
    for (char c : s) {
        freq[c]++;
        q.enqueue(c);

        while (!q.isEmpty() && freq[q.frontChar()] > 1) {
            q.dequeue();
        }

        if (q.isEmpty()) cout << -1 << " ";
        else cout << q.frontChar() << " ";
    }
    cout << endl;
    return 0;
}
