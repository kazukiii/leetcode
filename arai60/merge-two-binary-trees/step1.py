# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root1 and not root2: return None
        if not root1: return TreeNode(root2.val)
        if not root2: return TreeNode(root1.val)

        merged_root = TreeNode(root1.val + root2.val)
        def merge_trees_helper(root1: Optional[TreeNode], root2: Optional[TreeNode], merged_root: TreeNode) -> None:
            if not root1 and not root2: return
            if not root1:
                merged_root.left = deepcopy(root2.left)
                merged_root.right = deepcopy(root2.right)
                return
            if not root2:
                merged_root.left = deepcopy(root1.left)
                merged_root.right = deepcopy(root1.right)
                return

            if root1.left or root2.left:
                left_sum = 0
                if root1.left: left_sum += root1.left.val
                if root2.left: left_sum += root2.left.val
                merged_root.left = TreeNode(left_sum)
                merge_trees_helper(root1.left, root2.left, merged_root.left)

            if root1.right or root2.right:
                right_sum = 0
                if root1.right: right_sum += root1.right.val
                if root2.right: right_sum += root2.right.val
                merged_root.right = TreeNode(right_sum)
                merge_trees_helper(root1.right, root2.right, merged_root.right)

        merge_trees_helper(root1, root2, merged_root)
        return merged_root
