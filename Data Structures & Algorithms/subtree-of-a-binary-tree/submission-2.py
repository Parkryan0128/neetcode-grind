# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        node = []

        def dfs(root):
            nonlocal node

            if not root:
                return
            
            if root.val == subRoot.val:
                node.append(root)
            
            dfs(root.left)
            dfs(root.right)


        dfs(root)
        if not node:
            return False
        

        def sameTree(node, subRoot):
            if node == None and subRoot == None:
                return True
            if not node and subRoot:
                return False
            if node and not subRoot:
                return False


            if node.val != subRoot.val:
                return False
            
            left = sameTree(node.left, subRoot.left)
            right = sameTree(node.right, subRoot.right)

            return left and right
        
        for item in node:
            if (sameTree(item,subRoot)):
                return True
        

        return False

            



        
