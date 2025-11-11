struct CNode {
    int data;
    CNode* next;
    CNode(int x): data(x), next(NULL) {}
};

void displayCLL(CNode* head){
    if(!head) { cout<<"List is empty"<<endl; return; }
    CNode* p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
    cout<<endl;
}

void insertAtBeginningCLL(CNode* &head, int x){
    CNode* n=new CNode(x);
    if(!head){
        head=n;
        n->next=n;
        return;
    }
    CNode* temp=head;
    while(temp->next!=head) temp=temp->next;
    n->next=head;
    temp->next=n;
    head=n;
}

void insertAtEndCLL(CNode* &head, int x){
    CNode* n=new CNode(x);
    if(!head){
        head=n; n->next=n; return;
    }
    CNode* temp=head;
    while(temp->next!=head) temp=temp->next;
    temp->next=n;
    n->next=head;
}

void insertAfterCLL(CNode* head,int key,int x){
    if(!head) return;
    CNode* p=head;
    do{
        if(p->data==key){
            CNode* n=new CNode(x);
            n->next=p->next;
            p->next=n;
            return;
        }
        p=p->next;
    }while(p!=head);
}

void deleteValueCLL(CNode* &head,int key){
    if(!head) return;
    CNode* p=head;
    CNode* prev=NULL;

    do{
        if(p->data==key){
            if(p==head && p->next==head){ head=NULL; delete p; return; }
            if(p==head){
                CNode* last=head;
                while(last->next!=head) last=last->next;
                head=head->next;
                last->next=head;
            }else prev->next=p->next;
            delete p; return;
        }
        prev=p; p=p->next;
    }while(p!=head);
}

int searchCLL(CNode* head,int key){
    if(!head) return -1;
    int pos=1;
    CNode* p=head;
    do{
        if(p->data==key) return pos;
        p=p->next;
        pos++;
    }while(p!=head);
    return -1;
}
