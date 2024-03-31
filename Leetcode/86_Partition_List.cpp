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
    ListNode* partition(ListNode* head, int x) {
        ListNode *mh = new ListNode(0), *lh = new ListNode(0), *more = mh, *ptr = head, *less = lh;
        while (ptr != NULL) {
            if (ptr->val >= x) {
                more->next = ptr;
                more = more->next;
            }
            else {
                less->next = ptr;
                less = less->next;
            }
            ptr = ptr->next;
        }
        less->next = mh->next;
        more->next = NULL;
        return lh->next;
    }
};