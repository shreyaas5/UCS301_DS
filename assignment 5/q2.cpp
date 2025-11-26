void countAndDelete(Node* &head, int key) {
    int count = 0;

    // delete from beginning
    while(head && head->data == key) {
        Node* del = head;
        head = head->next;
        delete del;
        count++;
    }

    // delete from middle
    Node* curr = head;
    Node* prev = nullptr;

    while(curr) {
        if(curr->data == key) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            count++;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    cout << "Count: " << count << endl;
}
