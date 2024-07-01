/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        int carry = 0;
        ListNode dummy_head;
        ListNode* node = &dummy_head;
        while (list1 || list2 || carry) {
            int sum = carry;
            if (list1) {
                sum += list1->val;
                list1 = list1->next;
            }
            if (list2) {
                sum += list2->val;
                list2 = list2->next;
            }

            carry = sum / 10;
            node->next = new ListNode(sum % 10);
            node = node->next;
        }

        return dummy_head.next;
    }
};
