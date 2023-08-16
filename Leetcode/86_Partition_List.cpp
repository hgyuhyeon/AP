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
        ListNode* less = new ListNode(0), *lp = less, *more = new ListNode(0), *mp = more, *p = head;
        while (p != NULL) {
            p = p->next;
            if (head->val < x) {
                lp->next = head;
                lp = lp->next;
            }
            else {
                mp->next = head;
                mp = mp->next;
            }
            head = p;
        }
        lp->next = more->next;
        mp->next = NULL;
        
        return less->next;
    }
};