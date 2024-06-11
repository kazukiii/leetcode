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
    ListNode* reverseList(ListNode* head) {
        ListNode* previous_node = nullptr;
        ListNode* node = head;
        while (node) {
            ListNode* temp = node->next;
            node->next = previous_node;
            previous_node = node;
            node = temp;
        }
        return previous_node;
    }
};
