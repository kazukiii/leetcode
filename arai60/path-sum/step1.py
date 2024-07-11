# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], target_sum: int) -> bool:
        if not root: return False

        nodes_to_visit = [(root, root.val)]
        while nodes_to_visit:
            node, current_sum = nodes_to_visit.pop()
            if not node.left and not node.right and current_sum == target_sum:
                return True
            if node.left:
                nodes_to_visit.append((node.left, current_sum + node.left.val))
            if node.right:
                nodes_to_visit.append((node.right, current_sum + node.right.val))
        return False
