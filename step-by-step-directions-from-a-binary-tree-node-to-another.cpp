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
    string startToRootPath;
    string destToRootPath;
    string path;
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        startToRootPath = "";
        destToRootPath = "";
        path = "";
        getPathFromRoot(root, startValue, destValue);
        if(startToRootPath.empty())
            return destToRootPath;
        if(destToRootPath.empty())
            return string(startToRootPath.length(), 'U');
        int i = 0;
        while( i < startToRootPath.length() && i < destToRootPath.length() && startToRootPath[i] == destToRootPath[i]) {
            i++;
        }
        return string(startToRootPath.length() - i, 'U') + destToRootPath.substr(i);
    }
    
    void getPathFromRoot(TreeNode* root, int startValue, int destValue) {
        if(!root)
            return;
        if(root->val == startValue)
            startToRootPath  = path;
        else if(root->val == destValue)
            destToRootPath = path;
        if(!startToRootPath.empty() && !destToRootPath.empty())
            return;
        if(root->left) {
            path.push_back('L');
            getPathFromRoot(root->left, startValue, destValue);
            path.pop_back();
        }
        if(root->right) {
            path.push_back('R');
            getPathFromRoot(root->right, startValue, destValue);
            path.pop_back();
        }

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
string start;
string dest;
string path;
string getDirections(TreeNode* root, int startValue, int destValue) {
    helper(root, startValue, destValue);
    int i = 0;
    while(start[i] == dest[i])
        i++;
    dest = dest.substr(i);
    return string(start.length() - i, 'U') + dest;
}

void helper(TreeNode* root, int startValue, int destValue) {
    if(!root || (!start.empty() && !dest.empty())) {
        return;
    }
    if(root->val == startValue) {
        start = path;
    }
    if(root->val == destValue) {
        dest = path;
    }
    if(root->left) {
        path.push_back('L');
        helper(root->left, startValue, destValue);
        path.pop_back();
    }
    if(root->right) {
        path.push_back('R');
        helper(root->right, startValue, destValue);
        path.pop_back();
    }
}
};
