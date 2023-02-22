# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    prev = -10e9
    ans = 10e9
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        if not root:
            return
        self.getMinimumDifference(root.left)
        self.ans = min(self.ans, root.val - self.prev)
        self.prev = root.val
        self.getMinimumDifference(root.right)
        return self.ans
        
