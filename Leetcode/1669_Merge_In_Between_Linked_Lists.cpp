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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev = list1, *ptr = list1, *ptra = list1;

        for (int i=0; i<=b+1; i++) {
            if (i == a-1) prev = ptr;
            else if (i == b+1) break;
            ptr = ptr->next;
        }

        prev->next = list2;
        while (prev->next != NULL) prev = prev->next;
        prev->next = ptr;

        return list1;
    }
};