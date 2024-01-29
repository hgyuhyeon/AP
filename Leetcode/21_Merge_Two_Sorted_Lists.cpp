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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        else if (!list2) return list1;

        ListNode* ptr1 = list1, *ptr2 = list2, *head;
        if (ptr1->val <= ptr2->val) {
            head = ptr1;
            ptr1 = ptr1->next;
        }
        else {
            head = ptr2;
            ptr2 = ptr2->next;
        }
        ListNode* mptr = head;
        while (ptr1 != NULL && ptr2 != NULL) {
            if (ptr1->val <= ptr2->val) {
                mptr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else {
                mptr->next = ptr2;
                ptr2 = ptr2->next;
            }
            mptr = mptr->next;
        }

        if (ptr1 != NULL) mptr->next = ptr1;
        else if (ptr2 != NULL) mptr->next = ptr2;

        return head;
    }
};