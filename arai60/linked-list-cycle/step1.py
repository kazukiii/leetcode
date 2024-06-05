# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return False

        fast = head
        slow = head

        while fast is not None:
            fast = fast.next.next if fast.next is not None else fast.next
            slow = slow.next

            if fast == slow:
                return True

        return False
