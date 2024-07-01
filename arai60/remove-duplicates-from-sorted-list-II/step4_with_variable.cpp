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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* node = &dummy;
        ListNode* next_node = head;
        while (node && next_node) {
            bool has_duplicates = next_node->next && next_node->val == next_node->next->val;
            if (has_duplicates) {
                while (next_node->next && next_node->val == next_node->next->val) {
                    node->next = next_node->next;
                    next_node = next_node->next;
                }
                node->next = next_node->next;
                next_node = node->next;
                continue;
            }
            node = node->next;
            next_node = node->next;
        }
        return dummy.next;
    }
};
