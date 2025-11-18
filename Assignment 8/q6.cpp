#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(NULL), right(NULL) {}
};

void heapInsert(int heap[], int &n, int val) {
    heap[n] = val;
    int i = n;
    n++;

    while (i != 0 && heap[(i-1)/2] < heap[i]) {
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int heapDelete(int heap[], int &n) {
    int root = heap[0];
    heap[0] = heap[n-1];
    n--;
    heapify(heap, n, 0);
    return root;
}
