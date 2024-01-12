# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node, minval, maxval):
        if node == None: return

        self.ans = max(self.ans, abs(maxval - node.val))
        self.ans = max(self.ans, abs(minval - node.val))

        maxval = max(maxval, node.val)
        minval = min(minval, node.val)
        self.dfs(node.left, minval, maxval)
        self.dfs(node.right, minval, maxval)

    def maxAncestorDiff(self, root) -> int:
        self.ans = 0
        self.dfs(root, root.val, root.val)
        
        return self.ans