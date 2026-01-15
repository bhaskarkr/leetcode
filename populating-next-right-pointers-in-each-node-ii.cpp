/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    Node* connect(Node* root) {
        if(!root)
            return NULL;
        auto curr = root->next;
        while(curr and !curr->left and !curr->right) {
            curr = curr->next;
        }
        if(root->left) {
            if(root->right) {
                root->left->next = root->right;
            } else if(curr) {
                if(curr->left)
                    root->left->next = curr->left;
                else if(curr->right)
                    root->left->next = curr->right;
                else
                    root->left->next = NULL;
            } else {
                root->left->next = NULL;
            }
        }
        if(root->right) {
            if(curr) {
                if(curr->left)
                    root->right->next = curr->left;
                else if(curr->right)
                    root->right->next = curr->right;
                else
                    root->right->next = NULL;
            } else {
                root->right->next = NULL;
            }
        } 
        connect(root->right);
        connect(root->left);
        
        return root;
    }
};
