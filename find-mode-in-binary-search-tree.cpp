/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxC; 
    unordered_map<int , int> umap;
    void  helper(TreeNode* root) {
        if(!root)
            return;
        umap[root->val]++;
        maxC = max(maxC, umap[root->val]);
        if(root->left)
            helper(root->left);
        if(root->right)
            helper(root->right);  
    }
    vector<int> findMode(TreeNode* root) {
        helper(root);
        vector<int> temp;
        for(auto [k, v] : umap) {
            if(v == maxC)
                temp.push_back(k);
        }
        return temp;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int , int> umap;
        int maxC = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            umap[curr->val]++;
            maxC = max(maxC, umap[curr->val]);
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        vector<int> temp;
        for(auto [k, v] : umap) {
            if(v == maxC)
                temp.push_back(k);
        }
        return temp;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, int &prev, int &count, int &max, vector<int> &ans) {
        if(!root)
            return;
        helper(root->left, prev, count, max, ans);
        if(prev != INT_MIN) {
            if(prev == root->val)
                count++;
            else 
                count = 1;
        }
        if(count > max) {
            max = count;
            ans.clear();
            ans.push_back(root->val);
        } else if(count == max) {
            ans.push_back(root->val);
        }
        prev = root->val;
        
        helper(root->right, prev, count, max, ans);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int prev = INT_MIN, count = 1, max = 0;
        helper(root, prev, count, max, ans);
        return ans;
    }
};
