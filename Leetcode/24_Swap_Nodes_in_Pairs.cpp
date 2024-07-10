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
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead = new ListNode(0, head), *ptr = head, *prev = newHead, *next;
        while (ptr != NULL) {
            if (ptr->next != NULL) {
                next = ptr->next->next;
                prev->next = ptr->next;
                ptr->next->next = ptr;
                ptr->next = next;
                prev = ptr;
                ptr = next;
            }
            else break;
        }
        return newHead->next;
    }
};
