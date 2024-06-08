# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast = head
        slow = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

            if fast == slow:
                from_head = head
                from_collision = slow
                while from_head != from_collision:
                    from_head = from_head.next
                    from_collision = from_collision.next

                return from_head

        return None
