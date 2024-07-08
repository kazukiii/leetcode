# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        max_depth = 0
        nodes_to_visit = deque([root])
        while nodes_to_visit:
            max_depth += 1
            level_size = len(nodes_to_visit)
            for _ in range(level_size):
                node = nodes_to_visit.popleft()
                if node.left:
                    nodes_to_visit.append(node.left)
                if node.right:
                    nodes_to_visit.append(node.right)

        return max_depth
