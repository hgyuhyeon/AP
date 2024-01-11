# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    ans = 0
    
    def dfs(self, node, anc: list):
        self.ans = max(self.ans, abs(max(anc) - node.val))
        self.ans = max(self.ans, abs(min(anc) - node.val))

        if node.left != None:
            anc.append(node.left.val)
            self.dfs(node.left, anc)
            anc.pop()
        if node.right != None:
            anc.append(node.right.val)
            self.dfs(node.right, anc)
            anc.pop()

    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        ancestor = [root.val]
        self.dfs(root, ancestor)
        
        return self.ans