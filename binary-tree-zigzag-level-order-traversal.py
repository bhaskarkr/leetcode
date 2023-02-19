# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        Q = []
        ans = []
        direction = True
        Q.append(root)
        while len(Q) > 0:
            c = len(Q)
            temp = [ele.val for ele in Q]
            if not direction:
                temp = temp[::-1]
            ans.append(temp) 
            while c > 0:
                c -= 1
                curr = Q.pop(0)
                if curr.left:
                    Q.append(curr.left)
                if curr.right:
                    Q.append(curr.right)
            direction = not direction
        return ans
