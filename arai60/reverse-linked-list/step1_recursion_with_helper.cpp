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
        auto result = reverseListHelper(head);
        return result.first;
    }

private:
    pair<ListNode*, ListNode*> reverseListHelper(ListNode* node) {
        if (!node) return {nullptr, nullptr};
        if (!node->next) return {node, node};

        ListNode* next_node = node->next;
        node->next = nullptr;
        auto [head, tail] = reverseListHelper(next_node);
        tail->next = node;
        return {head, node};
    }
};
