/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        auto curr = head; 
        while(curr) {
            if(curr->child) {
                auto temp = curr->next; 
                auto newList = flatten(curr->child);
                newList->prev = curr;
                curr->next = newList;
                while(newList->next) {
                    newList = newList->next;
                }
                newList->next = temp;
                if(temp)
                    temp->prev = newList;
                curr->child = nullptr;
                curr = temp;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};
