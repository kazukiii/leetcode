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
        if (!head) return nullptr;

        stack<ListNode*> node_stack;
        ListNode* node = head;
        while (node) {
            node_stack.push(node);
            node = node->next;
        }

        ListNode* new_head = node_stack.top();
        node_stack.pop();
        while (!node_stack.empty()) {
            node = node_stack.top();
            node_stack.pop();
            node->next->next = node;
            node->next = nullptr;
        }
        return new_head;
    }
};
