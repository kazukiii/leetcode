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
        ListNode dummy_head(0, head);
        ListNode* node = &dummy_head;
        while (node) {
            bool has_duplicates = node->next && node->next->next && node->next->val == node->next->next->val;
            if (has_duplicates) {
                while (node->next && node->next->next && node->next->val == node->next->next->val) {
                    node->next = node->next->next;
                }
                node->next = node->next->next;
                continue;
            }
            node = node->next;
        }
        return dummy_head.next;
    }
};
