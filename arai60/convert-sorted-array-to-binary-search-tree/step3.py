# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def build_bst(left: int, right: int) -> Optional[TreeNode]:
            if right - left == 0: return None
            mid = (left + right) // 2
            root = TreeNode(nums[mid])
            root.left = build_bst(left, mid)
            root.right = build_bst(mid + 1, right)
            return root

        return build_bst(0, len(nums))
