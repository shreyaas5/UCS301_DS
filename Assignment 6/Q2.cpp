void displayRepeatHead(CNode* head){
    if(!head) return;
    CNode* p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
    cout<<head->data<<endl;
}
