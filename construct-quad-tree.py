"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def buildQuadTree(self, grid: List[List[int]], x : int, y : int, size : int) -> 'Node':
        if size == 1:
            return Node(grid[x][y], True, None, None, None, None)
        TL = self.buildQuadTree(grid, x, y, size // 2)
        BL = self.buildQuadTree(grid, x + size // 2, y, size // 2)
        TR = self.buildQuadTree(grid, x , y + size // 2, size // 2)
        BR = self.buildQuadTree(grid, x + size // 2, y + size // 2, size // 2)
        allLeaf = TL.isLeaf and TR.isLeaf and BL.isLeaf and BR.isLeaf
        allValEqual = TL.val == TR.val and BL.val == BR.val and TR.val == BL.val
        if allLeaf and allValEqual:
            return Node(TL.val, True, None, None, None, None)
        return Node(True, False, TL, TR, BL, BR)

    def construct(self, grid: List[List[int]]) -> 'Node':
        N = len(grid)
        if N == 0:
            return None
        return self.buildQuadTree(grid, 0, 0, N)
