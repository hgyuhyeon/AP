struct Node {
    int val;
    Node* next;
};

class MyLinkedList {
private:
    Node* head;
    int size;
public:
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if (index >= size) return -1;
        Node* ptr = head;
        for (int i = 0; i < index; i++) ptr = ptr->next;
        return ptr->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val, head);
        head = node;
        size += 1;
    }
    
    void addAtTail(int val) {
        if (!size) addAtHead(val);
        else {
            Node* ptr = head;
            while (ptr->next != NULL) ptr = ptr->next;
            ptr->next = new Node(val, NULL);
            size += 1;
        }        
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        else if (!size) addAtHead(val);
        else if (index == 0) {
            head = new Node(val, head);
            size += 1;
        }
        else {
            Node* ptr = head;
            for (int i = 0; i < index - 1; i++) ptr = ptr->next;
            Node* node = new Node(val, ptr->next);
            ptr->next = node;
            size += 1;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) return;
        Node* ptr = head;
        if (index == 0) head = head->next;
        else {
            for (int i = 0; i < index - 1; i++) ptr = ptr->next;
            ptr->next = ptr->next->next;
        }
        size -= 1;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */