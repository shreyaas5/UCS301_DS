bool isPalindrome(DNode* head){
    if(!head || !head->next) return true;
    DNode* left=head;
    DNode* right=head;
    while(right->next) right=right->next;
    while(left!=right && right->next!=left){
        if(left->data!=right->data) return false;
        left=left->next;
        right=right->prev;
    }
    return true;
}
