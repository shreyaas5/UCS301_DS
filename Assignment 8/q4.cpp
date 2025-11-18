#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

bool BSTUtil(Node* root, int min, int max) {
    if (!root) return true;

    if (root->data <= min || root->data >= max)
        return false;

    return BSTUtil(root->left, min, root->data) &&
           BSTUtil(root->right, root->data, max);
}

bool isBST(Node* root) {
    return BSTUtil(root, INT_MIN, INT_MAX);
}
