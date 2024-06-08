# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast = head
        slow = head

        while True:
            if not fast or not fast.next:
                return None

            fast = fast.next.next
            slow = slow.next

            if fast == slow:
                break

        ptr1 = head
        ptr2 = slow

        while ptr1 != ptr2:
            ptr1 = ptr1.next
            ptr2 = ptr2.next

        return ptr1
