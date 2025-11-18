#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(NULL), right(NULL) {}
};

Node* searchRec(Node* root, int key) {
    if (!root || root->key == key) return root;
    if (key < root->key) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchIter(Node* root, int key) {
    while (root && root->key != key) {
        root = (key < root->key) ? root->left : root->right;
    }
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* inorderSuccessor(Node* root, Node* target) {
    Node* succ = NULL;

    while (root) {
        if (target->key < root->key) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* target) {
    Node* pred = NULL;

    while (root) {
        if (target->key > root->key) {
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pred;
}
