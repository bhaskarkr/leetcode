/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> org;
        unordered_map<int, Node*> cp;
        auto temp = head;
        auto dummy = new Node(-1);
        auto prev = dummy;
        int i = 0;
        while(temp) {
            org[temp] = i;
            prev->next = new Node(temp->val);
            cp[i] = prev->next;
            prev = prev->next;
            temp = temp->next;
            i++;
        }
        temp = head;
        auto curr = dummy->next;
        while(temp) {
            if(temp->random)
                curr->random = cp[org[temp->random]];
            curr = curr->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};
