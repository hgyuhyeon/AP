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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1, *ptr2 = l2, *ans = new ListNode(0), *p = ans;
        int val = 0;
        do {
            if (ptr1 != NULL) {
                val += ptr1->val; 
                ptr1 = ptr1->next;
            }
            if (ptr2 != NULL) {
                val += ptr2->val;
                ptr2 = ptr2->next;
            }
            p->next = new ListNode(val % 10);
            p = p->next;
            val /= 10;
        } while (ptr1 != NULL || ptr2 != NULL);
        if (val) p->next = new ListNode(val % 10);
        return ans->next;
    }
};