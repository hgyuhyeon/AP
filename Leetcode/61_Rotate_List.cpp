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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* ptr = head, *prev;
        int n = 0;
        while (ptr != NULL) {
            n++;
            ptr = ptr->next;
        }

        if (!head || k % n == 0) return head;
        n -= (k % n);
        ptr = head;
        while (n-- > 0) {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        prev = ptr;
        while (ptr->next != NULL) ptr = ptr->next;
        ptr->next = head;
        return prev;
    }
};