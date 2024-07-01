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
        ListNode dummy_head;
        ListNode* node = &dummy_head;
        int carry = 0;

        add(list1, list2, carry, node);

        return dummy_head.next;
    }

private:
    void add(ListNode* list1, ListNode* list2, int carry, ListNode* node) {
        if (!list1 && !list2 && !carry) return;

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

        add(list1, list2, carry, node);
    }
};
