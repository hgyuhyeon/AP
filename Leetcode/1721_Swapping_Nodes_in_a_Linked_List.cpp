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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr = head, *ptr2 = head;

        int size = 1;
        while (ptr->next) {
            ptr = ptr->next;
            size++;
        }
        
        ptr = head;
        for (int i = 0; i < k - 1; i++) ptr = ptr->next;
        for (int i = 0; i < size - k; i++) ptr2 = ptr2->next;

        swap(ptr->val, ptr2->val);

        return head;
    }
};