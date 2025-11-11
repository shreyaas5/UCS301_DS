//DLL
int sizeDLL(DNode* head){
    int c=0;
    while(head){ c++; head=head->next; }
    return c;
}

//CLL
int sizeCLL(CNode* head){
    if(!head) return 0;
    int c=0;
    CNode* p=head;
    do{ c++; p=p->next; }while(p!=head);
    return c;
}
