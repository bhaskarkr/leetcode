class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
    Node(int val, Node* temp) {
        this->val = val;
        this->next = temp;
    }
};
class MyLinkedList {
public:
    Node * root = new Node(0);
    int c = 1;
    MyLinkedList() {  
    }
    
    int get(int index) {
        if(index >= c - 1)
            return -1;
        auto temp = root->next;
        while(index--)
            temp = temp->next;
        return temp->val;
    }
    
    void addAtHead(int val) {
        root->next = new Node(val, root->next);
        c++;
    }
    
    void addAtTail(int val) {
        auto temp = root;
        while(temp->next)
            temp = temp->next;
        temp->next = new Node(val);
        c++;
    }
    
    void addAtIndex(int index, int val) {
        if(index >= c)
            return;
        auto temp = root;
        while(index--)
            temp = temp->next;
        temp->next = new Node(val, temp->next);
        c++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= c - 1)
            return;
        auto temp = root;
        while(index--)
            temp = temp->next;
        temp->next = temp->next->next;
        c--;
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
