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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        TreeNode* root = helper(nums, l , r);
        return root;
    }
    
    TreeNode* helper(vector<int>& nums, int l, int r) {
        if(l > r)
            return NULL;
        int m = l + (r - l)/2;
        TreeNode* curr = new TreeNode(nums[m]);
        curr->left = helper(nums, l , m-1);
        curr->right = helper(nums, m + 1, r);
        return curr;
    }
};
