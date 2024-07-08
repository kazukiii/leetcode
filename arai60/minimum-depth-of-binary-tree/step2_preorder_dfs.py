# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        min_depth = math.inf
        nodes_to_visit = [(root, 1)]
        while nodes_to_visit:
            node, depth = nodes_to_visit.pop()
            if not node.left and not node.right:
                min_depth = min(min_depth, depth)

            if node.left:
                nodes_to_visit.append((node.left, depth + 1))
            if node.right:
                nodes_to_visit.append((node.right, depth + 1))

        return min_depth
