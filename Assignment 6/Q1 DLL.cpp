#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int x): data(x), prev(NULL), next(NULL) {}
};

void display(DNode* head){
    DNode* p = head;
    if(!p){ cout<<"List is empty"<<endl; return; }
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void insertAtBeginning(DNode* &head, int x){
    DNode* n = new DNode(x);
    if(head){
        n->next=head;
        head->prev=n;
    }
    head=n;
}

void insertAtEnd(DNode* &head, int x){
    DNode* n = new DNode(x);
    if(!head){ head=n; return; }
    DNode* p = head;
    while(p->next) p=p->next;
    p->next=n;
    n->prev=p;
}

void insertAfter(DNode* head, int key, int x){
    DNode* p=head;
    while(p && p->data!=key) p=p->next;
    if(!p) return;
    DNode* n=new DNode(x);
    n->next=p->next;
    n->prev=p;
    if(p->next) p->next->prev=n;
    p->next=n;
}

void insertBefore(DNode* &head, int key, int x){
    if(!head) return;
    if(head->data==key){ insertAtBeginning(head,x); return; }
    DNode* p=head;
    while(p && p->data!=key) p=p->next;
    if(!p) return;
    DNode* n=new DNode(x);
    n->next=p;
    n->prev=p->prev;
    p->prev->next=n;
    p->prev=n;
}

void deleteValue(DNode* &head, int key){
    if(!head) return;
    DNode* p=head;
    while(p && p->data!=key) p=p->next;
    if(!p) return;
    if(p->prev) p->prev->next=p->next;
    else head=p->next;
    if(p->next) p->next->prev=p->prev;
    delete p;
}

int search(DNode* head,int key){
    int pos=1;
    while(head){
        if(head->data==key) return pos;
        head=head->next;
        pos++;
    }
    return -1;
}
