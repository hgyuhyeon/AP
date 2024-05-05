/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* ptr = node->next, *prev = node;
        if (!ptr) prev->next = NULL;
        else {
            while (ptr->next != NULL) {
                prev->val = ptr->val;
                prev = ptr;
                ptr = ptr->next;
            }
            prev->val = ptr->val;
            prev->next = NULL;
        }
    }
};