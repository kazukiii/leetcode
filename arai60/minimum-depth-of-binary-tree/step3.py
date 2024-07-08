# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        nodes_to_visit = deque([(root, 1)])
        while nodes_to_visit:
            node, depth = nodes_to_visit.popleft()
            if not node: continue
            if not node.left and not node.right:
                return depth
            nodes_to_visit.append((node.left, depth + 1))
            nodes_to_visit.append((node.right, depth + 1))
        return 0
