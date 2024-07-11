# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], target_sum: int) -> bool:
        def has_path_sum_helper(root: TreeNode, current_sum: int) -> bool:
            current_sum += root.val
            if not root.left and not root.right:
                return current_sum == target_sum
            if root.left:
                if has_path_sum_helper(root.left, current_sum):
                    return True
            if root.right:
                if has_path_sum_helper(root.right, current_sum):
                    return True
            return False

        if not root:
            return False
        return has_path_sum_helper(root, 0)
