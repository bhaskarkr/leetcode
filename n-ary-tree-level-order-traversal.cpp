/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<Node*> Q;
        Q.push(root);
        while(!Q.empty()) {
            int c = Q.size();
            ans.push_back({});
            while(c--) {
                auto t = Q.front();
                ans.back().push_back(t->val);
                Q.pop();
                for(auto child : t->children)
                    Q.push(child);
            }
        }
        return ans;
    }
};
