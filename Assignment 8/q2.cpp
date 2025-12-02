#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    
    Node(int k) : key(k), left(NULL), right(NULL){};
};

Node* recursive_search(Node* root, int k){
    if(!root) return NULL;
    if(root->key == k) return root;
    else if(root->key > k){
        return recursive_search(root->left, k);
    } else{
        return recursive_search(root->right, k);
    }
}

Node* non_recursive_search(Node* root, int k){
    while(root){
        if(root->key == k) return root;
        root = (k < root->key) ? root->left : root->right;
    }
    return NULL;
}

int max_element(Node* root){
    if(!root) return INT_MIN;
    while(root->right) root = root->right;
    return root->key;
}

int min_element(Node* root){
    if(!root) return INT_MIN;
    while(root->left) root = root->left;
    return root->key;
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
