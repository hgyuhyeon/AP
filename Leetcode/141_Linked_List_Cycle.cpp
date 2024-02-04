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
    bool hasCycle(ListNode *head) {
        ListNode* ptr = head;
        while (ptr != NULL) {
            if (ptr->val == 10000000) return true;
            ptr->val = 10000000;
            ptr = ptr->next;
        }
        return false;
    }
};