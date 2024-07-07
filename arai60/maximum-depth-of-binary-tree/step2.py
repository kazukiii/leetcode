# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        nodes_to_visit = deque([(root, 1)])
        max_depth = 0

        while nodes_to_visit:
            node, depth = nodes_to_visit.popleft()
            if not node: continue
            max_depth = max(max_depth, depth)
            nodes_to_visit.append((node.left, depth + 1))
            nodes_to_visit.append((node.right, depth + 1))

        return max_depth
