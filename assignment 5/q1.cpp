#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x): data(x), next(nullptr) {}
};

void display(Node* head){
    Node* p = head;
    if(!p){ cout << "List is empty." << endl; return; }
    while(p){
        cout << p->data;
        if(p->next) cout << " -> ";
        p = p->next;
    }
    cout << endl;
}

void insertAtBeginning(Node*& head, int x){
    Node* n = new Node(x);
    n->next = head;
    head = n;
}

void insertAtEnd(Node*& head, int x){
    Node* n = new Node(x);
    if(!head){ head = n; return; }
    Node* p = head;
    while(p->next) p = p->next;
    p->next = n;
}

void insertBefore(Node*& head, int key, int x){
    if(!head){ return; }
    if(head->data == key){
        insertAtBeginning(head, x);
        return;
    }
    Node* p = head;
    while(p->next && p->next->data != key) p = p->next;
    if(p->next){
        Node* n = new Node(x);
        n->next = p->next;
        p->next = n;
    }
}

// Insert AFTER the first node with value key
void insertAfter(Node*& head, int key, int x){
    Node* p = head;
    while(p && p->data != key) p = p->next;
    if(p){
        Node* n = new Node(x);
        n->next = p->next;
        p->next = n;
    }
}

void deleteFromBeginning(Node*& head){
    if(!head) return;
    Node* t = head;
    head = head->next;
    delete t;
}

void deleteFromEnd(Node*& head){
    if(!head) return;
    if(!head->next){
        delete head;
        head = nullptr;
        return;
    }
    Node* p = head;
    while(p->next && p->next->next) p = p->next;
    delete p->next;
    p->next = nullptr;
}

void deleteValue(Node*& head, int key){
    if(!head) return;
    if(head->data == key){
        deleteFromBeginning(head);
        return;
    }
    Node* p = head;
    while(p->next && p->next->data != key) p = p->next;
    if(p->next){
        Node* t = p->next;
        p->next = t->next;
        delete t;
    }
}

int search(Node* head, int key){
    int pos = 1;
    Node* p = head;
    while(p){
        if(p->data == key) return pos;
        p = p->next;
        pos++;
    }
    return -1;
}

int main(){
    Node* head = nullptr;
    int ch;

    while(true){
        cout << endl;
        cout << "---- MENU ----" << endl;
        cout << "1. Insertion at the beginning" << endl;
        cout << "2. Insertion at the end" << endl;
        cout << "3. Insertion in between (before/after a specific value)" << endl;
        cout << "4. Deletion from the beginning" << endl;
        cout << "5. Deletion from the end" << endl;
        cout << "6. Deletion of a specific node (by value)" << endl;
        cout << "7. Search (position from head)" << endl;
        cout << "8. Display" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> ch;

        if(ch == 1){
            int x; cout << "Enter value: "; cin >> x;
            insertAtBeginning(head, x);
        }
        else if(ch == 2){
            int x; cout << "Enter value: "; cin >> x;
            insertAtEnd(head, x);
        }
        else if(ch == 3){
            int x, key; char where;
            cout << "Insert value: "; cin >> x;
            cout << "Before or After? (b/a): "; cin >> where;
            cout << "Enter the reference value: "; cin >> key;
            if(where == 'b' || where == 'B') insertBefore(head, key, x);
            else insertAfter(head, key, x);
        }
        else if(ch == 4){
            deleteFromBeginning(head);
        }
        else if(ch == 5){
            deleteFromEnd(head);
        }
        else if(ch == 6){
            int key; cout << "Enter value to delete: "; cin >> key;
            deleteValue(head, key);
        }
        else if(ch == 7){
            int key; cout << "Enter value to search: "; cin >> key;
            int pos = search(head, key);
            if(pos == -1) cout << "Not found." << endl;
            else cout << "Found at position: " << pos << endl;
        }
        else if(ch == 8){
            display(head);
        }
        else if(ch == 9){
            break;
        }
        else{
            cout << "Invalid choice." << endl;
        }
    }

    while(head) deleteFromBeginning(head);
    return 0;
}
