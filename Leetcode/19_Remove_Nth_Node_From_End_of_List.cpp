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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head, *prev = NULL;
        int size = -n;
        while (ptr != NULL) {
            size++;
            ptr = ptr->next;
        }
        ptr = head;
        if (size == 0) return head->next;
        while (size-- > 0) {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = ptr->next;
        return head;
    }
};