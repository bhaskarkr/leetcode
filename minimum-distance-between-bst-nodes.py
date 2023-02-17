# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        self.prev = -10e8
        self.ans = -self.prev
        def helper(root: Optional[TreeNode]):
            if not root:
                return
            helper(root.left)
            self.ans = min(self.ans, root.val - self.prev)
            self.prev = root.val
            
            helper(root.right)
        helper(root)
        return self.ans
