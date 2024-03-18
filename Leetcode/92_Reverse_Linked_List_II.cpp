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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ptr = head, *prev = NULL, *rev = NULL;
        int cnt = 1;
        while (cnt < left) {
            prev = ptr;
            ptr = ptr->next;
            cnt++;
        }

        while (cnt <= right) {
            ListNode* node = new ListNode(ptr->val, rev);
            rev = node;
            ptr = ptr->next;
            cnt++;
        }

        if (prev != NULL) prev->next = rev;
        else head = rev;
        while (rev->next != NULL) rev = rev->next;
        rev->next = ptr;
        return head;
    }
};