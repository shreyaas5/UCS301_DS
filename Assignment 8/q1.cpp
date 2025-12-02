// Write program using functions for binary tree traversals: Pre-order, In-order and Post order using recursive approach.

#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void preorder(Node* root){
    if(!root) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

int main(){
    Node* x1 = new Node(1);
    Node* x2 = new Node(3);
    Node* x3 = new Node(2);
    Node* x4 = new Node(4);
    Node* x5= new Node(7);
    Node* x6 = new Node(8);
    
    x1->left = x2;
    x1->right = x3;
    x2->left = x4;
    x2->right = x5;
    x3->right = x6;

    cout << "Inorder: ";
    inorder(x1);
    cout << "\n";

    cout << "Preorder: ";
    preorder(x1);
    cout << "\n";

    cout << "Postorder: ";
    postorder(x1);
    cout << "\n";

    return 0;

}
