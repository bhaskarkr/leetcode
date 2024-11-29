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
            return root;
        if(root->left)
            root->left->next = root->right;
        if(root->right and root->next)
            root->right->next = root->next->left;  
        connect(root->left);
        connect(root->right);
        return root;
    }
};

class Solution {
public:
    void helper(Node* root, int level, unordered_map<int, Node*> &prevLeft) {
        if(!root)
            return;
        if(prevLeft.find(level) != prevLeft.end())
            prevLeft[level]->next = root;
        prevLeft[level] = root;
        helper(root->left, level + 1, prevLeft);
        helper(root->right, level + 1, prevLeft);
    }
    Node* connect(Node* root) {
        unordered_map<int, Node*> prevLeft;
        helper(root, 0, prevLeft);
        for(auto [k, v] : prevLeft) {
            v->next = NULL;
        }
        return root;
    }
};
