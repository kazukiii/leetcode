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
        ListNode dummy;
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;
        int skip_count = 0;
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;
                skip_count++;
            } else {
                if (skip_count == 0) {
                    prev = curr;
                } else {
                    prev->next = curr->next;
                }

                skip_count = 0;
                curr = curr->next;
            }
        }

        if (skip_count != 0) {
            prev->next = curr->next;
        }

        return dummy.next;
    }
};
