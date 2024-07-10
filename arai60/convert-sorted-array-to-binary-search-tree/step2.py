# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def build_complete_binary_tree(index: int) -> Optional[TreeNode]:
            if index >= len(nums): return None
            node = TreeNode()
            node.left = build_complete_binary_tree(2 * index + 1)
            node.right = build_complete_binary_tree(2 * index + 2)
            return node

        binary_tree = build_complete_binary_tree(0)
        index = 0
        def set_value(root: Optional[TreeNode]) -> None:
            nonlocal index
            if not root: return
            set_value(root.left)
            root.val = nums[index]
            index += 1
            set_value(root.right)

        set_value(binary_tree)
        return binary_tree
