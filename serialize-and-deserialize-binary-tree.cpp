/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "# ";
        string temp = to_string(root->val) + " ";
        temp += serialize(root->left);
        temp += serialize(root->right);
        return temp;
    }

    TreeNode* helper(istringstream &in) {
        string val;
        in >> val;
        if(val == "#")
            return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = helper(in);
        root->right = helper(in);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return helper(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
