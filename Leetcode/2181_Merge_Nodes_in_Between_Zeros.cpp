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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ptr = head->next, *num = head->next;
        int sum = 0;
        while (ptr != NULL) {
            if (ptr->val == 0) {
                num->val = sum;
                sum = 0;
                num->next = ptr->next;
                num = ptr->next;
            }
            else sum += ptr->val;
            ptr = ptr->next;
        }
        return head->next;
    }
};